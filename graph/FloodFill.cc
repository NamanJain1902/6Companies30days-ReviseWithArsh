class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            
        int currColor = image[sr][sc];
        image[sr][sc] = newColor;
        if(newColor == currColor) {
            return image;
        }
         
        vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(auto move: moves) {
            
            int dx = sr + move[0];
            int dy = sc + move[1];
               
            if(dx < 0 or dy < 0 or dx >= image.size() or dy >= image[0].size()) {
                continue;
            }
            if(image[dx][dy] == currColor){         
                floodFill(image, dx, dy, newColor);    
            }
        }
        return image;
    } 

    vector<vector<int>> floodFillDFStack(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int root_color = image[sr][sc];
        auto isValid = [&](int x, int y, vector<vector<int>> image) {
            return !(x < 0 || y < 0 || x >= image.size() || 
                        y >= image[0].size() || image[x][y] !=root_color);  
        };
        
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        stack<pair<int, int>> st;
        st.push({sr, sc});
        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        while(!st.empty()) {
            pair<int, int> tp = st.top();
            st.pop();
            
            visited[tp.first][tp.second] = true;
            
            for(auto move: moves) {
                int dx = tp.first + move[0];
                int dy = tp.second + move[1];
                
                if(isValid(dx, dy, image) and !visited[dx][dy] ){
                    st.push({dx, dy});
                    visited[dx][dy] = true;
                    image[dx][dy] = newColor;
                }
            }
        }
        return image;
    }
    vector<vector<int>> floodFillBFS(vector<vector<int>>& image, int sr, int sc, int newColor) {

        int root_color = image[sr][sc];
        
        auto isValid = [&](int x, int y, vector<vector<int>> image) {
            return !(x < 0 || y < 0 || x >= image.size() || 
                        y >= image[0].size() || image[x][y] !=root_color);  
        };
        
        
        int m = image.size();
        int n = image[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        
        vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            
            for(auto move: moves) {
                int dx = p.first + move[0];
                int dy = p.second + move[1];
                
                
                if(isValid(dx, dy, image) and visited[dx][dy] != true) {
                    q.push({dx, dy});
                    visited[dx][dy] = true;
                    image[dx][dy] = newColor;
                }
            }
        }
        
        return image;
    }
};