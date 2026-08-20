class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n) return *max_element(nums.begin(), nums.end());

        vector<int>ans;
        if(k == 1){
            for(int i : nums){
                if(count(nums.begin(),nums.end(), i) == 1){
                    ans.push_back(i);
                }
            }
        }
        else{
            for(int i : {nums[0], nums[n-1]}){
                if(count(nums.begin(),nums.end(), i) == 1){
                    ans.push_back(i);
                }
            }
        }
        return ans.empty() ? -1 : *max_element(ans.begin(), ans.end());
    }
};