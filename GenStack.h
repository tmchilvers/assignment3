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
    void increaseSize();
    anyType pop();
    anyType peek();

    bool isFull();
    bool isEmpty();

    int getSize();
    int getTop();

  private:
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
  myArray = new anyType[maxSize];
  size = maxSize;
  top = -1;
}

template <class anyType>
GenStack<anyType>::~GenStack()
{
  delete myArray;
}

//auxiliary functions=================================================================
template <class anyType>
void GenStack<anyType>::push(anyType x)
{
  if(GenStack<anyType>::isFull())
  {
    this->GenStack<anyType>::increaseSize();
    myArray[++top] = x;
  }

  else
  {
    myArray[++top] = x;
  }
}

template <class anyType>
void GenStack<anyType>::increaseSize()
{
  int tempSize = size * 2;

  GenStack<anyType> newStack(tempSize);

  while(!this->isEmpty())
  {
    newStack.push(this->pop());
  }

  size = tempSize;
  delete myArray;
  myArray = new anyType[size];

  while(!newStack.isEmpty())
  {
    this->push(newStack.pop());
  }
}

template <class anyType>
anyType GenStack<anyType>::pop()
{
  if(GenStack<anyType>::isEmpty())
  {
    throw 1; //unable to pop error
  }

  else
  {
    return myArray[top--];
  }
}

template <class anyType>
anyType GenStack<anyType>::peek()
{
  if(GenStack<anyType>::isEmpty())
  {
    throw 2; //unable to peek error
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
bool GenStack<anyType>::isEmpty()
{
  return (top == -1);
}

template <class anyType>
int GenStack<anyType>::getSize()
{
  return size;
}

template <class anyType>
int GenStack<anyType>::getTop()
{
  return top;
}

#endif
