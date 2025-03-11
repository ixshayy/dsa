## 📌 Table of Contents
1. [Two Sum Problem](#1-two-sum-problem)
2. [Best Time to Buy and Sell Stock](#121-best-time-to-buy-and-sell-stock)
3. [Contains Duplicate](#217-contains-duplicate)
4. [Product of Array Except Self](#238-product-of-array-except-self)
5. [Maximum Subarray](#53-maximum-subarray)
6. [Find Minimum in Rotated Sorted Array](#153-find-minimum-in-rotated-sorted-array)
7. [Search in Rotated Sorted Array](#33-search-in-rotated-sorted-array)
8. [3Sum](#15-3sum)
9. [Container With Most Water](#11-container-with-most-water)



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

## Solution
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
[🔼 Back to Top](#-table-of-contents)


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

## Solution
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
[🔼 Back to Top](#-table-of-contents)


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

## Solution
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
# 238. Product of Array Except Self

## Problem Statement
Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

## Examples

### Example 1:
**Input:**
```plaintext
nums = [1,2,3,4]
```
**Output:**
```plaintext
[24,12,8,6]
```

### Example 2:
**Input:**
```plaintext
nums = [-1,1,0,-3,3]
```
**Output:**
```plaintext
[0,0,9,0,0]
```

## Constraints:
- `2 <= nums.length <= 10^5`
- `-30 <= nums[i] <= 30`
- The input is generated such that `answer[i]` is guaranteed to fit in a 32-bit integer.

## Solution
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1);
        
        for(int i = 1 , j = 1; i < n; i++){
            pre[j] = pre[j-1] * nums[i-1];
            j++;
        }

        int suffix = 1;
        for(int i = n-2 ; i >= 0; i--){
            suffix = suffix * nums[i+1];
            pre[i] = pre[i] * suffix;
        }

        return pre;
    }
};
```
[🔼 Back to Top](#-table-of-contents)


# 53. Maximum Subarray

## Problem Statement
Given an integer array `nums`, find the contiguous subarray with the largest sum, and return its sum.

## Examples

### Example 1:
**Input:**
```plaintext
nums = [-2,1,-3,4,-1,2,1,-5,4]
```
**Output:**
```plaintext
6
```
**Explanation:**
The subarray `[4,-1,2,1]` has the largest sum `6`.

### Example 2:
**Input:**
```plaintext
nums = [1]
```
**Output:**
```plaintext
1
```
**Explanation:**
The subarray `[1]` has the largest sum `1`.

### Example 3:
**Input:**
```plaintext
nums = [5,4,-1,7,8]
```
**Output:**
```plaintext
23
```
**Explanation:**
The subarray `[5,4,-1,7,8]` has the largest sum `23`.

## Constraints
- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## Solution
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;

        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            maxSum = max(sum, maxSum);
            if(sum < 0) sum = 0;         
        }                     

        return maxSum;
    }
};
```
[🔼 Back to Top](#-table-of-contents)



# 153. Find Minimum in Rotated Sorted Array

## Problem Statement
Suppose an array of length `n` sorted in ascending order is rotated between `1` and `n` times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:

- `[4,5,6,7,0,1,2]` if it was rotated 4 times.
- `[0,1,2,4,5,6,7]` if it was rotated 7 times.

Notice that rotating an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` of unique elements, return the minimum element of this array.

You must write an algorithm that runs in `O(log n)` time.

## Examples

### Example 1:
**Input:**
```plaintext
nums = [3,4,5,1,2]
```
**Output:**
```plaintext
1
```
**Explanation:**
The original array was `[1,2,3,4,5]` rotated 3 times.

### Example 2:
**Input:**
```plaintext
nums = [4,5,6,7,0,1,2]
```
**Output:**
```plaintext
0
```
**Explanation:**
The original array was `[0,1,2,4,5,6,7]` and it was rotated 4 times.

### Example 3:
**Input:**
```plaintext
nums = [11,13,15,17]
```
**Output:**
```plaintext
11
```
**Explanation:**
The original array was `[11,13,15,17]` and it was rotated 4 times.

## Constraints
- `n == nums.length`
- `1 <= n <= 5000`
- `-5000 <= nums[i] <= 5000`
- All the integers of `nums` are unique.
- `nums` is sorted and rotated between `1` and `n` times.

## Solution
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int minN = INT_MAX;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            minN = min(minN, nums[mid]);
            
            if (nums[l] <= nums[mid]) {
                minN = min(minN, nums[l]);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return minN;
    }
};
```
[🔼 Back to Top](#-table-of-contents)



# 33. Search in Rotated Sorted Array

## Problem Statement
There is an integer array `nums` sorted in ascending order (with distinct values).

Prior to being passed to your function, `nums` is possibly rotated at an unknown pivot index `k` (1 <= k < nums.length) such that the resulting array is:

```plaintext
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed)
```
For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` after the possible rotation and an integer `target`, return the index of `target` if it is in `nums`, or `-1` if it is not in `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

---

## Examples

### Example 1:
**Input:**
```plaintext
nums = [4,5,6,7,0,1,2], target = 0
```
**Output:**
```plaintext
4
```

### Example 2:
**Input:**
```plaintext
nums = [4,5,6,7,0,1,2], target = 3
```
**Output:**
```plaintext
-1
```

### Example 3:
**Input:**
```plaintext
nums = [1], target = 0
```
**Output:**
```plaintext
-1
```

---

## Constraints
- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- All values of `nums` are unique.
- `nums` is an ascending array that is possibly rotated.
- `-10^4 <= target <= 10^4`

---

## Approach
1. Check if the middle element is the target.
2. Identify the sorted half.
3. Check if the target is present in the sorted half or not and move the pointers accordingly.

---

## Solution
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while(l <= r){
            int mid = (l+r)/2;

            if(target == nums[mid]) return mid;

            if(nums[mid] < nums[r]){
                if(nums[mid] < target && target <= nums[r]) l = mid+1;
                else r = mid-1;
            }else{
                if(nums[l] <= target && target < nums[mid]) r = mid-1;
                else l = mid+1;
            }
        }

        return -1;
    }
};
```
[🔼 Back to Top](#-table-of-contents)




# 15. 3Sum

## Problem Statement

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that:
- `i != j`, `i != k`, and `j != k`
- `nums[i] + nums[j] + nums[k] == 0`

The solution set must not contain duplicate triplets.

## Examples

### Example 1:
**Input:**
```plaintext
nums = [-1,0,1,2,-1,-4]
```
**Output:**
```plaintext
[[-1,-1,2],[-1,0,1]]
```
**Explanation:**
```
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
```
The distinct triplets are `[-1,0,1]` and `[-1,-1,2]`.

### Example 2:
**Input:**
```plaintext
nums = [0,1,1]
```
**Output:**
```plaintext
[]
```
**Explanation:**
The only possible triplet does not sum up to `0`.

### Example 3:
**Input:**
```plaintext
nums = [0,0,0]
```
**Output:**
```plaintext
[[0,0,0]]
```
**Explanation:**
The only possible triplet sums up to `0`.

## Constraints
- `3 <= nums.length <= 3000`
- `-10^5 <= nums[i] <= 10^5`



## Approach:
1. Sort the array.
2. Iterate through the array:
   - Use two pointers (`j`, `k`) to find valid triplets.
   - Avoid duplicate triplets by skipping repeated elements.
3. Adjust the two pointers (`j++` or `k--`) based on the sum.
4. Store unique triplets in the result.


## Solution
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;  
        sort(nums.begin(), nums.end());  
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int j = i + 1;
            int k = n - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) {
                    j++;
                } else if(sum > 0) {
                    k--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j-1] == nums[j]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }        
            }
        }
        return ans;
    }
};
```
[🔼 Back to Top](#-table-of-contents)



# 11. Container With Most Water

## Problem Statement
You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `i-th` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

**Note:** You may not slant the container.

## Example 1:

**Input:**
```cpp
height = [1,8,6,2,5,4,8,3,7]
```

**Output:**
```cpp
49
```

**Explanation:**
The above vertical lines are represented by the array `[1,8,6,2,5,4,8,3,7]`. In this case, the maximum area of water (blue section) the container can contain is `49`.

## Example 2:

**Input:**
```cpp
height = [1,1]
```

**Output:**
```cpp
1
```

## Constraints:
- `n == height.length`
- `2 <= n <= 10^5`
- `0 <= height[i] <= 10^4`

---

## Approach
1. **Initialize Two Pointers:** Set one pointer at the beginning (`l = 0`) and the other at the end (`r = height.length - 1`).
2. **Calculate Area:** Compute the area formed by `height[l]` and `height[r]` using the formula:
   
   ```cpp
   area = min(height[l], height[r]) * (r - l);
   ```
3. **Update Maximum Area:** Store the maximum water area found so far.
4. **Move the Pointers:**
   - If `height[l] < height[r]`, move `l` to the right.
   - Otherwise, move `r` to the left.
5. **Repeat Until Pointers Meet:** Continue moving the pointers until they meet.

## Solution
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxWater = 0;

        while (l < r) {
            int currentLevel = min(height[l], height[r]) * (r - l);
            maxWater = max(maxWater, currentLevel);

            if (height[l] <= height[r])
                l++;
            else
                r--;
        }
        return maxWater;
    }
};
```

[🔼 Back to Top](#-table-of-contents)