#include <iostream>
#include <cstring>

using namespace std;

// Product from which the concrete products will inherit from 
class Transport
{
protected:
	char _type[15];
public:
	Transport()
	{
	}
	char *getType()
	{
		return _type;
	}
};

// One concrete class
class Road : public Transport
{
public:
	Road()
	{
		strcpy(_type, "Road");
		cout << endl << "Transporting by Road" << endl;
	}
};

// Another concrete class
class Sea : public Transport
{
public:
	Sea()
	{
		strcpy(_type, "Sea");
		cout << endl << "Transporting by Sea" << endl;
	}
};

class Air : public Transport
{
public:
	Air()
	{
		strcpy(_type, "Air");
		cout << endl << "Transporting by Air" << endl;
	}
};

class TransportTypeFactory
{
    private:
    Transport *transport;
    
    public:
    Transport *getTransport()
    {
        int choice;
        cin >> choice;
        switch(choice)
        {
            case 1:
                return new Road;
            case 2 :
                return new Sea;
            case 3 :
                return new Air;
            default:
                return nullptr;
        }
    }
};

int main()
{
    TransportTypeFactory *transportTypeFactory;
    Transport *t;
    t = transportTypeFactory->getTransport();
}