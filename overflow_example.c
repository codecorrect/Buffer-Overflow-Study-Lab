#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        int num = atoi(argv[1]);

        if (!(num >= 1 & num <= 3)) {
                printf("Usage: arg1 is number (1-3) for the variable to write to, arg2 is string to write to buffer.\n");
                return 1;
        }

        char buffer_one[8];
        char buffer_two[8];
        char buffer_three[8];

        strcpy(buffer_one, "one");
        strcpy(buffer_two, "two");
        strcpy(buffer_three, "three");

        printf("\n\033[96m[START]\033[0m Creating variables:\n\t    buffer_one at \033[31m%p\033[0m\n\t    buffer_two at \033[31m%p\033[0m\n\t    buffer_three at \033[31m%p\033[0m\n", buffer_one, buffer_two, buffer_three);

        printf("\n\033[96m[BEFORE]\033[0m buffer_one: \033[31m'%s'\033[0m, buffer_two: \033[31m'%s'\033[0m, buffer_three: \033[31m'%s'\033[0m", buffer_one, buffer_two, buffer_three);
        printf("\n\033[96m[STRCPY]\033[0m copying \033[31m%d bytes ('%s')\033[0m into \033[31m", strlen(argv[2]), argv[2]);

        switch ( num ) {
                case 1:
                        printf("buffer_one\033[0m\n");
                        strcpy(buffer_one, argv[2]);
                        break;
                case 2:
                        printf("buffer_two\033[0m\n");
                        strcpy(buffer_two, argv[2]);
                        break;
                case 3:
                        printf("buffer_three\033[0m\n");
                        strcpy(buffer_three, argv[2]);
                        break;
                default:
                        printf("Invalid number. Only 1-3\n");
                        return 1;
        }



        printf("\033[96m[AFTER]\033[0m buffer_one: \033[31m'%s'\033[0m, buffer_two: \033[31m'%s'\033[0m, buffer_three: \033[31m'%s'\033[0m", buffer_one, buffer_two, buffer_three);

        printf("\n\n\033[96m===================================\n");

        //examines every byte of every memory address
        printf("\n\033[96mContents of buffer_one:\033[0m\n");
        for (int i = sizeof(buffer_one)-1; i >= 0; i--) {
                if (buffer_one[i] == '\0') {
                        printf("Address: \033[31m%p\033[0m, Char: '\033[31m\\0\033[0m'\n", &buffer_one[i]);
                } else {
                        printf("Address: \033[31m%p\033[0m, Char: '\033[31m%c\033[0m'\n", &buffer_one[i], buffer_one[i]);
                }
        }


        printf("\n\033[96mContents of buffer_two:\033[0m\n");
        for (int i = sizeof(buffer_two)-1; i >= 0; i--) {
                if (buffer_two[i] == '\0') {
                        printf("Address: \033[31m%p\033[0m, Char: '\033[31m\\0\033[0m'\n", &buffer_two[i]);
                } else {
                        printf("Address: \033[31m%p\033[0m, Char: '\033[31m%c\033[0m'\n", &buffer_two[i], buffer_two[i]);
                }
        }

        printf("\n\033[96mContents of buffer_three:\033[0m\n");
        for (int i = sizeof(buffer_three)-1; i >= 0; i--) {
                if (buffer_three[i] == '\0') {
                        printf("Address: \033[31m%p\033[0m, Char: '\033[31m\\0\033[0m'\n", &buffer_three[i]);
                } else {
                        printf("Address: \033[31m%p\033[0m, Char: '\033[31m%c\033[0m'\n", &buffer_three[i], buffer_three[i]);
                }
        }

        return 0;

}
