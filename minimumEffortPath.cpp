class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       int n = heights.size();
       int m = heights[0].size();
       vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
       vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
       effort[0][0]=0;
       priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
       pq.push({0,0,0});
       while(!pq.empty()){
        auto [curreffort,r,c]=pq.top();
        pq.pop();
        
        if(r==n-1 && c==m-1) return curreffort;

        if(curreffort>effort[r][c]) continue;
        for(auto [dr,dc]:dir){
            int nr = r+dr,nc = c+dc;
            if(nr>=0 && nc>=0 && nr<n && nc<m){
                int nexteffort = max(curreffort, abs(heights[nr][nc] - heights[r][c]));
                if(nexteffort<effort[nr][nc]){
                    effort[nr][nc]=nexteffort;
                    pq.push({nexteffort,nr,nc});
                }
            }
        }
       }
       return -1;
    }
};
