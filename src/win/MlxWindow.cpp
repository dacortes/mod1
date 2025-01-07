#include <MlxWindow.hpp>
#include <utils.tpp>

/* Private */

void MlxWindow::createWindow(void)
{
	this->mlx = mlx_init(this->width, this->height, this->title, true);
	if (!mlx)
	{
		std::exit(error_message(mlx_errno, mlx_strerror(mlx_errno), ""));
	}
}

void MlxWindow::loop(void)
{
	mlx_loop(this->mlx);
}

void MlxWindow::destroy(void)
{
	mlx_terminate(this->mlx);
}


/* Public */
MlxWindow::MlxWindow(const char *title, int32_t width, int32_t height)
{
	this->title = title;
	this->width = width;
	this->height = height;
	createWindow();
}

MlxWindow::~MlxWindow(void)
{
	this->destroy();
}

void MlxWindow::addScene(std::string name, AObject object)
{
	
}