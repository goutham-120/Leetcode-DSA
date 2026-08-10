// 141. Linked List Cycle

// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

 

// Example 1:


// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
// Example 2:


// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
// Example 3:


// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.
 

// Constraints:

// The number of the nodes in the list is in the range [0, 104].
// -105 <= Node.val <= 105
// pos is -1 or a valid index in the linked-list.
 

// Follow up: Can you solve it using O(1) (i.e. constant) memory?

//code:
#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool hasCycle(ListNode* head) {

        // slow moves one step at a time
        // fast moves two steps at a time
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            // If they meet, a cycle exists
            if (slow == fast)
                return true;
        }

        // fast reached the end, so there is no cycle
        return false;
    }
};
int main() {
    Solution solution;
    // Create a linked list with a cycle for testing
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Create a cycle

    bool result = solution.hasCycle(head);
    cout << "Does the linked list have a cycle? " << (result ? "Yes" : "No") << endl;

    // Clean up memory (not shown here, but should be done in practice)
    return 0;
}

//note: after both pointers  enter the cycle, they will meet at some point within the cycle. The distance between the two pointers will decrease by one step in each iteration, so they will eventually meet.