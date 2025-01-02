//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        if(arr.size() == 1){
            if(arr[0] == 1){
                return arr[0] + 1;
            }else{
                return arr[0] - 1;
            }
        }
        int sum = 0,sumN = arr.size() + 1;
        for(int i = 0,j = 1;i < arr.size();i++,j++){
            sum += arr[i];
            sumN += j;
        }
        
        return sumN - sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNumber(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
