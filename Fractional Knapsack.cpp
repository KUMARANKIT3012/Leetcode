class Solution {
public:
    struct Item {
        int value, weight;
        Item(int v, int w) : value(v), weight(w) {}
    };

    // Custom comparator: sort by value/weight ratio in descending order
    static bool cmp(Item a, Item b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> items;

        // Create list of items
        for (int i = 0; i < n; ++i) {
            items.push_back(Item(val[i], wt[i]));
        }

        // Sort using custom comparator
        sort(items.begin(), items.end(), cmp);

        double totalValue = 0.0;

        for (int i = 0; i < n && capacity > 0; ++i) {
            if (items[i].weight <= capacity) {
                // Take the full item
                totalValue += items[i].value;
                capacity -= items[i].weight;
            } else {
                // Take fractional part
                double fraction = (double)capacity / items[i].weight;
                totalValue += items[i].value * fraction;
                break; // Knapsack is full
            }
        }

        return totalValue;
    }
};
