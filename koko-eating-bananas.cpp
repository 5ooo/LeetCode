class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_speed = 1;
        int max_speed = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            if (piles[i] > max_speed)
                max_speed = piles[i];
        }

        while (min_speed != max_speed)
        {
            int speed = min_speed + (max_speed - min_speed) / 2;
            if (calcHours(piles, speed) > h) 
            {
                min_speed = speed + 1;
            }
            else if (calcHours(piles, speed) <= h) 
            {
                max_speed = speed;
            }
        }

        return min_speed;
    }

    int calcHours(vector<int>& piles, int speed)
    {
        int ret = 0;

        for (int i = 0; i < piles.size(); i++)
            ret += (piles[i]%speed != 0) ? (piles[i]/speed + 1) : (piles[i]/speed);

        return ret;
    }
};
