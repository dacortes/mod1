#include <Scene2D.hpp>
#include <iostream>
#include <utils.tpp>

/* Constructors */
Scene2D::~Scene2D(void)
{}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void Scene2D::initialize(mlx_t *ctx_mlx)
{
	this->ctx_mlx = ctx_mlx;
	if (!ctx_mlx)
	{
		throw  Scene2D::SceneException(error_message("pointer: ", "The ctx pointer is null"));
	}

	if (!this->width or !this->height)
	{
		throw Scene2D::SceneException(error_message("Scene: ", "height or width cannot be zero"));
	}
	this->image = mlx_new_image(this->ctx_mlx, this->width, this->height);
	if (!image)
	{
		mlx_close_window(ctx_mlx);
		throw Scene2D::SceneException(std::string(mlx_strerror(mlx_errno)));
	}

	putScene(ctx_mlx);
	if (mlx_image_to_window(this->ctx_mlx, this->image, this->x, this->y))
	{
		mlx_close_window(this->ctx_mlx);
		puts(mlx_strerror(mlx_errno));
	}
}

void Scene2D::putScene(mlx_t *ctx_mlx)
{
	WinCen_y = ctx_mlx->height / 2;
	WinCen_x = ctx_mlx->width / 2;

	this->x = WinCen_x - (this->image->width / 2);
	this->y = WinCen_y - (this->image->height / 2);

	std::cout << "x: " << this->x << " width: " << image->width << std::endl;
	std::cout << "y: " << this->y << std::endl;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
			mlx_put_pixel(image, i, y, this->color);
	}
}
