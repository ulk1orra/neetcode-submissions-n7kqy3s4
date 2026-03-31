class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        		unordered_set <int> us(nums.begin(),nums.end());
		int longest = 0;

		for (int num : us)
		{
			if (us.find(num - 1) == us.end())
			{
				int length = 1;

				while (us.find(num + length) != us.end())
				{
					length++;
				}
				longest = max(longest, length);
			}
		}

		return longest;
    }
};
