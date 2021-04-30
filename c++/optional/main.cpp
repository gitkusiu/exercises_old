#include <iostream>
#include <string>
#include <optional>

std::optional<std::string>  get_string_from_cin()
{
    std::string s;
    std::cin >> s;
    if(s.empty()) return {};
    return s;
//    return s.empty() ? std::nullopt : s ;
}

int main()
{
    
    auto s = get_string_from_cin();
    if( s.has_value() ) {
        std::cout << "Jest wartosc" << std::endl;
    } else {
        std::cout << "nie ma wartosci" << std::endl;
    }
    return 0;
}
