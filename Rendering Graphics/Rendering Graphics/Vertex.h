#pragma once
#include "src/gl_core_4_4.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#define GLM_SWIZZLE
#define GLM_FORCE_PURE
#include "src\Gizmos.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

using glm::vec3;
using glm::vec4;
using glm::mat4;
using namespace std;

class Vertex
{
public:
	vec4 position;
	vec4 colour;
};