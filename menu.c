
/********************************************************************/
/* Copyright (C) SSE-USTC, 2014-2015                                */
/*                                                                  */
/*  FILE NAME             :  menu.c                                 */
/*  PRINCIPAL AUTHOR      :  LiYunpeng                              */
/*  SUBSYSTEM NAME        :  Menu                                   */
/*  MODULE NAME           :  Menu                                   */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2014/09/20                             */
/*  DESCRIPTION           :  interface of Menu                      */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by LiYunpeng,2014/09/20
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"menu.h"

#define CMD_LENGTH 10
#define DESCRIPTION_LENGTH 100

/* create Menu*/
tLinkTable* CreateMenu()
{
    tLinkTable* head = CreateLinkTable();
    return head;
}

/* Add MenuItem to Menu */
int AddMenuItem(tLinkTable* head, char* cmdname, char* cmddesc, int (*function)())
{
    tMenuItem* ptMenuItem = (tMenuItem*) malloc(sizeof(tMenuItem));
    ptMenuItem->cmd = (char*)malloc(sizeof(char)*CMD_LENGTH);
    ptMenuItem->desc = (char*)malloc(sizeof(char)*DESCRIPTION_LENGTH);
    strcpy(ptMenuItem->cmd,cmdname);
    strcpy(ptMenuItem->desc,cmddesc);
    ptMenuItem->handler = function;
    AddLinkTableNode(head,(tLinkTableNode *)ptMenuItem);
    return 0;
}

/* search MenuItem*/
tMenuItem* SearchMenuItem(tLinkTable* head, char* cmd)
{
    tMenuItem* pNode = (tMenuItem*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        if(!strcmp(pNode->cmd, cmd))
        {
            return  pNode;  
        }
        pNode = (tMenuItem*)GetNextLinkTableNode(head, (tLinkTableNode *)pNode);
    }
    return NULL;
}

/* Execute the menu */
int ExecuteMenu(tLinkTable* head)
{
    char cmdname[CMD_LENGTH];
    tMenuItem* ptMenuItem = NULL;
    do
    {
        printf("menu > ");
        scanf("%s",cmdname);
        ptMenuItem = SearchMenuItem(head, cmdname);
        if(ptMenuItem == NULL)
        {
            printf("This is not a command!\n");
            continue;
        }
        printf("%s",ptMenuItem->desc);
        if(ptMenuItem->handler != NULL)
        {
            ptMenuItem->handler();
        }
    }while(strcmp(cmdname, "exit"));
}

/*search preNode */
tMenuItem* SearchPreMenuItem(tLinkTable* head, char* cmd)
{
    tMenuItem* pNode = (tMenuItem*)GetLinkTableHead(head);
    tMenuItem* preNode = NULL;
    while(pNode != NULL)
    {
        if(!strcmp(pNode->cmd, cmd))
        {
            return preNode;
        }
        preNode = pNode;
        pNode = (tMenuItem*)GetNextLinkTableNode(head, (tLinkTableNode *)pNode);
    }
    return NULL;
}

/* show all  command */
int ShowAllMenuItem(tLinkTable* head)
{
    tMenuItem* pNode = (tMenuItem*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tMenuItem*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

/* Delete MenuItem from Menu */
int DeleteMenuItem(tLinkTable * head, char* cmdname)
{
    tMenuItem* p = SearchMenuItem(head, cmdname);
    return DelLinkTableNode(head,(tLinkTableNode *) p);
}
