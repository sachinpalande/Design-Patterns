/*
    solves the problem of creating product objects without specifying their concrete classes.
*/
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
    Coffee *getCoffee()
    {
        int choice;
        cin >> choice;
        switch(choice)
        {
            case 1:
                return new Espresso;
            case 2 :
                return new Cappuccino;
            default:
                return nullptr;
        }
    }
};

int main()
{
    CoffeeMakerFactory *coffeeMakerFactory;
    Coffee *cup;
    cup = coffeeMakerFactory->getCoffee();
}