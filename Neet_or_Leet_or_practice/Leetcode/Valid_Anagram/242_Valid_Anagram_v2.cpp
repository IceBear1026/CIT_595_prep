class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> s_map = separate_string_to_map(s);
        map<char, int> t_map = separate_string_to_map(t);

        return s_map == t_map;
    }

    map<char, int> separate_string_to_map(string x){
        map<char, int> return_map;
        for (int i = 0; i < x.length(); ++i){
            char each_char = x[i];
            return_map[each_char]++;
        }
        return return_map;
    }
};