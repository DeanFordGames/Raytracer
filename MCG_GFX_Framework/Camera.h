#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>

#include "Ray.h"

class Camera
{
public:

	Camera();

	Ray returnRay(glm::ivec2 pos, glm::ivec2 screen);

private:

	glm::mat4 m_viewMatrix;
	glm::mat4 m_projMatrix;

};