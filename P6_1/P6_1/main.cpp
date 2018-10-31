/*
 P6_1
 double scalar_product(vector<double> a, vector<double> b)
 that computes the scalar product of two vectors. The scalar product is
 scalar_products = a0b0 + a1b1 + ... + a(n-1)b(n-1)
*/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<double> a = {9.1, -4.6, 8.9, 3.82};
    vector<double> b = {-9.23, -9.23, 8.1, -2.79};
    int i;
    double s = 0.0;
    for (i = 0; (i < a.size() && i < b.size()); i++){
        s += (a[i]*b[i]);
    }
    cout << "s = " << s << endl;
}
