描述
有一个vector，里面存储了若干个string，计算这些string的最长前缀。


思路
两层循环，第一层变化前缀的下标，第二层遍历所有字符串在该下标下是否是相等的。


代码
class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        int strsLen = strs.size();
        if (!strsLen)
            return "";
            
        string result;
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 0; j < strsLen; j++) {
                if (strs[j][i] != strs[0][i])
                    return result;
            }
            result += strs[0][i];
        }
        return result;
    }
};

