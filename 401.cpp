/*
Kth Smallest Number in Sorted Matrix

Find the kth smallest number in at row and column sorted matrix.

Have you met this question in a real interview? Yes
Example
Given k = 4 and a matrix:

[
  [1 ,5 ,7],
  [3 ,7 ,8],
  [4 ,8 ,9],
]
return 5

Challenge
O(k log n), n is the maximal number in width and height.
*/

class Node {
public:
    int x;
    int y;
    int v;
    Node(int xx, int yy, int vv) {
        x = xx;
        y = yy;
        v = vv;
    }
};

class CompareNode {
public:
    bool operator()(Node& n1, Node& n2) {
        return (n1.v > n2.v);
    }
};

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        if (matrix.empty() || matrix[0].empty()) return -1;
        if (k == 1) return matrix[0][0];
        int n = matrix.size();
        int m = matrix[0].size();
        priority_queue<Node, vector<Node>, CompareNode> q;
        set<pair<int, int>> visited;
        q.push(Node(0, 0, matrix[0][0]));
        visited.insert(make_pair(0, 0));
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        for (int i = 0; i < k - 1; i++) {
            Node curr = q.top();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nx = curr.x + dx[j];
                int ny = curr.y + dy[j];
                if (inBound(nx, ny, n, m) && visited.find(make_pair(nx, ny)) == visited.end()) {
                    visited.insert(make_pair(nx, ny));
                    q.push(Node(nx, ny, matrix[nx][ny]));
                }
            }
        }
        return q.top().v;
    }
private:
    bool inBound(int& nx, int& ny, int& n, int& m) {
        return (nx >= 0 && ny >= 0 && nx < n && ny < m);
    }
};
