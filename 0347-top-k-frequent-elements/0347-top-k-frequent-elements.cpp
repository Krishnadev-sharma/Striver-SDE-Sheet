class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>fr;
        for(int &num : nums){
            fr[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minH;
        for(auto &pair : fr){
            int num = pair.first;
            int count = pair.second;
            minH.push({count,num});
            if(minH.size() > k)
            minH.pop();
        }
        vector<int>res;
        while(!minH.empty()){
            res.push_back(minH.top().second);
            minH.pop();
        }
        return res;
    }
};