#include "../../include/instance/instanceparser.h"
#include <string>

InstanceParser::InstanceParser(std::string filename) {
    _string_program = IOController::getStringOfFile(filename);
    head = 0;
}

char InstanceParser::peek() {
    return ((unsigned int)head < _string_program.length()) ? _string_program[head]: '@';
}

char InstanceParser::get() {
    return ((unsigned int)head < _string_program.length()) ? _string_program[head++]: '@';
}

bool InstanceParser::isBlank() {
    return (peek() == '\n' || peek() == '\t' || peek() == ' ' || peek() == '\r' || peek() == '\b');
}

void InstanceParser::omitBlanks() {
    while(isBlank()) get();
}

std::string InstanceParser::omitWord() {
    std::string word = "";
    while(!isBlank()) word += get();
    return word;
}

MDPInstance InstanceParser::parse() {
    int n;
    int k;
    int i = 0, j = 0;
    omitBlanks();
    n = std::stoi(omitWord());
    omitBlanks();
    k = std::stoi(omitWord());
    omitBlanks();
    std::vector<std::vector<double>> elementos(n, std::vector<double>(k));
    while ((unsigned int)head < _string_program.length()) {
        double coordenada = std::stod(omitWord());
        elementos[i][j++] = coordenada;
        omitBlanks();
        if (j == k) {
            j = 0;
            i++;
        }
    }

    MDPInstance mdp1(elementos, 3);
    return mdp1;
}