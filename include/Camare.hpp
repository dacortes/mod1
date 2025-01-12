#pragma once
#include <MLX42/MLX42.h>

class Camare
{
	private:
		int center_x, center_y;
	public:
		Camare(int center_x, int center_y) center_x(center_x), center_y(center_y) {}
		~Camare(void);

		updateImage(mlx_image *image);
};
