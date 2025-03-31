## 📌 Table of Contents
1. [Top K Frequent Elements](#1-top-k-frequent-elements)
2. [Find Median from Data Stream](#2-find-median-from-data-stream)
3. [Kth Largest Element in a Stream](#3-kth-largest-element-in-a-stream)


# 1. Top K Frequent Elements

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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        // Count the frequency of each element
        for (int num : nums) {
            count[num]++;
        }

        // Min Heap to store top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto it = count.begin(); it != count.end(); it++) {
            pq.push({it->second, it->first});
            if (pq.size() > k) pq.pop(); // Remove least frequent element
        }

        vector<int> ans;
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

---

# 2. Find Median from Data Stream

## **Problem Statement**
The **median** is the middle value in an ordered list of integers. If the list has an **even** number of elements, the median is the **average of the two middle values**.

- **Example 1:** `arr = [2,3,4]` → Median = `3`
- **Example 2:** `arr = [2,3]` → Median = `(2 + 3) / 2 = 2.5`

### **Implement the `MedianFinder` class:**
1. **`MedianFinder()`** → Initializes the object.
2. **`void addNum(int num)`** → Adds the integer `num` to the data structure.
3. **`double findMedian()`** → Returns the median of all elements so far. Answers within `10^-5` of the actual answer are accepted.

---

## **Example Usage**
### **Input:**
```cpp
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
```
### **Output:**
```cpp
[null, null, null, 1.5, null, 2.0]
```
### **Explanation:**
```cpp
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // returns 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr = [1, 2, 3]
medianFinder.findMedian(); // returns 2.0
```

---

## **Constraints**
- `-10^5 <= num <= 10^5`
- There will be **at least one element** before calling `findMedian()`.
- At most `5 × 10^4` calls to `addNum()` and `findMedian()`.

---

## **Intution**
### **Using Two Heaps (MaxHeap + MinHeap)**
To efficiently find the median, we use:
1. **Max Heap (`maxHeap`)** → Stores the **smaller half** of numbers.
2. **Min Heap (`minHeap`)** → Stores the **larger half** of numbers.

### **Steps:**
1. Insert numbers into **`maxHeap`** (left half) or **`minHeap`** (right half).
2. **Balance the heaps** to ensure their size difference is at most **1**.
3. **Find the median**:
   - If both heaps have the **same size**, return the **average** of both tops.
   - Otherwise, return the **top of the larger heap**.

---


## **Leetcode**
[LeetCode](https://leetcode.com/problems/find-median-from-data-stream/description/)


## **Solution**
```cpp
#include <queue>

class MedianFinder {
public:
    priority_queue<int> maxHeap;  // Max heap for the left half
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min heap for the right half

    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty() || num < maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

/**
 * Usage:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double result = obj->findMedian();
 */
```

---

## **Time & Space Complexity**
| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| `addNum()` | `O(log N)` | `O(N)` |
| `findMedian()` | `O(1)` | `O(1)` |


[🔼 Back to Top](#-table-of-contents)



# 3. Kth Largest Element in a Stream

## **Problem Statement**
You are part of a **university admissions office** and need to dynamically track the **k-th highest test score** from applicants in **real-time**. This helps determine the **cut-off marks** for interviews and admissions as new scores are submitted.

### **Task**
Implement the `KthLargest` class:
1. **`KthLargest(int k, int[] nums)`** → Initializes the object with the integer `k` and a stream of test scores `nums`.
2. **`int add(int val)`** → Adds a new test score `val` to the stream and returns the `k-th` largest element among all scores seen so far.

---

## **Example Usage**
### **Example 1**
#### **Input**
```cpp
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
```
#### **Output**
```cpp
[null, 4, 5, 5, 8, 8]
```
#### **Explanation**
```cpp
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);  // return 4
kthLargest.add(5);  // return 5
kthLargest.add(10); // return 5
kthLargest.add(9);  // return 8
kthLargest.add(4);  // return 8
```

### **Example 2**
#### **Input**
```cpp
["KthLargest", "add", "add", "add", "add"]
[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]
```
#### **Output**
```cpp
[null, 7, 7, 7, 8]
```
#### **Explanation**
```cpp
KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
kthLargest.add(2);  // return 7
kthLargest.add(10); // return 7
kthLargest.add(9);  // return 7
kthLargest.add(9);  // return 8
```

---

## **Constraints**
- `0 <= nums.length <= 10^4`
- `1 <= k <= nums.length + 1`
- `-10^4 <= nums[i] <= 10^4`
- `-10^4 <= val <= 10^4`
- At most `10^4` calls will be made to `add`.

---

## **Intitution**
### **Using a Min-Heap (Priority Queue)**
To efficiently maintain the **k-th largest element**, we use a **Min-Heap** of **size k**.

### **Steps:**
1. **Insert elements from `nums` into a Min-Heap** of size `k`.
2. If the heap grows **larger than k**, remove the smallest element (`pop()`).
3. For every new `add(val)`, insert `val` into the heap:
   - If the heap exceeds size `k`, remove the **smallest** element.
   - The **top of the heap** always stores the **k-th largest element**.

---

## **Practice**
[LeetCode](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)


## **Code Implementation**
```cpp
#include <queue>
#include <vector>

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > size) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Usage:
 * KthLargest* obj = new KthLargest(k, nums);
 * int result = obj->add(val);
 */
```

---

## **Time & Space Complexity**
| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| `add()` | `O(log k)` | `O(k)` |
| `KthLargest()` (initialization) | `O(N log k)` | `O(k)` |



