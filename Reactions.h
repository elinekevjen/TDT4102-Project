#pragma once

class ReactionRule {
private:
    std::string substance1;
    std::string substance2;
    bool reacts;
    std::string reactionType;
    std::string description;
public:
    ReactionRule(std::string s1, std::string s2, bool reacts,
                 std::string reactionType, std::string description);

    bool matches(const std::string& a, const std::string& b) const;
    std::string getReactionType() const;
    std::string getDescription() const;
    bool hasReaction() const;
};

class ReactionDatabase {
private:
    std::vector<ReactionRule> rules;
public:
    void loadFromFile(const std::string& filename);
    ReactionRule findReaction(const std::string& a, const std::string& b) const;
};