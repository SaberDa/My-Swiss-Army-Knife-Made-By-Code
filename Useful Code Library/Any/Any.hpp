/* 
 * std: any是一种值类型，它能够更改其类型，同时仍然具有类型安全性。
 * 也就是说，对象可以保存任意类型的值，但是它们知道当前保存的值是哪种类型。
 * 在声明此类型的对象时，不需要指定可能的类型。 
 */

#ifndef __ANY_H__
#define __ANY_H__

#include <iostream>
#include <memory>
#include <typeindex>

class Any {
public:
    Any() : m_typeIndex(std::type_index(typeid(void))) {}
    Any(Any& other) : m_basePtr(other.clone()), m_typeIndex(other.m_typeIndex) {}
    Any(Any&& other) : m_basePtr(std::move(other.m_basePtr)), m_typeIndex(m_typeIndex) {}

    

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