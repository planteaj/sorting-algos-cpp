#ifndef SORTING_H
#define SORTING_H

class sorting
{
 public:
  int MinIndex(int values [], int start, int end);
  void Swap(int * one, int * two);
  void SelectionSort(int values [], int numValues);
  void Merge(int values [], int leftFirst, int leftLast, int rightFirst, int rightLast);
  void MergeSort(int values [], int first, int last);
  void Split(int values [], int first, int last, int & splitPoint);
  void Split2(int values [], int first, int last, int & splitPoint);
  void QuickSort(int values [], int first, int last, bool ws);
  void ReheapDown(int values [], int root, int bottom);
  void HeapSort(int values[], int numValues);
  long returnComp();
 private:
  long comp;
  
};

#endif
