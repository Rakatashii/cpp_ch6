/*
 Exercise P6.12. Write a program that produces ten random permutations of the num- bers 1 to 10. To generate a random permutation, you need to fill a vector with the numbers 1 to 10 so that no two entries of the vector have the same contents. You could do it by brute force, by calling rand_int until it produces a value that is not yet in the vector. Instead, you should implement a smart method. Make a second array and fill it with the numbers 1 to 10. Then pick one of those at random, remove it, and append it to the permutation vector. Repeat ten times.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>

using namespace std;

void swap(vector<int>&v, int a, int b);
void random_permutations(vector<vector<int> >& all, vector<int>& base);
int main(int argc, const char * argv[]) {
    vector<int> one_ten = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned int i, j;
    vector<vector<int> > permutations;
    random_permutations(permutations, one_ten);
    for (i = 0; i < permutations.size(); i++){
        cout << "permutations[" << i+1 << "]: {";
        for (j = 0; j < permutations[i].size(); j++){
            if (j == (permutations[i].size() - 1)){
                cout << permutations[i][j] << "}\n";
            } else {
                cout << permutations[i][j] << ", ";
            }
        }
    }
    return 0;
}
void swap(vector<int>&v, int a, int b){
    int t = v[a];
    v[a] = v[b];
    v[b] = t;
}
void random_permutations(vector<vector<int> >& all, vector<int>& base){
    srand((unsigned int)(time(NULL)));
    while (all.size() < 10){
        unsigned int i = 0;
        for (i = 0; i < 10; i++){
            int rand1 = rand()%10;
            int rand2 = rand()%10;
            if (rand1 != rand2){
                swap(base, rand1, rand2);
            }
        }
        all.push_back(base);
    }
}

