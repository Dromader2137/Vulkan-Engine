#include "gameObject.h"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <vector>

std::vector<GameObject*> GameObject::gameObjects = {};

glm::mat4 GameObject::GetModelMatrix()
{
  return glm::translate(glm::mat4(1.0f), glm::vec3(position))
       * glm::scale(glm::mat4(1.0f), scale)
       * glm::toMat4(rotation);
}

void GameObject::OnStart()
{
  for(auto& comp : components)
  {
    comp->OnStart();
  }
}

void GameObject::OnUpdate()
{
  for(auto& comp : components)
  {
    comp->OnUpdate();
  }
}

GameObject::GameObject(uint16_t id) : id(id)
{
  for(auto& comp : components)
  {
    comp->OnCreate();
  }
}

GameObject::~GameObject()
{
  for(auto& comp : components)
  {
    comp->OnDestroy();
  }
}
