class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        unordered_set<string> ht;
        q.push(s);
        vector<string> res;
        while(!q.empty()) {
            string ss = q.front();
            q.pop();
            if(ht.count(ss)) continue;
            ht.insert(ss);
            if(isValid(ss)) res.push_back(ss);
            else if (res.empty()) 
                for(int i=0;i<ss.size();i++) 
                    if(ss[i]==')'|| ss[i]=='(') q.push(ss.substr(0,i)+ss.substr(i+1));
        }
        return res;
    }
    bool isValid(string &s) {
        int count=0;
        for(auto c:s) {
            if(c=='(') count++;
            if(c==')')
                if(count>0) count--;
                else return false;
        }
        return !count;
    }
};
