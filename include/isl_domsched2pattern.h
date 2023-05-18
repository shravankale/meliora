#ifndef ISL_DOMSCHED2PATTERN_H
#define ISL_DOMSCHED2PATTERN_H

#include "isl/isl-noexceptions.h"
//#include <isl/set.h>
//#include <isl/map.h>
#include <vector>
#include <any>
#include <tuple>
#include <iostream>

//#include "llvm/ADT/Sequence.h"

//using namespace llvm;

namespace isl_ItSpace{

    using vector_tuple2d = std::vector<std::tuple<int, int>>;
    using vecany = std::vector<std::any>;
    using vecint = std::vector<int>;
    using vecvec = std::vector<vecint>;

    vecvec getSetPoints(isl::set domain){

        vecvec pointlist;

        isl::size domain_length = domain.dim(isl::dim::set);
        //The case doesn't work if is_error() is not called before static_cast
        std::cout<<"bool: "<<domain_length.is_error()<<std::endl;
        unsigned int dval = static_cast<unsigned int>(domain_length);

        //unsigned int dval =2;

        domain.foreach_point([&pointlist, &domain, &dval](isl::point pt) -> isl::stat {

            vecint coord;

            for(size_t i=0;i<dval;i++){
                coord.push_back(pt.get_coordinate_val(isl::dim::set, i).get_num_si());
            }

            pointlist.push_back(coord);
            isl::stat stat_obj;
            return stat_obj.ok();
 
        });

        return pointlist;
    }

    void print_vecvec(vecvec vectorvector){

        for(auto &crd: vectorvector){
            std::cout<<"(";
            //Convert below to iterator to improve print
            for(auto &index: crd){
                std::cout<<index<<","; 
            }
            std::cout<<")\n";
        }
    }

    vecvec getSchedulePattern(isl::set domain, isl::map schedule){

        vecvec pointlist;
        isl::set domainSched;

        domainSched = domain.apply(schedule);
        pointlist = getSetPoints(domainSched);

        return pointlist;
    }

    /*
    void print_IterationSpace(vector_tuple2d aset){

        for(auto &t: aset){    
            std::cout<<"("<<std::get<0>(t)<<","<<std::get<1>(t)<<")"<<std::endl;
        }
    }
    

    vector_tuple2d getIterationSpace(isl::set domain){

        vector_tuple2d pointlist2d;

        isl::size domain_length = domain.dim(isl::dim::set);
        std::cout<<"bool: "<<domain_length.is_error()<<std::endl;

        //static_cast<unsigned>(domain_length).get_num_si();
        //unsigned l = domain.tuple_dim();

        //Cross check when dimension=1 Check isl/isl-noexception.h line:176
        unsigned int dval = static_cast<unsigned int>(domain_length);
        std::cout<<"Domain iteration: "<<dval<<std::endl;
    
        domain.foreach_point([&pointlist2d, &domain, &dval](isl::point pt) -> isl::stat {

                //isl::size pt_dim = pt.tuple_dim();
                //std::tuple coord = std::make_tuple()

                int x = pt.get_coordinate_val(isl::dim::set, 0).get_num_si();
                int y = pt.get_coordinate_val(isl::dim::set, 1).get_num_si();

                pointlist2d.emplace_back(x,y);
                isl::stat stat_obj;
                return stat_obj.ok();
        });

        return pointlist2d;
    }
    */
}

/*
int main(){

    isl_ctx* ctx = isl_ctx_alloc();
    isl::set testDomain = isl::set(ctx, "{[i,j]: 0<=i<10 and 0<=j<5}");

    getIterationSpace(domain);
    isl_ctx_free(ctx);
}
*/

#endif //ISL_DOMSCHED2PATTERN_H