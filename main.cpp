#include <iostream>
#include <string>
#include <fstream>
#include "InFile.h"
#include "GenStack.h"

using namespace std;

int main(int argc, char* argv[]) // take in two arguments. Second one must be file
{

  char ans; //answer for running another file, if no errors are found.
  do {
    //Try catch error for proper command line argument
    try
    {
      if(argc < 2 || argc > 2) //The program takes two arguments: program name and text file name
      {
        throw invalid_argument("Two arguments are required. Second arg must be a file to check for delimiters.\n"); //exception for incorrect number of arguments
      }
    }

    catch(const invalid_argument& e) //catch the exceptions here
    {
      cerr << e.what() << endl; //this will print out error message
      cerr << "Fatal error - Program exits\n";
      exit(1);
    }

    //Create three stacks, one for each delimiter
    GenStack<char> checkCurly;
    GenStack<char> checkParenthesis;
    GenStack<char> checkBracket;

    InFile inFile(argv[1]);
    ifstream& myFile = inFile.getFile();

    int error = 0; //count number of errors
    string line; //the line being read in file
    int count = 0; //count for which line of the file is being read.
    int countChar = 0; //count number of char until next double quote is found

    while(getline(myFile, line))
    {
      count++; //increment for current line of file being read
      for(int i = 0; i < line.size(); i++) //iterate through each character of line
      {
        if(line[i] == '/' && line[i+1] == '/') //if a line comment is read, ignore what is after
        {
          break;
        }

        if(line[i] == '"') //ignore when checking within a string
        {
          for(int j = i; j < line.size(); j++)
          {
            if(line[j] == '"')
            {
              break;
            }
            countChar++;
          }

          i += countChar;
          continue;
        }

////////////////////////////////////////////////////////////////////////////////
        if(line[i] == '{') //if { store in stack
        {
          checkCurly.push('{');
        }
        else if(line[i] == '}') //if } pop corresponding { in stack
        {
          try
          {
            checkCurly.pop();
          }
          catch(int e) //if unable to pop, output error
          {
            cout << "\nError Number: " << e << endl;
            cout << "Line: " << count << " Found '}'. Expected '{' before." << endl;
            error++;
          }
        }

////////////////////////////////////////////////////////////////////////////////
        if(line[i] == '(') //if ( store in stack
        {
          checkParenthesis.push('(');
        }
        else if(line[i] == ')') //if ) pop corresponding ( in stack
        {
          try
          {
            checkParenthesis.pop();
          }
          catch(int e) //if unable to pop, output error
          {
            cout << "\nError Number: " << e << endl;
            cout << "Line: " << count << " Found ')'. Expected '(' before." << endl;
            error++;
          }
        }

////////////////////////////////////////////////////////////////////////////////
        if(line[i] == '[') //if [ store in stack
        {
          checkBracket.push('[');
        }
        else if(line[i] == ']') //if ] pop corresponding [ in stack
        {
          try
          {
            checkBracket.pop();
          }
          catch(int e) //if unable to pop, output error
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
      while(!checkCurly.isEmpty()) //count how many curlies were left in stack
      {
        countCurly++;
        checkCurly.pop();
      }
      cout << "\nReached end of file. Missing " << countCurly << " '}'" << endl;
      break;
    }

    else if(!checkBracket.isEmpty())
    {
      int countBracket = 0;
      while(!checkBracket.isEmpty()) //count how many brackets were left in stack
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
      while(!checkParenthesis.isEmpty()) //count how many parenthesis' were left in stack
      {
        countParenthesis++;
        checkParenthesis.pop();
      }
      cout << "\nReached end of file. Missing " << countParenthesis << " ')'" << endl;
      break;
    }

    else if( error == 0) //no errors found, allow user to run program again with a new file
    {
      cout << "\nNo delimiter errors." << endl;
      cout << "\n\nRun another file 'y' or 'n'?: ";
      cin >> ans;

        if(ans == 'y' || ans == 'Y') //if yes, set file to command argument
        {
          cout << "What is the name of the file?: ";
          cin >> argv[1];
        }

        else if(ans == 'n' || ans == 'N')
        {
          //pass
        }

        else //invalid character for ans
        {
          cerr << "Invalid input." << endl;
        }
    }

  } while(ans == 'y' || ans == 'Y');

  cout << "\nProgram end." << endl;

  return 0;
}
