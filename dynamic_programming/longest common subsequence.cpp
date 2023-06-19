/*
    uname: karankulx
    qlink: https://leetcode.com/problems/longest-common-subsequence/description/
    qname: Longest Common Sub Sequence
    companies: Google, Microsoft, Adobe, Delloite, Airbnb, Oyo, Uber, Ola, etc
*/

class Solution {
public:
    int n, m;
    int t[1001][1001];
    int solve(string& s1, string& s2, int i , int j) {
        if( i > n - 1 || j > m - 1)
            return t[i][j] = 0;
        
        if(t[i][j] != -1) return t[i][j];

        if(s1[i] == s2[j]) {
            return t[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        };
        return t[i][j] = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
    };

    int longestCommonSubsequence(string s1, string s2) {
        n = s1.length();
        m = s2.length();
        memset(t, -1, sizeof(t));
        return solve(s1, s2, 0, 0);
    }
};