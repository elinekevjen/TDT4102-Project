#include "Laboratory.h"
#include "Substances.h"
#include <vector>

int main() {
    Lab::run();

    /* std::ifstream ifs("files/substances.txt");
    std::string line;
    
    std::vector<std::unique_ptr<Substance>> subs;
    while (std::getline(ifs, line)) {
        subs.push_back(createSubstanceFromLine(line));
    }

    for (const auto& sub : subs) {
        std::cout << sub->getName() << std::endl;
    } */
    return 0;
}