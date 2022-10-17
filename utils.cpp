#include "utils.h"
#include <cmath>

sf::Vector2f to_sfml(vec2 v) { return {v.x, v.y}; }
sf::Vector3f to_sfml(vec3 v) { return {v.x, v.y, v.z}; }
vec2 to_cm(sf::Vector2f v) { return {v.x, v.y}; }
vec3 to_cm(sf::Vector3f v) { return {v.x, v.y, v.z}; }

bool operator==(vec2 a, vec2 b) { return a.x == b.x && a.y == b.y; }
bool operator==(vec3 a, vec3 b) { return a.x == b.x && a.y == b.y && a.z == b.z; }
bool operator==(vec4 a, vec4 b) { return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w; }
bool operator!=(vec2 a, vec2 b) { return a.x != b.x || a.y != b.y; }
bool operator!=(vec3 a, vec3 b) { return a.x != b.x || a.y != b.y || a.z != b.z; }
bool operator!=(vec4 a, vec4 b) { return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w; }

float randf() { return (float)rand() / RAND_MAX; }
vec2 rand_vec2() { return {randf(), randf()}; }

vec2 operator+(vec2 a, vec2 b) { return {a.x + b.x, a.y + b.y}; }
vec3 operator+(vec3 a, vec3 b) { return {a.x + b.x, a.y + b.y, a.z + b.z}; }
vec4 operator+(vec4 a, vec4 b) { return {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w}; }
vec2 operator+(vec2 a, float b) { return {a.x + b, a.y + b}; }
vec3 operator+(vec3 a, float b) { return {a.x + b, a.y + b, a.z + b}; }
vec4 operator+(vec4 a, float b) { return {a.x + b, a.y + b, a.z + b, a.w + b}; }
vec2 operator+(float a, vec2 b) { return b + a; }
vec3 operator+(float a, vec3 b) { return b + a; }
vec4 operator+(float a, vec4 b) { return b + a; }
vec2& operator+=(vec2& a, vec2 b) { return a = a + b; }
vec3& operator+=(vec3& a, vec3 b) { return a = a + b; }
vec4& operator+=(vec4& a, vec4 b) { return a = a + b; }
vec2& operator+=(vec2& a, float b) { return a = a + b; }
vec3& operator+=(vec3& a, float b) { return a = a + b; }
vec4& operator+=(vec4& a, float b) { return a = a + b; }

vec2 operator-(vec2 a, float b) { return {a.x - b, a.y - b}; }
vec3 operator-(vec3 a, float b) { return {a.x - b, a.y - b, a.z - b}; }
vec4 operator-(vec4 a, float b) { return {a.x - b, a.y - b, a.z - b, a.w - b}; }
vec2 operator-(float a, vec2 b) { return {a - b.x, a - b.y}; }
vec3 operator-(float a, vec3 b) { return {a - b.x, a - b.y, a - b.z}; }
vec4 operator-(float a, vec4 b) { return {a - b.x, a - b.y, a - b.z, a - b.w}; }
vec2 operator-(vec2 b) { return {-b.x, -b.y}; }
vec3 operator-(vec3 b) { return {-b.x, -b.y, -b.z}; }
vec4 operator-(vec4 b) { return {-b.x, -b.y, -b.z, -b.w}; }
vec2 operator-(vec2 a, vec2 b) { return {a.x - b.x, a.y - b.y}; }
vec3 operator-(vec3 a, vec3 b) { return {a.x - b.x, a.y - b.y, a.z - b.z}; }
vec4 operator-(vec4 a, vec4 b) { return {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w}; }
vec2& operator-=(vec2& a, vec2 b) { return a = a - b; }
vec3& operator-=(vec3& a, vec3 b) { return a = a - b; }
vec4& operator-=(vec4& a, vec4 b) { return a = a - b; }
vec2& operator-=(vec2& a, float b) { return a = a - b; }
vec3& operator-=(vec3& a, float b) { return a = a - b; }
vec4& operator-=(vec4& a, float b) { return a = a - b; }

