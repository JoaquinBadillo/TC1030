#ifndef CartesianPoint_h
#define CartesianPoint_h

class CartesianPoint
{
    private:
        double x, y;

    public:
        CartesianPoint();
        CartesianPoint(double, double);

        double getX();
        double getY();

        CartesianPoint add(const CartesianPoint&);
        CartesianPoint operator+(const CartesianPoint&);
        
        CartesianPoint subtract(const CartesianPoint&);
        CartesianPoint operator-(const CartesianPoint&);

        CartesianPoint operator-();
};

CartesianPoint::CartesianPoint()
{
    x = 0;
    y = 0;  
}

CartesianPoint::CartesianPoint(double x_, double y_)
{
    x = x_;
    y = y_;
}

double CartesianPoint::getX()
{
    return x;
}

double CartesianPoint::getY()
{
    return y;
}

CartesianPoint CartesianPoint::add(const CartesianPoint& p2)
{
    double x3 = (this -> x) + p2.x;
    double y3 = (this -> y) + p2.y;

    CartesianPoint temp(x3, y3);

    return temp;
}

CartesianPoint CartesianPoint::operator+(const CartesianPoint& p2)
{
   return (*this).add(p2);
}

CartesianPoint CartesianPoint::subtract(const CartesianPoint& p2)
{
    double x3 = (this -> x) - p2.x;
    double y3 = (this -> y) - p2.y;

    CartesianPoint temp(x3, y3);

    return temp;
}

CartesianPoint CartesianPoint::operator-(const CartesianPoint& p2)
{
    return (*this).subtract(p2);
}

CartesianPoint CartesianPoint::operator-()
{
    double x2 = -(this -> x);
    double y2 = -(this -> y);

    CartesianPoint temp(x2, y2);

    return temp;
}

#endif