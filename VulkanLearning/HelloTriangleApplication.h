#pragma once
#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>

class HelloTriangleApplication
{
public:
	void Run();

private:
	void InitWindow();
	void InitVulkan();
	void MainLoop();
	void Cleanup();
	void CreateInstance();

	bool CheckValidationLayerSupport();

	GLFWwindow* window;
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;

	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;

	// Validation Layers for Vulkan
	const std::vector<const char*> validationLayers = {
		"VK_LAYER_KHRONOS_validation"
	};

#ifdef NODEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

	std::vector<const char*> GetRequiredExtentions();

	static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);

	void SetupDebugMessenger() { if (!enableValidationLayers) return; }
	void PopulateDebugMessengerCreateInfo();
};

