#include <iostream>

using namespace std;

int main() {

int val[]={12,10,20,15};
int wt[]={2,1,3,2};

int W=5;
int n=4;

int dp[n+1][W+1];

for(int i=0;i<=n;i++) {

for(int w=0;w<=W;w++) {

if(i==0 || w==0)
dp[i][w]=0;

else if(wt[i-1]<=w)

dp[i][w]=max(
val[i-1]+
dp[i-1][w-wt[i-1]],

dp[i-1][w]
);

else

dp[i][w]=dp[i-1][w];
}
}

cout<<"DYNAMIC PROGRAMMING\n\n";

cout<<"DP Table:\n\n";

for(int i=0;i<=n;i++){

for(int w=0;w<=W;w++)
cout<<dp[i][w]<<" ";

cout<<endl;
}

cout
<<"\nMaximum Value = "
<<dp[n][W];

return 0;
}