#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

struct items{
    char *item_code;
    char *item_name;
    float item_price;
    int item_quantity;
    struct items* next;
};
struct items *start=NULL;

//GLOBAL VARIABLES
char inventory_name[20];
char item_code[20][20];
char item_name[20][20];
static int a=0;
static int b=0;

void display_menu();
void select_from_menu();
void new_inventory_name();
void display_inventory_menu();
void add_items();
void inventory_function();
void display_items();
void bubbleSort(int);
void swap(struct items*,struct items*);
void continue_menu();
void writeLinkedList(char []);
void readLinkedList(char []);
int remove_items();
int update_items();
void max_price();
void min_price();
void max_quantity();
void min_quantity();
int purchase();

int main()
{
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\tINVENTORY MANAGEMENT SYSTEM\t\t\t\t\t\t\t\t\t");
    printf("\n\n");

    display_menu();

    select_from_menu();

    return 0;
}

void display_menu(){

    printf("\n\t\t\t\t\t\t\t\t 1.\t CREATE A NEW INVENTORY SYSTEM\t\t\t\t\t\t\t\t\n\n");
    printf("\n\t\t\t\t\t\t\t\t 2.\t IMPORT ITEM DETAILS\t\t\t\t\t\t\t\t\n\n");
    printf("\n\t\t\t\t\t\t\t\t 3.\t EXIT\t\t\t\t\t\t\t\t\n\n");

}

void new_inventory_name(){

    printf("\n\n\t\tEnter the Inventory name\t:\t");
    scanf(" %[^\n]s",inventory_name);

}

void select_from_menu(){

    int menu_option;


    printf("\t\tSelect your option\t:\t");
    scanf("%d",&menu_option);

    switch(menu_option){

    case 1:
        new_inventory_name();
        system("cls");
        display_inventory_menu();
        inventory_function();
        break;

    case 2:
        readLinkedList("inventory.txt");
        system("cls");
        display_inventory_menu();
        inventory_function();
        break;
    case 3:
        exit(1);
    default:
        printf("\n\n\n\t\tInvalid choice! Enter correct choice\n\n");

    }
}
void inventory_function(){

        int inventory_option;
        int wrt_price=0;
        int wrt_name=1;
        int x;
        struct items *ptr;
        struct items *temp;

        printf("\n\n\n\t\tSelect your option\t:\t");
        scanf("%d",&inventory_option);

        switch(inventory_option){

        case 1:
            add_items();
            break;
        case 2:
            display_items();
            continue_menu();
            break;
        case 3:
            bubbleSort(wrt_price);
            printf("\n\n\t\tItems are sorted ( w . r . t Item price)\t\t");
            continue_menu();
            break;
        case 4:
            bubbleSort(wrt_name);
            printf("\n\n\t\tItems are sorted ( w . r . t Item name)\t\t");
            continue_menu();
            break;
        case 5:
            writeLinkedList("inventory.txt");
            printf("\n\n\t\tItem details are exported successfully\t\t");
            continue_menu();
            break;
        case 6:
            x=remove_items();
            if(x==0)
                 printf("\n\n\t\tItem is removed\t\t");
            else if(x==-1)
                printf("\n\n\t\tInventor is Empty. Add Items\t\t");
            else
                printf("\n\n\t\tItem not Found\t\t");
            continue_menu();
            break;
        case 7:
            x=update_items();
            if(x==-1)
                printf("\n\n\t\tInventory is Empty. Add Items\t\t");
            if(x==1)
                printf("\n\n\t\tItem not Found\t\t");
            else
                printf("\n\n\t\tItem price and quantity are changed\t\t");
            continue_menu();
            break;
        case 8:
            max_price();
            continue_menu();
            break;
        case 9:
            min_price();
            continue_menu();
            break;
        case 10:
            max_quantity();
            continue_menu();
            break;
        case 11:
            min_quantity();
            continue_menu();
            break;
        case 12:
            x=purchase();
            if(x==0)
                printf("\n\n\t\tItem successfullty purchased\t\t");
            if(x==-1)
                printf("\n\n\t\tInventory is Empty. Add Items\t\t");
            if(x==1)
                printf("\n\n\t\tItem not found\t\t");
            if(x==2)
                printf("\n\n\t\tSorry! The required Item is not available at present\t\t");
            if(x==3)
                printf("\n\n\t\tSorry! Purchase quantity is higher than available stock\t\t");
            continue_menu();
            break;

        case 13:
            ptr=start;
            temp=NULL;
            while(ptr!=NULL){
                temp=ptr->next;
                free(ptr);
                ptr=temp;
            }
            start=NULL;
            exit(1);
        default:
            printf("\n\n\n\t\tInvalid choice! Enter correct choice\n\n");

        }

}

