#pragma once
#include<iostream>
#include<vector>
#include <SFML/Graphics.hpp>

#define SHAPE_POINT 0  ///< List of individual points
#define SHAPE_LINES 1         ///< List of individual lines
//enum PrimitiveType
//{
//	Points,        ///< List of individual points
//	Lines,         ///< List of individual lines
//	LineStrip,     ///< List of connected lines, a point uses the previous point to form a line
//	Triangles,     ///< List of individual triangles
//	TriangleStrip, ///< List of connected triangles, a point uses the two previous points to form a triangle
//	TriangleFan,   ///< List of connected triangles, a point uses the common center and the previous point to form a triangle
//	Quads,         ///< List of individual quads (deprecated, don't work with OpenGL ES)
//
//	// Deprecated names
//	LinesStrip = LineStrip,     ///< \deprecated Use LineStrip instead
//	TrianglesStrip = TriangleStrip, ///< \deprecated Use TriangleStrip instead
//	TrianglesFan = TriangleFan    ///< \deprecated Use TriangleFan instead
//};

using std::cout;
using std::endl;

extern sf::RenderWindow window;

struct point2D {
	double x;
	double y;
};