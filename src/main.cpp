#include <memory>
#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "renderer.h"
#include "gameObject.h"



int main()
{
  RendererInterface rendererInterface;
  rendererInterface.vertices =
  {
    {{0.0f, -0.8f, 0.5f}},
    {{-0.8f, 0.8f, 0.5f}},
    {{0.8f, 0.8f, 0.5f}}
  };
  rendererInterface.indices =
  {
    0, 2, 1
  };

  Renderer renderer = Renderer(1600, 900, &rendererInterface);
  renderer.init();
  
  std::vector<GameObject*> gameObjects; 
  gameObjects.push_back(new GameObject);  

  for(auto& obj : gameObjects)
  {
    obj->OnStart();
  }
  while(!glfwWindowShouldClose(renderer.getWindow())) 
  {
    glfwPollEvents();
    for(auto& obj : gameObjects)
    {
      obj->OnUpdate();
    }
    renderer.render(); 
  }
  vkDeviceWaitIdle(renderer.getLogicalDevice());
} 
