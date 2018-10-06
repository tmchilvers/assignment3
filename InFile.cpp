#include "InFile.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//constructors==================================================================
InFile::InFile()
{
  cerr << "Cannot open file. Please put a string object into the argument." << endl;
}

InFile::InFile(string filePath)
{
  inputFile.open(filePath);
}

InFile::~InFile()
{
  inputFile.close();
}

//auxiliary functions===========================================================
void InFile::printFile()
{
  string line;
  while(getline(inputFile, line))
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
}

bool InFile::checkOpen()
{
  return inputFile.is_open();
}


ifstream& InFile::getFile()
{
  return inputFile;
}
