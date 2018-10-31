/*
 Exercise P6.3. Write a procedure reverse that reverses the sequence of elements in a
 For example, if reverse is called with a vector containing
 1 4 9 16 9 7 4 9 11
 then the vector is changed to
 11 9 4 7 9 16 9 4 1
*/

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> seq = {1, 4, 9, 16, 9, 7, 4, 9, 11}; // 9e
    vector<int> reverse;
    size_t x = sizeof(seq);
    size_t y = sizeof(seq[0]);
    size_t z = x / y;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    int i = seq.size();
    cout << "i = " << i << endl;
    size_t k = seq.size();
    cout << "k = " << k << endl;
    k++;
    cout << "k++ = " << k << endl;
    ++k;
    cout << "++k = " << k << endl;
    
    size_t s = seq.size();
    // Because size_t is unsigned, cannot compare it with 0. When s (a size_t variable) is decremented below 0, it begins acting strange, since there is not supposed to be a size of 0?
    
    for (s+1; s > 0; --s){
        cout << "s = " << s << endl;
        reverse.push_back(seq[s-1]);
    }
    for (i = 0; i < reverse.size(); i++){
        cout << "reverse[" << i << "]: " << reverse[i] << endl;
    }
    
    return 0;
}