void display_inventory_menu(){

    printf("\n\n\t\t\t\t\t\t\t\t\t\t%s\t\t\t\t\t\t\t\t\t",inventory_name);
    printf("\n\n\t\t\t 1.\t ADD ITEMS");
    printf("\t\t\t\t\t\t\t\t 2.\t DISPLAY ITEMS\n\n");
    printf("\n\n\t\t\t 3.\t SORT ITEMS ( w . r . t Item price)");
    printf("\t\t\t\t\t 4.\t SORT ITEMS ( w . r . t Item name)\n\n");
    printf("\n\n\t\t\t 5.\t BACKUP ITEM DETAILS");
    printf("\t\t\t\t\t\t\t 6.\t REMOVE ITEMS\n\n");
    printf("\n\n\t\t\t 7.\t CHANGE ITEM PRICE AND QUANTITY");
    printf("\t\t\t\t\t\t 8.\t ITEM HAVING HIGHEST PRICE\n\n");
    printf("\n\n\t\t\t 9.\t ITEM HAVING LEAST PRICE");
    printf("\t\t\t\t\t\t 10.\t ITEM WITH HIGHEST NUMBER OF QUANTITIES\n\n");
    printf("\n\n\t\t\t 11.\t ITEM WITH LEAST NUMBER OF QUANTITIES");
    printf("\t\t\t\t\t 12.\t PURCHASE ITEMS\n\n");
    printf("\n\n\t\t\t 13.\t EXIT");
}


void add_items(){


    struct items *ptr;
    char yn;
    do{

        struct items *new_node=(struct items*)malloc(sizeof(struct items));

        printf("\n\n\t\tEnter Item code\t:\t");
        scanf(" %[^\n]s",item_code[a++]);
        new_node->item_code=item_code[a-1];

        printf("\n\t\tEnter Item Name\t:\t");
        scanf(" %[^\n]s",item_name[b++]);
        new_node->item_name=item_name[b-1];

        printf("\n\t\tEnter Item Price\t:\t");
        scanf("%f",&(new_node->item_price));

        printf("\n\t\tEnter Available Item Quantity \t:\t");
        scanf("%d",&(new_node->item_quantity));

        if(start==NULL){
            new_node->next=NULL;
            start=new_node;
        }
        else{
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=NULL;
        }
        printf("\n\n\t\tDo you want to continue? (y / n) \t\t");
        scanf(" %c",&yn);

    }while(yn!='n');
    system("cls");
    display_inventory_menu();
    inventory_function();
}

void display_items(){

    printf("\n\n");
    printf("\t\tItem Code\t\t\tItem Name\t\t\tItem Price\t\t\tItem Quantity\n\n");
    struct items *ptr=start;
    while(ptr!=NULL){
        printf("\t\t%-10s\t\t\t%-10s\t\t\t%-10.2f\t\t\t%-10d\n",ptr->item_code,ptr->item_name,ptr->item_price,ptr->item_quantity);
        ptr=ptr->next;
    }
}

