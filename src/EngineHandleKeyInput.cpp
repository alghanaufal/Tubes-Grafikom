#include "Engine.h"

void Engine::HandleKeyInput(GLFWwindow *win, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		switch (key)
		{
		// Move around
		case GLFW_KEY_W:
			cameraMovement.x = playerSpeed * glm::sin(cameraRotation);
			cameraMovement.z = playerSpeed * -glm::cos(cameraRotation);
			break;
		case GLFW_KEY_S:
			cameraMovement.x = playerSpeed * -glm::sin(cameraRotation);
			cameraMovement.z = playerSpeed * glm::cos(cameraRotation);
			break;
		// Rotate the camera
		case GLFW_KEY_A:
			rotationSpeed = -playerRotationSpeed;
			break;
		case GLFW_KEY_D:
			rotationSpeed = playerRotationSpeed;
			break;
		// Move around
		case GLFW_KEY_M:
			cameraPosition.y = 30.0f;
			break;
		case GLFW_KEY_N:
			cameraPosition.y = 2.0f;
			break;
		// Jump
		case GLFW_KEY_SPACE:
			if (cameraPosition.y <= 2.5f)
				cameraMovement.y = 15.0f;
			break;
		}
	}

	else if (action == GLFW_RELEASE)
	{
		switch (key)
		{
		// Stop moving
		case GLFW_KEY_W:
			cameraMovement.x = 0.0f;
			cameraMovement.z = 0.0f;
			break;
		case GLFW_KEY_S:
			cameraMovement.x = 0.0f;
			cameraMovement.z = 0.0f;
			break;
		// Stop rotating the camera the camera
		case GLFW_KEY_A:
			rotationSpeed = 0.0f;
			break;
		case GLFW_KEY_D:
			rotationSpeed = 0.0f;
			break;
		// Stop moving
		case GLFW_KEY_M:
			cameraMovement.x = 0.0f;
			cameraMovement.y = 0.0f;
			cameraMovement.z = 0.0f;
			break;
		case GLFW_KEY_N:
			cameraMovement.x = 0.0f;
			cameraMovement.y = 0.0f;
			cameraMovement.z = 0.0f;
			break;
		}
	}
}