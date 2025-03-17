## 📌 Table of Contents
1. [Climbing Stairs](#1-climbing-stairs)
2. [Coin Change](#2-coin-change)
3. [Longest Increasing Subsequence](#3-longest-increasing-subsequence)
4. [Longest Common Subsequence](#longest-common-subsequence)






# 1. Climbing Stairs

## Problem Statement
You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

---

## Examples

### Example 1:
**Input:**
```cpp
n = 2
```
**Output:**
```cpp
2
```
**Explanation:**
1. 1 step + 1 step
2. 2 steps

---

### Example 2:
**Input:**
```cpp
n = 3
```
**Output:**
```cpp
3
```
**Explanation:**
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

---

## Constraints
- `1 <= n <= 45`

---

## Practice
[Leetcode](https://leetcode.com/problems/climbing-stairs)


## Solution
### Approach: Dynamic Programming
This problem follows the Fibonacci sequence pattern. The number of ways to reach step `n` is the sum of ways to reach step `n-1` and step `n-2`.


### Code Implementation (C++)
```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;
        int step = 0, prev1 = 1, prev2 = 2;
        for (int i = 3; i <= n; i++) {
            step = prev1 + prev2;
            prev1 = prev2;
            prev2 = step;
        }
        return step;
    }
};
```

[🔼 Back to Top](#-table-of-contents)


# 2. Coin Change

## Problem Statement
You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

---

## Examples

### Example 1:
**Input:**  
```cpp
coins = [1,2,5], amount = 11
```
**Output:**  
```cpp
3
```
**Explanation:**  
11 = 5 + 5 + 1

### Example 2:
**Input:**  
```cpp
coins = [2], amount = 3
```
**Output:**  
```cpp
-1
```

### Example 3:
**Input:**  
```cpp
coins = [1], amount = 0
```
**Output:**  
```cpp
0
```

---

## Constraints
- `1 <= coins.length <= 12`
- `1 <= coins[i] <= 2^31 - 1`
- `0 <= amount <= 10^4`


## Practice
[Leetcode](https://leetcode.com/problems/coin-change)

---



## Solution
### Approach 1: Recursive + Memoization
This approach uses a recursive function with memoization to avoid redundant calculations.

```cpp
class Solution {
    int search(vector<int>& coins, int index, int amount, vector<vector<int>>& memo) {
        if (coins[index] == 0) return INT_MAX;
        if (index == 0) {
            if (amount % coins[index] == 0) return amount / coins[index];
            else return INT_MAX;
        }

        if (memo[index][amount] != -1) return memo[index][amount];
        int notPick = search(coins, index - 1, amount, memo);
        int pick = INT_MAX;
        if (amount >= coins[index]) {
            int ans = search(coins, index, amount - coins[index], memo);
            if (ans != INT_MAX) pick = 1 + ans;
        }

        return memo[index][amount] = min(notPick, pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(amount + 1, -1));
        int ans = search(coins, n - 1, amount, memo);
        return ans == INT_MAX ? -1 : ans;
    }
};
```

### Approach 2: Bottom-Up Dynamic Programming
This approach constructs a DP table iteratively to solve the problem efficiently.

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(amount + 1, -1));
        
        for (int i = 0; i < amount + 1; i++) {
            if (i % coins[0] == 0) memo[0][i] = i / coins[0];
            else memo[0][i] = INT_MAX;
        }

        for (int index = 1; index < n; index++) {
            for (int j = 0; j < amount + 1; j++) {
                int notPick = memo[index - 1][j];
                int pick = INT_MAX;
                if (j >= coins[index]) {
                    int ans = memo[index][j - coins[index]];
                    if (ans != INT_MAX) pick = 1 + ans;
                }

                memo[index][j] = min(pick, notPick);
            }
        }

        int ans = memo[n - 1][amount];
        return ans == INT_MAX ? -1 : ans;
    }
};
```

## Complexity Analysis
- **Recursive + Memoization:** `O(n * amount)` time complexity and `O(n * amount)` space complexity.
- **Bottom-Up DP:** `O(n * amount)` time complexity and `O(n * amount)` space complexity.


# 3. Longest Increasing Subsequence

## Problem Statement
Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

## Example

### Example 1:
**Input:**
```cpp
nums = [10,9,2,5,3,7,101,18]
```
**Output:**
```cpp
4
```
**Explanation:** The longest increasing subsequence is `[2,3,7,101]`, therefore the length is `4`.

### Example 2:
**Input:**
```cpp
nums = [0,1,0,3,2,3]
```
**Output:**
```cpp
4
```

### Example 3:
**Input:**
```cpp
nums = [7,7,7,7,7,7,7]
```
**Output:**
```cpp
1
```

## Constraints
- `1 <= nums.length <= 2500`
- `-10^4 <= nums[i] <= 10^4`


## Practice
[LeetCode](https://leetcode.com/problems/longest-increasing-subsequence/)

## Solution

### Approach 1: Recursion with Memoization (Top-Down)
```cpp
class Solution {
    int dfs(vector<int>& nums, int prevIndex, int index, vector<vector<int>> &memo){
        if(index == nums.size()) return 0;
        if(memo[prevIndex+1][index] != -1) return memo[prevIndex+1][index];
        
        int take = 0;
        if(prevIndex == -1 || nums[index] > nums[prevIndex])
            take = 1 + dfs(nums, index, index+1, memo);
        
        int notTake  = dfs(nums, prevIndex, index+1, memo);
        
        return memo[prevIndex+1][index] = max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n+1, vector<int>(n, -1));
        return dfs(nums, -1, 0, memo);
    }
};
```

### Approach 2: Bottom-Up Dynamic Programming
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n+2, vector<int>(n+1, 0));

        for(int prevIndex = n-2 ; prevIndex >= -1 ; prevIndex--){
            for(int index = n-1 ;  index >= 0 ; index--){
                int take = 0;
                if(prevIndex == -1 || nums[index] > nums[prevIndex])
                    take = 1 +  memo[index+1][index+1];
                
                int notTake  = memo[prevIndex+1][index+1];
                
                memo[prevIndex+1][index] = max(take, notTake);
            }
        }
        return memo[0][0];
    }
};
```

### Approach 3: Optimized Dynamic Programming (O(n^2))
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size(); 
       vector<int> dp(n, 1);
       int maxLen = 0;
       for(int curr = 0 ; curr < n ; curr++){
            for(int prev = 0 ; prev < curr; prev++){
                if(nums[prev] < nums[curr]){
                    dp[curr] = max(dp[curr], 1 + dp[prev]);
                }
            }
            maxLen = max(maxLen, dp[curr]);
       }
       return maxLen;
    }
};
```

# 4. Longest Common Subsequence

## Problem Statement

Given two strings `text1` and `text2`, return the length of their longest common subsequence. If there is no common subsequence, return `0`.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, `"ace"` is a subsequence of `"abcde"`.

A **common subsequence** of two strings is a subsequence that is common to both strings.

## Examples

### Example 1
**Input:**
```plaintext
text1 = "abcde", text2 = "ace"
```
**Output:**
```plaintext
3
```
**Explanation:** The longest common subsequence is "ace" and its length is 3.

### Example 2
**Input:**
```plaintext
text1 = "abc", text2 = "abc"
```
**Output:**
```plaintext
3
```
**Explanation:** The longest common subsequence is "abc" and its length is 3.

### Example 3
**Input:**
```plaintext
text1 = "abc", text2 = "def"
```
**Output:**
```plaintext
0
```
**Explanation:** There is no common subsequence, so the result is 0.

## Constraints
- `1 <= text1.length, text2.length <= 1000`
- `text1` and `text2` consist of only lowercase English characters.


## Practice
[LeetCode](https://leetcode.com/problems/longest-common-subsequence/)


## Solution

### Dynamic Programming Approach

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size();
        int s2 = text2.size();
        vector<vector<int>> memo(s1+1, vector<int>(s2+1, 0));

        for(int i = 1; i <= s1; i++) {
            for(int j = 1; j <= s2; j++) {
                if(text1[i - 1] == text2[j - 1])
                    memo[i][j] = 1 + memo[i-1][j-1];
                else
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
        return memo[s1][s2];
    }
};
```


