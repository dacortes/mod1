#pragma once
#include <AScene.hpp>
#include <string>
#include <memory>
#include <map>

// class AScene;

class Scene2D: public AScene
{
	public:
		Scene2D(uint32_t x, uint32_t y, uint32_t z): AScene(x, y, z){}
		~Scene2D(void);

		void initialize(mlx_t *ptr_mlx);
};
