#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

char *convertTime(time_t time);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Ingrese solo la ruta del archivo\n");
        return 1;
    }

    struct stat archivo;

    printf("\n\nDatos del archivo %s\n\n", argv[1]);
    printf("Tamaño: %d bytes\n", archivo.st_size);
    printf("Tamaño de bloque: %d\n", archivo.st_blksize);
    printf("Numero de bloques: %d\n", archivo.st_blocks);
    printf("Nodo-i del archivo: %d\n", archivo.st_ino);
    printf("Número de links: %d\n", archivo.st_nlink);
    printf("ID de usuario: %d\n", archivo.st_uid);
    printf("ID de grupo: %d\n", archivo.st_gid);
    printf("Último acceso al archivo: %s", convertTime(&archivo.st_atime));
    printf("Fecha de última modificación: %s", convertTime(&archivo.st_mtime));
    printf("Fecha de último cambio de estado: %s", convertTime(&archivo.st_ctime));
    printf("Permisos del archivo: ");
    printf("*");
    printf((S_ISDIR(archivo.st_mode)) ? "d" : "");
    printf("*");
    printf((archivo.st_mode & S_IRUSR) ? "r" : "");
    printf("*");
    printf((archivo.st_mode & S_IWUSR) ? "w" : "");
    printf("*");
    printf((archivo.st_mode & S_IXUSR) ? "x" : "");
    printf("*");
    printf((archivo.st_mode & S_IRGRP) ? "r" : "");
    printf("*");
    printf((archivo.st_mode & S_IWGRP) ? "w" : "");
    printf("*");
    printf((archivo.st_mode & S_IXGRP) ? "x" : "");
    printf("*");
    printf((archivo.st_mode & S_IROTH) ? "r" : "");
    printf("*");
    printf((archivo.st_mode & S_IWOTH) ? "w" : "");
    printf("*");
    printf((archivo.st_mode & S_IXOTH) ? "x" : "");
    printf("\n");

    printf("El archivo %s un link simbólico.\n\n\n", (S_ISLNK(archivo.st_mode)) ? "es" : "no es");

    return 0;
}

char *convertTime(time_t time)
{
    char *c_time_string;
    c_time_string = ctime(&time);
    return c_time_string;
}
