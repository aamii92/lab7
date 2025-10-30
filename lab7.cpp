#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Shape {
public:
    int x, y;
    char* name;
    // Эх классын параметртэй байгуулагч
    Shape(const char* n, int xcoor, int ycoor) {
        cout << "Constructor of Shape is called" << endl;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        x = xcoor;
        y = ycoor;
    }

    // Эх классын устгагч
     ~Shape() {
        delete[] name;
        cout << "Destructor of Shape is called" << endl;
    }
};

class TwoDShape : public Shape {
public:
    float r;

    // TwoDShape-ийн байгуулагч — Shape-ийг дуудаж байна
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

// -------------------- Square --------------------
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

// -------------------- Triangle --------------------
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

// -------------------- Main --------------------
int main() {
    Circle c1("Circle1", 3, 0, 0);
    Circle c2("Circle2", 5, 2, 2);
    Square s1("Square1", 4, 1, 1);
    Square s2("Square2", 2,6,7);
    Triangle t1("Triangle1", 6, 2, 2);
    Triangle t2("Triangle2", 4,9,2);

    // Бүх дүрсүүдийг массивт хадгалъя
    TwoDShape* shapes[6] = { &c1, &c2, &s1, &s2, &t1, &t2 };
    float areas[6] = { c1.Area(), c2.Area(), s1.Area(), s2.Area(), t1.Area(), t2.Area() };

    // Талбайгаар эрэмбэлэх (simple bubble sort)
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (areas[i] > areas[j]) {
                swap(areas[i], areas[j]);
                swap(shapes[i], shapes[j]);
            }
        }
    }

    cout << "\n--- Талбайгаар эрэмбэлсэн жагсаалт ---\n";
    for (int i = 0; i < 6; i++) {
        cout << shapes[i]->name << " -> Талбай = " << areas[i] << endl;
    }

    cout << endl;
    return 0;
}
