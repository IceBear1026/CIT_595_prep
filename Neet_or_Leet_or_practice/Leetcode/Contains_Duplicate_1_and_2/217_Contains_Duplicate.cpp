class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> contains_dup;
        for(int num : nums) {
            // this will keep adding to the correct key and store counter?
            contains_dup[num]++;
        }

        for(auto itr = contains_dup.begin(); itr != contains_dup.end(); ++itr){
            if(itr->second >= 2) {
                return true;
            }
        }
        return false;
    }
};