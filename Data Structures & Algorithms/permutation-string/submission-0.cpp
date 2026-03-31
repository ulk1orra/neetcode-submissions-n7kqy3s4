class Solution 
{
public:
    bool checkInclusion(string s1, string s2) 
    {
        if (s1.length() > s2.length()) 
        {
            return false;
        }

        vector<int> s1Count(26, 0); // массив для подсчета сколько раз каждая буква встречается в s1
        vector<int> s2Count(26, 0); // сколько раз каждая буква встречается в текущем окне s2

        for (int i = 0; i < s1.length(); i++) // подсчет букв s1 и s2
        {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0; //совпадение чисел по индексам в двух массивах (совпадение букв)

        for (int i = 0; i < 26; i++)  //если букв нет и там и там то ++, если буквы (индексы) равно в одних и тех же индексах то ++
        {
            if (s1Count[i] == s2Count[i]) 
            {
                matches++;
            }
        }

        int l = 0;
        for (int r = s1.length(); r < s2.length(); r++) //начинаем цикл с буквы, место которой это размер s1
        {
            if (matches == 26) // если есть все совпадения, то возвращаем тру
            {
                return true;
            }


            //Первый блок добавления буквы справа
            int index = s2[r] - 'a'; // порядковый номер буквы в алфавите от 0 до 25
            s2Count[index]++; // увеличиваем значение в массиве по порядковому номеру буквы
            if (s1Count[index] == s2Count[index]) //если есть совпадение когда мы добавили новую букву то ++
            {
                matches++;
            }
            else if (s1Count[index] + 1 == s2Count[index]) 
            {
                matches--;
            }


            //Второй блок убирания буквы слева 
            index = s2[l] - 'a';
            s2Count[index]--;
            if (s1Count[index] == s2Count[index]) 
            {
                matches++;
            }
            else if (s1Count[index] - 1 == s2Count[index]) 
            {
                matches--;
            }
            l++;
        }
        return matches == 26; //Возвращаем тру если в результате цикла все буквы совпали
    }
};