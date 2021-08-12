#include<iostream>
using namespace std;
const int maxn = 100005;
int q[maxn],k;
int knth_element(int q[],int l,int r,int k){
    if(l>=r)return q[l];
    int i=l-1,j=r+1,x=q[(l+r)>>1];
    while(i<j){
        do ++i;while(q[i]<x);
        do --j;while(q[j]>x);
        if(i<j)swap(q[i],q[j]);
    }
    if (j - l + 1 >= k) return knth_element(q, l, j, k);
    else return knth_element(q, j + 1, r, k - (j - l + 1));
}
int main(){
    int n;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&q[i]);
    }
    printf("%d",knth_element(q,0,n-1,k));
    
}