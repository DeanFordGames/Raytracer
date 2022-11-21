#include "Camera.h"


Camera::Camera()
{
	m_projMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	m_viewMatrix = glm::lookAt(glm::vec3(10.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

Ray Camera::returnRay(glm::ivec2 pos, glm::ivec2 screen)
{
	Ray rtn = Ray();

	float x = static_cast <float>(pos.x);
	float sX = static_cast <float> (screen.x);

	float y = static_cast <float>(pos.y);
	float sY = static_cast <float> (screen.y);

	float ndcX = (x / sX - 0.5f) * 2;
	float ndcY = (y / sY - 0.5f) * 2;

	rtn._origin.x = pos.x;
	rtn._origin.y = pos.y;
	rtn._origin.z = -1.0f;

	rtn._direction.x = pos.x;
	rtn._direction.y = pos.y;
	rtn._direction.z = 1.0f;

	rtn._direction = glm::normalize(rtn._direction);

	glm::vec4 origin = glm::vec4(rtn._origin, 1.0f);
	glm::vec4 dir = glm::vec4(rtn._direction, 1.0f);

	origin = origin * glm::inverse(m_projMatrix);
	dir = dir * glm::inverse(m_projMatrix);
	
	origin /= origin.w;
	dir /= dir.w;

	origin = origin * glm::inverse(m_viewMatrix);
	dir = dir * glm::inverse(m_viewMatrix);

	rtn._origin = origin;
	rtn._direction = dir;

	return rtn;
}