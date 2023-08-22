#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "rendererInterface.h"

class InputInterface
{
private:
  glm::vec2 prevMousePos;

public:
  RendererInterface* rendererInterface;

  bool IsKeyPressed(int keyCode);

  glm::vec2 GetMousePosition();
  glm::vec2 GetMouseDelta();

  void LateUpdate();
};
