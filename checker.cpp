#include <stack>
#include <iostream>
#include <string>

using namespace std;
using std::string;

string line;
int correct =0;
int wrong =0;
char open = '(';
char close = ')';

int main() {
    cout << "input string that consists of '(' and ')'" <<endl;
    while(getline(cin, line)){
        int check=0; //check should be 0 at final, and always be non-negative
        for(int i=0; i<line.length(); i++){
            if(line.at(i)==open){
                check++;}
            else if(line.at(i)==close){
                check--;};
            if(check<0){
                wrong++;
                break;};
            if(i==line.length()-1 && check!=0){
                wrong++;
                break;};
            if(i==line.length()-1 && check==0){
                correct++;};
            }}
    cout<<"correct "<<correct<<", wrong "<<wrong<<endl;}
           