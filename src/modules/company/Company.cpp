#include "faker-cxx/Company.h"

#ifdef FAKER_USE_FMT
#include <fmt/format.h>
#else
#include <format>
#endif

#include "data/BuzzAdjectives.h"
#include "data/BuzzNouns.h"
#include "data/BuzzVerbs.h"
#include "data/CatchPhraseAdjectives.h"
#include "data/CatchPhraseDescriptors.h"
#include "data/CatchPhraseNouns.h"
#include "data/CompanyTypes.h"
#include "data/Industries.h"
#include "data/Suffixes.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Person.h"

namespace faker
{
std::string Company::name()
{
    std::string companyName;

    switch (Number::integer<int>(3))
    {
    case 0:
#ifdef FAKER_USE_FMT
        companyName = fmt::format("{} {}", Person::lastName(), Helper::arrayElement<std::string>(companySuffixes));
#else
        companyName = std::format("{} {}", Person::lastName(), Helper::arrayElement<std::string>(companySuffixes));
#endif
        break;
    case 1:
#ifdef FAKER_USE_FMT
        companyName = fmt::format("{} {} {}", Person::firstName(), Person::lastName(), Person::jobArea());
#else
        companyName = std::format("{} {} {}", Person::firstName(), Person::lastName(), Person::jobArea());
#endif
        break;
    case 2:
#ifdef FAKER_USE_FMT
        companyName = fmt::format("{} {} {} Services", Person::firstName(), Person::lastName(), Person::jobArea());
#else
        companyName = std::format("{} {} {} Services", Person::firstName(), Person::lastName(), Person::jobArea());
#endif
        break;
    case 3:
#ifdef FAKER_USE_FMT
        companyName = fmt::format("{} {} {} {}", Person::firstName(), Person::lastName(), Person::jobArea(),
                                  Helper::arrayElement<std::string>(companySuffixes));
#else
        companyName = std::format("{} {} {} {}", Person::firstName(), Person::lastName(), Person::jobArea(),
                                  Helper::arrayElement<std::string>(companySuffixes));
#endif
        break;
    }

    return companyName;
}

std::string Company::type()
{
    return Helper::arrayElement<std::string>(companyTypes);
}

std::string Company::industry()
{
    return Helper::arrayElement<std::string>(companyIndustries);
}

std::string Company::buzzPhrase()
{
#ifdef FAKER_USE_FMT
    return fmt::format("{} {} {}", buzzVerb(), buzzAdjective(), buzzNoun());
#else
    return std::format("{} {} {}", buzzVerb(), buzzAdjective(), buzzNoun());
#endif
}

std::string Company::buzzAdjective()
{
    return Helper::arrayElement<std::string>(buzzAdjectives);
}

std::string Company::buzzNoun()
{
    return Helper::arrayElement<std::string>(buzzNouns);
}

std::string Company::buzzVerb()
{
    return Helper::arrayElement<std::string>(buzzVerbs);
}

std::string Company::catchPhrase()
{
#ifdef FAKER_USE_FMT
    return fmt::format("{} {} {}", catchPhraseAdjective(), catchPhraseDescriptor(), catchPhraseNoun());
#else
    return std::format("{} {} {}", catchPhraseAdjective(), catchPhraseDescriptor(), catchPhraseNoun());
#endif
}

std::string Company::catchPhraseAdjective()
{
    return Helper::arrayElement<std::string>(catchPhraseAdjectives);
}

std::string Company::catchPhraseDescriptor()
{
    return Helper::arrayElement<std::string>(catchPhraseDescriptors);
}

std::string Company::catchPhraseNoun()
{
    return Helper::arrayElement<std::string>(catchPhraseNouns);
}
}
