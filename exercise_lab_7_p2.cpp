/* File: exercise_lab_7_2.cpp
   Name: Stephen Gallagher
*/
#include <iostream>
using namespace std;

void sort(int array[], int N); //uses bubble sort to sort a given array
void swap(int &x, int &y); //swaps values
void printArray(int *elements, int N);

int main(int argc, const char * argv[]) {
    
    cout << "Please enter size of array:\n";
    int size;
    cin >> size;
    
    int *elements = new int[size]; //dynamic memory allocation
    
    for(int i = 0; i < size; i++)
        elements[i] = rand() % 1000 + 1; //fills array with random numbers between 1 and 1000
    
    
    //printing original, unsorted array
    cout << "Original array:\n";
    printArray(elements, size);
    
    //sorting
    sort(elements, size);
    cout << "\nprinting sorted array\n";
    
    //printing sorted array
    printArray(elements, size);
    
    //freeing memory
    delete [] elements;
}
//bubble sort algorithm used
void sort(int array[], int N){
    
    for(int i = 1; i < N; i++){
        bool sorted = true; //sorted is set to true, but is changed if the loop has to swap any value
        for(int j = 0; j < N - i; j++){
            if(array[j] > array[j + 1]){ //compares element with element ahead of it, swaps if first element is greater
                swap(array[j], array[j + 1]);
                sorted = false; //sets sorted to false, more sorting needs to be done
            }
        }
        //once the loop executes without having to swap, the array is fully sorted
        if(sorted)
            break;
    }
}
//swaps values
void swap(int &x, int &y){
    int temp = y;
    y = x;
    x = temp;
}
//prints all values in an array
void printArray(int *elements, int N){
    cout << "\n";
    for(int i = 0; i < N; i++){
        cout << elements[i] << "\n";
    }
}
