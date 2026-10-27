#define vs vector<string>
// code goes here ............................
class Solution {
public:
    vs createGrid(int m, int n) {
        vs grid(m , string(n , '#'));

        for (int i = 0 ; i<n;i++){
            grid[0][i]='.';
        }
        for(int i = 1 ; i<m;i++){
            grid[i][n-1]='.';
        }
        
        return grid;
    }
};