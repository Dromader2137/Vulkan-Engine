#include "gameObject.h"

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

GameObject::GameObject()
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
