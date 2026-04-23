#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 100


void zadacha1(){
    int guest;
    printf("Въведете брой гости: ");
    scanf("%d", &guest);

    int chairs = 0;
    int tables = 0; 
    int cups = 0;
    int dishes = 0;  
    int totalsum = 0;  

    char choice[20];
    scanf(" %s", &choice);


    while(strcmp(choice, "PARTY") != 0){
        
        if (strcmp(choice, "CHAIR") == 0){
            chairs++;
            totalsum += 13.99;
            
        }
        else if (strcmp(choice, "TABLE") == 0){
            tables++;
            totalsum += 42;
        }
        else if (strcmp(choice, "CUP") == 0){
            cups++;
            totalsum += 5.99;
        }
        else if (strcmp(choice, "DISH") == 0){
            dishes++;
            totalsum += 21.02;
        }

         scanf(" %s", &choice);

    }

    int need_chairs = guest;
    int needed_tables = ceil(guest / 8.0);
    int needed_sets = ceil(guest / 6.0);

    int more_chairs = need_chairs - chairs;
    int more_tables = needed_tables - tables;
    int more_cups = needed_sets - cups;
    int more_dishes = needed_sets - dishes;


    if (more_tables > 0){
        printf("%d Table\n", more_tables);
    }
    if (more_chairs > 0){
        printf("%d Chairs\n", more_chairs);
    }
    if (more_cups > 0){
        printf("%d Cups\n", more_cups);
    }
    if (more_dishes > 0){       
        printf("%d Dishes\n", more_dishes);
    }

}

typedef struct {
    char name[30];
    int price;
    int id;

} Product;


typedef struct {

    char address[50];
    int id;


} Order;


void zadacha2(){




}





int main(){
    Product product[MAX_PRODUCTS];
    Order order[MAX_PRODUCTS];
    int productCount = 0;
    int orderCount = 0;

    char command[20];

    while(1){
        scanf(" %s", &command);

    
     if (strcmp(command, "EXIT") == 0){
        break;
     }

        if(strcmp(command, "ADD_PRODUCT") == 0){
            Product p;
            scanf(" %s %d %d", p.name, &p.price, &p.id);
            product[productCount++] = p;

            for(int i = 0; i < orderCount; i++){
                if(order[i].id == p.id){
                    printf("Order %s matched with product %s\n", order[i].address, p.name);
                }
                for(int j = i; j <orderCount - 1; j++){
                    order[j] = order[j + 1];
                }
                orderCount--;
                i--;
            }
        }


        else if (strcmp(command, "ADD_ORDER") == 0){
        Order o;
        scanf(" %s %d", o.address, &o.id);
        int found = 0;

        for (int i = 0; i < productCount; i++){
            if(product[i].id == o.id){
                printf("Order %s matched with product %s\n", o.address, product[i].name);
                found = 1;
                break;
            }
        }

        if (!found){
            order[orderCount++] = o;
        }

    }

}


    
return 0;
}