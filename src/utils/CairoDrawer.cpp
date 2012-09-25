#include "CairoDrawer.hpp"

void CairoDrawer::drawLine(Glib::RefPtr<Gdk::Window> window, int x1, int y1, int x2, int y2)
{
	Cairo::RefPtr<Cairo::Context> cr = window->create_cairo_context();

	cr->set_source_rgb(0.0, 0.0, 0.0);

	cr->move_to(x1, y1);
    cr->line_to(x2, y2);

    cr->stroke();
}

void CairoDrawer::drawRectangle(Glib::RefPtr<Gdk::Window> window, int x, int y, int w, int h)
{

	Cairo::RefPtr<Cairo::Context> cr = window->create_cairo_context();

	Cairo::RefPtr< Cairo::LinearGradient > background_gradient_ptr = Cairo::LinearGradient::create (x, y, w, h);

	// Draw a rectangle and fill with gradient
	cr->rectangle(x,y,w,h);

	cr->set_source_rgb(1.0, 0.87, 0.67);
	cr->fill_preserve();
	cr->set_source_rgb(0.0, 0.0, 0.0);
	cr->stroke();
}

Rect CairoDrawer::drawText(Glib::RefPtr<Gdk::Window> window, int x, int y, std::string text, std::string fontDescription)
{
	Rect r;
	r.x = x;
	r.y = y;

	Cairo::RefPtr<Cairo::Context> cr = window->create_cairo_context();

	Glib::RefPtr<Pango::Layout> pangoLayout = Pango::Layout::create (cr);

	cr->move_to(x,y);

 	Pango::FontDescription font_desc(fontDescription);
  	pangoLayout->set_font_description(font_desc);

	pangoLayout->set_text(text);
	pangoLayout->get_pixel_size(r.w, r.h);

	pangoLayout->update_from_cairo_context(cr);  //gets cairo cursor position
	pangoLayout->add_to_cairo_context(cr);

	cr->fill();

	return r;
}

