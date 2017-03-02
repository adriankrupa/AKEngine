//
// Created by Adrian Krupa on 24.02.2017.
//

#include <spdlog/spdlog.h>

#include "akengine/Utilities/GLDebug.h"

using namespace std;

void printErrorLog(string logMessage) {
    auto console = spdlog::get("console");
    console->error(logMessage);
}