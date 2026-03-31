class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
      priority_queue<pair<int, pair<int, int>>> maxHeap;      

      for (auto& var : points) {
        int distance = var[0] * var[0] + var[1] * var[1];
        maxHeap.push({distance,{var[0],var[1]}});
        if (maxHeap.size() > k)
        {
          maxHeap.pop();
        }
      }
      vector<vector<int>> res;
      while (!maxHeap.empty()) 
      {
        res.push_back({maxHeap.top().second.first,maxHeap.top().second.second});
        maxHeap.pop();
      }
      return res;
    }

};
