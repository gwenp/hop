bin_PROGRAMS = hop

hop_LDADD = $(LIBJSONCPP_LIBS) $(LIBSIGC_LIBS) $(GTKMM_LIBS)
hop_CPPFLAGS = $(LIBJSONCPP_CFLAGS) $(LIBSIGC_CFLAGS) $(GTKMM_CFLAGS) -std=c++0x


hop_SOURCES = 	src/main.cpp \
		src/Debug/Dbg.cpp \
		src/Generator/Generator.cpp \
		src/GUI/GtkMain.cpp \
		src/GUI/UMLDiagramWidget/UMLDiagramWidget.cpp \
		src/GUI/UMLDiagramWidget/SignatureEditor.cpp \
		src/GUI/UMLDiagramWidget/PropertySignatureEditor.cpp \
		src/GUI/UMLDiagramWidget/MethodSignatureEditor.cpp \
		src/GUI/UMLDiagramWidget/UML/UMLClass.cpp \
		src/GUI/UMLDiagramWidget/UML/UMLMethod.cpp \
		src/GUI/UMLDiagramWidget/UML/UMLLink.cpp \
		src/GUI/UMLDiagramWidget/UML/UMLProperty.cpp \
		src/GUI/UMLDiagramWidget/UML/UMLMember.cpp \
		src/GUI/UMLDiagramWidget/UMLClassPropertiesWindow.cpp \
		src/utils/CairoDrawer.cpp