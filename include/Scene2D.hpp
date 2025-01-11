#pragma once
#include <AScene.hpp>
#include <string>
#include <memory>
#include <map>

// class AScene;

class Scene2D: public AScene
{
	private:
		uint32_t width, height, color;
		int	WinCen_x, WinCen_y, max_x, min_x, max_y, min_y;
	public:
		Scene2D(int pos_x, int pos_y, uint32_t width, uint32_t height, uint32_t color): AScene(pos_x, pos_y, 0)
		{
			this->height = height;
			this->width = width;
			this->color = color;
		}
		~Scene2D(void);

		void initialize(mlx_t *ctx_mlx);
		void putScene(mlx_t *ctx_mlx);
};
