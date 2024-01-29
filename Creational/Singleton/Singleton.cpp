/*
    When to use: Need only one object or instance at a time.

    Solution:
    Steps 1. Make constructor private & delete Copy constructor to avoid instanciation outside class.
          2. Make static instance and follow lazy initialization.
          3. To make it thread safe, can use Eager Initialization or use mutex.   
*/

#include <iostream>
using namespace std;

class Singleton
{
    static Singleton *instance;

    Singleton(){}
    Singleton( const Singleton& ) = delete;

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