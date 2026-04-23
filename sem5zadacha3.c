#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 100
#define MAX_WORD 51

int main(){
    FILE *fin = fopen("input.txt", "r");
    FILE *fb = fopen("output.bin", "wb");
    char word[MAX][MAX_WORD];
    int count = 0;
    char word[MAX_WORD];

    char prev_last = 0;
    int first = 1;

    while(fscanf(fin,"%s",word) != EOF){
        if (first || word[0] == prev_last){
            strcpy(word[count++], word);
            prev_last = word[strlen(word) - 1];
            first = 0;
        }
    }

    for (int i = 0; i < count; i++){
        fwrite(word[i], sizeof(char), strlen(word[i]), fb);
    }

    fclose(fin);
    fclose(fb);

    fb = fopen("output.bin", "rb");
    char buffer;
    while(buffer = fgetc(fb) !=  EOF){
        putchar(buffer);
    }
    fclose(fb); 
}