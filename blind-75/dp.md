## 📌 Table of Contents
1. [Climbing Stairs](#1-climbing-stairs)
2. [Coin Change](#2-coin-change)
3. [Longest Increasing Subsequence](#3-longest-increasing-subsequence)
4. [Longest Common Subsequence](#4-longest-common-subsequence)
5. [Word Break](#5-word-break)
6. [Combination Sum](#6-combination-sum)
7. [House Robber](#7-house-robber)
8. [Decode Ways](#8-decode-ways)
9. [Unique Paths](#9-unique-paths)
10. [Jump Game](#10-jump-game)



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

[🔼 Back to Top](#-table-of-contents)


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

[🔼 Back to Top](#-table-of-contents)

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



[🔼 Back to Top](#-table-of-contents)

# 5. Word Break

unavailable...

[🔼 Back to Top](#-table-of-contents)


# 6. Combination Sum

## Problem Statement
Given an array of **distinct** integers `candidates` and a target integer `target`, return a list of **all unique combinations** of `candidates` where the chosen numbers sum to `target`. You may return the combinations in any order.

The same number may be chosen from `candidates` an **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to `target` is less than 150 combinations for the given input.

## Examples

### Example 1:
**Input:**
```cpp
candidates = [2,3,6,7], target = 7
```
**Output:**
```cpp
[[2,2,3],[7]]
```
**Explanation:**
- 2 and 3 are candidates, and `2 + 2 + 3 = 7`. Note that `2` can be used multiple times.
- `7` is a candidate, and `7 = 7`.
- These are the only two combinations.

### Example 2:
**Input:**
```cpp
candidates = [2,3,5], target = 8
```
**Output:**
```cpp
[[2,2,2,2],[2,3,3],[3,5]]
```

### Example 3:
**Input:**
```cpp
candidates = [2], target = 1
```
**Output:**
```cpp
[]
```

## Constraints:
- `1 <= candidates.length <= 30`
- `2 <= candidates[i] <= 40`
- All elements of `candidates` are **distinct**.
- `1 <= target <= 40`

## Practice
[LeetCode](https://leetcode.com/problems/combination-sum/)


## Solution
```cpp
class Solution {
private:
    void getCombinationSum(int index, vector<int> &candidates, int remSum, vector<int> &current, vector<vector<int>> &ans) {
        if (index >= candidates.size()) {
            if (remSum == 0) ans.push_back(current);
            return;
        }

        // Include the current candidate if it does not exceed the remaining sum
        if (candidates[index] <= remSum) {
            current.push_back(candidates[index]);
            getCombinationSum(index, candidates, remSum - candidates[index], current, ans);
            current.pop_back(); // Backtrack
        }

        // Exclude the current candidate and move to the next one
        getCombinationSum(index + 1, candidates, remSum, current, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> ans;
        getCombinationSum(0, candidates, target, current, ans);
        return ans;
    }
};
```
[🔼 Back to Top](#-table-of-contents)

# 7. House Robber

## Problem Statement
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, but the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected. If two adjacent houses are broken into on the same night, the police will be alerted.

Given an integer array `nums` representing the amount of money in each house, return the maximum amount of money you can rob tonight without alerting the police.

## Examples

### Example 1:
**Input:**
```cpp
nums = [1,2,3,1]
```
**Output:**
```cpp
4
```
**Explanation:**
Rob house 1 (money = 1) and then rob house 3 (money = 3). Total amount robbed = `1 + 3 = 4`.

### Example 2:
**Input:**
```cpp
nums = [2,7,9,3,1]
```
**Output:**
```cpp
12
```
**Explanation:**
Rob house 1 (money = 2), rob house 3 (money = 9), and rob house 5 (money = 1). Total amount robbed = `2 + 9 + 1 = 12`.

## Constraints
- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 400`

## Practice
[Leetcode](https://leetcode.com/problems/house-robber/description/)


## Solution Approaches
### Approach 1: Recursion with Memoization
```cpp
class Solution {
private:
    int search(vector<int>& nums, int index, vector<int> &memo){
        if(index == 0) return nums[index];
        if(index < 0) return 0;

        if(memo[index] != -1) return memo[index];

        int pick = nums[index] + search(nums, index-2, memo);
        int notPick = search(nums, index-1, memo);

        return memo[index] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n+1, -1);
        return search(nums, n-1, memo);
    }
};
```
**Time Complexity:** `O(N)` (Each subproblem is solved only once and stored in `memo`).
**Space Complexity:** `O(N)` (For the `memo` array and recursion stack).

### Approach 2: Bottom-Up Dynamic Programming (Tabulation)
```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);

        memo[0] = nums[0];
        int sum = memo[0];

        for(int i = 1 ; i < n ; i++){
            int pick = nums[i];
            if(i > 1) pick += memo[i-2];

            int notPick = memo[i-1];
            sum = max(pick, notPick);
            memo[i] = sum;
        }

        return sum;
    }
};
```
**Time Complexity:** `O(N)` (Iterates through `nums` once).
**Space Complexity:** `O(N)` (For the `memo` array).

### Approach 3: Optimized Space Dynamic Programming
```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev2 = 0;
        int prev = nums[0];

        for(int i = 1 ; i < n ; i++){
            int pick = nums[i];
            if(i > 1) pick += prev2;

            int notPick = prev;
            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
```
**Time Complexity:** `O(N)` (Iterates through `nums` once).
**Space Complexity:** `O(1)` (Uses only two variables `prev` and `prev2`).

[🔼 Back to Top](#-table-of-contents)


# 8. Decode Ways

unavailable...

[🔼 Back to Top](#-table-of-contents)



# 9. Unique Paths

## Problem Statement

There is a robot on an `m x n` grid. The robot is initially located at the top-left corner `(grid[0][0])`. The robot tries to move to the bottom-right corner `(grid[m - 1][n - 1])`. The robot can only move either **down** or **right** at any point in time.

Given two integers `m` and `n`, return the **number of unique paths** that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be **less than or equal to 2 * 10^9**.

### Example 1:

```plaintext
Input: m = 3, n = 7
Output: 28
```

### Example 2:

```plaintext
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```

### Constraints:

- `1 <= m, n <= 100`


## Practice
[Leetcode](https://leetcode.com/problems/unique-paths/description/)


## Solution

### Approach 1: Recursion with Memoization (Top-Down DP)

#### Code:
```cpp
class Solution {
private:
    int search(int x, int y, vector<vector<int>>& memo){
        if(x == 0 && y == 0) return 1;
        if(x < 0 || y < 0) return 0;
        if(memo[x][y] != -1) return memo[x][y];
        return memo[x][y] = search(x-1, y, memo) + search(x, y-1, memo);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return search(m-1, n-1, memo);
    }
};
```

#### Complexity Analysis:
- **Time Complexity:** `O(m * n)`, as each subproblem is computed only once and stored in the `memo` table.
- **Space Complexity:** `O(m * n)`, due to the recursion stack and memoization table.

---

### Approach 2: Dynamic Programming (Bottom-Up DP)

#### Code:
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        vector<int> prev(n, 0);
        
        for(int i = 0; i < m; i++){
            vector<int> curr(n);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) curr[j] = 1;
                else{
                    int l = 0, r = 0;
                    if(i > 0) l = prev[j];
                    if(j > 0) r = curr[j-1];
                    curr[j] = l + r;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
```

#### Complexity Analysis:
- **Time Complexity:** `O(m * n)`, as we iterate through the entire grid.
- **Space Complexity:** `O(n)`, as we optimize the space usage with a single row (`prev`).

---

### Approach 3: Space Optimized Dynamic Programming

#### Code:
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        
        for(int i = 0; i < m; i++){
            vector<int> curr(n);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) curr[j] = 1;
                else{
                    int l = 0, r = 0;
                    if(i > 0) l = prev[j];
                    if(j > 0) r = curr[j-1];
                    curr[j] = l + r;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
```

#### Complexity Analysis:
- **Time Complexity:** `O(m * n)`, since we iterate through all grid cells.
- **Space Complexity:** `O(n)`, as we only store two rows at a time instead of the entire grid.


[🔼 Back to Top](#-table-of-contents)


# 10. Jump Game

## Problem Statement

You are given an integer array `nums`. You are initially positioned at the array's first index, and each element in the array represents your **maximum jump length** at that position.

Return `true` if you can reach the last index, or `false` otherwise.

### Example 1:

```plaintext
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

### Example 2:

```plaintext
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
```

### Constraints:

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 10^5`

## Practice
[Leetcode](https://leetcode.com/problems/jump-game/description/)

## Solution

### Greedy Algorithm

#### Explanation:
- Start from the last index and move backward.
- Maintain a `goal` position that initially points to the last index.
- If at index `i`, you can jump to `goal` (`i + nums[i] >= goal`), update `goal = i`.
- If `goal` reaches index `0`, return `true`; otherwise, return `false`.

#### Code:
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        
        return goal == 0;
    }
};
```

### Complexity Analysis:
- **Time Complexity:** `O(n)`, as we traverse the array once.
- **Space Complexity:** `O(1)`, since we use only a single integer variable `goal`.


[🔼 Back to Top](#-table-of-contents)