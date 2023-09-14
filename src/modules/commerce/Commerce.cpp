#include "faker-cxx/Commerce.h"

#ifdef FAKER_USE_FMT
#include <fmt/format.h>
#else
#include <format>
#endif

#include "data/Commerce.h"
#include "faker-cxx/Finance.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/String.h"

namespace faker
{
std::string Commerce::department()
{
    return Helper::arrayElement<std::string>(departments);
}

std::string Commerce::price(double min, double max)
{
    return Finance::amount(min, max);
}

std::string Commerce::sku(unsigned int length)
{
    return String::numeric(length, false);
}

std::string Commerce::productAdjective()
{
    return Helper::arrayElement<std::string>(productAdjectives);
}

std::string Commerce::productMaterial()
{
    return Helper::arrayElement<std::string>(productMaterials);
}

std::string Commerce::productName()
{
    return Helper::arrayElement<std::string>(productNames);
}

std::string Commerce::productFullName()
{
#ifdef FAKER_USE_FMT
    return fmt::format("{} {} {}", productAdjective(), productMaterial(), productName());
#else
    return std::format("{} {} {}", productAdjective(), productMaterial(), productName());
#endif
}
}
