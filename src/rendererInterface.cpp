#include "rendererInterface.h"
#include <cstdint>
#include <vector>
#include <vulkan/vulkan_core.h>

// VERTEX

VkVertexInputBindingDescription Vertex::getBindingDescription()
{
  VkVertexInputBindingDescription bindingDescription{};
    
  bindingDescription.binding = 0;
  bindingDescription.stride = sizeof(Vertex);
  bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
      
  return bindingDescription;
}

std::array<VkVertexInputAttributeDescription, 1> Vertex::getAttributeDescriptions()
{
  std::array<VkVertexInputAttributeDescription, 1> attributeDescriptions{};
    
  attributeDescriptions[0].binding = 0;
  attributeDescriptions[0].location = 0;
  attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
  attributeDescriptions[0].offset = offsetof(Vertex, pos); 

  return attributeDescriptions;
}

// INTERFACE

std::vector<Vertex> RendererInterface::vertices = 
{
  {{0.0f, -0.5f, 0.0f}},
  {{-0.5f, 0.5f, 0.0f}},
  {{0.5f, 0.5f, 0.0f}}
};

std::vector<uint16_t> RendererInterface::indices =
{
  0, 1, 2
};
