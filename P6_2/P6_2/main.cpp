/*
 Exercise P6.2. Write a function that computes the alternating sum of all elements in
 a vector. For example, if alternating_sum is called with a vector containing 1 4 9 16 9 7 4 9 11
 
 then it computes:
 1 − 4 + 9 − 16 + 9 − 7 + 4 − 9 + 11 = −2
 */

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> nums = {9, 18, 8, 17, 16, 14, 12, 11, 5, 6, 4, 10};
    int check;
    int sum = 0;
    for (check = 2; check < (nums.size() + 2); check++){
        if (check % 2 == 0){
            sum += nums[check-2];
        } else if (check % 2 == 1){
            sum -= nums[check-2];
        }
    }
    cout << "Sum of alternating vector = " << sum << endl;
    return 0;
}
