/*
Find Peak Element II
There is an integer matrix which has the following features:

The numbers in adjacent positions are different.
The matrix has n rows and m columns.
For all i < m, A[0][i] < A[1][i] && A[n - 2][i] > A[n - 1][i].
For all j < n, A[j][0] < A[j][1] && A[j][m - 2] > A[j][m - 1].
We define a position P is a peek if:

A[j][i] > A[j+1][i] && A[j][i] > A[j-1][i] && A[j][i] > A[j][i+1] && A[j][i] > A[j][i-1]
Find a peak element in this matrix. Return the index of the peak.

Have you met this question in a real interview? Yes
Example
Given a matrix:

[
  [1 ,2 ,3 ,6 ,5],
  [16,41,23,22,6],
  [15,17,24,21,7],
  [14,18,19,20,10],
  [13,14,11,10,9]
]
return index of 41 (which is [1,1]) or index of 24 (which is [2,2])

Note
The matrix may contains multiple peeks, find any of them.

Challenge
Solve it in O(n+m) time.

If you come up with an algorithm that you thought it is O(n log m) or O(m log n), 
can you prove it is actually O(n+m) or propose a similar but O(n+m) algorithm?
*/

class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int> > A) {
        // write your code here
        vector<int> res;
        if (A.empty() || A[0].empty()) return res;
        int n = A.size();
        int m = A[0].size();
        int i = 1;
        int j = 1;
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        while(inBound(i, j, n, m)) {
            int max = INT_MIN;
            int maxindex = -1;
            for (int k = 0; k < 4; k++) {
                if (A[i + dx[k]][j + dy[k]] > max) {
                    max = A[i + dx[k]][j + dy[k]];
                    maxindex = k;
                }
            }
            if (maxindex >= 0 && A[i][j] > A[i + dx[maxindex]][j + dy[maxindex]]) {
                res.push_back(i);
                res.push_back(j);
                break;
            }
            else if (maxindex == -1) break;
            i += dx[maxindex];
            j += dy[maxindex];
        }
        return res;
    }
private:
    bool inBound(int x, int y, int& n, int& m) {
        return (x > 0 && y > 0 && x < n - 1 && y < m - 1);
    }
};
