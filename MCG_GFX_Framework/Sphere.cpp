#include "Sphere.h"

#include <iostream>

Sphere::Sphere()
{
	_centre = glm::vec3(0.0f, 0.0f, -10.0f);
	_surfaceColour = glm::vec3(1.0f, 0.3f, 0.3f);
	_radius = 1.0f;
	_hit = false;
}

glm::vec3 Sphere::calculateColour(Ray ray, glm::vec3 intersection)
{
	glm::vec3 rtn = glm::vec3(1.0f, 0.2f, 0.1f);
	glm::vec3 distantLight = glm::normalize(glm::vec3(-0.4f, -0.4f, 0.4f));
	glm::vec3 sphereNormal = glm::normalize(intersection - _centre);
	glm::vec3 lightColour = glm::vec3(1.0f, 1.0f, 1.0f);

	rtn = _surfaceColour * lightColour * glm::max(glm::dot(sphereNormal, distantLight), 0.0f);

	return rtn;
}

glm::vec3 Sphere::rayToSphere(Ray ray)
{
	/*
	if (!powf((ray._origin.x - _centre.x), 2) +
		powf((ray._origin.y - _centre.y), 2) +
		powf((ray._origin.z - _centre.z), 2) <
		(_radius * _radius))
		*/
	// checking if ray's origin is inside sphere
	if( glm::distance(ray._origin,_centre) > _radius )
	{

		//glm::vec3 point = ray.closestPointOnLine(_centre);
		glm::vec3 temp = _centre - ray._origin;
		// distance from ray's origin to closest point to centre of sphere
		float rayLengthToClosestPoint = glm::dot(temp, ray._direction);

		// closest point on line
		glm::vec3 point = ray._origin + (ray._direction * rayLengthToClosestPoint);

		// Distance 'd' in teh equations
		float distToClosestPoint = glm::distance(point, _centre);


		//if (glm::dot(glm::normalize(ray._direction), (point - ray._origin)) <= 0.0f)

		// main intersection check
		if(distToClosestPoint <= _radius )
		{
			float x = glm::sqrt(_radius * _radius - distToClosestPoint * distToClosestPoint);

			_hit = true;
			return ray._origin + (glm::dot((_centre - ray._origin), ray._direction) - x) * ray._direction;

		}
		else
		{
			_hit = false;
			return glm::vec3(0.0f, 0.0f, 0.0f);
		}
	}
	else
	{
		_hit = false;
		return glm::vec3(0.0f, 0.0f, 0.0f);
	}
}