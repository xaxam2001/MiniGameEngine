#pragma once

namespace mge
{
    template<typename V>
    struct reverse_wrapper
    {
        V& vec;
        reverse_wrapper(V& _vec) : vec(_vec) {}
    
        typename V::reverse_iterator begin() {return vec.rbegin(); }
        typename V::reverse_iterator end() {return vec.rend(); }
    };

    template<typename T>
    reverse_wrapper<T> make_reverse(T& v)
    {
        return reverse_wrapper<T>(v);
    }
}
