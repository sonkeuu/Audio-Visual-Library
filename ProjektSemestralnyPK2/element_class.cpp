#include <iostream>
import Square, Rectangle;

using namespace std;

class Element {

};

class SquarePillar: public Element {

	float amount_of_material(float width, float length) {
		
		float Volume = Square(width).get_area * length;
		return Volume;
	}
};

class Door : public Element {

	float amount_of_material(float height, float width, float grubosc) {
	
		float Volume = Rectangle(height, width) * grubosc;
		return Volume;
	}
};

