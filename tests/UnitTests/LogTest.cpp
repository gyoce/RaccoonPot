#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <CommonTypes.hpp>

using testing::MatchesRegex;

TEST(Log, ShouldLogInCout) {
    const std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    RP::Log("Hello");
    std::cout.rdbuf(sbuf);
    EXPECT_THAT(buffer.str(), MatchesRegex("\\[.+\\]: Hello\n"));
}

TEST(Log, ShoudLogInCerr) {
    const std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cerr.rdbuf(buffer.rdbuf());
    RP::LogError("Hello");
    std::cerr.rdbuf(sbuf);
    EXPECT_THAT(buffer.str(), MatchesRegex("ERROR \\[.+\\]: Hello\n"));
}

TEST(Log, ShouldFormatCorrectly) {
    const std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    std::string myString = "myString";
    RP::Log("Hello {} {} {} | {}", 5, "World", 'a', myString);
    std::cout.rdbuf(sbuf);
    std::string bufferStr = buffer.str();
    EXPECT_THAT(buffer.str(), MatchesRegex("\\[.+\\]: Hello 5 World a \\| myString\n"));
}