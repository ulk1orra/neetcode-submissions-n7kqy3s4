class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		unordered_set <char> us;
		int res = 0;
		int l = 0;
		for (int  r = 0; r < s.size(); r++)
		{
			while (us.find(s[r]) != us.end() )
			{
				us.erase(s[l]);
				l++;
			}


			us.insert(s[r]);
			res = max(res, r - l + 1);
		}
		return res;

	}
};