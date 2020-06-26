#ifndef __ANY_H__
#define __ANY_H__

#include <iostream>
#include <memory>
#include <typeindex>

class Any {
public:
    Any() : m_typeIndex(std::type_index(typeid(void))) {}

private:
    class Base;

    using BasePtr = std::unique_ptr<Base>;

    class Base {
    public:
        virtual ~Base() {}
        virtual BasePtr clone() const = 0;
    };

    template<typename T>
    class Derived : public Base
    {
    public:
        template<typename U>
        Derived(U&& value) : m_value(std::forward<U>(value)) {}

        virtual BasePtr clone() const override {
            return BasePtr(new Derived<T>(m_value));
        }

        T m_value;
    };

    BasePtr clone() const {
        if (m_basePtr != nullptr) return m_basePtr->clone();
        return nullptr;
    }

    BasePtr m_basePtr;
    std::type_index m_typeIndex;
};

#endif