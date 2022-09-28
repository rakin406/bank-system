#ifndef UTILS_H
#define UTILS_H

#include <string_view>

namespace utils
{
    // Trim functions
    std::string_view ltrim(std::string_view str);
    std::string_view rtrim(std::string_view str);
    std::string_view trim(std::string_view str);

} // namespace utils

#endif
