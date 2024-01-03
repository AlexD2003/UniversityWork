#pragma once
#include "Shape.h"

class Circle: public Shape
{
public:
	Circle(float x, float y, float r);

	float area() override;
	std::string toString() override;
private:
	float m_radius;
};

