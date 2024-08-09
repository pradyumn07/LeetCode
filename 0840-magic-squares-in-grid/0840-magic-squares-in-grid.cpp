class Solution {
public:
    int findrowSum(vector<vector<int>>& mat,int r,int c){
        bool vis[10];
        int sum=0;
        for(int i=0;i<3;i++){
            int rowSum=0;
            for(int j=0;j<3;j++){
                int val=mat[r+i][j+c];
                if(val==0 || val>=10 || vis[val]){
                    return -1;
                }
                vis[val]=true;
                rowSum+=val;
            }
                if(i==0){
                    sum=rowSum;
                }
                else{
                    if(sum!=rowSum) return -1;
                }
            }
            return sum;
        }
    int findcolSum(vector<vector<int>>& mat,int r,int c){
        
        int sum=0;
        for(int j=0;j<3;j++){
            int colSum=0;
            for(int i=0;i<3;i++){
                int val=mat[r+i][j+c];
                colSum+=val;
            }
                if(j ==0){
                    sum=colSum;
                }
                else{
                    if(sum!=colSum) return -1;
                }
            }
            return sum;
        }
    
    int finddigSum(vector<vector<int>>& mat,int r,int c){
        int sum1=mat[r][c]+mat[r+1][c+1]+mat[r+2][c+2];
        int sum2=mat[r][c+2]+mat[r+1][c+1]+mat[r+2][c];
        if(sum1==sum2) return sum1;
        return -1;
    }
    
    bool isMagic(vector<vector<int>>& mat,int r,int c){
        int rowSum=findrowSum(mat,r,c);
        if(rowSum==-1) return false;
        int colSum=findcolSum(mat,r,c);
        if(colSum==-1) return false;
        int diagSum=finddigSum(mat,r,c);
        if(diagSum==-1) return false;
        if(rowSum==colSum && rowSum==diagSum){
            return true;
        }
        return false;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;
        for(int i=0;i<rows-2;i++){
            for(int j=0;j<cols-2;j++){
                if(isMagic(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};