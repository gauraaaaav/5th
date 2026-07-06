#include <iostream>
#include <vector>

using namespace std;

int best = 0;

vector<int> answer;

vector<int> current;

void solve(
int wt[],
int val[],
int n,
int W,
int i,
int currWeight,
int currValue
){

if(currWeight>W)
return;

if(i==n){

if(currValue>best){

best=currValue;

answer=current;
}

return;
}

current.push_back(i);

solve(
wt,
val,
n,
W,
i+1,
currWeight+wt[i],
currValue+val[i]
);

current.pop_back();

solve(
wt,
val,
n,
W,
i+1,
currWeight,
currValue
);
}

int main(){

int val[]={12,10,20,15};

int wt[]={2,1,3,2};

int n=4;

int W=5;

solve(
wt,
val,
n,
W,
0,
0,
0
);

cout
<<"BACKTRACKING\n\n";

cout
<<"Chosen Items\n";

int totalWeight=0;

for(int i:answer){

cout
<<"Item "
<<i+1
<<endl;

totalWeight+=wt[i];
}

cout
<<"\nTotal Weight: "
<<totalWeight;

cout
<<"\nMaximum Value: "
<<best;

return 0;
}