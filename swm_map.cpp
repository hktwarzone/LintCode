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
