#pragma once

#include "rendererInterface.h"
#include <vulkan/vulkan_core.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <optional>
#include <string>

struct SwapChainSupportDetails
{
  VkSurfaceCapabilitiesKHR capabilities;
  std::vector<VkSurfaceFormatKHR> formats;
  std::vector<VkPresentModeKHR> presentModes;
};

struct QueueFamilyIndices
{
  std::optional<uint32_t> graphicsFamily; 
  std::optional<uint32_t> presentFamily;

  bool IsComplete();
};

class Renderer
{
public:
  void init();
  void render();
 
  GLFWwindow* getWindow() { return window; }
  VkDevice getLogicalDevice() { return logicalDevice; }

  Renderer(int windowWidth, int windowHeight, RendererInterface* rendererInterface) : windowWidth(windowWidth), windowHeight(windowHeight), rendererInterface(rendererInterface) {}

  ~Renderer();

private:
  RendererInterface* rendererInterface;
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
  VkDescriptorSetLayout descriptorSetLayout;
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
  VkBuffer uniformBuffers;
  VkDeviceMemory uniformBuffersMemory;
  void* uniformBuffersMapped;
  VkDescriptorPool descriptorPool;
  VkDescriptorSet descriptorSet[1];
  VkImage depthImage;
  VkDeviceMemory depthImageMemory;
  VkImageView depthImageView;
  const std::vector<const char*> deviceExtensions = {VK_KHR_SWAPCHAIN_EXTENSION_NAME, VK_KHR_UNIFORM_BUFFER_STANDARD_LAYOUT_EXTENSION_NAME};
    
  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
  std::vector<char> readFile(const std::string& filename);
  bool checkValidationLayerSupport();
  VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags);
  void createImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
  
  void initWindow();
  void createInstance();
  void createSurface();
    bool isDeviceSuitable(VkPhysicalDevice device);
      bool checkDeviceExtensionSupport(VkPhysicalDevice device);
  void prepareDevices();
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
  void createSwapChain();
  void createDescriptorSetLayout();
  void createGraphicsPipeline();
    VkShaderModule createShaderModule(const std::vector<char>& code);
  void createFramebuffers();
  void createCommandPool();
  void createRenderingBuffers();
    void createBuffer(VkBuffer& buffer, VkDeviceMemory& bufferMemory, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties);
    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
  void createUniformBuffers();
  void createDescriptorPool();
  void createDescriptorSets();
  void updateUniformBuffer();
  void createCommandBuffer();
  void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
  void createSyncObjects();
  void createDepthResources();
    VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
    VkFormat findDepthFormat();
    bool hasStencilComponent(VkFormat format);
  
  void cleanupSwapChain();
  void recreateSwapChain();
};
