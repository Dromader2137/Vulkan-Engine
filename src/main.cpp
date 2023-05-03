#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "renderer.h"

int main()
{
  Renderer renderer = Renderer(1600, 900);
  renderer.init();

  while(!glfwWindowShouldClose(renderer.getWindow())) 
  { 
    glfwPollEvents();
    renderer.render(); 
  }
  vkDeviceWaitIdle(renderer.getLogicalDevice());
}
