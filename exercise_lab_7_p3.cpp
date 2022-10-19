/* File: exercise_lab_7_3.cpp
   Name: Stephen Gallagher
 */

#include <iostream>
using namespace std;

class Student{
    string students_name;
    int students_number;
    int N;
    int *results;
    
    public:
        Student(); //default constructor
        Student(string, int, int); //constructor
        ~Student(); //destructor
        bool pass(); //returns true if average result is above 40
        void printDetails(); //prints student details
};
//giving the student default values
Student::Student(){
    students_name = "default";
    students_number = 0;
    N = 0;
    results = NULL;
}
//takes in values, and assigns these values to the variables
Student::Student(string students_name, int students_number, int N){
    this -> students_name = students_name; //assigning object values
    this -> students_number = students_number;
    this -> N = N;
    
    results = new int[N]; //dynamic memory allocation
    
    for(int i = 0; i < N; i++){ //fills array with random values between 0 and 100
        int randInt = rand() % 100;
        results[i] = randInt;
    }
}
//destructor, frees memory used by results
Student::~Student(){
    delete [] results;
}
//returns true when average result is greater than 40
bool Student::pass(){
    int total = 0;
    bool passed = false; //false by default
    
    for(int i = 0; i < N; i++){ //adds up all values
        total += results[i];
    }
    if(N){ //ensures total is never divided by zero
        if((total / N) > 40)
            passed = true;
    }
    return passed;
}
//prints student details
void Student::printDetails(){
    cout << "\n\nStudent name: " << students_name << "\n";
    cout << "Student number: " << students_number << "\n";
    cout << "Student is registered for " << N << " modules\n";

    cout << "Results:\n"; //printing results line by line
    for(int i = 0; i < N; i++){
        cout << results[i] << "%\n";
    }
    
    cout << "Pass: " << (pass() ? "pass\n" : "fail\n"); //ternary operator used to print true or false
}
int main(int argc, const char * argv[]) {
    Student student1; //creating a default student object
    
    string name;
    int studentNo, modules;
    
    //taking user input for name, student number and number of modules
    cout << "Please enter name, student number and the number of modules the student does:\n";
    cin >> name >> studentNo >> modules;

    Student student2(name, studentNo, modules); //initialising with values
    
    cout << "Default Student object:\n";
    student1.printDetails();
    
    cout << "User created Student object:\n";
    student2.printDetails();
    
}
