#ifndef CAIROARROWS_HPP
#define CAIROARROWS_HPP

#include <gtkmm.h>
#include <iostream>
#include <math.h>

namespace Arrow{
	enum Type
	{
		NONE, OPEN, NORMAL, FILLED, DIAMOND, DIAMONDFILLED, CROSS
	};	
}

namespace Line{
	enum Type
	{
		NONE, DASHED, FULL
	};	
}

class Arrows
{
public:
	static void draw_arrow(Cairo::RefPtr< Cairo::Context > context_ref, int x1, int y1, int x2, int y2, Line::Type lineType, Arrow::Type startType, Arrow::Type endType, bool selected);
private:
	static void draw_arrowHead_open(Cairo::RefPtr< Cairo::Context > cr, int x1, int y1, int x2, int y2, bool selected);
	static void draw_arrowHead_filled(Cairo::RefPtr< Cairo::Context > cr, int x1, int y1, int x2, int y2, bool selected);
	static void draw_arrowHead(Cairo::RefPtr< Cairo::Context > cr, int x1, int y1, int x2, int y2, bool selected);
	static void draw_arrowHead_diamond(Cairo::RefPtr< Cairo::Context > cr, int x1, int y1, int x2, int y2, bool selected);
	static void draw_arrowHead_diamond_filled(Cairo::RefPtr< Cairo::Context > cr, int x1, int y1, int x2, int y2, bool selected);
	static void draw_arrowHead_cross(Cairo::RefPtr< Cairo::Context > cr, int x1, int y1, int x2, int y2, bool selected);
};

#endif /* CAIROARROWS_HPP */