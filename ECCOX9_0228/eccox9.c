#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 50

void nagybeture(const char *line)
{
    while (*line)
    {
        putchar(toupper(*line));
        line++;
    }
}

int main()
{
    char filename[] = "eccox9.txt";
    char line[MAX_LINE];
    FILE *file;

    file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Hiba a fájl megnyitásakor");
        return 1;
    }

    printf("Add meg a neved és a neptunkódodat. A befejezéshez írjd be: #\n");

    while (1)
    {
        fgets(line, MAX_LINE, stdin);
        if (line[0] == '#' && line[1] == '\n')
            break;
        fputs(line, file);
    }

    fclose(file);

    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Hiba a fájl megnyitásakor");
        return 1;
    }

    printf("\nA fájl tartalma:\n");
    while (fgets(line, MAX_LINE, file) != NULL)
    {
        nagybeture(line);
    }

    fclose(file);
    return 0;
}
