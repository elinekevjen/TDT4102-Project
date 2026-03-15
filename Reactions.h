#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <sstream>
#include <fstream>
#include <vector>

class Reaction {
private:
    std::string substance1;
    std::string substance2;
    bool reacts;
    std::string reactionType;
    std::string description;
public:
    Reaction() = default;
    Reaction(const std::string& substance1,
             const std::string& substance2,
             bool reacts,
             const std::string& reactionType,
             const std::string& description);
    bool matches(const std::string& a, const std::string& b) const;
    std::string getReactionType() const;
    std::string getDescription() const;
    bool hasReaction() const;

    friend std::istream& operator>>(std::istream& is, Reaction& rule);
};


class ReactionDatabase {
private:
    std::vector<Reaction> reactions;
public:
    void loadFromFile(const std::string& filename);
    Reaction findReaction(const std::string& a, const std::string& b) const;
};