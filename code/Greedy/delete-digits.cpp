描述
从一个字符串（数字构成）中删除指定个字符，使得删除后的字符串所表示的数字最小。例如，178542删除4个字符，最小的字符串是12。


思路
设删除k个字符，则做k次循环，每次循环从字符串中选择一个字符删除掉。删除的规则是，从字符串头部开始找，找到一个A[i] > A[i + 1]，则删除A[i]，找不到的话，则删除A[A.size() - 1]，即最后一个字符。


代码
class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        string result = A;
        for (int i = 0; i < k; i++) {
            removeDigit(result);
        }
        for (int i = 0; i < result.size() - 1; i++) {
            if (result[i] != '0')
                return result.substr(i, result.size() - i);
        }
        return result;        
    }
    
    void removeDigit(string& A) {
        for (int i = 0; i < A.size() - 1; i++) {
            if (A[i] > A[i + 1]) {
                A.erase(i, 1);
                return;
            }
        }
        A.erase(A.size() - 1, 1);
    }
};

