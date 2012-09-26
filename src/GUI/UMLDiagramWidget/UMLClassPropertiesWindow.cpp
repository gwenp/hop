#include "UMLClassPropertiesWindow.hpp"

UMLClassPropertiesWindow::UMLClassPropertiesWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
	: Gtk::Window(cobject)
{
	builder->get_widget("classNameEntry",_classNameEntry);
 	builder->get_widget("applyButton",_applyButton);
	builder->get_widget("cancelButton",_cancelButton);
	builder->get_widget("properties_vbox",_properties_vbox);
	builder->get_widget("methods_vbox",_methods_vbox);
	builder->get_widget("addPropertyButton",_addPropertyButton);
	builder->get_widget("addMethodButton",_addMethodButton);

	_addPropertyButton->signal_button_press_event().connect(sigc::mem_fun(*this, &UMLClassPropertiesWindow::on_addPropertyButtonButton_clicked), false);
	_addMethodButton->signal_button_press_event().connect(sigc::mem_fun(*this, &UMLClassPropertiesWindow::on_addMethodButtonButton_clicked), false);
	
 	_applyButton->signal_button_press_event().connect(sigc::mem_fun(*this, &UMLClassPropertiesWindow::on_applyButton_clicked), false);
	_cancelButton->signal_button_press_event().connect(sigc::mem_fun(*this, &UMLClassPropertiesWindow::on_cancelButton_clicked), false);

}

UMLClassPropertiesWindow::~UMLClassPropertiesWindow()
{

}

void UMLClassPropertiesWindow::setMainWidget(Gtk::DrawingArea* widget)
{
	_mainWidget = widget;
}

void UMLClassPropertiesWindow::setUMLClass(UMLClass* theClass)
{
	_theClass = theClass;
	_classNameEntry->set_text(_theClass->getName());

	for (std::vector<UMLMethod*>::iterator it = theClass->getMethods()->begin(); it != theClass->getMethods()->end(); ++it)
	{
		MethodSignatureEditor* newMethodEditor = new MethodSignatureEditor(*it);
		_methods_vbox->pack_start(*newMethodEditor, false,true);
		newMethodEditor->show();
	}

	for (std::vector<UMLProperty*>::iterator it = theClass->getProperties()->begin(); it != theClass->getProperties()->end(); ++it)
	{
		PropertySignatureEditor* newPropertyLabel = new PropertySignatureEditor(*it);
		_properties_vbox->pack_start(*newPropertyLabel, false,true);
		newPropertyLabel->show();
	}
}


bool UMLClassPropertiesWindow::on_addPropertyButtonButton_clicked(GdkEventButton* event)
{
	UMLProperty* p = new UMLProperty(Visibility::PRIVATE, "int", "_prop");
	_pendingProperties.push_back(p);
	
	PropertySignatureEditor* newPropertyEditor = new PropertySignatureEditor(p);
	_signatureEditors.push_back(newPropertyEditor);
	_properties_vbox->pack_start(*newPropertyEditor, false,true);
	newPropertyEditor->show();
}

bool UMLClassPropertiesWindow::on_addMethodButtonButton_clicked(GdkEventButton* event)
{
	UMLMethod* m = new UMLMethod(Visibility::PUBLIC, "int", "method");
	_pendingMethods.push_back(m);

	MethodSignatureEditor* newMethodEditor = new MethodSignatureEditor(m);
	_signatureEditors.push_back(newMethodEditor);
	_methods_vbox->pack_start(*newMethodEditor, false,true);
	newMethodEditor->show();
}

bool UMLClassPropertiesWindow::on_applyButton_clicked(GdkEventButton* event)
{
	_theClass->setName(_classNameEntry->get_text());
	
	for (std::vector<SignatureEditor*>::iterator it = _signatureEditors.begin(); it != _signatureEditors.end(); ++it)
	{
		(*it)->applyChanges();
	}

	for (std::vector<UMLMethod*>::iterator it = _pendingMethods.begin(); it != _pendingMethods.end(); ++it)
	{
		_theClass->addMethod(*it);
	}

	for (std::vector<UMLProperty*>::iterator it = _pendingProperties.begin(); it != _pendingProperties.end(); ++it)
	{
		_theClass->addProperty(*it);
	}

	_mainWidget->queue_draw();
	hideWindow();
}

bool UMLClassPropertiesWindow::on_cancelButton_clicked(GdkEventButton* event)
{
	hideWindow();
}

void UMLClassPropertiesWindow::hideWindow()
{
	//Reset dynamic containers for later use
	_methods_vbox->children().erase(_methods_vbox->children().begin(),_methods_vbox->children().end());
	_properties_vbox->children().erase(_properties_vbox->children().begin(),_properties_vbox->children().end());

	_pendingMethods.clear();
	_pendingProperties.clear();

	hide();
}