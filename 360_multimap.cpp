/*
Sliding Window Median
Given an array of n integer, and a moving window(size k), move the window at each iteration from the start of the array, 
find the median of the element inside the window at each moving. 
(If there are even numbers in the array, return the N/2-th number after sorting the element in the window. )
Example
For array [1,2,7,8,5], moving window size k = 3. return [2,7,7]
At first the window is at the start of the array like this
[ | 1,2,7 | ,8,5] , return the median 2;
then the window move one step forward.
[1, | 2,7,8 | ,5], return the median 7;
then the window move one step forward again.
[1,2, | 7,8,5 | ], return the median 7;
Challenge
O(nlog(n)) time
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        multiset<int, less<int>> minHeap;
        multiset<int, greater<int>> maxHeap;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                int toDelete = nums[i - k];
                if (maxHeap.find(toDelete) != maxHeap.end()) {
                    maxHeap.erase(maxHeap.find(toDelete));
                    if (minHeap.size() > maxHeap.size()) {
                        maxHeap.emplace(*minHeap.begin());
                        minHeap.erase(minHeap.begin());
                    }
                }
                else {
                    minHeap.erase(minHeap.find(toDelete));
                    if (maxHeap.size() > 1 + minHeap.size()) {
                        minHeap.emplace(*maxHeap.begin());
                        maxHeap.erase(maxHeap.begin());
                    }
                }
            }
            
            if (maxHeap.empty() || nums[i] <= *(maxHeap.begin())) {
                maxHeap.emplace(nums[i]);
                if (maxHeap.size() > 1 + minHeap.size()) {
                    minHeap.emplace(*maxHeap.begin());
                    maxHeap.erase(maxHeap.begin());
                }
            }
            else {
                minHeap.emplace(nums[i]);
                if (minHeap.size() > maxHeap.size()) {
                    maxHeap.emplace(*minHeap.begin());
                    minHeap.erase(minHeap.begin());
                }
            }
            
            if (i >= k - 1) {
                res.push_back(*maxHeap.begin());
            }
        }
        return res;
    }
};
