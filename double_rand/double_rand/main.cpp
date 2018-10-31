//
//  main.cpp
//  double_rand
//
//  Created by Christian Meyer on 10/22/18.
//  Copyright © 2018 Christian Meyer. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <iostream>

using namespace std;

double fRand(double fMin, double fMax);

int main(int argc, const char * argv[]) {
    double d = fRand(0.0, 100.0);
    cout << "d = " << d << endl;
    return 0;
}

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    cout << "(double)rand() = " << (double)rand() << endl;
    cout << "RAND_MAX = " << RAND_MAX << endl;
    cout << "f = " << f << endl;
    return fMin + f * (fMax - fMin);
}
