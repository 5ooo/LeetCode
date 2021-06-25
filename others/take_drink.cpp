#include <stdio.h>

#define DRINK_A 30
#define DRINK_B 31

double dp[DRINK_A+1][DRINK_B+1];

void take(int a, int b)
{
    if (a < 0 || b < 0)
        return ;

    dp[0][0] = 1;
    for (int i = 1; i <= a; i++)
        dp[i][0] = dp[i-1][0] * 0.5;

    for (int j = 1; j <= b; j++)
        dp[0][j] = dp[0][j-1] * 0.5;

    for (int i = 1; i <= a; i++)
    {
        double factor1 = (i == a) ? 1 : 0.5;

        for (int j = 1; j <= b; j++)
        {
            double factor2 = (j == b) ? 1 : 0.5;

            dp[i][j] = factor1 * dp[i][j-1] + factor2 * dp[i-1][j];
        }
    }

    printf("dp[%d][%d] :%f\n", a, b, dp[a][b]);
}

int main()
{
    take(DRINK_A, DRINK_B);
    printf("%f\n", dp[30][30]);

    return 0;
}
