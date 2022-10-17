#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char fristname[100];
    char lastname[100];
    char phonenum[100];
    struct node *next;
};

struct node *root = NULL;

void showMenu(){
    printf("[Phone Book]\n");
    printf("[ 1 ] Add Data\n");
    printf("[ 2 ] Delete Data\n");
    printf("[ 3 ] Display Data\n");
    printf("[ 4 ] Search\n");
    printf("[ 5 ] Exit\n\n");
    printf("Your Choice : ");
}

int getChoice(){
    int choice;
    scanf("%d", &choice);
    printf("\n\n");
    return choice;
}

void addData(){
    struct node *data = (struct node*) malloc(sizeof(struct node));
    printf("FristName : ");
    scanf("%s", &data->fristname);
    printf("LastName :");
    scanf("%s", &data->lastname);
    printf("Phonenumber : ");
    scanf("%s", &data->phonenum);
    
    if(root == NULL){
        data->next = NULL;
    }else{
        data->next = root;
    }
    root = data;
}

void displayData(){
    struct node *ptr = root;
    while(ptr != NULL){
        printf("FristName : %s\n", ptr->fristname);
        printf("LastName : %s\n", ptr->lastname);
        printf("phonenumber : %s\n\n", ptr->phonenum);
        ptr = ptr->next;
    }
    printf("\n");
}

void deleteData(){
    char name[100];
    printf("Name to delete : ");
    scanf("%s", &name);
    
    struct node *ptr = root;
    struct node *last = root;
    
    while(ptr != NULL){
        if(strcmp(ptr->fristname, name)==0){
            break;
            
        }
        last = ptr;
        ptr = ptr->next;
    }
    if(ptr==NULL){
        printf("Data not found\n\n");
        return;
    }else{
        if(ptr==last){
            if(ptr->next==NULL){
                root = NULL;
                free(ptr);
                return;
            }
            root = ptr->next;
            free(ptr);
            return;
        }
        last->next = ptr->next;
        free(ptr);
        return;
    }
}
int SearchData(){
    int a;
    char search[100];
    printf("1 Search with FristName\n");
    printf("2 Search with LastName\n");
    printf("3 Search with phonenumber\n");
    printf("your Choice :");
    scanf("%d",&a );
    if(a==1){
    printf("FristName to Search : ");
    scanf("%s", &search);
    struct node *ptr = root;
    struct node *last = root;
    while(ptr != NULL){
        if(strcmp(ptr->fristname, search)==0){
            printf("FristName : %s\n", ptr->fristname);
            printf("LastName :%s\n", ptr->lastname);
            printf("Phonenumber : %s\n\n", ptr->phonenum);
            break;
        }
        last = ptr;
        ptr = ptr->next;
    }
    }
    else if(a==2){
    printf("LastName to Search : ");
    scanf("%s", &search);
    struct node *ptr = root;
    struct node *last = root;
    while(ptr != NULL){
        if(strcmp(ptr->lastname, search)==0){
            printf("FristName : %s\n", ptr->fristname);
            printf("LastName :%s\n", ptr->lastname);
            printf("Phonenumber : %s\n\n", ptr->phonenum);
            break;
        }
        last = ptr;
        ptr = ptr->next;
    }
    }
    else if(a==3){
    printf("Phonenumber to Search : ");
    scanf("%s", &search);
    struct node *ptr = root;
    struct node *last = root;
    while(ptr != NULL){
        if(strcmp(ptr->phonenum, search)==0){
            printf("FristName : %s\n", ptr->fristname);
            printf("LastName :%s\n", ptr->lastname);
            printf("Phonenumber : %s\n\n", ptr->phonenum);
            break;
        }
        last = ptr;
        ptr = ptr->next;
    }
    }
    else{
        printf("No function\n");
    }
}

int main()
{
   for(;;){
       showMenu();
       int choice = getChoice();
       switch(choice){
            case 1:
                addData();
                break;
            case 2:
                deleteData();
                break;
            case 3:
                displayData();
                break;
            case 4:
                SearchData();
                break;
            case 5:
                return 0;
                
       }
   }
   return 0;
}
