描述
不断读入数字，求截止到当前数字的中位数。


思路
使用2个堆，最大堆存放前排序后的n/2的数字，最小堆存放n/2后的数字。对于奇数个数字，最大堆则多存储一个。为了保证这个存放规则，所有来的数字，如果比maxHeap的堆顶小，则放到大堆，否则放到小堆，然后判断大堆和小堆的存放数目，看需不需要调整。如果大堆的数字多了，就取堆顶元素放到小堆，小堆同理。


代码
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        vector<int> result;
        int n = nums.size();
        if (n == 0)
            return result;
            
        priority_queue<int, vector<int> > maxHeap;
        priority_queue<int, vector<int>, greater<int> > minHeap;
        
        maxHeap.push(nums[0]);
        result.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] < maxHeap.top())
                maxHeap.push(nums[i]);
            else
                minHeap.push(nums[i]);
            
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            result.push_back(maxHeap.top());
        }
        return result;
    }
};

