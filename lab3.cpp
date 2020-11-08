/* Разработать классы согласно варианту задания, классы должны наследоваться от базового класса Figure.
Фигуры являются фигурами вращения.
Все классы должны поддерживать набор общих методов:
1.   	Вычисление геометрического центра фигуры;
2.   	Вывод в стандартный поток вывода std::cout координат вершин фигуры; 
3. Вычисление площади фигуры.
 
Создать программу, которая позволяет:
•       Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
•       Сохранять созданные фигуры в динамический массив std::vector<Figure*>.
•   	Вызывать для всего массива общие функции (1-3 см. выше).
		Т.е. распечатывать для каждой фигуры в массиве геометрический центр, координаты вершин и площадь.
•       Необходимо уметь вычислять общую площадь фигур в массиве.
•       Удалять из массива фигуру по индексу.

Вариант 1: треугольник, квадрат, прямоугольник */

#include <iostream>
#include <vector>
#include <cmath>
#include "figure.hpp"
#include "vector.hpp"

bool checkR(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
    Vector l1, l2, l3, l4, l5, l6;
    l1.setup(x1, y1, x2, y2);   //AB
    l2.setup(x2, y2, x3, y3);   //BC
    l3.setup(x4, y4, x3, y3);   //CD
    l4.setup(x1, y1, x4, y4);   //AD
    if(l1.perpendicular(l2) && l1.perpendicular(l4) && l2.perpendicular(l3) && l3.perpendicular(l4)){   //rectangle
        return true;
    }else{
        return false;
    }
}

bool checkS(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
    Vector l1, l2, l3, l4, l5, l6;
    l1.setup(x1, y1, x2, y2);   //AB
    l2.setup(x2, y2, x3, y3);   //BC
    l3.setup(x4, y4, x3, y3);   //CD
    l4.setup(x1, y1, x4, y4);   //AD
    if(l1.perpendicular(l2) && l1.perpendicular(l4) && l2.perpendicular(l3) && l3.perpendicular(l4)){
    	if(l1.length == l2.length && l2.length == l3.length){
    		return true;
    	} else {
    		return false;
    	}
    }
}

bool checkT(double x1, double y1, double x2, double y2, double x3, double y3){
	Vector l1, l2, l3;
	l1.setup(x1, y1, x2, y2);
	l2.setup(x2, y2, x3, y3);
	l3.setup(x1, y1, x3, y3);
	//std::cout<<"l1 = " << l1.length << " l2 = " << l2.length << " l3 = " << l3.length << std::endl;
	if(l1.length + l2.length <= l3.length || l1.length + l3.length <= l2.length || l2.length + l3.length <= l1.length){
		return false;
	} else{
		return true;
	}
}

void printMenu(){
	std::cout << "Доступные команды:" << std::endl;
	std::cout << "0. Выход" << std::endl;
	std::cout << "1. Добавить треугольник" << std::endl;
	std::cout << "2. Добавить квадрат" << std::endl;
	std::cout << "3. Добавить прямоугольник" << std::endl;
	std::cout << "4. Узнать информацию о фигуре" << std::endl;
	std::cout << "5. Удалить фигуру по индексу" << std::endl;
	std::cout << "6. Узнать количество фигур"<<std::endl;
	std::cout << "7. Узнать общую площадь фигур" << std::endl;
}

int main(){
	setlocale(LC_ALL,"RUS");
	printMenu();
	std::vector<Figure*> v;
	double a, b, c, d, e, f, g, h;
	double S, p;
	short action;
	std::cout <<"Выберите необходимое действие: ";
	while(std::cin >> action){
		switch(action){

			case 1:
				std::cout << "Введите координаты точек для треугольника" << std::endl;
			    std::cout << "A: ";
			    std::cin >> a >> b;
			    std::cout << "B: ";
			    std::cin >> c >> d;
			    std::cout << "C: ";
			    std::cin >> e >> f;
			    if(checkT(a, b, c, d, e, f)){
			    	v.push_back(new Triangle(a, b, c, d, e, f));
			    	std::cout<< "Фигура добавлена" << std::endl;
			    } else{
			    std::cout<< "Невозможно задать треугольник с такими координатами" << std::endl;
			    }
			    break;

			case 2:
			    std::cout << "Введите координаты точек для квадрата" << std::endl;
			    std::cout << "A: ";
			    std::cin >> a >> b;
			    std::cout << "B: ";
			    std::cin >> c >> d;
			    std::cout << "C: ";
			    std::cin >> e >> f;
			    std::cout << "D: ";
			    std::cin >> g >> h;
			    if(checkS(a, b, c, d, e, f, g, h)){
			    	v.push_back(new Square(a, b, c, d, e, f, g, h));
			    	std::cout<< "Фигура добавлена" << std::endl;
			    } else{
			    std::cout<< "Ошибка! Проверьте корректность введенных координат" << std::endl;
			    }
			    break;

			case 3:
				std::cout << "Введите координаты точек для прямоугольника" << std::endl;
			    std::cout << "A: ";
			    std::cin >> a >> b;
			    std::cout << "B: ";
			    std::cin >> c >> d;
			    std::cout << "C: ";
			    std::cin >> e >> f;
			    std::cout << "D: ";
			    std::cin >> g >> h;
			    if(checkR(a, b, c, d, e, f, g, h)){
			    	v.push_back(new Rectangle(a, b, c, d, e, f, g, h));
			    	std::cout<< "Фигура добавлена" << std::endl;

			    } else{
			    std::cout<< "Ошибка! Проверьте корректность введенных координат" << std::endl;
			    }
			    break;

	        case 4:{
	        	int i = 0;
	        	std::cout << "Введите номер фигуры: ";
                std::cin >> i;
                if(i > v.size() && i >= 0){
                    std::cout << "There are " << v.size() << " figures" << std::endl;
                    std::cout << "Try again!" << std::endl;
                    break;
                }
                v[i-1]->type();
                v[i-1]->printPoints();
               	v[i-1]->printCenter();
               	v[i-1]->printArea();
                break;
	        }


            case 5:{
	            int idx;
	            std::cout << "Введите номер удаляемой фигуры: ";
	            std::cin >> idx;
	            --idx;
	            if (idx < 0 || idx >= v.size()) {
	                std::cout << "Нет фигуры по заданному номеру\n";
	                continue;
	            }
	            std::cout << "Удалено!" << std::endl;
	            delete v[idx];
	            v.erase(v.begin() + idx);
	        	}
	        	break;

	        case 6:
	        	 std::cout << "Количество фигур: " << v.size() << "\n";
	        	 for(int i = 0; i < v.size(); ++i){
	        	 	v[i]->type();
	        	 }
                break;

			case 7:
				if(v.size() == 0){
                    std::cout << "Общая площадь S = 0" << std::endl;
                    break;
                } else{
                    double S = 0;
                    for(int i = 0; i < v.size(); ++i){
                        S += v[i]->S;
                    }
                    std::cout << "Общая площадь S = " << S << std::endl;
                }
                break;

	        case 0:
	        	for (Figure* ptr : v) {
       			 delete ptr;
    			}
				v.clear();
				return 0;

			default:
				std:: cout << "Невозможное действие!" << std:: endl;
				printMenu();
				std:: cin >> action;
				std:: cout << "\n";
				break;
		}
		std::cout <<"Выберите необходимое действие: ";
	}

    return 0;

}