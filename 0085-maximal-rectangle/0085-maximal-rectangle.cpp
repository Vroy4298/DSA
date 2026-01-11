class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int numCols = matrix[0].size();
        vector<int> heights(numCols);  // Heights array for histogram calculation
        int maxArea = 0;
      
        // Process each row to build histogram heights
        for (auto& row : matrix) {
            for (int col = 0; col < numCols; ++col) {
                if (row[col] == '1') {
                    // Increment height if current cell is '1'
                    ++heights[col];
                } else {
                    // Reset height to 0 if current cell is '0'
                    heights[col] = 0;
                }
            }
            // Calculate max rectangle area for current histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
      
        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        stack<int> indexStack;  
        vector<int> leftBoundary(n, -1);  
        vector<int> rightBoundary(n, n);   
      
       
        for (int i = 0; i < n; ++i) {
            while (!indexStack.empty() && heights[indexStack.top()] >= heights[i]) {
              
                rightBoundary[indexStack.top()] = i;
                indexStack.pop();
            }
            if (!indexStack.empty()) {
                leftBoundary[i] = indexStack.top();
            }
          
            indexStack.push(i);
        }
        for (int i = 0; i < n; ++i) {
            int width = rightBoundary[i] - leftBoundary[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
      
        return maxArea;
    }
};
