#include "MethodSignatureEditor.hpp"

MethodSignatureEditor::MethodSignatureEditor(UMLMethod* method)
	: _method(method)
{
	_entryName = new Gtk::Entry();
	_entryName->set_text(method->getName());
	pack_start(*_entryName, false,true);

	show_all_children();
}

MethodSignatureEditor::~MethodSignatureEditor()
{

}

