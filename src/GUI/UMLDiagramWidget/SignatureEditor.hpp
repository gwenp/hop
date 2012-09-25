#ifndef SIGNATUREEDITOR_HPP
#define SIGNATUREEDITOR_HPP

#include <vector>
#include <string>

#include <gtkmm.h>

#include "UML/UMLProperty.hpp"

class SignatureEditor : public Gtk::HBox
{
public:
	SignatureEditor();
	~SignatureEditor();

	virtual void applyChanges() =0;
private:
};

#endif /* SIGNATUREEDITOR_HPP */