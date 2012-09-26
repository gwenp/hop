#include "UMLLink.hpp"

#include "UMLClass.hpp"

UMLLink::UMLLink(UMLClass* class1, UMLClass* class2) : _class1(class1), _class2(class2), _linkType_begin(LinkTypes::ASSOCIATION), _linkType_end(LinkTypes::ASSOCIATION)
{

}

void UMLLink::draw(Gtk::DrawingArea* drawingArea)
{
	Cairo::RefPtr<Cairo::Context> cr = drawingArea->get_window()->create_cairo_context();

	if(_class1 != _class2)
	{	

		Arrow::Type typeBegin, typeEnd;
		Line::Type lineType = Line::FULL;

		switch(getLinkTypeBegin())
		{
			case LinkTypes::ASSOCIATION:
				typeBegin = Arrow::NONE;
				break;
			case LinkTypes::COMPOSITION:
				typeBegin = Arrow::DIAMONDFILLED;
				break;
			case LinkTypes::AGGREGATION:
				typeBegin = Arrow::DIAMOND;
				break;
			case LinkTypes::DEPENDENCY:
				typeBegin = Arrow::OPEN;
				lineType = Line::DASHED;
				break;
			case LinkTypes::NAVIGATION:
				typeBegin = Arrow::OPEN;
				break;
		}
		
		switch(getLinkTypeEnd())
		{
			case LinkTypes::ASSOCIATION:
				typeEnd = Arrow::NONE;
				break;
			case LinkTypes::COMPOSITION:
				typeEnd = Arrow::DIAMONDFILLED;
				break;
			case LinkTypes::AGGREGATION:
				typeEnd = Arrow::DIAMOND;
				break;
			case LinkTypes::DEPENDENCY:
				lineType = Line::DASHED;
				typeEnd = Arrow::OPEN;
				break;
			case LinkTypes::NAVIGATION:
				typeEnd = Arrow::OPEN;
				break;

		}

		if(_class1 != _class2)
			Arrows::draw_arrow(cr, getX1(), getY1(), getX2(), getY2(), lineType, typeBegin, typeEnd, isSelected());
	}
	else
	{
		int x = _class1->getCenterX() - _class1->getWidth()/3;
		int y = _class1->getCenterY() - _class1->getHeight()/2;

		Arrow::Type typeBegin, typeEnd;

		switch(getLinkTypeBegin())
		{
			case LinkTypes::ASSOCIATION:
				typeBegin = Arrow::NONE;
				break;
			case LinkTypes::COMPOSITION:
				typeBegin = Arrow::DIAMONDFILLED;
				break;
			case LinkTypes::AGGREGATION:
				typeBegin = Arrow::DIAMOND;
				break;
			case LinkTypes::NAVIGATION:
				typeBegin = Arrow::OPEN;
				break;

		}
		switch(getLinkTypeEnd())
		{
			case LinkTypes::ASSOCIATION:
				typeEnd = Arrow::NONE;
				break;
			case LinkTypes::COMPOSITION:
				typeEnd = Arrow::DIAMONDFILLED;
				break;
			case LinkTypes::AGGREGATION:
				typeEnd = Arrow::DIAMOND;
				break;
			case LinkTypes::NAVIGATION:
				typeEnd = Arrow::OPEN;
				break;
		}
		
		Arrows::draw_arrow(cr, x, y+40, x-100, y+40, Line::NONE, Arrow::NONE, typeBegin, isSelected());
		Arrows::draw_arrow(cr, x+40, y, x+40, y-100, Line::NONE, Arrow::NONE, typeEnd, isSelected());
		if(isSelected())
			cr->set_source_rgb(1.0, 0.0, 0.0);
		else
			cr->set_source_rgb(0.0, 0.0, 0.0);

		cr->arc(x, y, 40, 20.7f, 0);
		cr->stroke();
	}
}

bool UMLLink::isPointOnElement(int x, int y)
{
	if(_class1 != _class2)
	{	
		float distance;

		int x1 = getX1();
		int y1 = getY1();
		int x2 = getX2();
		int y2 = getY2();

		float dx=x-x1;
		float dy=y-y1;

		float l=sqrt( ( getX2() - getX1() ) * ( getX2() - getX1() ) + ( getY2() - getY1() ) * ( getY2() - getY1() ) ) ;
		
		float lx=(x2-x1)/l;
		float ly=(y2-y1)/l;
		
		float d=lx*dx+ly*dy;
		
		if(d<0)
		{
			distance = sqrt(dx*dx+dy*dy);
		}

		if(d>l)
		{
			dx=x-x2;
			dy=y-y2;
			distance = sqrt(dx*dx+dy*dy);
		}

		dx-=lx*d;
		dy-=ly*d;
		distance = sqrt(dx*dx+dy*dy);

		std::cout << "distance = " << distance << std::endl;

		if(distance < 5)
			return true;
		else
			return false;
	}
	else
	{
		int centerX = _class1->getCenterX() - _class1->getWidth()/3;
		int centerY = _class1->getCenterY() - _class1->getHeight()/2;

		if(abs(x - centerX) < 20 && abs(y - centerY) < 20)
		{
			if(x > centerX && y > centerY)
				return false;
			else
				return true;
		}
		else return false;
	}
}

