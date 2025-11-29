// Check for the password
#include <stdio.h>
#include <string.h>

int main() {
    char pass[50];
    int ok;

    do {
        ok = 1;
        printf("Enter password: ");
        scanf("%s", pass);

        int len = strlen(pass);
        int up = 0, num = 0, sp = 0;

        for(int i = 0; i < len; i++) {
            // uppercase
            if(pass[i] >= 'A' && pass[i] <= 'Z') up = 1;
            // numbers
            else if(pass[i] >= '0' && pass[i] <= '9') num = 1;
            // special characters
            else if(pass[i] == '@' || pass[i] == '#' || pass[i] == '_') sp = 1;
        }
            // conditional check
        if(len < 8 || !up || !num || !sp)
            ok = 0;

    } while(ok == 0);   

    printf("Strong password accepted!\n");
return 0;
}