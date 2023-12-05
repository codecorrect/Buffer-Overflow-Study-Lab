#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_authentication(char *password) {
        int auth_flag = 0;
        char password_buffer[16];

        strcpy(password_buffer, password);

        if(strcmp(password_buffer, "P@ssw0rd") == 0)
                auth_flag = 1;

        //print variables
        printf("\n\033[96mContents of auth_flag:\033[0m\n");
        unsigned char *bytePointer = (unsigned char *)&auth_flag;
        for (int i = sizeof(auth_flag)-1; i >= 0; i-- ) {
                if (bytePointer[i] == '\0') {
                        printf("Address: \033[31m%p\033[0m, Char: '\033[31m\\0\033[0m'\n", &bytePointer[i]);
                } else {
                        printf("Address: \033[31m%p\033[0m, Char: '\033[31m%c\033[0m'\n", &bytePointer[i], bytePointer[i]);
                }
        }

        printf("\n\033[96mContents of password_buffer:\033[0m\n");
        for (int i = sizeof(password_buffer)-1; i >= 0; i--) {
                if (password_buffer[i] == '\0') {
                        printf("Address: \033[31m%p\033[0m, Char: '\033[31m\\0\033[0m'\n", &password_buffer[i]);
                } else {
                        printf("Address: \033[31m%p\033[0m, Char: '\033[31m%c\033[0m'\n", &password_buffer[i], password_buffer[i]);
                }
        }






        return auth_flag;
}

int main(int argc, char *argv[]) {
        if (argc < 2) {
                printf("Usage: %s <password>\n", argv[0]);
                exit(0);
        }

        if (check_authentication(argv[1])) {
                printf("\n========================\n");
                printf("     Access Granted     \n");
                printf("========================\n");
        } else {
                printf("\n\033[31m========================\n");
                printf("     Access Denied     \n");
                printf("========================\033[0m\n");
        }
}
                                                                                                                                                                                                                                            
