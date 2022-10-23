#include <bits/stdc++.h>
void out() {}//used with out(...args) recursivly
template <typename T, typename... Types>void out(T param, Types ... params) {
    std::cout << param;
    if (sizeof...(params) > 0) std::cout << "", out(params...);
    // else std::cout << std::"\n";
}
template <std::size_t N, std::size_t ... Is, typename... Types, class T> //https://stackoverflow.com/questions/58633925/expand-stdvector-into-parameter-pack
void out(std::array<T, N> const& vElements, std::index_sequence<Is...> const&, Types... params) {
    { out(vElements[Is]..., params...); }
}
template <std::size_t N, typename... Types, class T>void out(std::array<T, N> const& vElements, Types... params) {
    out(vElements, std::make_index_sequence<N>(), params...);
}
