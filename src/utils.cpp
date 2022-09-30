#include "../include/utils.h"

#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>

namespace
{
    constexpr std::string_view WHITESPACE = " \n\r\t\f\v";
}

namespace utils
{
    std::string_view ltrim(std::string_view str)
    {
        size_t start = str.find_first_not_of(WHITESPACE);
        return (start == std::string_view::npos) ? "" : str.substr(start);
    }

    std::string_view rtrim(std::string_view str)
    {
        size_t end = str.find_last_not_of(WHITESPACE);
        return (end == std::string_view::npos) ? "" : str.substr(0, end + 1);
    }

    std::string_view trim(std::string_view str) { return rtrim(ltrim(str)); }

    void stringToLowerCase(std::string* str)
    {
        std::transform(str->begin(), str->end(), str->begin(),
                       [](unsigned char c) { return std::tolower(c); });
    }
} // namespace utils
