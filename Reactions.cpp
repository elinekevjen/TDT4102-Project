#include "Reactions.h"

Reaction::Reaction(const std::string& substance1, const std::string& substance2, bool reacts,
                           const std::string& reactionType, const std::string& description) 
    : substance1{substance1},
      substance2{substance2},
      reacts{reacts},
      reactionType{reactionType},
      description{description} {}


bool Reaction::matches(const std::string& a, const std::string& b) const{
    return (a == substance1 && b == substance2) || (b == substance1 && a == substance2);
}

std::string Reaction::getReactionType() const{
    return reactionType;
}

std::string Reaction::getDescription() const{
    return description;
}

bool Reaction::hasReaction() const{
    return reacts;
}

std::istream& operator>>(std::istream& inStream, Reaction& reaction) {

    std::string line;
    if (!std::getline(inStream, line)) {
        return inStream;
    }

    std::stringstream stringStream(line);

    std::string reactsStr;

    std::getline(stringStream, reaction.substance1, ';');
    std::getline(stringStream, reaction.substance2, ';');
    std::getline(stringStream, reactsStr, ';');
    std::getline(stringStream, reaction.reactionType, ';');
    std::getline(stringStream, reaction.description, ';');

    reaction.reacts = (reactsStr == "true");

    return inStream;
}

void ReactionDatabase::loadFromFile(const std::string& filename){
    /*
    Leser inn mulige reaksjoner fra reactions/reactions.txt
    */
    std::ifstream ifs(filename);
    if (!ifs) {
        throw std::runtime_error("Kunne ikke åpne fil");
    }

    Reaction reaction;

    while (ifs >> reaction) {
        reactions.push_back(reaction);
    }
}
Reaction ReactionDatabase::findReaction(const std::string& a, const std::string& b) const{
    /*
    Finner ut om det skjer en reaksjon mellom to stoffer som tas inn
    */
    for (const auto& reaction : reactions) {
        if (reaction.matches(a,b)) {
            return reaction;
        } 
    }
    return Reaction(a, b, false, "Ingen reaksjon", "Ingen synlig endring");
}
