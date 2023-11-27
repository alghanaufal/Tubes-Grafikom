#include "Engine.h"

void Engine::Update()
{
	cameraPosition += cameraMovement * timeToDrawFrame;
	if (cameraPosition.x < -mapXSize || cameraPosition.x > mapXSize || cameraPosition.z < -mapZSize || cameraPosition.z > mapZSize)
	{
		cameraPosition.x -= cameraMovement.x * timeToDrawFrame;
		cameraPosition.z -= cameraMovement.z * timeToDrawFrame;
	}

	cameraRotation += rotationSpeed * timeToDrawFrame;

	theta += timeToDrawFrame;

	// Handle wall collision
	for (auto w : maze)
	{
		if (cameraPosition.x > w.x - wallSize - 0.1f && cameraPosition.x < w.x + wallSize + 0.1f &&
			cameraPosition.z > w.z - wallSize - 0.1f && cameraPosition.z < w.z + wallSize + 0.1f)
		{
			cameraPosition.x -= cameraMovement.x * timeToDrawFrame;
			cameraPosition.z -= cameraMovement.z * timeToDrawFrame;
			break;
		}
	}

	// Check to see if the player found the exit
	glm::vec3 distanceToExit = exitPos - cameraPosition;
	if (glm::sqrt(distanceToExit.x * distanceToExit.x + distanceToExit.y * distanceToExit.y + distanceToExit.z * distanceToExit.z) < 1.0f)
	{
		GenerateMaze(1);
		return;
	}

	// Check to see if the player found the monster
	for (std::vector<glm::vec3>::iterator it = monster.begin(); it != monster.end(); it++)
	{
		glm::vec3 tempMonster = *it;
		glm::vec3 distanceToMonster = tempMonster - cameraPosition;
		if (glm::sqrt(distanceToMonster.x * distanceToMonster.x + distanceToMonster.y * distanceToMonster.y + distanceToMonster.z * distanceToMonster.z) < 2.0f)
		{
			// monster.erase(it);
			GenerateMaze(0);
			break;
		}
	}

	// Have gravity affect the camera
	if (cameraPosition.y > 2.5f)
	{
		if (cameraPosition.y > 25.0f)
		{
			cameraPosition.y = 30.0f;
		}
		else
		{
			cameraMovement.y -= 22.0f * timeToDrawFrame;
		}
	}
	else if (cameraPosition.y < 2.5f)
	{
		if (cameraPosition.y <= 2.5f)
		{
			cameraPosition.y = 2.5f;
			cameraMovement.y = 0.0f;
		}
	}

	glfwPollEvents();
}
