#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using std::string;


class Node{
    private :
        int elem;
        Node* next;

        friend class CircleList;

};

class CircleList{
    public:
        CircleList();
        ~CircleList();
        bool empty() const;
        const int& front() const;
        const int& back() const;
        void add_unique(const int& e);
        void remove();
        int getmin();
        int getmax();
        int getnum();
        
    private :
        Node* cursor;
        
};
//Constructor
CircleList::CircleList() : cursor(NULL){};
//Destructor
CircleList::~CircleList(){
    while(!empty()) remove();
};
//Check empty
bool CircleList::empty() const{
    return cursor==NULL;
};

//get element following cursor
const int& CircleList::front() const{
    return cursor->next->elem; 
};

//get element at cursor
const int& CircleList::back() const{
    return cursor->elem;
}

//add if input element is unique value
void CircleList::add_unique(const int& e){
    Node* v = new Node;
    Node* start = cursor;
    v-> elem = e;
    //if list is empty, add v as a cursor
    if(cursor == NULL){
        v-> next =v;
        cursor = v;
        cout<<"2: "<<e<<endl;
    }
    //If list is not empty
    else{
    	cout<<"3"<<endl;
        //check if the input element is a unique value which means, it doesn't match any element of the list
        if(cursor->elem!=e){
            start = start->next;
            int same = 0;
            while(start!=cursor){
                if(start->elem!=e){
                    start = start->next;
                }
                else{
                    same++;
                }
            }            
            // If the input element is unique value, add to the list
            if(same==0){
            v-> next = cursor->next;
            cursor->next =v ;
            cursor = v;}
        }
        };
delete start;        
};

//remove node after cursor
void CircleList::remove(){
    Node* old = cursor->next;
    if(old==cursor){
        cursor==NULL;
    }
    else{
        cursor->next = old->next;
        delete old;
    }
};

//get number of nodes in the list
int CircleList::getnum(){
    int num = 0;
    Node* start = cursor;
    if(cursor==NULL){
    cout<<"2"<<endl;
    	num=0;}
    else if(cursor->next = cursor){
        num = 1;
        cout<<"1"<<endl;
    }
    else{
    cout<<"3"<<endl;
        start = start->next;
        num++;
        while(start!=cursor){
            start = start->next;
            num++;
        }
        delete start;
    }
    return num;}

//get minimum value of the node element
int CircleList::getmin(){
    Node* start = cursor->next;
    int min = start->elem;
    if(start==cursor){
        return min;
    }
    else{
        while(start!=cursor){
            if(min>start->elem){
                min = start->elem;
            };
            start = start->next;
            }
        return min;}
    delete start;
}

//get maximum value of the node element
int CircleList::getmax(){
    Node* start = cursor->next;
    int max = start->elem;
    if(start==cursor){
        return max;
    }
    else{
        while(start!=cursor){
            if(max<start->elem){
                max = start->elem;
            };
            start = start->next;
            }
        return max;}
}


int main(){
    CircleList cl = CircleList();
    cout<<"input"<<endl;
    string s;
    while(getline(cin,s)){
        string start;
    	string l;
    	for(int i=0;i<s.length(); i++){
    		if(s[i]!=' '){
    			start[i] = s[i];}
    		else{int n=0;
    			for(int a=i+1; a<s.length(); a++){
    			l[n]=s[a];
    			n++;}}}
    	int start_offset = stoi(start);
    	int length = stoi(l);
    	
       if(start_offset>=0){
           if(length>0){
               for(int i=0;i<length;i++){
                   int e = start_offset+i;           
                   cl.add_unique(e);
               }}           
           else{
               cout<<"length has to be positive number"<<endl;
               break;
           }}
        else{
            cout<<"start_offset should be non-negative number"<<endl;
            break;
        };
       };
       cout<<"out"<<endl;
    /*int num;
    int min;
    int max;
    num = cl.getnum();
    min = cl.getmin();
    max = cl.getmax();
    cout<<num<<min<<max;
    if(num==max-min+1){
        cout<<"merged result"<<endl;
        cout<<min<<" "<<num<<endl;
    }
    else{
        cout<<"error"<<endl;
    };*/
}
