#pragma once

#include <cstdint>
#include <vector>
#include <array>

#include "glm/glm.hpp"
#include "vulkan/vulkan_core.h"
#include "GLFW/glfw3.h"

#define MAX_OBJ 512

struct UniformBufferObject
{
  alignas(16) glm::mat4 proj;
  alignas(16) glm::mat4 view;
  alignas(16) glm::mat4 model[MAX_OBJ];
};

struct Vertex
{
  glm::vec3 pos;
  glm::vec3 normal;
  glm::vec2 uv;
  int obj;
  int mat;

  static VkVertexInputBindingDescription getBindingDescription();
  static std::array<VkVertexInputAttributeDescription, 5> getAttributeDescriptions();
};

class RendererInterface
{
public:
  std::vector<Vertex> vertices;
  std::vector<uint16_t> indices;
  UniformBufferObject ubo;
  GLFWwindow* window;
};
