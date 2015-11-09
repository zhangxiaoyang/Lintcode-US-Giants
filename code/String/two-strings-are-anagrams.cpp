描述
有两个字符串s和t，判断s和t是否为anagram。anagram是说s中的字符和t中字符一样多且字符字符所属的集合一样。比如：abcd、dcab，比如aabc、baca。


思路
O(n)时间，O(1)空间。先用一个数组int chars[UCHAR_MAX+1]存每个字符出现的个数，默认是0。一次遍历，遍历s的长度（即t的长度），把chars[s[i]]++，chars[t[i]]--。最后，再来一次遍历，此次遍历的是chars，看是不是每个元素都是0。


代码
class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        int chars[UCHAR_MAX + 1] = {0};
        int sLen = s.size();
        int tLen = t.size();
        
        if (sLen != tLen)
            return false;
            
        for (int i = 0; i < sLen; i++) {
            chars[(unsigned char)s[i]]++;
            chars[(unsigned char)t[i]]--;
        }
        for (int i = 0; i < UCHAR_MAX + 1; i++) {
            if (chars[i])
                return false;
        }
        return true;
    }
};

