class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cntF = 0, totalT = 0, cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 0)
                    vis[i][j] = 1;

                else
                    cntF++;
            }
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int totalTime = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time  = q.front().second;
            q.pop();
            totalTime  = max(totalTime, time);
            for(int i = 0; i < 4; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    if(!vis[nr][nc] && grid[nr][nc] == 1){
                        cnt++;
                        q.push({{nr,nc}, time +1});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
        if(cnt != cntF) return -1;
        return totalTime; 
    }
};