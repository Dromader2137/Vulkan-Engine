#pragma once

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <memory>
#include <vector>

class Component
{
public:
  virtual void OnStart() { }
  virtual void OnCreate() { }
  virtual void OnUpdate() { }
  virtual void OnDestroy() { }
};

class GameObject
{
public:
  static std::vector<GameObject*> gameObjects;

  uint16_t id;
  std::vector<Component*> components;
  
  glm::dvec3 position = glm::dvec3(0.0, 0.0, 0.0);
  glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
  glm::quat rotation = glm::quat();

  glm::mat4 GetModelMatrix();

  void OnStart();
  void OnUpdate();

  GameObject(uint16_t id);
  ~GameObject();
};

