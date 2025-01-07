#pragma once
#include<AScene.hpp>

class AObject: public AScene
{
	protected:
		std::string getName(void) const;
	public:
		/* Constructors */
		virtual ~AObject() = default;

		/* Functions */
		virtual void initialize() const = 0;
		virtual void update() const = 0;
		virtual void render() const = 0;
		virtual void cleanUp() const = 0;
};