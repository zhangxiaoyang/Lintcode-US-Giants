描述
给定一个数字数组，将其元素重新排序使得构成的数字最大。例如，[1, 20, 23, 4, 8]组成的最大数字是8423201。


思路
贪心的选择最大的数字放到高位，比如描述中的例子，8放在首位。还需要考虑，如3,32,30中，哪个数字应该放在前面？应该是3，因为332构成的最大。可以修改排序的compare函数，compare(int a, int b)，如果“ab”这个数字大于“ba”这个数字，那么就返回true，即a排到前面。“


代码
class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), compare);
        string result;
        for (int i = 0; i < num.size(); i++) {
            if (!result.size() && num[i] == 0 && i != num.size() - 1)
                continue;
            result += to_string(num[i]);
        }
        return result;
    }
    struct {
        bool operator()(int a, int b) {
            return a * pow(10, to_string(b).size()) + b > b * pow(10, to_string(a).size()) + a
                ? true : false;
        }
    } compare;
};

