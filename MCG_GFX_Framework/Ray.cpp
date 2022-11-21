#include "Ray.h"

Ray::Ray()
{
	_origin = glm::vec3(0.0f, 0.0f, 0.0f);
	_direction = glm::vec3(0.0f, 0.0f, 0.0f);
}

glm::vec3 Ray::closestPointOnLine(glm::vec3 queryPoint)
{
	glm::vec3 temp = queryPoint - _origin;
	float dotP = glm::dot(temp, glm::normalize(_direction));

	glm::vec3 rtn = _origin + glm::normalize(_direction) * dotP;

	return rtn;
}