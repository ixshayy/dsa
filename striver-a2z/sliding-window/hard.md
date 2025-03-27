## 📌 Table of Contents
1. [Subarrays with K Different Integers](#1-subarrays-with-k-different-integers)
2. [Minimum Window Substring](#2-minimum-window-substring)


# 1. Subarrays with K Different Integers

## Problem Statement
Given an integer array `nums` and an integer `k`, return the number of **good subarrays** in `nums`.

A **good subarray** is a subarray that contains **exactly** `k` distinct integers.

- **Example:** `[1,2,3,1,2]` has 3 different integers: `1, 2, and 3`.

A **subarray** is a contiguous part of an array.

---

## Examples
### Example 1
**Input:**  
```cpp
nums = [1,2,1,2,3], k = 2
```
**Output:**  
```
7
```
**Explanation:**  
Valid subarrays with exactly `2` distinct integers:  
`[1,2]`, `[2,1]`, `[1,2]`, `[2,3]`, `[1,2,1]`, `[2,1,2]`, `[1,2,1,2]`.

### Example 2
**Input:**  
```cpp
nums = [1,2,1,3,4], k = 3
```
**Output:**  
```
3
```
**Explanation:**  
Valid subarrays with exactly `3` distinct integers:  
`[1,2,1,3]`, `[2,1,3]`, `[1,3,4]`.

---

## Constraints
- `1 <= nums.length <= 2 × 10⁴`
- `1 <= nums[i], k <= nums.length`

---

## Practice
[Leetcode](https://leetcode.com/problems/subarrays-with-k-different-integers/description/)



## Intuition
Instead of checking all possible subarrays explicitly (which would be too slow), we can use a **sliding window** approach:

1. **Key Idea**:  
   Instead of counting subarrays with exactly `k` distinct numbers directly, we **use two helper functions** to count subarrays with **at most `k` distinct numbers**.
   
   - **Why?**  
     - The number of subarrays with **exactly `k` distinct numbers** is the difference:
       ```
       subarraysWithAtMostKDistinct(k) - subarraysWithAtMostKDistinct(k-1)
       ```
     - This works because:
       - `subarraysWithAtMostKDistinct(k)`: Counts all subarrays having **at most** `k` distinct numbers.
       - `subarraysWithAtMostKDistinct(k-1)`: Counts all subarrays having **at most** `k-1` distinct numbers.
       - Their **difference** removes the extra subarrays that contain fewer than `k` distinct numbers.

2. **Sliding Window Technique**:
   - Expand the window (`j` pointer) until we have at most `k` distinct elements.
   - If the window exceeds `k` distinct elements, shrink it (`i` pointer) until it's valid again.
   - At every step, count the **valid subarrays** ending at `j`.

---

## Solution
```cpp
class Solution {
public:
    int subarraysWithAtMostKDistinct(vector<int> nums, int k){
        unordered_map<int, int> freq;
        int count = 0;
        int i = 0, j = 0, n = nums.size();

        while (j < n) {
            freq[nums[j]]++; // Include nums[j] in the window

            // If the number of distinct elements exceeds k, shrink window
            while (freq.size() > k) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) freq.erase(nums[i]); // Remove nums[i] if count becomes 0
                i++;
            }

            // Number of valid subarrays ending at j
            count += j - i + 1;
            j++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k-1);
    }
};
```


## **Time & Space Complexity**
- **Time Complexity:** `O(N)`, since each element is processed at most twice (once when expanding, once when contracting).
- **Space Complexity:** `O(K)`, since we store frequencies of up to `K` elements in a hashmap.


[🔼 Back to Top](#-table-of-contents)



# 2. Minimum Window Substring

## Problem Statement
Given two strings `s` and `t` of lengths `m` and `n` respectively, return the **minimum window** in `s` such that **every** character in `t` (including duplicates) is included in the window.  

If no such substring exists, return the empty string `""`.

The test cases are designed such that the **answer is unique**.

---

## Examples
### **Example 1**
**Input:**  
```cpp
s = "ADOBECODEBANC", t = "ABC"
```
**Output:**  
```
"BANC"
```
**Explanation:**  
The minimum window substring `"BANC"` contains `'A'`, `'B'`, and `'C'` from string `t`.

---

### **Example 2**
**Input:**  
```cpp
s = "a", t = "a"
```
**Output:**  
```
"a"
```
**Explanation:**  
The entire string `s` is the minimum window.

---

### **Example 3**
**Input:**  
```cpp
s = "a", t = "aa"
```
**Output:**  
```
""
```
**Explanation:**  
Both `'a'` characters from `t` must be included in the window.  
Since `s` only contains one `'a'`, return an empty string.

---

## Constraints
- `1 <= m, n <= 10^5`
- `s` and `t` consist of uppercase and lowercase English letters.

---

## Practice
[Leetcode](https://leetcode.com/problems/minimum-window-substring/description/)

## Intuition
1. **Expanding & Shrinking a Window:**  
   - We maintain a **sliding window** to include characters from `t` while iterating through `s`.
   - As soon as we have all characters of `t` covered, we **try shrinking** the window from the left to find the smallest valid substring.

2. **Using Frequency Count:**  
   - We maintain a **character frequency map** for `t` to track how many characters are still needed.
   - A counter `count` keeps track of how many characters of `t` are satisfied.

3. **Optimization Using Two Pointers (`i` and `j`):**
   - **Expand `j`** to include valid characters until all of `t` is covered.
   - **Shrink `i`** to minimize the window while keeping it valid.

---

## Solution
```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int freq[256] = {0};  // Frequency map for t
        int minLen = INT_MAX;
        int sIndex = -1;
        int i = 0, j = 0, count = 0;
        int m = s.size(), n = t.size();

        // Count frequency of each character in t
        for (int k = 0; k < n; k++) {
            freq[t[k]]++;
        }

        // Sliding window technique
        while (j < m) {
            if (freq[s[j]] > 0) count++; // A required character is found
            
            freq[s[j]]--; // Decrease its frequency in the window

            // Try to shrink the window if all characters are matched
            while (count == n) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    sIndex = i; // Store the start index of minimum window
                }

                freq[s[i]]++; // Restore character frequency when moving left
                if (freq[s[i]] > 0) count--; // A required character is lost

                i++; // Shrink from left
            }

            j++; // Expand from right
        }

        return sIndex != -1 ? s.substr(sIndex, minLen) : "";
    }
};
```

## **Time & Space Complexity**
- **Time Complexity:** `O(m)`, since each character is processed at most twice (once when expanding, once when contracting).
- **Space Complexity:** `O(1)`, since the frequency array has a fixed size of `256`.


[🔼 Back to Top](#-table-of-contents)