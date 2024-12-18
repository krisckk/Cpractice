IPHTC Online Judge Home Problems Contests Status
 Rank 
 About 
Accepted
Time: 1ms Memory: 4MB Lang: C++ Author: lightbulb
ID	Status	Memory	Time	Score
1
Accepted
4MB
1ms
1
2
Accepted
4MB
1ms
1
3
Accepted
4MB
0ms
1
4
Accepted
4MB
0ms
1
5
Accepted
4MB
0ms
1
6
Accepted
4MB
1ms
1

#include <cstddef>
#include <iterator>

namespace IPHTC {
    template<typename T>
    class Enumerate {
    private:
        using TIter = decltype(std::begin(std::declval<T>()));
        using TVal = decltype(*std::begin(std::declval<T>()));

    public:
        class iterator {
        public:
            using value_type = std::pair<const std::size_t &, TVal>;
            using reference = value_type;
            using pointer = value_type*;
            using difference_type = std::ptrdiff_t;
            using iterator_category = std::input_iterator_tag;

        public:
            iterator() = default;
            iterator(std::size_t index, TIter it) : m_size{index}, m_it{it} {}
            iterator &operator++ () { ++m_size; ++m_it; return *this; }
            bool operator== (const iterator &rhs) const { return m_it == rhs.m_it; }
            bool operator!= (const iterator &rhs) const { return m_it != rhs.m_it; }
            reference operator* () const { return {m_size, *m_it}; }

        private:
            std::size_t m_size;
            TIter m_it;
        };

        Enumerate(T iterable) : m_iterable{iterable} {
            m_size = std::distance(std::begin(m_iterable), std::end(m_iterable));
        }
        iterator begin() const { return iterator{0, std::begin(m_iterable)}; }
        iterator end() const { return iterator{m_size, std::end(m_iterable)}; }
        const std::size_t &size() const { return m_size; }

    private:
        T m_iterable;
        std::size_t m_size;
    };
};

// Do not modify the following contents! Otherwise the compilation will fail.
#include <utility>
namespace IPHTC {
    template<typename T>
    Enumerate<T> enumerate(T &&iterable) {
        return {std::forward<T>(iterable)};
    }
};

// You may test your own implementation with this function.
#include <iostream>
#include <string>
#include <vector>
#include <list>
void test() {
    for (auto [i, x] : IPHTC::enumerate(std::vector<int>{1, 2, 3, 4, 5})) {
        std::cout << i << ": " << x << '\n';
    }
    std::string s = "Hello, World!";
    for (auto [i, c] : IPHTC::enumerate(s)) {
        std::cout << i << ": " << c << '\n';
        c = '3';
    }
    std::list<int> l{1, 2, 3, 4, 5};
    for (auto [i, x] : IPHTC::enumerate(l)) {
        std::cout << i << ": " << x << '\n';
        x = 3;
    }
}
IPHTC Online Judge

Powered by OnlineJudge   Version: 20240121-980e4

