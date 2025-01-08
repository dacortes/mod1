#include <Scene2D.hpp>
#include <iostream>
/* Constructors */
Scene2D::~Scene2D(void)
{}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void Scene2D::initialize(mlx_t *ptr_mlx)
{
	this->ptr_mlx = ptr_mlx;
	if (!ptr_mlx)
		std::cout << "Estoy condenado loco :c" << std::endl;
	this->image = mlx_new_image(this->ptr_mlx, 99, 99);
	if (!image)
	{
		mlx_close_window(ptr_mlx);
		puts(mlx_strerror(mlx_errno));
		std::cout << "Estoy pocho loco" << std::endl;
		/* agregrar error para haccer un try */
	}

	for (uint32_t x = 0; x < this->image->width; ++x){
		for (uint32_t y = 0; y < this->image->height; ++y){
			uint32_t color = ft_pixel(
			rand() % 0xFF, // R
			rand() % 0xFF, // G
			rand() % 0xFF, // B
			rand() % 0xFF  // A
		);
			mlx_put_pixel(this->image, x , y, color);
		}
	}

	if (mlx_image_to_window(this->ptr_mlx, this->image, 0, 0))
	{
		mlx_close_window(this->ptr_mlx);
		puts(mlx_strerror(mlx_errno));
	}
}

