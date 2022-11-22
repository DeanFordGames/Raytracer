#include "Tracer.h"

Tracer::Tracer()
{
	object = Sphere();
}

glm::vec3 Tracer::returnColour(Ray ray)
{
	glm::vec3 rtn = glm::vec3(0.2f, 0.2f, 0.4f);

	glm::vec3 pos = object.rayToSphere(ray);

	if (object.rayToSphere(ray) != glm::vec3(0.0f, 0.0f, 0.0f))
	{
		rtn = object.calculateColour(ray, pos);
	}

	return rtn;
}
