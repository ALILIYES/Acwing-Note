#include<iostream>
#include<vector>
using namespace std;
bool cmp(vector<int> &a,vector<int> &b){
    if(a.size()!=b.size())return a.size()>b.size();//相等时无法判断大小
    for(int i=a.size()-1;i>=0;--i){
        if(a[i]!=b[i])
            return a[i]>b[i];
    }
    return true;//相等无需变化
}
vector<int> high_sub(vector<int> &a,vector<int> &b){
    vector<int> C;
    int t = 0;
    for(int i=0;i<a.size();++i){
        t = a[i]-t;
        if(i<b.size())t-=b[i];
        C.push_back((t+10)%10);//包含t小于零或者大于零的情况
        if(t<0)t=1;
        else t=0;
    }
    while(C.size()>1 && C.back()==0)C.pop_back();
    return C;
}
int main(){
    string a,b;
    vector<int> A,B;
    cin>>a>>b;//"123456"
    for(int i=a.size()-1;i>=0;--i)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;--i)B.push_back(b[i]-'0');
    if(cmp(A,B)){
        vector<int> C = high_sub(A,B);
        for(int i=C.size()-1;i>=0;--i)cout<<C[i];
    }else{
        vector<int> C = high_sub(B,A);
        cout<<"-";
        for(int i=C.size()-1;i>=0;--i)cout<<C[i];
    }
}