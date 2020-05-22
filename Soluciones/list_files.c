
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    if (argc > 3)
    {
        printf("Total de argumentos no válidos\n");
        return 1;
    }

    DIR *path;
    struct dirent *miArchivo;
    struct stat stat;

    if (argc == 1)
    {
        path = opendir(".");
        while ((miArchivo = readdir(path)) != NULL)
        {
            printf("%s\t", miArchivo->d_name);
        }
        printf("\n");
        closedir(path);
        return 0;
    }

    if (argc == 2 && strcmp(argv[1], "-l") != 0)
    {
        path = opendir(argv[1]);
        while ((miArchivo = readdir(path)) != NULL)
        {
            printf("%s\n", miArchivo->d_name);
        }
        printf("\n");
        closedir(path);
        return 0;
    }

    if (argc == 2 && strcmp(argv[1], "-l") == 0)
    {

        path = opendir(".");
        char buf[512];

        while ((miArchivo = readdir(path)) != NULL)
        {
            sprintf(buf, "%s/%s", argv[1], miArchivo->d_name);
            char archivo[100];
            strcpy(archivo, "./stat.out ");
            strcat(archivo, miArchivo->d_name);
            int status = system(&archivo);
        }
        printf("\n");
        closedir(path);
        return 0;
    }

    if (argc == 3 && strcmp(argv[1], "-l") == 0)
    {
        path = opendir(argv[2]);
        char buf[512];

        while ((miArchivo = readdir(path)) != NULL)
        {
            sprintf(buf, "%s/%s", argv[1], miArchivo->d_name);
            char archivo[100];
            strcpy(archivo, "./stat.out ");
            strcat(archivo, argv[2]);
            strcat(archivo, "/");
            strcat(archivo, miArchivo->d_name);
            int status = system(&archivo);
        }
        closedir(path);
        return 0;
    }
}