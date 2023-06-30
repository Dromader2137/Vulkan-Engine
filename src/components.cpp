#include "components.h"

#include <cstring>
#include <vector>

//MESH

std::vector<Mesh*> Mesh::meshes;

void Mesh::UpdateMesh()
{
  rendererInterface->vertices.clear();
  rendererInterface->indices.clear();
  int indexOffset = 0;
  for(auto x : meshes)
  {
    for(auto v : x->vertices)
    {
      rendererInterface->vertices.push_back(v);
    }
    int newOffset = indexOffset;
    for(auto i : x->indices)
    {
      newOffset = std::max(newOffset, i + indexOffset);
      rendererInterface->indices.push_back(i + indexOffset);
    }
    indexOffset = newOffset + 1;
  }
}

Mesh::Mesh(RendererInterface* ri)
{
  rendererInterface = ri;
  meshes.push_back(this);
}

Mesh::~Mesh()
{
  for(std::vector<Mesh*>::iterator it = meshes.begin(); it != meshes.end(); ++it)
  {
    if(*it == this)
    {
      meshes.erase(it);
      break;
    }
  }
}
