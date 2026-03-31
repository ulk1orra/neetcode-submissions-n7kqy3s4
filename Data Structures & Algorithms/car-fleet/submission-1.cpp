class Solution 
{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        vector <pair<int, int>> pairs;
        for (int i = 0; i < position.size(); i++)
        {
            pairs.push_back({ position[i],speed[i] });
        }
        sort(pairs.rbegin(), pairs.rend());
        
        vector<double> res;

        for (auto& var : pairs)
        {
            res.push_back((double)(target - var.first) / var.second);

            if (res.size() >= 2 && res.back() <= res[res.size() - 2])
            {
                res.pop_back();
            }
        }
        return res.size();
    }
};