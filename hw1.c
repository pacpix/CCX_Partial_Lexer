/* Justin Stachofsky
 * Professor Wilder
 * CS 210
 * Homework #1
 */

#include <stdlib.h>
#include <stdio.h>

void comment(char FileData[]);
void identifier(char FileData[]);
void string(char FileData[]);
void keyword(char FileData[]);
void characterliteral(char FileData[]);
void operator(char FileData[]);
void numericliteral(char FileData[]);
void unk(char FileData[]);

int i = 0;

int main(int argc, char *argv[])
{
    FILE *file;
    char c;
    char FileData[10000];

    file = fopen(argv[1], "r");
    
    if(file == 0)
    {
        printf("File Failed to Open\n");
        return 0;
    }
    
    while((FileData[i]=fgetc(file))!=EOF)
    {
        i++;
    }    
    
    i=0;
    while(FileData[i] != '\0')
    {
        if(FileData[i] == '/' && FileData[i+1] == '*')
        {
             comment(FileData);
             i++;
        }
        else if(FileData[i] == '.' || FileData[i] == '<' || FileData[i] == '>' || FileData[i] == '(' || FileData[i] == ')' || FileData[i] == '+' || FileData[i] == '-' || FileData[i] == '*' || FileData[i] == '/' || FileData[i] == '|' || FileData[i] == '&' || FileData[i] == ';' || FileData[i] == ',' || FileData[i] == ':' || FileData[i] == '[' || FileData[i] == ']' || FileData[i] == '=' || FileData[i] == '!') 
        {
             operator(FileData);
        }
        else if(FileData[i] == '"')
        {
            string(FileData);
            i++;
        }
        else if((FileData[i] == 'a' && FileData[i+1] == 'c' && FileData[i+2] == 'c' && FileData[i+3] == 'e' && FileData[i+4] == 's' && FileData[i+5] == 's' && FileData[i+6] == 'o' && FileData[i+7] == 'r') || (FileData[i] == 'a' && FileData[i+1] == 'n' && FileData[i+2] == 'd') || (FileData[i] == 'a' && FileData[i+1] == 'r' && FileData[i+2] == 'r' && FileData[i+3] == 'a' && FileData[i+4] == 'y') || (FileData[i] == 'b' && FileData[i+1] == 'e' && FileData[i+2] == 'g' && FileData[i+3] == 'i' && FileData[i+4] == 'n') || (FileData[i] == 'b' && FileData[i+1] == 'o' && FileData[i+2] == 'o' && FileData[i+3] == 'l') || (FileData[i] == 'c' && FileData[i+1] == 'a' && FileData[i+2] == 's' && FileData[i+3] == 'e') || (FileData[i] == 'e' && FileData[i+1] == 'l' && FileData[i+2] == 's' && FileData[i+3] == 'e') || (FileData[i] == 'e' && FileData[i+1] == 'l' && FileData[i+2] == 's' && FileData[i+3] == 'i' && FileData[i+4] == 'f') || (FileData[i] == 'e' && FileData[i+1] == 'n' && FileData[i+2] == 'd') || (FileData[i] == 'e' && FileData[i+1] == 'x' && FileData[i+2] == 'i' && FileData[i+3] == 't') || (FileData[i] == 'f' && FileData[i+1] == 'u' && FileData[i+2] == 'n' && FileData[i+3] == 'c' && FileData[i+4] == 't' && FileData[i+5] == 'i' && FileData[i+6] == 'o' && FileData[i+7] == 'n') || (FileData[i] == 'i' && FileData[i+1] == 'f') || (FileData[i] == 'i' && FileData[i+1] == 'n' && FileData[i+2] == 't' && FileData[i+3] == 'e' && FileData[i+4] == 'g' && FileData[i+5] == 'e' && FileData[i+6] == 'r') || (FileData[i] == 'i' && FileData[i+1] == 'n' && FileData[i+2] == 't' && FileData[i+3] == 'e' && FileData[i+4] == 'r' && FileData[i+5] == 'f' && FileData[i+6] == 'a' && FileData[i+7] == 'c' && FileData[i+8] == 'e') || (FileData[i] == 'i' && FileData[i+1] == 's' && FileData[i+2] == ' ') || (FileData[i] == 'i' && FileData[i+1] == 's' && FileData[i+2] == '\n') || (FileData[i] == 'l' && FileData[i+1] == 'o' && FileData[i+2] == 'o' && FileData[i+3] == 'p') || (FileData[i] == 'm' && FileData[i+1] == 'o' && FileData[i+2] == 'd' && FileData[i+3] == 'u' && FileData[i+4] == 'l' && FileData[i+5] == 'e') || (FileData[i] == 'm' && FileData[i+1] == 'u' && FileData[i+2] == 't' && FileData[i+3] == 'a' && FileData[i+4] == 't' && FileData[i+5] == 'o' && FileData[i+6] == 'r') || (FileData[i] == 'n' && FileData[i+1] == 'a' && FileData[i+2] == 't' && FileData[i+3] == 'u' && FileData[i+4] == 'r' && FileData[i+5] == 'a' && FileData[i+6] == 'l') || (FileData[i] == 'n' && FileData[i+1] == 'u' && FileData[i+2] == 'l' && FileData[i+3] == 'l') || (FileData[i] == 'o' && FileData[i+1] == 'f') || (FileData[i] == 'o' && FileData[i+1] == 'r') || (FileData[i] == 'o' && FileData[i+1] == 't' && FileData[i+2] == 'h' && FileData[i+3] == 'e' && FileData[i+4] == 'r' && FileData[i+5] == 's') || (FileData[i] == 'o' && FileData[i+1] == 'u' && FileData[i+2] == 't') || (FileData[i] == 'p' && FileData[i+1] == 'o' && FileData[i+2] == 's' && FileData[i+3] == 'i' && FileData[i+4] == 't' && FileData[i+5] == 'i' && FileData[i+6] == 'v' && FileData[i+7] == 'e') || (FileData[i] == 'p' && FileData[i+1] == 'r' && FileData[i+2] == 'o' && FileData[i+3] == 'c' && FileData[i+4] == 'e' && FileData[i+5] == 'd' && FileData[i+6] == 'u' && FileData[i+7] == 'r' && FileData[i+8] == 'e') || (FileData[i] == 'r' && FileData[i+1] == 'e' && FileData[i+2] == 't' && FileData[i+3] == 'u' && FileData[i+4] == 'r' && FileData[i+5] == 'n') || (FileData[i] == 's' && FileData[i+1] == 't' && FileData[i+2] == 'r' && FileData[i+3] == 'u' && FileData[i+4] == 'c' && FileData[i+5] == 't') || (FileData[i] == 's' && FileData[i+1] == 'u' && FileData[i+2] == 'b' && FileData[i+3] == 't' && FileData[i+4] == 'y' && FileData[i+5] == 'p' && FileData[i+6] == 'e') || (FileData[i] == 't' && FileData[i+1] == 'h' && FileData[i+2] == 'e' && FileData[i+3] == 'n') || (FileData[i] == 't' && FileData[i+1] == 'y' && FileData[i+2] == 'p' && FileData[i+3] == 'e') || (FileData[i] == 'w' && FileData[i+1] == 'h' && FileData[i+2] == 'e' && FileData[i+3] == 'n') || (FileData[i] == 'w' && FileData[i+1] == 'h' && FileData[i+2] == 'i' && FileData[i+3] == 'l' && FileData[i+4] == 'e') || (FileData[i] == 'i' && FileData[i+1] == 'n' && FileData[i+2] == ' '))
        {
            keyword(FileData);
        }
        else if(FileData[i] == '\'')
        {
            characterliteral(FileData);
        }
        else if(FileData[i] == 'A' || FileData[i] == 'B' || FileData[i] == 'C' || FileData[i] == 'D' || FileData[i] == 'E' || FileData[i] == 'F' || FileData[i] == 'G' || FileData[i] == 'H' || FileData[i] == 'I' || FileData[i] == 'J' || FileData[i] == 'K' || FileData[i] == 'L' || FileData[i] == 'M' || FileData[i] == 'N' || FileData[i] == 'O' || FileData[i] == 'P' || FileData[i] == 'Q' || FileData[i] == 'R' || FileData[i] == 'S' || FileData[i] == 'T' || FileData[i] == 'U' || FileData[i] == 'V' || FileData[i] == 'W' || FileData[i] == 'X' || FileData[i] == 'Y' || FileData[i] == 'Z' || FileData[i] == 'a' || FileData[i] == 'b' || FileData[i] == 'c' || FileData[i] == 'd' || FileData[i] == 'e' || FileData[i] == 'f' || FileData[i] == 'g' || FileData[i] == 'h' || FileData[i] == 'i' || FileData[i] == 'j' || FileData[i] == 'k' || FileData[i] == 'l' || FileData[i] == 'm' || FileData[i] == 'n' || FileData[i] == 'o' || FileData[i] == 'p' || FileData[i] == 'q' || FileData[i] == 'r' || FileData[i] == 's' || FileData[i] == 't' || FileData[i] == 'u' || FileData[i] == 'v' || FileData[i] == 'w' || FileData[i] == 'x' || FileData[i] == 'y' || FileData[i] == 'z' )
        {
            identifier(FileData);
        }
        else if(FileData[i] == '0' || FileData[i] == '1' || FileData[i] == '2' || FileData[i] == '3' || FileData[i] == '4' || FileData[i] == '5' || FileData[i] == '6' || FileData[i] == '7' || FileData[i] == '8' || FileData[i] == '9')
        {
            numericliteral(FileData);
        }
        else
        {
            unk(FileData);
        }
    }

    return 0;
}

