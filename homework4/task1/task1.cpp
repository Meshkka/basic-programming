#include <iostream>
#include <string>

class Figure {
protected:
    int sides_count;
    std::string name;

public:
    Figure() : sides_count(0), name("Фигура") 
    {}

    Figure(int count, const std::string& fig_name) : sides_count(count), name(fig_name) 
    {}

    int get_sides_count() const {
        return sides_count;
    }

    std::string get_name() const {
        return name;
    }

    virtual ~Figure() = default;
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3, "Треугольник") {}
};

class Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4, "Четырёхугольник") {}
};

int main() {
    setlocale(LC_ALL, "RU");

    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;

    std::cout << "Количество сторон:" << std::endl;
    std::cout << figure.get_name() << ": " << figure.get_sides_count() << std::endl;
    std::cout << triangle.get_name() << ": " << triangle.get_sides_count() << std::endl;
    std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << std::endl;

    return 0;
}