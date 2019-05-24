#include <iostream>
using namespace std;
class circle {
	public:                             
	double radius;
	double pi;
	circle() {
                radius = 2;
                pi = 3.14159;
        }
        double input() {
                cout << "Enter radius: ";
                cin >> radius;
                return radius;
        }
	double area() {
		return pi * radius * radius;
	}
};
class rectangle {
        public:
        double length;
        double breadth;
        rectangle() {
                length = 2;
                breadth = 2;
        }
        double input() {
                cout << "Enter length and breadth in order: ";
                cin >> length >> breadth;
                return length;
                return breadth;
        }
        double area() {
                return length * breadth;
        }
};
int main() {
	circle C1;
	cout << "Area of default circle: " << C1.area() << " square units" << endl;
	circle C2;
	C2.input();
	cout << "Area: " << C2.area() << " square units" << endl;
	rectangle R1;
	cout << "Area of default rectangle: " << R1.area() << " square units" << endl;
	rectangle R2;
	R2.input();
	cout << "Area: " << R2.area() << " square units" << endl;
	return 0;
}
