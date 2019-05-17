/*
You are given a string, consisting of lowercase Latin letters.

A pair of neighbouring letters in a string is considered ugly if these letters are also neighbouring in a alphabet. For example, string "abaca" contains ugly pairs at positions (1,2) — "ab" and (2,3) — "ba". Letters 'a' and 'z' aren't considered neighbouring in a alphabet.

Can you rearrange the letters of a given string so that there are no ugly pairs? You can choose any order of the letters of the given string but you can't add any new letters or remove the existing ones. You can also leave the order the same.

If there are multiple answers, print any of them.

You also have to answer T separate queries.

Input
The first line contains a single integer T (1≤T≤100) — the number of queries.

Each of the next T lines contains string s (1≤|s|≤100) — the string for the next query. It is guaranteed that it contains only lowercase Latin letters.

Note that in hacks you have to set T=1.

Output
Print T lines. The i-th line should contain the answer to the i-th query.

If the answer for the i-th query exists, then print such a rearrangment of letters of the given string that it contains no ugly pairs. You can choose any order of the letters of the given string but you can't add any new letters or remove the existing ones. You can also leave the order the same.

If there are multiple answers, print any of them.

Otherwise print "No answer" for that query.
*/
#include <bits/stdc++.h>

#define forn(i,n)  for(int i =0;i<int(n);i++)

using namespace std;

// code : https://codeforces.com/blog/entry/66827

// consider the string s [a:b], b is even, a is odd. 
bool check(string s)
{
    bool ok = true;
    forn(i, int(s.size())-1)
    {
        ok &= (abs(s[i]-s[i+1])!=1);
    }
    return ok;
}

int main()
{
    int T;
    scanf("%d",&T);
    static char buf[120];
    forn(_,T)
    {
        scanf("%s",buf);
        string s = buf;
        string odd = "",even = "";
        forn(i,s.size())
        {
            if(s[i]%2==0)
                odd +=s[i];
            else
            {
                even += s[i];
            }
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        if(check(odd+even))
        {
            printf("%s\n",(odd+even).c_str());
        }
        else if(check(even+odd))
        {
            printf("%s\n",(even+odd).c_str());
        }
        else
        {
            puts("No answer");
        }
    }
    return 0;
}
