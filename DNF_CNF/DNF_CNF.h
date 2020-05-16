#include<math.h>
//функция для определения является ли число степенем двойки
bool Is_log2(int n)
{
    if (n == 0) {
        return false;
    }

    for (; n % 2 == 0; n /= 2);
    return (n == 1);
}
