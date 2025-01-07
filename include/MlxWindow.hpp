#pragma once
#include <MLX42/MLX42.h>
#include <AObject.hpp>
#include <AScene.hpp>
#include <memory>
#include <string>
#include <map>

class MlxWindow
{
	private:
		/* Init window */
		mlx_t		*mlx;
		int32_t		width;
		int32_t		height;
		const char *title;

		/* Scenes */
		std::map<std::string, std::unique_ptr<AScene>> scenes;
		/* Functions */
		void createWindow(void);
		void loop(void);
		void destroy(void);
	public:
		/* Constructors */
		MlxWindow(const char *title, int32_t width, int32_t height);
		~MlxWindow(void);

		/* Functions */
		void addScene(std::string name, AObject object);
};
