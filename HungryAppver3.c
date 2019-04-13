#include "HungryApp.h"
int max(int a,int b){
    return (a > b)? a : b;
}
struct Rest* initRestNode(){
    int j;
    struct Rest* head=(struct Rest*)malloc(sizeof(struct Rest));
    printf("Enter the name of Restaurant\n");
    scanf("%s",head->nameR);
    printf("Enter the address\n");
    scanf("%s",head->addR);
    printf("Enter the category of Restaurant\n");
    scanf("%s",head->category);
    printf("Enter the cuisine\n");
    scanf("%s",head->cuisine);
    printf("Enter the 5 menu items with their prices\n");
    for(j=0;j<5;j++){
        scanf("%s %f ",head->menu[j], &head->price[j]);
    }
    head->heightR=1;
    head->rightR = head->leftR = NULL;
    return head;
}
struct Agent* initAgentNode(){
    struct Agent* head=(struct Agent*)malloc(sizeof(struct Agent));
    printf("Enter the name of the Agent\n");
    scanf("%s",head->nameA);
    printf("Enter the address of the Agent\n");
    scanf("%s",head->Add);
    printf("Enter the agent phone number\n");
    scanf("%s",head->phoneA);
    head->com=0.0;
    agentID++;
    head->IDA=agentID;
    head->ava=1;
    head->heightA=1;
    head->leftA=head->rightA=NULL;
    return head;
}
struct User* initUserNode(){
    struct User* head=(struct User*)malloc(sizeof(struct User));
    printf("Enter the name of the User\n");
    scanf("%s",head->nameU);
    printf("Enter the address of the User\n");
    scanf("%s",head->addU);
    printf("Enter the user phone number\n");
    scanf("%s",head->phoneU);
    userID++;
    head->IDU=userID;
    head->heightU=1;
    head->leftU=head->rightU=NULL;
    return head;
}
//Calculates height
int hR(struct Rest *T)
{
    int lh,rh;
	if(T==NULL)
		return(0);

	if(T->leftR==NULL)
		lh=0;
	else
		lh=1+T->leftR->heightR;

	if(T->rightR==NULL)
		rh=0;
	else
		rh=1+T->rightR->heightR;

	if(lh>rh)
		return(lh);

	return(rh);
}
int hA(struct Agent *T)
{
    int lh,rh;
	if(T==NULL)
		return(0);

	if(T->leftA==NULL)
		lh=0;
	else
		lh=1+T->leftA->heightA;

	if(T->rightA==NULL)
		rh=0;
	else
		rh=1+T->rightA->heightA;

	if(lh>rh)
		return(lh);

	return(rh);
}
int hU(struct User *T)
{
    int lh,rh;
	if(T==NULL)
		return(0);

	if(T->leftU==NULL)
		lh=0;
	else
		lh=1+T->leftU->heightU;

	if(T->rightU==NULL)
		rh=0;
	else
		rh=1+T->rightU->heightU;

	if(lh>rh)
		return(lh);

	return(rh);
}
struct Rest *rightRotateR(struct Rest *x){
    struct Rest *y;
	y=x->leftR;
	x->leftR=y->rightR;
	y->rightR=x;
	x->heightR=hR(x);
	y->heightR=hR(y);
	return(y);
}
struct Agent *rightRotateA(struct Agent *x){
    struct Agent*y;
	y=x->leftA;
	x->leftA=y->rightA;
	y->rightA=x;
	x->heightA=hA(x);
	y->heightA=hA(y);
	return(y);
}
struct User *rightRotateU(struct User *x){
    struct User *y;
	y=x->leftU;
	x->leftU=y->rightU;
	y->rightU=x;
	x->heightU=hU(x);
	y->heightU=hU(y);
	return(y);
}
struct Rest *leftRotateR(struct Rest *x){
    struct Rest *y;
	y=x->rightR;
	x->rightR=y->leftR;
	y->leftR=x;
	x->heightR=hR(x);
	y->heightR=hR(y);

	return(y);
}
struct Agent *leftRotateA(struct Agent *x){
    struct Agent *y;
	y=x->rightA;
	x->rightA=y->leftA;
	y->leftA=x;
	x->heightA=hA(x);
	y->heightA=hA(y);

