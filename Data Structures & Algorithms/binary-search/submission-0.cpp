class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size();

        while (l < r)
        {
            int m = l + (r - l) / 2;

            if (nums[m] >= target)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        if (l < nums.size() && nums[l] == target)
        {
            return l;
        }
        else
        {
            return -1;
        }
    }
};
