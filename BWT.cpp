/*
CSCI3220 2021-22 First Term Assignment 2

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
#include <string>

using namespace std;


string sequence (int* O, string last){ //find s
    string s;
    int c[4] = {0}, le, pos[last.length()]; //c for counting 0:A 1:C 2:G 3:T. le: 0:A 1:C 2:G 3:T
    for (int i = 0; i<last.length(); i++){ //assign position num
        if  (last[i] == 'A')   le=0;        //condition for assigning array respect to different letter
        else if (last[i] == 'C')   le=1;
        else if (last[i] == 'G')   le=2;
        else if (last[i] == 'T')   le=3;
        else {pos[i] = 0; continue;}
        c[le]++;
        pos[i] = c[le];
    }

    for (int i=0, j=0; i<last.length(); i++){ //retrieve s
        if  (last[j] == 'A')   le=0;
        else if (last[j] == 'C')   le=1;
        else if (last[j] == 'G')   le=2;
        else if (last[j] == 'T')   le=3;
        else break;
        s = last[j] + s;
        j = O[le+1] + pos[j] - 1;
    }

    return s + '$';
}

int main(){
    string b;
    getline(cin,b);

    int c[5] = {0}; //for counting 0:$ 1:A 2:C 3:G 4:T
    int O[5] = {0}; //for first occurrence array 0:$ 1:A 2:C 3:G 4:T
    int lenOfb = b.length();

    for (int i = 0; i < lenOfb; i++){   //count each letter occurrence
        if (b[i] == '$')        c[0]++;
        else if (b[i] == 'A')   c[1]++;
        else if (b[i] == 'C')   c[2]++;
        else if (b[i] == 'G')   c[3]++;
        else    c[4]++;
    }

    for (int i = 0, p = 0; i < 5; i++){ //first occurrence array
        if (c[i] == 0) {O[i] = NULL; continue;}
        O[i] = p;
        p += c[i];
    }
    string s = sequence(O, b);
    int a=b.length()*2;
    for (int i=1; i<b.length(); i++){ //find length of BWT output of the DNA sequence in run-length encoding
        if (b[i-1] == b[i]) a-=2;
    }
    int runs = s.length()*2;
    for (int i=1; i<s.length(); i++){ //find length of original DNA sequence in run-length encoding
        if (s[i-1] == s[i]) runs-=2;
    }
    cout<< s.length()<<","<<runs<<","<<a<<endl;


    return 0;

}
