class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> vInt;
        
        if(x < 0)
        {
            return false;
        }
        
        while(x != 0)
        {
            vInt.push_back(x % 10);
            x /= 10;
        }
        for(int i = 0; i < vInt.size(); i++)
        {
            if(vInt[i] != vInt[vInt.size() - i - 1])
                return false;
        }
        return true;
    }
};
