#include <bits/stdc++.h>
using namespace std;
void PRINT(string a,vector<vector<string> > b)
{
    for(int i=0;i<data.size();i++)
    {
        for(int j =0;j<data[i].size();j++)
        {
            if(a==b[i][j])
            {
                for(int x=0;x<data[i].size();x++)
                {
                    if(x==j)
                        cout<< toupper(data[i][x]);
                    else
                        cout<<data[i][x];
                    if(x!=data[i].size()-1)
                        cout<<' ';
                    else
                        cout<<endl;
                }
            }
        }
    }    
}
string toupper(string a)
{
    string aa;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]>='a'&&a[i]<='z')
        {
            aa+='A'+a[i]-'a';        
        }
        else
            aa+=a[i];
    }
    return aa;
}
bool find(string a,vector<string> b)
{
    string aa;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]>='a'&&a[i]<='z')
        {
            aa+='A'+a[i]-'a';        
        }
        else
            aa+=a[i];
    } 
    for(int i = 0;i<b.size();i++)
    {
        if(b[i]==aa)
            return false;
    }
    return true;
}
vector<string> mesort(vector<vector<string> > a,vector<string> t)
{
    vector<string> key;
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            if(find(a[i][j],t))
                key.push_back(a[i][j]);
        }
    }
    sort(key.begin(),key.end());
    return key;
}
vector<string> split(string a)
{
    vector<string> mp;
    string t;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!=' ')
            t+=a[i];
        else
        {
            mp.push_back(t); 
            t="";
        }
    }
    mp.push_back(t);
    return mp;
}
int main()
{
    string temp;
    vector<string> t;
    vector<vector<string> > data;
    while(getline(cin,temp))
    {
        if(temp=="::")
            break;
        for(int i =0;i<temp.length();i++)
            temp[i]='A'+temp[i]-'a';
        t.push_back(temp);
    }    
    while(getline(cin,temp))
    {        
        data.push_back(split(temp));
    }
    for(int i=0;i<data.size();i++)
    {
        for(int j=0;j<data[i].size();j++)
            cout<<data[i][j]<<' ';
        cout<<endl;
    }
    for(int i=0;i<t.size();i++)
        cout<<t[i]<<' ';
    cout<<endl;
    vector<string> ans = mesort(data,t);
    for(int i=0;i<ans.size();i++)
    {

        cout<<ans[i]<<'\n';
    }
        
    return 0;
}
