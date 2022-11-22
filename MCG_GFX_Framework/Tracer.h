#include <GLM/glm.hpp>
#include "Ray.h"
#include "Sphere.h"

#include <vector>

class Tracer
{
public:
	Tracer();

	glm::vec3 returnColour(Ray ray);

	std::vector<Sphere> objects;

};
