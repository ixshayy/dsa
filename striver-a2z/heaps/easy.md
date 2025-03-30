## 📌 Table of Contents
1. [Does Array Represent Heap](#1-does-array-epresent-heap)


Here is the `README.md` file for the **Does Array Represent Heap** problem.  

---

# 1. Does Array Represent Heap

## **Problem Statement**
Given an array `arr` of size `n`, check if the given array can be a **level-order representation of a Max Heap**.

A **Max Heap** is a binary tree where:
- The value of each parent node is **greater than or equal to** the values of its children.
- The tree follows the **complete binary tree** property, meaning all levels are completely filled except possibly the last, which is filled from left to right.

---

## **Examples**
### **Example 1**
**Input:**  
```cpp
n = 6
arr[] = {90, 15, 10, 7, 12, 2}
```
**Output:**  
```
1
```
**Explanation:**  
The given array represents the following **Max Heap**:
```
       90
     /    \
   15      10
  /  \     /
7    12  2
```
Since every node follows the **max-heap property**, the output is `1`.

---

### **Example 2**
**Input:**  
```cpp
n = 6
arr[] = {9, 15, 10, 7, 12, 11}
```
**Output:**  
```
0
```
**Explanation:**  
The given array represents the following **tree**:
```
       9
     /    \
   15      10
  /  \     /
7    12  11
```
Since **9** is smaller than **15** and **10**, and **10** is smaller than **11**, this **does not satisfy the max-heap property**.  
Thus, the output is `0`.

---

## **Constraints**
- `1 ≤ n ≤ 10^5`
- `1 ≤ arr[i] ≤ 10^5`

---

## **Approach**
### **Intuition**
A **Max Heap** must satisfy:
1. **Complete Binary Tree Condition** – In level-order representation, the array must be **contiguous** (no missing nodes).
2. **Heap Property** – Each parent node `arr[i]` must be **greater than or equal to** its children.

For any node at index `i`:
- Left child is at index **`2*i + 1`**
- Right child is at index **`2*i + 2`**

We check for **every parent node** whether:
- `arr[i] >= arr[2*i + 1]` (if left child exists)
- `arr[i] >= arr[2*i + 2]` (if right child exists)

If any condition fails, the array **does not represent a max heap**.

---


## **Practice**
- [GeeksforGeeks](https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1)


---

## **Solution**
```cpp
class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        for(int i = 0; i < n/2 ; i++){
            if(arr[i] < arr[2*i+1] || arr[i] < arr[2*i+2]) return false; 
        }
        
        return true;
    }
};
```

---

## **Time & Space Complexity**
| Approach | Time Complexity | Space Complexity | Notes |
|----------|----------------|------------------|-------|
| **Iterate through parents** | `O(n)` | `O(1)` | Efficient check |

✅ **This solution runs in `O(n)` time with `O(1)` space**, making it optimal.


[🔼 Back to Top](#-table-of-contents)