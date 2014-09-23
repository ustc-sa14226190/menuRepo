
/********************************************************************/
/* Copyright (C) SSE-USTC, 2014-2015                                */
/*                                                                  */
/*  FILE NAME             :  menu.h                                 */
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

#ifndef _MENU_H_
#define _MENU_H_

#include<stdio.h>
#include<stdlib.h>
#include"linktable.h"

/* Define MenuItem Type */
typedef struct MenuItem
{
    struct  tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)();
}tMenuItem;

/* create menu*/
tLinkTable* CreateMenu();

/* Add MenuItem to Menu */
int AddMenuItem(tLinkTable* head, char* cmdname, char* cmddesc, int (*function)());

/* Delete MenuItem from Menu */
int DeleteMenuItem(tLinkTable* head, char* cmdname);

/* Execute the menu */
int ExecuteMenu(tLinkTable* head);

/* search MenuItem*/
tMenuItem* SearchMenuItem(tLinkTable* head, char* cmd);

/*search preNode */
tMenuItem* SearchPreMenuItem(tLinkTable* head, char* cmd);
/* show all  command */
int ShowAllMenuItem(tLinkTable* head);

#endif /* _MENU_H_ */
