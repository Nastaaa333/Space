#ifndef ARRAY_H
#define ARRAY_H

#include "number.h"

class Array
{
private:
    number* array;
    int length;
public:
    Array(int len = 0);
    void fillArray();
    ~Array();
    int findLength();
    void printArray();
    void quicksort(int end, int begin, bool reverse);
    void changeElement(int index, number newElement);
    void changeArraySize(int newLength);
    number mean();
    number standardDeviation();
};

#endif // ARRAY_H