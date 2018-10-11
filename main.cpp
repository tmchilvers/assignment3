#include <iostream>
#include <string>
#include <fstream>
#include "InFile.h"
#include "GenStack.h"

using namespace std;

int main(int argc, char* argv[]) // take in two arguments
{
  GenStack<char> checkCurly;
  GenStack<char> checkParenthesis;
  GenStack<char> checkBracket;
  InFile inFile(argv[1]);

  ifstream& myFile = inFile.getFile();

  int error = 0;
  char ans = ' ';
  string line;
  int count = 0;
  do {

    while(getline(myFile, line))
    {
      count++;
      for(int i = 0; i < line.size(); i++)
      {
        if(line[i] == '{')
        {
          checkCurly.push('{');
        }
        else if(line[i] == '}')
        {
          try
          {
            checkCurly.pop();
          }
          catch(int e)
          {
            cout << "\nError Number: " << e << endl;
            cout << "Line: " << count << " Found '}'. Expected '{' before." << endl;
            error++;
          }
        }

        if(line[i] == '(')
        {
          checkParenthesis.push('(');
        }
        else if(line[i] == ')')
        {
          try
          {
            checkParenthesis.pop();
          }
          catch(int e)
          {
            cout << "\nError Number: " << e << endl;
            cout << "Line: " << count << " Found ')'. Expected '(' before." << endl;
            error++;
          }
        }

        if(line[i] == '[')
        {
          checkBracket.push('[');
        }
        else if(line[i] == ']')
        {
          try
          {
            checkBracket.pop();
          }
          catch(int e)
          {
            cout << "\nError Number: " << e << endl;
            cout << "Line: " << count << " Found ']'. Expected '[' before." << endl;
            error++;
          }
        }

      }
    }
    if(!checkCurly.isEmpty())
    {
      int countCurly = 0;
      while(!checkCurly.isEmpty())
      {
        countCurly++;

        char peek;
        peek = checkCurly.peek();
        cout << peek << endl;

        checkCurly.pop();
      }
      cout << "\nReached end of file. Missing " << countCurly << " '}'" << endl;
      break;
    }

    else if(!checkBracket.isEmpty())
    {
      int countBracket = 0;
      while(!checkBracket.isEmpty())
      {
        countBracket++;
        checkBracket.pop();
      }
      cout << "\nReached end of file. Missing " << countBracket << " ']'" << endl;
      break;
    }

    else if(!checkParenthesis.isEmpty())
    {
      int countParenthesis = 0;
      while(!checkParenthesis.isEmpty())
      {
        countParenthesis++;
        checkParenthesis.pop();
      }
      cout << "\nReached end of file. Missing " << countParenthesis << " ')'" << endl;
      break;
    }

    else if( error == 0)
    {
      cout << "\nNo delimiter errors." << endl;
      cout << "\n\nRun another file 'y' or 'n'?: ";
      cin >> ans;
    }


  } while(ans == 'y');

  cout << "\nProgram end." << endl;

  return 0;
}
