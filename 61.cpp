/*
Search for a Range
Given a sorted array of n integers, find the starting and ending position of a given target value.

If the target is not found in the array, return [-1, -1].

Have you met this question in a real interview? Yes
Example
Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].

Challenge
O(log n) time.
*/

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        int lb = lowerBound(A, target);
        int ub = upperBound(A, target);
        if (lb == ub) return vector<int>{-1, -1};
        else return {lb, ub - 1};
    }
private:
    int lowerBound(vector<int> &A, int target) {
        if (A.empty()) {return -1;}
        if (A[A.size() - 1] < target) {return A.size();}
        if (A[0] >= target) {return 0;}
        int left = 0;
        int right = A.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] >= target) {right = mid;}
            else {left = mid + 1;}
        }
        return left;
    }
    int upperBound(vector<int> &A, int target) {
        if (A.empty()) {return -1;}
        if (A[A.size() - 1] <= target) {return A.size();}
        if (A[0] > target) {return 0;}
        int left = 0;
        int right = A.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] > target) {right = mid;}
            else {left = mid + 1;}
        }
        return left;
    }
};
