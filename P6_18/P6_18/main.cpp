/*
 Exercise P6.18. Implement the following algorithm to construct magic n × n squares; it works only if n is odd. Place a 1 in the middle of the bottom row. After k has been placed in the (i, j) square, place k + 1 into the square to the right and down, wrap- ping around the borders. However, if you reach a square that has already been filled, or if you reach the lower right corner, then you must move one square up instead. Here is the 5 × 5 square that you get if you follow this method:
 Write a program whose input is the number n and whose output is the magic square of order n if n is odd.
*/

#include <iostream>
#include <vector>
#include <string>
#include "helpers.hpp"
#include "assert.h"

bool check_vector(vector<vector<int> > v, bool status);
bool check_index(vector<int> v, int index);

int main(int argc, const char * argv[]) {
    int i, j, k;
    int n = 5;
    int sq = pow(n, 2);
    int m_index = n/2;
    cout << "m_index = " << m_index << endl;
    assert(n%2 == 1);
    assert(sq%2 == 1);
    
    vector<int> flat;
    for (i = 0; i < sq; i++){
        flat.push_back(i+1);
    }
    
    vector<vector<int> > square(3, vector<int>(3, 0));
    square[n-1][m_index] = flat[0];
    remove_element(flat, 0);
    //bool check = check_vector(square, true);
    
    i = 0;
    j = 0;
    k = m_index+1;
    while (check_vector(square, false)){
        if (j >= square.size()){
            j = 0;
        } else if (j < 0){
            j = square.size()-abs(j);
        }
        if (k >= square[j].size()){
            k = 0;
        } else if (k < 0){
            k = square[j].size()-abs(k);
        }
        //while (square[j][k] == 0){
        if (square[j][k] == 0){
            square[j][k] = flat[0];
            remove_element(flat, 0);
            if ((j == (square.size()-1))&&(k == square[j].size()-1)){
                j--;
            } else{
                j++;
                k++;
            }
        } else {
            if (square[j-2][k-1] == 0){
                j -= 2;
                k -= 1;
            }
        }
    }
    
    
    print_all(square, "square");
    return 0;
}
bool check_vector(vector<vector<int> > v, bool status){
    int i, j;
    bool zeros = false;
    for (i = 0; i < v.size(); i++){
        for (j = 0; j < v[i].size(); j++){
            if (v[i][j] == 0){
                zeros = true;
            }
        }
    }
    if (status == true){
        if (zeros == true){
            cout << "zeros == true" << endl;
        } else {
            cout << "zeros == false" << endl;
        }
    }
    return zeros;
}
bool check_index(vector<int> v, int index);

