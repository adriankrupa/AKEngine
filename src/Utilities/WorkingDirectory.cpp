//
// Created by Adrian Krupa on 28.02.2017.
//

#ifdef _WIN32

#include <stdio.h>  /* defines FILENAME_MAX */
#include <direct.h>
#include <windows.h>
#include "Shlwapi.h"
#else

#include <libgen.h>

#endif

#include "akengine/Utilities/WorkingDirectory.h"

using namespace std;

string WorkingDirectory::argv0;

void WorkingDirectory::SetArgv0(char *argv0) {
    WorkingDirectory::argv0 = string(argv0);
}

string WorkingDirectory::GetExecutableDirectory() {

#ifdef _WIN32
    wchar_t buffer[MAX_PATH];

        // Will contain exe path
        HMODULE hModule = GetModuleHandle(NULL);
        if (hModule != NULL)
        {
            // When passing NULL to GetModuleHandle, it returns handle of exe itself
            GetModuleFileName(hModule, buffer, (sizeof(buffer)));
            PathRemoveFileSpec(buffer);
        }
        char ch[MAX_PATH];
        char DefChar = ' ';
        WideCharToMultiByte(CP_ACP,0,buffer,-1, ch,MAX_PATH,&DefChar, NULL);
        return string(ch);
#else
    char *canon_path = realpath(argv0.c_str(), NULL);
    char *path = dirname(canon_path);
    string s(path);
    delete canon_path;
    return s;
#endif
}