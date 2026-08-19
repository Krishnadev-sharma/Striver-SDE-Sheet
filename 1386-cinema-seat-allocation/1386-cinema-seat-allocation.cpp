class Solution {
public:
    bool check(vector<int>&seats,int a, int b){
        for(auto i : seats){
        if(i >=a && i <= b) return false;
        }
        return true;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
      map<int, vector<int>> mp;
      for(auto i : reservedSeats) mp[i[0]].push_back(i[1]);
      int ans = 0;
      for(auto i : mp){
        vector<int>seats= i.second;
        bool k = check(seats,2,5);
        bool s = check(seats,4,7);
        bool r = check(seats,6,9);
        if(k && r) ans +=2;
        else if(k || s || r) ans++;
      }
      ans += (n - mp.size()) * 2;
      return ans;
    }
};