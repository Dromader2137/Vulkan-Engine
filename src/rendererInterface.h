#include <cstdint>
#include <vector>
#include <array>

#include "glm/glm.hpp"
#include "vulkan/vulkan_core.h"

struct Vertex
{
  glm::vec3 pos;

  static VkVertexInputBindingDescription getBindingDescription();
  static std::array<VkVertexInputAttributeDescription, 1> getAttributeDescriptions();
};

class RendererInterface
{
public:
  static std::vector<Vertex> vertices;
  static std::vector<uint16_t> indices;
};
