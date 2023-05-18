//#include <vector>
#include <iostream>

#include "stack.h"
#include "reusedistance.h"



void pushInStack(meliora::Stack &st, meliora::vecint &v1){

    if(st.elementInStack(v1)==true){
        std::cout<<"Element already in stack:\n";
        st.printStack();
    }
    else{
        st.push(v1);
    }
}

int main(){

    /*
    meliora::vecint d1 = {1,2,3};
    meliora::vecint d2 = {4,5,6};
    meliora::vecint d3 = {7,8,9};
    meliora::vecint d4 = {4,5,6};
    meliora::vecint d5 = {12,23,32};
    */

    //a=1, b=2, c=3, d=4
    meliora::vecint d1 = {1}; //a
    meliora::vecint d2 = {2}; //b
    meliora::vecint d3 = {2}; //b
    meliora::vecint d4 = {4}; //d
    meliora::vecint d5 = {1}; //a
    meliora::vecint d6 = {2}; //b
    meliora::vecint d7 = {3}; //c
    meliora::vecint d8 = {1}; //a
    meliora::vecint d9 = {2}; //b
    meliora::vecint d10 = {4}; //d
    
    /*
        0(inf): 4
        1: 1,
        2: 4,
        3: 1
    */



    std::cout<<"Size of d1: "<<d1.size()<<std::endl;

    meliora::Stack st;

    /*
    st.push(d1);
    st.push(d2);
    st.push(d3);
    st.push(d4);
    st.push(d5);
    */
    
    pushInStack(st,d1);
    pushInStack(st,d2);
    pushInStack(st,d3);
    pushInStack(st,d4);
    pushInStack(st,d5);
    

    std::cout<<"Size of stack: "<<st.size()<<std::endl;

    std::cout<<"D2 pos: "<<st.findElementPos(d5)<<std::endl;
    std::cout<<"DX pos: "<<st.findElementPos({4,4,4})<<std::endl;


    std::cout<<"Printing stack"<<std::endl;
    st.printStack();

    std::cout<<"Reuse Distance tests:"<<std::endl;
    //Testing the skeleton of reusedistance
    meliora::ReuseDistance rd;

    meliora::vecvec sequence;
    sequence.push_back(d1);
    sequence.push_back(d2);
    sequence.push_back(d3);
    sequence.push_back(d4);
    sequence.push_back(d5);
    sequence.push_back(d6);
    sequence.push_back(d7);
    sequence.push_back(d8);
    sequence.push_back(d9);
    sequence.push_back(d10);

    //rd.initMap(sequence);

    //rd.calculate(sequence);

    meliora::mapRDH mrdh = rd.calculateHist(sequence);

    std::cout<<"{"<<std::endl;
    for(auto &kv: mrdh){
        std::cout<<"["<<kv.first<<"] : "<<kv.second<<","<<std::endl;
    }
    std::cout<<"}"<<std::endl;

    //rd.printMapRD();

    return 0;
}