/*!
 * @file
 * This file defines the `boost::mpl11::key` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_KEY_HPP
#define BOOST_MPL11_INTRINSIC_KEY_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct key_impl; }

template <typename AssociativeSequence, typename Element>
struct key
    : detail::tag_dispatched<
        extension::key_impl, AssociativeSequence, Element
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_KEY_HPP
