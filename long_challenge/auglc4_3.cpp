#include <bits/stdc++.h>
using namespace std;

//  Utility method to add value val, to range [lo, hi] 
void add(int arr[], int N, int lo, int hi, int val) 
{ 
    arr[lo] += val;
    if (hi != N - 1)
       arr[hi + 1] -= val;
} 
  
//  Utility method to get actual array from operation array 
void updateArray(int arr[], int N) 
{ 
    //  convert array into prefix sum array 
    for (int i = 2; i < N; i++) 
        arr[i] += arr[i - 1]; 
} 
  
// //  method to print final updated array 
// void printArr(int arr[], int N) 
// { 
//     updateArray(arr, N); 
//     for (int i = 0; i < N; i++) 
//         cout << arr[i] << " "; 
//     cout << endl; 
// }

//  Driver code to test above methods 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int c[N+1],h[N+1];
        for(int i=1;i<=N;i++)
            cin>>c[i];
        for(int i=1;i<=N;i++)
            cin>>h[i];
        int arr[N+1] = {0};
        c[0]=0,h[0]=0;
        //  Range add Queries 
        for(int i=1;i<=N;i++)
            add(arr, N+1, max(1,i-c[i]), min(N,i+c[i]), 1); 
        // updateArray(arr, N); 
        updateArray(arr,N+1);
        // printArr(arr, N);
        for(int i=1;i<=N;i++)
            cout<<arr[i]<<" ";

        sort(arr,arr+N+1,greater<int>());
        sort(h,h+N+1,greater<int>());

        int flag=1;
        for (int i=1;i<=N;i++)
            if(arr[i]!=h[i])
                flag=0;
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        // cout<<endl<<flag;
    }
    return 0; 
} 