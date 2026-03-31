class Solution 
{
public:
    bool isValid(string s) 
    {
        stack <char> stack;
        unordered_map <char, char> um_map =
        {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for (char c : s)
        {
            if (um_map.count(c))
            {
                if (!stack.empty() && um_map[c] == stack.top())
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                stack.emplace(c);
            }
        }
        return stack.empty();
    }
};