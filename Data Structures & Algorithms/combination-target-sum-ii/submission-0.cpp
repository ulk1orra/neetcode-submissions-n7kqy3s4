class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int> &nums, int target)
    {
        res.clear();
        sort(nums.begin(), nums.end());
        dfs(0, {}, 0, nums, target);
        return res;
    }

private:
    void dfs(int i,
             vector<int> subset,
             int total,
             vector<int> &nums,
             int target)
    {

        if (total == target)
        {
            res.push_back(subset);
            return;
        }

        for (int j = i; j < nums.size(); j++)
        {
            if (j > i && nums[j] == nums[j - 1])
            {
                continue;
            }
            if (total + nums[j] > target)
            {
                break;
            }

            subset.push_back(nums[j]);
            dfs(j + 1, subset, total + nums[j], nums, target);
            subset.pop_back();
        }
    }
};

