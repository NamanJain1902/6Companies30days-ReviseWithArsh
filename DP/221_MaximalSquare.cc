class Solution {
public:
    //1. brute...considering every possible square starting with 1
    //2. like count island problem but need to check for square constraint
    //3. 
    
    int brute(vector<vector<char>> &mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        int maxlen = 0;
        for(int gap=1; gap<m; ++gap) {
            for(int i=0,j=gap-1; gap<n; i++, ++j) {
                
                if(mat[i][j] == '0') continue;
                bool allone = true;
                for(int ix = i; ix< gap; ix++) {
                    for(int jx = j; jx < gap; jx++) {
                        // keeping max square dimenssion
                        if(mat[i][j] == '0') {
                            allone = false;
                            break;
                        }
                    }
                    if(!allone) break;
                }
                if(allone)
                maxlen = gap;
            }
        }
        return maxlen * maxlen;
    }
    int brute2(vector<vector<char>>&  mat){
        int maxlen =0;
        int m = mat.size();
        int n = mat[0].size();
        
        // while(size + )
        // for(int size = 1; size <= min(m, n); ++size) {
            // cout << "***************Size:-  " << size << "\t*********" <<endl;
            for(int io = 0; io < m; io++){
                for(int jo = 0; jo < n; jo++) {
                    int size = 1;
                    
                    if(mat[io][jo] == '0') continue;
                    
                    bool ok = true;
                    
                    while(size + io < m and size + jo < n and ok) {
                    
                        for(int i=jo; i<=jo+size; ++i) {
                            if(mat[io+size][i] == '0' ){
                                ok = false;
                                break;
                            }
                        }
                        
                        for(int i=io; i<=io+size; ++i) {
                            if(mat[i][jo+size] == '0' ){
                                ok = false;
                                break;
                            }
                        }
                        
                        // for(int i=io; i<io+size; ++i) {
                        //     for(int j=jo; j<jo+size; ++j) {
                        //         if(mat[i][j] != '1'){
                        //             ok = false;
                        //             break;
                        //         }                    
                        //     }
                        //     if(ok == false) break;
                        // }

//                         if(ok) {
//                                cout << "***************Size:-  " << size << "\t*********" <<endl;
//                             maxlen = size;

//                             cout << "io: " << io << "\t" << "jo: " << jo << endl;  

//                             for(int i=io; i<size; ++i) {
//                                 for(int j=jo; j<size; ++j) {
//                                   cout << mat[i][j] << " ";               
//                             }
//                                 cout <<  "\n";
//                              }
//                         }
                        if(ok) size++;
                    }
                    
                    maxlen = max(maxlen, size);
                }
            }
        // }
        
        return maxlen * maxlen;
        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        
        // return brute2(matrix);
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int omax = 0;
        for(int i=0; i<m; ++i) {
            dp[i][n-1] = (matrix[i][n-1] == '1');
            if(dp[i][n-1] == 1) omax=1;
        }
        for(int i=0; i<n; ++i) {
            dp[m-1][i] = (matrix[m-1][i] == '1');
            if(dp[m-1][i] == 1) omax=1;
        }
        
        
        for(int i=m-2; i>= 0; i--) {
            for(int j = n-2; j>=0; j--) {
                if(matrix[i][j] == '0') dp[i][j] = 0;
                else {
                    dp[i][j] = min(dp[i][j+1], min(dp[i+1][j], dp[i+1][j+1])) + 1;
                    omax = max(omax, dp[i][j]);
                }
            }
        }
        
        return omax * omax;
    }
};