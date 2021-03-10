#include <iostream>
#include <string>

using namespace std;
using std::string;


void run_generator(string s,int num, int order, int open, int close){
    if(open==num && close==num){
        cout << s <<endl; } //if every parentheses are used correctly, print
    else{
	//if open is less than num, it is able to add (, and in same time, if open is bigger than close, it is able to add )
        if(open<num){
            s.replace(order,1,"(");
            int o_order = order+1;
            int o_open = open+1;
            run_generator(s,num,o_order,o_open,close);};
        if(open>close){
            s.replace(order,1,")");
            int c_order = order+1;
            int c_close = close+1;
            run_generator(s,num,c_order,open,c_close);
        }
        }
    }

int main(){
    int n;
    cout<<"enter integer whose value is between 1 and 10"<<endl;
    cin>>n;
    if(n>0 && n<11){
        string s;
        run_generator(s,n,0,0,0);}
    else{
        cout<<"input value is out of range"<<endl;
    };  
}
