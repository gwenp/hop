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
	_comboFamilyBegin->append_text("Dependency");

	_comboFamilyEnd->append_text("Association");
	_comboFamilyEnd->append_text("Composition");
	_comboFamilyEnd->append_text("Aggregation");
	_comboFamilyEnd->append_text("Navigation");
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


	switch(theLink->getLinkTypeBegin())
	{
		case LinkTypes::ASSOCIATION:
			_comboFamilyBegin->set_active_text("Association");
			break;
		case LinkTypes::COMPOSITION:
			_comboFamilyBegin->set_active_text("Composition");
			break;
		case LinkTypes::AGGREGATION:
			_comboFamilyBegin->set_active_text("Aggregation");
			break;
		case LinkTypes::DEPENDENCY:
			_comboFamilyBegin->set_active_text("Dependency");
			break;
		case LinkTypes::NAVIGATION:
			_comboFamilyBegin->set_active_text("Navigation");
			break;
	}

	switch(theLink->getLinkTypeEnd())
	{
		case LinkTypes::ASSOCIATION:
			_comboFamilyEnd->set_active_text("Association");
			break;
		case LinkTypes::COMPOSITION:
			_comboFamilyEnd->set_active_text("Composition");
			break;
		case LinkTypes::AGGREGATION:
			_comboFamilyEnd->set_active_text("Aggregation");
			break;
		case LinkTypes::DEPENDENCY:
			_comboFamilyEnd->set_active_text("Dependency");
			break;
		case LinkTypes::NAVIGATION:
			_comboFamilyEnd->set_active_text("Navigation");
			break;
	}
}

bool UMLLinkPropertiesWindow::on_applyButton_clicked(GdkEventButton* event)
{
	std::cout << "on_applyButton_clicked" << std::endl;
		if(_comboFamilyBegin->get_active_text() == "Association")
			_theLink->setLinkTypeBegin(LinkTypes::ASSOCIATION);
		else if(_comboFamilyBegin->get_active_text() == "Composition")
			_theLink->setLinkTypeBegin(LinkTypes::COMPOSITION);
		else if(_comboFamilyBegin->get_active_text() == "Aggregation")
			_theLink->setLinkTypeBegin(LinkTypes::AGGREGATION);
		else if(_comboFamilyBegin->get_active_text() == "Dependency")
			_theLink->setLinkTypeBegin(LinkTypes::DEPENDENCY);
		else if(_comboFamilyBegin->get_active_text() == "Navigation")
			_theLink->setLinkTypeBegin(LinkTypes::NAVIGATION);
		else 
			_theLink->setLinkTypeBegin(LinkTypes::ASSOCIATION);

		if(_comboFamilyEnd->get_active_text() == "Association")
			_theLink->setLinkTypeEnd(LinkTypes::ASSOCIATION);
		else if(_comboFamilyEnd->get_active_text() == "Composition")
			_theLink->setLinkTypeEnd(LinkTypes::COMPOSITION);
		else if(_comboFamilyEnd->get_active_text() == "Aggregation")
			_theLink->setLinkTypeEnd(LinkTypes::AGGREGATION);
		else if(_comboFamilyEnd->get_active_text() == "Dependency")
			_theLink->setLinkTypeEnd(LinkTypes::DEPENDENCY);
		else if(_comboFamilyEnd->get_active_text() == "Navigation")
			_theLink->setLinkTypeEnd(LinkTypes::NAVIGATION);
		else 
			_theLink->setLinkTypeEnd(LinkTypes::ASSOCIATION);

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

