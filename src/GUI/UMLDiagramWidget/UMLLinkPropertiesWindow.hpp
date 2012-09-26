#ifndef UMLLINKPROPERTIESWINDOW_HPP
#define UMLLINKPROPERTIESWINDOW_HPP

#include <vector>
#include <string>

#include "UML/UMLLink.hpp"
#include "PropertySignatureEditor.hpp"
#include "MethodSignatureEditor.hpp"

#include <gtkmm.h>

class UMLLinkPropertiesWindow : public Gtk::Window
{
public:
	UMLLinkPropertiesWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
	~UMLLinkPropertiesWindow();

	void setMainWidget(Gtk::DrawingArea* widget);
	void setUMLLink(UMLLink* theLink);

private:
	bool on_applyButton_clicked(GdkEventButton* event);
	bool on_cancelButton_clicked(GdkEventButton* event);

	void hideWindow();

	UMLLink* _theLink;

	Gtk::Button* _applyButton;
	Gtk::Button* _cancelButton;

	Gtk::HBox* _hboxFamilyBegin;
	Gtk::HBox* _hboxMultiplicityBegin;
	Gtk::HBox* _hboxFamilyEnd;
	Gtk::HBox* _hboxMultiplicityEnd;

	Gtk::ComboBoxText* _comboFamilyBegin;
	Gtk::ComboBoxEntryText* _comboMultiplicityBegin;
	
	Gtk::ComboBoxText* _comboFamilyEnd;
	Gtk::ComboBoxEntryText* _comboMultiplicityEnd;

	Gtk::DrawingArea* _mainWidget;
};

#endif /* UMLLINKPROPERTIESWINDOW_HPP */