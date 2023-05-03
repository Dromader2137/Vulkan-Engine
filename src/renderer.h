#include <vulkan/vulkan_core.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <vector>
#include <optional>
#include <cstdint>
#include <array>
#include <string>

struct QueueFamilyIndices
{
  std::optional<uint32_t> graphicsFamily; 
  std::optional<uint32_t> presentFamily;

  bool IsComplete();
};

struct Vertex
{
  glm::vec3 pos;

  static VkVertexInputBindingDescription getBindingDescription();
  static std::array<VkVertexInputAttributeDescription, 1> getAttributeDescriptions();
};

class Renderer
{
public:
  std::vector<uint16_t> indices;
  std::vector<Vertex> vertices;

  void init();
  void render();
 
  Renderer(int windowWidth, int windowHeight);

  ~Renderer();

private:
  int windowWidth = 1600, windowHeight = 900;
  GLFWwindow* window;
  VkSurfaceKHR renderSurface;
  VkInstance instance;
  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  VkDevice logicalDevice;
  VkQueue graphicsCommandQueue;
  VkQueue presentCommandQueue;
  VkSwapchainKHR swapChain;
  std::vector<VkImage> swapChainImages;
  VkFormat swapChainImageFormat;
  VkExtent2D swapChainExtent;
  std::vector<VkImageView> swapChainImageViews;
  std::vector<VkFramebuffer> swapChainFramebuffers;
  VkPipeline graphicsPipeline;
  VkPipelineLayout pipelineLayout;
  VkRenderPass renderPass;
  VkCommandPool commandPool;
  VkCommandBuffer commandBuffer;
  VkSemaphore imageAvailableSemaphore;
  VkSemaphore renderFinishedSemaphore;
  VkFence inFlightFence;
  VkBuffer vertexBuffer;
  VkDeviceMemory vertexBufferMemory;
  VkBuffer indexBuffer;
  VkDeviceMemory indexBufferMemory;
    
  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
  std::vector<char> readFile(const std::string& filename);
  
  void initWindow();
  void createInstance();
  void createSurface();
  void prepareDevices();
  void createSwapChain();
  void createGraphicsPipeline();
    VkShaderModule createShaderModule(const std::vector<char>& code);
  void createFramebuffers();
  void createCommandPool();
  void createRenderingBuffers();
    void createBuffer(VkBuffer& buffer, VkDeviceMemory& bufferMemory, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties);
    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
  void createCommandBuffer();
  void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
  void createSyncObjects();
};
