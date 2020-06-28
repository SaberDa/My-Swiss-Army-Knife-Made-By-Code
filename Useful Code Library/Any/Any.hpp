/* 
 * std: any是一种值类型，它能够更改其类型，同时仍然具有类型安全性。
 * 也就是说，对象可以保存任意类型的值，但是它们知道当前保存的值是哪种类型。
 * 在声明此类型的对象时，不需要指定可能的类型。 
 * 
 * std: any is a value type that can change its type while still having type safety. 
 * That is, objects can hold any type of value, but they know what type of value is currently saved. 
 * When declaring objects of this type, there is no need to specify possible types.
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

    /*
     * When creating a smart pointer, for general types, you can use std::decay to delete references
     * and cv characters to obtain the original type.
    */
    template<typename U, class = typename std::enable_if<!std::is_same<typename std::decay<U>::type, Any>::value, U>::type>
    Any(U&& value) : m_basePtr(new Derived<typename std::decay<U>::type>(std::forward<U>(value))),
        m_typeIndex(std::type_index(typeid(typename std::decay<U>::type))) {}

    bool isNull() const {
        return !bool(m_basePtr);
    }

    template<typename U>
    bool is() const {
        return m_typeIndex == std::type_index(typeid(U));
    }

    /* Transfer Any to actually type */
    template<typename U>
    U& anyCast() {
        if (!is<U>()) {
            std::cout<< "Can not cast " << typeid(U).name() << " to " << m_typeIndex.name() << std::endl;
            throw std::bad_cast();
        }

        auto dervide = dynamic_cast<Derived<U>*>(m_basePtr.get());
        return dervide->m_value;
    }

    Any& operator=(const Any& other) {
        if (m_basePtr == other.m_basePtr) return *this;
        m_basePtr = other.clone();
        m_typeIndex = other.m_typeIndex;
        return *this;
    }


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