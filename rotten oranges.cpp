class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int vis[100][100] = {0}; // assuming max grid size <= 100x100
        queue<pair<pair<int,int>, int>> q;  // {{row, col}, time}

        // Push all initially rotten oranges into queue and mark visited
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
            }
        }

        int tm = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            tm = max(tm, t);

            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }

        // Check if any fresh orange is left unrotten
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    return -1;
                }
            }
        }

        return tm;
    }
};
