#include <GLM/glm.hpp>
#include "Ray.h"

class Tracer
{
public:
	Tracer();

	glm::vec3 returnColour(Ray ray);

};
