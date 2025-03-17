class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            int maxCol = 0;
            for(int i = 1; i < mat[0].size(); i++){
                if(mat[mid][i] > mat[mid][maxCol]){
                    maxCol = i;
                }
            }
            int upperVal = (mid > 0) ? mat[mid - 1][maxCol] : -1;
            int lowerVal = (mid < n - 1) ? mat[mid + 1][maxCol] : -1;
            if(mat[mid][maxCol] > upperVal && mat[mid][maxCol] > lowerVal){
                return {mid, maxCol};
            }else if(upperVal > mat[mid][maxCol]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return {};
    }
};