描述
有一个环形路线，其中有N个加油站。从加油站i到加油站i+1需要耗费cost[i]，加油站i可以提供gas[i]的油。从N个加油站中选择一个作为起始点，使得可以走完整个环形路线。


思路
因为每个加油站提供的油有多有少，所以有可能从某个加油站往下一处行驶时油不够，所以就需要之前存下的油（剩下的油）。有2个规律：1. 如果sum(gas[i]) - sum(cost[i]) >= 0，说明从某个加油站出发，可以走完一圈，否则走不完；2. 如果从某个加油站i出发，到达不了j，因为油不够，则从i～j出发也可能到达不了j，因为从i走是可以存一点油的，都到不了j，从i～j之间就更到不了了。


代码
class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int count = gas.size();
        int surplus = 0;
        int index = 0;
        int total = 0;
        for (int i = 0; i < count; i++) {
            total += gas[i] - cost[i];
            surplus += gas[i] - cost[i];
            if (surplus < 0) {
                surplus = 0;
                index = i + 1;
            }
        }
        return total >= 0 ? index : -1;
    }
};

