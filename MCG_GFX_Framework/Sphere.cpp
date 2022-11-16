#include "Sphere.h"

Sphere::Sphere()
{
	_centre = glm::vec3(0.0f, 0.0f, 0.0f);
	_radius = 1.0f;
}

glm::vec3 Sphere::calculateColour(Ray ray, glm::vec3 intersection)
{
	glm::vec3 rtn = glm::vec3(0.2, 0.2, 0.4);



	return rtn;
}

glm::vec3 Sphere::rayToSphere(Ray ray)
{
	if (!powf((ray._origin.x - _centre.x), 2) +
		powf((ray._origin.y - _centre.y), 2) +
		powf((ray._origin.z - _centre.z), 2) <
		(_radius * _radius))
	{
		glm::vec3 point = ray.closestPointOnLine(_centre);
		if (!glm::dot(glm::normalize(ray._direction), (point - ray._origin)))
		{
			float distance = sqrtf(powf((point.x - _centre.x), 2) +
				powf((point.y - _centre.y), 2) +
				powf((point.z - _centre.z), 2));
			if (distance >= -0.1f && distance <= 0.1f)
			{
				return point;
			}
			else
			{
				return glm::vec3(0.0f,0.0f,0.0f);
			}

		}
		else
		{
			return glm::vec3(0.0f, 0.0f, 0.0f);
		}
	}
	else
	{
		return glm::vec3(0.0f, 0.0f, 0.0f);
	}
}