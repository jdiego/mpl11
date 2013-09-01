/*!
 * @file
 * Defines `boost::mpl11::algorithm::contains`.
 */

#ifndef BOOST_MPL11_ALGORITHM_CONTAINS_HPP
#define BOOST_MPL11_ALGORITHM_CONTAINS_HPP

#include <boost/mpl11/algorithm/find.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/not_equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Returns whether `Sequence` contains one or more elements identical
     * to `Element`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            not_equal_to<
                find<Sequence, Element>::type,
                end<Sequence>::type
            >
       @endcode
     */
    template <typename Sequence, typename Element>
    struct contains
        : detail::tag_dispatched<tag::contains, Sequence, Element>::template
          with_default<
            lazy_always<
                not_equal_to<
                    typename find<Sequence, Element>::type,
                    typename end<Sequence>::type
                >
            >
          >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_CONTAINS_HPP