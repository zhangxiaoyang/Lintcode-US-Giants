描述
ugly number是3、5、7相互组合（乘法）的一个序列，数字依次增大（不重复），第一个为2。


思路
有2个方法，分别对应于代码一和代码二。
方法一，使用的是“竞争策略”，dp[0]=1，然后让3、5、7分别去乘以dp[0]，最后3*dp[0]最小，所以竞争成功，即dp[1]=2；下一轮中，5、7去乘以dp[0]，2应该乘以dp[1]了，以此类推。需要注意代码中的if是并列的，不能用else，因为dp[i]可能对于3或5都可以进行计算得到。
方法二，使用最小堆，每次从堆里取出最小的值与3、5、7相乘，然后再放入堆中，期间需要用一个set来存放序列记录防止重复。


代码一
class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        vector<long long> dp(k + 1, 1);
        int k3 = 0, k5 = 0, k7 = 0;
        for (int i = 1; i <= k; i++) {
            dp[i] = min(min(dp[k3] * 3, dp[k5] * 5), dp[k7] * 7);
            if (dp[i] == dp[k3] * 3)
                k3++;
            if (dp[i] == dp[k5] * 5)
                k5++;
            if (dp[i] == dp[k7] * 7)
                k7++;
        }
        return dp[k];
    }
};


代码二
class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        const int factors[] = {3, 5, 7};
        priority_queue<long long, vector<long long>, greater<long long> > minHeap;
        unordered_set<long long> cache;
        minHeap.push(1);
        cache.insert(1);
        
        for (int i = 0; ; i++) {
            long long minItem = minHeap.top();
            minHeap.pop();
            if (i == k)
                return minItem;
                
            for (int j = 0; j < 3; j++) {
                long long tmp = minItem * factors[j];
                if (cache.find(tmp) == cache.end()) {
                    minHeap.push(tmp);
                    cache.insert(tmp);
                }
            }
        }
        return 0;//never be here
    }
};

