#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string input, prev;
    int gid, r, g, b, validIDsum=0, prev_gid;
    bool valid_gid = true, prev_valid_gid = false;
    
    while(cin >> input)
    {
      //cout<<input<<"\n";
      if(input == "Game") // reset values
      {
        //check for previous valid gid
        if(prev_valid_gid) {validIDsum += prev_gid;  cout<<"grid for sum: "<<prev_gid<<"\n";}
        
        //reset
        r = 12, g = 13, b = 14;
        valid_gid=true;
        
        cin >>input;
        input.pop_back(); // remove colon
        gid = stoi(input);
        cout<<"gid : "<<gid<<"\n";
      }
      
      if(input == "red,")
      {
        r -= stoi(prev);
      }
      
      if(input == "red;" || input == "red")
      {
        r -= stoi(prev);
        if(r<0 || g<0 || b<0) {valid_gid = false;}
        r = 12, g = 13, b = 14; // reset
      }
      
      if(input == "green,")
      {
        g -= stoi(prev);
      }
      
      if(input == "green;" || input == "green")
      {
        g -= stoi(prev);
        if(r<0 || g<0 || b<0) {valid_gid = false;}
        r = 12, g = 13, b = 14; // reset
      }
      
      if(input == "blue,")
      {
        b -= stoi(prev);
      }
      
      if(input == "blue;" || input == "blue")
      {
        b -= stoi(prev);
        if(r<0 || g<0 || b<0) valid_gid = false;
        r = 12, g = 13, b = 14; // reset
      }
      
      //cout<<"r: "<<r<<" g: "<<g<<" b: "<<b<<"\n";
      
      prev = input;
      prev_gid = gid;
      prev_valid_gid = valid_gid;
    }
    
    // for last game played
    if(prev_valid_gid) {validIDsum += prev_gid; cout<<"grid for sum: "<<prev_gid<<"\n";}
    
    cout<<"validIDsum : "<<validIDsum;
    return 0;
}