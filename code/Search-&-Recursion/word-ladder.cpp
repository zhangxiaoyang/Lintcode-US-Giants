描述
start = "hit", end = "cog", dict = ["hot","dot","dog","lot","log"]。计算从start变成end最少需要几次，每次变化只能改变一个字母且变化后的词在dict中出现。对于这个例子，"hit" -> "hot" -> "dot" -> "dog" -> "cog"，一共是5次。


思路
一看到最少、最短，就要立马想到bfs。这里是从start开始，使用genStrs产生可以变化的下一层结点，然后再对每个结点产生下层结点，只能某层的某结点等于end为止。需要注意，在产生了某个结点后，要从dict中删除掉他，要不然某个结点（比如很下层的）可能还会产生这个结点，就不是最长的了。


代码
class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> cache;
        cache.push(start);
        int distance = 1;
        
        while (!cache.empty()) {
            int count = cache.size();
            for (int i = 0; i < count; i++) {
                string str = cache.front();
                cache.pop();
                if (str == end)
                    return distance;
                    
                vector<string> strs = genStrs(dict, str);
                for (int i = 0; i < strs.size(); i++) {
                    cache.push(strs[i]);
                    dict.erase(strs[i]);
                }
            }
                
            distance++;
        }
        return 0;
    }
    
    vector<string> genStrs(unordered_set<string>& dict, string& str) {
        vector<string> strs;
        for (int i = 0; i < str.size(); i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                string s = str;
                s[i] = ch;
                if (s != str && dict.find(s) != dict.end())
                    strs.push_back(s);
            }
        }
        return strs;
    }
};

