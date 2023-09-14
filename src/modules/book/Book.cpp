#include "faker-cxx/Book.h"

#include "data/Authors.h"
#include "data/Genres.h"
#include "data/Publishers.h"
#include "data/Titles.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/String.h"

#ifdef FAKER_USE_FMT
#include <fmt/format.h>
#else
#include <format>
#endif

namespace faker
{
std::string Book::title()
{
    return Helper::arrayElement<std::string>(titles);
}

std::string Book::genre()
{
    return Helper::arrayElement<std::string>(genres);
}

std::string Book::author()
{
    return Helper::arrayElement<std::string>(authors);
}

std::string Book::publisher()
{
    return Helper::arrayElement<std::string>(publishers);
}

std::string Book::isbn()
{
#ifdef FAKER_USE_FMT
    return fmt::format("{}-{}-{}-{}-{}", String::numeric(3, false), String::numeric(2), String::numeric(2),
                       String::numeric(5), String::numeric(1));
#else
    return std::format("{}-{}-{}-{}-{}", String::numeric(3, false), String::numeric(2), String::numeric(2),
                       String::numeric(5), String::numeric(1));
#endif
}
}
