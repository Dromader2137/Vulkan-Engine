#include <memory>
#include <vector>

class Component
{
public:
  void OnStart() { }
  void OnCreate() { }
  void OnUpdate() { }
  void OnDestroy() { }
};

class GameObject
{
public:
  void OnStart();
  void OnUpdate();

  GameObject();
  ~GameObject();

private:
  std::vector<std::unique_ptr<Component>> components;
};

