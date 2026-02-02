#include <iostream>
#include <string>

using namespace std;

class Figure {
public:
    virtual void print() const = 0;
    virtual ~Figure() = default;
};

class Triangle : public Figure {
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C) {}

    void print() const override {
        cout << "Треугольник:\n";
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90) {}

    void print() const override {
        cout << "Прямоугольный треугольник:\n";
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A) {}

    void print() const override {
        cout << "Равнобедренный треугольник:\n";
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side) : Triangle(side, side, side, 60, 60, 60) {}

    void print() const override {
        cout << "Равносторонний треугольник:\n";
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class Quadrilateral : public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrilateral(double a, double b, double c, double d,
        double A, double B, double C, double D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
    }

    void print() const override {
        cout << "Четырехугольник:\n";
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {
    }

    void print() const override {
        cout << "Прямоугольник:\n";
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

class Square : public Quadrilateral {
public:
    Square(double side) : Quadrilateral(side, side, side, side, 90, 90, 90, 90) {}

    void print() const override {
        cout << "Квадрат:\n";
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A, double B) : Quadrilateral(a, b, a, b, A, B, A, B) {}

    void print() const override {
        cout << "Параллелограмм:\n";
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

class Rhombus : public Quadrilateral {
public:
    Rhombus(double side, double A, double B) : Quadrilateral(side, side, side, side, A, B, A, B) {}

    void print() const override {
        cout << "Ромб:\n";
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

void print_info(const Figure* figure) {
    figure->print();
}

int main() {
    setlocale(LC_ALL, "RU");

    Triangle t(10, 20, 30, 50, 60, 70);
    RightTriangle rt(10, 20, 30, 50, 60);
    IsoscelesTriangle it(10, 20, 50, 60);
    EquilateralTriangle et(30);

    Quadrilateral q(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle r(10, 20);
    Square s(20);
    Parallelogram p(20, 30, 30, 40);
    Rhombus rh(30, 30, 40);

    print_info(&t);
    print_info(&rt);
    print_info(&it);
    print_info(&et);
    print_info(&q);
    print_info(&r);
    print_info(&s);
    print_info(&p);
    print_info(&rh);

    return 0;
}