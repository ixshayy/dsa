## 📌 Table of Contents
1. [Reverse Linked List](#1-reverse-linked-list)
2. [Linked List Cycle](#2-linked-list-cycle)
3. [Merge Two Sorted Lists](#3-merge-two-sorted-lists)
4. [Merge k Sorted Lists](#4-merge-k-sorted-lists)
5. [Remove Nth Node From End of List](#5-remove-nth-node-from-end-of-list)



# 1. Reverse Linked List

## Problem Statement

Given the head of a singly linked list, reverse the list, and return the reversed list.

### Example 1:

![Example 1](../assets/images/rev1ex1.jpg)

```plaintext
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

### Example 2:

![Example 2](../assets/images/rev1ex2.jpg)

```plaintext
Input: head = [1,2]
Output: [2,1]
```

### Example 3:

```plaintext
Input: head = []
Output: []
```

### Constraints:

- The number of nodes in the list is in the range `[0, 5000]`.
- `-5000 <= Node.val <= 5000`


## Practice
[Leetcode](https://leetcode.com/problems/reverse-linked-list/description/)


## Solution
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* back = NULL;
        ListNode* mover = head;
        ListNode* front = NULL;

        while(mover){
            front = mover->next;
            mover->next = back;
            back = mover;
            mover = front;
        }

        return back;
    }
};
```

### Complexity Analysis:
- **Time Complexity:** `O(n)`, where `n` is the number of nodes in the linked list. We traverse the list once.
- **Space Complexity:** `O(1)`, as we use only a few extra pointers.


[🔼 Back to Top](#-table-of-contents)

# 2. Linked List Cycle

## Problem Statement

Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that the tail's `next` pointer is connected to. Note that `pos` is not passed as a parameter.

Return `true` if there is a cycle in the linked list. Otherwise, return `false`.

---

## Example 1:

![Example 1](../assets/images/circularlinkedlist.png)

```plaintext
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```

## Example 2:

![Example 2](../assets/images/circularlinkedlist_test2.png)

```plaintext
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
```

## Example 3:

![Example 3](../assets/images/circularlinkedlist_test3.png)

```plaintext
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
```

---

## Constraints:

- The number of nodes in the list is in the range `[0, 10^4]`.
- `-10^5 <= Node.val <= 10^5`
- `pos` is `-1` or a valid index in the linked list.

---

## Practice
[Leetcode](https://leetcode.com/problems/linked-list-cycle/)


## Solution

### Floyd's Cycle Detection Algorithm (Two Pointers Method)

**Intuition:**
- Use two pointers, `slow` and `fast`. `slow` moves one step at a time, while `fast` moves two steps.
- If there is a cycle, `slow` and `fast` will eventually meet.
- If `fast` reaches the end (`NULL`), there is no cycle.

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) return true;
        }
        
        return false;
    }
};
```

### Complexity Analysis:

- **Time Complexity:** `O(n)`, where `n` is the number of nodes in the linked list.
- **Space Complexity:** `O(1)`, as no extra space is used.

---

[🔼 Back to Top](#-table-of-contents)



# 3. Merge Two Sorted Lists

## Problem Statement
You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

## Examples

### Example 1:
![Example 1](../assets/images/merge_ex1.jpg)

**Input:**
```
list1 = [1,2,4], list2 = [1,3,4]
```
**Output:**
```
[1,1,2,3,4,4]
```

### Example 2:
**Input:**
```
list1 = [], list2 = []
```
**Output:**
```
[]
```

### Example 3:
**Input:**
```
list1 = [], list2 = [0]
```
**Output:**
```
[0]
```

## Constraints
- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `list1` and `list2` are sorted in non-decreasing order.


## Practice
[Leetcode](https://leetcode.com/problems/merge-two-sorted-lists/description/).

## Solution
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* head = new ListNode();
        ListNode* mover = head;

        while(curr1 != NULL && curr2 != NULL ){
            if(curr1->val <= curr2->val){
                ListNode* node = new ListNode(curr1->val);
                mover->next = node;
                curr1 = curr1->next;
            }else{
                ListNode* node = new ListNode(curr2->val);
                mover->next = node;
                curr2 = curr2->next;
            }
            mover = mover->next;
        }

        while(curr1 != NULL){
            ListNode* node = new ListNode(curr1->val);
            mover->next = node;
            curr1 = curr1->next;
            mover = mover->next;
        }

        while(curr2 != NULL){
            ListNode* node = new ListNode(curr2->val);
            mover->next = node;
            curr2 = curr2->next;
            mover = mover->next;
        }

        return head->next;
    }
};
```


[🔼 Back to Top](#-table-of-contents)



# 4. Merge k Sorted Lists

## Problem Statement
You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

## Example 1

**Input:**
```plaintext
lists = [[1,4,5],[1,3,4],[2,6]]
```

**Output:**
```plaintext
[1,1,2,3,4,4,5,6]
```

**Explanation:**
The linked-lists are:
```
[
  1->4->5,
  1->3->4,
  2->6
]
```
Merging them results in:
```
1->1->2->3->4->4->5->6
```

## Example 2

**Input:**
```plaintext
lists = []
```

**Output:**
```plaintext
[]
```

## Example 3

**Input:**
```plaintext
lists = [[]]
```

**Output:**
```plaintext
[]
```

## Constraints
- `k == lists.length`
- `0 <= k <= 10^4`
- `0 <= lists[i].length <= 500`
- `-10^4 <= lists[i][j] <= 10^4`
- `lists[i]` is sorted in ascending order.
- The sum of `lists[i].length` will not exceed `10^4`.

## Practice
[Leetcode](https://leetcode.com/problems/merge-k-sorted-lists/description/).


## Solution
We can solve this problem efficiently using a **Min Heap (Priority Queue)**. The idea is to always extract the smallest node from the heap and append it to the merged list. If the extracted node has a next node, push it into the heap.

```cpp
#include <queue>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

       for(int i = 0 ; i < lists.size() ; i++){
            if(lists[i]){
                pq.push({lists[i]->val, lists[i]});
            }
       }

        ListNode* ans = new ListNode();
        ListNode* mover = ans;
       while(!pq.empty()){
            int val = pq.top().first;
            ListNode* node = pq.top().second;
            pq.pop();
            
            ListNode* temp = new ListNode(val);
            mover->next = temp;
            mover = mover->next;

            if(node->next){
                pq.push({node->next->val, node->next});
            }
       }

       return ans->next;
    }
};
```

## Complexity Analysis
- **Heap Operations:** Each node is inserted and removed from the priority queue exactly once. This takes **O(log k)** time per operation.
- **Total Nodes:** There are at most **N** total nodes across all linked lists.
- **Overall Complexity:** Since each insertion and removal operation in the heap takes **O(log k)** time, and there are **N** total operations, the total time complexity is **O(N log k)**.


[🔼 Back to Top](#-table-of-contents)


# 5. Remove Nth Node From End of List

## Problem Statement
Given the head of a linked list, remove the nth node from the end of the list and return its head.

## Examples

### Example 1:
![Example 1](../assets/images/remove_ex1.jpg)

**Input:**
```plaintext
head = [1,2,3,4,5], n = 2
```
**Output:**
```plaintext
[1,2,3,5]
```

### Example 2:
**Input:**
```plaintext
head = [1], n = 1
```
**Output:**
```plaintext
[]
```

### Example 3:
**Input:**
```plaintext
head = [1,2], n = 1
```
**Output:**
```plaintext
[1]
```

## Constraints:
- The number of nodes in the list is `sz`.
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`



## Practice
[Leetcode](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)


## Solution

### Approach:
- Use a two-pointer approach where one pointer moves `n` steps ahead.
- Move both pointers one step at a time until the fast pointer reaches the end.
- Remove the nth node by adjusting pointers.

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;

        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        // If fast is NULL, we need to remove the head node
        if(fast == NULL) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};
```

[🔼 Back to Top](#-table-of-contents)


# 143. Reorder List

## Problem Statement
You are given the head of a singly linked list. The list can be represented as:

```
L0 → L1 → … → Ln - 1 → Ln
```

Reorder the list to the following form:

```
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
```

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

---

## Examples

### Example 1:
![Example 1](../assets/images/reorder1linked-list.jpg)

**Input:** `head = [1,2,3,4]`

**Output:** `[1,4,2,3]`

### Example 2:
![Example 2](../assets/images/reorder2-linked-list.jpg)

**Input:** `head = [1,2,3,4,5]`

**Output:** `[1,5,2,4,3]`

---

## Constraints
- The number of nodes in the list is in the range `[1, 5 * 10^4]`.
- `1 <= Node.val <= 1000`

---



## Practice
[Leetcode](https://leetcode.com/problems/reorder-list/description/)

## Solution

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* back = NULL;
        ListNode* curr = head;
        ListNode* front = NULL;

        while (curr != NULL) {
            front = curr->next;
            curr->next = back;
            back = curr;
            curr = front;
        }

        return back;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle node
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revHalfHead = reverseList(slow->next);
        slow->next = nullptr;  // Break the link to avoid a cycle

        ListNode* mover = head;

        while (mover != NULL && revHalfHead != NULL) {
            ListNode* tempMover = mover->next;
            ListNode* tempRevHead = revHalfHead->next;

            mover->next = revHalfHead;
            revHalfHead->next = tempMover;

            mover = tempMover;
            revHalfHead = tempRevHead;
        }
    }
};
```



[🔼 Back to Top](#-table-of-contents)

