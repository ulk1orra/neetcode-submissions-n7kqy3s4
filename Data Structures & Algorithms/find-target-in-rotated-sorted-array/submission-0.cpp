class Solution 
{
public:
    int search(std::vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size() - 1;

        while (l <= r) 
        {
            int m = (r - l) / 2 + l ;
            if (target == nums[m]) //если заданное число равно середине то возвращаем его 
            {
                return m;
            }

            if (nums[l] <= nums[m]) //если левая граница меньше или равна середине то
            {
                if (target > nums[m] || target < nums[l]) //если заданное число больше середины или меньше левой границы
                {
                    l = m + 1; //то смещаем лево в середину +1
                }
                else 
                {
                    r = m - 1;
                }
            }


            else 
            {
                if (target < nums[m] || target > nums[r]) 
                {
                    r = m - 1;
                }
                else 
                {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};