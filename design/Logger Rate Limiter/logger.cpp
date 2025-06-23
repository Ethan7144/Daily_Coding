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