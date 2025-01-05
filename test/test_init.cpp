#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>

class VulkanWin
{
	public:
		void run(void)
		{
			initWindow(void);
			initVulkan();
			mainLoop();
			clean();
		}
};

int	main(void)
{
	return (EXIT_SUCCESS);
}