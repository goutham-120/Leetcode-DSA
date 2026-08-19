// ============================================================
// Title: 155. Min Stack
// ============================================================

// Problem Statement:
// Design a stack that supports push, pop, top, and retrieving
// the minimum element in constant time.
//
// Implement the MinStack class:
//
// - MinStack() initializes the stack object.
// - void push(int value) pushes the element value onto the stack.
// - void pop() removes the element on the top of the stack.
// - int top() gets the top element of the stack.
// - int getMin() retrieves the minimum element in the stack.
//
// You must implement a solution with O(1) time complexity
// for each function.

// ============================================================
// Example 1:
// ============================================================
//
// Input:
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]
//
// Output:
// [null,null,null,null,-3,null,0,-2]
//
// Explanation:
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2

// ============================================================
// Constraints:
// ============================================================
//
// - -2^31 <= val <= 2^31 - 1
// - Methods pop, top and getMin will always be called
//   on non-empty stacks.
// - At most 3 * 10^4 calls will be made to push, pop, top,
//   and getMin.

// ============================================================
// Complexity:
// ============================================================
//
// push()   -> O(1)
// pop()    -> O(1)
// top()    -> O(1)
// getMin() -> O(1)
// Space    -> O(n)

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    // Each pair stores:
    // first  -> actual value
    // second -> minimum value in the stack up to this element
    stack<pair<int, int>> s;

    MinStack() {}

    void push(int value) {

        // If the stack is not empty, the new minimum is the
        // smaller of the current value and the previous minimum.
        if (!s.empty()) {
            s.push({value, min(value, s.top().second)});
        }
        else {
            // For the first element, the value itself is the minimum.
            s.push({value, value});
        }
    }

    void pop() {

        // Remove the top pair.
        if (!s.empty()) {
            s.pop();
        }
    }

    int top() {

        // The first element of the pair is the actual top value.
        return s.top().first;
    }

    int getMin() {

        // The second element of the pair stores the current minimum.
        return s.top().second;
    }
};

int main() {

    MinStack minStack;

    // Same operations as LeetCode Example 1.
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "getMin(): " << minStack.getMin() << endl;

    minStack.pop();

    cout << "top(): " << minStack.top() << endl;
    cout << "getMin(): " << minStack.getMin() << endl;

    return 0;
}