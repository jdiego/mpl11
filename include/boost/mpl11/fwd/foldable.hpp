/*!
 * @file
 * Forward declares the @ref Foldable typeclass.
 */

#ifndef BOOST_MPL11_FWD_FOLDABLE_HPP
#define BOOST_MPL11_FWD_FOLDABLE_HPP

#include <boost/mpl11/fwd/functional.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>
#include <boost/mpl11/fwd/logical.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Foldable Foldable
     *
     * The `Foldable` typeclass is used for data structures that can
     * be folded.
     *
     *
     * ### Methods
     * `foldl` and `foldr`.
     *
     * ### Minimal complete definition
     * All the methods.
     *
     *
     * @todo
     * `Foldable` is currently weak compared to its Haskell counterpart
     * because I have not found a suitable way to implement a Monoid yet.
     *
     *
     * @todo
     * Rewrite `all`, `any` and `none`'s unit test using a `Foldable`
     * instead of an `Iterable`.
     *
     * @{
     */
    template <typename Datatype>
    struct Foldable;

    //! Right-associative fold of a structure using a binary operator.
    template <typename f, typename state, typename structure>
    struct foldr;


    //! Left-associative fold of a structure using a binary operator.
    template <typename f, typename state, typename structure>
    struct foldl;


    /*!
     * Boolean `StaticConstant` representing whether all the elements of
     * the structure satisfy the `predicate`.
     */
    template <typename predicate, typename structure>
    using all = foldr<
        compose<quote<and_>, predicate>,
        true_,
        structure
    >;

    /*!
     * Boolean `StaticConstant` representing whether none of the elements
     * of the structure satisfy the `predicate`.
     */
    template <typename predicate, typename structure>
    using none = all<compose<quote<not_>, predicate>, structure>;

    /*!
     * Boolean `StaticConstant` representing whether any element of the
     * structure satisfies the `predicate`.
     */
    template <typename predicate, typename structure>
    using any = not_<none<predicate, structure>>;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FOLDABLE_HPP