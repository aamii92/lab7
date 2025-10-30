#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Shape {
public:
    int x, y;
    char* name;

    // Эцэг классын байгуулагч
    Shape(const char* n, int xcoor, int ycoor) {
        cout << "Constructor of Shape is called" << endl;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        x = xcoor;
        y = ycoor;
    }

    // Эцэг классын устгагч
    virtual ~Shape() {
        delete[] name;
        cout << "Destructor of Shape is called" << endl;
    }
};

class TwoDShape : public Shape {
public:
    float r;

    //  TwoDShape-ийн байгуулагч — Shape-ийг дуудаж байна
    TwoDShape(const char* n, float length, int xcoor, int ycoor)
        : Shape(n, xcoor, ycoor) {
        cout << "Constructor of TwoDShape is called" << endl;
        r = length;
    }

    ~TwoDShape() {
        cout << "Destructor of TwoDShape is called" << endl;
    }
};

// -------------------- Circle --------------------
class Circle : public TwoDShape {
public:
    Circle(const char* n, float length, int xcoor, int ycoor)
        : TwoDShape(n, length, xcoor, ycoor) {
        cout << "Constructor of Circle is called" << endl;
    }

    ~Circle() {
        cout << "Destructor of Circle is called" << endl;
    }

    float Area() { return 3.14 * r * r; }
};

class Square : public TwoDShape {
public:
    Square(const char* n, float length, int xcoor, int ycoor)
        : TwoDShape(n, length, xcoor, ycoor) {
        cout << "Constructor of Square is called" << endl;
    }

    ~Square() {
        cout << "Destructor of Square is called" << endl;
    }

    float Area() { return r * r; }
};


class Triangle : public TwoDShape {
public:
    Triangle(const char* n, float length, int xcoor, int ycoor)
        : TwoDShape(n, length, xcoor, ycoor) {
        cout << "Constructor of Triangle is called" << endl;
    }

    ~Triangle() {
        cout << "Destructor of Triangle is called" << endl;
    }

    float Area() { return (sqrt(3) / 4) * r * r; }
};

int main() {
    Circle c1("Circle1", 3, 0, 0);
    Circle c2("Circle2", 5, 2, 2);
    Square s1("Square1", 4, 1, 1);
    Triangle t1("Triangle1", 6, 2, 2);

    // Бүх дүрсүүдийг массивт хадгалж байна
    TwoDShape* shapes[4] = { &c1, &c2, &s1, &t1 };
    float areas[4] = { c1.Area(), c2.Area(), s1.Area(), t1.Area() };

    // Талбайгаар эрэмбэлэх ( bubble sort)
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (areas[i] > areas[j]) {
                swap(areas[i], areas[j]);
                swap(shapes[i], shapes[j]);
            }
        }
    }

    cout << "\n--- Талбайгаар эрэмбэлсэн жагсаалт ---\n";
    for (int i = 0; i < 4; i++) {
        cout << shapes[i]->name << " -> Талбай = " << areas[i] << endl;
    }

    cout << endl;
    return 0;
}
