#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//---------------------------------------------------------------------------------------------------

// Structure to store the Firewall Rules:

struct FireWallRule{

    int ruleID;
    char sourceIP[16];
    char destinationIP[16];
    int sourcePort;
    int destinationPort;
    char protocol[10];
    char action[10];
    int priority;
    char status[10];
    
};

//--------------------------------------------------------------------------------------------------

// Functions for managing the rules:

  /* 1) ADD RULE */

  void addRule(int count,struct FireWallRule r[]){


            printf("Enter Rule ID :");
            scanf("%d",&r[count].ruleID);

            printf("Enter Source IP :");
            scanf("%s",r[count].sourceIP);

            printf("Enter Destination IP :");
            scanf("%s",r[count].destinationIP);

            printf("Enter Source Port :");
            scanf("%d",&r[count].sourcePort);

            printf("Enter Destination Port :");
            scanf("%d",&r[count].destinationPort);

            printf("Enter Protocol :");
            scanf("%s",r[count].protocol);

            printf("Action (ALLOW / DENY) :");
            scanf("%s",r[count].action);

            printf("Enter Rule Priority :");
            scanf("%d",&r[count].priority);

            printf("Enter Rule Status (ACTIVE / INACTIVE) :");
            scanf("%s",r[count].status);
        
  }

/* 2) DISPLAY ALL FIREWALL RULES : */

void displayRules(int count,struct FireWallRule r[]){

    for(int i=0;i<count;i++){

        printf("<<<<<<< FIREWALL RULE-%d >>>>>>\n\n",(i+1));


         printf("Rule ID :%d\n",r[i].ruleID);


         printf("Source IP :%s\n",r[i].sourceIP);


         printf("Destination IP :%s\n",r[i].destinationIP);
            

         printf("Source Port :%d\n",r[i].sourcePort);
            

         printf("Destination Port :%d\n",r[i].destinationPort);
        

         printf("Protocol :%s\n",r[i].protocol);

         printf("Action :%s\n",r[i].action);
            

         printf("Rule Priority :%d\n",r[i].priority);
        

         printf("Rule Status :%s\n",r[i].status);

         printf("\n");
        }
}

/* DISPLAY SINGLE FIREWALL RULE */

void displayRule(int i,struct FireWallRule r[]){

        printf("\n");

        printf("<<<<<<< FIREWALL RULE >>>>>>\n\n");


         printf("Rule ID :%d\n",r[i].ruleID);


         printf("Source IP :%s\n",r[i].sourceIP);


         printf("Destination IP :%s\n",r[i].destinationIP);
            

         printf("Source Port :%d\n",r[i].sourcePort);
            

         printf("Destination Port :%d\n",r[i].destinationPort);
        

         printf("Protocol :%s\n",r[i].protocol);


         printf("Action :%s\n",r[i].action);
            

         printf("Rule Priority :%d\n",r[i].priority);
        

         printf("Rule Status :%s\n",r[i].status);

         printf("\n");

}

/* 3) SORT FIREWALL RULE */



// a)) Sort by Rule ID (Bubble Sort):

        void ruleIDSORT(int count,struct FireWallRule r[]){

            

            for(int i=0;i<(count-1);i++){

                for(int j=0;j<(count-i-1);j++){

                    if(r[j].ruleID > r[j+1].ruleID){

                        struct FireWallRule temp = r[j];

                        r[j] = r[j+1];

                        r[j+1] = temp;

                    }
                }
            }
        }

// b)) Sort by Priority (Merge Sort):