void comment(char FileData[])
{
    for (i; FileData[i] != '\0'; i++)
    {
        printf("%c", FileData[i]);
        if(FileData[i] == '*' && FileData[i+1] == '/')
        {
            break;
        }
    }
    i++;
    printf("%c", FileData[i]);
    printf(" (comment)");
    printf("\n");
}

void identifier(char FileData[])
{
    if(FileData[i-2] == '.')
    {
        printf("%c", FileData[i-1]);
    }
    for(i; FileData[i] == 'A' || FileData[i] == 'B' || FileData[i] == 'C' || FileData[i] == 'D' || FileData[i] == 'E' || FileData[i] == 'F' || FileData[i] == 'G' || FileData[i] == 'H' || FileData[i] == 'I' || FileData[i] == 'J' || FileData[i] == 'K' || FileData[i] == 'L' || FileData[i] == 'M' || FileData[i] == 'N' || FileData[i] == 'O' || FileData[i] == 'P' || FileData[i] == 'Q' || FileData[i] == 'R' || FileData[i] == 'S' || FileData[i] == 'T' || FileData[i] == 'U' || FileData[i] == 'V' || FileData[i] == 'W' || FileData[i] == 'X' || FileData[i] == 'Y' || FileData[i] == 'Z' || FileData[i] == 'a' || FileData[i] == 'b' || FileData[i] == 'c' || FileData[i] == 'd' || FileData[i] == 'e' || FileData[i] == 'f' || FileData[i] == 'g' || FileData[i] == 'h' || FileData[i] == 'i' || FileData[i] == 'j' || FileData[i] == 'k' || FileData[i] == 'l' || FileData[i] == 'm' || FileData[i] == 'n' || FileData[i] == 'o' || FileData[i] == 'p' || FileData[i] == 'q' || FileData[i] == 'r' || FileData[i] == 's' || FileData[i] == 't' || FileData[i] == 'u' || FileData[i] == 'v' || FileData[i] == 'w' || FileData[i] == 'x' || FileData[i] == 'y' || FileData[i] == 'z' || FileData[i] == '0' || FileData[i] == '1' || FileData[i] == '2' || FileData[i] == '3' || FileData[i] == '4' || FileData[i] == '5' || FileData[i] == '6' || FileData[i] == '7' || FileData[i] == '8' || FileData[i] == '9' || FileData[i] == '_'; i++)
    {
        printf("%c", FileData[i]);
    }
    printf(" (identifier)");
    printf("\n");
}

