/*!
 * @file
 * Defines `boost::mpl11::algorithm::is_permutation`.
 */

#ifndef BOOST_MPL11_ALGORITHM_IS_PERMUTATION_HPP
#define BOOST_MPL11_ALGORITHM_IS_PERMUTATION_HPP

#include <boost/mpl11/algorithm/count_if.hpp>
#include <boost/mpl11/algorithm/is_permutation_fwd.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/apply_wrap.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/size.hpp>
#include <boost/mpl11/operator/and.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/operator/not_equal_to.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
namespace is_permutation_detail {
    //////////////////////////////////////////////////////////////////////////
    // A very simple set-like class to support O1 membership testing.
    struct empty_basic_set {
        template <typename Element>
        struct has_key
            : false_
        { };
    };

    template <typename Element, typename Next>
    struct basic_set : Next {
        template <typename Other, bool = equal_to<Element, Other>::type::value>
        struct has_key
            : Next::template has_key<Other>
        { };

        template <typename Other>
        struct has_key<Other, true>
            : true_
        { };
    };
    //////////////////////////////////////////////////////////////////////////

    template <typename T, typename U>
    struct lazy_equal_to
        : equal_to<typename T::type, typename U::type>
    { };

    template <typename Sequence1, typename Sequence2, typename Predicate>
    class is_permutation_impl {
        using Last = typename end<Sequence1>::type;

        template <typename Iter, typename Counted,
                  bool = equal_to<Iter, Last>::type::value>
        struct contains_same_elements;

        template <typename Iter, typename Counted,
                  typename Element = typename deref<Iter>::type,
                  bool = Counted::template has_key<Element>::type::value>
        struct continue_;

        template <typename Iter, typename Counted>
        struct contains_same_elements<Iter, Counted, true /* Iter == Last */>
            : identity<true_>
        { };

        template <typename Iter, typename Counted>
        struct contains_same_elements<Iter, Counted, false /* Iter != Last */>
            : continue_<Iter, Counted>
        { };

        template <typename Iter, typename Counted>
        struct check_next
            : contains_same_elements<
                typename next<Iter>::type, Counted
            >
        { };

        // `Element` was already counted.
        template <typename Iter, typename Counted, typename Element>
        struct continue_<Iter, Counted, Element, true>
            : check_next<Iter, Counted>
        { };

        // `Element` was _not_ already counted.
        template <typename Iter, typename Counted, typename Element>
        struct continue_<Iter, Counted, Element, false> {
            using Pred = typename lambda<
                apply_wrap<Predicate, Element, _1>
            >::type;

            using InSequence1 = algorithm::count_if<
                view::bounded_by<Iter, Last>, Pred
            >;

            using InSequence2 = algorithm::count_if<
                Sequence2, Pred
            >;

            using type = typename and_<
                not_equal_to<typename InSequence2::type, ulong<0>>,
                lazy_equal_to<InSequence1, InSequence2>,
                check_next<Iter, basic_set<Element, Counted>>
            >::type;
        };

    public:
        using type = typename and_<
            equal_to<
                typename size<Sequence1>::type,
                typename size<Sequence2>::type
            >,
            contains_same_elements<
                typename begin<Sequence1>::type,
                empty_basic_set
            >
        >::type;
    };
} // end namespace is_permutation_detail

template <typename S1, typename S2, typename Pred>
struct dispatch<tag::default_<tag::is_permutation>, S1, S2, Pred>
    : is_permutation_detail::is_permutation_impl<
        S1, S2, typename lambda<Pred>::type
    >
{ };

template <typename S1, typename S2>
struct dispatch<tag::default_<tag::is_permutation>, S1, S2>
    : algorithm::is_permutation<S1, S2, quote<equal_to>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_IS_PERMUTATION_HPP