#include "../../include/IOController/IOController.h"

std::string IOController::getStringOfFile(std::string filename) {
    std::ifstream t(filename);
    std::string str;

    t.seekg(0, std::ios::end);   
    str.reserve(t.tellg());
    t.seekg(0, std::ios::beg);

    str.assign((std::istreambuf_iterator<char>(t)),
                std::istreambuf_iterator<char>());
    return str;
}

void IOController::toFile(std::string filename, std::string content) {
    std::ofstream ofs;
    ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
    ofs << content;
    ofs.close();
}