#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(Job arr[], int n) {

    sort(arr, arr + n, compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, arr[i].deadline);

    int slot[maxDeadline + 1];

    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = arr[i].id;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    cout << "Selected Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1)
            cout << "J" << slot[i] << " ";
    }

    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {

    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    Job arr[n];

    cout << "Enter Job ID, Deadline and Profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }

    jobSequencing(arr, n);

    return 0;
}