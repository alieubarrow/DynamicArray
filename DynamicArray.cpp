//Header files
#include <iostream>
using namespace std;

//Function prototype 
int* copyData(int* dynamicArray, int* tempArray, int position);

int main() {

        //Variables
        int position = 0;
        int number;
        int length;
        int size = 5;
        int* dynamicArray = new int[size];
        int* tempArray = new int[size];

        cout << "Enter integer numbers to store (Stop by entering any non-numeric value): " << endl;

        //Loop through numbers and end reading a number when user enters a non-numeric value
        while (cin >> number) {

                //Add first number to current index of dynamicArray[] and then increment counter
                dynamicArray[position++] = number;

                tempArray = new int[size++]; //Increase size of new array size capacity 
                tempArray = copyData(dynamicArray, tempArray, position); //Copy values to new array using copyData() function        
                delete[] dynamicArray; //Deallocate the memory space
                dynamicArray = tempArray; //Reset pointer
        }

        length = position; //Take length of dynamicArray[]
        cout << "You entered " << length << " numbers " << endl;

        for (int j = 0; j < length; j++) {
                cout << dynamicArray[j] << " ";
        }

        delete[] dynamicArray; //Deallocate the memory space

        cout << endl;

        return 0;
}

//Copy data function copies numbers from dynamicArray[] to temporary array
int* copyData(int* dynamicArray, int* tempArray, int position) {

        int length = position; //Taek length of array
        for (int i = 0; i < length; i++) {
                tempArray[i] = dynamicArray[i]; //Copy from dynamiArray to tempArray[]
        }
        return tempArray; //Return newly copied array
}
