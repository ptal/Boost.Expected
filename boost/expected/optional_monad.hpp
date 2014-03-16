// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// (C) Copyright 2014 Vicente J. Botet Escriba

#ifndef BOOST_EXPECTED_OPTIONAL_MONAD_HPP
#define BOOST_EXPECTED_OPTIONAL_MONAD_HPP

#include <boost/expected/expected_like_monad.hpp>
#include <boost/optional.hpp>
#include <boost/mpl/identity.hpp>

namespace boost
{
  namespace monads
  {

    template <class T>
    struct is_monad<optional<T> > : std::true_type {};
    template <class T, class U>
    struct bind<optional<T>, U> : mpl::identity<optional<U> > {};
    template <class T>
    struct functor_category<optional<T> > : mpl::identity<category::expected_like> { };
    template <class T>
    struct monad_category<optional<T> > : mpl::identity<category::expected_like> { };
    template <class T>
    struct monad_error_category<optional<T> > : mpl::identity<category::expected_like> { };

    template <class T>
    struct unexpected_traits< optional<T> > {
      template< class M >
      using type = none_t;
      static constexpr none_t get_unexpected(optional<T> const& ) { return none; }
    };


  }
}


#endif // BOOST_EXPECTED_OPTIONAL_MONAD_HPP