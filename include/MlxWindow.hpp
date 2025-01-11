#pragma once
#include <MLX42/MLX42.h>
#include <AObject.hpp>
#include <AScene.hpp>
#include <utils.tpp>
#include <memory>
#include <string>
#include <map>

class MlxWindow
{
	protected:
		/* variables */
		mlx_t		*mlx;
		int32_t		width;
		int32_t		height;
		const char *title;
	private:
		/* variables */
		std::string currentSceneKey;
		/* Scenes */
		std::map<std::string, std::unique_ptr<AScene>> scenes;
		/* Functions */
		void createWindow(void);
		void destroy(void);
	public:
		/* Constructors */
		MlxWindow(const char *title, int32_t width, int32_t height);
		~MlxWindow(void);

		/* Functions */
		void addScene(const std::string &name, std::unique_ptr<AScene> scene);
		void switchToScene(const std::string& name);
		void loop(void);

		class MlxWindowException: public std::exception
		{
			private:
				std::string _msgError;
			public:
				MlxWindowException(std::string msgError): _msgError(msgError){}
				virtual const char *what() const throw()
				{
					return (_msgError.c_str());
				}
				~MlxWindowException(void) throw(){}
		};
};
