/*
 Write a function that removes duplicates from a vector. For example, if remove_duplicates is called with a vector containing
 1 4 9 16 9 7 4 9 11
 then the vector is changed to
 1 4 9 16 7 11
*/

#include <iostream>
#include <vector>

using namespace std;

void remove_duplicates(vector<int>& v);

int main(int argc, const char * argv[]) {
    vector<int> a = {1, 4, 9, 16, 9, 7, 4, 9, 11};
    vector<int> b = {1, 4, 13, 82, 91, 8, 9, 9, 16, 9, 7, 4, 5, 2, 3, 4, 9, 6, 11, 9, 11};
    unsigned int i;
    cout << "a = { ";
    for (i = 0; i < a.size(); i++){
        if (i == (a.size() - 1)){
            cout << a[i] << " }" << endl;
        } else {
            cout << a[i] << ", ";
        }
    }
    remove_duplicates(a);
    cout << "After #remove_duplicates(a)" << endl;
    cout << "a = { ";
    for (i = 0; i < a.size(); i++){
        if (i == (a.size() - 1)){
            cout << a[i] << " }" << endl;
        } else {
            cout << a[i] << ", ";
        }
    }
    cout << "\n";
    cout << "b = { ";
    for (i = 0; i < b.size(); i++){
        if (i == (b.size() - 1)){
            cout << b[i] << " }" << endl;
        } else {
            cout << b[i] << ", ";
        }
    }
    remove_duplicates(b);
    cout << "After #remove_duplicates(b)" << endl;
    cout << "b = { ";
    for (i = 0; i < b.size(); i++){
        if (i == (b.size() - 1)){
            cout << b[i] << " }" << endl;
        } else {
            cout << b[i] << ", ";
        }
    }
    // Working as expected
    return 0;
}

void remove_duplicates(vector<int>& v){
    vector<int> temp;
    unsigned int i = 0;
    temp.push_back(v[i]);
    for (i = i; i < v.size(); i++){
        unsigned int j;
        bool not_in_temp = true;
        for (j = 0; j < temp.size(); j++){
            if (v[i] == temp[j]){
                not_in_temp = false;
            }
        }
        if (not_in_temp){
            temp.push_back(v[i]);
        }
    }
    v = temp;
}
