#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]){
    if(argc < 3){
        return 0;
    }
    FILE* fp = fopen(argv[1], "r");
    const char* target_str = argv[2];

    if(fp==NULL){
        return 0;
    }

    char buffer[1024]={0};
    while(1){
        if(fgets(buffer, sizeof(buffer), fp) == NULL){
            break;
        }

        if(buffer[strlen(buffer) - 1] == '\n'){
            buffer[strlen(buffer) - 1] = '\0';
        }
        
        char st[1024];
        strcpy(st, buffer);
        char* c = strtok(buffer, " ,.");

        while(c != NULL){
            if(strcmp(c, target_str) == 0){
                printf("%s\n", st);
            }
            c = strtok(NULL, " ,.");
        }
    }

    fclose(fp);
}
