#include <cstdint>
#include <vector>
#include <array>

#include "glm/glm.hpp"
#include "vulkan/vulkan_core.h"

#define MAX_OBJ 1024

struct UniformBufferObject
{
  glm::mat4 proj;
  glm::mat4 view;
  glm::mat4 model[MAX_OBJ];
  int from[MAX_OBJ];
};

struct Vertex
{
  glm::vec3 pos;
  glm::vec3 normal;
  glm::vec2 uv;

  static VkVertexInputBindingDescription getBindingDescription();
  static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions();
};

class RendererInterface
{
public:
  std::vector<Vertex> vertices;
  std::vector<uint16_t> indices;
  std::vector<UniformBufferObject> ubo;
};
