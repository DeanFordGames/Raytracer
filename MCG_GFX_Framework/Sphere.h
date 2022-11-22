#include <GLM/glm.hpp>

#include "Ray.h"

class Sphere
{
public:

	Sphere();

	glm::vec3 calculateColour(Ray ray, glm::vec3 intersection);

	glm::vec3 rayToSphere(Ray ray);

	glm::vec3 _surfaceColour;
	glm::vec3 _centre;
	float _radius;

	bool _hit;

};
