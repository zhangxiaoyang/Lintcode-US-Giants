描述
直方图中的最大矩形。


思路
可以观察到一个特性，即如果height[i]比height[i - 1]大，则i - 1的位置肯定不是矩形的右端点。即，当height[i] > height[i - 1]的时候，就会不断遍历左端点，选一个max。具体为使用一个栈来存储左侧的所有下标，不断pop然后计算。需要给height.push_back(-1)，否则的话[1,2,3]这样的case就没法算了。


代码
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> height) {
        if (height.size() == 0)
            return 0;
            
        stack<int> cache;
        height.push_back(-1);
        int maxArea = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!cache.empty() && height[i] <= height[cache.top()]) {
                int h = height[cache.top()];
                cache.pop();
                maxArea = cache.size() != 0
                    ? max(maxArea, (i - cache.top() - 1) * h)
                    : max(maxArea, i * h);
            }
            cache.push(i);
        }
        return maxArea;
    }
};

