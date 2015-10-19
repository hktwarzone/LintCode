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
        int left = 1;
        int right = n - 2;
        int local = 0;
        while(left < right) {
            int mid = left + (right - left) / 2;
            local = findPeak(A[mid]);
            if (A[mid][local] < A[mid - 1][local]) {
                right = mid - 1;
            }
            else if (A[mid][local] < A[mid + 1][local]) {
                left = mid + 1;
            }
            else {
                res.push_back(mid);
                res.push_back(local);
                return res;
            }
        }
        res.push_back(left);
        res.push_back(findPeak(A[left]));
        return res;
    }
private:
    int findPeak(vector<int>& A) {
        int m = A.size();
        int left = 1;
        int right = m - 2;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] < A[mid - 1]) {
                right = mid - 1;
            }
            else if (A[mid] < A[mid + 1]) {
                left = mid + 1;
            }
            else return mid;
        }
        return left;
    }
};
