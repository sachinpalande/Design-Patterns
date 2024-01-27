#include <iostream>
using namespace std;

class Wheel
{
    public:
    void spin(){ cout << " spinning wheel"; }
    virtual Wheel* getWheel() = 0;
};

class OrdinaryWheel : public Wheel
{
    public:
    void spin(){ cout << " spinning wheel slow" <<endl; }
    Wheel* getWheel() { return new OrdinaryWheel; }
};

class LuxuryWheel : public Wheel
{
    public:
    void spin(){ cout << " spinning wheel Fast"<<endl; }
    Wheel* getWheel() { return new LuxuryWheel; }
};

class Door
{
    public:
    void open() { cout << "Opening Door"<<endl; }
    void close() { cout << "closing Door"<<endl; }
    Door* getDoor() { return new Door; }
};

class Engine
{
    public:
    void start() { cout << "starting engine"<<endl; }
    void stop() { cout << "stoping engine"<<endl; }
    virtual Engine* getEngine() = 0;
};

class ManualEngine : public Engine
{
    public:
    void start() { cout << "starting engine -- AHHH"<<endl; }
    void stop() { cout << "stoping engine -- DRUHH"<<endl; }
    Engine* getEngine(){ return new ManualEngine; }
};

class AutoEngine : public Engine
{
    public:
    void start() { cout << "starting engine -- BHRUHH"<<endl; }
    void stop() { cout << "stoping engine -- AMM"<<endl; }
    Engine* getEngine(){ return new AutoEngine; }
};

class Car
{
    Wheel *w;
    Door *d;
    Engine *e;
    const char *_carType;
    
    public:
    Car (const char* type) : _carType( type )
    {}
    void setWheel(Wheel *_w){ w = _w; }
    void setDoor(Door *_d){ d = _d; }
    void setEngine(Engine *_e){ e = _e; }
    void startCar()
    {
        cout << _carType;
    }
    
};

class CarBuilder
{
    protected:
        Car *c;
    public:
        virtual void setWheel() =0;
        virtual void setDoor() =0;
        virtual void setEngine() =0;
        Car *getCar()
        {
            return c;
        }
};

class OldCar : public CarBuilder
{
    public:
    OldCar()
    {
        c = new Car("Old");
    }
    void setEngine()
    {
        ManualEngine *me = new ManualEngine;
        c->setEngine( me);
    }
    void setDoor()
    {
        Door *d = new Door;
        c->setDoor( d);
    }
    void setWheel()
    {
        OrdinaryWheel *ow = new OrdinaryWheel;
        c->setWheel( ow);
    }
};

class NewCar : public CarBuilder
{
    public:
    NewCar()
    {
        c = new Car("New");
    }
    void setEngine()
    {
        AutoEngine *ae = new AutoEngine;
        c->setEngine( ae);
    }
    void setDoor()
    {
        Door *d = new Door;
        c->setDoor( d);
    }
    void setWheel()
    {
        LuxuryWheel *lw = new LuxuryWheel;
        c->setWheel( lw);
    }
};

class Director
{   
    CarBuilder *carBuilder;
    public:
    Director(CarBuilder *carBuilder) : carBuilder(carBuilder) {}
    Car* createCar()
    {
        carBuilder->setEngine();
        carBuilder->setDoor();
        carBuilder->setWheel();
        return carBuilder->getCar();
    }
};

int main()
{
    OldCar oldCar;
    NewCar newCar;
    Director d(&oldCar);
   
    Car *old = d.createCar();
    old->startCar();
       
    return 0;
}