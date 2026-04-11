#include <stdio.h>
#include <limits.h>

void zadacha1(){
    int n,m;
    
    scanf("%d %d", &n, &m);

    int num[50][50];

    for (int i = 0; i < n; i++){
        for(int j = 0; j < m;j++ ){
            scanf("%d", num[i][j]);

        }
    }
    int isIncreasing = 1;
    int isDecreasing = 1;


    for (int i = 0; i < n; i++){
        for(int j = 0; j < m-1;j++ ){
            if(num[i][j] >= num[i][j+1] ){
                isIncreasing = 0;
            }
        }
    }

        for (int i = 0; i < m-1; i++){
        for(int j = 0; j < n;j++ ){
            if(num[i][j] <= num[i][j+1] ){
                isDecreasing = 0;
            }
        }
    }


    if(isIncreasing){
        printf(" Is increasing in all rows");
    }
    else{
        printf("Not increasing in all rows");
    }
    if(isDecreasing){
        printf("IsDecreasing in all rows ");
    }
    else{
        printf("Not Decreasing in all rows");
    }


}



void zadacha2(){
    int n, m;
    scanf("%d %d", &n, &m);

    int num[50][50];

    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++ ){
            scanf("%d", &num[i][j]);
        }
    }

    int value = num[0][0];
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++){
        for (int j = 0 ; j < m; j++){
            int currentSum = 0;

            for (int k = i - 1; k <= i + 1; k++){
                for (int l = j - 1; l <= j + 1; l++){
                    if (k >= 0 && k < n && l >= 0 && l < m){
                        currentSum += num[k][l];
                    }
                }
            }

            if (currentSum > maxSum){
                value = num[i][j];
                maxSum = currentSum;
            }
        }
    }

    printf("Max sum is %d around num %d\n", maxSum, value);
}




void zadacha3(){
        int n,m;
    
    scanf("%d %d", &n, &m);

    int num[50][50];

    for (int i = 0; i < n; i++){
        for(int j = 0; j < m;j++ ){
            scanf("%d", num[i][j]);

        }
    }

    int minRow = 0; int MinEl = num[0][0];
    int maxRow = 0; int MaxEl = num[0][0];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (num[i][j] < MinEl){
                MinEl = num[i][j];
                minRow = i;
            }
            if (num[i][j] > MaxEl){
                MaxEl = num[i][j];
                maxRow = i;
            }
        }
    }


    for (int j = 0; j < m; j++){
        int temp = num[minRow][j];
        num[minRow][j] = num[maxRow][j];
        num[maxRow][j] = temp;
    }




}


void zadacha4(){
      int n, m;
    scanf("%d %d", &n, &m);

    int friendsCount[n + 1];

    for(int i = 1; i <= n; i++){
        friendsCount[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        friendsCount[a]++;
        friendsCount[b]++;
    }

    int x;
    scanf("%d", &x);

    printf("%d\n", friendsCount[x]);
}



#define MAX 1000

int arr[MAX];
int size = 0;

void add(int x) {
    if (size < MAX) {
        arr[size++] = x;
    }
}

void delete(int x) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != x) {
            arr[j++] = arr[i];
        }
    }
    size = j;
}

void smallest(int x) {
    if (x > size || x <= 0) {
        printf("Invalid\n");
    }

    int temp[MAX];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    printf("%d\n", temp[x - 1]);
}

void zadacha5() {
    add(5);
    add(3);
    add(7);
    add(3);

    smallest(1);
    smallest(2);

    delete(3);

    smallest(1);

}




void zadacha6(){
int n;
scanf("%d", &n);
int *arr1 = (int*)malloc(n * sizeof(int));
int size = 0;
int *arr2 =  (int*)malloc(size * sizeof(int));

int k = 0;

for (int i = 0; i < n; i++){
    scanf("%d", &arr1[i]);
    int simple = 1;
    for(int j = 2; j < arr1[i]; j++){
        if (arr1[i] % j == 0){
            simple = 0;
            break;
        }
    }
    if (simple && arr1[i] > 1){
        size++;
        int *temp = (int*)realloc(arr2, size * sizeof(int));
        temp[k] = arr1[i];
        arr2 = temp;
        k++;
    }
}

for(int i = 0; i < n; i++){
    printf("%d ", arr1[i]);
}

for (int i = 0; i < size; i++){
    printf("%d ", arr2[i]);
}

free(arr1);
free(arr2);
}

void zadacha7(){
  int n,m;
  int arr[50][50];
  scanf("%d %d", &n, &m);
int minSum = 0;
int startRow = 0;
int startCol = 0;

for (int i = 0; i < 3; i++){
    for(int j = 0; j <3;){
        minSum += arr[i][j];
    }
}


for (int i = 0; i < n -3; i++){
    for (int j = 0; j < m - 3; j++){
        int currentSum = 0;
        for (int k = i; k < i + 3; k++){
            for (int l = j; l < j + 3; l++){
                currentSum += arr[k][l];
            }
        }
        if (currentSum < minSum){
            minSum = currentSum;
            startRow = i;
            startCol = j;
        }
    }

 }


 for (int i = startRow; i < startRow + 3; i++){
    for (int j = startCol; j < startCol + 3; j++){
        printf("%d ", arr[i][j]);
    }
    printf("\n");
 }

}

void zadacha8(){
     int size = 10;
    int *arr1 = (int*)malloc(sizeof(int) * size);



    for(int i = 0; i < size; i++){
        scanf("%d", &arr1[i]);
    }

    int val, pos;

    while(scanf("%d", &val) == 1 && val != 0){
        scanf("%d", &pos);


        int *temp = (int*)realloc(arr1, (size + 1) * sizeof(int));



        arr1 = temp;

        for(int i = size; i > pos; i--){
            arr1[i] = arr1[i - 1];
        }

        
        arr1[pos] = val;
        size++;
    }




    for(int i = 0; i < size; i++){
        printf("%d ", arr1[i]);
    }

    free(arr1);
}

  




int main (){






}