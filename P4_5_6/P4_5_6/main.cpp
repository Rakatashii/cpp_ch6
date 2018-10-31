

#include <iostream>
#include <vector>

using namespace std;

vector<int> append_b(vector<int> a, vector<int> b);
vector<int> merge(vector<int> a, vector<int> b);
vector<int> merge_sorted(vector<int> a, vector<int> b);

int main(int argc, const char * argv[]) {
    /* P6_4
     Write a function
     vector<int> append(vector<int> a, vector<int> b)
     that appends one vector after another. For example,
     if a is
     1 4 9 16
     and b is
     9 7 4 9 11
     then append returns the vector
     1 4 9 16 9 7 4 9 11
    */
    vector<int> a1 = {1, 4, 9, 16};
    vector<int> b1 = {9, 7, 4, 9, 11};
    vector<int> c1 = append_b(a1, b1);
    unsigned int i;
    //cout << "c1: { ";
    for (i = 0; i < c1.size(); i++){
        if (i == c1.size() - 1){
            //cout << c1[i] << " }" << endl;
        } else {
            //cout << c1[i] << ", ";
        }
    }
    //cout << "\n";
    // Working
    
    // P6_5
    /*
     Exercise P6.5.
     Write a function
     vector<int> merge(vector<int> a, vector<int> b)
     that merges two arrays, alternating elements from both arrays. If one array is shorter than the other, then alternate as long as you can and then append the remaining elements from the longer array.
     For example,
     if a is
     1 4 9 16
     and b is
     9 7 4 9 11
     then merge returns the array
     1 9 4 7 9 4 16 9 11
    */
    vector<int>a2 = {1, 4, 9, 16};
    vector<int>b2 = {9, 7, 4, 9, 11};
    vector<int>c2 = merge(a2, b2);
    //cout << "c2: { ";
    for (i = 0; i < c2.size(); i++){
        if (i == c2.size() - 1){
            //cout << c2[i] << " }" << endl;
        } else {
            //cout << c2[i] << ", ";
        }
    }
    //cout << "\n";
    // Working
    
    /*
     Exercise P6.6.
     Write a function
     vector<int> merge_sorted(vector<int> a, vector<int> b)
     that merges two sorted vectors, producing a new sorted vector. Keep an index into each vector, indicating how much of it has been processed already. Each time, append the smallest unprocessed element from either vector, then advance the index.
     For example,
     if a is
     1 4 9 16
     and b is
     4 7 9 9 11
     then merge_sorted returns the vector
     1 4 4 7 9 9 9 11 16
    */
    vector<int> a3 = {1, 4, 9, 16};
    vector<int> b3 = {4, 7, 9, 9, 11};
    vector<int> c3 = merge_sorted(a3, b3);
    cout << "c3: { ";
    for (i = 0; i < c3.size(); i++){
        if (i == (c3.size() - 1)){
            cout << c3[i] << " }" << endl;
        } else {
            cout << c3[i] << ", ";
        }
    }
    cout << "\n";
    // Working - seems very fragile though.
    
    return 0;
}

vector<int> append_b(vector<int> a, vector<int> b){
    vector<int> temp = a;
    for (int i = 0; i < b.size(); i++){
        temp.push_back(b[i]);
    }
    return temp;
}
vector<int> merge(vector<int> a, vector<int> b){
    vector<int> alt;
    int i;
    int j = 0;
    int k = 0;
    for (i = 0; i < (a.size() + b.size()); i++){
        if (i % 2 == 0 && j < a.size()){
            alt.push_back(a[j]);
            j++;
            // cout << "i = " << i << "EVEN" << endl; // So 0 is considered even.
        } else if ((i % 2 == 1) && (k < b.size())){
            alt.push_back(b[k]);
            k++;
        } else if (j < a.size()){
            alt.push_back(a[j]);
            j++;
        } else if (k < b.size()){
            alt.push_back(b[k]);
            k++;
        }
    }
    return alt;
}
vector<int> merge_sorted(vector<int> a, vector<int> b){
    /*
     if a is
     1 4 9 16
     and b is
     4 7 9 9 11
     then merge_sorted returns the vector
     1 4 4 7 9 9 9 11 16
    */
    vector<int> alt;
    bool unsorted = true;
    unsigned int i = 0, j = 0;
    while (unsorted){
        if ((i >= (a.size())) && (j < b.size())){
            alt.push_back(b[j]);
            j++;
            /*
            for (j = j; j < b.size(); j++){
                alt.push_back(b[j]);
                //j++;
            }
             */
        }
        if ((j >= (b.size())) && (i < a.size())){
            alt.push_back(a[i]);
            i++;
            /*
            for (i = i; i < a.size(); i++){
                alt.push_back(a[i]);
                //i++;
            }
             */
        }
        if ((i >= (a.size())) && (j >= (b.size()))){
            cout << "HERE - i = " << i << " : j = " << j << endl;
            unsorted = false;
            break;
        }
        if (a[i] == b[j]){
            alt.push_back(a[i]);
            i++;
            alt.push_back(b[j]);
            j++;
        } else if (a[i] < b[j]){
            alt.push_back(a[i]);
            i++;
        } else if (b[j] < a[i]){
            alt.push_back(b[j]);
            j++;
        }
    }
    return alt;
}









