#include "Camera.h"


Camera::Camera()
{
	m_projMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	m_viewMatrix = glm::mat4(1);//glm::lookAt(glm::vec3(10.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

Ray Camera::returnRay(glm::ivec2 pos, glm::ivec2 screen)
{
	Ray rtn = Ray();

	float x = static_cast <float>(pos.x);
	float sX = static_cast <float> (screen.x);

	float y = static_cast <float>(pos.y);
	float sY = static_cast <float> (screen.y);

	float ndcX = (x / sX - 0.5f) * 2.0f;
	float ndcY = (y / sY - 0.5f) * 2.0f;

	rtn._origin.x = ndcX;
	rtn._origin.y = ndcY;
	rtn._origin.z = -1.0f;

	rtn._direction.x = ndcX;
	rtn._direction.y = ndcY;
	rtn._direction.z = 1.0f;

	//rtn._direction = glm::normalize(rtn._direction);

	glm::vec4 origin = glm::vec4(rtn._origin, 1.0f);
	glm::vec4 dir = glm::vec4(rtn._direction, 1.0f);

	origin = glm::inverse(m_projMatrix) * origin;
	dir = glm::inverse(m_projMatrix) * dir;
	
	origin /= origin.w;
	dir /= dir.w;

	origin = glm::inverse(m_viewMatrix) * origin;
	dir = glm::inverse(m_viewMatrix) * dir;

	rtn._origin = origin;
	rtn._direction = glm::normalize(dir - origin);

	return rtn;
}