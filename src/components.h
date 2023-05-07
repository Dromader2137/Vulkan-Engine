#include "gameObject.h"
#include "renderer.h"

#include <cstdint>
#include <vector>

class Mesh : public Component
{
  std::vector<Vertex> vertices;
  std::vector<uint16_t> indices;
};
