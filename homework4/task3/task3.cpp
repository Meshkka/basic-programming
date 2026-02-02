#include <iostream>
#include <string>

class Figure {
protected:
    std::string name;
    int sides_count;

public:
    Figure(const std::string& name = "Фигура", int sides = 0) : name(name), sides_count(sides) 
    {}

    virtual ~Figure() = default;

    virtual void print_info() const {
        std::cout << name << ":" << std::endl;
        std::cout << (check() ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << sides_count << std::endl;
    }

    virtual bool check() const {
        return sides_count == 0;
    }
};

class Triangle : public Figure {
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : Figure("Треугольник", 3), a(a), b(b), c(c), A(A), B(B), C(C) {
    }

    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }

    bool check() const override {
        return (sides_count == 3) && (A + B + C == 180);
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    }

    bool check() const override {
        return Triangle::check() && (C == 90);
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A) {
        name = "Равнобедренный треугольник";
    }

    bool check() const override {
        return Triangle::check() && (a == c) && (A == C);
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }

    bool check() const override {
        return Triangle::check() && (a == b && b == c) && (A == 60 && B == 60 && C == 60);
    }
};

class Quadrilateral : public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrilateral(double a, double b, double c, double d,
        double A, double B, double C, double D)
        : Figure("Четырёхугольник", 4), a(a), b(b), c(c), d(d),
        A(A), B(B), C(C), D(D) {
    }

    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }

    bool check() const override {
        return (sides_count == 4) && (A + B + C + D == 360);
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }

    bool check() const override {
        return Quadrilateral::check() &&
            (a == c && b == d) &&
            (A == 90 && B == 90 && C == 90 && D == 90);
    }
};

class Square : public Rectangle {
public:
    Square(double side)
        : Rectangle(side, side) {
        name = "Квадрат";
    }

    bool check() const override {
        return Rectangle::check() && (a == b && b == c && c == d);
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }

    bool check() const override {
        return Quadrilateral::check() &&
            (a == c && b == d) &&
            (A == C && B == D);
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double side, double A, double B)
        : Parallelogram(side, side, A, B) {
        name = "Ромб";
    }

    bool check() const override {
        return Parallelogram::check() && (a == b && b == c && c == d);
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    Figure* figure = new Figure();
    Figure* triangle = new Triangle(10, 20, 30, 50, 60, 70);
    Figure* rightTriangle1 = new RightTriangle(10, 20, 30, 50, 60);
    Figure* rightTriangle2 = new RightTriangle(10, 20, 30, 50, 40);
    Figure* isoscelesTriangle = new IsoscelesTriangle(10, 20, 50, 60);
    Figure* equilateralTriangle = new EquilateralTriangle(30);
    Figure* quadrilateral = new Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Figure* rectangle = new Rectangle(10, 20);
    Figure* square = new Square(20);
    Figure* parallelogram = new Parallelogram(20, 30, 30, 40);
    Figure* rhombus = new Rhombus(30, 30, 40);

    std::cout << std::endl;
    figure->print_info();
    std::cout << std::endl;

    triangle->print_info();
    std::cout << std::endl;

    rightTriangle1->print_info();
    std::cout << std::endl;

    rightTriangle2->print_info();
    std::cout << std::endl;

    isoscelesTriangle->print_info();
    std::cout << std::endl;

    equilateralTriangle->print_info();
    std::cout << std::endl;

    quadrilateral->print_info();
    std::cout << std::endl;

    rectangle->print_info();
    std::cout << std::endl;

    square->print_info();
    std::cout << std::endl;

    parallelogram->print_info();
    std::cout << std::endl;

    rhombus->print_info();
    std::cout << std::endl;

    delete figure;
    delete triangle;
    delete rightTriangle1;
    delete rightTriangle2;
    delete isoscelesTriangle;
    delete equilateralTriangle;
    delete quadrilateral;
    delete rectangle;
    delete square;
    delete parallelogram;
    delete rhombus;

    return 0;
}