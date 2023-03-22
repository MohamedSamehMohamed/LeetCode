class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long curMass = mass;
        for (int i = 0; i < asteroids.size(); i++){
            if (curMass < asteroids[i]) return 0;
            curMass += asteroids[i];
        }
        return 1;
    }
};