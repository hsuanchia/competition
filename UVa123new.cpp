#include<bits/stdc++.h>

using namespace std;

vector<string> split(string str)
{
    int j;
    vector<string> ans;
    string tmp = "";
    for(int i = 0 ;i < str.length(); i++)
    {
        if(str[i] != ' ')
            tmp += str[i];
        else
        {
            for(j = 0; j < tmp.length(); j++)
                tmp[j] = tolower(tmp[j]);
            ans.push_back(tmp);
            tmp = "";
        }
    }
    for(j = 0; j < tmp.length(); j++)
        tmp[j] = tolower(tmp[j]);
    ans.push_back(tmp);
    return ans;

}
map<string,int> findword(vector<vector<string> > title,map<string,int> mp)
{
    map<string,int> ans;
    for(int i = 0 ;i < title.size(); i++)
        for(int j = 0 ;j < title[i].size(); j++)
        {
            map<string,int>::iterator iter = mp.find(title[i][j]);
            map<string,int>::iterator it = ans.find(title[i][j]);
            if(iter == mp.end())
            {
                if(it != mp.end())
                    ans.insert(pair<string,int>(title[i][j],1));
                else
                    (*iter).second++;
            }
        }
    return ans;

}
void print(vector<string> line,int j)
{
    vector<string> ans = line;
    for(int k = 0; k < ans[j].length(); k++)
        ans[j][k] = toupper(ans[j][k]);
    for(int i = 0; i < ans.size()-1; i++)
        cout<<ans[i]<<" ";
    cout<<ans[ans.size()-1]<<endl;
}
void search(map<string,int> key,vector<vector<string> > title)
{
    map<string,int>::iterator iter = key.begin();
    while(iter != key.end())
    {
        for(int i = 0; i < title.size(); i++)
            for(int j = 0; j < title[i].size(); j++)
                if(title[i][j] == (*iter).first)
                {
                    print(title[i],j);
                    (*iter).second--;
                }

        iter++;
    }
}
int main()
{
    map<string,int> pre;
    string tmp;
    while(cin>>tmp)
    {
        if(tmp == "::")
            break;
        pre.insert(pair<string,int>(tmp,1));
    }
    vector<vector<string> > title;
    map<string,int> keyword;
    while(getline(cin,tmp))
        title.push_back(split(tmp));
    title.erase(title.begin());
    keyword = findword(title,pre);       
    search(keyword,title);
    /*for(int i = 0; i < title.size(); i++)
    {
        for(int j = 0; j < title[i].size(); j++)
            cout<<title[i][j]<<" ";
        cout<<endl;
    }*/
}

