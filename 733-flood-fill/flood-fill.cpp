/*
 * Problem: Flood Fill (LeetCode 733)
 * Approach: Iterative Depth-First Search (DFS) using a stack
 *
 * Summary:
 * - Given a starting pixel, we perform a DFS to change the color of all
 *   connected pixels with the same original color to a new target color.
 * - We use a stack for DFS to avoid recursion stack overflow in large images.
 * - For each pixel, we check if it's within bounds and has the original color.
 *   If so, we color it and push its 4 neighbors onto the stack.
 * - We return the modified image after processing.
 *
 * Time Complexity: O(m * n)
 *   - Each pixel is visited at most once.
 *
 * Space Complexity: O(m * n)
 *   - In the worst case, the entire image might be filled (stack size).
 */

class Solution {
public:
        vector<pair<int,int>> directions = {
            {0, 1}, // right
            {1, 0}, // Down
            {0, -1}, // left
            {-1, 0}, // up
        };

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];

        if(originalColor == color){
            return image;
        }
            dfs(image, sr, sc, originalColor, color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int r, int c, int originalColor, int newColor)
    {
        stack<pair<int, int>> st;

        st.push({r, c});

        while(!st.empty()) {
            // iterate thru the cloest ones, then change the color if it is the same pixel value.
            auto [r, c] = st.top();
            st.pop();

            if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size())
            {
                continue;
            }
            if (image[r][c] != originalColor){
                continue;
            }

            image[r][c] = newColor;

            for(auto [dr, dc] : directions){
                int newRow = r + dr;
                int newCol = c + dc;
                st.push({newRow, newCol});
            }

        }
    }
};