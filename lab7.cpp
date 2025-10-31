    #include <iostream>
    #include <cstring>
    #include <cmath>
    using namespace std;

    // Эх класс 
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
    // TwoDShape классыг Shape-аас удамшуулж байна
    class TwoDShape : public Shape {
    public:
        float r;

        // TwoDShape-ийн параметртэй байгуулагч — Shape-ийг дуудаж байна
        TwoDShape(const char* n, float length, int xcoor, int ycoor)
            : Shape(n, xcoor, ycoor) {
            cout << "Constructor of TwoDShape is called" << endl;
            r = length;
        }
        // TwoDShape классын устгагч
        ~TwoDShape() {
            cout << "Destructor of TwoDShape is called" << endl;
        }
        virtual float Area() = 0;
    };

    //  Circle классыг TwoDShape-аас удамшуулж байна
    class Circle : public TwoDShape {
    public:
        // Circle классын параметртэй байгуулагч — TwoDShape-ийг дуудаж байна
        Circle(const char* n, float length, int xcoor, int ycoor)
            : TwoDShape(n, length, xcoor, ycoor) {
            cout << "Constructor of Circle is called" << endl;
        }
        // Circle классын устгагч
        ~Circle() {
            cout << "Destructor of Circle is called" << endl;
        }
        // Талбайг олох функц
        float Area() override { return 3.14 * r * r; }
    };

    // Square классыг TwoDShape-аас удамшуулж байна
    class Square : public TwoDShape {
    public:
        // Square классын параметртэй байгуулагч — TwoDShape-ийг дуудаж байна
        Square(const char* n, float length, int xcoor, int ycoor)
            : TwoDShape(n, length, xcoor, ycoor) {
            cout << "Constructor of Square is called" << endl;
        }
        // Square классын устгагч
        ~Square() {
            cout << "Destructor of Square is called" << endl;
        }
        // Талбайг олох функц
        float Area() override { return r * r; }
    };

    // Triangle классыг TwoDShape-аас удамшуулж байна
    class Triangle : public TwoDShape {
    public:
    // Square классын параметртэй байгуулагч — TwoDShape-ийг дуудаж байна
        Triangle(const char* n, float length, int xcoor, int ycoor)
            : TwoDShape(n, length, xcoor, ycoor) {
            cout << "Constructor of Triangle is called" << endl;
        }
        // Triangle классын устгагч
        ~Triangle() {
            cout << "Destructor of Triangle is called" << endl;
        }
        // Талбайг олох функц
        float Area() override { return (sqrt(3) / 4) * r * r; }
    };

    // main функц
    int main() {
        // Дүрсүүдийг утга оноож байна
        Circle c1("Circle1", 3, 0, 0);
        Circle c2("Circle2", 5, 2, 2);
        Square s1("Square1", 4, 1, 1);
        Square s2("Square2", 2, 6, 7);
        Triangle t1("Triangle1", 6, 2, 2);
        Triangle t2("Triangle2", 4, 9, 2);
    
    
        //Дүрсийн нэр болон талын уртыг хэвлэлт
        cout<< "\n Өгөгдсөн мэдээлэл: \n"<<endl;
        cout<<c1.name<<"-> Радиус:"<<c1.r<<endl;
        cout<<c2.name<<"-> Радиус:"<<c2.r<<endl;
        cout<<s1.name<<"-> Талын урт:"<<s1.r<<endl;
        cout<<s2.name<<"-> Талын урт:"<<s2.r<<endl;
        cout<<t1.name<<"-> Талын урт:"<<t1.r<<endl;
        cout<<t2.name<<"-> Талын урт:"<<t2.r<<endl<<endl;


        // Бүх дүрсүүдийг массивт хадгалж байна
    TwoDShape* shapes[6] = { &c1 , &c2, &s1, &s2, &t1, &t2 };
  for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (shapes[i]->Area() > shapes[j]->Area()) {
                swap(shapes[i], shapes[j]);
            }
        }
    }

    // Хэвлэлт
    cout << "\n--- Объектуудыг ТАЛБАЙГААР эрэмбэлсэн жагсаалт ---\n";
    for (int i = 0; i < 6; i++) {
        cout << shapes[i]->name << " -> Талбай = " << shapes[i]->Area() << endl;
    }

    }
