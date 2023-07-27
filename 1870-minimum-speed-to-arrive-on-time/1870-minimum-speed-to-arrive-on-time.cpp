class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // sum(d / speed) <= hour
        int l = 1, r = 1e7 + 1, m, speed = -1;
        while (l <= r){
            m = (l+r) >> 1;
            double total = 0;
            for (int i = 0; i < dist.size(); i++){
                if (i)
                    total = ceil(total);
                total += 1.0*dist[i] / m;
                if (total > hour) break;
            }
            if (total <= hour)
                speed = m, r = m - 1;
            else 
                l = m + 1;
        }
        return speed;
    }
};