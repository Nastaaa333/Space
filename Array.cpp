#include "array.h"
#include <iostream>

using namespace std;

Array::Array(int len) {
    if (len < 0) {
        length = 0;
        cout << "Incorrect length." << endl;

    }
    else {
        length = len;
        array = new number[length];
    }
}

void Array::fillArray() {
    for (int i = 0; i < length; i++) {
        cin >> *(array + i);
    }
}

Array::~Array() {
    delete[]array;
}

void Array::printArray() {
    cout << "The current array is " << endl;
    for (int i = 0; i < length; i++) {
        cout << *(array + i) << " ";
    }
    cout << endl;
}

void  Array::changeArraySize(int newLength) {
    if (newLength < 0) {
        cout << "Incorrect length." << endl;
    }

    else {
        number* newArray = new number[newLength];
        for (int i = 0; i < newLength; i++) {
            *(newArray + i) = *(array + i);
        }

        length = newLength;
        delete[]array;
        array = newArray;
    }
}

int Array::findLength() {
    return this->length;
}

void Array::quicksort(int end, int begin, bool reverse) {
    int pivotElement;
    if (reverse) {
        int start = begin;
        int finish = end;
        pivotElement = array[(start + finish) / 2];
        while (start < finish) {
            while (array[start] < pivotElement) start++;
            while (array[finish] > pivotElement) finish--;
            if (start <= finish) {
                std::swap(array[start], array[finish]);
                start++;
                finish--;
            }
        }
        if (begin < finish) quicksort(finish, begin, true);
        if (start < end) quicksort(end, start, true);
    }
    
    else {
        int start = begin;
        int finish = end;
        pivotElement = array[(start + finish) / 2];
        while (start < finish) {
            while (array[start] > pivotElement) start++;
            while (array[finish] < pivotElement) finish--;
            if (start <= finish) {
                std::swap(array[start], array[finish]);
                start++;
                finish--;
            }
        }
        if (begin < finish) quicksort(finish, begin, false);
        if (start < end) quicksort(end, start, false);
    }
}

void Array::changeElement(int index, number newElement) {
    if (index >= length && index <= 0) {
        cout << "Incorrect index";
    }

    else {
        *(array + index) = newElement;
    }
}

number Array::mean() {
    if (length == 0) {
        return 0;
    }

    else {
        number sum = 0;
        for (int i = 0; i < length; i++) {
            sum += *(array + i);
        }
        sum /= ((number)length);
        return sum;
    }
}

number Array::standardDeviation() {
    number meanValue = mean();
    number standardDeviationValue = 0;

    if (length == 0) {
        return 0;
    }

    else {
        for (int i = 0; i < length; i++) {
            standardDeviationValue += pow(*(array + i) - meanValue, 2);
        }

        standardDeviationValue /= ((number)length - 1);
        standardDeviationValue = pow(standardDeviationValue, 0.5);
        return standardDeviationValue;
    }
}