	return(y);
}
struct User *leftRotateU(struct User *x){
    struct User *y;
	y=x->rightU;
	x->rightU=y->leftU;
	y->leftU=x;
	x->heightU=hU(x);
	y->heightU=hU(y);

	return(y);
}
int getBalanceR(struct Rest *N)
{
	if (N == NULL)
		return 0;
	return hR(N->leftR) - hR(N->rightR);
}
int getBalanceA(struct Agent *N)
{
	if (N == NULL)
		return 0;
	return hA(N->leftA) - hA(N->rightA);
}
int getBalanceU(struct User *N)
{
	if (N == NULL)
		return 0;
	return hU(N->leftU) - hU(N->rightU);
}
struct Rest* initRest(struct Rest* head, struct Rest* node){
    if(head==NULL){
        return node;
    }
    if(strcmp(node->nameR, head->nameR)<0){
        head->leftR=initRest(head->leftR, node);
    }
    else if(strcmp(node->nameR, head->nameR)>0){
        head->rightR=initRest(head->rightR, node);
    }
    else{
        return head;
    }
    head->heightR=1+max(hR(head->leftR), hR(head->rightR));
    int  balance=getBalanceR(head);
    if (balance > 1 && strcmp(node->nameR, head->leftR->nameR)<0)
		return rightRotateR(head);

	// Right Right Case
	if (balance < -1 && strcmp(node->nameR, head->rightR->nameR)>0)
		return leftRotateR(head);

	// Left Right Case
	if (balance > 1 && strcmp(node->nameR, head->leftR->nameR)>0)
	{
		head->leftR = leftRotateR(head->leftR);
		return rightRotateR(head);
	}

	// Right Left Case
	if (balance < -1 && strcmp(node->nameR, head->rightR->nameR)<0)
	{
		head->rightR = rightRotateR(head->rightR);
		return leftRotateR(head);
	}

	/* return the (unchanged) node pointer */
	return head;
}
struct Agent* initAgent(struct Agent* head, struct Agent* node){
    if(head==NULL){
        return node;
    }
    if(strcmp(node->nameA, head->nameA)<0){
        head->leftA=initAgent(head->leftA, node);
    }
    else if(strcmp(node->nameA, head->nameA)>0){
        head->rightA=initAgent(head->rightA, node);
    }
    else{
        return head;
    }
    head->heightA=1+max(hA(head->leftA), hA(head->rightA));
    int  balance=getBalanceA(head);
    if (balance > 1 && strcmp(node->nameA, head->leftA->nameA)<0)
		return rightRotateA(head);

	// Right Right Case
	if (balance < -1 && strcmp(node->nameA, head->rightA->nameA)>0)
		return leftRotateA(head);

	// Left Right Case
	if (balance > 1 && strcmp(node->nameA, head->leftA->nameA)>0)
	{
		head->leftA = leftRotateA(head->leftA);
		return rightRotateA(head);
	}

	// Right Left Case
	if (balance < -1 && strcmp(node->nameA, head->rightA->nameA)<0)
	{
		head->rightA = rightRotateA(head->rightA);
		return leftRotateA(head);
	}

	/* return the (unchanged) node pointer */
	return head;
}
struct User* initUser(struct User* head, struct User* node){
    if(head==NULL){
        return node;
    }
    if(strcmp(node->nameU, head->nameU)<0){
        head->leftU=initUser(head->leftU, node);
    }
    else if(strcmp(node->nameU, head->nameU)>0){
        head->rightU=initUser(head->rightU, node);
    }
    else{
        return head;
    }
    head->heightU=1+max(hU(head->leftU), hU(head->rightU));
    int  balance=getBalanceU(head);
    if (balance > 1 && strcmp(node->nameU, head->leftU->nameU)<0)
		return rightRotateU(head);

	// Right Right Case
	if (balance < -1 && strcmp(node->nameU, head->rightU->nameU)>0)
		return leftRotateU(head);

