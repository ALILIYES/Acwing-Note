#include<iostream>
using namespace std;
const int maxn = 100010;
int nums[maxn],n,q;
void findnums(int k){
    int l=0,r=n-1;
    while(l<r){
        int mid=(l+r)>>1;
        if(nums[mid]>=k)r=mid;
        else l=mid+1;
    }
    if(nums[l]!=k){
        printf("-1 -1\n");
    }else{
        printf("%d ",l);
        int l=0,r=n-1;
        while(l<r){
            int mid = (l+r+1)>>1;
            if(nums[mid]<=k)l=mid;
            else r=mid-1;
        }
        printf("%d\n",l);
    }
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;++i){
        scanf("%d",&nums[i]);
    }
    while(q--){
        int k;
        scanf("%d",&k);
        findnums(k);
    }
    
}