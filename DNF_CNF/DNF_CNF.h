#include<math.h>
//������� ��� ����������� �������� �� ����� �������� ������
bool Is_log2(int n)
{
    if (n == 0) {
        return false;
    }

    for (; n % 2 == 0; n /= 2);
    return (n == 1);
}
