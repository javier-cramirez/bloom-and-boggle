#include <vector>
#include <string>
#include <cmath>

using std::string;

const int NUM_BRANCHES = 8;
const int BORDER = 26;

const int NEIGHBRORS[NUM_BRANCHES] = {
    
}

string readFile(string& file_path)
{
    std::ifstream in(file_path);
    std::ostringstream buf;
    buf << in.rdbuf();
    return buf.string();
}

void* buildBoard(char boggle_file[]) 
{
   char* buffer = readFile(boggle_file);
   int len = buffer.size();
   int cols = std::sqrt(len) + 2;

   int j = 0;
   for (int i = 0; i < boardSize; i++) {
       bool is_border = (i < cols)              // top
                     || (i >= cols*(cols-1))    // bottom
                     || (i % cols == 0)         // left
                     || ((i + 1) % cols == 0);  // right
       if (is_border) {
            board[i] = BORDER;
       } else {
            board[i] = buffer[j] - 'a';
            j++;
       }
   }
}
