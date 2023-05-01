class Solution {
public:
    double average(vector<int>& salary) {
      int sum = 0, mx = salary[0], mn = salary[0];
      for (int i = 0; i < salary.size(); i++){
        sum += salary[i];
        mn = min(mn, salary[i]);
        mx = max(mx, salary[i]);
      }
      return 1.0 * (sum - mx - mn) / (salary.size() - 2);
    }
};