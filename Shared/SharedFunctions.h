/*
 * by        : HALZOOM
 * Date      : 5 / 14 / 2024
 * File Name : SharedFunctions.h
 * */

#ifndef HAREDFUNCTIONS_H
#define HAREDFUNCTIONS_H

/**********************************Includes****************************/
#include <stdio.h>
#include <conio.h>

/*********************************Return Values************************/
typedef enum{
    SuccessfullyDone,
    Couldn_tFindUserAccount,
    Couldn_tFindAdminAccount,
    Couldn_tFindYourAccount,
    Couldn_tFindTheReceiverAccount,
    NoEnoughMoney,
    AdminFreezedAccount,
    UserFreezedAccount,
    YourFreezedAccount,
    ReciverFreezedAccount,
    FailedToCreateUserAccount,
    FailedToCreateAdminAccount,
    NoTransactionYet,
    WrongPassword,
    WrongManagerID
}ReturnState_t;

/*********************************Account States**********************/
typedef enum{
    ACTIVE,
    FREEZED
}State_t;

/***************************************************************************************
 * Function Name    : DealWithRetVal                                                   *
 * Parameters       : 1. RetVal => Return state enum value                             *
 * Return Type      : void                                                             *
 * Functionality    : Deals with different return states and prints corresponding      *
 *                    messages to the console.                                         *
 * Time Complexity  : O(1)                                                             *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Takes a return state value as input and prints a corresponding message to        *
 *    inform the user about the result of an operation.                                *
 * 2. Each return state corresponds to a specific message.                             *
 * 3. Handles various scenarios such as successful operations, failures, account       *
 *    freezing, incorrect passwords, and other specific cases.                         *
 ***************************************************************************************/
void DealWithRetVal(ReturnState_t RetVal);

/***************************************************************************************
 * Function Name    : Get_ID                                                           *
 * Parameters       : 1. Type => Type of ID (e.g., "User" or "Admin" or "Manger")      *
 * Return Type      : long long                                                        *
 * Functionality    : Prompts the user to enter an ID and returns it.                  *
 * Time Complexity  : O(1)                                                             *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Prompts the user to enter an ID for a specific type (e.g., user or admin).       *
 * 2. Reads the input ID from the user.                                                *
 * 3. Returns the entered ID.                                                          *
 ***************************************************************************************/
long long Get_ID(char *Type);

/***************************************************************************************
 * Function Name    : Get_State                                                        *
 * Parameters       : None                                                             *
 * Return Type      : State_t                                                          *
 * Functionality    : Prompts the user to choose the account state and returns it.     *
 * Time Complexity  : O(1)                                                             *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Prompts the user to choose between two account states: Active or Freezed.        *
 * 2. Reads the user's choice.                                                         *
 * 3. Returns the selected account state.                                              *
 * 4. If the user selects Freezed, sets the return value to FREEZED, otherwise sets it *
 *    to ACTIVE.                                                                       *
 ***************************************************************************************/
State_t Get_State();
void clearConsole();

#endif  //SHAREDFUNCTIONS_H
