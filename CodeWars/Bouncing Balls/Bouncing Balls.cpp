#include <iostream>

/*source link: https://www.codewars.com/kata/5544c7a5cb454edb3c000047/train/cpp */

class Bouncingball
{
public:
    static int bouncingBall(float h, float bounce, float window)
    {
        if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h)return -1;
        int n = static_cast<int>(ceilf(logf(window / h) / logf(bounce)));

        return 2 * n - 1;
    }
}