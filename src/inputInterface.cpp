#include "inputInterface.h"

bool InputInterface::IsKeyPressed(int keyCode)
{
  return glfwGetKey(window, keyCode) == GLFW_PRESS;
}
