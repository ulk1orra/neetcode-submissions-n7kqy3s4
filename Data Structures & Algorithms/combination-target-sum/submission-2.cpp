class Solution
{
public:
    vector<vector<int>> res; // результат
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        // dfs fun
        dfs(0, subset, nums, 0, target);
        return res;
    }

    void dfs(int i,
             vector<int> &subset,
             vector<int> &nums,
             int total,
             int target)
    {
        if (total == target)
        {
            res.push_back(subset);
            return;
        }
        for (int j = i; j < nums.size(); ++j)
        {
            if (total + nums[j] > target)
            {
                return;
            }
            subset.push_back(nums[j]);
            dfs(j, subset, nums, total + nums[j], target);
            subset.pop_back();
        }
    }
};

