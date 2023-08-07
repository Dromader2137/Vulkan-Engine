#pragma once

#include <GLFW/glfw3.h>

class InputInterface
{
public:
  GLFWwindow* window;

  bool IsKeyPressed(int keyCode);
};
