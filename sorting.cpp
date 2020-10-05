#include "sorting.h"
#include <iostream>
#include <cstdlib>


int sorting::MinIndex(int values[], int start, int end)
{
  int indexOfMin = start;
  for(int index = start +1; index <= end; index++)
    {
      if(values[ index] < values [indexOfMin])
	indexOfMin = index ;
      comp++;
    }
  return indexOfMin;
}
void sorting::Swap(int *one, int *two)
{
  int temp = *one;
  *one = *two;
  *two = temp;
}

void sorting::SelectionSort(int values[], int numValues )
{
  int endIndex = numValues -1;
  for (int current = 0; current < endIndex; current++)
  {
    Swap(&values[current], &values[MinIndex(values, current, endIndex)]);
  }
}

void sorting::Merge(int values[], int leftFirst, int leftLast,int rightFirst, int rightLast)
{
  int tempArray[10000];
  int index = leftFirst;
  int saveFirst = leftFirst;
  while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
      if (values[leftFirst] < values[rightFirst])
	{
	  tempArray[index] = values[leftFirst];
	  leftFirst++;
	}
      else
	{
	  tempArray[index] = values[rightFirst];
	  rightFirst++;
	}
      index++;
      comp++;
    }
  while (leftFirst <= leftLast)
    {
      tempArray[index] = values[leftFirst];
      leftFirst++;
      index++;
     }
  while(rightFirst <= rightLast)
    {
      tempArray[index] = values[rightFirst];
      rightFirst++;
      index++;
     }
  for(index = saveFirst; index <= rightLast; index++)
    {
      values[index] = tempArray[index];
    }
}

void sorting::MergeSort(int values[], int first, int last)
{
  if(first < last)
    {
      int middle = (first + last) / 2;
      MergeSort (values, first, middle);
      MergeSort (values, middle + 1, last);
      Merge(values, first, middle, middle + 1, last);
    }
}

void sorting::Split(int values[], int first, int last, int & splitPoint)
{
  int splitVal = values[first];
  int saveFirst = first;
  bool onCorrectSide;
  first++;
  do
    {
       onCorrectSide = true;
      while (onCorrectSide)
	{
	  comp++;
	  if (values[first] > splitVal)
	    {
	      onCorrectSide = false;
	    }
	  else
	    {
	      first++;
	      onCorrectSide = (first <= last);
	    }
	}
      onCorrectSide = (first <= last);
      while (onCorrectSide)
	{
	  	      comp++;
	  if (values[last] <= splitVal)
	    {
	      onCorrectSide = false;
	    }
	  else
	    {
	      last--;
	      onCorrectSide = (first <= last);
	    } // else
	}
      if (first < last)
	{
	  Swap(&values[first], &values[last]);
	  first++;
	  last--;
	}
    } while (first <= last);
  splitPoint = last;
  Swap(&values[saveFirst], &values[splitPoint]);
}

void sorting::Split2(int values[], int first, int last, int & splitPoint)
{
  srand(time(NULL));
  int random = first + rand() % (last - first);
  Swap(&values[random], &values[first]);
  Split(values, first, last, splitPoint);
}

void sorting::QuickSort(int values[], int first, int last, bool ws)
{
  if(ws)
    {
      if( first < last)
	{
	  int splitPoint;
	  Split(values, first, last, splitPoint);
	  QuickSort(values, first, splitPoint-1, true);
	  QuickSort(values, splitPoint + 1, last, true);
	}
    } else if(!ws)
    {
      if( first < last)
	{
	  int splitPoint;
	  Split2(values, first, last, splitPoint);
	  QuickSort(values, first, splitPoint - 1, false);
	  QuickSort(values, splitPoint + 1, last, false);
	}
    }
}

void sorting::ReheapDown(int values[], int root, int bottom)
{
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root * 2 + 1;
  rightChild = root * 2 + 2;
  if(leftChild <= bottom)
    {
      comp++;
      if(leftChild == bottom)
	{
	  maxChild = leftChild;
	}
      else
	{
	  if(values[leftChild] <= values[rightChild])
	    maxChild = rightChild;
	  else
	    maxChild = leftChild;
	}
      if(values[root] < values[maxChild])
	{
	  Swap(&values[root], &values[maxChild]);
	  ReheapDown(values, maxChild, bottom);
	}
    }
}
 
void sorting::HeapSort( int values[], int numValues)
{
  int index;

  for(index = numValues/2; index >= 0; index--)
    {
      ReheapDown ( values, index, numValues - 1);
    }
  for(index = numValues - 1; index >= 1; index --)
    {
      Swap(&values[0], &values[index]);
      ReheapDown(values, 0, index-1);
    }
}

long sorting::returnComp()
{
  return comp;
}
  


