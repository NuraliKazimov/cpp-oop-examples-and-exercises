#include <iostream>

using namespace std;


/*
    Inheritance and Polymorphism with Static members
*/

/*
    Exercise: Implement static methods within the Circle and Rectangle classes 
    to calculate the areas of circles and rectangles, respectively. 
    Additionally, create a static method in the Shape class to compare the areas of two shapes.

    Tasks:

    1. Implement the CalculateArea static methods in the Circle and Rectangle classes to calculate the areas of circles and rectangles, respectively.
    2. Create a static method in the Shape class to compare the areas of two shapes. You'll need to access the CalculateArea static methods in the derived classes for this comparison.
    3. In the main function, prompt the user to enter the radius for a circle and the width and height for a rectangle.
    4. Calculate and display the areas of the circle and rectangle using the static methods.

    Implement comparisons of areas using the static method in the Shape class to determine if the areas are equal.
*/

class Shape {
    public:
        // Static method to compare the areas of two shapes
        // Hint: You'll need to access the CalculateArea static methods in the derived classes.
        static void compare(); 
        
};

class Circle : public Shape {
    public:
        double radius;
        static double area;
        Circle(double radius) : radius(radius) {
             area=3.14*radius*radius;
        }
        static double calculateArea() {
            return area;
        }

        // Static method to calculate the area of a circle
        // Hint: Use the formula for calculating the area of a circle (A = π * r^2)
};

class Rectangle : public Shape {
    public:
    double width, height;
    static double area;
        Rectangle(double width, double height) : width(width), height(height) {
            area=width*height;
        }

        // Static method to calculate the area of a rectangle
        // Hint: Use the formula for calculating the area of a rectangle (A = width * height)
         static double calculateArea() {
            return area;
        }
};

double Circle::area=0;
double Rectangle::area=0;

 void Shape::compare() {
            if (Circle::calculateArea()<Rectangle::calculateArea()) {
                cout << "Area of the rectangle is bigger" << endl;
            } else if (Circle::calculateArea()>Rectangle::calculateArea()) {
                cout << "Area of the circle is bigger" << endl;
            } else {
                cout << "Areas are the same" << endl;
            }
        }

int main() {
    double circleRadius, rectWidth, rectHeight;

    cout << "Enter the radius of a circle: ";
    cin >> circleRadius;

    cout << "Enter the width and height of a rectangle: ";
    cin >> rectWidth >> rectHeight;

    // Calculate and display the areas using the static methods
    Circle circle(circleRadius);
    Rectangle rec(rectWidth,rectHeight);
    cout << "Area of the circle: " << circle.calculateArea() << endl;
    cout << "Area of the rectangle: " << rec.calculateArea() << endl;
    Shape::compare();

    // Implement comparisons of areas using the static method in the Shape class

    return 0;
}
