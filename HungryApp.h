#ifndef HUNGRYAPP_H_INCLUDED
#define HUNGRYAPP_H_INCLUDED



#endif // HUNGRYAPP_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int order=0;
int agentID=0;
int userID=0;
struct Rest{            //Data which describes restaurant
    char nameR[20], addR[20], category[20], cuisine[20];
    char menu[5][20];
    float price[5];
    int heightR;
    struct Rest* leftR;
    struct Rest* rightR;
};
struct User{                //Data which describes user
    char nameU[20], addU[20], phoneU[10];
    int IDU;
    int heightU;                 //user will be assigned a user ID for convenience
    struct User* leftU;
    struct User* rightU;
};
struct Agent{           //Data which describes agent
    char nameA[20], phoneA[10], Add[20];
    int IDA;             //agent will be assigned a agent ID for convenience
    int ava;//when  ava = 1 agent is available otherwise busy
    float com;
    int heightA;
    struct Agent* leftA;
    struct Agent* rightA;
};
struct Order{
    char name[20], rest[20], item[20];
    float item_cost;
    int orderno,agentAssg;
    struct Order* next;
};
struct Order* o=NULL;
