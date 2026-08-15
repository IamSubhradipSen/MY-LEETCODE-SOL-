class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; 
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement exists in our map
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            
            // Add the current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        return {};
    }
};