#include <SFML/Graphics.hpp>
#include "utils.h"
#include <functional>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <cmath>

std::string string_time() {
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	std::ostringstream oss;
	oss << std::put_time(&tm, "(%d-%m-%Y %H-%M-%S)");
	return oss.str();
}

struct Box2 {
	vec2 s = s = {1.f, 1.f}, p0 = {0.f, 0.f};
};
vec2 operator*(Box2 b, vec2 v) { return b.p0 + b.s * v; }

u32 clamp_255(float x) {
	s32 ix = (s32)(255.f * x);
	return (u32)(ix < 0 ? 0 : ix > 255 ? 255 : ix);
}

u32 to_color(vec3 rgb) {
	return(clamp_255(rgb.x)) | (clamp_255(rgb.y) << 8) | (clamp_255(rgb.z) << 16) | 0xFF000000; 
}

vec3 twilight_shifted(float t) {
    const vec3 c0 = vec3{0.120488, 0.047735, 0.106111};
    const vec3 c1 = vec3{5.175161, 0.597944, 7.333840};
    const vec3 c2 = vec3{-47.426009, -0.862094, -49.143485};
    const vec3 c3 = vec3{197.225325, 47.538667, 194.773468};
    const vec3 c4 = vec3{-361.218441, -146.888121, -389.642741};
    const vec3 c5 = vec3{298.941929, 151.947507, 359.860766};
    const vec3 c6 = vec3{-92.697067, -52.312119, -123.143476};
    return c0 + t * (c1 + t * (c2 + t * (c3 + t * (c4 + t * (c5 + t * c6)))));
}
vec3 twilight_shifted_2(vec2 p) {
	return twilight_shifted(atan2(p.x, p.y) / (M_PI * 2.f) + .5f);
}

const u32 NC = 4;
struct Model_Params {
	vec2 nodes[4];
	float d, R, C;
};
Model_Params make_model_params(float t) {
	t *= 30.f;
	Mat2x2 rot_mat = {cosf(t), sinf(t), -sinf(t), cosf(t)};
	return {
		.nodes = {
			rot_mat * vec2{.5f, 0.f},
			rot_mat * vec2{0.f, .5f},
			rot_mat * vec2{-.5f, 0.f},
			rot_mat * vec2{0.f, -.5f}
		},
		.d = 0.1f, .R = .2f, .C = .2f,
	};
}
struct Model {
	vec2 pos, speed;
};

Model make_model(vec2 pos) {
	return {
		.pos = pos, .speed = {sinf(pos.y * 10.f) * .05f, 0.f} 
	};
}
Model* make_model_set(Box2 box, u32 X, u32 Y) {
	Model *model_set = new Model[X * Y];
	for(u32 i = 0, y = 0; y < Y; y++) {
		for(u32 x = 0; x < X; x++, i++) {
			model_set[i] = make_model(box * vec2{(x + .5f) / X, (y + .5f) / Y});
		}
	}
	return model_set;
}
vec4 get_derivative(const Model_Params* model_params, vec4 p) {
	vec2 pos = {p.x, p.y}, vel = {p.z, p.w};
	vec2 force = -(model_params->C * pos + model_params->R * vel);
	float dd = model_params->d * model_params->d;
	for(u32 i = 0; i < NC; i++) {
		vec2 dp = model_params->nodes[i] - pos;
		force += dp / pow(len2(dp) + dd, 1.5f);
	}
	return {vel.x, vel.y, force.x, force.y};
}

void iterate(const Model_Params* model_params, Model* model, float delta_time) {
	vec4 X = {model->pos.x, model->pos.y, model->speed.x, model->speed.y};
	vec4 k1 = get_derivative(model_params, X);
	vec4 k2 = get_derivative(model_params, X + k1 * delta_time / 2.f);
	vec4 k3 = get_derivative(model_params, X + k2 * delta_time / 2.f);
	vec4 k4 = get_derivative(model_params, X + k3 * delta_time);
	vec4 X_ = X + (delta_time / 6.f) * (k1 + 2.f * k2 + 2.f * k3 + k4);

	model->pos = {X_.x, X_.y};
	model->speed = {X_.z, X_.w};
}
sf::Image make_image(u32 X, u32 Y) {
	sf::Image img;
	img.create(X, Y);
	return img;
}
void plot(sf::Image* img, Model* models, u32 X, u32 Y) {
	auto data = (u32*)img->getPixelsPtr();
	for(u32 i = 0, y = 0; y < Y; y++) {
		for(u32 x = 0; x < X; x++, i++) {
			data[i] = to_color(twilight_shifted_2(models[i].pos));
		}
		printf("line : %d/%d\n", y + 1, Y);
	}
}

int main() {
	const u32 X = 300, Y = 200;
	Model_Params model_params;
	float time = 0.f;
	const float delta_time = 0.01f;	

	auto img = make_image(X, Y);
	auto model_set = make_model_set({{3.3f, 2.2f}, {-1.65f, -1.1f}}, X, Y);

	for(u32 I = 0; I < 10; I++) {
		model_params = make_model_params(time);
		time += delta_time;
		for(u32 i = 0; i < X * Y; i++) {
			for(u32 j = 0; j < 20; j++) iterate(&model_params, model_set + i, delta_time);
			if(!(i % (X * 10))) printf("line : %d/%d\n", i / X + 1, Y);
		}
		plot(&img, model_set, X, Y);
		img.saveToFile("results/" + string_time() + "___" + std::to_string(I) + ".png");
	}

	delete[] model_set;
	return 0;
}
