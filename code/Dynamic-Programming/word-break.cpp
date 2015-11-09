描述
给一个字符串，和一个字典，判断该字符串能否由字典的字符串组合而成。


思路
dp[i] = dp[j] && s.substr(k, i - k) in dict。其中，dp[i]表示前i个字符是否能由dict中的字符串组成，也就是s[0~i-1]，所以dp[0~N]有N+1个元素，dp[0]用于初始化，在这里dp[0]该初始化成几呢？dp[1] = dp[0] && s.substr(..) in dict。所以，dp[0] = true，如果是false，dp[1]就不对了。这个思路会超时，主要是因为2重循环。
然后就有了第二种方法，即代码二。不同之处是，在内层循环，对dict进行遍历，这样会减少无用功，原来可是一个字符一个字符的尝试，现在是按照dict中字符串的长度进行尝试，明显提高了命中率。


代码一（超时）
class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
      
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = dp[j] && dict.find(s.substr(j, i - j)) != dict.end();
                if (dp[i])
                    break;
            }
        }
        return dp[n];
    }
};


代码二
class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
      
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i <= n; i++) {
            if (dp[i]) {
                for (unordered_set<string>::iterator j = dict.begin(); j != dict.end(); j++) {
                    if (dict.find(s.substr(i, (*j).size())) != dict.end())
                        dp[i + (*j).size()] = true;
                }
            }
        }
        return dp[n];
    }
};

