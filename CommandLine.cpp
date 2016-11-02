	   // do we need a display class?
#ifndef CommandLine_H
#define CommandLine_H	   
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm> 
#include <fstream>
   
using namespace std;


class CommandLine

{
    protected:
    string line;
    
    public:
    CommandLine(){};
    CommandLine(string line):line(line){};
    
    virtual void exe(CommandLine* line) {};
    
    string out(){
        string outline;
        outline = this->line;
        return outline;
    }
};
#endif
/*





#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
   
using namespace std;
int main(int argc, char* argv[])
{
    ifstream inFS; 

cout << "file name plz "<< endl;
    string fl;
    cin >> fl;
    inFS.open(fl.c_str());
    if (!inFS.is_open()) {
      cout << "Could not open file " << argv[1] << "." << endl;
      return 1; // 1 indicates error
   }
   else
   {
       cout << "Opened"<<endl;
       
   }
    string h;
    while(!inFS.eof())//can use inFS>>h in place of inFS.eof, or .get function
    {
    getline(inFS, h );
    cout << h;
    }
}*/