class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Two separate loops are stil O(n)
        // If the loops are NESTED, then it becomes O(n^2)

        // creates a vector with the specific size and making it all 1. 
        vector<int> answer(nums.size(), 1);

        // first pass: place left-side products into answer.
        int prefix = 1;
        for (int i = 0; i < nums.size(); ++i){
            answer[i] = prefix;
            prefix = prefix * nums[i];
        }

        // second pass: multiply by right-side products.
        int suffix = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            answer[i] *= suffix;
            suffix*= nums[i];
        }
        
        return answer;
    }
};