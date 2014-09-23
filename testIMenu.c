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
/*  DESCRIPTION           :  Tests of menu interface                */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by LiYunpeng,2014/09/20
 *
 */
#include "menu.h"

int Help();
int Execute();

tLinkTable * menu = NULL;

int main()
{
    menu = CreateMenu();
    AddMenuItem(menu, "version","This is version 1.0!\n", NULL);
    AddMenuItem(menu, "exit","Exit menu execution!\n", NULL);
    AddMenuItem(menu, "help", "This is help command!\n",Help);
    AddMenuItem(menu, "execute", "This is Execute function!\n",Execute);
    printf("Execute the first time :\n");
    ExecuteMenu(menu);
    printf("Execute after delete 'execute command':\n");
    DeleteMenuItem(menu,"execute");
    ExecuteMenu(menu);
    return 0;
}

int Help()
{
    ShowAllMenuItem(menu);
    return 0;
}

int Execute()
{
    ExecuteMenu(menu);
}
