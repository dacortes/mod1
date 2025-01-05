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
		VulkanWin(const char *titleWin, const char *AppName, const uint32_t widthWin, const uint32_t heightWin);
		~VulkanWin(void);
	
		void run(void);
	private:
		/* Variables */
		GLFWwindow *window;
		VkInstance	instance;
		const char *titleWin;
		const char	*AppName;
		const uint32_t widthWin;
		const uint32_t heightWin;

		/* Funtions */
		void initWindow(void);

		void createInstance(void);
		void mainLoop(void);
		void cleanWin(void);
};