//
//  helpers.hpp
//  P6_18
//
//  Created by Christian Meyer on 10/23/18.
//  Copyright © 2018 Christian Meyer. All rights reserved.
//

#ifndef helpers_hpp
#define helpers_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void remove_vector(vector<vector<int> >&v, int index);
void remove_element(vector<int>&v, int index);
void swap_same(vector<int>&v, int a, int b);
void swap_diff(vector<int>&va, vector<int>&vb, int a, int b);
int get_sum(vector<int> v);
int get_row_sum(vector<int> v);
void print_elements(vector<int>v, string m);
void print_all(vector<vector<int> >v, string m);
vector<int> remove_brackets(vector<vector<int> > v);


#endif /* helpers_hpp */
