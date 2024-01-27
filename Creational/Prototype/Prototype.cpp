/******************************************************************************
copy constructor is intended to be used when knowing exact instance of the object, 
while prototype is used when there could be any possible implementation of some interface 
and you just want to obtain new object of exactly the same implementation, 
without resorting to some weird casting and checking methods.

---In the below example, we can not copy the cow in Animal object, and to achieve this 
we have to do weird casting, that can be avoided using prototype pattern
*******************************************************************************/
#include <iostream>
using namespace std;

class Animal
{
protected:
    int height, weight, age;
    int stubberness;
public:
    void setHeight(int height){ this->height = height; }
    void setWeight(int weight){ this->weight = weight; }
    void setAge(int age){ this->age = age; }
    void setStubberness(int stubberness){ this->stubberness = stubberness; }
    virtual int getAge() =0;
    virtual Animal* clone() = 0;
};

class Sheep : public Animal
{
    int horn;
public:
    Sheep( int h, int w, int age, int st, int horn) : horn(horn){
         height= h;
         weight=w,
         this->age= age;
         stubberness= st;
    }
    int getAge(){ return age;}
    Animal* clone() override
    {
        return new Sheep(*this);
    }
};

class Cow : public Animal
{
    int calmness;
public:
    Cow( int h, int w, int age, int st, int calmness) : calmness(calmness)
    {
        height= h;
        weight=w,
        this->age= age;
        stubberness= st;
    }
    int getAge(){ return age;}
    int getCalmness(){ return calmness;}
    Animal* clone() override
    {
        return new Cow(*this);
    }
};
int main()
{
    Animal *a;
    Sheep s(10,30,5,10,2);
    Cow c(20,100,20,0,50);
    
    cout << "Sheep age:"<< s.getAge()<<endl;
    cout << "cow age:"<< c.getAge()<<endl;
    
    Cow c2 = c;
    cout << "cow2 age:"<< c2.getAge()<<endl;
    cout << "cow2 calmness:"<< c2.getCalmness()<<endl;
    
    
    int ch;
    cin >> ch;
    switch(ch)
    {
       case 1:
            a= new Sheep(10,30,5,10,2);
            break;
        case 2:
            a = new Cow(1,3,51,110,21);
            break;
            
    }
    /*! a is object of abstract class so it can not make it's normal object and use copy constructor */
    //Cow *c3 = reinterpret_cast<Cow*>(a);

    /*! Here clone method has given another copy of object which is created, so the purpose of creating copy and do slight modification in that suffice */
    Animal *c3 = a->clone();

    /*! With following we are just creating another reference pointing to same memory address, not making copy*/
    //Animal *c3 = a;
    
    cout <<"c3:"<< c3->getAge();
    
    cout <<"sachin";
    return 0;
}