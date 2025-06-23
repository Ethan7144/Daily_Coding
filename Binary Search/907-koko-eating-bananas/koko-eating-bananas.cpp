class Solution {
public:
    /**
     * This function determines the minimum integer eating speed 'k'
     * such that Koko can eat all the banana piles within 'h' hours.
     *
     * Approach:
     * - Binary search is applied to the answer space of possible eating speeds.
     * - The range of speeds is from 1 to the size of the largest pile.
     * - For each candidate speed 'k', the total hours needed to eat all piles
     *   is calculated using ceiling division.
     * - The goal is to find the smallest 'k' for which total hours <= h.
     *
     * Time Complexity:  O(n * log m)
     *     - n = number of piles
     *     - m = maximum bananas in a pile
     *
     * Space Complexity: O(1)
     *     - Uses a constant amount of extra space (excluding input)
     */
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end()); // Max possible eating speed

        while (left < right) {
            int mid = left + (right - left) / 2; // Candidate eating speed
            int hours = 0;

            // Calculate total hours Koko needs at speed 'mid'
            for (int pile : piles) {
                // Ceiling division: how many hours to finish this pile at speed 'mid'
                hours += (pile + mid - 1) / mid;
            }

            if (hours <= h) {
                // If Koko can finish on time, try a slower speed
                right = mid;
            } else {
                // If not, she must eat faster
                left = mid + 1;
            }
        }

        // 'left' is the minimum speed that works
        return left;
    }
};
