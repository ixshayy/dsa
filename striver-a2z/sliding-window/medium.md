## 📌 Table of Contents
1. [Longest Substring Without Repeating Characters](#1-longest-substring-without-repeating-characters)
2. [Max Consecutive Ones III](#2-max-consecutive-ones-III)
3. [Longest Repeating Character Replacement](#3-longest-repeating-character-replacement)
4. [Binary Subarrays With Sum](#4-binary-subarrays-with-sum)
5. [Count Number of Nice Subarrays](#5-count-umber-of-nice-subarrays)



# 1. Longest Substring Without Repeating Characters

## Problem Statement
Given a string `s`, find the length of the longest substring without repeating characters.

## Example 1:
**Input:**
```plaintext
s = "abcabcbb"
```
**Output:**
```plaintext
3
```
**Explanation:** The answer is "abc", with the length of 3.

## Example 2:
**Input:**
```plaintext
s = "bbbbb"
```
**Output:**
```plaintext
1
```
**Explanation:** The answer is "b", with the length of 1.

## Example 3:
**Input:**
```plaintext
s = "pwwkew"
```
**Output:**
```plaintext
3
```
**Explanation:** The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

## Constraints:
- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols, and spaces.

## Intuition
The problem requires finding the longest contiguous substring with unique characters. A brute force approach would check all substrings and verify uniqueness, but that would be inefficient. Instead, we can use the **Sliding Window** technique to efficiently track the longest valid substring.

### **Approach:**
1. Use two pointers `i` and `j` to define a window.
2. Expand `j` to add characters to the window and track their occurrences using a hashmap.
3. If a duplicate character is found, shrink the window from `i` until the duplicate is removed.
4. Keep track of the maximum window size encountered.

This ensures that each character is processed efficiently with an amortized time complexity of **O(n)**.

## Practice
[Leetcode](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)


## Solution
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count;
        int i = 0, j = 0;
        int size = s.size();
        int maxLen = 0;

        while (j < size) {
            count[s[j]]++;

            while (count[s[j]] > 1) {
                count[s[i]]--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};
```

## Time & Space Complexity
- **Time Complexity:** `O(N)`, where `N` is the length of the string. Each character is processed at most twice (once when added and once when removed from the map).
- **Space Complexity:** `O(min(N, M))`, where `M` is the size of the character set (256 for extended ASCII). In the worst case, we store all unique characters in the hash map.


[🔼 Back to Top](#-table-of-contents)




# 2. Max Consecutive Ones III

## Problem Statement
Given a binary array `nums` and an integer `k`, return the maximum number of consecutive `1`s in the array if you can flip at most `k` `0`s.

### Example 1:
**Input:**  
`nums = [1,1,1,0,0,0,1,1,1,1,0]`, `k = 2`  
**Output:**  
`6`  
**Explanation:**  
After flipping two `0`s, the longest contiguous subarray of `1`s is `[1,1,1,0,0,1,1,1,1,1,1]`.

### Example 2:
**Input:**  
`nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]`, `k = 3`  
**Output:**  
`10`  
**Explanation:**  
After flipping three `0`s, the longest contiguous subarray of `1`s is `[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]`.

## Constraints:
- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.
- `0 <= k <= nums.length`


## Practice
[Leetcode](https://leetcode.com/problems/max-consecutive-ones-iii/description/)

---

## Intuition
The problem requires us to find the longest contiguous subarray containing only `1`s, with the flexibility of flipping up to `k` zeroes. This suggests a **sliding window** approach:
- Expand the window by moving the right pointer (`j`) while counting the number of `0`s.
- If the count of `0`s exceeds `k`, shrink the window from the left (`i`) until we have at most `k` zeroes.
- Keep track of the maximum window size encountered.

---

## Solution
```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, numberOfZeroes = 0;
        int size = nums.size();
        int maxLen = 0;

        while (j < size) {
            if (nums[j] == 0) numberOfZeroes++;

            while (numberOfZeroes > k) {
                if (nums[i] == 0) numberOfZeroes--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};
```

---

## Time Complexity
- **O(n)**: The right pointer (`j`) iterates over the array once, and the left pointer (`i`) also moves at most `n` times. Hence, the total complexity is linear.

## Space Complexity
- **O(1)**: We use only a few integer variables, making the solution space-efficient.


[🔼 Back to Top](#-table-of-contents)


# 3. Longest Repeating Character Replacement

## Problem Statement
You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

## Examples

### Example 1:
**Input:**
```plaintext
s = "ABAB", k = 2
```
**Output:**
```plaintext
4
```
**Explanation:** Replace the two 'A's with two 'B's or vice versa.

### Example 2:
**Input:**
```plaintext
s = "AABABBA", k = 1
```
**Output:**
```plaintext
4
```
**Explanation:** Replace the one 'A' in the middle with 'B' and form "AABBBBA". The substring "BBBB" has the longest repeating letters, which is 4. There may exist other ways to achieve this answer too.

## Constraints
- `1 <= s.length <= 10^5`
- `s` consists of only uppercase English letters.
- `0 <= k <= s.length`


## Intuition
The problem is essentially asking us to find the longest contiguous substring where we can change at most `k` characters to make all characters in that substring the same.

The brute force approach would be to check all possible substrings and count the maximum frequency character, then determine whether the substring can be converted by changing at most `k` other characters. However, this would be computationally expensive.

Instead, we use the **Sliding Window** approach:
- Maintain a window `[i, j]` in which the most frequent character appears `maxFrequency` times.
- Expand the window by increasing `j` and update the frequency of the character at `s[j]`.
- If the condition `(j - i + 1 - maxFrequency) > k` is met (i.e., we need to change more than `k` characters to make the substring uniform), shrink the window from the left by increasing `i`.
- Keep track of the maximum window length encountered during this process.

## Practice 
[Leetcode](https://leetcode.com/problems/longest-repeating-character-replacement/description/)



## Solution
### Brute Force Approach (TLE)
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int maxF = 0;
        int longestSubstr = 0;

        for(int i = 0 ; i < s.size() ; i++){
            maxF = 0;
            memset(count, 0, 26 * sizeof(count[0]));
            
            for(int j = i ; j < s.size() ; j++){
                count[s[j] - 'A']++;
                for(int i = 0 ; i < 26 ; i++){
                    maxF = max(maxF, count[i]);
                }
                
                if(j - i + 1 - maxF <= k){
                    longestSubstr = max(longestSubstr, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return longestSubstr;
    }
};
```
**Time Complexity:** `O(N^2)`, where `N` is the length of the string. This is because we check each possible substring and count character frequencies repeatedly.

### Optimized Sliding Window Approach
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int maxFrequency = 0, longestSubstr = 0;
        int i = 0, j = 0;
        int size = s.size();

        while(j < size){
            count[s[j] - 'A']++;
            maxFrequency = max(maxFrequency, count[s[j] - 'A']);
            
            while(j - i + 1 - maxFrequency > k){
                count[s[i] - 'A']--;
                i++;
            }

            longestSubstr = max(longestSubstr, j - i + 1);
            j++;
        }

        return longestSubstr;
    }
};
```

## Time Complexity Analysis
- **Sliding Window Approach:** `O(N)`, since each character is processed at most twice (once when expanding the window and once when contracting it).
- **Space Complexity:** `O(1)`, as we only use an array of fixed size 26 for character frequency.


[🔼 Back to Top](#-table-of-contents)



# 4. Binary Subarrays With Sum

## Problem Statement

Given a binary array `nums` and an integer `goal`, return the number of non-empty subarrays with a sum equal to `goal`.

A subarray is a contiguous part of the array.

### Example 1:

```
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are:
[1,0,1]
[1,0,1]
[0,1,0,1]
[1,0,1,0,1]
```

### Example 2:

```
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
```

### Constraints:

- `1 <= nums.length <= 3 * 10^4`
- `nums[i]` is either `0` or `1`.
- `0 <= goal <= nums.length`

[Leetcode](https://leetcode.com/problems/binary-subarrays-with-sum/description/)

---

## Intuition

The problem requires us to count subarrays whose sum equals `goal`. A brute-force approach would involve checking all subarrays, leading to an `O(N^2)` complexity, which is inefficient for large `N`.

Instead, we can use a **sliding window approach** to count the number of subarrays with sum ≤ `goal` and the number of subarrays with sum ≤ `goal - 1`. The difference between these two counts gives us the exact number of subarrays with sum = `goal`.

This is based on the observation that:
- `f(goal)`: Count of subarrays with sum `≤ goal`
- `f(goal - 1)`: Count of subarrays with sum `≤ goal - 1`
- `f(goal) - f(goal - 1)`: Count of subarrays with sum exactly equal to `goal`

---

## Brute Force Solution (O(N^2))

```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        int f1 = 0, f2 = 0;
        
        for(int i = 0 ; i < nums.size() ; i++) {
            sum = 0;
            for(int j = i ; j < nums.size(); j++) {
                sum += nums[j];
                if(sum <= goal) f1++;
                if(sum <= goal-1) f2++;
            }
        }
        return f1 - f2;
    }
};
```

### Time Complexity:
- **O(N^2)** - Nested loops iterating through all possible subarrays.

### Space Complexity:
- **O(1)** - No extra space used.

---

## Optimized Solution (Sliding Window, O(N))

```cpp
class Solution {
public:
    int getTotalSubArrWithSumLessEqualGoal(vector<int>& nums, int goal) {
        if(goal < 0) return 0;

        int i = 0, j = 0;
        int count = 0, sum = 0;

        while(j < nums.size()) {
            sum += nums[j];
            while(sum > goal) {
                sum -= nums[i];
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return getTotalSubArrWithSumLessEqualGoal(nums, goal) -
               getTotalSubArrWithSumLessEqualGoal(nums, goal - 1);
    }
};
```

### Time Complexity:
- **O(N)** - Each element is processed at most twice (once for adding and once for removing in the sliding window).

### Space Complexity:
- **O(1)** - No extra space used.


[🔼 Back to Top](#-table-of-contents)


# 5. Count Number of Nice Subarrays

## Problem Statement
Given an array of integers `nums` and an integer `k`. A continuous subarray is called **nice** if there are exactly `k` odd numbers in it.

Return the number of **nice** subarrays.

### Example 1:
**Input:**
```plaintext
nums = [1,1,2,1,1], k = 3
```
**Output:**
```plaintext
2
```
**Explanation:** The only subarrays with 3 odd numbers are `[1,1,2,1]` and `[1,2,1,1]`.

### Example 2:
**Input:**
```plaintext
nums = [2,4,6], k = 1
```
**Output:**
```plaintext
0
```
**Explanation:** There are no odd numbers in the array.

### Example 3:
**Input:**
```plaintext
nums = [2,2,2,1,2,2,1,2,2,2], k = 2
```
**Output:**
```plaintext
16
```

## Constraints
- `1 <= nums.length <= 50000`
- `1 <= nums[i] <= 10^5`
- `1 <= k <= nums.length`

## Intuition
To count the number of nice subarrays efficiently, we can break the problem into two parts:
1. Count the number of subarrays with at most `k` odd numbers (`c1`).
2. Count the number of subarrays with at most `k-1` odd numbers (`c2`).
3. The difference `c1 - c2` gives us the count of subarrays containing exactly `k` odd numbers.

This technique works because subarrays with at most `k` odd numbers include all subarrays with exactly `k` odd numbers, plus some extra subarrays that contain fewer odd numbers. By subtracting the extra cases (`k-1`), we get the exact count.

## Practice
[LeetCode](https://leetcode.com/problems/count-number-of-nice-subarrays/description/).



## Solution
### Optimal Approach
```cpp
class Solution {
private:
    int subArrCount(vector<int>& nums, int k) {
        int l = 0, r = 0, odd = 0, count = 0, n = nums.size();
        if (k < 0) return 0;

        while (r < n) {
            if (nums[r] % 2 != 0) odd++;
            while (odd > k) {
                if (nums[l] % 2 != 0) {
                    odd--;
                }
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subArrCount(nums, k) - subArrCount(nums, k - 1);
    }
};
```

## Time Complexity Analysis
- **`subArrCount(nums, k)`** runs in **O(n)** time because it processes each element once.
- Since we call this function twice, the overall time complexity is **O(n)**.


[🔼 Back to Top](#-table-of-contents)
