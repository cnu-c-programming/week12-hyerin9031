#include <stdio.h>

int main(int argc, const char* argv[]){
    if(argc < 3){
        return 0;
    }
    FILE* fp_src = fopen(argv[1], "r");
    FILE* fp_dst = fopen(argv[2], "w");

    if(fp_src == NULL || fp_dst == NULL){
        return 0;
    }

    char buffer[256] = {0};
    while(1){
        fgets(buffer, sizeof(buffer), fp_src);
        if(feof(fp_src)!=0){
            break;
        }
        fputs(buffer, fp_dst);
    }

    fclose(fp_src);
    fclose(fp_dst);

    return 0;
}
