class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // let's create a map that has a key that represents the main anagram of all the other anagrams that will be inside the vector.
        map<string, vector<string>> anagrams_with_sorted_key;
        for(string str : strs) {
            string temp_str = str;
            sort(temp_str.begin(), temp_str.end());
            anagrams_with_sorted_key[temp_str].push_back(str);
        }

        vector<vector<string>> return_vector;
        for(auto itr = anagrams_with_sorted_key.begin(); itr != anagrams_with_sorted_key.end(); ++itr){
            return_vector.push_back(itr->second);
        }

        return return_vector;
    }
};