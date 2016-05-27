//
//  notifier.hpp
//  notifier
//
//  Created by ISHII 2bit on 2016/05/28.
//
//

#pragma once

#ifndef notifier_h
#define notifier_h

#include "arithmetic_notifier.hpp"
#include "referenced_arithmetic_notifier.hpp"
#include "string_notifier.hpp"

namespace bbb {
    namespace detail {
        template <typename, typename = void>
        struct notifier;
        
        template <typename type_>
        struct notifier<type_, typename std::enable_if<std::is_arithmetic<type_>::value>::type> {
            using type = arithmetic_notifier<type_>;
        };
        
        template <typename type_>
        struct notifier<type_, typename std::enable_if<is_basic_string<type_>::value>::type> {
            using type = string_notifier<type_>;
        };
    };
    
    template <typename type>
    using notifier = typename detail::notifier<type>::type;
};

#endif /* notifier_h */
