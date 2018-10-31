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

#ifndef employee_hpp
#define employee_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Employee{
public:
    Employee(){
        name = "";
        salary = 0.0;
        age = 0;
        days_employed = 0;
    }
    Employee(string n, double s, int a, int d){
        name = n;
        salary = s;
        age = a;
        days_employed = d;
    }
    string get_name() const { return name; };
    double get_salary() const { return salary; };
    int get_age() const { return age; };
    int get_days_employed() const { return days_employed; };
    void set_name(string n) { name = n; };
    void set_salary(double s) { salary = s; };
    void set_age(int a) { age = a; };
    void set_days_employed(int d) { days_employed = d; };
private:
    string name;
    double salary;
    int age, days_employed;
};

#endif /* employee_hpp */
