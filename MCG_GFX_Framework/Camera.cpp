#include "Camera.h"

Camera::Camera()
{

}

Ray Camera::returnRay(glm::ivec2 pos)
{
	Ray rtn = Ray();
	
	rtn._origin.x = pos.x;
	rtn._origin.y = pos.y;

	return rtn;
}