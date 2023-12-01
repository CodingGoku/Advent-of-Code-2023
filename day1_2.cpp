#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() 
{
    string input;
    int beg, end, ans=0;
    
    unordered_map<string, int> num;
    num["one"] = 1;
    num["two"] = 2;
    num["three"] = 3;
    num["four"] = 4;
    num["five"] = 5;
    num["six"] = 6;
    num["seven"] = 7;
    num["eight"] = 8;
    num["nine"] = 9;
    
    while(cin >> input)
    {
      beg = -1;
      int index = -1;
      int mini = INT_MAX, maxi = INT_MIN;
      for(char c : input)
      {
        ++index;
        if(beg == -1) // not assigned
        {
          if(isdigit(c)) {beg = c - '0'; mini = min(mini, index);}
        }
        if(isdigit(c)) {end = c - '0'; maxi = max(maxi, index);}
      }
      
      
      for(auto& mp : num)
      {
        int pos = input.find(mp.first);
        while(pos != string::npos)
        {

          //cout<<"beg "<<beg<<" end "<<end<<" pos "<<pos<<" num "<<mp.second<<" MiNi "<<mini<<"\n";
          if(pos < mini) {beg = mp.second; mini = min(mini, pos); cout<<"beg at pos "<<pos<<" is "<<beg<<" mini "<<mini<<"\n";}

          if(pos > maxi) {end = mp.second; maxi = max(maxi, pos); cout<<"end at pos "<<pos<<" is "<<end<<"\n";}
          
          pos = input.find(mp.first, pos + 1);
        }
      }
      //cout<<"VAL CALC : "<<" BEG "<<beg<<" END "<<end<<"\n";
      int val = (beg*10) + end;
      cout<<val<<"\n";
      ans += val;
    }
    cout<<"\n\n ANS : "<<ans;
    return 0;
}