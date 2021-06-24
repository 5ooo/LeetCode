#include <stdio.h>
#include <math.h>

double dp[30][31] = { -1 };

double take(int a, int b, int sum)
{
    if (sum == 0)
        printf("a:%d b:%d p:%f\n", a, b, dp[a][b]);

    if (fabs(dp[a][b] + 1) < 0.00001)
        return dp[a][b];

    if (a > 0 && b >0)
        dp[a - 1][b - 1] = 0.5 * (take(a, b -1, sum -1) + take(a - 1, b, sum -1));

    return dp[a][b];
        
}



int main()
{
    take(30, 31, 60);
}
