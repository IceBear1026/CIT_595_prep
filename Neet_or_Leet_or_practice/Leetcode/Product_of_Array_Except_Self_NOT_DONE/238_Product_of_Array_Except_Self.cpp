class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    
    vector<int> result;
    int i = 0;
    int size = nums.size();
    while(i < size){
        int left_side = 1;
        int right_side = 1;
        // do the left side of the i (multiplication)
        for (int j = 0; j < i; ++j){
            left_side *= nums[j];
        }

        // do the right side of the i (multiplication)
        for (int k = i + 1; k < size; ++k){
            right_side *= nums[k];
        }
        result.push_back(left_side * right_side);
        i++;
    }
    return result;
    }
};