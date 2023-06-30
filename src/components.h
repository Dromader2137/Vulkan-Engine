#pragma once

#include "gameObject.h"
#include "rendererInterface.h"

#include <cstdint>
#include <vector>

class Mesh : public Component
{
public:
  void UpdateMesh();

  std::vector<Vertex> vertices;
  std::vector<uint16_t> indices;
  static std::vector<Mesh*> meshes;

  Mesh(RendererInterface* ri);
  ~Mesh();

private:
  RendererInterface* rendererInterface;
};
