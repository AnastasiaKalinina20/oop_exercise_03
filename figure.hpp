#pragma once

#include <iostream>
#include <cmath>
#include "vector.hpp"

class Figure{
    public:
        double Ax, Ay;
        double Bx, By;
        double Cx, Cy;
        double Dx, Dy;
        double cenX, cenY;
        double S;

        virtual void printPoints(){
			std::cout << "(" << Ax << "," << Ay << ")" << std::endl;
			std::cout << "(" << Bx << "," << By << ")" << std::endl;
			std::cout << "(" << Cx << "," << Cy << ")" << std::endl;
		}

        virtual void type(){
            std::cout << "No type" << std::endl;
        }

        void printArea(){
            std::cout << "Площадь: " << S << std::endl;
        }

        void printCenter(){
            std::cout << "Геометрический центр: (" << cenX << "," << cenY << ")" << std::endl;
        }

        virtual void calcArea(){
            S = 0;
        }

        virtual void calcCenter(){
            cenX = cenY = 0;
        }

};

class Square: public Figure{
public:

    Square(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy){
            Ax = ax;
            Ay = ay;
            Bx = bx;
            By = by;
            Cx = cx;
            Cy = cy;
            Dx = dx;
            Dy = dy;
            calcArea();
            calcCenter();
        }

    void type() override{
        std::cout << "Квадрат" << std::endl;
    }

    void printPoints() override{
        std::cout << "(" << Ax << "," << Ay << ")" << std::endl;
        std::cout << "(" << Bx << "," << By << ")" << std::endl;
        std::cout << "(" << Cx << "," << Cy << ")" << std::endl;
        std::cout << "(" << Dx << "," << Dy << ")" << std::endl;
    }

    void calcArea() override{   // площадь
        Vector l1, l2;
        l1.setup(Ax, Ay, Bx, By);
        l2.setup(Bx, By, Cx, Cy);
        S = fabs(l1.length * l2.length);
    }

    void calcCenter() { // центр
        cenX = (Ax + Cx) / 2;
        cenY = (Ay + Cy) / 2;
    }
};

class Rectangle: public Figure{
public: 

    Rectangle(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy){
        Ax = ax;
        Ay = ay;
        Bx = bx;
        By = by;
        Cx = cx;
        Cy = cy;
        Dx = dx;
        Dy = dy;
        calcCenter();
        calcArea();
     }

    void printPoints() override{
        std::cout << "(" << Ax << "," << Ay << ")" << std::endl;
        std::cout << "(" << Bx << "," << By << ")" << std::endl;
        std::cout << "(" << Cx << "," << Cy << ")" << std::endl;
        std::cout << "(" << Dx << "," << Dy << ")" << std::endl;
    }

    void type() override{
        std::cout << "Прямоугольник" << std::endl;
    }

    void calcArea() override{   // площадь
        Vector l1, l2;
        l1.setup(Ax, Ay, Bx, By);
        l2.setup(Bx, By, Cx, Cy);
        S = fabs(l1.length * l2.length);
    }

    void calcCenter(){  // центр
        cenX = (Ax + Cx) / 2;
        cenY = (Ay + Cy) / 2;
    }
};

class Triangle: public Figure{
public:

    Triangle(double ax, double ay, double bx, double by, double cx, double cy){
            Ax = ax;
            Ay = ay;
            Bx = bx;
            By = by;
            Cx = cx;
            Cy = cy;
            calcCenter();
            calcArea();
    }

    void type() override{
        std::cout << "Треугольник" << std::endl; 
    }

    void calcArea() override{   // площадь
        Vector v1, v2, v3;
        v1.setup(Ax, Ay, Bx, By);
        v2.setup(Bx, By, Cx, Cy);
        v3.setup(Ax, Ay, Cx, Cy);
        double p = 0.5 * (v1.length + v2.length + v3.length);
        S = sqrt(p * (p - v1.length) * (p - v2.length) * (p - v3.length));
    }

    void calcCenter(){    // центр
            cenX = (Ax + Bx + Cx) / 3.0;
            cenY = (Ay + By + Cy) / 3.0;
    }
};