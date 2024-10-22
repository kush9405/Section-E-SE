class Solution {
public:

    /*if we look at this question in a completely opposite way, i.e water flowing
    from ocean to land, if the current cell is greater than the prev cell, only
    then water flows. */
    void helper(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<int>>& ocean) {
        if(i < 0 or j < 0 or i >= heights.size() or j >= heights[0].size() or ocean[i][j] == 1 or heights[i][j] < prev)
            return;
        
        // if(ocean[i][j] == 1)
        //     return;
        
        // if(height[i][j] < prev)
        //     return;
        
        ocean[i][j] = 1;

        helper(heights, i + 1, j, heights[i][j], ocean);
        helper(heights, i - 1, j, heights[i][j], ocean);
        helper(heights, i, j + 1, heights[i][j], ocean);
        helper(heights, i, j - 1, heights[i][j], ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        vector<vector<int>> pacific(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> atlantic(heights.size(), vector<int>(heights[0].size(), 0));

        for(int i = 0; i < heights[0].size(); ++i) {
            helper(heights, 0, i, -1, pacific);
            helper(heights, heights.size() - 1, i, INT_MIN, atlantic);
        }

        for(int j = 0; j < heights.size(); ++j) {
            helper(heights, j, 0, -1, pacific);
            helper(heights, j, heights[0].size() - 1, INT_MIN, atlantic);
        }
        
        for(int i = 0; i < heights.size(); ++i) {
            for(int j = 0; j < heights[0].size(); ++j) {
                if(pacific[i][j] == 1 and atlantic[i][j] == 1) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
