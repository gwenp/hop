#ifndef CAIRODRAWER_HPP
#define CAIRODRAWER_HPP

#include <string>
#include <gtkmm.h>

class Rect
{
public:
	int x;
	int y;
	int w;
	int h;
};

class CairoDrawer
{
public:
	static void drawLine(Glib::RefPtr<Gdk::Window> window, int x1, int y1, int x2, int y2);
	static void drawRectangle(Glib::RefPtr<Gdk::Window> window, int x, int y, int w, int h);
	static Rect drawText(Glib::RefPtr<Gdk::Window> window, int x, int y, std::string text, std::string fontDescription);
protected:
};

#endif /* CAIRODRAWER_HPP */