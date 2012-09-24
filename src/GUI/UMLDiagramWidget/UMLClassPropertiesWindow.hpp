#ifndef UMLCLASSPROPERTIESWINDOW_HPP
#define UMLCLASSPROPERTIESWINDOW_HPP

#include <vector>
#include <string>

#include "UML/UMLClass.hpp"
#include "PropertySignatureEditor.hpp"
#include "MethodSignatureEditor.hpp"

#include <gtkmm.h>

class UMLClassPropertiesWindow : public Gtk::Window
{
public:
	UMLClassPropertiesWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
	~UMLClassPropertiesWindow();

	void setMainWidget(Gtk::DrawingArea* widget);
	void setUMLClass(UMLClass* theClass);

private:
	bool on_applyButton_clicked(GdkEventButton* event);
	bool on_cancelButton_clicked(GdkEventButton* event);

	void hideWindow();

	UMLClass* _theClass;

	Gtk::Entry* _classNameEntry;
	Gtk::Button* _applyButton;
	Gtk::Button* _cancelButton;
	Gtk::Button* _addPropertyButton;
	Gtk::Button* _addMethodButton;
	Gtk::VBox* _methods_vbox;
	Gtk::VBox* _properties_vbox;

	Gtk::DrawingArea* _mainWidget;
};

#endif /* UMLCLASSPROPERTIESWINDOW_HPP */