// implement stack
#include<bits/stdc++.h>
#include<vector>

using namespace std;

// max size say 1000
class Istack {
    vector<int> st;
    int stackSize,stackSum;
    vector<int> incrementTracker;
    public:
        Istack() {
            stackSum = 0;
            st.resize(1001,0);
            incrementTracker.resize(1001,0);
        }
        void insert(int num) {
            stackSize++;
            st[stackSize] = num;
            stackSum += num;
        }

        int pop() {
            int ret = incrementTracker[stackSize] ? st[stackSize] + incrementTracker[stackSize] : st[stackSize];
            stackSum -= ret;
            if(stackSize > 0) incrementTracker[stackSize-1] = incrementTracker[stackSize];
            incrementTracker[stackSize] = 0;
            stackSize--;
            return ret;
        }

        int sum() {
            return stackSum;
        }

        void increase(int x,int k) {
            incrementTracker[x] = k;
            stackSum += (x*k);
        }
};

int main() {
    Istack *stack = new Istack();
    stack->insert(10);
    stack->insert(20);
    cout << stack->sum() << endl;
    cout << stack->pop() << endl;
    stack->increase(1,5);
    cout << stack->sum() << endl;
    return 0;
}