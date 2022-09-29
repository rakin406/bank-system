#ifndef UTILS_H
#define UTILS_H

#include <string_view>

namespace utils
{
    // Trim functions
    std::string_view ltrim(std::string_view str);
    std::string_view rtrim(std::string_view str);
    std::string_view trim(std::string_view str);

    namespace net
    {
        /**
         * @brief Get local country using HTTP request.
         *
         * @return country as string.
         */
        std::string_view getLocalCountry();
    } // namespace net

} // namespace utils

#endif
