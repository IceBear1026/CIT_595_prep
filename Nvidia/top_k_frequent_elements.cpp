class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using namespace std;

        map<int, int> unique_count;
        for(int i = 0; i < nums.size(); ++i) {
            unique_count[nums[i]]++;
        }

        vector<pair<int,int>> sort_array(unique_count.begin(), unique_count.end());

        // this is a lambda function to sort the array in descending order based on the frequency count.
        // as you can see you can reference the second element of the pair using a.second and b.second.
        sort(sort_array.begin(), sort_array.end(), [](auto& a, auto& b) {
            return a.second > b.second; // descending order;
        });

        vector<int> result;
        // you can see that we are only pushing the first element of the pair which is the unique number into the result vector.
        // we are referencing the first element of the pair using sort_array[j].first.
        for(int j = 0; j < k; ++j) {
            result.push_back(sort_array[j].first);
        }
        return result;
    }
};
