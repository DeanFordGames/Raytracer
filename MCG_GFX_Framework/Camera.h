#include <GLM/glm.hpp>

#include "Ray.h"

class Camera
{
public:

	Camera();

	Ray returnRay(glm::ivec2 pos);

};