#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

#define STEP_ONE 1
#define STEP_TWO 2

static unsigned int g_cnt = 0;
static queue<string> g_queue;


void _climb_stairs(unsigned int levels, string _case)
{
    if (levels == 0)
    {
        g_queue.push(_case);
        return ;
    }

    if (levels >= STEP_ONE)
    {
        string new_case = _case + " 1";
        _climb_stairs(levels - STEP_ONE, new_case);
    }

    if (levels >= STEP_TWO)
    {
        string new_case = _case + " 2";
        _climb_stairs(levels - STEP_TWO, new_case);
    }
}


void climb_stairs(unsigned int levels)
{
    if (levels >= STEP_ONE)
    {
        string new_case = "1";
        _climb_stairs(levels - STEP_ONE, new_case);
    }

    if (levels >= STEP_TWO)
    {
        string new_case = "2";
        _climb_stairs(levels - STEP_TWO, new_case);
    }
}




int main()
{

    climb_stairs(9);


    printf("cnt : %d\n", g_queue.size());

    while (!g_queue.empty())
    {
        cout << g_queue.front() << endl;
        g_queue.pop();
    }

    return 0;
}
