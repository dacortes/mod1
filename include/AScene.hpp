#pragma once

class AScene
{
	protected:
		/* Variables */
		int x, y, z;
		std::map<std::string, std::unique_ptr<AObject>> objects;

		/* Constructor */
		AScene(int x = 0, int y = 0): x(x), y(y) {}
		AScene(int x = 0, int y = 0, int z = 0): x(x), y(y), z(z) {}

		/* Functions */
		void addObject(std::unique_ptr<AObject> object);
		const std::string getName(void) const;
	public:
		/* Constructors */
		virtual ~AScene() = default;

		/* Functions */
		virtual void initialize() = 0;
		virtual void update() = 0;
		virtual void render() = 0;
		virtual void cleanUp() = 0;
};