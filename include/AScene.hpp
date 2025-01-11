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
		mlx_t		*ctx_mlx;
		mlx_image_t	*image;
		int x, y, z;
		std::map<std::string, std::unique_ptr<AObject>> objects;

		/* Constructor */
		AScene(int x = 0, int y = 0, int z = 0):  x(x), y(y), z(z) {}

		/* Functions */
		void addObject(std::unique_ptr<AObject> object);
	public:
		/* Constructors */
		virtual ~AScene() = default;

		// /* Functions */
		virtual void initialize(mlx_t *ctx_mlx) = 0;
		virtual void putScene(mlx_t *ctx_mlx) = 0;
		// virtual void update() = 0;
		// virtual void render() = 0;
		// virtual void cleanUp() = 0;

		class SceneException: public std::exception
		{
			private:
				std::string _msgError;
			public:
				SceneException(std::string msgError): _msgError(msgError){}
				virtual const char *what() const throw()
				{
					return (_msgError.c_str());
				}
				~SceneException(void) throw(){}
		};
};