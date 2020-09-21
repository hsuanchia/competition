#include<bits/stdc++.h>

using namespace std;

int count(string x)
{
    return x.length() - 2;
}
double change(string x, int k,int j)
{
    double ans;
    long long tmp = 0;
    string temp;
    for(int i=2;i<x.length();i++)
        temp += x[i];
    for(int i=x.length()-j;i<x.length();i++)
        temp += x[i];
    int t = 0;
    for(int i = temp.length()-1 ; i >= 0 ;i--)
        tmp += pow(10,t++) * (temp[i] - '0'); 
    ans = tmp * pow(10,(-1)*(k+j*2));
    return ans;
}
int times(int a)
{
    int ans = 1;
    while(a--)
        ans *= 10;
    return ans;
}

int main()
{
    int j,k;
    int cases = 1;
    double num;
    string x;
    while(cin>>j)
    {
        long long a = 0,b = 0;
        if(j == -1)
            break;
        cin>>x;
        if(j == 0)
        {
            k = count(x)-j;
            int ex = 0;
            for(int i = x.length()-1; i > 1; i--)
                a += (x[i] - '0') * pow(10,ex++);
            b = pow(10,ex);
        }
        else
        {
            k = count(x)-j;
            num = change(x,k,j);
            a = (int)(times(k+j) * num) - (int)(times(k) * num);
            b = times(k+j) - times(k);
        }
        cout<<"Case "<<cases++<<": ";
        cout<<a/__gcd(a,b)<<"/"<<b/__gcd(a,b)<<endl;
    }

}
