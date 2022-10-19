/* File: exercise_lab_7_1.cpp
   Name: Stephen Gallagher
 */

#include <iostream>
using namespace std;

void printArray(int *elements, int size); //prints array
void reverseArray(int *elements, int size); //prints array in reverse
int returnSumofSquares(int *elements, int size); //adds together the squares of every value

int main(int argc, const char * argv[]) {
    //asking for user input
    cout << "Please enter size of array:\n";
    int length;
    cin >> length;
    
    int *elements = new int[length]; //dynamic memory allocation
    
    *(elements) = 0; //initialising first two values
    if(length > 1) //ensures there is more than one value
        elements[1] = 1;
    
    
    //loop starts after first two values
    for(int i = 2; i < length; i++){
        /*looks at the value before i and the value before that value, and adds them.
         the next value in the array is set to this new value
        */
        int nextVal = elements[i - 1] + elements[i - 2];
        elements[i] = nextVal;
    }
    
    cout << "\noriginal sequence:\n";
    printArray(elements, length);
    
    cout << "\nreversed sequence:\n";
    reverseArray(elements, length);
    
    cout << "\nsum of squares:\n";
    cout << returnSumofSquares(elements, length) << "\n\n";
    
    //deleting dynamically allocated memory
    delete [] elements;
    
}
//prints all elements in an array
void printArray(int *elements, int size){
    
    for(int i = 0; i < size; i++){
        cout << elements[i] << "\n";
    }
}
//prints all elements in an array, starts at the end and works back
void reverseArray(int *elements, int size){
    
    for(int i = size - 1; i >= 0; i--){
        cout << elements[i] << "\n";
    }
}
int returnSumofSquares(int *elements, int size){
    int result = 0;
    
    for(int i = 0; i < size; i++){
        result += elements[i] * elements[i];
    }
    return result;
}
