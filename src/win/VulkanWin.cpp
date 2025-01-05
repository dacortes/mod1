#include <VulkanWin.hpp>

/*	Public	*/
VulkanWin::VulkanWin(const char *AppName, const uint32_t widthWin, const uint32_t heightWin)
{
	this->AppName = AppName;
	this->widthWin = widthWin;
	this->heightWin = heightWin;
}

VulkanWin::~VulkanWin(void)
{

}

/*	Private	*/
void VulkanWin::initWindow(void)