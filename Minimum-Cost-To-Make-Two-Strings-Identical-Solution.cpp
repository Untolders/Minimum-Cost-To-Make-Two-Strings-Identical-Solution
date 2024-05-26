#################################################################################  Question  #######################################################################################################################

Given two strings x and y, and two values costX and costY, the task is to find the minimum cost required to make the given two strings identical. You can delete characters from both the strings. The cost of deleting a character from string X is costX and from Y is costY. The cost of removing all characters from a string is the same.

Example 1:

Input: x = "abcd", y = "acdb", costX = 10 
       costY = 20.
Output: 30
Explanation: For Making both strings 
identical we have to delete character 
'b' from both the string, hence cost 
will be = 10 + 20 = 30.
Example 2:

Input : x = "ef", y = "gh", costX = 10
        costY = 20.
Output: 60
Explanation: For making both strings 
identical, we have to delete 2-2 
characters from both the strings, hence 
cost will be = 10 + 10 + 20 + 20 = 60.
Your Task:
You don't need to read or print anything. Your task is to complete the function findMinCost() which takes both strings and the costs as input parameters and returns the minimum cost.

Expected Time Complexity: O(|x|*|y|)
Expected Space Complexity: O(|x|*|y|)

Constraints:
1 ≤ |x|, |y| ≤ 1000
1<= costX, costY <= 105









##################################################################################  Solution  ######################################################################################################################

  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {

  public:

    int findMinCost(string x, string y, int costX, int costY) {
  int n = x.size() - 1;
    int m = y.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int len = lcs(x, y, n, m, dp);
    return costX * (n + 1 - len) + costY * (m + 1 - len);
}
int lcs(string &x, string &y, int n, int m, vector<vector<int>> &dp)
{
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (x[n] == y[m])
    {
        return dp[n][m] = 1 + lcs(x, y, n - 1, m - 1, dp);
    }
    return dp[n][m] = max(lcs(x, y, n - 1, m, dp), lcs(x, y, n, m - 1, dp));
}
};



//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends

