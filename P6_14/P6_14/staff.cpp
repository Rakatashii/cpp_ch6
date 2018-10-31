//
//  staff.cpp
//  P6_14
//
//  Created by Christian Meyer on 10/22/18.
//  Copyright © 2018 Christian Meyer. All rights reserved.
//

#include "staff.hpp"

Staff::Staff(){
    department = "";
    members = {};
}
Staff::Staff(string d){
    department = d;
    members = {};
}
Staff::Staff(string d, vector<Employee> m){
    department = d;
    members = m;
}
Employee Staff::get_employee(int index) const{
    return members[index];
}
void Staff::remove_employee(int index){
    for(int i = index; i < (members.size()-1); i++){
        //cout << "enter for loop\n";
        //^ shows that for loop is never entered if index already = size()-1
        //... so only pop_back() is executed
        members[i] = members[i+1];
    }
    members.pop_back();
}
void Staff::add_employee(Employee e){
    members.push_back(e);
}
unsigned long Staff::get_size() const{
    return members.size();
}
int Staff::find_index(string name){
    unsigned int i , members_index = NULL;
    bool found = false;
    if (members.size() > 0){
        for (i = 0; i < members.size(); i++){
            if (name == members[i].get_name()){
                members_index = i;
                found = true;
            }
        }
    }
    if (found) {
        return members_index;
    } else {
        return -1;
    }
}
Employee Staff::find_employee(string name){
    unsigned int i;
    Employee e = Employee();
    if (members.size() > 0){
        for (i = 0; i < members.size(); i++){
            if (name == members[i].get_name()){
                e = members[i];
            }
        }
    }
    return e;
}
string Staff::get_department() const{
    return department;
}
vector<Employee> Staff::get_members() const{
    return members;
}
void Staff::print_members() const{
    int i;
    cout << left << setw(12) << setfill(' ') << "Name";
    cout << left << setw(12) << setfill(' ') << "Salary";
    cout << left << setw(12) << setfill(' ') << "Age";
    cout << left << setw(12) << setfill(' ') << "Days Employed";
    cout << endl;
    for (i = 0; i < members.size(); i++){
        cout << left << setw(12) << setfill(' ') << members[i].get_name();
        cout << left << setw(12) << setfill(' ') << members[i].get_salary();
        cout << left << setw(12) << setfill(' ') << members[i].get_age();
        cout << left << setw(12) << setfill(' ') << members[i].get_days_employed();
        cout << endl;
    }
    
}

/*
private:
string department;
vector<Employee> members;
*/
