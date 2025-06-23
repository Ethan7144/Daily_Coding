class Solution {
public:
    /*
     * Problem: Kth Largest Element in an Array (LeetCode 215)
     * Approach: Min Heap (Priority Queue)
     *
     * Time: O(n log k)
     * Space: O(k)
     */
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int num : nums)
        {
            minHeap.push(num); // add to the heap
            if (minHeap.size() > k)
            {
                minHeap.pop(); // remove smallest
            }
        }
        return minHeap.top(); // kth largest
    }
};