#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

//The header uses stack = std::vector<vecint>; but in other headers
//it's vecvec = std::vector<vecint>; Make it all consistent

namespace meliora{

//using namespace::std;

using vecint = std::vector<int>;
using stack = std::vector<vecint>;

class Stack{

private:
    stack st;
    int top;
    //size_t capacity;

public:
    Stack();
    //~Stack();

    void push(vecint);
    vecint pop();
    //vecint peek();

    //bool operator==(vecint, vecint);
    bool isEqual(vecint, vecint);
    bool elementInStack(vecint);
    int findElementPos(vecint);
    stack::iterator begin();
    stack::iterator end();
    void printStack();

    size_t size();
    bool isEmpty();
    
};

Stack::Stack(){
    //capacity = 0;
    top = -1;
}

/*Stack::~Stack(){
    delete st;
}*/

bool Stack::isEqual(vecint vi1, vecint vi2){
    return vi1 == vi2;
}


stack::iterator Stack::begin(){
    return st.begin();
}

stack::iterator Stack::end(){
    return st.end();
}

void Stack::printStack(){

    /*
    std::cout<<"<"<<std::endl;
    for(auto &elements: st){
        std::cout<<"<";
        //Convert below to iterator to improve print
        for(auto &member: elements){
            std::cout<<member<<","; 
        }
        std::cout<<">"<<std::endl;
    }
    std::cout<<">\n";
    */

    size_t counter_pos = st.size()-1;

    std::cout<<"<"<<std::endl;
    for(auto i=st.rbegin(); i<st.rend(); i++){
        std::cout<<"<";
        for(auto &member: *i){
            std::cout<<member<<",";
        }
        std::cout<<"> ";
        std::cout<<"pos: "<<counter_pos<<std::endl;
        counter_pos -=1;
    }
    std::cout<<">\n"<<std::endl;
}

bool Stack::elementInStack(vecint element){

    bool ret = false;
    for(stack::iterator i=Stack::begin(); i<Stack::end(); ++i){
        if(element == *i){
            ret = true;
        }
    }

    return ret;
}

int Stack::findElementPos(vecint crd){

    int pos = -1;
    if(Stack::elementInStack(crd)==true){

        for(int i=0; i<st.size(); i++){
            if(st.at(i)==crd){
                pos = i;
            }
        }
        
    }

    return pos;
}

size_t Stack::size(){
    return st.size();
}

bool Stack::isEmpty(){
    return st.empty();
}

void Stack::push(vecint avecint){
    st.push_back(avecint);
    top+=1;
}

vecint Stack::pop(){
    top-=1;
    vecint ret = st.back();
    st.pop_back();

    return ret;

}

/*
vecint Stack::peek(){
    if(!st.empty()){
        return st.back();
    }
}
*/

}


#endif //end STACK_H