#ifndef InFile_H
#define InFile_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;


//This class can read in a file and process the characters on each line.
//Must declare name of file as a string. Create the InFile object and put the name
//into the constructor argument
class InFile
{
  public:
    //constructors
    InFile();
    InFile(string filePath);
    ~InFile();

    //auxiliary functions
    void printFile();
    bool checkOpen();

    ifstream& getFile();

  private:
    ifstream inputFile;
};

#endif
