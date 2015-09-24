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
