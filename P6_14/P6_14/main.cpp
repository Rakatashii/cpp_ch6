/*
 Define a class
 class Staff
 {
 public:
 ... private:
 vector<Employee> members;
 };
 and implement the find and raise_salary procedures for the Staff data type.
 */

#include <iostream>
#include <time.h>
#include <thread>
#include <chrono>
#include "staff.hpp"
#include <cstdlib>
#include "time.h"

using namespace std;

double fRand(double fMin, double fMax);

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    int i;
    vector<string> names = {"Jonny", "David", "Lora", "Kimmmy", "Mike", "Donald", "Frank", "Charlie", "Kevin", "Sara"};
    Staff event("DenverTech");
    for(i = 0; i < 10; i++){
        double d1 = fRand(10000, 500000);
        int i1 = rand()%100+1, i2;
        do {
            i2 = rand()%100+1;
        } while (i1 < i2);
        event.add_employee(Employee(names[i], d1, i1, i2));
    }
    //Employee f = event.find_employee("Frank");
    //cout << "f.get_name() = " << f.get_name() << endl;
    //int f_index = event.find_index("Frank");
    //cout << "f_index = " << f_index << endl;
    
    event.print_members();
    cout << "\n";
    
    event.remove_employee(event.find_index("Frank"));
    event.print_members();
    cout << "\n";
    
    event.remove_employee(event.find_index("Sara"));
    event.print_members();
    cout << "\n";
    
    cout << "\n";
    return 0;
}
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    //cout << "(double)rand() = " << (double)rand() << endl;
    //cout << "RAND_MAX = " << RAND_MAX << endl;
    //cout << "f = " << f << endl;
    return fMin + f * (fMax - fMin);
}
