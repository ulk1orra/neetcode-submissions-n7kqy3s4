class MinStack 
{
private:
    long min = 0;
    std::stack<long> stack;

public:
    MinStack() {} 

    void push(int val) 
    {
        if (stack.empty()) 
        {
            stack.push(0);
            min = val;
        }
        else
        {
            stack.push(val - min);
            if (val < min)
            {
                min = val;
            }
        }
    }


    int top() 
    {
        long top = stack.top();

        if (top > 0)
        {
            return top + min;
        }
        else
        {
            return (int)min; 
        }

        
    }

    void pop() 
    {

        if (stack.empty())
        {
            return;
        }

        long pop = stack.top();
        stack.pop();

        if (pop < 0) 
        {
            min = min - pop;
        }
        
    }


    int getMin() 
    {
        return (int)min;
    }
};

