class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> checkanagram;
        for (string str : strs) {
            // string anagramed_string = sort(str.begin(), str.end());
            // I can't do this because sort() command returns void. 
            // I would have to create a str copy
            string anagramed_string = str;
            sort(anagramed_string.begin(), anagramed_string.end());
            checkanagram[anagramed_string].push_back(str);
            // this checkanagram[anagramed_string] is actually the vector if you think about it since we referenced the map and its key. Meaning this whole thing would be the vector itself. So we can now reference it as if it's just a vector by using commands like push_back. 
        }
    vector<vector<string>> result;

    for (auto itr = checkanagram.begin(); itr != checkanagram.end(); itr++){
        result.push_back(itr->second);
    }
    return result;
    }
};