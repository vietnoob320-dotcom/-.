 #include <stdio.h>

int main() {
    char inputFile[100];
    int key;

    printf("Enter file name: ");
    scanf("%s", inputFile);

    printf("Enter key (2-10): ");
    scanf("%d", &key);

    if (key < 2 || key > 10) {
        printf("Invalid key!\n");
        return 1;
    }

    FILE *fin = fopen(inputFile, "r");
    if (!fin) {
        printf("Cannot open input file!\n");
        return 1;
    }

    FILE *fout = fopen("encoded.txt", "w");
    if (!fout) {
        printf("Cannot open output file!\n");
        return 1;
    }

    char ch;

    while ((ch = fgetc(fin)) != EOF) {
        char encoded = ch + key;  
        fputc(encoded, fout);
    }

    fclose(fin);
    fclose(fout);

    printf("File encoded successfully.\n");



    return 0;
}