//{ Driver Code Starts
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        std::sort(a.begin(),a.end());
        std::sort(b.begin(),b.end());
        long long unsigned int i = 0,j = 0;
        for(;i < a.size();i++){
            if(a[i] == b[j]){
                j++;
            }
            if(j == b.size()){
                return true;
            }
        }
        return false;
    }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a1, a2;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a1.push_back(number);
        }
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            a2.push_back(number);
        }
        Solution s;
        bool ans = s.isSubset(a1, a2);
        if (ans) {
            cout << "true"
                 << "\n";
        } else {
            cout << "false"
                 << "\n";
        }
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends

//une autre version 
bool isSubsetWithDuplicates(const std::vector<int>& a, const std::vector<int>& b) {
    std::unordered_map<int, int> freqA; // Stocke la fréquence des éléments de `a`

    // Comptage des occurrences dans `a`
    for (int num : a) {
        freqA[num]++;
    }

    // Vérification des éléments de `b`
    for (int num : b) {
        if (freqA[num] == 0) {
            return false; // Si `num` n'est pas dans `a`, `b` n'est pas un sous-ensemble
        }
        freqA[num]--; // Réduit la quantité disponible
    }

    return true;
}
