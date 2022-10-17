#pragma once
#include <cstdint>
#include <SFML/Graphics.hpp>

typedef uint8_t u8;
typedef int8_t s8;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;

struct vec2 { float x, y; };
struct vec3 { float x, y, z; };
struct vec4 { float x, y, z, w; };

struct Mat2x2 { 
	float a, b, c, d; 
	Mat2x2 inv() const;
	float det() const;
	Mat2x2 transposed() const;
	Mat2x2 operator*(const Mat2x2& B) const;
	vec2 operator*(vec2 v) const;
};


sf::Vector2f to_sfml(vec2 v);
sf::Vector3f to_sfml(vec3 v);
vec2 to_cm(sf::Vector2f v);
vec3 to_cm(sf::Vector3f v);

bool operator==(vec2 a, vec2 b);
bool operator==(vec3 a, vec3 b);
bool operator==(vec4 a, vec4 b);
bool operator!=(vec2 a, vec2 b);
bool operator!=(vec3 a, vec3 b);
bool operator!=(vec4 a, vec4 b);

float randf();
vec2 rand_vec2();

vec2 operator+(vec2 a, vec2 b);
vec3 operator+(vec3 a, vec3 b);
vec4 operator+(vec4 a, vec4 b);
vec2 operator+(vec2 a, float b);
vec3 operator+(vec3 a, float b);
vec4 operator+(vec4 a, float b);
vec2 operator+(float a, vec2 b);
vec3 operator+(float a, vec3 b);
vec4 operator+(float a, vec4 b);
vec2& operator+=(vec2& a, vec2 b);
vec3& operator+=(vec3& a, vec3 b);
vec4& operator+=(vec4& a, vec4 b);
vec2& operator+=(vec2& a, float b);
vec3& operator+=(vec3& a, float b);
vec4& operator+=(vec4& a, float b);

vec2 operator-(vec2 a, float b);
vec3 operator-(vec3 a, float b);
vec4 operator-(vec4 a, float b);
vec2 operator-(float a, vec2 b);
vec3 operator-(float a, vec3 b);
vec4 operator-(float a, vec4 b);
vec2 operator-(vec2 b);
vec3 operator-(vec3 b);
vec4 operator-(vec4 b);
vec2 operator-(vec2 a, vec2 b);
vec3 operator-(vec3 a, vec3 b);
vec4 operator-(vec4 a, vec4 b);
vec2& operator-=(vec2& a, vec2 b);
vec3& operator-=(vec3& a, vec3 b);
vec4& operator-=(vec4& a, vec4 b);
vec2& operator-=(vec2& a, float b);
vec3& operator-=(vec3& a, float b);
vec4& operator-=(vec4& a, float b);

vec2 operator*(vec2 a, vec2 b);
vec3 operator*(vec3 a, vec3 b);
vec4 operator*(vec4 a, vec4 b);
vec2 operator*(vec2 a, float b);
vec3 operator*(vec3 a, float b);
vec4 operator*(vec4 a, float b);
vec2 operator*(float a, vec2 b);
vec3 operator*(float a, vec3 b);
vec4 operator*(float a, vec4 b);
vec2& operator*=(vec2& a, vec2 b);
vec3& operator*=(vec3& a, vec3 b);
vec4& operator*=(vec4& a, vec4 b);
vec2& operator*=(vec2& a, float b);
vec3& operator*=(vec3& a, float b);
vec4& operator*=(vec4& a, float b);

vec2 operator/(vec2 a, vec2 b);
vec3 operator/(vec3 a, vec3 b);
vec4 operator/(vec4 a, vec4 b);
vec2 operator/(vec2 a, float b);
vec3 operator/(vec3 a, float b);
vec4 operator/(vec4 a, float b);
vec2 operator/(float a, vec2 b);
vec3 operator/(float a, vec3 b);
vec4 operator/(float a, vec4 b);
vec2& operator/=(vec2& a, vec2 b);
vec3& operator/=(vec3& a, vec3 b);
vec4& operator/=(vec4& a, vec4 b);
vec2& operator/=(vec2& a, float b);
vec3& operator/=(vec3& a, float b);
vec4& operator/=(vec4& a, float b);

float dot(vec2 a, vec2 b);
float dot(vec3 a, vec3 b);
float dot(vec4 a, vec4 b);
float len2(vec2 v);
float len2(vec3 v);
float len2(vec4 v);
float len(vec2 v);
float len(vec3 v);
float len(vec4 v);

vec2 lrot(vec2 a);
float cross(vec2 a, vec2 b);
vec2 lerp(vec2 a, vec2 b, float t);

vec2 normalize(vec2 v, float eps, vec2 u0);
vec3 normalize(vec3 v, float eps, vec3 u0);
vec4 normalize(vec4 v, float eps, vec4 u0);
