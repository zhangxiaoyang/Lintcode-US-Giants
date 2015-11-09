描述
同word ladder，将start转换成end，只能使用dict的词进行转换，且每次转换只能改变一个字母。求最少转换次数下的所有可能的转换。


思路
直接用bfs只能求出最短的路径，但是不能求出所有的路径。原来的策略是，每次转换到一个新的词，就把这个词从dict中删掉，这里是不可行的，因为这个词可能在另一个转换路径上出现。但是可以肯定，这个词只能在这一层使用，在下一层使用肯定会使转换次数变多。所以，在一层bfs完成后，统一对所有使用的词进行删除。还需要一个found变量记录，一旦找到start == end，则就不再继续进行下一层。还有一个问题是，要将所有的路径存储下来，存储使用unordered_map<string, unordered_set<string> > paths; key存储下一个结点，value存储可以到达key的所有结点。最后对paths进行dfs，可以还原出所有路径到vector。为了方便dfs，之前的bfs从end找start，而不是从start找end。


代码
class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, unordered_set<string> > paths;
        queue<string> cache;
        bool found = false;
        cache.push(end);

        while (!cache.empty()) {
            vector<string> tmp;
            while (!cache.empty()) {
                string str = cache.front();
                cache.pop();
                
                if (str == start)
                    found = true;
                tmp.push_back(str);
            }
            
            if (found)
                break;
            else {
                for (int i = 0; i < tmp.size(); i++) {
                    dict.erase(tmp[i]);
                }
                for (int i = 0; i < tmp.size(); i++) {
                    string str = tmp[i];
                    vector<string> strs = genStrs(dict, str);
                    for (int j = 0; j < strs.size(); j++) {
                        paths[strs[j]].insert(str);
                        cache.push(strs[j]);
                    }
                }
            }
        }

        vector<vector<string> > result;
        vector<string> item;
        item.push_back(start);
        dfs(item, start, end, paths, result);
        return result;
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
    
    void dfs(vector<string>& item, string start, string end, unordered_map<string, unordered_set<string> >& paths, vector<vector<string> >& result) {
        if (start == end) {
            result.push_back(item);
            return;
        }
            
        for (unordered_set<string>::iterator i = paths[start].begin(); i != paths[start].end(); i++) {
            item.push_back(*i);
            dfs(item, *i, end, paths, result);
            item.pop_back();
        }
    }
};

