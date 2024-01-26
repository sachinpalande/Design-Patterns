/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <mutex>
#include <string_view>
#include <thread>
using namespace std;

class SingleTon;

SingleTon *s1;
mutex myMutex;
int counter=0;
pthread_t tid[2]; 

class SingleTon
{
  private:
  int x;
  static SingleTon* s1;
  
  SingleTon(){};
  
  SingleTon(const SingleTon &obj) = delete;
  
  public:
  
  static SingleTon *getSingletonInstance()
  {
      
        lock_guard<mutex> guard(myMutex);
        
        if(s1 == nullptr)
        {
            s1 = new SingleTon;
        }
        return s1;
  }
  
  int getSingletonInstanceobj()
  {
      return x;
  }
  
  void setSingleTonInstance(int x)
  {
      this->x =x;
  }
};

SingleTon* SingleTon::s1 = nullptr;
void* trythis(void* arg) 
{ 
    unsigned long i = 0; 
    counter += 1; 
    printf("\n Job %d has started\n", counter); 
    
    //s1 = SingleTon::getSingletonInstance();
    
    
    for (i = 0; i < 5000; i++)
    {
        if( i % 2 == 0 )
        {
             s1 = SingleTon::getSingletonInstance();
        }
    }
    
    printf("\n Job %d has finished\n", counter); 
  
    return NULL; 
} 
int main()
{
    int i = 0; 
    int error; 
  
    while (i < 2) { 
        error = pthread_create(&(tid[i]), NULL, &trythis, NULL); 
        if (error != 0) 
            printf("\nThread can't be created : []"); 
        i++; 
    } 
    // SingleTon *S1= SingleTon::getSingletonInstance();
    // S1->setSingleTonInstance(5);
    pthread_join(tid[0], NULL); 
    pthread_join(tid[1], NULL); 

    return 0;
}