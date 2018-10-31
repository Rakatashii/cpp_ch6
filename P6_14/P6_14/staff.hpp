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


#ifndef staff_hpp
#define staff_hpp

#include <stdio.h>
#include <iostream>
#include "employee.hpp"
#include <vector>
#include <iomanip>

using namespace std;

class Staff{
public:
    Staff();
    Staff(string d);
    Staff(string d, vector<Employee> m);
    Employee get_employee(int index) const;
    void add_employee(Employee e);
    void remove_employee(int index);
    unsigned long get_size() const;
    int find_index(string name);
    Employee find_employee(string name);
    string get_department() const;
    vector<Employee> get_members() const;
    void print_members() const;
private:
    string department;
    vector<Employee> members;
};

#endif /* staff_hpp */
