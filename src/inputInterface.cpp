#include "inputInterface.h"

bool InputInterface::IsKeyPressed(int keyCode)
{
  return glfwGetKey(rendererInterface->window, keyCode) == GLFW_PRESS;
}

glm::vec2 InputInterface::GetMousePosition()
{
  glm::dvec2 pos;
  glfwGetCursorPos(rendererInterface->window, &pos.x, &pos.y);
  return pos;
}

glm::vec2 InputInterface::GetMouseDelta()
{
  return GetMousePosition() - prevMousePos;
}

void InputInterface::LateUpdate()
{
  prevMousePos = GetMousePosition();
}
