#include<iostream>
using namespace std;
const int n = 10;
void quick_sort(int q[], int l, int r)
{
    if(l>=r)return;
    int i=l-1,j=r+1,x=q[(i+j)>>1];
    while(i<j){
        do ++i;while(q[i]<x);  
        do --j;while(q[j]>x);
        if(i<j)swap(q[i],q[j]);
        // for(int i=0;i<n;++i){
        //     printf("%d ",q[i]); 
        // }
        // cout<<endl;
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}
int main(){
    int q[n] = {1,3,2,7,6,5,4,9,3,2};
    quick_sort(q,0,n-1);
    for(int i=0;i<n;++i){
        printf("%d ",q[i]);
    }
}