class Solution
{
public:
	string encode(vector<string>& strs)
	{
		string res;

		for (string var : strs)
		{
			res += to_string(var.size()) + "#" + var;
		}

		return res;
	}

	vector<string> decode(string s)
	{
		vector <string> res;
		int i = 0;

		while (s.size() > i)
		{
			int j = i;

			while (s[j] != '#')
			{
				j++;
			}

			int length = stoi(s.substr(i, j - i));

			i = j + 1;

			j = length + i;

			res.push_back(s.substr(i, length));

			i = j;

		}

		



		return res;

	}
};



