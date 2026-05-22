#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2)
        return 0;

    FILE* fp = fopen(argv[1], "r");

    int arr[26] = {0};
    while(!feof(fp)){
        char c;
        fscanf(fp, "%c", &c);
        arr[(int)c - 97] += 1;
    }

    for(int i=0; i<26; i++){
        printf("%c: %d\n",(char)(i+97), arr[i]);
    }

    fclose(fp);
}