void string(char FileData[])
{
    for(i; FileData[i+1] != '"'; i++)
    {
        printf("%c", FileData[i]);
    }
    printf("%c", FileData[i]);
    i++;
    printf("%c", FileData[i]);
    printf(" (string)");
    printf("\n");
}

void keyword(char FileData[])
{
    for(i; FileData[i] == 'a' || FileData[i] == 'b' || FileData[i] == 'c' || FileData[i] == 'd' || FileData[i] == 'e' || FileData[i] == 'f' || FileData[i] == 'g' || FileData[i] == 'h' || FileData[i] == 'i' || FileData[i] == 'j' || FileData[i] == 'k' || FileData[i] == 'l' || FileData[i] == 'm' || FileData[i] == 'n' || FileData[i] == 'o' || FileData[i] == 'p' || FileData[i] == 'q' || FileData[i] == 'r' || FileData[i] == 's' || FileData[i] == 't' || FileData[i] == 'u' || FileData[i] == 'v' || FileData[i] == 'w' || FileData[i] == 'x' || FileData[i] == 'y' || FileData[i] == 'z'; i++)
    {
        printf("%c", FileData[i]);
    }
    printf(" (keyword)");
    printf("\n");
}

void characterliteral(char FileData[])
{
    for(i; FileData[i+1] != '\''; i++)
    {
        printf("%c", FileData[i]);
    }
    printf("%c", FileData[i]);
    i++;
    printf("%c", FileData[i]);
    printf(" (character literal)");
    printf("\n");
    i++;
}

