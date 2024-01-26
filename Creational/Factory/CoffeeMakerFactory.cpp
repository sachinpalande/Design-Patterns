// 03_02_FactoryImp_Start.cpp 
//
#include <iostream>
#include <cstring>

using namespace std;

// Product from which the concrete products will inherit from 
class Coffee
{
protected:
	char _type[15];
public:
	Coffee()
	{
	}
	char *getType()
	{
		return _type;
	}
};

// One concrete class
class Espresso : public Coffee
{
public:
	Espresso()
	{
		strcpy(_type, "Espresso");
		cout << endl << "Making a cup of espresso" << endl;
		cout << "Grind and brew one scoop of espresso beans." << endl;
	}
};

// Another concrete class
class Cappuccino : public Coffee
{
public:
	Cappuccino()
	{
		strcpy(_type, "Cappuccino");
		cout << endl << "Making a cup of cappuccino" << endl;
		cout << "Grind and brew one scoop of espresso beans." << endl;
		cout << "Heat and foam milk." << endl;
	}
};

class CoffeeMakerFactory
{
    public:
    virtual Coffee *getCoffee() = 0;
};

class EspressoFactory : public CoffeeMakerFactory
{
public:
    Coffee *getCoffee() override
    {
        return new Espresso;
    }
};

class CappuccinoFactory : public CoffeeMakerFactory
{
public:
    Coffee *getCoffee() override
    {
        return new Cappuccino;
    }
};

int main()
{
    CoffeeMakerFactory *coffeeMaker1 = new EspressoFactory;
    CoffeeMakerFactory *coffeeMaker2 = new CappuccinoFactory;
    
    Coffee *cup;
    cup = coffeeMaker1->getCoffee();
    
    cup = coffeeMaker2->getCoffee();
}