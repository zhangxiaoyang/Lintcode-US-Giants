描述
把一个字符串转换成int类型，如“-123abc“转成-123。


思路
把输入字符串看成通用形式abc123abc456，即数字的左右两侧会有非数字。依次从左到右读入字符，如果没有还没有遇到数字，就继续读入下一个字符，一旦读入数字，则继续读入数字直到遇到非数字停止。所以，abc123abc456会转换成123。还需要注意正负号，如果还没有读入数字，读入正负号则记录到flag，如果已经读入了数字，新遇到正负号则停止（此时新遇到的正负号就是非数字了，所以按照前面的规则，停止）。通过result = result*10 + str[i] - '0'来不断更新result值，最后result*flag就是转换后的值了。在不断更新result的时候，每次都要检验是否超出int的表示范围，如果超出则返回边界值。之所以要每次都要检测，是因为用long存储的结果值，如果输入的数字太大，long也溢出了。


代码
class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int intOverflow(long num) {
        if (num > INT_MAX)
            return INT_MAX;
        if (num < INT_MIN)
            return INT_MIN;
        return 0;
    }
    int atoi(string str) {
        long result = 0;
        int strLen = str.size();
        int flag = 0;
        
        for (int i = 0; i < strLen; i++) {
            if (!flag && (str[i] == '+' || str[i] == '-')) {
                if (str[i] == '+')
                    flag = 1;
                else
                    flag = -1;
            }
            else if (str[i] >= '0' && str[i] <= '9') {
                if (!flag)
                    flag = 1;
                int num = intOverflow(result * flag);
                if (num)
                    return num;
                result = result * 10 + str[i] - '0';
            }
            else if (!flag)
                continue;
            else
                break;
        }
        result *= flag;
        
        int num = intOverflow(result);
        if (num)
            return num;
        return (int)result;
    }
};