void operator(char FileData[])
{
    printf("%c", FileData[i]);
    i++;
    if(FileData[i] == '.' || FileData[i] == '<' || FileData[i] == '>' || FileData[i] == '=' || FileData[i] == '*')
    {
        printf("%c", FileData[i]);
    }
    if(FileData[i-1] == ':' || FileData[i-1] == '.' || FileData[i-1] == '<' || FileData[i-1] == '>' || FileData[i-1] == '*' || FileData[i-1] == '!' || FileData[i-1] == '=')
    {
        i++;
        if(FileData[i-2] == '.' && (FileData[i-1] == 'd' || FileData[i-1] == 'h' || FileData[i-1] == 'm' || FileData[i-1] == 's' || FileData[i-1] == 'y'))
        {
            i--;
        }
    }
    printf(" (operator)");
    printf("\n");
}

void numericliteral(char FileData[])
{
    for(i; FileData[i] == '0' || FileData[i] == '1' || FileData[i] == '2' || FileData[i] == '3' || FileData[i] == '4' || FileData[i] == '5' || FileData[i] == '6' || FileData[i] == '7' || FileData[i] == '8' || FileData[i] == '9' || FileData[i] == 'A' || FileData[i] == 'B' || FileData[i] == 'C' || FileData[i] == 'D' || FileData[i] == 'E' || FileData[i] == 'F' || FileData[i] == 'a' || FileData[i] == 'b' || FileData[i] == 'c' || FileData[i] == 'd' || FileData[i] == 'e' || FileData[i] == 'f' || FileData[i] == '-' || FileData[i] == '.' || FileData[i] == '#'; i++)
    {
      printf("%c", FileData[i]);
    }
    printf(" (numeric literal)");
    printf("\n");
}

void unk(char FileData[])
{
    if(FileData[i] == '\n' || FileData[i] == ' ')
    {
        i++;
    }
    else
    {
        if(FileData[i] == '\377')
        {
            exit(0);
        }
        printf("%c", FileData[i]);
        printf(" (unk)");
        printf("\n");
        exit(0);
    }
}

