#include "Tracer.h"


Tracer::Tracer()
{
	int x = 0;
	for (int i = -1; i < 2; i++)
	{
		for (int b = -1; b < 2; b++)
		{
			objects.push_back(Sphere());
			objects[x]._centre = glm::vec3(i * 2.0f, b * 2.0f, -10.0f);
			x++;
		}
	}
}

glm::vec3 Tracer::returnColour(Ray ray)
{
	glm::vec3 rtn = glm::vec3(0.2f, 0.2f, 0.4f);

	for each (Sphere object in objects)
	{
		glm::vec3 pos = object.rayToSphere(ray);
		if (object._hit == true)
		{
			rtn = object.calculateColour(ray, pos);
		}
	}

	return rtn;
}
