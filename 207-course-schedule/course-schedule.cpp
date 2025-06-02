class Solution {
public:
    /*
     * Problem: Course Schedule (LeetCode 207)
     * Approach: Kahn’s Algorithm (Topological Sort via BFS)
     *
     * Summary:
     * - Build a graph of course dependencies.
     * - Track in-degrees (number of prerequisites) for each course.
     * - Start with courses that have no prerequisites (in-degree 0).
     * - Remove them one-by-one and reduce in-degrees of their neighbors.
     * - If you can visit all courses, return true (no cycles).
     *
     * Time: O(n + e), Space: O(n + e)
     */

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);       // Graph: prereq → course
        vector<int> inDegree(numCourses, 0);           // In-degree count

        // Step 1: Build the graph and count in-degrees
        for (auto& pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            adjList[prereq].push_back(course);
            inDegree[course]++;
        }

        // Step 2: Start with courses that have no prerequisites
        queue<int> classes;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                classes.push(i);
        }

        int completed = 0;

        // Step 3: BFS to process courses
        while (!classes.empty()) {
            int curr = classes.front(); classes.pop();
            completed++;

            for (int neighbor : adjList[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    classes.push(neighbor);
            }
        }

        return completed == numCourses;
    }
};
