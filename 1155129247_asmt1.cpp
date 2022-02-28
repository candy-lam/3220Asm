/*
CSCI3220 2021-22 First Term Assignment 1
I declare that the assignment here submitted is original except for source
material explicitly acknowledged, and that the same or closely related material
has not been previously submitted for another course. I also acknowledge that I
am aware of University policy and regulations on honesty in academic work, and
of the disciplinary guidelines and procedures applicable to breaches of such
policy and regulations, as contained in the following websites.
University Guideline on Academic Honesty:
http://www.cuhk.edu.hk/policy/academichonesty/
Student Name: Lam Hiu Ching
Student ID : 1155129247
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void gettable(string r, string s, int match, int mmatch, int indel){
    int m = r.length(), n = s.length();
    int table[m+1][n+1];
    int arrow[m+1][n+1];


    for (int i = 0; i<=m; i++)
        for (int j = 0; j <= n; j++){
            table[i][j] = 0;
        }

    for (int i = 0; i<=m; i++)
        for (int j = 0; j <= n; j++){
            table[m][j] = 0;
            table[i][n] = 0;
        }

    int score = 0;

    for (int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if (r[i] == s[j])
                score = match;
            else
                score = mmatch;
            table[i][j] = max({table[i+1][j+1] + score,
                                table[i][j+1] + indel,
                                table[i+1][j] + indel
                                });
        }
    }


    for (int i = 0; i<=m; i++){
        for (int j = 0; j <= n; j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }



}

int main(){
    int match, mmatch, indel;
    string r, s;
    cin >> match;
    cin >> mmatch;
    cin >> indel;
    cin >> r;
    cin >> s;


    gettable(r, s, match, mmatch, indel);

    return 0;

}