void prioritySORT(int count, struct FireWallRule r[])
{
    if (count <= 1)
        return;

    int mid = count / 2;

    struct FireWallRule *left = malloc(mid * sizeof(struct FireWallRule));
    struct FireWallRule *right = malloc((count - mid) * sizeof(struct FireWallRule));

    for (int i = 0; i < mid; i++)
        left[i] = r[i];

    for (int i = mid; i < count; i++)
        right[i - mid] = r[i];

    prioritySORT(mid, left);
    prioritySORT(count - mid, right);

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < mid && j < count - mid)
    {
        if (left[i].priority <= right[j].priority)
        {
            r[k] = left[i];
            i++;
        }
        else
        {
            r[k] = right[j];
            j++;
        }

        k++;
    }

    while (i < mid)
    {
        r[k] = left[i];
        i++;
        k++;
    }

    while (j < count - mid)
    {
        r[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}

// c)) Sort by Source Port (Selection Sort):

        void sourcePortSORT(int count,struct FireWallRule r[]){

            struct FireWallRule temp;

            for(int i=0;i<(count-1);i++){

                int pos = i;

                for(int j=i+1;j<count;j++){

                    if(r[pos].sourcePort > r[j].sourcePort){


                        pos = j;

                    }
                }
                temp = r[i];
                r[i] = r[pos];
                r[pos] = temp;
            }
        }

// d)) Sort by Destination Port (Insertion Sort):

        void destinationPortSORT(int count,struct FireWallRule r[]){

             for(int i=1;i<count;i++){

                struct FireWallRule temp = r[i];

                    int j=(i-1);

                    while( j>=0 && temp.destinationPort < r[j].destinationPort){

                        r[j+1] = r[j];
                        j--;
                    }

                    r[j+1] = temp;
                    
                }
             }


/* 4) SEARCH FIREWALL RULE */


/* ====== LINEAR SEARCH ====== */

void sourceIPSearch(int count,struct FireWallRule r[]){

        char sourceip[16];
        int j;
        int found_index=-1;
        printf("Enter the Source IP:");
        scanf("%s",sourceip);
        printf("\n");

        for(j=0;j<count;j++){

                 if(strcmp(r[j].sourceIP,sourceip) == 0){
                 found_index=0;
                 break;
                        }
        }

        if(found_index!=-1){
        displayRule(j,r);}
        else{
                printf("ERROR => RULE NOT FOUND");
                printf("\n");
        }

}

void destinationIPSearch(int count,struct FireWallRule r[]){

        char destinationip[16];
                int k;
                int found_index = -1;
                printf("Enter the Destination IP:");
                scanf("%s",destinationip);
                printf("\n");

                for(k=0;k<count;k++){
                        if(strcmp(r[k].destinationIP,destinationip)==0){
                                found_index = 0;
                                break;
                        }
                }

                if(found_index != -1){
                displayRule(k,r);}
                else{
                        printf("ERROR => RULE NOT FOUND");
                        printf("\n");
                }
                
}

void protocolSearch(int count,struct FireWallRule r[]){
        
                char Protocol[10];
                int l;
                int found_index = -1;
                printf("Enter the protcol:");
                scanf("%s",Protocol);

                for(l=0;l<count;l++){

                        if(strcmp(r[l].protocol,Protocol)==0){
                                found_index = 1;
                                break;

                        }

                }
                if(found_index!=-1){
                displayRule(l,r);}
                else{

                printf("ERROR => RULE NOT FOUND");
                }

}

/* ====== BINARY SEARCH ====== */

int ruleIDSearch(int count,struct FireWallRule r[]){

        

        int ruleid;
        printf("Enter the Rule ID:");
        scanf("%d",&ruleid);

        int low = 0;
        int high = (count - 1);
        
        

        while(low <= high){

                int mid = (low + high)/2;

                if(r[mid].ruleID == ruleid){

                        displayRule(mid,r);
                        return mid;
                
                
                }

                else if(r[mid].ruleID < ruleid){

                        low = mid + 1;
        
                }

                else{
                        high = mid - 1;
                }
        }
}

/* 5) DELETE RULE: */

void deleteRule(int count,int index,struct FireWallRule r[]){

        

        if( index != (count-1)){
                int i = index;
                while(i<(count-1)){

                        r[i] = r[i+1];
                        i++;

                }
        
        } 

}

// ------------------------------------------------------------------------------------------------
int main(){

    int count=0;  //  Increment by 1 for : 1) Add a rule and 2)Update rule <> Decrement by 1 for : 5) Delete Rule 
    int target_index;
    int index ;

    struct FireWallRule *r;

    r = (struct FireWallRule *)calloc(count,sizeof(struct FireWallRule));

    printf("<<<<<<  FIREWALL RULES MANAGER   >>>>>>\n\n");

    int option = 0; // For => Selection of Operation.
    int option1 = 0; // For => Selection of Sorting Method.
    int option2 = 0; // For => Selection of Searching Method.
    

    while(option!=8){

        int target;

        printf("\n");
        printf("<<<<<<< OPERATIONS >>>>>>>\n\n");
        printf("1)Add Firewall Rule\n2)Display Firewall Rules\n3)Sort Rules\n4)Search Rules\n5)Delete Rule\n6)Update Rule\n7)Delete all data\n8)Exit\n");
        scanf("%d",&option);
        printf("\n");

        

        switch(option){

            case 1: // ADD RULE:
                    count++;
                    r = realloc(r, count * sizeof(struct FireWallRule));
                    addRule(count-1,r);
                    break;

            case 2: // DISPLAY ALL FIREWALL RULES:
                    displayRules(count,r);
                    break;

            case 3: // SORTING:

                    printf("====== Sorting Methods ======\n\n");
                    printf("1)Rule ID\n2)Priority\n3)Source Port\n4)Destination Port\n");
                    scanf("%d",&option1);

                    switch(option1){
                                    case 1:
                                            ruleIDSORT(count,r);
                                            break;

                                    case 2:
                                            prioritySORT(count,r);
                                            break;
                                    
                                    case 3:
                                            sourcePortSORT(count,r);
                                            break;
                                    
                                    case 4:
                                            destinationPortSORT(count,r);
                                            break;

                                    default:
                                            printf("INVALID SORTING METHOD SELECTED!");
                    }
                    break;

            case 4: // SEARCHING:
                    
                    printf("<====== SEARCH RULES ======>\n\n");
                    printf("1)Rule ID\n2)Source IP\n3)Destination IP\n4)Protocol\n");
                    scanf("%d",&option2);
                    printf("\n");

                    switch(option2){

                        case 1:
                                ruleIDSORT(count,r);
                                ruleIDSearch(count,r);
                                break;

                        case 2: 
                                sourceIPSearch(count,r);
                                break;

                        case 3:
                                destinationIPSearch(count,r);
                                break;
                        
                        case 4:
                                protocolSearch(count,r);
                                break;
                        default:
                                printf("INVALID SEARCHING METHOD!");
                    }

                    break;

            case 5: // DELETE RULE:

                    ruleIDSORT(count,r);
                    
                    index = ruleIDSearch(count,r); // The index for the rule ID to be deleted.
                    deleteRule(count,index,r);
                    count--;
                    r = realloc(r, count * sizeof(struct FireWallRule));
                    break;

            case 6: // UPDATE RULE:
                    
                    ruleIDSORT(count,r);
                    
                    target_index = ruleIDSearch(count,r);
                    addRule(target_index,r);
                    break;

             case 7: // DELETE ALL DATA:
                    
                        free(r);
                        break;

            case 8:
                    printf("====== EXITING FIREWALL RULE MANAGER ======");
                    
                    break;

            default:
                    printf("INVALID OPTION SELECTED!");

        }

    }
return 0;
}




















