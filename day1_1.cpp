#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() 
{
    string input;
    int beg, end, ans=0;
    
    while(cin >> input)
    {
      beg = -1;
      for(char c : input)
      {
        if(beg == -1) // not assigned
        {
          if(isdigit(c)) beg = c - '0';
        }
        if(isdigit(c)) end = c - '0';
      }
      int val = (beg*10) + end;
      cout<<val<<"\n";
      ans += val;
    }
    cout<<"\n\n ANS : "<<ans;
    return 0;
}