//
//  helpers.cpp
//  P6_18
//
//  Created by Christian Meyer on 10/23/18.
//  Copyright © 2018 Christian Meyer. All rights reserved.
//

#include "helpers.hpp"

void remove_vector(vector<vector<int> >&v, int index){
    for (int i = index; i < v.size(); i++){
        v[i]=v[i+1];
    }
    v.pop_back();
}
void remove_element(vector<int>&v, int index){
    for (int i = index; i < v.size(); i++){
        v[i]=v[i+1];
    }
    v.pop_back();
}
void swap_same(vector<int>&v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}
void swap_diff(vector<int>&va, vector<int>&vb, int a, int b){
    int temp = va[a];
    va[a] = vb[b];
    vb[b] = temp;
}
int get_sum(vector<int> v){
    int i, sum = 0;
    for (i = 0; i < v.size(); i++){
        sum += v[i];
    }
    return sum;
}
int get_row_sum(vector<int> v){
    int sum = get_sum(v);
    return (sum / sqrt(v.size()));
}
void print_elements(vector<int>v, string m){
    int i;
    if (m != ""){
        cout << m << ": { ";
    } else {
        cout << m << "{ ";
    }
    for (i = 0; i < v.size(); i++){
        if (i == (v.size() - 1)){
            cout << v[i] << " }\n";
        } else {
            cout << v[i] << ", ";
        }
    }
}
void print_all(vector<vector<int> >v, string m){
    int i;
    cout << m << ":\n";
    for (i = 0; i < v.size(); i++){
        cout << "v[" << i+1 << "]: ";
        print_elements(v[i], "all");
    }
}
vector<int> remove_brackets(vector<vector<int> > v){
    vector<int> v2;
    int i, j;
    for (i = 0; i < v.size(); i++){
        for (j = 0; j < v[i].size(); j++){
            v2.push_back(v[i][j]);
        }
    }
    return v2;
}
