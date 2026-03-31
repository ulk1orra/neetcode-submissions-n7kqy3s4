class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map <int, int> count;
 
 for (auto var : nums)
 {
     count[var] += 1;
 }

 vector <vector<int>> pair (nums.size()+1);

 for (const auto& var : count)
 {
     pair[var.second].push_back(var.first); 
 }


 vector <int> res;
 for (int i = pair.size() - 1; i > 0; --i)
 {
     for (auto var : pair[i])
     {
         res.push_back(var);

         if (res.size() == k)
         {
             return res;
         }
     }
 }
 return res;
    }
};
