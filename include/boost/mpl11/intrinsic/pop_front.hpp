/*!
 * @file
 * Defines `boost::mpl11::intrinsic::pop_front`.
 */

#ifndef BOOST_MPL11_INTRINSIC_POP_FRONT_HPP
#define BOOST_MPL11_INTRINSIC_POP_FRONT_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/erase.hpp>
#include <boost/mpl11/intrinsic/is_empty.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace pop_front_detail {
    template <typename Sequence>
    struct pop_front_impl {
        static_assert(!intrinsic::is_empty<Sequence>::value,
        "Attempt to use `pop_front` on an empty sequence.");

        using type = typename intrinsic::erase<
            Sequence,
            typename intrinsic::begin<Sequence>::type
        >::type;
    };
} // end namespace pop_front_detail

namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Removes the element at the beginning of a sequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `erase<Sequence, begin<Sequence>::type>` if
     * `is_empty<Sequence>::type::value` is `false`, and a
     * compile-time assertion is triggered otherwise.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A compile-time assertion is triggered if the sequence is empty.
     */
    template <typename Sequence>
    struct pop_front
        : detail::tag_dispatched<tag::pop_front, Sequence>::template
          with_default<
            lazy_always<
                pop_front_detail::pop_front_impl<Sequence>
            >
          >
    { };
} // end namespace intrinsic
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_POP_FRONT_HPP