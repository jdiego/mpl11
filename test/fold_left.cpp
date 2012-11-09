/**
 * This file defines unit tests for the @em fold_left metafunction.
 */

#include <mpl11/fold_left.hpp>
#include <mpl11/pack.hpp>
#include <mpl11/push_back.hpp>
#include <mpl11/types.hpp>

#include <type_traits>


using namespace mpl11;

template <typename T>
struct add {
    template <typename X, typename Y>
    struct apply : integral_constant<T, X::value + Y::value> { };
};

static_assert(std::is_same<
                fold_left<add<int>, integral_constant<int, 0>,
                    integral_constant<int, 1>,
                    integral_constant<int, 2>,
                    integral_constant<int, 3>,
                    integral_constant<int, 4>
                >::type,
                integral_constant<int, 10>
              >::value, "");


struct accumulate_left {
    template <typename HeadPack, typename Tail>
    struct apply : push_back<Tail, HeadPack> { };
};

// Make sure the fold is made in the right direction.
static_assert(std::is_same<
                fold_left<accumulate_left,
                    pack<double>, int, float, char, void
                >::type,
                pack<double, int, float, char, void>
              >::value, "");

// Check with few arguments.
static_assert(std::is_same<
                fold_left<accumulate_left,
                    pack<double>, int
                >::type,
                pack<double, int>
              >::value, "");
