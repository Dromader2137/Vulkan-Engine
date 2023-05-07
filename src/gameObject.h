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
  std::vector<Component*> components;
  
  void OnStart();
  void OnUpdate();

  GameObject();
  ~GameObject();
};

