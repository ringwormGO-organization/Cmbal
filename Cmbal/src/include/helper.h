/* 
 * This file was made just to help "visitor.c".
 * In functions like "builtin_function_clear" it is required to have more lines of code because to clean it up
 * and we don't punt in switch statments multiple lines of code
 * and here will be functions which will have more lines of code.
*/

#ifndef HELPER_H
#define HELPER_H

#define PRINT(...) printf(__VA_ARGS__)
#define FGETS(...) fgets(__VA_ARGS__)
#define EXIT(...) exit(__VA_ARGS__)

void console_clear();

#endif