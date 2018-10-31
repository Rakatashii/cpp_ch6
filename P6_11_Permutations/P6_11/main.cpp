/*
 Exercise P6.11.
 Write a program that asks the user to input a number n and prints all permutations of the sequence of numbers 1, 2, 3, ..., n. For example, if n is 3, the program should print
 1 2 3
 1 3 2
 2 1 3
 2 3 1
 3 1 2
 3 2 1
 Hint: Write a function
 permutation_helper(vector<int> prefix, vector<int> to_permute)
 that computes all the permutations in the array to_permute and prints each permutation, prefixed by all numbers in the array prefix. For example, if prefix contains the number 2 and to_permute the numbers 1 and 3, then permutation_helper prints
 2 1 3
 2 3 1
 The permutation_helper function does the following: If to_permute has no elements, print the elements in prefix. Otherwise, for each element e in to_permute, make an array to_permute2 that is equal to permute except for e and an array prefix2 consist- ing of prefix and e. Then call permutation_helper with prefix2 and to_permute2.
*/
#include <iostream>
#include <vector>

using namespace std;

void print_vect(vector<int> v);
void swap(vector<int>& v, int a, int b);
void generate_permutations(vector<vector<int> >& all_permutations, vector<int> p, int start, int end);

int main(int argc, const char * argv[]) {
    vector<int> permutation_vect;
    cout << "n? ";
    int n;
    //cin >> n;
    n = 4;
    cout << n << endl;
    unsigned int i, n_bang = 1;
    for (i = 1; i <= n; i++){
        permutation_vect.push_back(i);
    }
    for (i = 1; i <= n; i++){
        n_bang *= i;
    }
    cout << "n! = " << n_bang << endl;
    //print_vect(permutation_vect);
    /*
    print_vect(p);
    swap(p, 1, 2);
    print_vect(p);
    */
    vector<vector<int> > all_permutations;
    generate_permutations(all_permutations, permutation_vect, 0, n);
    for (i = 0; i < all_permutations.size(); i++){
        print_vect(all_permutations[i]);
    }
    
    return 0;
}

void generate_permutations(vector<vector<int> >& permutations, vector<int> p, int start, int end){
    vector<int> temp = p;
    
    unsigned int i, max_count = (end/2)+1;
    
    if (start == end){
        bool equal = false;
        unsigned int j, k;
        for (i = 0; i < permutations.size(); i++){
            for (j = 0; j < permutations[i].size(); j++){
                unsigned int count = 0;
                for (k = 0; k < temp.size(); k++){
                    if (permutations[i][j] == temp[k] && (j == k)){
                        count++;
                        if (count >= max_count){
                            equal = true;
                        }
                    }
                }
            }
        }
        if (!equal){
            permutations.push_back(temp);
        }
    } else {
        for (i = start; i < end; i++){
            swap(temp, start, i);
            generate_permutations(permutations, temp, start+1, end);
            swap(temp, start, i);
        }
    }
}
void print_vect(vector<int> v){
    unsigned int i;
    for (i = 0; i < v.size(); i++){
        cout << v[i] << " ";
        if (i == (v.size() - 1)){
            cout << endl;
        }
    }
}
void swap(vector<int>& v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}
