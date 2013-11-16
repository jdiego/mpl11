/*!
 * @file
 * Forward declares `boost::mpl11::all_of`.
 */

#ifndef BOOST_MPL11_FWD_ALL_OF_HPP
#define BOOST_MPL11_FWD_ALL_OF_HPP

#include <boost/mpl11/fwd/identity.hpp>
#include <boost/mpl11/fwd/quote.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     *
     * Returns whether all the elements of a `Sequence` satisfy a given
     * `Predicate`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `none_of<%Sequence, lambda<not_<apply<Predicate, _0>>>>`.
     */
    template <typename Sequence, typename Predicate = quote<identity>>
    struct all_of;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ALL_OF_HPP
