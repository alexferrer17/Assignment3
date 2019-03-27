#include <iostream>
#include <fstream>


using namespace std;
//Array based template of a General stack with a fixed size
template <class T> class GenStack {
private:
  int maxsize = 10; //max size
  int top;
  bool overflow;
  bool underflow;
  T stack[];

public:
  GenStack(){ //
    top = -1;
    overflow = false;
    underflow = true;

  }

  ~GenStack(){
    //destructor
  }

  bool isEmpty(){
    if(top<0)
    {
      underflow = true;
    }
    else
    {
      underflow = false;
    }
    return underflow;
  }

  bool isFull(){
    if(top >= (maxsize-1))
    {
      overflow = true;
    }
    else
    {
      overflow = false;
    }
    return overflow;
  }

  void printStack(){
    if(!isEmpty())
    {
      for(int i=top;i>=0;i--)
      {
        if(i>0)
        {
          cout<<stack[i]<<",";
        }
        else
        {
          cout<<stack[i];
        }
      }
    }
  }

  void push(T value){
    if(!isFull())
    {
      top++;
      stack[top] = value;
    }
  }

  T pop(){
    T temp;
    if(!isEmpty())
    {
      temp = stack[top];
      top--;
      return temp;
    }
    else
    {
      throw "It's empty";
    }
  }

  T peek(){
    T temp;
    if(!isEmpty())
    {
      temp = stack[top];
      return temp;
    }
    else
    {
      throw "It's empty";
    }
  }

};
