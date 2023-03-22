class AuthenticationManager {
public:
    int timeToLive;
    unordered_map<string, int> mp;
    multiset<int> times;
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + timeToLive;
        times.insert(currentTime + timeToLive);
    }
    
    void renew(string tokenId, int currentTime) {
        if (mp[tokenId] > currentTime){
            times.erase(mp[tokenId]);
            generate(tokenId, currentTime);
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        if (times.empty()) return 0;
        auto it = times.end();
        it--;
        int unExpiredTokens = 0;
        while (1){
            if (*it <= currentTime) break;
            unExpiredTokens++;
            if (it == times.begin()) break;
            it--;
        }
        return unExpiredTokens;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */