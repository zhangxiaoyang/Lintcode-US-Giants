描述
有一个vector，里面存放的是若干个字符串，现在需要把里面的anagrams字符串找出来。比如，["ab", "ba", "cd", "dc", "e]，最后需要得到["ab", "ba", "cd", "dc"]，顺序无所谓。需要注意的是，所谓的anagrams字符串，一定是有2个或2个以上的，要不然你和谁anagrams啊，是吧？


思路
需要用一个map，来存储每个字符串出现的位置，字符串是排序好的，这一来了下一个字符串也sort一下，就可以看看map中有没有了。之所以记录位置，是因为map的key已经是排序的了，原来的字符串只能通过位置去输入的vector中取。总的时间是O(n2logn)，如果不用排序，就可以降到O(n2)了。能想到的方法是对每一个字符串做一个hash，map存储的是hash->位置。问题是，如何计算hash呢，使得hash(abc) = hash(bca)？


代码
class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        int strsLen = strs.size();
        vector<string> result;
        map<string, int> cache;
        
        for (int i = 0; i < strsLen; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (cache.find(s) == cache.end()) {
                cache[s] = i;
            }
            else {
                if (cache[s] >= 0) {
                    result.push_back(strs[cache[s]]);
                    cache[s] = -1;
                }
                result.push_back(strs[i]);   
            }
        }
        return result;
    }
};