	// Left Right Case
	if (balance > 1 && strcmp(node->nameU, head->leftU->nameU)>0)
	{
		head->leftU = leftRotateU(head->leftU);
		return rightRotateU(head);
	}

	// Right Left Case
	if (balance < -1 && strcmp(node->nameU, head->rightU->nameU)<0)
	{
		head->rightU = rightRotateU(head->rightU);
		return leftRotateU(head);
	}

	/* return the (unchanged) node pointer */
	return head;
}
void  preOrderR(struct Rest* head, char* str){
    int i;
    if(head!=NULL){
        if(strcmp(head->nameR, str)==0){
            printf("Name: %s\nAddress: %s\nCategory: %s\n", head->nameR, head->addR, head->category);
            printf("Menu items with prices: \n");
            for(i=0;i<5;i++){
                printf(" %s %f\n",head->menu[i], head->price[i]);
            }
        }
        preOrderR(head->leftR, str);
        preOrderR(head->rightR, str);
    }
}
void  preOrderA(struct Agent* head, char* str){
    if(head!=NULL){
        if(strcmp(head->Add, str)==0){
           printf("Name: %s\nAvailability: %d\nID: %d\nCommission: %f\n", head->nameA, head->ava, head->IDA, head->com);
        }
        preOrderA(head->leftA, str);
        preOrderA(head->rightA, str);
    }
}
void basedOnArea(struct Rest* head, char* str){
    if(strcmp(head->addR,str)==0){
        printf("This restaurant has what you need: %s",head->nameR);
        return;
    }
    else if(head->leftR==NULL && head->rightR==NULL){
    }
    else{
        basedOnArea(head->leftR, str);
        basedOnArea(head->rightR, str);
    }
}
void basedOnCategory(struct Rest* head, char* str){
    if(strcmp(head->category,str)==0){
        printf("This restaurant has what you need: %s",head->nameR);
        return;
    }
    else if(head->leftR==NULL && head->rightR==NULL){
    }
    else{
        basedOnCategory(head->leftR, str);
        basedOnCategory(head->rightR, str);
    }
}
void basedOnCuisine(struct Rest* head, char* str){
    int i=0;
    if(strcmp(head->cuisine, str)==0){
        printf("This restaurant has what you need: %s\n",head->nameR);
        return;
    }
    if(head->leftR==NULL && head->rightR==NULL){
    }
    else{
        basedOnCuisine(head->leftR, str);
        basedOnCuisine(head->rightR, str);
    }
}
struct Order* CreateOrderNode(){
    struct Order* Otemp;
    Otemp=(struct Order*)malloc(sizeof(struct Order));
    printf("Enter user name\n");
    scanf("%s",Otemp->name);
    printf("Enter the restaurant name\n");
    scanf("%s",Otemp->rest);
    printf("Enter the item name\n");
    scanf("%s",Otemp->item);
    Otemp->next=NULL;
}
int PriceSet(struct Order* newO, struct Rest* r){
    int i;
    for(i=0;i<5;i++){
        if(strcmp(r->menu[i], newO->item)==0){
            newO->item_cost=r->price[i];
            return 0;
            break;
        }
    }
    return 0;
}
int AgentSet(struct Order* newO, struct Rest* r, struct Agent* a){
    if(strcmp(a->Add, r->addR)==0){
        newO->agentAssg=a->IDA;
        a->ava=0;
        return 0;
    }
    else if(a->leftA==NULL && a->rightA==NULL){
    }
    else{
        AgentSet(newO, r, a->leftA);
        AgentSet(newO, r, a->rightA);
    }
    return 0;
}
void AddressSet(struct Order* newO, struct Rest* r, struct Agent* a){
    if(strcmp(r->nameR, newO->rest)==0){
        PriceSet(newO, r);
        AgentSet(newO, r, a);
    }
    else if(r->leftR==NULL && r->rightR==NULL){
    }
    else{
        AddressSet(newO, r->leftR, a);
        AddressSet(newO, r->rightR, a);
    }
}
void OrderNew(struct Order* newO, struct Rest* r, struct Agent* a){
    AddressSet(newO, r, a);
    order++;
    newO->orderno=order;
    if(o==NULL){
        o=newO;
    }
    else{
        struct Order* temp=o;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newO;
    }
    printf("Order placed\n");
}
void PrintOrders(struct Order* temp){
    if(temp==NULL){
        printf("No order present\n");
    }
    while(temp!=NULL){
        printf("Order number:%d\n",temp->orderno);
        printf("Order for:%s\n",temp->name);
        printf("Restaurant name and item with price:%s %s %f",temp->rest, temp->item, temp->item_cost);
        printf("\n");
        temp=temp->next;
    }
}
void FreeAgent(struct Order* temp, struct Agent* a){
    if(temp->agentAssg==a->IDA){
        a->ava=1;
    }
    else  if(a->leftA==NULL && a->rightA==NULL){
    }
    else{
        FreeAgent(temp, a->leftA);
        FreeAgent(temp, a->rightA);
    }
}
 struct Order* DeleteNode(struct Order **head, int x, struct Agent* a){
    struct Order* prev, *temp= *head;
    prev=head;
    if(temp!=NULL && temp->orderno==x){
        *head=temp->next;
        FreeAgent(temp, a);
        free(temp);
        temp=NULL;
        return *head;
    }
    while(temp!=NULL && temp->orderno!=x){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        return *head;
    }
    prev->next=temp->next;
    free(temp);
    temp=NULL;
    return *head;
 }
 int Commission(struct Order* newO, struct Agent* a, int id){
    if(newO->agentAssg==a->IDA){
        a->com=a->com+0.1*newO->item_cost;
        a->ava=1;
        o=DeleteNode(&o, id, a);
        return 0;
    }
    else if(a->leftA==NULL && a->rightA==NULL){
    }
    else{
        Commission(newO, a->leftA, id);
        Commission(newO, a->rightA, id);
    }
    return 0;
 }
 void Delivery(struct Agent* a){
    int id;
    printf("Enter the order ID\n");
    scanf("%d",&id);
    Commission(o, a, id);
    printf("Order complete\n");
 }
 void Cancel(struct Agent* a){
    int id;
    printf("Enter the order ID\n");
    scanf("%d",&id);
    o=DeleteNode(&o, id, a);
    printf("Order canceled\n");
 }
