# 1. Two Sum Problem

## Problem Statement
Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to `target`.

### Constraints:
- Each input has exactly **one** solution.
- You may not use the same element twice.
- You can return the answer in **any order**.

## Examples

### Example 1:
**Input:**
```plaintext
nums = [2,7,11,15], target = 9
```
**Output:**
```plaintext
[0,1]
```
**Explanation:**
Because `nums[0] + nums[1] == 9`, we return `[0,1]`.

### Example 2:
**Input:**
```plaintext
nums = [3,2,4], target = 6
```
**Output:**
```plaintext
[1,2]
```

### Example 3:
**Input:**
```plaintext
nums = [3,3], target = 6
```
**Output:**
```plaintext
[0,1]
```

## Constraints
- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- Only one valid answer exists.

### Solution
```cpp
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> preSum;
            vector<int> ans;
            for(int i = 0 ; i < nums.size() ; i++){
                int rem = target - nums[i];
    
                if(preSum.find(rem) != preSum.end()){
                    ans = {preSum[rem], i};
                    return ans;
                }else{
                    preSum[nums[i]] = i;
                }
            }
            
            return ans;
        }
    
    };
```


# 121. Best Time to Buy and Sell Stock

## Problem Statement
You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

## Examples

### Example 1:
**Input:**
```plaintext
prices = [7,1,5,3,6,4]
```
**Output:**
```plaintext
5
```
**Explanation:**
Buy on day `2` (price = `1`) and sell on day `5` (price = `6`), profit = `6-1 = 5`.

### Example 2:
**Input:**
```plaintext
prices = [7,6,4,3,1]
```
**Output:**
```plaintext
0
```
**Explanation:**
In this case, no transactions are done and the max profit = `0`.

## Constraints
- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

### Solution
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minElem = prices[0];
        int maxProfit = 0;

        for(int i = 0 ; i < prices.size() ; i++){
            if(prices[i] < minElem){
                minElem = prices[i];
            }
            maxProfit = max(maxProfit, prices[i] - minElem);
        }

        return maxProfit;
    }
};
```


# 217. Contains Duplicate

## Problem Statement
Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

## Examples

### Example 1:
**Input:**
```plaintext
nums = [1,2,3,1]
```
**Output:**
```plaintext
true
```
**Explanation:**
The element `1` occurs at the indices `0` and `3`.

### Example 2:
**Input:**
```plaintext
nums = [1,2,3,4]
```
**Output:**
```plaintext
false
```
**Explanation:**
All elements are distinct.

### Example 3:
**Input:**
```plaintext
nums = [1,1,1,3,3,4,3,2,4,2]
```
**Output:**
```plaintext
true
```

## Constraints
- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

### Solution
```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;

        for(int i = 0 ; i < nums.size() ; i++){
            if(count[nums[i]]) return true;

            count[nums[i]]++;
        }

        return false;
    }
};
```
