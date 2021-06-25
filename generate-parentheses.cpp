class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;

        _sub_generate_parenthesis(n, n, "", ret);

        return ret;
    }

    //leftCnt rightCnt 剩余括号数
    void _sub_generate_parenthesis(int leftCnt, int rightCnt, string tmp, vector<string> &ret)
    {
        if (leftCnt > rightCnt)
            return ;

        if (leftCnt == 0 && rightCnt == 0)
        {
            printf("%s\n", tmp.c_str());

            ret.push_back(tmp);
            return ;
        }

        if (leftCnt > 0)
            _sub_generate_parenthesis(leftCnt - 1, rightCnt, tmp + "(", ret);

        if (rightCnt > 0)
            _sub_generate_parenthesis(leftCnt, rightCnt - 1, tmp + ")", ret);
    }
};
