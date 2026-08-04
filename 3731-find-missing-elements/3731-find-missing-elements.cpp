class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MIN;
        int mx = INT_MAX;
        for (int i = 0; i < n; i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < n - 1; i++) {
            int curr = nums[i];
            while (curr + 1 < nums[i + 1]) {
                ans.push_back(curr+1);
                curr++;
            }
        }
        return ans;
    }
};