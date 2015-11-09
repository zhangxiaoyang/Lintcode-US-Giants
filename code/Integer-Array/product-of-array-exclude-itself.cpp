描述
给定一个数组，如A={1,2,3}，返回B={6,3,2}，计算规则是：非当前下标的其它元素之积，对于A[0]，对应的B[0]=A[1]*A[2]=6。不能在计算中使用除法（如果可以使用，先全部求一下积，然后计算每个元素的时候，除以当前对应的A中元素即可）


思路
使用2个数组，分别为left[N]和right[N]，left[i]表示第i个元素左边其它元素之积，right[i]同理。先通过一次遍历，填充left、right。最后再一次遍历，使用B[i]=left[i]*right[i]。需要注意的是，left和right的计算规律及left和right初始的每一个元素要置为1。


代码
class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        int numsLen = nums.size();
        vector<long long> left(numsLen, 1);
        vector<long long> right(numsLen, 1);
        vector<long long> result(numsLen, 1);
        for (int i = 1; i < numsLen; i++) {
            left[i] = left[i - 1] * nums[i - 1];
            right[numsLen - i - 1] = right[numsLen -i] * nums[numsLen - i];
        }
        for (int i = 0; i < numsLen; i++) {
            result[i] = left[i] * right[i];
        }
        return result;
    }
};

