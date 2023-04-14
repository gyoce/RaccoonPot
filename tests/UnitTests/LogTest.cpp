#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <Logs/Log.hpp>

using namespace EcsGameEngine;

using ::testing::MatchesRegex;

TEST(Log, ShouldLogInCout) {
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    Log::Log("Hello");
    std::cout.rdbuf(sbuf);
    EXPECT_THAT(buffer.str(), MatchesRegex("\\[.+\\]: Hello\n"));
}

TEST(Log, ShoudLogInCerr) {
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cerr.rdbuf(buffer.rdbuf());
    Log::LogError("Hello");
    std::cerr.rdbuf(sbuf);
    EXPECT_THAT(buffer.str(), MatchesRegex("ERROR \\[.+\\]: Hello\n"));
}

TEST(Log, ShouldFormatCorrectly) {
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    Log::Log("Hello %d %s %c", 5, "World", 'a');
    std::cout.rdbuf(sbuf);
    EXPECT_THAT(buffer.str(), MatchesRegex("\\[.+\\]: Hello 5 World a\n"));
}