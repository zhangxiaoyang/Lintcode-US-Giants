描述
给定一个数组，从中找3个元素使得和为0，把符合这个要求的三元组都找出来（不可重复）。


思路
还是先排序O(nlogn)，然后使用一个i变量进行一层变量。内层使用j和k，j=i+1、k=N-1，夹逼。如果遇到了和为0的情况，就把结果存起来。到这里应该没啥问题了。关键问题是，如果有重复的三元组怎么办。方法是，对
i、j、k，每次进行一轮循环时，都判断下i-1、j-1、k+1存的值和当前的值是不是一样，一样的话就不进行深入的判断了，直接i++、j++、k--。


代码
class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > result;
        int numsLen = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < numsLen; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
                
            int j = i + 1;
            int k = numsLen - 1;
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                if (k < numsLen - 1 && nums[k] == nums[k + 1]) {
                    k--;
                    continue;
                }
                    
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    result.push_back(tmp);
                }
                
                if (sum <= 0)
                    j++;
                else
                    k--;
            }
        }
        return result;
    }
};

