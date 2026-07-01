class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      //i am thinking to check columns and rows in two different loops, with 
      //unordered sets which will immediately notify me if there is a DUPE
      vector<unordered_set<int>> columns;
      vector<unordered_set<int>> rows;
      vector<unordered_set<int>> subbox;

      rows.resize(9);
      columns.resize(9);
      subbox.resize(9);

      //column checks
      for(size_t i = 0; i < 9; i++) {
        for(size_t j = 0; j < 9; j++) {
            if(isdigit(board[j][i])) {
                int digit = board[j][i] - '0';
                auto isUnique = columns[i].insert(digit);
                if(!isUnique.second) {return false;}
            }
        }
      }

      //row checks
      for(size_t i = 0; i < 9; i++) {
        for(size_t j = 0; j < 9; j++) {
            if(isdigit(board[i][j])) {
                int digit = board[i][j] - '0';
                auto isUnique = rows[i].insert(digit);
                if(!isUnique.second) {return false;}
            }
        }
      }
    
      //lastly, the very headache inducing subbox check
      for(size_t i = 0; i < 9; i++) {
        int startRow = i / 3;
        int startCol = i % 3;
        for(size_t j = 0; j < 3; j++) {
            for(size_t k = 0; k < 3; k++) {
                if(isdigit(board[3*startRow + j][3*startCol + k])) {
                    int digit = board[3*startRow + j][3*startCol + k] - '0';
                    auto isUnique = subbox[i].insert(digit);
                    if(!isUnique.second) {return false;}
                }
            }
        }
      }
      //there are for sure no dupes!
      return true;
    }
};
