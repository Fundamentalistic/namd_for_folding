#include "elements.h"

class heapRecord
{ public:
  short deleted; // boolean
  InfoRecord *info;
};

class heapIterator{
public:
  int next;
};

class minHeap
{
private:
  heapRecord *h;
  int count;

  void swap(int i, int j) 
    {
      heapRecord temp = h[i];
      h[i] = h[j];
      h[j] = temp;
    }
  
public:
  minHeap(int size);
  int numElements();
  void insert(InfoRecord *);
  InfoRecord *deleteMin();
  InfoRecord *iterator(heapIterator *);
  InfoRecord *next(heapIterator *);
};

class maxHeap
{
private:
  heapRecord *h;
  int count;

  void swap(int i, int j) 
    {
      heapRecord temp = h[i];
      h[i] = h[j];
      h[j] = temp;
    }
  
public:  
  maxHeap(int size);
  int numElements();
  void insert(InfoRecord *);
  InfoRecord *deleteMax();
  InfoRecord *iterator(heapIterator *);
  InfoRecord *next(heapIterator *);
};

