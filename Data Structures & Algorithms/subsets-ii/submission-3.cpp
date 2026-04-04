class Solution
{
    vector<vector<int>> res; // результат
    vector<int> subset;      // подсписок

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        backtrack(0, nums, subset);
        return res;
    }

    void backtrack(int i,
                   vector<int> &nums,
                   vector<int> &subset)
    {
        res.push_back(subset);
        for (int j = i; j < nums.size(); ++j)
        {
            if (j > i && nums[j] == nums[j - 1])
            {
                continue;
            }
            subset.push_back(nums[j]);
            backtrack(j + 1, nums, subset);
            subset.pop_back();
        }
    }
};
