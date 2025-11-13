#include "application.h"
#include "array.h"
#include <iostream>

using namespace std;

Application::Application() {

}

int Application::output() {
    int choice;
    int choiceLength;
    int sortLength;

    Array* array = new Array(0);

    while (true) {
        menu();
        int choice;
        cout << "Please, choose what you want to do: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Please, enter the length of the array" << endl;
            cin >> choiceLength;

            array = new Array(choiceLength);
            break;
        case 2:
            cout << "Please, enter " << choiceLength << " elements you want to add to the array" << endl;

            array->fillArray();
            break;
        case 3:
            cout << "The mean value equals " << array->mean() << endl;
            cout << "The standard deviation equals " << array->standardDeviation() << endl;
            break;
        case 4:
            cout << "The array was sorted in an ascending order. ";

            sortLength = array->findLength();
            array->quicksort(sortLength - 1, 0, true);
            array->printArray();

            cout << "The array was sorted in a descending order. ";

            sortLength = array->findLength();
            array->quicksort(sortLength - 1, 0, false);
            array->printArray();
            break;
        case 5:
            cout << "Please, enter the new size of the array" << endl;

            int newLength;
            cin >> newLength;

            array->changeArraySize(newLength);
            break;
        case 6:
            int index;
            number newElement;

            cout << "Please, enter an index of the element you want to change and a new element. (Note: the first number in an array has an index equal 0)" << endl;
            cin >> index;
            cin >> newElement;

            array->changeElement(index, newElement);
            break;
        case 7:
            array->printArray();
            break;
        case 8:
            return 0;
        default:
            cout << "There is no such option. Please, try again." << endl;
        }
    }
}

void Application::menu() {
    cout << "1 - Create an array with a certain length" << endl;
    cout << "2 - Add input numbers to the array" << endl;
    cout << "3 - Find a mean value and a standard deviation" << endl;
    cout << "4 - Sort an array in ascending and descending order" << endl;
    cout << "5 - Change array size" << endl;
    cout << "6 - Change selected element of the array" << endl;
    cout << "7 - Display the current array" << endl;
    cout << "8 - Exit" << endl;
}