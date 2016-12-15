/*
 * Demonstration of using multiple variadic templates
 */

#include <tuple>

template <typename ...Ts>
struct Pack { };

template <typename ...Ts>
class Foo;

template <typename ...Ts, typename ...Us>
struct Foo<Pack<Ts...>, Pack<Us...> > {
    std::tuple<Ts...> first;
    std::tuple<Us...> second;
};

/********** USAGE EXAMPLE **********/

#include <iostream>
#include <string>

struct Bar {
    std::string str;
    Bar() { }
    Bar(std::string str) : str(str) { }
};

int main() {
    Foo<Pack<int, std::string, float>, Pack<Bar, char> > foo;

    std::get<std::string>(foo.first) = "hello";
    std::get<Bar>(foo.second) = Bar("bar");

    std::cout << std::get<std::string>(foo.first) << " " << std::get<Bar>(foo.second).str << std::endl;
}
