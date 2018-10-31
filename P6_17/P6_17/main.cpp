/*
 Magic squares.
 An n × n matrix that is filled with the numbers 1, 2, 3, . . ., n2 is a magic square if the sum of the elements in each row, in each column, and in the two diagonals is the same value. For example,
 
 16 3  2  13            1  2  3  4
 5  10 11 8             5  6  7  8
 9  6  7  12            9  10 11 12
 4  15 14 1             13 14 15 16
 
 Write a program that reads in n2 values from the keyboard and tests whether they
 form a magic square when put into array form. You need to test three features:
 1. Did the user enter n2 numbers for some n?
 2. Does each of the numbers 1, 2, ..., n2 occur exactly once in the user input?
 3. When the numbers are put into a square, are the sums of the rows, columns, and diagonals equal to each other?
 Hint: First read the numbers into a vector. If the size of that vector is a square, test whether all numbers between 1 and n are present. Then fill the numbers into a matrix and compute the row, column, and diagonal sums.
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> remove_brackets(vector<vector<int> > v);
vector<vector<int> > convert2cols(vector<vector<int> > v, int col_size, int col_sum);
vector<vector<int> > generate_columns(vector<vector<int> >&m, int col_size, int col_sum);
vector<vector<int> > generate_rows(vector<int>&m, int row_size, int row_sum);
void remove_at_indices(vector<int>&m, vector<int>ind);
void remove_at_vector_indices(vector<vector<int> >&m, vector<vector<int> >ind);
vector<vector<int> > check_rows(vector<vector<int> >& v, int row_size, int row_sum);
void remove_vector(vector<vector<int> >&v, int index);
void remove_element(vector<int>&v, int index);
vector<vector<int> > make_rows(vector<int> v, int n);
void swap_same(vector<int>&v, int a, int b);
void swap_diff(vector<int>&va, vector<int>&vb, int a, int b);
int get_sum(vector<int> v);
int get_row_sum(vector<int> v);
void print_elements(vector<int>v, string m);
void print_all(vector<vector<int> >v, string m);

int main(int argc, const char * argv[]) {
    int n = 4;
    int sq = pow(n, 2);
    int i;
    vector<int> magic;
    for (i = 1; i <= sq; i++){
        magic.push_back(i);
    }
    cout << "sum = " << get_row_sum(magic) << endl;
    vector<vector<int> > square = make_rows(magic, n);
    int sum = get_row_sum(magic);
    print_all(square, "square");
    cout << "\n";
    vector<vector<int> > row_square = generate_rows(magic, n, sum);
    print_all(row_square, "row_square");
    
    vector<int> flat_rows = remove_brackets(row_square);
    print_elements(flat_rows, "flat_rows");
    
    vector<vector<int> > col_square = convert2cols(row_square, n, sum);
    print_all(col_square, "col_square");
    cout << "\n";
    
    /* (1) works, but may not be useful since (2) is not working.
    //1
    vector<int> flat_columns = remove_brackets(col_square);
    print_elements(flat_columns, "flat_columns");
    cout << "\n";
    //2
    vector<vector<int> > t_square = generate_rows(flat_columns, n, sum);
    print_all(t_square, "t_square");
    cout << "\n";
    */
    
    // Left off trying to work with either sorted rows or sorted columns to achieve
    // both sorted rows and columns.
    // After that, still need to sort diagonals.
    
    return 0;
}
// Simply changes the sorted rows into sorted columns since rows are usually easier to work with.
vector<vector<int> > convert2cols(vector<vector<int> > v, int col_size, int col_sum){
    vector<vector<int > > result = v;
    int i, j;
    for (i = 0; i < v.size(); i++){
        for (j = 0; j < v[i].size(); j++){
            result[j][i] = v[i][j];
        }
    }
    return result;
}
// Sorts the rows so that each row sums to the row_sum
vector<vector<int> > generate_rows(vector<int>&m, int row_size, int row_sum){
    vector<vector<int> > all;
    int i;
    
    while (all.size() < 4){
        vector<int> temp = {};
        vector<int> indices = {};
        
        for (i = 0; i < m.size(); i++){
            if ((get_sum(temp) + m[i]) <= row_sum){
                temp.push_back(m[i]);
                indices.push_back(i);
                if (temp.size() > row_size){
                    temp = {};
                    indices = {};
                    i -= 2;
                } else if ((temp.size() == row_size) && (get_sum(temp) == row_sum)){
                    print_elements(temp, "temp");
                    print_elements(indices, "indices");
                    all.push_back(temp);
                    remove_at_indices(m, indices);
                    print_elements(m, "m");
                } else if (temp.size() == row_size){
                    temp = {};
                    indices = {};
                    i -= 3;
                }
            }
        }
    }
    return all;
}
void remove_vector(vector<vector<int> >&v, int index){
    for (int i = index; i < v.size(); i++){
        v[i]=v[i+1];
    }
    v.pop_back();
}
void remove_at_indices(vector<int>&m, vector<int>ind){
    int i, j;
    //print_elements(ind, "indicies in remove_at_indices()");
    for (i = 0; i < ind.size(); i++){
        for (int j = ind[i]; j < m.size(); j++){
            m[j]=m[j+1];
        } // problem is that the values at the indicies we want to remove at are set one index back on each iteration.
        // This can be accounted for by decrementing each index value in the ind vector by 1 one each iteration.
        m.pop_back();
        for (j = 0; j < ind.size(); j++){
            ind[j]--;
        }
    }
}
void remove_at_vector_indices(vector<vector<int> >&m, vector<vector<int> >ind){
    int i, j;
    //print_elements(ind, "indicies in remove_at_indices()");
    for (i = 0; i < ind.size(); i++){
        for (int j = 0; j < ind[i].size(); j++){
            m[i][j]=m[i][j+1];
        } // problem is that the values at the indicies we want to remove at are set one index back on each iteration.
        // This can be accounted for by decrementing each index value in the ind vector by 1 one each iteration.
        m.pop_back();
        for (j = 0; j < ind[i].size(); j++){
            ind[i][j]--;
        }
    }
}
void remove_element(vector<int>&v, int index){
    for (int i = index; i < v.size(); i++){
        v[i]=v[i+1];
    }
    v.pop_back();
}
vector<vector<int> > make_rows(vector<int> v, int n){
    int i, j, multiplier = 0;
    int row_size = n;
    vector<vector<int> > all;
    vector<int> temp;
    for (i = 0; i < n; i++){
        temp = {};
        int start = (row_size*multiplier);
        int end = (row_size*(multiplier+1));
        //cout << "start = " << start << endl;
        //cout << "end = " << end << endl;
        //cout << "got here" << endl;
        temp = {};
        for (j = start; j < end; j++){
            //all[i].push_back(v[j]);
            temp.push_back(v[j]);
            //cout << "v[j] = " << v[j] << endl;
            //cout << "temp[" << j-start << "] = " << temp[j-start] << endl;
        }
        multiplier++;
        all.push_back(temp);
    }
    /*
     cout << "all[0].size() = " << all[0].size() << endl;
     cout << "all[3].size() = " << all[3].size() << endl;
     cout << "multiplier = " << multiplier << endl;
     cout << "all[0][0] = " << all[0][0] << endl;
     cout << "all[3][3] = " << all[3][2] << endl;
     */
    return all;
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



/*
 vector<vector<int> > check_rows(vector<vector<int> >& v, int row_size, int row_sum){
 vector<vector<int> > result; */
/*
 if (i == k){
 break;
 } else if (get_sum(v[i]) == row_sum){
 result.push_back(v[i]);
 remove_vector(v, i);
 } else if (get_sum(v[k]) == row_sum){
 result.push_back(v[k]);
 remove_vector(v, k);
 }
 */
/*
 while (result.size() < 4){
 int vstart = 0;
 int vend = v.size();
 int i = vstart, k = vend;
 for (i = vstart; i < vend; i++){
 for (k = vend; k > 0; k--){
 if (i == k){
 break;
 }
 int rstart = 0;
 int rend = row_size;
 int j = rstart, m = rend;
 for (j = rstart; j < rend; j++){
 for (m = rend; m > 0; m--){
 if (m == k){
 break;
 } else if (get_sum(v[i]) < get_sum(v[k])){
 if (v[i][j] < v[k][m]){
 swap_diff(v[i], v[k], j, m);
 if (get_sum(v[i]) == row_sum){
 result.push_back(v[i]);
 remove_vector(v, i);
 } else if (get_sum(v[k]) == row_sum){
 result.push_back(v[k]);
 remove_vector(v, k);
 }
 } else if (v[i][m] < v[k][j]){
 swap_diff(v[i], v[k], m, j);
 if (get_sum(v[i]) == row_sum){
 result.push_back(v[i]);
 remove_vector(v, i);
 } else if (get_sum(v[k]) == row_sum){
 result.push_back(v[k]);
 remove_vector(v, k);
 }
 }
 } else if (get_sum(v[i]) > get_sum(v[k])){
 if (v[i][j] > v[k][m]){
 swap_diff(v[i], v[k], j, m);
 if (get_sum(v[i]) == row_sum){
 result.push_back(v[i]);
 remove_vector(v, i);
 } else if (get_sum(v[k]) == row_sum){
 result.push_back(v[k]);
 remove_vector(v, k);
 }
 } else if (v[i][m] < v[k][j]){
 swap_diff(v[i], v[k], m, j);
 if (get_sum(v[i]) == row_sum){
 result.push_back(v[i]);
 remove_vector(v, i);
 } else if (get_sum(v[k]) == row_sum){
 result.push_back(v[k]);
 remove_vector(v, k);
 }
 }
 }
 }
 }
 }
 }
 if (v.size() == 1){
 result.push_back(v[0]);
 }
 cout << "result size: " << result.size() << endl;
 }
 //END
 return result;
 } */

