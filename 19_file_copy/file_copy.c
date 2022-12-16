#include <stdio.h>

int main(int argc, char* argv[]) {
    // argument handling
    if (argc != 3) {
        printf("Invalid argument count\n");
        printf("Usage: executable <read_path> <write_path>\n");
        return -1;
    }

    // open read and write files, check for failure
    FILE* pRead = fopen(argv[1], "r");
    if (pRead == NULL) {
        printf("Error: %s could not be accessed.\n", argv[1]);
        return -2;
    }

    FILE* pWrite = fopen(argv[2], "w");
    if (pWrite == NULL) {
        printf("Error: %s could not be accessed.\n", argv[2]);
        return -2;
    }

    // fgets from read file and fputs into write file
    char line_buffer[100];
    while (fgets(line_buffer, 100, pRead)) {
        fputs(line_buffer, pWrite);
    }

    printf("File copied successfully\n");

    fclose(pRead);
    fclose(pWrite);
}