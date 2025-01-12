#pragma once
#include <AScene.hpp>
#include <string>

class AObject
{
	protected:
		int posScene_x, posScene_y, posScene_z;
	public:
		/* Constructors */
		virtual ~AObject() = default;

		/* Functions */
		virtual const std::string getName(void) const = 0;
		// virtual void initialize() const = 0;
		// virtual void update() const = 0;
		// virtual void render() const = 0;
		// virtual void cleanUp() const = 0;
};