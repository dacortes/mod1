#pragma once
#include <MLX42/MLX42.h>
#include <AObject.hpp>
#include <memory>
#include <string>
#include <map>

class AObject;

class AScene
{
	protected:
		/* Variables */
		mlx_t		*ptr_mlx;
		mlx_image_t	*image;
		int x, y, z;
		std::map<std::string, std::unique_ptr<AObject>> objects;

		/* Constructor */
		AScene(uint32_t x = 0, uint32_t y = 0): x(x), y(y) {}
		AScene(uint32_t x = 0, uint32_t y = 0, uint32_t z = 0):  x(x), y(y), z(z) {}

		/* Functions */
		void addObject(std::unique_ptr<AObject> object);
	public:
		/* Constructors */
		virtual ~AScene() = default;

		// /* Functions */
		virtual void initialize(mlx_t *ptr_mlx) = 0;
		// virtual void update() = 0;
		// virtual void render() = 0;
		// virtual void cleanUp() = 0;
};