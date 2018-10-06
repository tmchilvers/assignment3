#include <iostream>
#include <string>
#include <fstream>
#include "InFile.h"

using namespace std;

int main(int argc, char* argv[]) // take in two arguments
{
  InFile inFile(argv[1]);

  ifstream& myFile = inFile.getFile();

  string line;
  while(getline(myFile, line))
  {
    for(int i = 0; i < line.size(); i++)
    {
      if(line[i] == '\r')
      {
        cout << endl;
      }
      cout << line[i];
    }
    cout << endl;
  }

  return 0;
}
