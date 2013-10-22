/*!
 * @file
 * Forward declares `boost::mpl11::distance`.
 */

#ifndef BOOST_MPL11_FWD_DISTANCE_HPP
#define BOOST_MPL11_FWD_DISTANCE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Returns the distance between `First` and `Last` iterators.
     *
     * @todo Put the doc in the appropriate concept.
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            foldl<
                iterator_range<First, Last>,
                ulong<0>,
                next<_1>
            >
       @endcode
     */
    template <typename First, typename Last>
    struct distance;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_DISTANCE_HPP