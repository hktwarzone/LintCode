/*
Nuts & Bolts Problem 
Given a set of n nuts of different sizes and n bolts of different sizes. 
There is a one-one mapping between nuts and bolts. Comparison of a nut to another nut or a bolt to another bolt is not allowed. 
It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.

We will give you a compare function to compare nut with bolt.

Example
Given nuts = ['ab','bc','dd','gg'], bolts = ['AB','GG', 'DD', 'BC'].
Your code should find the matching bolts and nuts.
one of the possible return:
nuts = ['ab','bc','dd','gg'], bolts = ['AB','BC','DD','GG'].
we will tell you the match compare function. If we give you another compare function.
the possible return is the following:
nuts = ['ab','bc','dd','gg'], bolts = ['BC','AA','DD','GG'].
So you must use the compare function that we give to do the sorting.
The order of the nuts or bolts does not matter. You just need to find the matching bolt for each nut.
*/

/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        if (nuts.size() != bolts.size()) return;
        cmpsort(nuts, bolts, 0, nuts.size() - 1, compare);
    }
private:
    void cmpsort(vector<string>& n, vector<string>& b, int start, int end, Comparator compare) {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        string pivot = b[mid];
        int left = start;
        int right = end;
        while(true) {
            while (left < right && compare.cmp(n[left], pivot) < 0) { left++; }
            while (left < right && compare.cmp(n[right], pivot) > 0) { right--; }
            if (left < right) {
                swap(n[left], n[right]);
            }
            else { break; }
        }
        pivot = n[right];
        left = start;
        right = end;
        while(true) {
            while (left < right && compare.cmp(pivot, b[left]) > 0) { left++; }
            while (left < right && compare.cmp(pivot, b[right]) < 0) { right--; }
            if (left < right) {
                swap(b[left], b[right]);
            }
            else { break; }
        }
        cmpsort(n, b, start, right - 1, compare);
        cmpsort(n, b, right + 1, end, compare);
    }
};
