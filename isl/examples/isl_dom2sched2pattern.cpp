
//#define ISL_NO_EXCEPTIONS
#include <stdlib.h>
#include <isl/cpp.h>
#include <isl/ctx.h>

//#include <isl/isl-noexceptions.h>
//#include <isl/ctx.h>
//#include <islcpp/islcpp.hpp>
/*
#include <isl/set.h>
#include <isl/map.h>
#include <isl/point.h>
#include <isl/stdint.h>*/

#include <vector>
#include <tuple>

using namespace std;
using namespace isl;


int getIterationSpace(isl::set domain){

    std::vector<std::tuple<int64_t, int64_t>> pointlist2d;

    /*auto callback = [&pointlist2d, &domain](isl::point pt) -> isl_stat {
        
        int x = pt.get_coordinate_val(isl::dim::set, 0).get_num_si();
        int y = pt.get_coordinate_val(isl::dim::set, 1).get_num_si();

        pointlist2d.emplace_back(x,y);

        return isl_stat_ok;
    };*/

    domain.foreach_point([&pointlist2d, &domain](isl::point pt) -> isl_stats {

        int x = pt.get_coordinate_val(isl::dim::set, 0).get_num_si();
        int y = pt.get_coordinate_val(isl::dim::set, 1).get_num_si();

        pointlist2d.emplace_back(x,y);

        return isl::stat::ok();
    });


    return 0;

}

/*int main(){

    isl::ctx *ctx_ptr = isl::ctx::alloc();
    ctx my_ctx(ctx_ptr);

    //isl::ctx* ctx = isl::ctx::get();
    //isl::ctx *ctx;
    //ctx->get();
    isl::set testDomain = isl::set(my_ctx,"{[i,j]: 0<=i<10 and 0<=j<5}");

    getIterationSpace(testDomain);

    isl::ctx *released_ptr = my_ctx.release();
    isl::ctx::free(released_ptr);

    //ctx->release();
}

int main(){

    isl::ctx myctx(isl_ctx );
    return 0;
}*/

int main() {
  //isl::ctx ctx = isl::ctx(isl_ctx_alloc());
  //isl::set set = isl::set::empty(isl::space(ctx, 0, 0));

  isl_ctx *ct;  
  isl::ctx myctx = isl::ctx(ct);

  isl::set testDomain = isl::set(myctx,"{[i,j]: 0<=i<10 and 0<=j<5}");
  
  myctx.release();
  
  return 0;
}