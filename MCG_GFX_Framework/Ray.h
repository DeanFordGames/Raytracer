#pragma once
#include <GLM/glm.hpp>

class Ray
{
public:

	Ray();

	glm::vec3 closestPointOnLine(glm::vec3 queryPoint);

	glm::vec3 _origin;
	glm::vec3 _direction;

};