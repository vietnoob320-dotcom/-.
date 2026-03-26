#include <stdio.h>

void zadacha1(){
int n;
scanf("%d",&n);
int a[n];

for(int i = 0; i < n; i++){
scanf("%d", &a[i] );

}

for (int i = 0; i < n-1; i++){
    for(int j = 0; j < n-1-i; j++){
        if (a[j] > a[j+1]){
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;

        }
    }
}

int currlength = 1, maxstart = 0, maxlength = 1, currstart = 0;

for(int i = 1; i <n; i++){
    if (a[i] == a[i-1]){
        currlength++;
    }
    else{
        if(currlength > maxlength){
            maxlength = currlength;
            maxstart = currstart;
        }
        else{
            currstart = i;
            currlength = 1;
        }
    }

}
printf("The start of the length: %d " ,maxstart);
    printf("the length of the longest array: %d",  maxlength);
    

for (int i = 0; i < currlength; i++){
        printf("%d", a[maxlength]);
    }


}


void zadacha2(){
int n;
int flag = 0;
scanf("%d", &n);
int a[n];
for (int i = 0; i < n;i++){
    scanf("%d", &a[i]);
}


for (int i = 1; i < n; i++){
    if (a[i] > a[i-1] && a[i] > a[i+1]){
        flag = 1;
        break;
    }
}

if(!flag){
    printf("Няма релация");
}
else {
    printf("Има релация");
    
}

}

void zadacha3(){
int n;
int flag = 0;
scanf("%d", &n);
int a[n];
int b[n];
for (int i = 0; i < n;i++){
    scanf("%d", &a[i]);
}

int j =0;
for (int i = n -1 ; i >= 0 ;i--){
    printf("%d\n", a[i]);
    b[j] = a[i];
    j++;
}



}

void zadacha4 (){
int n;
scanf("%d", &n);
int k;
k = k % n;
int a[n];
for (int i = 0; i < n;i++){
    scanf("%d", &a[i]);
}

for (int i = 0; i < k; i++){
    int last = a[n-1];
    for(int j = n-1; j > 0; j--){
        a[j] = a[j-1];
    }

a[0] = last;  
}
for(int i = 0 ; i < n; i++){
    printf(" %d", a[i]);


}



}

void zadacha5(){
int n;
scanf("%d",&n);
int k;
scanf("%d", &k);
int a[n];

for(int i = 0; i < n; i++){
scanf("%d", &a[i]);

}

for (int i = 0; i < n-1; i++){
    for(int j = 0; j < n-1-i; j++){
        if (a[j] > a[j+1]){
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;

        }
    }
}


for(int i = 0; i < n; i++){
printf("%d\t", a[i]);
}

printf("%d - тия по големина от масива: %d",k,a[n -k]);

}


void zadacha7(){
int n;
scanf("%d",&n);
int k;
scanf("%d", &k);
int a[n];



for(int i = 0; i < n; i++){
scanf("%d", &a[i]);
}

for (int i = 0; i <n;i++){
    int targetSum = 0;
    for (int j = i; j < n;j++){
        targetSum += a[j];
        if (targetSum == k){
            for (int t = i; t <= j; t++){
                printf("%d ", a[t]);
            }

        }
    }


}

}

void zadacha8(){

    int a[20];
    int count = 10;

for(int i = 0; i < 10; i++){
      scanf("%d", &a[i]);
 }

while (count < 20){
        int value, position;

        scanf("%d", &value);
        if(value == 0){
            break;
        }

        scanf("%d", &position);

        if(position < 0 || position > count){
            continue;
        }

        int i = count;
        while(i > position){
            a[i] = a[i - 1];
            i--;
        }

        a[position] = value;
        count++;
    }

    for(int i = 0; i < count; i++){
        printf("%d ", a[i]);
    }
}






void zadacha9(){
int n;
scanf("%d",&n);
int a[n];

for(int i = 0; i < n; i++){
scanf("%d", &a[i] );

}


int currlength = 1, maxstart = 0, maxlength = 1, currstart = 0;

for(int i = 1; i <n; i++){
    if (a[i] == a[i-1]){
        currlength++;
    }
    else{
        if(currlength > maxlength){
            maxlength = currlength;
            maxstart = currstart;
        }
        else{
            currstart = i;
            currlength = 1;
        }
    }

}
printf("The start of the length: %d" ,maxstart);
    printf("the length of the longest array: %d",  maxlength);
    

for (int i = 0; i < currlength; i++){
        printf("%d", a[maxlength]);
    }
}

void zadacha6(){

int n, arr[100] = {0};
scanf("%d", &n);
 
for(int i = 0 ; i < n; i++){
    scanf(" %d", &arr[i]);
   }
 
int maxLen =1, maxStart = 0;
int currInc = 1, currDec = 1;
int startInc = 0, startDec = 0;
 
for(int i = 0; i < n; i++){
    if(arr[i] > arr[i - 1]){
    currInc++;
    currDec = 1;
    startDec = i;
        }
    else if(arr[i] < arr[i - 1]){
        currDec++;
        currInc = 1;
        startInc = i;
        }
    else{
        currInc = 1;
        currDec = 1;
        startInc = 1;
        startDec = 1;
    }
}
 
if(currInc > maxLen){
    maxLen = currInc;
    maxStart = startInc;
}
if(currDec > maxLen){
    maxLen = currDec;
    maxStart = startDec;
}
 
for(int i = maxStart; i < maxLen; i++){
    printf("%d | ", arr[i]);
}
 







}





int main (){

zadacha8();



}