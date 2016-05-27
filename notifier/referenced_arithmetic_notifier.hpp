//
//  referenced_arithmetic_notifier.hpp
//  notifier
//
//  Created by ISHII 2bit on 2016/05/28.
//
//

#pragma once

#ifndef referenced_arithmetic_notifier_h
#define referenced_arithmetic_notifier_h

#include <functional>

namespace bbb {
    template <typename type>
    struct referenced_arithmetic_notifier {
        referenced_arithmetic_notifier() = delete;
        referenced_arithmetic_notifier(type &value)
        : value(value) {}
        
        referenced_arithmetic_notifier(std::function<void(type)> will_change,
                                       std::function<void(type)> did_change)
        : will_change(will_change)
        , did_change(did_change) {}
        
        referenced_arithmetic_notifier(const referenced_arithmetic_notifier &mom) = default;
        referenced_arithmetic_notifier(referenced_arithmetic_notifier &&mom) = default;
        
        referenced_arithmetic_notifier &operator=(const referenced_arithmetic_notifier &mom) = default;
        referenced_arithmetic_notifier &operator=(referenced_arithmetic_notifier &&mom) = default;

        operator type &() { return value; }
        operator const type &() const { return value; }
        
        template <typename T>
        referenced_arithmetic_notifier &operator=(T value) {
            will_change(this->value);
            this->value = value;
            did_change(this->value);
            return *this;
        }
        
        referenced_arithmetic_notifier &operator++() {
            will_change(this->value);
            ++value;
            did_change(this->value);
            return *this;
        }
        
        referenced_arithmetic_notifier operator++(int) {
            referenced_arithmetic_notifier tmp = *this;
            will_change(this->value);
            value++;
            did_change(this->value);
            return tmp;
        }
        
        referenced_arithmetic_notifier &operator--() {
            will_change(this->value);
            --value;
            did_change(this->value);
            return *this;
        }
        
        referenced_arithmetic_notifier operator--(int) {
            referenced_arithmetic_notifier tmp = *this;
            will_change(this->value);
            value--;
            did_change(this->value);
            return tmp;
        }
        
#define def_op(op)\
        template <typename T>\
        referenced_arithmetic_notifier &operator op(T value) {\
            will_change(this->value);\
            this->value op value;\
            did_change(this->value);\
            return *this;\
        }
        
        def_op(+=);
        def_op(-=);
        def_op(*=);
        def_op(/=);
        def_op(%=);
        def_op(&=);
        def_op(|=);
        def_op(^=);
        def_op(<<=);
        def_op(>>=);
        
#undef def_op
        
        void notify_will_change() { will_change(this->value); }
        void notify_did_change() { did_change(this->value); }
        void value_will_change(std::function<void(type)> callback) {
            will_change = callback;
        }
        void value_did_change(std::function<void(type)> callback) {
            did_change = callback;
        }
    private:
        type &value;
        std::function<void(type)> will_change = [](type){};
        std::function<void(type)> did_change  = [](type){};
    };
};

#endif /* referenced_arithmetic_notifier_h */
