#include <VulkanWin.hpp>
#include <utils.tpp>

/*	Public	*/

VulkanWin::VulkanWin(const char *titleWin, const char *AppName, const uint32_t widthWin, const uint32_t heightWin)
    : titleWin(titleWin), AppName(AppName), widthWin(widthWin), heightWin(heightWin)
{}

VulkanWin::~VulkanWin(void)
{
	vkDestroyInstance(this->instance, nullptr);
	glfwDestroyWindow(this->window);
	glfwTerminate();
}

void VulkanWin::run(void)
{
	this->initWindow();
	this->createInstance();
	this->mainLoop();
}

/*	Private	*/
void VulkanWin::initWindow(void)
{
	if (not glfwInit()){
		std::exit(::error_message(INIT, ERROR_INIT_WINDOWS, "funtion: initWindow()"));
	}
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	this->window = glfwCreateWindow(this->widthWin, this->heightWin, "Vulkan Window", nullptr, nullptr);
}

void VulkanWin::createInstance(void)
{
	VkApplicationInfo	appInfo{};

	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = this->AppName;
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo createInfo{};

	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;

	createInfo.enabledLayerCount = 0;

	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
		throw std::runtime_error("failed to create instance!");
}

void VulkanWin::mainLoop(void)
{
	while (not glfwWindowShouldClose(this->window))
		glfwPollEvents();
}
