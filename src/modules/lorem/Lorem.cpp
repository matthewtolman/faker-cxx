#include "faker-cxx/Lorem.h"

#ifdef FAKER_USE_FMT
#include <fmt/format.h>
#else
#include <format>
#endif

#include "../../common/StringHelper.h"
#include "data/LoremWords.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string Lorem::word()
{
    return Helper::arrayElement<std::string>(loremWords);
}

std::string Lorem::words(unsigned numberOfWords)
{
    std::vector<std::string> words;

    for (unsigned i = 0; i < numberOfWords; i++)
    {
        words.push_back(word());
    }

    return StringHelper::join(words, " ");
}

std::string Lorem::sentence(unsigned minNumberOfWords, unsigned maxNumberOfWords)
{
    const std::integral auto numberOfWords = Number::integer(minNumberOfWords, maxNumberOfWords);

    const auto sentenceWords = words(numberOfWords);

#ifdef FAKER_USE_FMT
    return fmt::format("{}{}.", static_cast<char>(std::toupper(sentenceWords[0])), sentenceWords.substr(1));
#else
    return std::format("{}{}.", static_cast<char>(std::toupper(sentenceWords[0])), sentenceWords.substr(1));
#endif
}

std::string Lorem::sentences(unsigned minNumberOfSentences, unsigned maxNumberOfSentences)
{
    const std::integral auto numberOfSentences = Number::integer(minNumberOfSentences, maxNumberOfSentences);

    std::vector<std::string> sentences;

    for (unsigned i = 0; i < numberOfSentences; i++)
    {
        sentences.push_back(sentence());
    }

    return StringHelper::join(sentences, " ");
}

std::string Lorem::slug(unsigned int numberOfWords)
{
    std::vector<std::string> words;

    for (unsigned i = 0; i < numberOfWords; i++)
    {
        words.push_back(word());
    }

    return StringHelper::join(words, "-");
}

std::string Lorem::paragraph(unsigned int minNumberOfSentences, unsigned int maxNumberOfSentences)
{
    return sentences(minNumberOfSentences, maxNumberOfSentences);
}

std::string Lorem::paragraphs(unsigned int minNumberOfParagraphs, unsigned int maxNumberOfParagraphs)
{
    const std::integral auto numberOfParagraphs = Number::integer(minNumberOfParagraphs, maxNumberOfParagraphs);

    std::vector<std::string> paragraphs;

    for (unsigned i = 0; i < numberOfParagraphs; i++)
    {
        paragraphs.push_back(paragraph());
    }

    return StringHelper::join(paragraphs, "\n");
}

}
