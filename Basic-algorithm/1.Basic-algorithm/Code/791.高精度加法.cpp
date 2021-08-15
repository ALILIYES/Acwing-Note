#include<iostream>
#include<vector>
using namespace std;
vector<int> high_add(vector<int> &a,vector<int> &b){
    vector<int> C;
    int t=0;//进位
    for(int i=0;i<a.size()||i<b.size();++i){
        if(i<a.size())t+=a[i];
        if(i<b.size())t+=b[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t)C.push_back(1);
    return C;
}
int main(){
    string a,b;
    vector<int> A,B;
    cin>>a>>b;//"123456"
    for(int i=a.size()-1;i>=0;--i)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;--i)B.push_back(b[i]-'0');
    vector<int> C = high_add(A,B);
    for(int i=C.size()-1;i>=0;--i)cout<<C[i];
}