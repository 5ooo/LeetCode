class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
#define COMBINATION(X) \
do{\
    if (i == 0)\
    {\
        for (int j = 0; j < X.size(); j++)\
            vRet.push_back(X[j]);\
    }\
    else\
    {\
        int nSize = vRet.size();\
        for (int j = 0; j < nSize; j++)\
        {\
            for (int k = 0; k < X.size(); k++)\
                vRet.push_back(vRet.front() + X[k]);\
         \
            vRet.erase(vRet.begin());\
        }\
    }\
}while(0)
        
        vector<string> vRet;
        vector<string> v2{"a", "b", "c"};
        vector<string> v3{"d", "e", "f"};
        vector<string> v4{"g", "h", "i"};
        vector<string> v5{"j", "k", "l"};
        vector<string> v6{"m", "n", "o"};
        vector<string> v7{"p", "q", "r", "s"};
        vector<string> v8{"t", "u", "v"};
        vector<string> v9{"w", "x", "y", "z"};

        for (int i = 0; i < digits.length(); i++)
        {
            switch (digits.at(i))
            {
            case '2':
                COMBINATION(v2);
                break;
            case '3':
                COMBINATION(v3);
                break;
            case '4':
                COMBINATION(v4);
                break;
            case '5':
                COMBINATION(v5);
                break;
            case '6':
                COMBINATION(v6);
                break;
            case '7':
                COMBINATION(v7);
                break;
            case '8':
                COMBINATION(v8);
                break;
            case '9':
                COMBINATION(v9);
                break;
            default:
                vRet.clear();
                return vRet;
            }
        }
        return vRet;
    }
};
