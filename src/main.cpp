#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "renderer.h"
#include "gameObject.h"
#include "components.h"
#include "inputInterface.h"


 /*
  *
  *  INCLUDE YOUR HEADERS FROM HERE
  *
  */
  
 /*
  *
  *  INCLUDE YOUR HEADERS TO HERE
  *
  */

int main()
{
  /*
   *
   *  WRITE YOUR CODE FROM HERE
   *
   */
  
  /*
   *
   *  WRITE YOUR CODE TO HERE
   *
   */
  
  RendererInterface rendererInterface;
  rendererInterface.ubo.view = glm::lookAt(glm::vec3(2.0f, 2.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
  rendererInterface.ubo.proj = glm::perspective(glm::radians(45.0f), 1600 / 900.0f, 0.1f, 10.0f); 
  rendererInterface.ubo.proj[1][1] *= -1;
  
  Renderer renderer = Renderer(1600, 900, &rendererInterface);
  renderer.init();

  InputInterface inputInterface = InputInterface();
  inputInterface.window = renderer.getWindow();

  GameState gameState;
  gameState.rendererInterface = &rendererInterface;
  gameState.inputInterface = &inputInterface;
  
  for(auto& obj : GameObject::gameObjects)
    obj->OnStart();

  while(!glfwWindowShouldClose(renderer.getWindow())) 
  {
    glfwPollEvents();
    for(int i = 0; i < GameObject::gameObjects.size(); ++i)
    {
      GameObject::gameObjects[i]->OnUpdate(gameState);
      rendererInterface.ubo.model[GameObject::gameObjects[i]->id] = GameObject::gameObjects[i]->GetModelMatrix();
    }
    renderer.render(); 
  }
  vkDeviceWaitIdle(renderer.getLogicalDevice());
} 
