#include "faker-cxx/Music.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "data/Artists.h"
#include "data/Genres.h"
#include "data/SongNames.h"

using namespace ::testing;
using namespace faker;

class MusicTest : public Test
{
public:
};

TEST_F(MusicTest, shouldGenerateArtist)
{
    const auto generatedArtist = Music::artist();

    ASSERT_TRUE(std::any_of(artists.begin(), artists.end(),
                            [generatedArtist](const std::string& artist) { return generatedArtist == artist; }));
}

TEST_F(MusicTest, shouldGenerateGenre)
{
    const auto generatedGenre = Music::genre();

    ASSERT_TRUE(std::any_of(genres.begin(), genres.end(),
                            [generatedGenre](const std::string& genre) { return generatedGenre == genre; }));
}

TEST_F(MusicTest, shouldGenerateSongName)
{
    const auto generatedSongName = Music::songName();

    ASSERT_TRUE(std::any_of(songNames.begin(), songNames.end(),
                            [generatedSongName](const std::string& songName)
                            { return generatedSongName == songName; }));
}
