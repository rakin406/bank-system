#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <string_view>

namespace utils
{
    // Trim functions
    std::string_view ltrim(std::string_view str);
    std::string_view rtrim(std::string_view str);
    std::string_view trim(std::string_view str);

    /**
     * @brief Convert string to lowercase.
     *
     * @param str String.
     */
    void stringToLowerCase(std::string* str);
} // namespace utils

#endif
