//
// Created by Adrian Krupa on 28.02.2017.
//

#ifndef AKENGINE_WORKINGDIRECTORY_H
#define AKENGINE_WORKINGDIRECTORY_H

#include <string>
#include <cstdlib>

class WorkingDirectory {
    static std::string argv0;
public:
    static void SetArgv0(char *argv0);

    static std::string GetExecutableDirectory();
};


#endif //AKENGINE_WORKINGDIRECTORY_H
