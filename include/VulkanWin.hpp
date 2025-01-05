#pragma once

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>

class VulkanWin
{
	public:
		VulkanWin(const char *AppName, const uint32_t widthWin, const uint32_t heightWin);
		~VulkanWin(void);

		run(void);
	private:
		/* Variables */
		GLFWwindow *window;
		VkInstance	VkInstance;
		const char	*AppName;
		const uint32_t widthWin;
		const uint32_t heightWin;

		/* Funtions */
		void initWindow(void);
		void initVulkan(void);

		void createInstance(void);
		void mainLoop(void);
		void cleanWin(void);
};