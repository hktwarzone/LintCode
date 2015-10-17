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
        map<int, int> maxHeap;
        map<int, int> minHeap;
        int maxCount = 0;
        int minCount = 0;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                int toDelete = nums[i - k];
                if (maxHeap.find(toDelete) != maxHeap.end()) {
                    if (maxHeap[toDelete] == 1) {
                        maxHeap.erase(maxHeap.find(toDelete));
                    }
                    else {
                        maxHeap[toDelete]--;
                    }
                    maxCount--;
                }
                else {
                    if (minHeap[toDelete] == 1) {
                        minHeap.erase(minHeap.find(toDelete));
                    }
                    else {
                        minHeap[toDelete]--;
                    }
                    minCount--;
                    
                }
                rebalance(maxHeap, minHeap, maxCount, minCount);
            }
            
            if (maxCount == 0 || nums[i] <= maxHeap.rbegin()->first) {
                maxHeap[nums[i]]++;
                maxCount++;
            }
            else {
                minHeap[nums[i]]++;
                minCount++;
            }
            rebalance(maxHeap, minHeap, maxCount, minCount);
            
            if (i >= k - 1) {
                res.push_back(maxHeap.rbegin()->first);
            }
        }
        return res;
    }
    
private:
    void rebalance(map<int, int>& maxHeap, map<int, int>& minHeap, int& maxCount, int& minCount) {
        if (maxCount < minCount) {
            int target = minHeap.begin()->first;
            if (minHeap[target] == 1) {
                minHeap.erase(minHeap.find(target));
            }
            else {
                minHeap[target]--;
            }
            minCount--;
            maxHeap[target]++;
            maxCount++;
        }
        if (maxCount > minCount + 1) {
            int target = maxHeap.rbegin()->first;
            if (maxHeap[target] == 1) {
                maxHeap.erase(maxHeap.find(target));
            }
            else {
                maxHeap[target]--;
            }
            maxCount--;
            minHeap[target]++;
            minCount++;
        }
            
    }
};
