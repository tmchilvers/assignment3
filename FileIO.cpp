#include "FileIO.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//constructors==================================================================
FileIO::FileIO()
{
  cerr << "Cannot open file. Please put a string object into the argument." << endl;
}

FileIO::FileIO(string filePath)
{
  try
  {
    inputFile.open(filePath);
    if(!inputFile.is_open())
    {
     throw invalid_argument("Second argument must be a readable file type and/or exist in directory.\n"); //exception for incorrect file type
    }
  }

  catch(const invalid_argument& e) //catch the exceptions here
  {
    cerr << e.what() << endl; //this will print out error message
    cerr << "Fatal error - Program exits\n";
    exit(1);
  }
}

FileIO::~FileIO()
{
  inputFile.close();
}

//auxiliary functions===========================================================
void FileIO::printFile()
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

bool FileIO::checkOpen()
{
  return inputFile.is_open();
}


ifstream& FileIO::getFile()
{
  return inputFile;
}
