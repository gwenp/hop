#include "UMLLinkPropertiesWindow.hpp"

UMLLinkPropertiesWindow::UMLLinkPropertiesWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
	: Gtk::Window(cobject)
{
	builder->get_widget("applyButton",_applyButton);
	builder->get_widget("cancelButton",_cancelButton);

	builder->get_widget("hboxFamilyBegin",_hboxFamilyBegin);
	builder->get_widget("hboxMultiplicityBegin",_hboxMultiplicityBegin);
	builder->get_widget("hboxFamilyEnd",_hboxFamilyEnd);
	builder->get_widget("hboxMultiplicityEnd",_hboxMultiplicityEnd);

	_comboFamilyBegin = new Gtk::ComboBoxText();
	_comboMultiplicityBegin = new Gtk::ComboBoxText();
	_comboFamilyEnd = new Gtk::ComboBoxText();
	_comboMultiplicityEnd = new Gtk::ComboBoxText();

	_comboFamilyBegin->append_text("Association");
	_comboFamilyBegin->append_text("Composition");
	_comboFamilyBegin->append_text("Aggregation");
	_comboFamilyBegin->append_text("Dependency");

	_comboFamilyEnd->append_text("Association");
	_comboFamilyEnd->append_text("Composition");
	_comboFamilyEnd->append_text("Aggregation");
	_comboFamilyEnd->append_text("Dependency");

	_comboMultiplicityBegin->append_text("1 .. 1");
	_comboMultiplicityBegin->append_text("1 .. n");
	_comboMultiplicityBegin->append_text("0 .. n");
	_comboMultiplicityBegin->append_text("1");

	_comboMultiplicityEnd->append_text("1 .. 1");
	_comboMultiplicityEnd->append_text("1 .. n");
	_comboMultiplicityEnd->append_text("0 .. n");
	_comboMultiplicityEnd->append_text("1");

	_hboxFamilyBegin->pack_start(*_comboFamilyBegin, true, true);
	_hboxMultiplicityBegin->pack_start(*_comboMultiplicityBegin, true, true);
	_hboxFamilyEnd->pack_start(*_comboFamilyEnd, true, true);
	_hboxMultiplicityEnd->pack_start(*_comboMultiplicityEnd, true, true);

	_applyButton->signal_button_press_event().connect(sigc::mem_fun(*this, &UMLLinkPropertiesWindow::on_applyButton_clicked), false);
	_cancelButton->signal_button_press_event().connect(sigc::mem_fun(*this, &UMLLinkPropertiesWindow::on_cancelButton_clicked), false);

	show_all_children();
}

UMLLinkPropertiesWindow::~UMLLinkPropertiesWindow()
{

}

void UMLLinkPropertiesWindow::setMainWidget(Gtk::DrawingArea* widget)
{
	_mainWidget = widget;
}

void UMLLinkPropertiesWindow::setUMLLink(UMLLink* theLink)
{
	_theLink = theLink;
}

bool UMLLinkPropertiesWindow::on_applyButton_clicked(GdkEventButton* event)
{
	hideWindow();
}

bool UMLLinkPropertiesWindow::on_cancelButton_clicked(GdkEventButton* event)
{
	hideWindow();
}

void UMLLinkPropertiesWindow::hideWindow()
{
	hide();
}

