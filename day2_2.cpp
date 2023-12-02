#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string input, prev;
    int r, g, b, r_min, g_min, b_min, prev_r_min, prev_g_min, prev_b_min;

    
    long long pwr=0;
    
    while(cin >> input)
    {
      //cout<<input<<"\n";
      if(input == "Game") // reset values
      {
        r_min = 0, g_min = 0, b_min = 0;

        pwr += (prev_r_min*prev_g_min*prev_b_min);
        cout<<"r_min: "<<prev_r_min<<" g_min: "<<prev_g_min<<" b_min: "<<prev_b_min<<"\n";
          
      }
      
      if(input == "red," || input == "red;" || input == "red")
      {
        r_min = max(r_min,stoi(prev));
      }
      
      if(input == "green," || input == "green;" || input == "green")
      {
        g_min = max(g_min,stoi(prev));
      }
      
      if(input == "blue," || input == "blue;" || input == "blue")
      {
        b_min = max(b_min,stoi(prev));
      }
      
      
      prev = input;
      prev_r_min = r_min;
      prev_g_min = g_min;
      prev_b_min = b_min;
      
    }
    
    // for last game played
    pwr += (prev_r_min*prev_g_min*prev_b_min);
    cout<<"r_min: "<<prev_r_min<<" g_min: "<<prev_g_min<<" b_min: "<<prev_b_min<<"\n";
    
    cout<<"pwr : "<<pwr;
    return 0;
}