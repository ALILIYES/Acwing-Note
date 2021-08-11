#include<iostream>
using namespace std;
typedef long long LL;
LL res = 0;
const int maxn = 100010;
int q[maxn],tmp[maxn];
LL reverse_pair(int l,int r){
    if(l>=r)return 0;
    int mid = (l+r)>>1;
    res = reverse_pair(l,mid)+reverse_pair(mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid && j<=r){
        if(q[i]<=q[j])tmp[k++]=q[i++];
        else{
            res+=mid-i+1;
            tmp[k++]=q[j++];
        }
    }
    while(i<=mid)tmp[k++]=q[i++];
    while(j<=r)tmp[k++]=q[j++];
    for(int i=l,j=0;i<=r;++i,++j){
        q[i]=tmp[j];
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&q[i]);
    }
    printf("%lld",reverse_pair(0,n-1));
}