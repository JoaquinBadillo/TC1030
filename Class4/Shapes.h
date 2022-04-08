//
//  Shapes.h
//  Clase 8 de Abril
//
//  Created by Jesus Llano García on 08/04/22.
//

#ifndef Shapes_h
#define Shapes_h

#include <string>

class Shape{
private:
    int x;
    int y;
    
public:
    Shape(){
        x = 0;
        y = 0;
    }
    
    Shape(int ValX, int ValY){
        x = ValX;
        y = ValY;
    }
    
    virtual std::string draw(){
        return "Soy una Figura";
    }
    
    int getValueX(){
        return x;
    }
    int getValueY(){
        return y;
    }
};

class Circle : public Shape {
    
    private:
        int r;
    
    public:
        Circle(){
            r = 0;
        }
        Circle(int ValX, int ValY, int ValR) : Shape(ValX, ValY){
            r = ValR;
        }
    
        int getValueR(){
            return r;
        }

        std::string draw(){
            return "Soy un Círculo";
        }
};

class Triangle : public Shape {
    
    private:
        int base;
        int height;
        std::string type;
    
    public:
        Triangle(){
            base = 1;
            height = 1;
            type = "Right-angled";
        }

        Triangle(int ValX, int ValY, int ValBase, int ValHeight, std::string ValType) : Shape(ValX, ValY){
            base = ValBase;
            height = ValHeight;
            type = ValType;
        }
    
        int getSide(){
            return base;
        }

        int getHeight(){
            return height;
        }

        std::string getType(){
            return type;
        }

        std::string draw(){
            return "Soy un Triángulo";
        }
};

class Rectangle : public Shape {
    
    private:
        int width;
        int height;
    
    public:
        Rectangle(){
            width = 1;
            height = 1;
        }

        Rectangle(int ValX, int ValY, int ValWidth, int ValHeight) : Shape(ValX, ValY){
            width = ValWidth;
            height = ValHeight;
        }
    
        int getWidth(){
            return width;
        }

        int getHeight(){
            return height;
        }

        std::string draw(){
            return "Soy un Rectángulo";
        }
};

#endif
