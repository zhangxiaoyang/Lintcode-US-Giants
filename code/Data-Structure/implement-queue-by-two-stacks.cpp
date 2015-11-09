描述
使用2个栈实现队列。


思路
使用stack1和stack2，所有的push操作入stack1。如果pop，则将stack1的元素pop出并依次入stack2，然后再从stack2中pop。这里需要判断一下，如果stack2不空，则无需从stack1中pop，直接把stack2的pop出即可。


代码
class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
    }

    void push(int element) {
        stack1.push(element);
    }

    int getTopFromDummyQueue() {
        int value;
        if (!stack2.empty()) {
            value = stack2.top();
        }
        else {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            value = stack2.top();
        }
        return value;
    }    
    
    int pop() {
        int value = getTopFromDummyQueue();
        stack2.pop();
        return value;
    }

    int top() {
        return getTopFromDummyQueue();
    }
};

