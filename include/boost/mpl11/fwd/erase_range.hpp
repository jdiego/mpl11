/*!
 * @file
 * Forward declares `boost::mpl11::erase_range`.
 */

#ifndef BOOST_MPL11_FWD_ERASE_RANGE_HPP
#define BOOST_MPL11_FWD_ERASE_RANGE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Removes several adjacent elements in a container, starting from
     * an arbitrary position.
     */
    template <typename Container, typename First, typename Last>
    struct erase_range;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ERASE_RANGE_HPP