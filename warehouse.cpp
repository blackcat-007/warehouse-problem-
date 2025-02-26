#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int warehouses;
    cout << "Enter the number of warehouses: ";
    cin >> warehouses;

    for (int wh = 0; wh < warehouses; wh++) {
        int partners, orders;
        
        cout << "Enter the number of partners: ";
        cin >> partners;
        
        cout << "Enter the number of orders: ";
        cin >> orders;

        // Aggregation
        unordered_map<int, int> pt;
        for (int order = 0; order < orders; order++) {
            int entries;
            
            cout << "Enter the number of entries for order " << order + 1 << ": ";
            cin >> entries;
            
            while (entries--) {
                int product, quantity;
                cout << "Enter product ID and quantity: ";
                cin >> product >> quantity;
                pt[product] += quantity;
            }
        }

        // Distribution
        vector<map<int, int>> allocateptnr(partners);

        // For every product, allocate its total quantity across partners.
        for (auto &entry : pt) {
            int product = entry.first;
            int totalqnt = entry.second;
            
            if (totalqnt < partners) {
                for (int i = 0; i < totalqnt; i++) {
                    allocateptnr[i][product] = 1;
                }
            } else {
                int distributedvalue = totalqnt / partners;
                int extra = totalqnt % partners;

                for (int i = 0; i < partners; i++) {
                    int allocate = distributedvalue;
                    if (i < extra) {
                        allocate++; // extra unit for this partner
                    }
                    if (allocate > 0) {
                        allocateptnr[i][product] = allocate;
                    }
                }
            }
        }

        // Output the distribution in a neat, sorted format.
        for (int i = 0; i < partners; i++) {
            cout << "Partner " << (i + 1) << ": {";
            bool first = true;
            for (auto &prod : allocateptnr[i]) {
                if (!first)
                    cout << ", ";
                cout << prod.first << ": " << prod.second;
                first = false;
            }
            cout << "}\n";
        }
    }
    
    return 0;
}