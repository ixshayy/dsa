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