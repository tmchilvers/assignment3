#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>

using namespace std;


//This is a generic Stack (of array) class that can be of any type. Note function:
//When the stack is full, the size will increase to twice the original size.
//For error check: Catch int '1' and '2', for pop error and peek error, respectfully.
//Implement the catch in class that makes use of GenStack
//template class======================================================================
template <class anyType>
class GenStack
{
  public:
    //constuctors
    GenStack(); //the default size is 10
    GenStack(int maxSize);
    ~GenStack();

    void push(anyType);
    void increaseSize(); //increase to twice the size
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
  myArray = new anyType[10]; //set new array to size of 10
  size = 10;
  top = -1; //set top to -1 since there is no content yet for it to be top of.
}

template <class anyType>
GenStack<anyType>::GenStack(int maxSize)
{
  myArray = new anyType[maxSize]; //set new array to inputted size
  size = maxSize;
  top = -1;
}

template <class anyType>
GenStack<anyType>::~GenStack()
{
  delete myArray; //garbage collector
}

//auxiliary functions=================================================================
template <class anyType>
void GenStack<anyType>::push(anyType x)
{
  if(GenStack<anyType>::isFull())
  {
    this->GenStack<anyType>::increaseSize(); //call increase size
    myArray[++top] = x; //set top to new pushed element
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
  anyType* newArray = new anyType[tempSize];

  for(int i = top; i >= 0; i--)
  {
    newStack.push(myArray[i]);
    newArray[i] = newStack.peek();
  }

  delete myArray;
  myArray = new anyType[size];

  for(int i = 0; i < tempSize; i++)
  {
    myArray[i] = newArray[i];
  }

  delete newArray;

}

template <class anyType>
anyType GenStack<anyType>::pop()
{
  if(GenStack<anyType>::isEmpty())
  {
    throw 1; //unable to pop error.
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
