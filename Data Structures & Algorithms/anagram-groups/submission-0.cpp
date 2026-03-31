class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>> res;

 for (const auto& words : strs)
 {
     vector <int> count(26, 0);
     for (char c : words)
     {
         count[c - 'a']++;
     }
     string key = to_string(count[0]);
     for (size_t i = 1; i < 26; ++i)
     {
         key += '_' + to_string(count[i]);
     }
     res[key].push_back(words);
      
 }
 vector <vector<string>> result;

 for (auto pair : res)
 {
     result.push_back(pair.second);
 }
 return result;
    }
};