void main(){
    int x,f=1;
    char s[20];
    printf("Initialize the database\n");
    struct Rest* rest=NULL;
    struct User* user=NULL;
    struct Agent* agent=NULL;
    printf("Initialize restaurants\n");
    while(f==1){
        printf("\n");
        printf("Following are the services we provide:\n");
        printf("Search:\n1. Based on category\n2. Based on cuisine\n3. Based on area\n");
        printf("Initialize:\n4. Add restaurant\n5. Add agent\n6. Add user\n");
        printf("Records:\n7. Print restaurant database\n8. Print agent database\n9. Quit\n10. Print the global order list\n");
        printf("Delivery:\n11. Order food\n12. Delivery Done?\n13. Cancel Order\n");
        scanf("%d",&x);
        switch(x){
            case 1: printf("Enter the category\n");
                    scanf("%s",s);
                    basedOnCategory(rest, s);
                    break;
            case 2: printf("Enter the cuisine\n");
                    scanf("%s",s);
                    basedOnCuisine(rest, s);
                    break;
            case 3: printf("Enter the area\n");
                    scanf("%s",s);
                    basedOnArea(rest, s);
                    break;
            case 4: rest=initRest(rest, initRestNode());
                    break;
            case 5: agent=initAgent(agent, initAgentNode());
                    break;
            case 6: user=initUser(user, initUserNode());
                    break;
            case 7: printf("Enter the restaurant name\n");
                    scanf("%s",s);
                    preOrderR(rest, s);
                    break;
            case 8: printf("Enter the area of agent to search\n");
                    scanf("%s",s);
                    preOrderA(agent, s);
                    break;
            case 9: f=0;
                    break;
            case 11:OrderNew(CreateOrderNode(),rest,agent);
                    break;
            case 10:PrintOrders(o);
                    break;
            case 12:Delivery(agent);
                    break;
            case 13:Cancel(agent);
                    break;
        }
    }
}
