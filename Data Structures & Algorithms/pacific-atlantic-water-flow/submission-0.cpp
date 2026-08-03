class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>>pacificQueue;
        queue<pair<int,int>>atlanticQueue;

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacificVisited(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlanticVisited(rows, vector<bool>(cols, false));

        for(int j = 0; j < cols; j++) {
            pacificQueue.push({0,j});
            pacificVisited[0][j] = true;
        }
        for(int i = 0; i < rows; i++) {
            pacificQueue.push({i,0});
            pacificVisited[i][0] = true;
        }

        for(int j = 0; j < cols; j++) {
            atlanticQueue.push({rows-1,j});
            atlanticVisited[rows-1][j] = true;
        }
        for(int i = 0; i < rows; i++) {
            atlanticQueue.push({i,cols-1});
            atlanticVisited[i][cols-1] = true;
        }

        

        while(!pacificQueue.empty()) {
            auto elementOfPacific = pacificQueue.front();

            pacificQueue.pop();

            int rowOfPacific = elementOfPacific.first;
            int colOfPacific = elementOfPacific.second;

            if(rowOfPacific-1 >= 0 && 
            rowOfPacific-1 < rows && 
            colOfPacific >= 0 && 
            colOfPacific < cols && 
            heights[rowOfPacific-1][colOfPacific] >= heights[rowOfPacific][colOfPacific] &&
            !pacificVisited[rowOfPacific-1][colOfPacific]) {
                pacificVisited[rowOfPacific-1][colOfPacific] = true;
                pacificQueue.push({rowOfPacific-1,colOfPacific});
            }

            if(rowOfPacific+1 >= 0 && 
            rowOfPacific+1 < rows && 
            colOfPacific >= 0 && 
            colOfPacific < cols && 
            heights[rowOfPacific+1][colOfPacific] >= heights[rowOfPacific][colOfPacific] &&
            !pacificVisited[rowOfPacific+1][colOfPacific]) {
                pacificVisited[rowOfPacific+1][colOfPacific] = true;
                pacificQueue.push({rowOfPacific+1,colOfPacific});
            }

            if(rowOfPacific >= 0 && 
            rowOfPacific < rows && 
            colOfPacific-1 >= 0 && 
            colOfPacific-1 < cols && 
            heights[rowOfPacific][colOfPacific-1] >= heights[rowOfPacific][colOfPacific] &&
            !pacificVisited[rowOfPacific][colOfPacific-1]) {
                pacificVisited[rowOfPacific][colOfPacific-1] = true;
                pacificQueue.push({rowOfPacific,colOfPacific-1});
            }

            if(rowOfPacific >= 0 && 
            rowOfPacific < rows && 
            colOfPacific+1 >= 0 && 
            colOfPacific+1 < cols && 
            heights[rowOfPacific][colOfPacific+1] >= heights[rowOfPacific][colOfPacific] &&
            !pacificVisited[rowOfPacific][colOfPacific+1]) {
                pacificVisited[rowOfPacific][colOfPacific+1] = true;
                pacificQueue.push({rowOfPacific,colOfPacific+1});
            }
        }

        while(!atlanticQueue.empty()) {
            auto elementOfAtlantic = atlanticQueue.front();

            atlanticQueue.pop();

            int rowOfAtlantic = elementOfAtlantic.first;
            int colOfAtlantic = elementOfAtlantic.second;

            if(rowOfAtlantic-1 >= 0 && 
            rowOfAtlantic-1 < rows && 
            colOfAtlantic >= 0 && 
            colOfAtlantic < cols && 
            heights[rowOfAtlantic-1][colOfAtlantic] >= heights[rowOfAtlantic][colOfAtlantic] &&
            !atlanticVisited[rowOfAtlantic-1][colOfAtlantic]) {
                atlanticVisited[rowOfAtlantic-1][colOfAtlantic] = true;
                atlanticQueue.push({rowOfAtlantic-1,colOfAtlantic});
            }

            if(rowOfAtlantic+1 >= 0 && 
            rowOfAtlantic+1 < rows && 
            colOfAtlantic >= 0 && 
            colOfAtlantic < cols && 
            heights[rowOfAtlantic+1][colOfAtlantic] >= heights[rowOfAtlantic][colOfAtlantic] &&
            !atlanticVisited[rowOfAtlantic+1][colOfAtlantic]) {
                atlanticVisited[rowOfAtlantic+1][colOfAtlantic] = true;
                atlanticQueue.push({rowOfAtlantic+1,colOfAtlantic});
            }

            if(rowOfAtlantic >= 0 && 
            rowOfAtlantic < rows && 
            colOfAtlantic+1 >= 0 && 
            colOfAtlantic+1 < cols && 
            heights[rowOfAtlantic][colOfAtlantic+1] >= heights[rowOfAtlantic][colOfAtlantic] &&
            !atlanticVisited[rowOfAtlantic][colOfAtlantic+1]) {
                atlanticVisited[rowOfAtlantic][colOfAtlantic+1] = true;
                atlanticQueue.push({rowOfAtlantic,colOfAtlantic+1});
            }

            if(rowOfAtlantic >= 0 && 
            rowOfAtlantic < rows && 
            colOfAtlantic-1 >= 0 && 
            colOfAtlantic-1 < cols && 
            heights[rowOfAtlantic][colOfAtlantic-1] >= heights[rowOfAtlantic][colOfAtlantic] &&
            !atlanticVisited[rowOfAtlantic][colOfAtlantic-1]) {
                atlanticVisited[rowOfAtlantic][colOfAtlantic-1] = true;
                atlanticQueue.push({rowOfAtlantic,colOfAtlantic-1});
            }
        }
        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacificVisited[i][j] && atlanticVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
