class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string result;
      
        // Calculate number of columns in the matrix
        int columns = encodedText.size() / rows;
        for (int startCol = 0; startCol < columns; ++startCol) {
    
            int row = 0;
            int col = startCol;
          
            while (row < rows && col < columns) {
          
                int index = row * columns + col;
                result += encodedText[index];
              
                // Move to next position in the diagonal
                row++;
                col++;
            }
        }
      

        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
      
        return result;
    }
};
