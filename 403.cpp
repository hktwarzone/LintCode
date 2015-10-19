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
        vector<int> res;
        if (A.empty()) return res;
        int start = 0;
        int maxsum = A[0];
        int sum = A[0];
        int total = A[0];
        vector<int> resmax = {0, 0};
        vector<int> resmin = {0, 0};
        for (int i = 1; i < A.size(); i++) {
            if (sum < 0) {
                sum = 0;
                start = i;
            }
            sum += A[i];
            total += A[i];
            if (sum > maxsum) {
                maxsum = sum;
                resmax = {start, i};
            }
        }
        int minsum = A[0];
        sum = A[0];
        start = 0;
        for (int i = 1; i < A.size(); i++) {
            if (sum > 0) {
                sum = 0;
                start = i;
            }
            sum += A[i];
            if (sum < minsum) {
                minsum = sum;
                resmin = {start, i};
            }
        }   
        if (total == minsum) {
            return resmax;
        }
        else if (total - minsum <= maxsum) {
            return resmax;
        }
        else { //do not need to handle boundary: if minsum is on the bourdary, total-minsum <= maxsum
            return vector<int>{++resmin[1],--resmin[0]};
        }
    }
};
