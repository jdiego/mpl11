/*!
 * @file
 * Defines `boost::mpl11::foldr`.
 */

#ifndef BOOST_MPL11_FOLDR_HPP
#define BOOST_MPL11_FOLDR_HPP

#include <boost/mpl11/fwd/foldr.hpp>

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 {
namespace foldr_detail {
    template <typename First, typename Last, typename State, typename F,
              bool = equal_to<First, Last>::type::value>
    struct foldr_impl
        : apply_wrap<
            F,
            typename foldr_impl<
                typename next<First>::type, Last, State, F
            >::type,
            typename deref<First>::type
        >
    { };

    template <typename First, typename Last, typename State, typename F>
    struct foldr_impl<First, Last, State, F, true>
        : identity<State>
    { };
} // end namespace foldr_detail

template <typename Sequence, typename State, typename F>
struct foldr
    : foldr_detail::foldr_impl<
        typename begin<Sequence>::type,
        typename end<Sequence>::type,
        State,
        typename lambda<F>::type
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDR_HPP