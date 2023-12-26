class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        
        vector<int> ways(target+1);
        // i'm not interested in a sum > target 
        // if only one dice, this is how to compute 
        for (int i = 1; i <= min(k, target); i++) ways[i] = 1;
        for (int i = 1; i < n; i++){
            // build the new ways list with the new dice added 
            vector<int> new_ways(target + 1);
            for (int j = target; j >= 1; j--){
                // do I have a list of sum = j? 
                if (ways[j] == 0) continue;
                for (int new_dice = k; new_dice >= 1; new_dice--){
                    // to not access an index graeter than target 
                    if (new_dice + j <= target)
                        new_ways[new_dice + j] = (new_ways[new_dice + j] + ways[j])%mod;
                }
            }
            // update the ways list 
            ways = new_ways;
        }
        return ways[target];
    }
};

class Solution_recursive {
public:
    int mod = 1e9 + 7;
    int ways[31][1001];
    int solve(int remDices, int maxValue, int neededSum){
        // if I used all my dices, should return 1 if I reached the desierd sum
        if (remDices == 0)
            return neededSum == 0;
        // if I get more than the sum I need, no need to continue 
        if (neededSum <= 0) return 0;
        // if ways != -1 it means I computed it before so return
        if (ways[remDices][neededSum] != -1) return ways[remDices][neededSum];
        ways[remDices][neededSum] = 0;
        for (int dice = 1; dice <= maxValue; dice++){
            // add the ways if I used [dice] for in the current Dice   
            ways[remDices][neededSum] = (ways[remDices][neededSum] + 
            solve(remDices - 1, maxValue, neededSum - dice)) % mod;
        }
        return ways[remDices][neededSum];
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(ways, -1, sizeof ways);
        return solve(n, k, target);
    }
};
