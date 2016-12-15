/*
 * This example shows how to use a tuple to use arbitrary types in a field
 * for a class.
 */ 

#include <tuple>

template <typename ...Ts>
class Foo {
    std::tuple<Ts...> m_tup;

public:
    template <typename T>
    void set(T val) { std::get<T>(m_tup) = val; }

    template <typename T>
    T get() { return std::get<T>(m_tup); }
};

/********** USAGE EXAMPLE ***********/

#include <iostream>
#include <string>

class Bar {
    std::string m_str;

public:
    Bar() { }
    Bar(std::string str) : m_str(str) { }
    void operator()() { std::cout << "hi my name is " << m_str << std::endl; }
};

int main() {
    Foo<int, std::string, Bar> foo;

    foo.set<Bar>(Bar("kota"));
    foo.set<int>(4);
    foo.set<std::string>("baz");

    foo.get<Bar>()();
    std::cout << foo.get<int>() << " " << foo.get<std::string>() << std::endl;
}
