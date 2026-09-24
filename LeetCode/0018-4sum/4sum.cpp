/*
Problem: 4Sum (#18)
LeetCode: https://leetcode.com/problems/4sum/
Language: C++
Runtime: 19 ms
Memory: 17.4 MB
Approach: One-Pass Hash Map (Complement Lookup)
Author: Krishnadev_sharma
Synced by CodeCrus: https://github.com/Krishnadev-sharma/Striver-SDE-Sheet
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
       vector<vector<int>>op;
       for(int i = 0; i < n-3; i++){
        for(int j = i + 1; j < n-2; j++){
            long long nt = (long long ) target - (long long) nums[i] - (long long) nums[j];
            int low = j+1, high = n-1;
            while(low < high){
                if(nums[low] + nums[high] < nt){
                    low++;
                }
                else if(nums[low] + nums[high] > nt){
                    high--;
                }
                else{
                    op.push_back({nums[i],nums[j],nums[low],nums[high]});
                    int idx1 = low, idx2 = high;
                    while( low<high && nums[low] == nums[idx1]) low++;
                    while(low < high && nums[high] ==nums[idx2]) high--;
                }
            }
            while(j+1 < n && nums[j] == nums[j+1]) j++;
        }
        while(i +1 < n && nums[i] == nums[i+1]) i++;
       }
       return op;
    }
};