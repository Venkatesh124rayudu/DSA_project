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
};
typedef struct node* Node;
Node first=NULL,last=NULL;

Node createNode(D base){
    Node temp = (Node)malloc(sizeof(struct node));
    temp->info =base;
    temp->next =NULL;
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
    Node N;
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
        N = createNode(temp);
    }
    else{
        int ch;
        printf("Room not availables,\nEnter 1 for trying again\t2 for Skip");
        scanf("%d",&ch);
        if(ch==1){
            Enter_dets();
        }
        N =NULL;
    }

    if (N){
        if(first==NULL){
            first = N;
            last = N;
        }
        else{
            last->next=N;
            last = N;
        }
    }
}
void displayRec(D temp){
    printf("\n%d\t%s\t\t%d\t%d\t%d\t%d\t%d\t%d\n",temp.ID,temp.name,temp.Adults,temp.children,temp.room_type,temp.start_day,temp.end_day,temp.amount);
}
void display(){
    Node temp = first;
    if (temp == NULL){
        printf("Empty\n");
    }
    else{
        printf("Employee records are :-\nRoomID\tName\tAdults\tType\tChildren\tStart\tEnd\tAmount\n");
        while (temp)
        {
            displayRec(temp->info);
            temp=temp->next;
        }
        
    }
}
void addInput(){
    //       ID     Name    Adults  Children    Type    Start   End     Amount
    D L[5]={{001,"Pikachu",0,1,1,1,5,1000},{002,"Charmander",0,2,1,2,5,2000},{003,"Charizard",2,0,2,3,5,5000},{004,"Squirtel",10,0,1,3,10,25000},{011,"Dragonite",1,0,1,1,2,6000}};
    Node P = createNode(L[0]);
    Node N;
    for (int i=0;i<5;i++){
        N = createNode(L[i]);
        last->next=N;
        last = N;
    }
}
struct feedback{
    int Room_ID;
    char Room_Feedback[1000];
    struct feedback *next;
}*feed,*feedback,*temp=NULL,*firs=NULL,*las=NULL;

void comments(){
    //  create a node and enter room id and feedback
    void creatr(){
        temp=(struct feedback*)malloc(sizeof(struct feedback));
        printf("\nEnter the Room_ID\n");
        scanf("%d",temp->Room_ID);
        printf("\nEnter the Feedback\n");
        fflush(stdin);
        fflush(stdin);
        gets(temp->Room_Feedback);
        temp->next=NULL;
    }

    creatr();
    if (firs == NULL){
        firs = temp;
        las = firs;
    }
    else{
        las->next = temp;
        las = temp;
    }

    void display(){
        temp = firs;
        printf("\tRoomID\t\t Comment\n");
        while(temp){
            printf("\n\t%d\t\t  %s\n\n",temp->Room_ID,temp->Room_Feedback);
            temp = temp -> next;
        }
    }

    display();
}











//==============================================================================================================
//                          MAIN FUNTION
//========================================================================================================
void main(){
    int ch=1,choice;
    char pref;
    while(ch){
        printf("Menu\n1.Add guest\t2.Add comment\t3.Display\t4.Add inputs\nEnter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                Enter_dets();
                break;
            case 2:
                printf("Enter the comment you want to add");
                comments();
                break;
            case 3:
                display();
                break;
            case 4:
                addInput();
                break;
        }
    }
}



