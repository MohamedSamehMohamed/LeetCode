class SolutionOne {
public:
    bool isPathCrossing(string path) {
        int x, y;
        x = y = 0;
        vector<vector<int>> vec;
        vec.push_back({x, y});
        for (int i = 0; i < path.size(); i++){
            if (path[i] == 'N') y++;
            if (path[i] == 'S') y--;
            if (path[i] == 'E') x++;
            if (path[i] == 'W') x--;
            vec.push_back({x, y});
        }
        
        for (int i = 0; i < vec.size(); i++){
            for (int j = i + 1; j < vec.size(); j++)
                if (vec[i][0] == vec[j][0] && vec[i][1] == vec[j][1])
                    return 1;
        }
        return 0;
    }
};

class Solution {
public:
    bool isPathCrossing(string path) {
        int x, y;
        x = y = 0;
        vector<vector<int>> vec;
        vec.push_back({x, y});
        for (int i = 0; i < path.size(); i++){
            if (path[i] == 'N') y++;
            if (path[i] == 'S') y--;
            if (path[i] == 'E') x++;
            if (path[i] == 'W') x--;
            vec.push_back({x, y});
        }
       
        for (int i = 1; i < vec.size(); i++){
            if (vec[i][0] == vec[i-1][0] && vec[i][1] == vec[i-1][1])
                return 1;
        }
        return 0;
    }
};

class SolutionTwo {
public:
    bool isPathCrossing(string path) {
        int x, y;
        x = y = 0;
        vector<vector<int>> vec;
        vec.push_back({x, y});
        for (int i = 0; i < path.size(); i++){
            if (path[i] == 'N') y++;
            if (path[i] == 'S') y--;
            if (path[i] == 'E') x++;
            if (path[i] == 'W') x--;
            vec.push_back({x, y});
        }
        sort(vec.begin(), vec.end());
        for (int i = 1; i < vec.size(); i++){
            if (vec[i][0] == vec[i-1][0] && vec[i][1] == vec[i-1][1])
                return 1;
        }
        return 0;
    }
};

class SolutionThree {
public:
    bool isPathCrossing(string path) {
        int x, y;
        x = y = 0;
        set<vector<int>> st;
        st.insert({x, y});
        for (int i = 0; i < path.size(); i++){
            if (path[i] == 'N') y++;
            if (path[i] == 'S') y--;
            if (path[i] == 'E') x++;
            if (path[i] == 'W') x--;
            if (st.count({x, y})) return 1;
            st.insert({x, y});
        }
        return 0;
    }
};
