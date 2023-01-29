class Solution {
public:
    bool isValid(int i,int j,int n,int m,vector<vector<int>> & grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==0 ){
            return true;
        }
        return false;
    }
    void dfs(int i,int j,int n,int m ,vector<vector<int>>& grid){
        grid[i][j]=1;
        int ax[4]={1,-1,0,0};//just a dfs call usinng a[i] and a[j]
        int ay[4]={0,0,1,-1};

        for(int k=0;k<4;k++){
            int nx=i+ax[k];
            int ny =j+ay[k];

            if(isValid(nx,ny,n,m,grid)){
                dfs(nx,ny,n,m,grid);
            }



        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        //for boundary dfs

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //for all the elements int the boundary
                if(i*j==0||i==n-1||j==m-1){
                    if(grid[i][j]==0){
                        dfs(i,j,n,m,grid);
                    }
                   
                }

            }
        }
        int ans=0;// we will count all the land surrounded by water.
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    ans++;
                    dfs(i,j,m,n,grid);
                }
            }
        }
        return ans;
        
    }
};
