#include <MlxWindow.hpp>

/* Private */

void MlxWindow::createWindow(void)
{
	this->mlx = mlx_init(this->width, this->height, this->title, true);
	if (!mlx)
		throw MlxWindow::MlxWindowException(std::string(mlx_strerror(mlx_errno), ""));
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

void MlxWindow::addScene(const std::string &name, std::unique_ptr<AScene> scene)
{
	scenes[name] = std::move(scene);
}

void MlxWindow::switchToScene(const std::string& name) {
    if (scenes.find(name) != scenes.end())
	{
        currentSceneKey = name;
        scenes[currentSceneKey]->initialize(this->mlx);
    }
}