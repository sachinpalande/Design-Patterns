#include <iostream>
using namespace std;
class Chair
{
public:
  virtual void sit () = 0;
};

class ModernChair:public Chair
{
public:
  void sit ()
  {
    cout << "modern Chair sit" << endl;
  }
};

class VictorianChair:public Chair
{
public:
  void sit ()
  {
    cout << "Victorian Chair sit" << endl;
  }
};

class Sofa
{
public:
  virtual void sit () = 0;
};

class ModernSofa : public Sofa
{
public:
  void sit ()
  {
    cout << "modern Sofa sit" << endl;
  }
};

class VictorianSofa : public Sofa
{
public:
  void sit ()
  {
    cout << "Victorian Sofa sit" << endl;
  }
};

class FurnitureFactory
{
    public:
    virtual Chair* makeChair() = 0;
    virtual Sofa* makeSofa() = 0;
};

class ModernFurnitureFactory : public FurnitureFactory
{
    public:
    Chair* makeChair()
    {
        return new ModernChair;
    }
    Sofa* makeSofa()
    {
        return new ModernSofa;
    }
};
class VictorianFurnitureFactory : public FurnitureFactory
{
    public:
    Chair* makeChair()
    {
        return new VictorianChair;
    }
    Sofa* makeSofa()
    {
        return new VictorianSofa;
    }
};

int main ()
{
    FurnitureFactory *furnitureFactory;
    int ch;
    cin >> ch;
    switch (ch)
    {
        case 1: furnitureFactory = new ModernFurnitureFactory; break;
        case 2: furnitureFactory = new VictorianFurnitureFactory; break;
        default: furnitureFactory = nullptr; break;
    }
    if(furnitureFactory)
    {
        Chair *c = furnitureFactory->makeChair();
        Sofa *s = furnitureFactory->makeSofa();
        c-> sit();
        s->sit();
    }
}