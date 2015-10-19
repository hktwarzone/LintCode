/*
Building Outline
Given N buildings in a x-axis，each building is a rectangle and can be represented by a triple (start, end, height)，
where start is the start position on x-axis, end is the end position on x-axis and height is the height of the building. 
Buildings may overlap if you see them from far away，find the outline of them。

An outline can be represented by a triple, (start, end, height), where start is the start position on x-axis of the outline, 
end is the end position on x-axis and height is the height of the outline.

Example
Given 3 buildings：

[
  [1, 3, 3],
  [2, 4, 4],
  [5, 6, 1]
]
The outlines are：

[
  [1, 2, 3],
  [2, 4, 4],
  [5, 6, 1]
]
Note
Please merge the adjacent outlines if they have the same height and make sure different outlines cant overlap on x-axis.

*/

class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        vector<vector<int>> res;
        if (buildings.empty()) return res;
        vector<pair<int, int>> points;
        multiset<int> heights;
        for (int i = 0; i < buildings.size(); i++) {
            points.push_back(make_pair(buildings[i][0], -buildings[i][2]));
            points.push_back(make_pair(buildings[i][1], buildings[i][2]));
        }
        sort(points.begin(), points.end());
        heights.insert(0);
        int currHeight = 0;
        int prevHeight = 0;
        int prevStart = -1;
        for (int i = 0; i < points.size(); i++) {
            if (points[i].second < 0) { heights.insert(-points[i].second); }
            else { heights.erase(heights.find(points[i].second)); }
            currHeight = *heights.rbegin();
            if (prevHeight != currHeight) {
                if (prevStart != -1 && prevHeight > 0) {
                    res.push_back(vector<int>{prevStart, points[i].first, prevHeight});
                }
                prevStart = points[i].first;
                prevHeight = currHeight;
            }
        }
        return res;
    }
};
