class Solution {
public:
    string simplifyPath(string path) {
        string con = "/";
        deque<string> paths;
        int n = path.size(); 
        for(int i = 0; i < path.size(); i++)
        {
            while(i < n && path[i] == '/')
                i++; 
            string cur = ""; 
            while(i < n && path[i] != '/')
                cur += path[i++];
            if (cur == "..")
            {
                if (!paths.empty())
                    paths.pop_back(); 
            }else if (cur != "." && cur.size() > 0)
                paths.push_back(cur);
        }
        while(paths.size() > 0)
        {
            cout << paths.front() <<"\n";
            con += paths.front();
            paths.pop_front(); 
            if (paths.size() > 0)
                con += '/'; 
        }
        return con;
    }
};