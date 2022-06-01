class Shape
{
    public:
        virtual float area() = 0;
        virtual float perimeter() = 0;
};


class Rectangle: public Shape
{
    private:
        float base;
        float height;
    
    public:
        Rectangle()
        {
            base = 1;
            height = 1;
        }

        Rectangle(float base_, float height_)
        {
            base = base_;
            height = height_;
        }

        float area()
        {
            return base * height;
        }

        float perimeter()
        {
            return 2 * base + 2 * height;
        }
};

class Circle: public Shape
{
    private:
        float radius;
    
    public:

        Circle()
        {
            radius = 1;
        }

        Circle(float radius_)
        {
            radius = radius_;
        }

        float area()
        {
            return 3.14159265 * radius * radius;
        }

        float perimeter()
        {
            return 2 * 3.14159265 * radius;
        }
};
