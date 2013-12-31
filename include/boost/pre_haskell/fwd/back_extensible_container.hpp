/*!
 * @file
 * Forward declares `boost::mpl11::BackExtensibleContainer`.
 */

#ifndef BOOST_MPL11_FWD_BACK_EXTENSIBLE_CONTAINER_HPP
#define BOOST_MPL11_FWD_BACK_EXTENSIBLE_CONTAINER_HPP

#include <boost/mpl11/fwd/container.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * `Container` supporting insertion and removal at the end.
     *
     *
     * ## Refinement of
     * `Container`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `C`        | A `BackExtensibleContainer`
     * | `T`        | Any type
     *
     *
     * ## Valid expressions
     * | Expression              | %Type
     * | ----------              | ----
     * | `pop_back<C>::type`     | `BackExtensibleContainer`
     * | `push_back<C, T>::type` | `BackExtensibleContainer`
     */
    struct BackExtensibleContainer : Container {

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
        //! This operation must be provided by the user.
        template <typename Container>
        struct pop_back_impl;

        //! This operation must be provided by the user.
        template <typename Container, typename T>
        struct push_back_impl;
#endif

        /*!
         * Uses `push_back` repeatedly on `clear<%Container>::type` to
         * create a new container.
         */
        template <typename Container>
        struct new_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BACK_EXTENSIBLE_CONTAINER_HPP