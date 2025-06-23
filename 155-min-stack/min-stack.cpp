class MinStack {
private:
    int size;
    int head;
    int *miniStack;
    int *minVal;

    bool isFull() {
        return head == size;
    }

    void resize() {
        int newSize = size * 2;
        int* newStack = new int[newSize];
        int* newMin = new int[newSize];

        for (int i = 0; i < size; i++) {
            newStack[i] = miniStack[i];
            newMin[i] = minVal[i];
        }

        delete[] miniStack;
        delete[] minVal;
        miniStack = newStack;
        minVal = newMin;
        size = newSize;
    }

public:
    MinStack() {
        head = 0;
        size = 10;
        miniStack = new int[size];
        minVal = new int[size];
    }

    void push(int val) {
        if (isFull()) resize();

        miniStack[head] = val;

        if (head == 0)
            minVal[head] = val;
        else
            minVal[head] = std::min(val, minVal[head - 1]);

        head++;
    }

    void pop() {
        if (head > 0) head--;
    }

    int top() {
        return miniStack[head - 1];
    }

    int getMin() {
        return minVal[head - 1];
    }
};
