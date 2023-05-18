#ifndef REUSEDISTANCE_H
#define REUSEDiSTANCE_H

/* This is a Stack based tree implementation for computing reuse distance for memory
accesses described vector<vector<ints>> from the isl_ItSpace namespace */

#include <iostream>
#include <map>
#include <limits>
#include "stack.h"
//#include "isl_domsched2pattern.h"


namespace meliora{

using vecint = std::vector<int>;
using vecvec = std::vector<vecint>;
using mapRD = std::map<vecint,float>;
using mapRDH = std::map<int, int>; //{[reusedistance]: #array-accesses}

class ReuseDistance{

private:
    meliora::Stack st;
    mapRD mrd;
    mapRDH mrdh;
    float INF = std::numeric_limits<float>::infinity();
    float NINF = INF*(-1);

    //ReuseDistance();
public:
    //bool ifKeyExists(int);
    void calculateReuseDistance(vecvec);
    void printMapRD();
    void initMap(vecvec);
    void pushMrdh(int, int);
    //void calculate(vecvec);
    mapRDH calculateHist(vecvec);



};

//Constructor?

//Change parameter from int key to (check std::map) Key key
/*bool ReuseDistance::ifKeyExists(int key){
    auto search = mrd.find(key);
    bool ret=true;
    if(search == mrd.end()){
        ret = false;
    }
    else{
        ret = true;
    }

    return ret;
}
*/

void ReuseDistance::printMapRD(){

    std::cout<<"{"<<std::endl;
    for(const auto& kv : mrd ){
        const auto &key = kv.first;
        const auto &value = kv.second; 
        std::cout<<"[";
        for(const auto &v: key){
            std::cout<<v<<",";
        }
        std::cout<<"]";
        std::cout<<" : ";
        std::cout<<value<<std::endl;
    }
    std::cout<<"}"<<std::endl;
}

void ReuseDistance::initMap(vecvec sequence){

    // Since it's init simplfy it by removing checks
    for(auto &crds: sequence){
        
        auto search = mrd.find(crds);

        if(search == mrd.end()){
            mrd[crds]=NINF;
        }
        else{
            std::cout<<"Rais Exception"<<std::endl;
        }
    
    }
}

void ReuseDistance::pushMrdh(int key, int value){

    auto it = mrdh.find(key);

    if(it!=mrdh.end()){
        mrdh[key] +=value;
    }
    else{
        mrdh[key] =value;
    }
}

mapRDH ReuseDistance::calculateHist(vecvec sequence){

    for(auto &crd: sequence){

        //If crd not in stack; type(crd)=vecint
        if(st.elementInStack(crd)==false){
            st.push(crd);

            //X- Infinity(==0) ++1
            ReuseDistance::pushMrdh(0,1);
        }
        //If crd is in stack, delete the crd (in 3 steps) and then push it back on stack
        else{
            
            int pos = st.findElementPos(crd);
            size_t sz = st.size();
            int crd_rse_distance=1;

            //Step 1: Pop all the elements above the index of found crd
            vecvec popped_sequence;
            if(pos!=sz-1){
                for(int i=pos; i<st.size();i++){
                    popped_sequence.push_back(st.pop());
                }

                //Calculating reuse distance for crd
                crd_rse_distance =(sz-1)-pos;
            }
            else{
                crd_rse_distance = 1;
            }

            //Add details mrdh<reusedistance, frequency>
            ReuseDistance::pushMrdh(crd_rse_distance,1);

            //Step 2: Pop the element crd
            st.pop();

            //Step 3: Push elements from popped_sequence back onto the stack in reverse order
            //Only if there are elements in popped_sequence to be pushed back
            if(popped_sequence.empty()==false){
                //Step 3: Push all the popped elements in Step 2 in the reverse order of popping
                for( auto i =popped_sequence.rbegin(); i<popped_sequence.rend();i++){
                    st.push(*i);
                }
            }

            //Step 4: Push the new element crd
            st.push(crd);

            //Print the stack
            st.printStack();


        }
    }

    return mrdh;

}

/*
void ReuseDistance::calculate(vecvec sequence){
    
    //Init a map
    //mapRD mprd;
    //Initializing a map of all unique vecints (arrray access pattens) with a value of NINF
    initMap(sequence);

    //mprd.printMapRD();

    for(auto &crd: sequence){
        //If crd not in stack; type(crd)==vecint
        if(st.elementInStack(crd)==false){
            mrd[crd] = INF;
            st.push(crd);
        }
        //If crd is in stack, delete the crd (in 3 steps) and then push it back on stack
        else{

            //Step 1: Pop all the elements above the index of found crd

            int pos = st.findElementPos(crd);
            size_t sz = st.size();
            float crd_rse_distance=1.0;

            vecvec popped_sequence;

            //Only if there is something to pop
            if(pos!=sz){

                for(int i=pos+1; i<st.size();i++){
                    popped_sequence.push_back(st.pop());
                }

            }
           
            if(popped_sequence.size()!=0){
                //Should I add +1 at the end for popping the previous crd, which I find incorrect?
                int n_popped = float((sz-1)-pos);
                crd_rse_distance += n_popped;
                
                if(mrd[crd]==INF){
                    mrd[crd]=crd_rse_distance;
                }
                else if (mrd[crd]==NINF)
                {
                    std::cout<<"Raise Exception: Something wrong"<<std::endl;
                }
                else{
                    mrd[crd] = mrd[crd]+crd_rse_distance;
                }
                
            }
            else{
                mrd[crd]=crd_rse_distance;
            }
            

            //Step 2: Pop the element crd
            st.pop();

            //Only if there are elements in popped_sequence to be pushed back
            if(popped_sequence.size() !=0){
                //Step 3: Push all the popped elements in Step 2 in the reverse order of popping
                for( auto i =popped_sequence.rbegin(); i<popped_sequence.rend();i++){
                    st.push(*i);
                }
            }

            //Step 4: Push the new element crd
            st.push(crd);

            //Print the stack
            st.printStack();

        }
    }
    



} */

}

#endif