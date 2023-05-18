#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>



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

    std::cout<<"<";
    for(auto &elements: st){
        std::cout<<"<";
        //Convert below to iterator to improve print
        for(auto &member: elements){
            std::cout<<member<<","; 
        }
        std::cout<<">";
    }
    std::cout<<">\n";
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