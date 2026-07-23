class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> last_seen;
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; ++i){
            int num = nums[i];
            if(last_seen.contains(num)){
                int previous_index = last_seen[num];

                if(i - previous_index <= k){
                    return true;
                }
            }
            last_seen[num] = i;
        }
        return false;
    }
};

/*
Another solution:
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int num_size = nums.size();
        for(int i = 0; i < num_size; ++i){
            int vector_value = nums[i];
            int vector_index = i;
            if(last_seen.contains(vector_value) && (i - last_seen[vector_value] <= k)){
                    return true;
            }
            last_seen[vector_value] = vector_index;
        }
        return false;
    }
};

*/