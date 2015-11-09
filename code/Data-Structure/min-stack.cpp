描述
实现一个有min操作的栈，即可以获得栈中最小的元素。


思路
使用realStack和minStack分别为真实的栈和存放最小值的栈。每次push，都直接push到realStack，如果number比minStack的栈顶小或相等，则也push到minStack（如果minStack为空也push进去）。pop的时候，realStack直接pop，然后判断pop出的元素与minStack栈顶是否相等，相等则也pop。这里需要注意，push到minStack的条件，等于minStack栈顶的时候也要push，因为可能会push一堆相同的数字，如果只在minStack存一个的话，pop的时候就不好办了。


代码
class MinStack {
public:
    stack<int> realStack;
    stack<int> minStack;
    
    MinStack() {
    }

    void push(int number) {
        realStack.push(number);
        if (minStack.empty() || minStack.top() >= number)
            minStack.push(number);
    }

    int pop() {
        int value = realStack.top();
        realStack.pop();
        if (value == minStack.top())
            minStack.pop();
        return value;
    }

    int min() {
        return minStack.top();
    }
};

