/*
Trapping Rain Water II

Given n x m non-negative integers representing an elevation map 2d where the area of each cell is 1 x 1, 
compute how much water it is able to trap after raining.

Example
Given 5*4 matrix

[12,13,0,12]
[13,4,13,12]
[13,8,10,12]
[12,13,12,12]
[13,13,13,13]
return 14.

*/

class Node {
public:
    int x;
    int y;
    int h;
    Node(int xx, int yy, int hh) {
        x = xx;
        y = yy;
        h = hh;
    }
};

class CompareNode {
public:
    bool operator()(Node& n1, Node& n2) {
        return (n1.h > n2.h);
    }
};

class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        // write your code here
        if (heights.empty() || heights[0].empty()) return 0;
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<Node, vector<Node>, CompareNode> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < m; i++) {
            q.push(Node(0, i, heights[0][i]));
            q.push(Node(n - 1, i, heights[n - 1][i]));
            visited[0][i] = true;
            visited[n - 1][i] = true;
        }
        for (int i = 0; i < n; i++) {
            q.push(Node(i, 0, heights[i][0]));
            q.push(Node(i, m - 1, heights[i][m - 1]));
            visited[i][0] = true;
            visited[i][m - 1] = true;
        }
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        int res = 0;
        while(!q.empty()) {
            Node curr_node = q.top();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int curr_x = curr_node.x + dx[i];
                int curr_y = curr_node.y + dy[i];
                if (curr_x >= 0 && curr_x < n && curr_y >= 0 && curr_y < m && !visited[curr_x][curr_y]) {
                    visited[curr_x][curr_y] = true;
                    q.push(Node(curr_x, curr_y, max(curr_node.h, heights[curr_x][curr_y])));
                    res += max(0, curr_node.h - heights[curr_x][curr_y]);
                }
            }
        }
        return res;
    }
};
