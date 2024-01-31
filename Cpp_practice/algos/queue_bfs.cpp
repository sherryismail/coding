#include <iostream>
#include <queue>
using namespace std;
typedef struct {
    int val;
    struct Node * left;
    struct Node * right;
} Node;//doubly Linked List
int main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(7);
    cout << endl<< "q.size() : " << q.size();
    cout << "\ngquiz.front() : " << q.front()<<endl;
    cout << "\ngquiz.back() : " << q.back() <<endl;
    cout << "\ngquiz.pop() : ";
    q.pop();//delete the top of the list
    //cout << "Queue is" << (int)q.empty() == 0? "empty":"NOT empty";
    struct Node * head = NULL;
    insert()

}
/* https://leetcode.com/problems/number-of-islands/description/
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 You may assume all four edges of the grid are all surrounded by water.*/

int bfs_algo(Node * head, int target){
    queue<Node> q; // store all nodes which are waiting to be processed
    int step = 0;// number of steps neeeded from root to current node
    //add root to the queue
    q.push(*head);
    while(q.size() != 0)
    {
        // iterate the nodes which are already in the queue
        int size = q.size();
        for (int i=0; i < size; i++)
        {
            Node current = q.front();
            if(current.val == target)
                return step;
            q.push(*(current.left));
            q.push(*(current.right));
            q.pop();
        }
        step++;
    }
    return -1;
}

    int bfs(vector<vector<char>>& grid) {
        if(grid.empty() == 0 || grid[0].empty())
            return 0;
        
        int N= grid.size();
        int M= grid[0].size();
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};//offset to down, right, up, left
        int islands = 0;
        for(int r =0; r<N; r++)
        {
            for(int c=0; c<M; c++)
            {
                if(grid[r][c] == '1')//detect first island edge
                {
                    queue<pair<int,int>> q;
                    q.push({r,c});
                    grid[r][c] = '0';//or set to visited '#'
                    while(!q.empty())
                    {
                        pair<int,int> curr = q.front();
                        q.pop();//delete FIFO element
                        
                        int row = curr.first;
                        int col = curr.second;
                        for(int i=0; i < directions.size(); i++)
                        {
                            int nextRow = row + directions[i][0];//check adjacent neighbours
                            int nextCol = col + directions[i][1];
                            if(nextRow <0 || nextRow >= N || nextCol < 0 || nextCol >=M)
                                continue;
                            if(grid[nextRow][nextCol] == '1')
                            {
                                grid[nextRow][nextCol] = '0';//set to visited
                                q.push({nextRow,nextCol});//this was continuation of island for while{}
                            }
                        }//end of 4 for-directions
                    }//end while
                    islands++;
                }//end if
            }//end of all cols
        }//end of all rows
        return islands;      
    }
//or go depth first by setting values to '0' first
int dfs(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
    }

    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }

/*
i, j be the coordinate (p.first, p.second)
k = 0 ; new coordinates : i+0, j+1 (right)
k = 1 ; new coordinates : i+1, j+0 (down)
k = 2 ; new coordinates : i+0, j-1 (left)
k = 3 ; new coordinates : i-1, j+0 (up)
Hence we covered all four directions
*/