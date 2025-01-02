//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        vector <int> result(1,-1);
        int isTarget = -1;

        for(int i = 0;i < arr.size();i++){
            int sum = 0;
            if(arr[i] == target && isTarget == -1){
                isTarget = i + 1;
            }
            for(int j = i;j < arr.size();j++){
                sum += arr[j];
                if(sum == target){
                    result.pop_back();
                    result.push_back(i+1);
                    result.push_back(j+1);

                    return result;
                }
            }
        }
        if(isTarget > -1){
            result.pop_back();
            result.push_back(isTarget);
            result.push_back(isTarget);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends
