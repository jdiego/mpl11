/*!
 * @file
 * Defines `boost::mpl11::algorithm::none_of`.
 */

#ifndef BOOST_MPL11_ALGORITHM_NONE_OF_HPP
#define BOOST_MPL11_ALGORITHM_NONE_OF_HPP

#include <boost/mpl11/algorithm/find_if.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Overloaded algorithm for querying a sequence about the truth value of
     * its elements.
     */
    template <typename Sequence, typename Predicate = detail::optional>
    struct none_of;

    /*!
     * @ingroup algorithm
     *
     * Returns whether no element of a sequence satisfies a given `Predicate`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            equal_to<
                find_if<Sequence, Predicate>::type,
                end<Sequence>::type
            >
       @endcode
     */
    template <typename Sequence, typename Predicate>
    struct none_of BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Predicate>)
        : detail::tag_dispatched<tag::none_of, Sequence, Predicate>::template
          with_default<
            lazy_always<
                intrinsic::equal_to<
                    typename find_if<Sequence, Predicate>::type,
                    typename intrinsic::end<Sequence>::type
                >
            >
          >
    { };

    /*!
     * @ingroup algorithm
     *
     * Returns whether no element of a sequence is a `true`-valued boolean
     * `IntegralConstant`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `none_of<Sequence, _1>`.
     */
    template <typename Sequence>
    struct none_of<Sequence>
        : detail::tag_dispatched<tag::none_of, Sequence>::template
          with_default<
            lazy_always<
                none_of<Sequence, _1>
            >
          >
    { };
}}} // end namespace boost::mpl11::algorithm

#endif // !BOOST_MPL11_ALGORITHM_NONE_OF_HPP