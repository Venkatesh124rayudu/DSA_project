#include<stdio.h>
#include<stdlib.h>
#define MAX_typeA 8     //room code 1

#define MAX_typeB3 15   //room code 2
#define MAX_typeB2 40   //room code 3

#define MAX_typeC2 20   //room code 4
#define MAX_typeC1 60   //room code 5

int curr_A=0;
int curr_B3=0;
int curr_B2=0;
int curr_C2=0;
int curr_C1=0;

int check(int n){
    if (n==1){
        if (curr_A <= MAX_typeA) return 1;
        else return 0;
    }
    else if (n==2){
        if (curr_B3 <= MAX_typeB3) return 1;
        else return 0;
    }
    else if (n==3){
        if (curr_B2 <= MAX_typeB2) return 1;
        else return 0;
    }
    else if (n==4){
        if (curr_C2 <= MAX_typeC2) return 1;
        else return 0;
    }
    else if (n==5){
        if (curr_C1 <= MAX_typeC1) return 1;
        else return 0;
    }
}


//================================================================================================================================================================================================================
//================================================================================================================================================================================================================

//                                                                          LEONADO10000 :
//                                                               ADD GUEST NAME USING PREFFERENCE METHOD

//================================================================================================================================================================================================================
//================================================================================================================================================================================================================


struct details
{
    /* data */
    int ID;
    char name[50];
    int Adults;
    int children;
    int room_type;
    int start_day;
    int end_day;
    int amount;
};
typedef struct details D;

struct node{
    D info;
    struct node* next;
    struct node* prev;
};
typedef struct node* Node;

Node createNode(D base){
    Node temp = (Node)malloc(sizeof(struct node));
    temp->info =base;
    temp->next =NULL;
    temp->prev =NULL;
    return temp;
}

Node Enter_dets(){
    char room_pref,l;
    int beds,i;
    printf("Enter room preference\n1.For type A\t2.For type B\t3.For type C");    
    scanf("%s",&room_pref);
    if(room_pref==1){
        i=check(1);
        l=1;
    }
    else if(room_pref==2){
        printf("Enter the number of rooms(beds) [2,3]");
        scanf("%d",&beds);
        if(beds==2){
            i=check(3);
            l=3;
        }
        else if(beds==3){
           i=check(2);
           l=2;
        }
    }
    else if(room_pref==3){
        printf("Enter the number of rooms(beds) [2,1]");
        scanf("%d",&beds);
        if(beds==1){
            i=check(5);
            l=5;
        }
        else if(beds==2){
            i=check(4);
            l=4;
        }
    }

    if(i){
        D temp;
        printf("Enter room ID");
        scanf("%d",&temp.ID);
        printf("Enter Name");
        scanf("%s",&temp.name);
        printf("Enter No. of adults");
        scanf("%d",&temp.Adults);
        printf("Enter No. of Children");
        scanf("%d",&temp.children);
        printf("Enter start day");
        scanf("%d",&temp.start_day);
        printf("Enter end day");
        scanf("%d",&temp.end_day);
        printf("Enter amount");
        scanf("%d",&temp.amount);
        temp.room_type = l;

        Node N = createNode(temp);
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d",temp.ID,temp.name,temp.Adults,temp.children,temp.start_day,temp.end_day,temp.amount);


    }
    else{
        int ch;
        printf("Room not availables,\nEnter 1 for trying again\t2 for Skip");
        scanf("%d",&ch);
        if(ch==1){
            Enter_dets();
        }
    }
}












//==============================================================================================================
//                          MAIN FUNTION
//========================================================================================================
void main(){
    int ch=1,choice;
    char pref;
    while(ch){
        printf("Menu\n1.Add guest\t2.Add comment\nEnter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                Enter_dets();
                break;
            case 2:
                printf("Enter the comment you want to add");
                break;
        }
    }
}



