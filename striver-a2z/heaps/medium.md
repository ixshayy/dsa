## 📌 Table of Contents
1. [Kth Largest Element in an Array](#1-kth-largest-element-in-an-array)
2. [Merge k Sorted Arrays](#2-merge-k-sorted-arrays)
3. [Hand of Straights](#3-hand-of-straights)
4. [Task Scheduler](#4-task-scheduler)
5. [Top K Frequent Elements](#5-top-k-frequent-elements)


# 1. Kth Largest Element in an Array

## **Problem Statement**
Given an integer array `nums` and an integer `k`, return the **kth largest element** in the array.

💡 **Note:**  
- The **kth largest** element means the element that would be at index `n - k` in the **sorted** array.
- The **kth largest** is not necessarily the **kth distinct** element.
- You should solve it **without sorting**.

---

## **Examples**

### **Example 1**
**Input:**  
```cpp
nums = [3,2,1,5,6,4], k = 2
```
**Output:**  
```
5
```
**Explanation:**  
If sorted: `[1, 2, 3, 4, 5, 6]`, the **2nd largest** element is **5**.

---

### **Example 2**
**Input:**  
```cpp
nums = [3,2,3,1,2,4,5,5,6], k = 4
```
**Output:**  
```
4
```
**Explanation:**  
If sorted: `[1, 2, 2, 3, 3, 4, 5, 5, 6]`, the **4th largest** element is **4**.

---

## **Constraints**
- `1 <= k <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

---

## **Intuition**
To find the **kth largest element**, the simplest approach is sorting the array and picking the `n-k` indexed element.  
However, sorting takes **O(n log n)** time, which is inefficient for large inputs.

Instead, we can use a **Min Heap (Priority Queue)** to efficiently track the `k` largest elements.

---

### **Efficient Approach (Min Heap)**
1. Use a **Min Heap** of size `k` (stores only the `k` largest elements).
2. Traverse the array:
   - Insert each element into the heap.
   - If the heap size exceeds `k`, **remove the smallest element**.
3. The **top element** of the heap is the `kth largest` element.


## Practice
[Leetcode](https://leetcode.com/problems/kth-largest-element-in-an-array/)


## **Code Implementation**
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop();  // Remove smallest element if size > k
        }

        return minHeap.top();  // The kth largest element
    }
};
```

---

## **Time & Space Complexity**
| Approach | Time Complexity | Space Complexity | Notes |
|----------|----------------|------------------|-------|
| **Sorting** | `O(n log n)` | `O(1)` | Not optimal |
| **Min Heap** | `O(n log k)` | `O(k)` | Efficient |

- **Heap operations (`push` and `pop`)** take **O(log k)** time.
- Since we process `n` elements, total time complexity is **O(n log k)**.
- Space complexity is **O(k)** since we store `k` elements in the heap.


[🔼 Back to Top](#-table-of-contents)


# 2. Merge k Sorted Arrays

## **Problem Statement**
Given `k` sorted arrays arranged in the form of a matrix of size `k * k`, the task is to **merge them into one sorted array**.

- **Return Type:**
  - C++: Pointer to the merged sorted array.
  - Java: `ArrayList`
  - Python: `list`

---

## **Examples**

### **Example 1**
**Input:**  
```cpp
k = 3
arr[][] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
}
```
**Output:**  
```
1 2 3 4 5 6 7 8 9
```
**Explanation:**  
Each row is already sorted. Merging all rows results in `[1, 2, 3, 4, 5, 6, 7, 8, 9]`.

---

### **Example 2**
**Input:**  
```cpp
k = 4
arr[][] = {
    {1, 2, 3, 4},
    {2, 2, 3, 4},
    {5, 5, 6, 6},
    {7, 8, 9, 9}
}
```
**Output:**  
```
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9
```
**Explanation:**  
Merging all rows results in `[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9]`.

---

## **Constraints**
- `1 <= k <= 100`
- Each row is already **sorted in ascending order**.


## **Intuition**
Since all rows are already sorted, we can efficiently merge them using a **Min Heap (Priority Queue)**.

### **Efficient Approach (Min Heap)**
1. Use a **Min Heap** to store elements from each row.
2. Traverse the entire matrix and **push all elements into the heap**.
3. Extract elements one by one to **get a sorted array**.

✅ **Why Min Heap?**  
- The smallest element is always at the **top** of the heap.
- Extracting elements in order gives a **sorted** merged array.

---

## **Practice**
[GFG](https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1)

---

## **Code Implementation**
```cpp
class Solution {
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                pq.push(arr[i][j]);
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};
```

---

## **Time & Space Complexity**
| Approach | Time Complexity | Space Complexity | Notes |
|----------|----------------|------------------|-------|
| **Naïve (Merging one by one)** | `O(k^2 log k^2)` | `O(k^2)` | Slow for large `k` |
| **Min Heap (Optimal)** | `O(k^2 log k)` | `O(k^2)` | Efficient |

- **Heap operations (`push` and `pop`)** take **O(log k)** time.
- Since we process `k^2` elements, total time complexity is **O(k^2 log k)**.
- Space complexity is **O(k^2)** since we store all elements.



[🔼 Back to Top](#-table-of-contents)


Here’s the `README.md` file for the **Hand of Straights** problem:

---

# 3. Hand of Straights

## **Problem Statement**
Alice has some number of cards and wants to **rearrange them into groups** where:
1. Each group consists of **`groupSize`** cards.
2. Each group contains **consecutive** card values.

Given an integer array `hand` where `hand[i]` represents the value on the `i`-th card, and an integer `groupSize`, return:
- `true` if Alice **can** rearrange the cards into valid groups.
- `false` otherwise.

---

## **Examples**

### **Example 1**
**Input:**  
```cpp
hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
```
**Output:**  
```cpp
true
```
**Explanation:**  
Alice's hand can be rearranged into the following valid groups:  
```
[1,2,3], [2,3,4], [6,7,8]
```

---

### **Example 2**
**Input:**  
```cpp
hand = [1,2,3,4,5], groupSize = 4
```
**Output:**  
```cpp
false
```
**Explanation:**  
It's **impossible** to form groups of size `4`.

---

## **Constraints**
- `1 <= hand.length <= 10^4`
- `0 <= hand[i] <= 10^9`
- `1 <= groupSize <= hand.length`

---

## **Approach**
### **Intuition**
- Since each group must be **consecutive**, we need to check if we can pick `groupSize` consecutive numbers **greedily**.
- The **smallest available card** must always be part of a valid group.
- Use **Min Heap** (Priority Queue) to track the smallest card available.

---

## **Efficient Approach (Min Heap + Hash Map)**
### **Steps:**
1. **Count occurrences** of each card using a **hash map (`unordered_map`)**.
2. **Push unique card values into a Min Heap** (to process them in increasing order).
3. **Process the heap:**
   - Start from the **smallest available card**.
   - Try to form a group of `groupSize` consecutive numbers.
   - If any required number is missing, return **false**.
   - Otherwise, **reduce their counts** and remove if count reaches `0`.

---

## **Practice**
[LeetCode](https://leetcode.com/problems/hand-of-straights/description/)

---

## **Code Implementation**
```cpp
class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false; // The number of cards must be divisible by groupSize

        std::unordered_map<int, int> freq;

        // Count occurrences of each number
        for (int num : hand) {
            freq[num]++;
        }

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        // Push unique elements into the min heap
        for (auto& pair : freq) {
            minHeap.push(pair.first);
        }

        while (!minHeap.empty()) {
            int first = minHeap.top();

            // If the current element is already used up, remove it from the heap
            if (!freq[first]) {
                minHeap.pop();
                continue;
            }

            // Try to form a valid group of size `groupSize`
            for (int i = first; i < first + groupSize; i++) {
                if (!freq[i]) return false; // Missing a required element

                // Decrease count or remove from map if count reaches 0
                if (--freq[i] == 0) {
                    freq.erase(i);
                }
            }
        }

        return true;
    }
};
```

---

## **Time & Space Complexity**
| Approach | Time Complexity | Space Complexity | Explanation |
|----------|----------------|------------------|-------------|
| **Sorting + Greedy** | `O(N log N)` | `O(N)` | Sorting takes `O(N log N)`, then processing takes `O(N)` |
| **Heap + Hash Map (Optimal)** | `O(N log N)` | `O(N)` | Min Heap operations take `O(log N)`, overall `O(N log N)` |



[🔼 Back to Top](#-table-of-contents)


Here’s the `README.md` file for the **Task Scheduler** problem:

---

# 4. Task Scheduler

## **Problem Statement**
You are given an array of **CPU tasks**, each represented by an uppercase letter (`A-Z`). The CPU can:
- Execute **one task per interval** or **stay idle**.
- Tasks **can be completed in any order**.
- However, **the same task must be separated by at least `n` intervals**.

Return the **minimum number of CPU intervals** required to complete all tasks.

---

## **Examples**

### **Example 1**
**Input:**  
```cpp
tasks = ["A","A","A","B","B","B"], n = 2
```
**Output:**  
```cpp
8
```
**Explanation:**  
A possible execution order:
```
A -> B -> idle -> A -> B -> idle -> A -> B
```
- Task `A` and `B` must be separated by at least `2` intervals.
- The `idle` states are needed to satisfy the constraint.

---

### **Example 2**
**Input:**  
```cpp
tasks = ["A","C","A","B","D","B"], n = 1
```
**Output:**  
```cpp
6
```
**Explanation:**  
A possible execution order:
```
A -> B -> C -> D -> A -> B
```
- Since `n = 1`, a task can be repeated after just **one** other task.

---

### **Example 3**
**Input:**  
```cpp
tasks = ["A","A","A","B","B","B"], n = 3
```
**Output:**  
```cpp
10
```
**Explanation:**  
A possible execution order:
```
A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B
```
- Since `n = 3`, tasks `A` and `B` must be **separated by at least 3 intervals**.
- This leads to **idle intervals**.

---

## **Constraints**
- `1 <= tasks.length <= 10^4`
- `tasks[i]` is an **uppercase English letter** (`A-Z`).
- `0 <= n <= 100`

---

## **Intuition**
- **High-frequency tasks** should be scheduled first.
- If a task appears `f` times, it must be **spaced out** with `n` intervals.
- **Idle states** are introduced when necessary.

---

## **Efficient Approach (Max Heap + Cooldown Queue)**
### **Steps:**
1. **Count occurrences** of each task.
2. **Use a Max Heap** to prioritize tasks with higher frequency.
3. **Use a Queue for cooldown tracking**:
   - If a task is executed, it enters a **cooldown period (`n` intervals)**.
   - Once the cooldown expires, push the task back into the heap.
4. **Process tasks one by one** while tracking time.

---


## **practice**
[LeetCode](https://leetcode.com/problems/task-scheduler/description/)

---

## **Code Implementation**
```cpp
#include <vector>
#include <queue>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        int freq[26] = {0};
        int size = tasks.size();

        // Count frequency of each task
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        std::priority_queue<int> pq;
        std::queue<std::pair<int, int>> cooldown;
        int time = 0;

        // Push task frequencies into max heap
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.push(freq[i]);
        }

        while (!pq.empty() || !cooldown.empty()) {
            time++;

            int taskCount = -1;

            // Pick the highest frequency task
            if (!pq.empty()) {
                taskCount = pq.top();
                pq.pop();
            }

            // If task remains, push it into cooldown
            if (taskCount > 1) {
                cooldown.push({taskCount - 1, time + n});
            }

            // If cooldown time is reached, push the task back
            if (!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};
```

---

## **Time & Space Complexity**
| Approach | Time Complexity | Space Complexity | Explanation |
|----------|----------------|------------------|-------------|
| **Sorting + Greedy** | `O(N log N)` | `O(N)` | Sorting takes `O(N log N)`, processing takes `O(N)` |
| **Max Heap + Cooldown Queue** | `O(N log 26) = O(N)` | `O(N)` | Heap operations take `O(log 26) ≈ O(1)`, processing takes `O(N)` |

[🔼 Back to Top](#-table-of-contents)



Here’s the `README.md` file for the **Top K Frequent Elements** problem:

---

# 5. Top K Frequent Elements

## **Problem Statement**
Given an integer array `nums` and an integer `k`, return the `k` most frequent elements. You may return the answer in **any order**.

---

## **Examples**

### **Example 1**
**Input:**  
```cpp
nums = [1,1,1,2,2,3], k = 2
```
**Output:**  
```cpp
[1,2]
```
**Explanation:**  
- `1` appears **3 times**  
- `2` appears **2 times**  
- `3` appears **1 time**  
- The `2` most frequent elements are `[1, 2]`.

---

### **Example 2**
**Input:**  
```cpp
nums = [1], k = 1
```
**Output:**  
```cpp
[1]
```
**Explanation:**  
Since there is **only one element**, it is the most frequent.

---

## **Constraints**
- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `k` is in the range `[1, number of unique elements in nums]`
- The answer is **guaranteed to be unique**.

---

## **Approach**
### **Intuition**
- The problem requires finding the `k` most frequent elements.
- This can be efficiently solved using a **hash map + min heap**.

---

## **Efficient Approach (Hash Map + Min Heap)**
### **Steps:**
1. **Count occurrences** of each element using an **unordered_map**.
2. **Use a Min Heap** (priority queue) to keep track of the **top `k` frequent elements**.
3. **Iterate through the frequency map**:
   - Push elements into the heap.
   - Maintain only `k` elements in the heap.
4. **Extract the top `k` elements** from the heap.


---


## **Practice**
[LeetCode](https://leetcode.com/problems/top-k-frequent-elements/description/)


---

## **Solution**
```cpp
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count;

        // Count the frequency of each element
        for (int num : nums) {
            count[num]++;
        }

        // Min Heap to store top k frequent elements
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        for (auto it = count.begin(); it != count.end(); it++) {
            pq.push({it->second, it->first});
            if (pq.size() > k) pq.pop(); // Remove least frequent element
        }

        std::vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
```

---

## **Time & Space Complexity**
| Approach | Time Complexity | Space Complexity | Explanation |
|----------|----------------|------------------|-------------|
| **Hash Map + Min Heap** | `O(N log K)` | `O(N + K)` | `O(N)` for counting, `O(N log K)` for heap operations |



[🔼 Back to Top](#-table-of-contents)

