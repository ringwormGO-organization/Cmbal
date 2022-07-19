#include <stdio.h>
#include <string.h>
#include "include/lexer.h"
#include "include/parser.h"
#include "include/visitor.h"
#include "include/io.h"
#include "include/helper.h"

#define MAX_LIMIT 200
int print_help()
{
    PRINT("Usage:\nCmbal.out <filename>\n");
    return 1; 
}

int main(int argc, char* argv[])
{
    if (argc >= 2)
    {
        for(int i = 1; i < argc; i++)
        {
            int len = strlen(argv[i]);
            char* last_four = &argv[i][len-6];

            if(strcmp(last_four,".cmbal") == 0)
            {
                lexer_T* lexer = init_lexer(get_file_contents(argv[i]));
                parser_T* parser = init_parser(lexer);
                AST_T* root = parser_parse(parser, parser->scope);
                visitor_T* visitor = init_visitor();
                visitor_visit(visitor, root);
            }

            else 
            {
                return print_help();
            }
        }
    }

    else 
    {
        char input[MAX_LIMIT];
        PRINT("Welcome to the Cmbal V1.1\n\n");

        while(1)
        {
            PRINT(">> ");
            FGETS(input, MAX_LIMIT, stdin);
            lexer_T* lexer = init_lexer(input);
            parser_T* parser = init_parser(lexer);
            AST_T* root = parser_parse(parser, parser->scope);
            visitor_T* visitor = init_visitor();
            visitor_visit(visitor, root);
        }
    }
    return 0;
}
