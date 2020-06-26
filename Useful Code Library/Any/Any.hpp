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

    template<typename U>
    class Derived : public Base {
    public:
        
    };

    BasePtr m_basePtr;
    std::type_index m_typeIndex;
};

#endif