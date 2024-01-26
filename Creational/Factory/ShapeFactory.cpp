#include <iostream>
using namespace std;

class Shape
{
    public:
    virtual void myShape() = 0;
};

class Circle : public Shape
{
    public:
    void myShape()
    {
        cout <<"Circle"<<endl;
    }
};

class Rectange : public Shape
{
    public:
    void myShape()
    {
        cout <<"Rectange"<<endl;
    }
};

class ShapeFactory
{
    public:
    Shape *getShape( int ch)
    {
        switch(ch)
        {
            case 1: return new Circle;
            case 2: return new Rectange;
            default: return nullptr;
        }
    }
};

int main()
{
    ShapeFactory *shapeFactory;
    Shape *s  = shapeFactory->getShape(2);
    s->myShape();
}