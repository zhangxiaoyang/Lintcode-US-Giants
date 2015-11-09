描述
有2个字符串source和target，返回target在source中出现的下标位置。如皋不存在，则返回-1。


思路
KMP可以很好的解决这个问题，这里用最暴力的O(n2)算法解决。需要注意的是，source和target可能是NULL，这个不代表字符串是“”。所以，有NULL就返回-1。


代码
class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (source == NULL || target == NULL)
            return -1;
            
        int sLen = strlen(source);
        int tLen = strlen(target);
        if (tLen > sLen)
            return -1;
            
        for (int i = 0; i < sLen - tLen + 1; i++) {
            if (strncmp(&source[i], &target[0], tLen) == 0)
                return i;
        }
        return -1;
    }
};

