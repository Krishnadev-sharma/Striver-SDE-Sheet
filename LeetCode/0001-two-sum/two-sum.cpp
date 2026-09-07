/*
Problem: Two Sum (#1)
LeetCode: https://leetcode.com/problems/two-sum/
Language: C++
Runtime: 0 ms
Memory: 14.9 MB
Approach: Optimized Solution
Author: Krishnadev_sharma
Synced by CodeCrus: https://github.com/Krishnadev-sharma/Striver-SDE-Sheet
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int>ref;
      int res = 0;
      for(int i = 0; i < nums.size(); i++){
        res = target - nums[i];
        if(ref.find(res) != ref.end()) return {ref[res], i};
        ref[nums[i]] = i;
      }
      return {};
    }
};