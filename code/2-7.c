#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config{
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
}Config;

void config_parser(Config* config_ptr){
    FILE* fp = fopen("config.txt", "r");
    if(fp == NULL){
        return;
    }

    char buffer[256] = {0};
    while(1){
        if(fgets(buffer, sizeof(buffer), fp) == NULL){
            break;
        }
        if(buffer[strlen(buffer) - 1] == '\n'){
            buffer[strlen(buffer) - 1] = '\0';
        }
        char* c = strtok(buffer, "=");
        if(!strcmp("InputFileName", c)){
            strcpy(config_ptr->InputFileName, strtok(NULL, "="));
        }
        else if(!strcmp("Options", c)){
            config_ptr->Options =atoi(strtok(NULL, "="));
        }
        else if(!strcmp("SectionName", c)){
            strcpy(config_ptr->SectionName, strtok(NULL, "="));
        }
        else{
            config_ptr->Address = strtoull(strtok(NULL, "="), NULL, 16);
        }
    }
}

int main(int argc, const char* argv[]){
    Config config;
    config_parser(&config);

    printf("config: %s %d %s %llu\n", config.InputFileName, config.Options, config.SectionName, config.Address);
    return 0;
}

