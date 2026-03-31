class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        deque<int> dq;
        vector<int>res(n - k + 1,0);
        int l = 0, r = 0;
        while (r < n)
        {
            while (!dq.empty() && nums[dq.back()] < nums[r])
            {
                dq.pop_back();
            }
            dq.push_back(r);

            if (l>dq.front())
            {
                dq.pop_front();
            }

            if ((r + 1) >= k)
            {
                res[l] = nums[dq.front()];
                l++;
            }
            r++;
        }
        return res;
    }
};