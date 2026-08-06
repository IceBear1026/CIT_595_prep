#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            // this makes it so that even if I have a negative number or only one number, it will still return the number. 
            int largestSum = nums[0];

            for (int i = 0; i < nums.size(); ++i) {
                // the reason why we want to se the current sum here is because every loop will create a new scenario of index i which is a new starting of of subarray.
                int currentSum = 0;
                for (int j = i; j < nums.size(); ++j) {
                    // we are just adding the current number to the current sum. 
                    currentSum += nums[j];

                    // so every iteration of each of the currentSum of every new index i, it will keep adding and checking every loop where the sum with the next value and the next will be larger compared to the stored largestSum. 
                    if(currentSum > largestSum) {
                        largestSum = currentSum;
                    }
                }
            }
            return largestSum;
        }
};