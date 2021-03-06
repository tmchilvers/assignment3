#ifndef FileIO_H
#define FileIO_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;


//This class can read in a file and process the characters on each line.
//Must declare name of file as a string. Create the InFile object and put the name
//into the constructor argument
class FileIO
{
  public:
    //constructors
    FileIO(); //will output error stating that constructor must take a file path argument
    FileIO(string filePath);
    ~FileIO();

    //auxiliary functions
    void printFile();
    bool checkOpen();

    ifstream& getFile(); //reference allows ability to get the file stream

  private:
    ifstream inputFile;
};

#endif
