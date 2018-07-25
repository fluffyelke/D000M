/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Print.h"

void createPrint(const std::string& printInfo) {
    std::cout << printInfo << " object CREATED.\n";
}
void destroyPrint(const std::string& printInfo) {
    std::cout << printInfo << " object DESTROYED.\n";
}
