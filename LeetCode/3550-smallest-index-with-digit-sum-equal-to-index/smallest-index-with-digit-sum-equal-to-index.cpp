/*
Problem: Smallest Index With Digit Sum Equal to Index (#3550)
LeetCode: https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/
Language: C++
Runtime: 0 ms
Memory: 30.9 MB
Approach: Optimized Single-Pass Traversal
Author: Krishnadev_sharma
Synced by CodeCrus: https://github.com/Krishnadev-sharma/Striver-SDE-Sheet
*/

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
       for(int i = 0; i < n; i++){
        int num = nums[i];
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        if(sum == i)
        return i;
       }
       return -1;
    }
};