LinkTypes::Types UMLLink::getLinkTypeBegin()
{
	return _linkType_begin;
}

void UMLLink::setLinkTypeBegin(LinkTypes::Types linkTypeBegin)
{
	_linkType_begin = linkTypeBegin;
}

LinkTypes::Types UMLLink::getLinkTypeEnd()
{
	return _linkType_end;
}

void UMLLink::setLinkTypeEnd(LinkTypes::Types linkTypeEnd)
{
	_linkType_end = linkTypeEnd;
}

std::string UMLLink::getMultiplicityBegin()
{
	return _multiplicity_begin;
}

void UMLLink::setMultiplicityBegin(std::string multiplicityBegin)
{
	_multiplicity_begin = multiplicityBegin;
}

std::string UMLLink::getMultiplicityEnd()
{
	return _multiplicity_end;
}

void UMLLink::setMultiplicityEnd(std::string multiplicityEnd)
{
	_multiplicity_end = multiplicityEnd;
}


int UMLLink::getX1()
{
	int x1;

	int class1x1 = _class1->getCenterX() - _class1->getWidth() / 2;
	int class1x2 = _class1->getCenterX() + _class1->getWidth() / 2;
	int class2x1 = _class2->getCenterX() - _class2->getWidth() / 2;
	int class2x2 = _class2->getCenterX() + _class2->getWidth() / 2;

	if(class1x2 < class2x1)
	{
		x1 = _class2->getCenterX() - _class2->getWidth()/2;
	}
	else if(class1x1 > class2x2)
	{
		x1 = _class2->getCenterX() + _class2->getWidth()/2;
	}
	else
	{
		x1 = _class2->getCenterX();
	}

	return x1;
}

int UMLLink::getY1()
{
	int y1;

	int class1y1 = _class1->getCenterY() - _class1->getHeight() / 2;
	int class1y2 = _class1->getCenterY() + _class1->getHeight() / 2;
	int class2y1 = _class2->getCenterY() - _class2->getHeight() / 2;
	int class2y2 = _class2->getCenterY() + _class2->getHeight() / 2;

	if(class1y2 < class2y1)
	{
		y1 = _class2->getCenterY() - _class2->getHeight()/2;
	}
	else if(class1y1 > class2y2)
	{
		y1 = _class2->getCenterY() + _class2->getHeight()/2;
	}
	else
	{
		y1 = _class2->getCenterY();
	}

	return y1;
}

int UMLLink::getX2()
{
	int x2;

	int class1x1 = _class1->getCenterX() - _class1->getWidth() / 2;
	int class1x2 = _class1->getCenterX() + _class1->getWidth() / 2;
	int class2x1 = _class2->getCenterX() - _class2->getWidth() / 2;
	int class2x2 = _class2->getCenterX() + _class2->getWidth() / 2;

	if(class1x2 < class2x1)
	{
		x2 = _class1->getCenterX() + _class1->getWidth()/2;
	}
	else if(class1x1 > class2x2)
	{
		x2 = _class1->getCenterX() - _class1->getWidth()/2;
	}
	else
	{
		x2 = _class1->getCenterX();
	}

	return x2;
}

int UMLLink::getY2()
{
	int y2;

	int class1y1 = _class1->getCenterY() - _class1->getHeight() / 2;
	int class1y2 = _class1->getCenterY() + _class1->getHeight() / 2;
	int class2y1 = _class2->getCenterY() - _class2->getHeight() / 2;
	int class2y2 = _class2->getCenterY() + _class2->getHeight() / 2;

	if(class1y2 < class2y1)
	{
		y2 = _class1->getCenterY() + _class1->getHeight()/2;
	}
	else if(class1y1 > class2y2)
	{
		y2 = _class1->getCenterY() - _class1->getHeight()/2;
	}
	else
	{
		y2 = _class1->getCenterY();
	}

	return y2;
}

ElementType::Type UMLLink::getType()
{
	return ElementType::LINK;
}
