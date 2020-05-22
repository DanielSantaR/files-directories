#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

    char buffer[10000];
    int simboloLeido;
    FILE *file;
    int lineaActual = 0;

    if (argc != 3)
    {
        printf("Total de argumentos no válidos\n");
        exit(-1);
    }

    if ((file = fopen(argv[2], "r")) == NULL)
    {
        perror("Ocurrió un error al ejecutar fopen");
        exit(-1);
    }

    if ((fseek(file, 0, SEEK_END) == -1) || (fseek(file, -1, SEEK_CUR) == -1))
    {
        printf("Ocurrió un error al ejecutar seek");
        exit(-1);
    }

    char lineas[50];
    strcpy(lineas, argv[1]);
    int idxToDel = 0;
    memmove(&lineas[idxToDel], &lineas[idxToDel + 1], strlen(lineas) - idxToDel);
    int tam = strlen(lineas);
    for (int i = 0; i < tam; i++)
    {
        if (!isdigit(lineas[i]))
        {
            printf("Argumento no válido.\n");
            exit(1);
        }
    }

    int n = atoi(lineas);

    while (1)
    {
        if ((simboloLeido = fgetc(file)) == '\n')
        {
            lineaActual++;
        }
        if (simboloLeido == EOF)
        {
            break;
        }

        if (n <= lineaActual)
        {
            break;
        }

        if (ungetc(simboloLeido, file) == EOF)
        {
            printf("Ocurrió un error al ejecutar ungetc");
            exit(-1);
        }
        fseek(file, -1, SEEK_CUR);
    }

    while (fgets(buffer, 10000, file) != NULL)
    {
        printf("%s", buffer);
    }
    printf("\n");
}