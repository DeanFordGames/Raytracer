#include "Sphere.h"

#include <iostream>

Sphere::Sphere()
{
	_centre = glm::vec3(0.0f, 0.0f, -10.0f);
	_surfaceColour = glm::vec3(1.0f, 0.3f, 0.3f);
	_radius = 1.0f;
	_hit = false;
	_shininess = 0.7f;
}

glm::vec3 Sphere::calculateColour(Ray ray, glm::vec3 intersection)
{
	glm::vec3 rtn = glm::vec3(1.0f, 0.2f, 0.1f);
	glm::vec3 distantLight = glm::normalize(glm::vec3(0.0f, 0.0f, 0.6f));
	glm::vec3 sphereNormal = glm::normalize(intersection - _centre);
	glm::vec3 lightColour = glm::vec3(1.0f, 1.0f, 1.0f);


	//calculate diffuse colour
	glm::vec3 diffuse = _surfaceColour * lightColour * glm::max(glm::dot(sphereNormal, distantLight), 0.0f);


	//stop specular light from appearing on oppisite side of sphere
	glm::vec3 facing = glm::vec3(1.0f);
	if (glm::dot(sphereNormal, distantLight) < 0)
		facing = glm::vec3(0.0f);

	//halfway point between ray and light
	//glm::vec3 halfway = (ray._direction + distantLight) / 2.0f;
	//calculate specular colour
	//glm::vec3 specular = _surfaceColour * lightColour * facing * powf((glm::max(glm::dot(sphereNormal, halfway), 0.0f)), _shininess);

	glm::vec3 surfaceToEye = glm::normalize(intersection - ray._origin);
	glm::vec3 reflection = glm::normalize(2.0f * glm::dot(sphereNormal, distantLight) * (sphereNormal - distantLight));
	glm::vec3 specular = _surfaceColour * lightColour * facing * powf((glm::max(glm::dot(reflection, surfaceToEye), 0.0f)), _shininess);

	//return value of colour
	rtn = diffuse + specular;

	return rtn;
}

glm::vec3 Sphere::rayToSphere(Ray ray)
{
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
			//intersection point
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