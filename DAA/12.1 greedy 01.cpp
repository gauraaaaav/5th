#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int id, value, weight;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {

    int val[] = {12,10,20,15};
    int wt[] = {2,1,3,2};

    int n = 4;
    int W = 5;

    vector<Item> items;

    for(int i=0;i<n;i++) {
        items.push_back({
            i+1,
            val[i],
            wt[i],
            (double)val[i]/wt[i]
        });
    }

    sort(items.begin(), items.end(), compare);

    int totalWeight = 0;
    int totalValue = 0;

    cout << "GREEDY APPROACH\n\n";

    cout << "Item\tRatio\tWeight\tValue\n";

    for(auto item:items) {

        if(totalWeight + item.weight <= W) {

            totalWeight += item.weight;
            totalValue += item.value;

            cout
            << item.id << "\t"
            << item.ratio << "\t"
            << item.weight << "\t"
            << item.value << endl;
        }
    }

    cout
    << "\nWeight Used: "
    << totalWeight
    << endl;

    cout
    << "Maximum Value: "
    << totalValue;

    return 0;
}