#ifndef PolarPoint_h
#define PolarPoint_h

class PolarPoint
{
    private:
        double r, theta;

    public:
        PolarPoint();
        PolarPoint(double, double);

        double getR();
        double getTheta();

        PolarPoint multiply(const PolarPoint&);
        PolarPoint operator*(const PolarPoint&);

        PolarPoint divide(const PolarPoint&);
        PolarPoint operator/(const PolarPoint&);
};

PolarPoint::PolarPoint()
{
    r = 0;
    theta = 0;  
}

PolarPoint::PolarPoint(double r_, double theta_)
{
    r = r_;
    theta = theta_;
}

double PolarPoint::getR()
{
    return r;
}

double PolarPoint::getTheta()
{
    return theta;
}

PolarPoint PolarPoint::multiply(const PolarPoint& p2)
{
    double r3 = (this -> r) * p2.r;
    double theta3 = (this -> theta) + p2.theta;

    PolarPoint temp(r3, theta3);

    return temp;
}

PolarPoint PolarPoint::operator*(const PolarPoint& p2)
{
   return (*this).multiply(p2);
}

PolarPoint PolarPoint::divide(const PolarPoint& p2)
{
    double r3 = (this -> r) / p2.r;
    double theta3 = (this -> theta) - p2.theta;

    PolarPoint temp(r3, theta3);

    return temp;
}

PolarPoint PolarPoint::operator/(const PolarPoint& p2)
{
   return (*this).divide(p2);
}

#endif