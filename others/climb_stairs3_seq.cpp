#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

#define STEP_ONE 1
#define STEP_TWO 2
#define STEP_THREE 3

static unsigned int g_cnt[100] = { 0 };
static queue<string> g_queue;
static vector<vector<string> > dp;


void _climb_stairs(unsigned int last_step, unsigned int cur_levels, unsigned int levels, string _case)
{
    if (cur_levels == levels)
    {
        g_queue.push(_case);
        return ;
    }

    if (last_step != STEP_ONE && levels >= STEP_ONE + cur_levels)
    {
        string new_case = _case + " 1";
        _climb_stairs(STEP_ONE, cur_levels + 1, levels, new_case);
    }

    if (last_step != STEP_TWO && levels >= STEP_TWO + cur_levels)
    {
        string new_case = _case + " 2";
        _climb_stairs(STEP_TWO, cur_levels + 2, levels, new_case);
    }

    if (last_step != STEP_THREE && levels >= STEP_THREE + cur_levels)
    {
        string new_case = _case + " 3";
        _climb_stairs(STEP_THREE, cur_levels + 3, levels, new_case);
    }
}


void climb_stairs(unsigned int levels)
{
    if (levels >= STEP_ONE)
    {
        string new_case = "1";
        unsigned int cur_levels = 1;
        _climb_stairs(STEP_ONE, cur_levels, levels, new_case);
    }

    if (levels >= STEP_TWO)
    {
        string new_case = "2";
        unsigned int cur_levels = 2;
        _climb_stairs(STEP_TWO, cur_levels, levels, new_case);
    }

    if (levels >= STEP_THREE)
    {
        string new_case = "3";
        unsigned int cur_levels = 3;
        _climb_stairs(STEP_THREE, cur_levels, levels, new_case);
    }
}




int main()
{

    climb_stairs(100);


    printf("cnt : %d\n", g_queue.size());

    while (!g_queue.empty())
    {
        cout << g_queue.front() << endl;
        g_queue.pop();
    }

    return 0;
}
