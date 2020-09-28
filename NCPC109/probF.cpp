#include<bits/stdc++.h>

using namespace std;

map<vector<int> ,int > mp;
int sum(vector<int> a)
{
    int tmp = 0;
    for(int i = 0; i < a.size(); i++)
        tmp += a[i];
    return tmp;

}
void build(vector<int> v)
{
    if(v.size() > 1)
    {
        vector<int> tmp = v;
        for(int i = 0; i < v.size(); i++)
        {
            tmp.erase(tmp.begin()+i);
            mp.insert(pair<vector<int>, int>(tmp,sum(tmp)));
            build(tmp);
            tmp = v;
        }
    }
}
bool f(vector<int> a, vector<int> b)
{
    if(a[a.size()-1] != b[b.size()-1])
        return a[a.size()-1] > b[b.size()-1];
    else
    {
        for(int i = 0 ; i < a.size() && i < b.size(); i++)
        {
            if(a[i] == b[i])
                continue;
            else
                return a[i] > b[i];
        }
    }

}
void print(vector<vector<int> > ans)
{
    int start,end = ans.size()-1,csize = ans[ans.size()-1].size();
    for(int i = ans.size()-1; i >= 0; i--)
    {
        if(ans[i].size() != csize)
        {
            start = i + 1;
            sort(ans.begin()+start,ans.begin()+end,f);
            end = i;
            csize = ans[i].size();
        }
    }
    int cond = 0;
    for(int i = ans.size()-1 ; i >= 0; i--)
    {
        if(cond != 0)
            cout<<"; ";
        for(int j = 0; j < ans[i].size()-1; j++)
            cout<<ans[i][j]<<" ";
        cout<<ans[i][ans[i].size()-1];
        cond = 1;
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    while(m != 0)
    {
        vector<int> a;
        int count = 0;
        for(int i = 1; i <= m; i++)
        {
            count += i;
            a.push_back(i);
            mp.insert(pair<vector<int>, int>(vector<int>(i), i));
        }
        mp.insert(pair<vector<int>, int>(a,count));
        build(a);
        vector<vector<int> > ans;
        map<vector<int>, int>::iterator iter;
        for(iter = mp.begin(); iter != mp.end(); iter++)
        {
            if((*iter).second == n)
                ans.push_back((*iter).first);
        }
        if(!ans.empty())
        {
            if(ans.size() == 1)
            {
                for(int i = 0 ; i < ans[0].size()-1; i++)
                    cout<<ans[0][i]<<" ";
                cout<<ans[0][ans[0].size()-1]<<endl;
            }
            else
                print(ans);
                
        }
        else
            cout<<-1<<endl;

        mp.clear();
        cin>>m;
        if(m == 0) break;
        cin>>n;
    }

}
