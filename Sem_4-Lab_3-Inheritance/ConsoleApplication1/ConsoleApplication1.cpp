#include <iostream>
#include <string>
#include <cmath>
constexpr auto PI = 3.14;
using namespace std;


class Shape {

public:

	virtual void ShowInfo() = 0;
	virtual std::string GetName() = 0;
};

class Shape2D : public Shape {
public:
	float area;
	virtual void CalculateArea() = 0;
	virtual float GetArea() = 0;
};


class Square : public Shape2D {
private:
	float side;
public:
	Square(float side)
		: side(side) {}
	void CalculateArea() override {
		this->area = side * side;
	}
	string GetName() {
		return "Square";
	}
	float GetArea() override {
		return this->area;
	}
	void ShowInfo() override {
		CalculateArea();
		std::cout << "Я квадрат " << std::endl;
		std::cout << "Моя сторона = " << side << std::endl;
		std::cout << "Моя площадь = " << GetArea() << "\n" << std::endl;
	}
};

class Triangle : public Shape2D {
private:
	float base, height;
public:
	Triangle(float base, float height)
		: base(base), height(height) {}

	string GetName() override {
		return "triangle";
	}
	void CalculateArea() override {
		area = (base * height) / 2;
	}
	float GetArea() override {
		return this->area;
	}
	void ShowInfo() override {
		std::cout << "Я треугольник " << std::endl;
		std::cout << "Длина основания = " << base << std::endl;
		std::cout << "Моя высота = " << height << std::endl;
		std::cout << "Моя площадь = " << this->GetArea() << "\n" << std::endl;
	}
};

class Circle : public Shape2D {
private:
	float radius;
public:
	Circle(float radius)
		:radius(radius) {}
	void CalculateArea() override {
		this->area = radius * radius * PI;
	}
	float GetArea() override {
		return this->area;
	}
	string GetName() override {
		return "Я круг! ";
	}
	void ShowInfo() override {
		std::cout << this->GetName() << std::endl;
		std::cout << "Мой радиус = " << radius << std::endl;
		std::cout << "Моя площадь = " << this->GetArea() << "\n" << std::endl;
	}
};

class Shape3D : public Shape {
private:
public:
	float volume;
	virtual float GetVolume() = 0;
	virtual void CalculateVolume() = 0;
};

class TriangularPyramid : public Shape3D {
private:
	Triangle baseTriangle;
	float PyramidHeight;
public:
	TriangularPyramid(float h, float base, float height)
		:PyramidHeight(h), baseTriangle(base, height) {}

	float GetVolume() override {
		return volume;
	}
	string GetName() override {
		return "Я треугольная пирамида!";
	}
	void CalculateVolume() override {
		baseTriangle.CalculateArea();
		volume = baseTriangle.GetArea() * PyramidHeight * 1 / 3;
	}
	void ShowInfo() override {
		std::cout << this->GetName() << std::endl;
		std::cout << "Моя высота = " << PyramidHeight << std::endl;
		std::cout << "Мой объем = " << this->GetVolume() << "\n" << std::endl;
	}

};

class Cylinder : public Shape3D {
private:
	Circle baseCircle;
	float CylinderHeight;
public:
	Cylinder(float CylinderHeight, float radius)
		:CylinderHeight(CylinderHeight), baseCircle(radius) {}

	float GetVolume() override {
		return volume;
	}
	string GetName() override {
		return "Я цилиндр!";
	}
	void CalculateVolume() override {
		baseCircle.CalculateArea();
		volume = baseCircle.GetArea() * CylinderHeight * 1 / 3;
	}
	void ShowInfo() override {

		std::cout << this->GetName() << std::endl;
		std::cout << "Моя высота = " << CylinderHeight << std::endl;
		std::cout << "Мой объем = " << this->GetVolume() << "\n" << std::endl;
	}
};

class Sphere : public Shape3D {
private:
	float radius;
public:
	Sphere(float radius)
		:radius(radius) {}

	float GetVolume() override {
		return volume;
	}
	string GetName() override {
		return "Я сфера!";
	}
	void CalculateVolume() override {
		volume = 4 / 3 * PI * pow(radius, 3);
	}
	void ShowInfo() override {
		CalculateVolume();
		std::cout << this->GetName() << std::endl;
		std::cout << "Мой радиус = " << radius << std::endl;
		std::cout << "Мой объем = " << this->GetVolume() << "\n" << std::endl;
	}
};



int main() {
	setlocale(LC_ALL, "rus");

	Square sq(3.0);
	//sq.CalculateArea();
	sq.ShowInfo();

	Triangle tr(4.0, 5.0);
	tr.CalculateArea();
	tr.ShowInfo();

	Circle ci(5);
	ci.CalculateArea();
	ci.ShowInfo();

	TriangularPyramid tp(10.0, 4.0, 5.0);
	tp.CalculateVolume();
	tp.ShowInfo();

	Cylinder cy(15.0, 5.0);
	cy.CalculateVolume();
	cy.ShowInfo();

	Sphere sp(5.4);
	sp.ShowInfo();

}








//class MyClass {
//private:
//	int Size;
//public:
//	int* data;
//	MyClass(int size)
//		: Size(size){
//		data = new int[size];
//		for (int i = 0; i < size; i++) 
//		{
//			data[i] = i;
//		}
//	}
//	MyClass(const MyClass &other){
//		this->Size = other.Size;
//
//		this->data = new int[other.Size];
//
//		for (int i = 0; i < other.Size; i++)
//		{
//			this->data[i] = other.data[i];
//		}
//	}
//
//};