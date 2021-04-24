#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long total_cnt = 100000000;

    unsigned long long cnt = 0;

    unsigned long long rand_a = 0;
    unsigned long long rand_b = 0;

    unsigned long long choose_a; //30
    unsigned long long choose_b; //31

    for (unsigned long long j = 0; j < total_cnt; j++)
    {
        choose_a = 30;
        choose_b = 31;

        for (unsigned long long i = 0; i < 60; i++)
        {
            if (rand() % 2)
            {
                rand_a++;
                choose_a--;
            }
            else
            {
                rand_b++;
                choose_b--;
            }

            if (choose_a == 0)
            {
                cnt++;
                break;
            }

            if (choose_b == 0)
            {
                break;
            }
        }
    }

    printf("%lld %lld\n", rand_a, rand_b);
    printf("%f\n", (double)cnt/total_cnt);
}
