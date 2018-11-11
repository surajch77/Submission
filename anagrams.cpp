vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    int N = A.size();
    pair<string, int> p[N];
    
    for(int i=0; i<N; ++i){
        string temp = A[i];
        sort(temp.begin(), temp.end());
        p[i].first = temp;
        p[i].second = i+1;
    }
    
    sort(p, p+N);
    vector< vector <int> > ans;
    int i = 1;
    vector<int> v;
    
    v.push_back(p[0].second);
    while(i < N){
        if(p[i].first == p[i-1].first)
            v.push_back(p[i].second);
        else{
            ans.push_back(v);
            v.clear();
            v.push_back(p[i].second);
        }
        i++;
    }
    if(v.size() >= 1)
        ans.push_back(v);
    return ans;
}

