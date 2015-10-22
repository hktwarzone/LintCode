/*
Post Office Problem
On one line there are n houses. Give you an array of integer means the the position of each house. 
Now you need to pick k position to build k post office, so that the sum distance of each house to the nearest post office 
is the smallest. Return the least possible sum of all distances between each village and its nearest post office.

Example
Given array a = [1,2,3,4,5], k = 2. return 3.

Challenge
Could you solve this problem in O(n^2) time ?
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        // Write your code here
        int n = A.size();
        if (n == 0 || k >= n) return 0;
        sort(A.begin(), A.end());
        vector<vector<int>> dis(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int mid = i + (j - i) / 2;
                for (int x = i; x <= j; x++) {
                    dis[i][j] += abs(A[x - 1] - A[mid - 1]);
                }
            }
        }
        vector<vector<int>> f(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; i++) {
            f[i][1] = dis[1][i];
        }
        for (int j = 2; j <= k; j++) {
            for (int i = j; i <= n; i++) {
                f[i][j] = f[1][j - 1] + dis[2][i];
                for (int x = 2; x < i; x++) {
                    f[i][j] = min(f[i][j], f[x][j - 1] + dis[x + 1][i]);
                }
            }
        }
        return f[n][k];
    }
};
