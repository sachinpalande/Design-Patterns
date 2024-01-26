/*
    When to use: Need only one object or instance at a time.
*/

#include <iostream>
using namespace std;

class Singleton
{
    static Singleton *instance;

    //Singleton(){}

    public:
    static Singleton *getInstance()
    {
        if(!instance)
        {
            instance = new Singleton;
        }
        return instance;
    }
};
Singleton* Singleton ::instance = nullptr;
int main()
{   
    Singleton *s = s->getInstance();
    return 0;
}