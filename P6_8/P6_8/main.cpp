/*
 Write a predicate function
 bool same_set(vector<int> a, vector<int> b)
 that checks whether two vectors have the same elements in some order, ignoring multiplicities. For example, the two vectors
 and
 1 4 9 16 9 7 4 9 11 11 11 7 9 16 4 1
 would be considered identical. You will probably need one or more helper functions.
*/

#include <iostream>
#include <vector>

using namespace std;

bool same_set(vector<int> a, vector<int> b);

int main(int argc, const char * argv[]) {
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {1, 2, 3, 4};
    vector<int> c = {4, 3, 2, 1};
    vector<int> d = {2, 3, 4, 5};
    vector<int> e = {5, 4, 3, 2};
    
    cout << "a == b? " << same_set(a, b) << endl << endl;
    cout << "a == c? " << same_set(a, c) << endl << endl;
    cout << "a == d? " << same_set(a, d) << endl << endl;
    cout << "a == e? " << same_set(a, e) << endl << endl;
    cout << "b == c? " << same_set(b, c) << endl << endl;
    cout << "b == d? " << same_set(b, d) << endl << endl;
    cout << "b == e? " << same_set(b, e) << endl << endl;
    cout << "c == a? " << same_set(c, a) << endl << endl;
    cout << "c == d? " << same_set(c, d) << endl << endl;
    cout << "c == e? " << same_set(c, e) << endl << endl;
    cout << "d == e? " << same_set(d, e) << endl << endl;
    
    return 0;
}

bool same_set(vector<int> a, vector<int> b){
    if (a.size() != b.size()){
        //cout << "a and b are not the same size." << endl;
        return false;
    }
    unsigned int i = 0, j = 0, correct = 0;
    for (i = 0; i < a.size(); i++){
        for (j = 0; j < b.size(); j++){
            if (a[i] == b[j]){
                correct++;
            }
        }
    }
    if (correct >= i){
        //cout << "correct = " << correct << endl;
        //cout << "a and b are the same size" << endl;
        return true;
    }
    //cout << "a and b are not the same size." << endl;
    // Working
    return false;
}
