class Solution {
public:
unordered_map<char,int>m;
vector<int>v;
unordered_set<int>se;
    int minDeletions(string s) {
        int n=s.size();
        for(int i=0;i<n;i++) m[s[i]]++;
        for(auto x:m) v.push_back(x.second);
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int del=0;
        for(int i=0;i<v.size();i++)
        {
            if(se.count(v[i])==0) se.insert(v[i]);
            else
            {
               while(!(se.count(v[i])==0))
               {
                   v[i]--;
                   if(v[i]<0) break;
                   del++;
               }
               se.insert(v[i]);
            }
        }
        return del;
        
    }
};
