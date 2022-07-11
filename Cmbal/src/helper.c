#include "include/helper.h"

void console_clear()
{
    #ifdef _WIN32
        system("cls");
    #elif _WIN64
        system("cls");
    #elif __APPLE__ || __MACH__
        system("clear");
    #elif __linux__
        system("clear");
    #elif __FreeBSD__
        system("clear");
    #elif __unix || __unix__
        system("clear");
    #else
        #pragma error "Add name for "clear" command or use ANSI characters!"
    #endif
}