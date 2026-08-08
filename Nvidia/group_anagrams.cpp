class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> unique_key_map;
        vector<vector<string>> result; 
        for (string s : strs) {
            string temp_sort = s;
            sort(temp_sort.begin(), temp_sort.end());
            unique_key_map[temp_sort].push_back(s);
        }
        for (auto& [key, value] : unique_key_map){
            result.push_back(value);
        }
        return result;
    }
};
