//#include <vector>
#include <iostream>

#include "stack.h"



void pushInStack(meliora::Stack st, meliora::vecint v1){

    if(st.elementInStack(v1)==true){
        std::cout<<"Element already in stack:\n";
        st.printStack();
    }
    else{
        st.push(v1);
    }
}

int main(){

    meliora::vecint d1 = {1,2,3};
    meliora::vecint d2 = {4,5,6};
    meliora::vecint d3 = {7,8,9};
    meliora::vecint d4 = {4,5,6};
    meliora::vecint d5 = {12,23,32};

    meliora::Stack st;
    //st.push(d1);
    //st.push(d2);

    pushInStack(st,d1);
    pushInStack(st,d2);
    pushInStack(st,d3);
    pushInStack(st,d4);
    pushInStack(st,d5);

    std::cout<<"Printing stack"<<std::endl;
    st.printStack();

    return 0;
}