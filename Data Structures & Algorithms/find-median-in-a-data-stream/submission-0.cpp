class MedianFinder
{
    priority_queue<int, vector<int>, less<int> > smallHeap; // по убыванию, в топе максимальное число(левый хип)

    priority_queue<int, vector<int>, greater<int> > largeHeap; //по возрастанию, в топе минимальное число (правый хип)
public:
    void addNum(int num)
    {
        smallHeap.push(num);
        if (!largeHeap.empty() && smallHeap.top() > largeHeap.top())
        //если справа не пусто и топ слева больше топа справа
        {
            largeHeap.push(smallHeap.top()); //переносим левый топ вправо
            smallHeap.pop(); //и сносим левый топ
        }
        if (smallHeap.size() > largeHeap.size() + 1) //если левая куча больше
        {
            largeHeap.push(smallHeap.top()); //то добавляем в правую кучу
            smallHeap.pop(); // и сносим
        }
        if (largeHeap.size() > smallHeap.size() + 1) //если же правая куча больше, то делаем наоборот
        {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }


    double findMedian() //нахождение медианы
    {
        if (smallHeap.size() == largeHeap.size()) //если размер куч равен, то складываем два топа и делим на 2.0
        {
            return (largeHeap.top() + smallHeap.top()) / 2.0;
        }
        else if (smallHeap.size() > largeHeap.size())
        {
            return smallHeap.top();
        }
        else
        {
            return largeHeap.top();
        }
    }
};
