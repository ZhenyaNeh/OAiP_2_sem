#include <iostream>
#include <cstdarg>
using namespace std;
//var 3
template <typename T >
T min(T count, ...)
{
    T* value = &count;
    int sumBit = 2;
    if (typeid(T) == typeid(double)) {
        sumBit = 1;
    }
    T maxValue = *value;
    for (int i = 0; i < count - 1; ++i)
    {
        value += sumBit;
        T nextValue = *value;
        if (maxValue < nextValue)
            maxValue = nextValue;
    }
    return maxValue;
}

void main()
{
    cout << "First min: \n" << min(10, 1, 3, 7, 9, 6, 2, 9, 8, 3, 8, 1) << "\n";
    cout << "Second min: \n" << min(10.0, 3.0, 7.8, 9.8, 6.5, 2.1, 9.0, 10.8, 8.0, 3.0, 8.0) << "\n";
    cout << "Third min: \n" << min(10, 3, 7, 9, 6, 2, 9, 8, 2, 18, 8) << "\n";
}

/*начало функции min
    *value=&count
    инициялизация sumBit=2
    если T == double
        sumBit=1
    начало цикла i от 0 до 10
        прибавляем к value sumBit
        присваеваем nextValue значение *value
        если minValue больше nextValue
            присваеваем minValue значение nextValue
    конец цикла
    возращаем minValue
 конец*/

 /*начало функции main
     вывод "First min" и min(10,1, 3, 7, 9, 6, 2, 9, 8, 3, 8, 10)
     вывод "Second min: " и min(10.0, 3.0, 7.8, 9.8, 6.5, 2.1, 9.0, 8.0, 3.0, 8.0, 10.0)
     вывод "Third min: " и min(10, 3, 7, 9, 6, 2, 9, 8, 2, 8, 10)
 конец*/