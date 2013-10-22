/*!
 * @file
 * Defines `boost::mpl11::distance`.
 */

#ifndef BOOST_MPL11_DISTANCE_HPP
#define BOOST_MPL11_DISTANCE_HPP

#include <boost/mpl11/fwd/distance.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename First, typename Last>
    struct distance
        : class_<First>::type::template distance<First, Last>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DISTANCE_HPP