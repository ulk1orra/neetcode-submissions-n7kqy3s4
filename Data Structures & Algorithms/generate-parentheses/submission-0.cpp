class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string stack;
        backtrack(n, 0, 0, stack, res);
        return res;
    }

    void backtrack(int n,
                   int opened,
                   int closed,
                   string &stack,
                   vector<string> &res)
    {

        if (opened == closed && n == opened)
        {
            res.push_back(stack);
            return;
        }
        if (n > opened)
        {
            stack += '(';
            backtrack(n, opened + 1, closed, stack, res);
            stack.pop_back();
        }
        if (opened > closed)
        {
            stack += ')';
            backtrack(n, opened, closed + 1, stack, res);
            stack.pop_back();
        }
    };
};

