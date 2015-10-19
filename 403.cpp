/*
Continuous Subarray Sum II
Given an integer array, find a continuous rotate subarray where the sum of numbers is the biggest. 
Your code should return the index of the first number and the index of the last number. 
(If their are duplicate answer, return anyone. The answer can be rorate array or non- rorate array)

Example
Give [3, 1, -100, -3, 4], return [4,1].
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        int start = 0;
        int maxsum = INT_MIN;
        int sum = 0;
        vector<int> resmax = {0, 0};
        vector<int> resmin = {0, 0};
        for (int i = 0; i < A.size(); i++) {
            if (sum < 0) {
                sum = 0;
                start = i;
            }
            sum += A[i];
            if (sum > maxsum) {
                maxsum = sum;
                resmax[0] = start;
                resmax[1] = i;
            }
        }
        
        int minsum = INT_MAX;
        sum = 0;
        start = 0;
        int total = 0;
        for (int i = 0; i < A.size(); i++) {
            if (sum > 0) {
                sum = 0;
                start = i;
            }
            sum += A[i];
            total += A[i];
            if (sum < minsum) {
                minsum = sum;
                resmin[0] = start;
                resmin[1] = i;
            }
        }        
        if (total - minsum < maxsum) {
            return resmax;
        }
        else {
            if (total == minsum) {
                return resmax;
            }
            else {
                vector<int> res;
                res.push_back((resmin[1] + 1) % A.size());
                res.push_back(resmin[0] == 0 ? A.size() - 1 : resmin[0] - 1);
                return res;
            }
        }
    }
};
