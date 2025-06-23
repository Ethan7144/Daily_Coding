class Logger {
    unordered_map<string, int> lastPrinted;
    public:

    bool shouldPrintMessage(int timestamp, string message){
        if(lastPrinted.count(message) && timestamp - lastPrinted[message] < 10)
            return false;
        lastPrinted[message] = timestamp;
        return true;
    }
}


// Now the system is multi-user, and each user has their own stream of messages.
// Rate limit per user, and per message, same with the 10 second rule.

// For a given user and message, return true if it hasn't been printed
// in the last 10 seconds. Uses a nested map to track last print times per user.
// Time: O(1), Space: O(U * M) where U = users, M = messages per user.

class Logger {
    private:
    unordered_map<string, unordered_map<string, int>> userLogs;
    public:

    bool shouldPrintMessage(int timestamp, string userId, string message){
        if(userLogs[userId].count(message) && timestamp - userLogs[userId][message] < 10)
            return false;
        userLogs[userId][message] = timestamp;
        return true;
    }
}

// Now what if we want to delete old messages?

class Logger {
private:
    unordered_map<string, unordered_map<string, int>> userLogs;
    queue<tuple<int, string, string>> recentMessages;

public:
    // Checks if message can be printed for a given user based on last 10s
    bool shouldPrintMessage(int timestamp, string userId, string message) {
        // Clean up expired entries from the queue
        while (!recentMessages.empty() && timestamp - get<0>(recentMessages.front()) >= 10) {
            auto [oldTime, uid, msg] = recentMessages.front();
            recentMessages.pop();
            if (userLogs[uid][msg] == oldTime) {
                userLogs[uid].erase(msg);
            }
        }

        // Check current message timing
        auto& userMap = userLogs[userId];
        if (userMap.count(message) && timestamp - userMap[message] < 10)
            return false;

        // Log and queue the new message
        userMap[message] = timestamp;
        recentMessages.push({timestamp, userId, message});
        return true;
    }
};

