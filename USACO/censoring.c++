int main()
{
    string s,t,ans;
    cin>>s>>t;
    for(char ch:s){
        ans+=ch;
        if(ans.size()>=t.size() && ans.substr(ans.size()-t.size())==t){
            for(int i=0;i<t.size();i++) ans.pop_back();
        }
    }
    cout<<ans;

    return 0;
}
