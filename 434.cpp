/*
Number of Islands II
Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). 
Originally, the 2D matrix is all 0 which means there is only sea in the matrix. 
The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the 
grid matrix[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each operator.

Example
Given n = 3, m = 3, array of pair A = [(0,0),(0,1),(2,2),(2,1)].

return [1,1,2,2].

Note
0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. 
We only consider up/down/left/right adjacent.
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        // Write your code here
        int t = operators.size();
        vector<int> numI;
        vector<vector<int>> board(n, vector<int>(m, 0));
        vector<int> father(n * m, 0);
        for (int i = 0; i < n * m; i++) {
            father[i] = i;
        }
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        int res = 0;
        for (int i = 0; i < t; i++) {
            int ox = operators[i].x;
            int oy = operators[i].y;
            int ido = id(m, ox, oy);
            board[ox][oy] = 1;
            res++;
            for (int j = 0; j < 4; j++) {
                int nx = ox + dx[j];
                int ny = oy + dy[j];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 1) {
                    int idd = id(m, nx, ny);
                    int of = compressed_find(father, ido);
                    int nf = compressed_find(father, idd);
                    if (of != nf) {
                        res--;
                        find_union(father, ido, idd);
                    }
                }
            }
            numI.push_back(res);
        }
        return numI;
    }
private:
    int id(int& m, int x, int y) {
        return x * m + y;
    }
    int compressed_find(vector<int>& father, int x) {
        int parent = father[x];
        while(parent != father[parent]) {
            parent = father[parent];
        }
        int tmp = -1;
        int fa = father[x];
        while(fa != father[fa]) {
            tmp = father[fa];
            father[fa] = parent;
            fa = tmp;
        }
        return parent;
    }
    void find_union(vector<int>& father, int x, int y) {
        int fx = compressed_find(father, x);
        int fy = compressed_find(father, y);
        if (fx != fy) {
            father[fx] = fy;
        }
    }
};
