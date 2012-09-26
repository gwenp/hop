#include "Arrows.hpp"

void Arrows::draw_arrow(Cairo::RefPtr< Cairo::Context > cr,int x1, int y1, int x2, int y2, Line::Type lineType, Arrow::Type startType, Arrow::Type endType, bool selected)
{
	switch(lineType)
	{
		case Line::FULL:
			cr->move_to(x1,y1);
			cr->line_to(x2,y2);

			if(selected)
				cr->set_source_rgb(1.0, 0.0, 0.0);
			else
				cr->set_source_rgb(0.0, 0.0, 0.0);

			cr->stroke();

			break;
		case Line::DASHED:
			break;
		case Line::NONE:
			break;
	}

	switch(startType)
	{
		case Arrow::NONE:
			break;

		case Arrow::OPEN:
			draw_arrowHead_open(cr, x1, y1, x2, y2, selected);
			break;

		case Arrow::NORMAL:
			draw_arrowHead(cr, x1, y1, x2, y2, selected);
			break;

		case Arrow::FILLED:
			draw_arrowHead_filled(cr, x1, y1, x2, y2, selected);
			break;

		case Arrow::DIAMOND:
			draw_arrowHead_diamond(cr, x1, y1, x2, y2, selected);
			break;

		case Arrow::DIAMONDFILLED:
			draw_arrowHead_diamond_filled(cr, x1, y1, x2, y2, selected);
			break;
	}

	switch(endType)
	{
		case Arrow::NONE:
			break;

		case Arrow::OPEN:
			draw_arrowHead_open(cr, x2, y2, x1, y1, selected);
			break;

		case Arrow::NORMAL:
			draw_arrowHead(cr, x2, y2, x1, y1, selected);
			break;

		case Arrow::FILLED:
			draw_arrowHead_filled(cr, x2, y2, x1, y1, selected);
			break;

		case Arrow::DIAMOND:
			draw_arrowHead_diamond(cr, x2, y2, x1, y1, selected);
			break;

		case Arrow::DIAMONDFILLED:
			draw_arrowHead_diamond_filled(cr, x2, y2, x1, y1, selected);
			break;
	}
}

void Arrows::draw_arrowHead_open(Cairo::RefPtr< Cairo::Context > cr, int x1, int y1, int x2, int y2, bool selected)
{
	double angle = atan2 (y2 - y1, x2 - x1) + M_PI;
	double arrow_degrees = 0.5;
	int arrow_length = 25;

	int xA, yA, xB, yB;

	xA = x2 + arrow_length * cos(angle - arrow_degrees);
	yA = y2 + arrow_length * sin(angle - arrow_degrees);
	xB = x2 + arrow_length * cos(angle + arrow_degrees);
	yB = y2 + arrow_length * sin(angle + arrow_degrees);

	cr->move_to(x2,y2);
	cr->line_to(xA,yA);
	cr->move_to(x2,y2);
	cr->line_to(xB,yB);

	if(selected)
		cr->set_source_rgb(1.0, 0.0, 0.0);
	else
		cr->set_source_rgb(0.0, 0.0, 0.0);

	cr->stroke();
}

void Arrows::draw_arrowHead(Cairo::RefPtr< Cairo::Context > cr, int x1, int y1, int x2, int y2, bool selected)
{
	double angle = atan2 (y2 - y1, x2 - x1) + M_PI;
	double arrow_degrees = 0.5;
	int arrow_length = 25;

	int xA, yA, xB, yB;

	xA = x2 + arrow_length * cos(angle - arrow_degrees);
	yA = y2 + arrow_length * sin(angle - arrow_degrees);
	xB = x2 + arrow_length * cos(angle + arrow_degrees);
	yB = y2 + arrow_length * sin(angle + arrow_degrees);

	cr->move_to(x2,y2);
	cr->line_to(xA,yA);
	cr->line_to(xB,yB);
	cr->line_to(x2,y2);

	cr->set_source_rgb(1.0, 1.0, 1.0);
	cr->fill_preserve();

	if(selected)
		cr->set_source_rgb(1.0, 0.0, 0.0);
	else
		cr->set_source_rgb(0.0, 0.0, 0.0);
	cr->stroke();
}

void Arrows::draw_arrowHead_filled(Cairo::RefPtr< Cairo::Context > cr, int x1, int y1, int x2, int y2, bool selected)
{
	double angle = atan2 (y2 - y1, x2 - x1) + M_PI;
	double arrow_degrees = 0.5;
	int arrow_length = 25;

	int xA, yA, xB, yB;

	xA = x2 + arrow_length * cos(angle - arrow_degrees);
	yA = y2 + arrow_length * sin(angle - arrow_degrees);
	xB = x2 + arrow_length * cos(angle + arrow_degrees);
	yB = y2 + arrow_length * sin(angle + arrow_degrees);

	cr->move_to(x2,y2);
	cr->line_to(xA,yA);
	cr->line_to(xB,yB);
	cr->line_to(x2,y2);

	if(selected)
		cr->set_source_rgb(1.0, 0.0, 0.0);
	else
		cr->set_source_rgb(0.0, 0.0, 0.0);
	cr->fill_preserve();
	cr->stroke();
}

void Arrows::draw_arrowHead_diamond(Cairo::RefPtr< Cairo::Context > cr, int x1, int y1, int x2, int y2, bool selected)
{
	double angle = atan2 (y2 - y1, x2 - x1) + M_PI;
	double arrow_degrees = 0.5;
	double arrow_length = 18;

	int xA, yA, xB, yB, xC, yC;

	xA = x2 + arrow_length * cos(angle - arrow_degrees);
	yA = y2 + arrow_length * sin(angle - arrow_degrees);
	xB = x2 + arrow_length * cos(angle + arrow_degrees);
	yB = y2 + arrow_length * sin(angle + arrow_degrees);
	xC = x2 + arrow_length * 2 * cos(angle);
	yC = y2 + arrow_length * 2 * sin(angle);

	cr->move_to(x2,y2);
	cr->line_to(xA,yA);
	cr->line_to(xC,yC);
	cr->line_to(xB,yB);
	cr->line_to(x2,y2);

	cr->set_source_rgb(1.0, 1.0, 1.0);
	cr->fill_preserve();

	if(selected)
		cr->set_source_rgb(1.0, 0.0, 0.0);
	else
		cr->set_source_rgb(0.0, 0.0, 0.0);
	cr->stroke();
}

void Arrows::draw_arrowHead_diamond_filled(Cairo::RefPtr< Cairo::Context > cr, int x1, int y1, int x2, int y2, bool selected)
{
	double angle = atan2 (y2 - y1, x2 - x1) + M_PI;
	double arrow_degrees = 0.5;
	double arrow_length = 18;

	int xA, yA, xB, yB, xC, yC;

	xA = x2 + arrow_length * cos(angle - arrow_degrees);
	yA = y2 + arrow_length * sin(angle - arrow_degrees);
	xB = x2 + arrow_length * cos(angle + arrow_degrees);
	yB = y2 + arrow_length * sin(angle + arrow_degrees);
	xC = x2 + arrow_length * 2 * cos(angle);
	yC = y2 + arrow_length * 2 * sin(angle);

	cr->move_to(x2,y2);
	cr->line_to(xA,yA);
	cr->line_to(xC,yC);
	cr->line_to(xB,yB);
	cr->line_to(x2,y2);

	if(selected)
		cr->set_source_rgb(1.0, 0.0, 0.0);
	else
		cr->set_source_rgb(0.0, 0.0, 0.0);
	cr->fill();
	cr->stroke();
}
