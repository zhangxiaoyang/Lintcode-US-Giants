描述
有2个字符串A和B（由大写字母组成），判断B中的字符是不是都在A中。比如，abcd、ac，这个都在。注意，需要考虑数目，比如abcd、aac，就不在了，因为B有2个a，而A有1个a。


思路
因为A和B由大写字母组成，可以设置一个int chars[26] = {0}，和anagram类似。然后，遍历A和B，出现在A的字符则++，出现在B的字符则--。最后，遍历chars，看有没有元素小于0，如果有说明B中有字符不存在A中，否则说明B中的字符都在A中。


代码
class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        int chars[26] = {0};
        
        int ALen = A.size();
        int BLen = B.size();
        int len = ALen > BLen ? ALen : BLen;
        
        for (int i = 0; i < len; i++) {
            i < ALen && chars[A[i] - 'A']++;
            i < BLen && chars[B[i] - 'A']--;
        }
        for (int i = 0; i < 26; i++) {
            if(chars[i] < 0)
                return false;
        }
        return true;
    }
};

