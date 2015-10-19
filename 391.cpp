/*
Number of Airplanes in the Sky

Given an interval list which are flying and landing time of the flight. How many airplanes are on the sky at most?

Have you met this question in a real interview? Yes
Example
For interval list [[1,10],[2,3],[5,8],[4,7]], return 3

Note
If landing and flying happens at the same time, we consider landing should happen at first.
*/
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        vector<pair<int, int>> times;
        for (int i = 0; i < airplanes.size(); i++) {
            times.push_back(make_pair(airplanes[i].start, 1));
            times.push_back(make_pair(airplanes[i].end, -1));
        }
        int res = 0;
        int count = 0;
        sort(times.begin(), times.end());
        for (int i = 0; i < times.size(); i++) {
            count += times[i].second;
            res = max(res, count);
        }
        return res;
    }
};