void bubbleSort(int wrt)
{
    int swapped;

    struct items *ptr1;
    struct items *lptr = NULL;
    if (start == NULL)
        return;
    if(wrt==0){
        do
        {
            swapped = 0;
            ptr1 = start;

            while (ptr1->next != lptr)
            {
                if (ptr1->item_price > ptr1->next->item_price)
                {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        }
        while (swapped);
    }
    if(wrt==1){
        do
        {
            swapped = 0;
            ptr1 = start;

            while (ptr1->next != lptr)
            {
                if (*ptr1->item_name > *ptr1->next->item_name)
                {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        }
        while (swapped);
    }

}
void swap(struct items *a, struct items *b)
{
    char* temp_item_code=a->item_code;
    a->item_code=b->item_code;
    b->item_code=temp_item_code;

    char* temp_item_name=a->item_name;
    a->item_name=b->item_name;
    b->item_name=temp_item_name;

    float temp_item_price=a->item_price;
    a->item_price=b->item_price;
    b->item_price=temp_item_price;

    int temp_item_quantity=a->item_quantity;
    a->item_quantity=b->item_quantity;
    b->item_quantity=temp_item_quantity;
}

void continue_menu(){
    printf("\n\n\n\n\t\tEnter any Key to continue \t:\t");
    printf("%c",getch());
    system("cls");
    display_inventory_menu();
    inventory_function();
}

void writeLinkedList(char filename[]){
    struct items* temp=start;

    FILE* file;
    file=fopen(filename, "w");

    for(int i=0;temp!=NULL;i++){
        fprintf(file,"\n%s\t\t\t%s\t\t\t%f\t\t\t%d",(temp->item_code),temp->item_name,temp->item_price,(temp->item_quantity));
        temp=temp->next;
    }

    fclose(file);
}

void readLinkedList(char filename[]){

    FILE *fp;
    fp=fopen(filename,"r");
    float item_price;
    struct items *ptr;
    int item_quantity;
    if(fp!=NULL){
        fseek(fp,0,SEEK_END);
        int len=(int)ftell(fp);

        if(len>0){

            rewind(fp);
            while(fscanf(fp,"\n%s\t\t%s\t\t%f\t\t%d",item_code[a++],item_name[b++],&item_price,&item_quantity)!=EOF){

                if(start==NULL){
                    struct items *p=(struct items *)malloc(sizeof(struct items));
                    p->item_code=item_code[a-1];
                    p->item_name=item_name[b-1];
                    p->item_price=item_price;
                    p->item_quantity=item_quantity;
                    start=p;
                    p->next=NULL;
                }
                else{
                    ptr=start;
                    while(ptr->next!=NULL){
                        ptr=ptr->next;
                    }
                    struct items *p=(struct items *)malloc(sizeof(struct items));
                    p->item_code=item_code[a-1];
                    p->item_name=item_name[b-1];
                    p->item_price=item_price;
                    p->item_quantity=item_quantity;
                    ptr->next=p;
                    p->next=NULL;
                }

            }
        }
    }
}

int remove_items(){
    char remove_item_name[20];int flag=0;
    printf("\n\n\t\tEnter Item name you want to remove \t:\t");
    scanf(" %[^\n]s",remove_item_name);

    if(start==NULL){
        return -1;
    }
    else if(strcmp(start->item_name,remove_item_name)==0){
        struct items* temp=start;
        start=temp->next;
        free(temp);
        temp=NULL;
        return 0;
    }
    else{
        struct items* temp=start;
        struct items* pretemp;
        while(strcmp(temp->item_name,remove_item_name)!=0){
            pretemp=temp;
            temp=temp->next;
            if(temp==NULL){
                flag=1;
                break;
            }
        }
        if(flag==1){
            return 1;
        }
        pretemp->next=temp->next;
        free(temp);
        temp=NULL;
        return 0;
    }
}

int update_items(){
    char update_items[20];int flag=0;
    printf("\n\n\t\tEnter Item name to change price and quantity \t:\t");
    scanf(" %[^\n]s",update_items);

    if(start==NULL){
        return -1;
    }
    else{
        struct items* temp=start;
        while(strcmp(temp->item_name,update_items)!=0){
            temp=temp->next;
            if(temp==NULL){
                flag=1;
                break;
            }
        }
        if(flag==1){
            return 1;
        }
        float new_item_price;int new_item_quantity;
        printf("\n\n\t\tEnter new Item price  \t:\t");
        scanf("%f",&new_item_price);
        temp->item_price=new_item_price;
        printf("\n\n\t\tEnter new Item quantity  \t:\t");
        scanf("%d",&new_item_quantity);
        temp->item_quantity=new_item_quantity;
        return 0;

    }

}

void max_price(){
    struct items *max_price_node;
    float max_price=0.00;
    if(start==NULL){
        printf("\n\n\t\tAdd Items first!\t:\t");
    }
    else{
        struct items *ptr=start;
        while(ptr!=NULL){
            if(ptr->item_price>max_price){
                max_price=ptr->item_price;
                max_price_node=ptr;
            }
            ptr=ptr->next;
        }
        printf("\n\n");
        printf("\t\tItem Code\t\t\tItem Name\t\t\tItem Price\t\t\tItem Quantity\n\n");
        printf("\t\t%-10s\t\t\t%-10s\t\t\t%-10.2f\t\t\t%-10d\n",max_price_node->item_code,max_price_node->item_name,max_price_node->item_price,max_price_node->item_quantity);

    }
}

void min_price(){
    struct items *min_price_node;
    float min_price=340282346638528859811704183484516925440.0000000000000000;
    if(start==NULL){
        printf("\n\n\t\tAdd Items first!\t:\t");
    }
    else{
        struct items *ptr=start;
        while(ptr!=NULL){
            if(ptr->item_price<min_price){
                min_price=ptr->item_price;
                min_price_node=ptr;
            }
            ptr=ptr->next;
        }
        printf("\n\n");
        printf("\t\tItem Code\t\t\tItem Name\t\t\tItem Price\t\t\tItem Quantity\n\n");
        printf("\t\t%-10s\t\t\t%-10s\t\t\t%-10.2f\t\t\t%-10d\n",min_price_node->item_code,min_price_node->item_name,min_price_node->item_price,min_price_node->item_quantity);

    }
}

void max_quantity(){
    struct items *max_quantity_node;
    float max_quantity=0.00;
    if(start==NULL){
        printf("\n\n\t\tAdd Items first!\t:\t");
    }
    else{
        struct items *ptr=start;
        while(ptr!=NULL){
            if(ptr->item_quantity>max_quantity){
                max_quantity=ptr->item_quantity;
                max_quantity_node=ptr;
            }
            ptr=ptr->next;
        }
        printf("\n\n");
        printf("\t\tItem Code\t\t\tItem Name\t\t\tItem Price\t\t\tItem Quantity\n\n");
        printf("\t\t%-10s\t\t\t%-10s\t\t\t%-10.2f\t\t\t%-10d\n",max_quantity_node->item_code,max_quantity_node->item_name,max_quantity_node->item_price,max_quantity_node->item_quantity);

    }
}

void min_quantity(){
    struct items *min_quantity_node;
    float min_quantity=340282346638528859811704183484516925440.0000000000000000;
    if(start==NULL){
        printf("\n\n\t\tAdd Items first!\t:\t");
    }
    else{
        struct items *ptr=start;
        while(ptr!=NULL){
            if(ptr->item_quantity<min_quantity){
                min_quantity=ptr->item_quantity;
                min_quantity_node=ptr;
            }
            ptr=ptr->next;
        }
        printf("\n\n");
        printf("\t\tItem Code\t\t\tItem Name\t\t\tItem Price\t\t\tItem Quantity\n\n");
        printf("\t\t%-10s\t\t\t%-10s\t\t\t%-10.2f\t\t\t%-10d\n",min_quantity_node->item_code,min_quantity_node->item_name,min_quantity_node->item_price,min_quantity_node->item_quantity);

    }
}

int purchase()
{
    char purchase_items[20];int flag=0;
    int purchase_quantity;
    printf("\n\n\t\tEnter Item name to purchase\t:\t");
    scanf(" %[^\n]s",purchase_items);

    if(start==NULL){
        return -1;
    }
    else{
        struct items* temp=start;
        while(strcmp(temp->item_name,purchase_items)!=0){
            temp=temp->next;
            if(temp==NULL){
                flag=1;
                break;
            }
        }
        if(flag==1){
            return 1;
        }

        printf("\n\n\t\tEnter Item quantity to purchase\t:\t");
        scanf("%d",&purchase_quantity);
        if(temp->item_quantity==0){
            return 2;
        }
        if(purchase_quantity>temp->item_quantity)
          return 3;
        else
        {
            int new_item_quantity=temp->item_quantity-purchase_quantity;
            temp->item_quantity=new_item_quantity;
            if(temp->item_quantity<5)
                printf("\n\n\t\tThis product is low on stock.Please update your stock as soon as possible\t");
            return 0;
        }
    }
}

