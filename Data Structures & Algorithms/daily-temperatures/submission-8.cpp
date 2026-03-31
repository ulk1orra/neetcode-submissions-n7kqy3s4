class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> res(temperatures.size(), 0); //результат с размером параметра температур

        stack<pair<int, int>> stack; // стек для сравнений, где <пара из<температуры, индекса>>

        for (int i = 0; i < temperatures.size(); i++) //проходимя по температурам 
        {

            while (!stack.empty() && temperatures[i] > stack.top().first) // пока стек не пустой и температура больше температуры в стеке
            {
                const auto pair = stack.top();
                 
                res[pair.second] = i - pair.second; // в результат[индкс пары] закидываем разница индексом цикла и циклом пары
                stack.pop(); // сносим верхушку
            }

            stack.push({ temperatures[i], i }); // пушим температуру + индекс 
        }
        return res;
    }
};