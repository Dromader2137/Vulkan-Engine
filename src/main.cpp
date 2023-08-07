#include <memory>
#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "renderer.h"
#include "gameObject.h"
#include "components.h"
#include "inputInterface.h"

int main()
{
  RendererInterface rendererInterface;
  rendererInterface.ubo.view = glm::lookAt(glm::vec3(2.0f, 2.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
  rendererInterface.ubo.proj = glm::perspective(glm::radians(45.0f), 1600 / 900.0f, 0.1f, 10.0f); 
  rendererInterface.ubo.proj[1][1] *= -1;

  GameObject* gameObject = new GameObject(0);
  GameObject* gameObject1 = new GameObject(1);
  Mesh* mesh = new Mesh(&rendererInterface);
  gameObject->components.push_back(mesh);
  Mesh* meshh = new Mesh(&rendererInterface);
  gameObject1->components.push_back(meshh);
  
  mesh->vertices =
  {
    {{1.0f, 1.0f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}, 0, 2},
    {{1.0f, -1.0f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}, 0, 2},
    {{-1.0f, -1.0f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}, 0, 2},
    {{-1.0f, 1.0f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}, 0, 2},
    {{1.0f, 1.0f, -0.5f}, {1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{1.0f, -1.0f, -0.5f}, {1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{0.0f, 0.0f, 0.5f}, {1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{1.0f, -1.0f, -0.5f}, {0.0f, -1.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{-1.0f, -1.0f, -0.5f}, {0.0f, -1.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{0.0f, 0.0f, 0.5f}, {0.0f, -1.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{-1.0f, -1.0f, -0.5f}, {-1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{-1.0f, 1.0f, -0.5f}, {-1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{0.0f, 0.0f, 0.5f}, {-1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{-1.0f, 1.0f, -0.5f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{1.0f, 1.0f, -0.5f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{0.0f, 0.0f, 0.5f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
  };
  mesh->indices =
  {
    0, 1, 2, 3, 0, 2, 4, 6, 5, 7, 9, 8, 10, 12, 11, 13, 15, 14
  };

  meshh->vertices =
  {
    {{1.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 1, 3},
    {{1.0f, -1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 1, 3},
    {{-1.0f, -1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 1, 3},
    {{-1.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 1, 3},
  };
  meshh->indices =
  {
    0, 2, 1, 0, 3, 2
  };


  mesh->UpdateMesh();


  /*rendererInterface.vertices =
  {
    {{1.0f, 1.0f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}, 0, 2},
    {{1.0f, -1.0f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}, 0, 2},
    {{-1.0f, -1.0f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}, 0, 2},
    {{-1.0f, 1.0f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}, 0, 2},
    {{1.0f, 1.0f, -0.5f}, {1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{1.0f, -1.0f, -0.5f}, {1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{0.0f, 0.0f, 0.5f}, {1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{1.0f, -1.0f, -0.5f}, {0.0f, -1.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{-1.0f, -1.0f, -0.5f}, {0.0f, -1.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{0.0f, 0.0f, 0.5f}, {0.0f, -1.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{-1.0f, -1.0f, -0.5f}, {-1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{-1.0f, 1.0f, -0.5f}, {-1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{0.0f, 0.0f, 0.5f}, {-1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{-1.0f, 1.0f, -0.5f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{1.0f, 1.0f, -0.5f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
    {{0.0f, 0.0f, 0.5f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f}, 0, 2},
  };
  rendererInterface.indices =
  {
    0, 1, 2, 3, 0, 2, 4, 6, 5, 7, 9, 8, 10, 12, 11, 13, 15, 14
  };*/

  Renderer renderer = Renderer(1600, 900, &rendererInterface);
  renderer.init();

  InputInterface inputInterface = InputInterface();
  inputInterface.window = renderer.getWindow();
  
  GameObject::gameObjects.push_back(gameObject);  
  GameObject::gameObjects.push_back(gameObject1);  

  for(auto& obj : GameObject::gameObjects)
  {
    obj->OnStart();
  }
  while(!glfwWindowShouldClose(renderer.getWindow())) 
  {
    glfwPollEvents();
    for(int i = 0; i < GameObject::gameObjects.size(); ++i)
    {
      GameObject::gameObjects[i]->OnUpdate();
      std::cout << inputInterface.IsKeyPressed(GLFW_KEY_W);
      rendererInterface.ubo.model[GameObject::gameObjects[i]->id] = GameObject::gameObjects[i]->GetModelMatrix();
    }
    renderer.render(); 
  }
  vkDeviceWaitIdle(renderer.getLogicalDevice());
} 
