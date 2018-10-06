#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>

using namespace std;

//template class======================================================================
template <class anyType>
class GenStack
{
  public:
    GenStack();
    GenStack(int maxSize);
    ~GenStack();

    void push(anyType);
    anyType pop();
    anyType peek();

    bool isFull();
    bool isEmpty();

    int size;
    int top;

    anyType *myArray;
};

//template functions==================================================================
//constructors/destructor=============================================================
template <class anyType>
GenStack<anyType>::GenStack()
{
  myArray = new anyType[10];
  size = 10;
  top = -1;
}

template <class anyType>
GenStack<anyType>::GenStack(int maxSize)
{
  myArray = new anytype[maxSize];
  size = maxSize;
  top = -1;
}

template <class anyType>
GenStack<anyType>::~GenStack()
{
  delete myArray;
  cout << "Stack destroyed" << endl;
}

//auxiliary functions=================================================================
template <class anyType>
void GenStack<anyType>::push(anyType x)
{
  if(GenStack<anyType>::isFull())
  {
    cerr << "Unable to push. Stack is full." << endl;
  }

  else
  {
    myArray[++top] = x;
  }
}

template <class anyType>
anyType GenStack<anyType>::pop()
{
  if(GenStack<anyType>::isEmpty())
  {
    cerr << "Unable to pop. Stack is empty." << endl;
  }

  else
  {
    return myArray[top--]
  }
}

template <class anyType>
anyType GenStack<anyType>::peek()
{
  if(GenStack<anyType>::isEmpty())
  {
    cerr << "Nothing to peek. Stack is empty." << endl;
  }

  else
  {
    return myArray[top];
  }
}

template <class anyType>
bool GenStack<anyType>::isFull()
{
  return (top == size - 1);
}

template <class anyType>
bool GenStack<anyType>isEmpty()
{
  return (top == -1);
}


#endif
