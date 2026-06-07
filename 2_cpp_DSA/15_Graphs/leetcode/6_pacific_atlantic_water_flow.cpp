class Solution {
    void dfs(int i, int j, set<pair<int, int>> &visited, vector<vector<int>> &heights) {
        visited.insert(make_pair(i, j));
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(int k = 0; k < directions.size(); k++) {
            int r = i + directions[k][0];
            int c = j + directions[k][1];

            if(r >= 0 && r < rows && c >= 0 && c < cols && visited.find(make_pair(r, c)) == visited.end() && heights[r][c] >= heights[i][j]) {
                dfs(r, c, visited, heights);
            }
        }
        
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        set<pair<int, int>> pacific;
        set<pair<int, int>> atlantic;

        // Traverse Rows
        for(int j = 0; j < cols; j++) {
            // int prev_height = heights[i][j];
            dfs(0, j, pacific, heights);
            dfs(rows-1, j, atlantic, heights);
        }

        // Traverse Cols 
        for(int i = 0; i< rows; i++) {
            // int prev_height = heights[i][j];
            dfs(i, 0, pacific, heights);
            dfs(i, cols-1, atlantic, heights);
        }

        vector<vector<int>> ans;
        for(auto it=pacific.begin(); it != pacific.end(); it++) {
            if(atlantic.find(*it) != atlantic.end()) {
                ans.push_back({it->first, it->second});
            }
        }
        return ans;
    }
};