vec2 operator*(vec2 a, vec2 b) { return {a.x * b.x, a.y * b.y}; }
vec3 operator*(vec3 a, vec3 b) { return {a.x * b.x, a.y * b.y, a.z * b.z}; }
vec4 operator*(vec4 a, vec4 b) { return {a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w}; }
vec2 operator*(vec2 a, float b) { return {a.x * b, a.y * b}; }
vec3 operator*(vec3 a, float b) { return {a.x * b, a.y * b, a.z * b}; }
vec4 operator*(vec4 a, float b) { return {a.x * b, a.y * b, a.z * b, a.w * b}; }
vec2 operator*(float a, vec2 b) { return {a * b.x, a * b.y}; }
vec3 operator*(float a, vec3 b) { return {a * b.x, a * b.y, a * b.z}; }
vec4 operator*(float a, vec4 b) { return {a * b.x, a * b.y, a * b.z, a * b.w}; }
vec2& operator*=(vec2& a, vec2 b) { return a = a * b; }
vec3& operator*=(vec3& a, vec3 b) { return a = a * b; }
vec4& operator*=(vec4& a, vec4 b) { return a = a * b; }
vec2& operator*=(vec2& a, float b) { return a = a * b; }
vec3& operator*=(vec3& a, float b) { return a = a * b; }
vec4& operator*=(vec4& a, float b) { return a = a * b; }

vec2 operator/(vec2 a, vec2 b) { return {a.x / b.x, a.y / b.y}; }
vec3 operator/(vec3 a, vec3 b) { return {a.x / b.x, a.y / b.y, a.z / b.z}; }
vec4 operator/(vec4 a, vec4 b) { return {a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w}; }
vec2 operator/(vec2 a, float b) { return {a.x / b, a.y / b}; }
vec3 operator/(vec3 a, float b) { return {a.x / b, a.y / b, a.z / b}; }
vec4 operator/(vec4 a, float b) { return {a.x / b, a.y / b, a.z / b, a.w / b}; }
vec2 operator/(float a, vec2 b) { return {a / b.x, a / b.y}; }
vec3 operator/(float a, vec3 b) { return {a / b.x, a / b.y, a / b.z}; }
vec4 operator/(float a, vec4 b) { return {a / b.x, a / b.y, a / b.z, a / b.w}; }
vec2& operator/=(vec2& a, vec2 b) { return a = a / b; }
vec3& operator/=(vec3& a, vec3 b) { return a = a / b; }
vec4& operator/=(vec4& a, vec4 b) { return a = a / b; }
vec2& operator/=(vec2& a, float b) { return a = a / b; }
vec3& operator/=(vec3& a, float b) { return a = a / b; }
vec4& operator/=(vec4& a, float b) { return a = a / b; }

float dot(vec2 a, vec2 b) { return a.x * b.x + a.y * b.y; }
float dot(vec3 a, vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
float dot(vec4 a, vec4 b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }
float len2(vec2 v) { return v.x * v.x + v.y * v.y; }
float len2(vec3 v) { return v.x * v.x + v.y * v.y + v.z * v.z; }
float len2(vec4 v) { return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w; }
float len(vec2 v) { return sqrtf(len2(v)); }
float len(vec3 v) { return sqrtf(len2(v)); }
float len(vec4 v) { return sqrtf(len2(v)); }

vec2 lrot(vec2 a) { return {-a.y, a.x}; }
float cross(vec2 a, vec2 b) { return a.x * b.y - a.y * b.x; }
vec2 lerp(vec2 a, vec2 b, float t) { return a + t * (b - a); }

vec2 normalize(vec2 v, float eps, vec2 u0) { 
	float l = len(v);
	return l < eps ? u0 : v / l;
}
vec3 normalize(vec3 v, float eps, vec3 u0) { 
	float l = len(v);
	return l < eps ? u0 : v / l;
}
vec4 normalize(vec4 v, float eps, vec4 u0) { 
	float l = len(v);
	return l < eps ? u0 : v / l;
}

Mat2x2 Mat2x2::inv() const { float D = det(); return {d / D, -b / D, -c / D, a / D}; }
float Mat2x2::det() const { return a * d - b * c; }
Mat2x2 Mat2x2::transposed() const { return {a, c, b, d}; }
Mat2x2 Mat2x2::operator*(const Mat2x2& B) const { return { a * B.a + b * B.c, a * B.b + b * B.d, c * B.a + d * B.c, c * B.b + d * B.d}; }
vec2 Mat2x2::operator*(vec2 v) const { return { a * v.x + b * v.y, c * v.x + d * v.y }; }
