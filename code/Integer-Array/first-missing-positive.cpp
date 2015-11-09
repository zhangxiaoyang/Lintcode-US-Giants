描述
找到数组中第一个缺失的正数，比如{3,2,3}缺失了1，{1,2,3}缺失了4。


思路
最直观的想法是排序，然后找。但是，题目要求使用O(n)时间，常数空间。思路是，我们把数放到他们应该在的地方，比如1放到0的位置，5放到4的位置，这样放好以后，就可以遍历一次找到不对的那个数，这样就找到了缺失的正数了。还要注意的是，我们只交换符合要求的数，不符合要求的数跳过，如果他们运气好，后面可能会被其他的数交换，如果运气不好，就呆在那个位置了。所谓的符合要求是指1~N之间的数，N是数组的长度，并且还要判断，如果在某个位置已经放对了一个数了，后面又遇到了一次这个数，此时的做法是不交换。


代码
class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        int ALen = A.size();
        int i = 0;
        while (i < ALen) {
            if (A[i] != (i + 1) && A[i] >= 1 && A[i] <= ALen && A[i] != A[A[i] - 1])
                swap(A[i], A[A[i] - 1]);
            else
                i++;
        }
        
        int result = ALen + 1;
        for (int i = 0; i < ALen; i++) {
            if (A[i] != (i + 1)) {
                result = i + 1;
                break;
            }
        }
        return result;
    }
};

