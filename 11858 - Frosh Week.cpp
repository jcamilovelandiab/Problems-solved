#include <bits/stdc++.h>
#define loop(i,a) for(int i=0; i<a; i++)
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define MAX 1000000+10

using namespace std;
typedef long long ll;

ll cnt, arr[MAX], temp[MAX];

void Merge(ll low, ll high){
    ll mid=(high+low)/2;
    ll i=low, j=mid+1, k=low;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
            cnt+=(mid-i+1);
        }
    }
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=high) temp[k++]=arr[j++];
    for(ll z=low; z<= high; z++) arr[z]=temp[z];
}

void MergeSort(ll low, ll high){
    if(low<high){
        ll mid=(low+high)/2;
        MergeSort(low,mid);
        MergeSort(mid+1, high);
        Merge(low,high);
    }
}

int main(){
    ios:: sync_with_stdio(false);
    ll n;
    while(cin>>n){
        loop(i,n) cin>>arr[i];
        cnt=0;
        MergeSort(0,n-1);
        cout<<cnt<<endl;
    }
    return 0;
}
