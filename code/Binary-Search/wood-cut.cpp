描述
有若干个木块，需要对这些木块进行切割。最终得到若干个长度相同的木块。要求：最终得到的长度相同的木块的长度最长，并且木块个数要大于等于指定的k。


思路
很难直接想到二分查找。题目最终使用二分查找，遍历的区域是1~max(L[N])，为啥不从0开始呢？因为，是要从遍历的区域中二分查找，选出来的数作为“相同木块的长度”，所以从0开始就可能得到length=0，进而在用L[i]/length时出错。通过设置一个全局变量result，记录当前符合要求(>=k)的最大长度。还有一个需要注意的地方，应该使用long存储，尽管传参是int，因为在(left + right)/2可能会溢出，比如left=INT_MAX，right=INT_MAX。long x = (left+right)/2；依然会得到错误的结果，因为在给long赋值时，left+right已经溢出了。所以要用long存储，而不是int。


代码
class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int max(vector<int> v) {
        int _max = 0;
        for (int i = 0; i < v.size(); i++)
            if (v[i] > _max)
                _max = v[i];
        return _max;
    }
    int woodCut(vector<int> L, int k) {
        long left = 1;
        long right = max(L);
        long result = 0;
        while (left <= right) {
            long length = (left + right) / 2;
            int _k = 0;
            for (int i = 0; i < L.size(); i++) {
                _k += L[i] / length;   
            }
            if (_k >= k && length > result)
                result = length;
                
            if (_k < k)
                right = length - 1;
            else
                left = length + 1;
        }
        return result;
    }
};

