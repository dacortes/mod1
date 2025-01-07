#pragma once
#include <Scene2D.hpp>

class Scene2D: public AScene
{
	private:
		int x, y;
	public:
		Scene2D(int x, int y): AScene(x, y);
		~Scene2D(void);
};
