class LRUCache 
{
private:
	int capacity;
	list<int> order;
	unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
	LRUCache(int capacity)  //задаем максимальный размер в конструкторе
	{
		this->capacity = capacity;
	}

	void put(int key, int value) //кладем ключ и значение
	{
		if (cache.find(key) != cache.end())
		{
			order.erase(cache[key].second);
		}
		else if(capacity == cache.size())
		{
			int lru = order.front();
			order.pop_front();
			cache.erase(lru);
		}
		order.push_back(key);
		cache[key] = { value,--order.end() };
	}

	int get(int key) 
	{
		if (cache.find(key) == cache.end())
		{
			return -1;
		}
		order.erase(cache[key].second);
		order.push_back(key);
		cache[key].second = --order.end();
		return cache[key].first;
	}

};
