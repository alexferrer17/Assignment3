#include <iostream>
#include <fstream>


using namespace std;
//Array based template of a General stack with a fixed size
template <class T> class GenStack {
private:
  int maxsize = 10; //max size
  int top;
  bool overflow; //checks upper boundry of the stack
  bool underflow; //checks upper boundry of the stack
  T stack[];

public:
  GenStack(){ //constructor
    top = -1;
    overflow = false;
    underflow = true;

  }

  ~GenStack(){
    //destructor
  }

  bool isEmpty(){ //checks if the stack is empty
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

  bool isFull(){ //checks if the stack is full
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

  void printStack(){ //returns stack
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

  void push(T value){ //inserts element to stack
    if(!isFull())
    {
      top++;
      stack[top] = value;
    }
  }

  T pop(){ //returns top element and deletes it
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

  T peek(){ //returns top element
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
