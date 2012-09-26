#include "UMLLinkPropertiesWindow.hpp"

UMLLinkPropertiesWindow::UMLLinkPropertiesWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
	: Gtk::Window(cobject)
{
	builder->get_widget("linkApplyButton",_applyButton);
	builder->get_widget("linkCancelButton",_cancelButton);

	builder->get_widget("hboxFamilyBegin",_hboxFamilyBegin);
	builder->get_widget("hboxMultiplicityBegin",_hboxMultiplicityBegin);
	builder->get_widget("hboxFamilyEnd",_hboxFamilyEnd);
	builder->get_widget("hboxMultiplicityEnd",_hboxMultiplicityEnd);

	_comboFamilyBegin = new Gtk::ComboBoxText();
	_comboMultiplicityBegin = new Gtk::ComboBoxEntryText();
	_comboFamilyEnd = new Gtk::ComboBoxText();
	_comboMultiplicityEnd = new Gtk::ComboBoxEntryText();

	_comboFamilyBegin->append_text("Association");
	_comboFamilyBegin->append_text("Composition");
	_comboFamilyBegin->append_text("Aggregation");
	_comboFamilyBegin->append_text("Navigation");
	_comboFamilyBegin->append_text("Forbidden");
	_comboFamilyBegin->append_text("Dependency");

	_comboFamilyEnd->append_text("Association");
	_comboFamilyEnd->append_text("Composition");
	_comboFamilyEnd->append_text("Aggregation");
	_comboFamilyEnd->append_text("Navigation");
	_comboFamilyEnd->append_text("Forbidden");
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

	show_all_children();

	std::cout << "UMLLinkPropertiesWindow::ctor" << std::endl;
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
	_applyButton->signal_button_press_event().connect(sigc::mem_fun(*this, &UMLLinkPropertiesWindow::on_applyButton_clicked), false);
	_cancelButton->signal_button_press_event().connect(sigc::mem_fun(*this, &UMLLinkPropertiesWindow::on_cancelButton_clicked), false);

	_comboFamilyBegin->set_active_text(LinkTypes::convertToString(theLink->getLinkTypeBegin()));
	_comboFamilyEnd->set_active_text(LinkTypes::convertToString(theLink->getLinkTypeEnd()));
}

bool UMLLinkPropertiesWindow::on_applyButton_clicked(GdkEventButton* event)
{
	std::cout << "on_applyButton_clicked" << std::endl;

	_theLink->setLinkTypeBegin(LinkTypes::convertFromString(_comboFamilyBegin->get_active_text()));
	_theLink->setLinkTypeEnd(LinkTypes::convertFromString(_comboFamilyEnd->get_active_text()));

	_theLink->setMultiplicityBegin(_comboMultiplicityBegin->get_active_text());
	_theLink->setMultiplicityEnd(_comboMultiplicityEnd->get_active_text());

	_mainWidget->queue_draw();
	hideWindow();
}

bool UMLLinkPropertiesWindow::on_cancelButton_clicked(GdkEventButton* event)
{
	std::cout << "on_cancelButton_clicked" << std::endl;

	hideWindow();
}

void UMLLinkPropertiesWindow::hideWindow()
{
	hide();
}

