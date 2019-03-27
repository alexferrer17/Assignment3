#include <iostream>
#include <fstream>
#include "GenStack.h"
#include <string>
using namespace std;


int main(int argc, char** argv) {

  while(true) { //this loop allows the user to correct different files until he wants to stop

    GenStack<char> stack = GenStack<char>();
    cout << "What is the name of the file you want to correct?" << '\n';
    string file = "";
    string str = "";

    cin >> file;

    fstream inputFile(file);
    if(inputFile.is_open())
    {
      while(getline(inputFile,str))
      {
        int lineNumber = 1;
        for(int i=0;i<str.length()-1;i++){

          if(str[i] == '{' || str[i] == '(' || str[i] == '[')
          {
            stack.push(str[i]);
          }
          else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
          {
            if(stack.isEmpty())
            {
              cout << "Error in line:" << lineNumber << " you are missing an open: " << str[i] << endl;
            }
            if(stack.peek() != str[i])
            {
              cout << "Error in line:" << lineNumber << "wrong type of sintax" << endl;
            }
            stack.pop();
          }
          if (stack.isEmpty())
          {
            cout << "No sintax errors" << endl;
          }
          else
          {
            cout << "Error in line:" << lineNumber << " you are missing a closing: " << str[i] << endl;
          }
        }
        lineNumber++;
      }
    }
    inputFile.close();

    cout << "Do you want to correct another file? (yes) or (no)" << '\n';
    string answear = "";
    cin >> answear;
    if(answear == "no")
    {
      break;
    }

  }

}
