/*
 * by        : HALZOOM
 * Date      : 5 / 14 / 2024
 * File Name : UserOperations.h
 * */

#ifndef USEROPERATOINS_H_
#define USEROPERATOINS_H_

/**********************************Includes****************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../Shared/SharedFunctions.h"


/********************************This struct date of transaction***********************/
typedef struct{
    double Money;
    char Sign;
    char *Date;
}Date_t;

/*******This struct represent a simple circular queue for dates of transaction*********/
typedef struct {
    int LastDate;
    int FirstDate;
    Date_t DatesForTransactionOperations[10];
}History_t;

/*************************This struct contains all user details************************/
typedef struct {
    char Name[50];
    long long ID;
    int Age;
    double Balance;
    char Password[20];
    State_t State;
    History_t *History;
}UserAccountDetails_t;

/****This struct contains Pointer to the user details and pointer to the next user*****/
typedef struct UNode{
    UserAccountDetails_t *Data;
    struct UNode *Next;
}UserNode_t;

/***This struct contains pointer to the first user and number of users in the system***/
typedef struct {
    int Size;
    UserNode_t *Head;
}Users_t;


/***************************************************************************************
 * Function Name    : Deposit                                                          *
 * Parameters       : 1. UserID     => User's ID                                       *
 * Return Type      : ReturnState_t => State of the function (e.g., "SuccessfullyDone")*
 * Functionality    : Deposits money into the user's account if conditions are met,    *
 *                    updates the user's balance, and records the transaction date.    *
 * Time Complexity  : O(N) (where N is the number of users in the system)              *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Searches for the user with the provided ID.                                      *
 * 2. If the user is found:                                                            *
 *    - Checks if the account is freezed.                                              *
 *    - Prompts the user to enter the amount of money to deposit.                      *
 *    - Verifies the password.                                                         *
 *    - If all conditions are met, updates the user's balance and records the          *
 *      transaction date, then returns SuccessfullyDone.                               *
 *    - If the account is freezed, returns YourFreezedAccount.                         *
 *    - If the password is incorrect, returns WrongPassword.                           *
 * 3. If the user is not found, returns Couldn_tFindYourAccount.                       *
 ***************************************************************************************/
ReturnState_t Deposit(long long UserID);

/***************************************************************************************
 * Function Name    : Withdraw                                                         *
 * Parameters       : 1. UserID     => User's ID                                       *
 * Return Type      : ReturnState_t => State of the function (e.g., "SuccessfullyDone")*
 * Functionality    : Withdraws money from the user's account if conditions are met,   *
 *                    updates the user's balance, and records the transaction date.    *
 * Time Complexity  : O(N) (where N is the number of users in the system)              *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Searches for the user with the provided ID.                                      *
 * 2. If the user is found:                                                            *
 *    - Checks if the account is freezed.                                              *
 *    - Prompts the user to enter the amount of money to withdraw.                     *
 *    - Verifies the password.                                                         *
 *    - If all conditions are met and the balance is sufficient, updates the user's    *
 *      balance, records the transaction date, and returns SuccessfullyDone.           *
 *    - If the account is freezed, returns YourFreezedAccount.                         *
 *    - If the password is incorrect, returns WrongPassword.                           *
 *    - If there's not enough money in the account, returns NoEnoughMoney.             *
 * 3. If the user is not found, returns Couldn_tFindYourAccount.                       *
 ***************************************************************************************/
ReturnState_t Withdraw(long long UserID);

/***************************************************************************************
 * Function Name    : Transfer                                                         *
 * Parameters       : 1. Sender_ID   => ID of the sender                               *
 *                    2. Receiver_ID => ID of the receiver                             *
 * Return Type      : ReturnState_t => State of the function (e.g., "SuccessfullyDone")*
 * Functionality    : Transfers money from the sender's account to the receiver's      *
 *                    account if conditions are met, updates balances, and records     *
 *                    transaction dates.                                               *
 * Time Complexity  : O(N^2) (where N is the number of users in the system)            *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Searches for the sender and receiver in the system.                              *
 * 2. If the sender is found:                                                          *
 *    - Checks if the sender's account is freezed.                                     *
 *    - Searches for the receiver.                                                     *
 *    - If the receiver is found:                                                      *
 *      - Checks if the receiver's account is freezed.                                 *
 *      - Prompts the sender to enter the amount of money to transfer.                 *
 *      - Verifies the sender's password.                                              *
 *      - If all conditions are met and the sender has enough balance, transfers the   *
 *        money from the sender to the receiver, updates balances, records transaction *
 *        dates, and returns SuccessfullyDone.                                         *
 *      - If the sender's account is freezed, returns YourFreezedAccount.              *
 *      - If the password is incorrect, returns WrongPassword.                         *
 *      - If there's not enough money in the sender's account, returns NoEnoughMoney.  *
 *    - If the receiver is not found, returns Couldn_tFindTheReciverAccount.           *
 * 3. If the sender is not found, returns Couldn_tFindYourAccount.                     *
 ***************************************************************************************/
ReturnState_t Transfer(long long Sender_ID , long long Receiver_ID);

/***************************************************************************************
 * Function Name    : TransactionHistory                                               *
 * Parameters       : 1. ID    => User's ID                                            *
 * Return Type      : ReturnState_t                                                    *
 * Functionality    : Displays the transaction history of a user if conditions are met,*
 *                    based on the provided ID.                                        *
 * Time Complexity  : O(N) (where N is the number of users in the system)              *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Searches for the user with the provided ID.                                      *
 * 2. If the user is found:                                                            *
 *    - Verifies the password.                                                         *
 *    - Retrieves the transaction history.                                             *
 *    - Prints the transaction details (date, operation type, amount) for each         *
 *      transaction in the history.                                                    *
 *    - Returns SuccessfullyDone if the password is correct and the history is printed.*
 *    - Returns WrongPassword if the password is incorrect.                            *
 * 3. If the user is not found, returns Couldn_tFindYourAccount.                       *
 ***************************************************************************************/
ReturnState_t TransactionHistory(long long ID);

/***************************************************************************************
 * Function Name    : ViewDetails                                                      *
 * Parameters       : 1. UserID    => User's ID                                        *
 * Return Type      : ReturnState_t                                                    *
 * Functionality    : Displays the details of a user if conditions are met, based on   *
 *                    the provided ID.                                                 *
 * Time Complexity  : O(N) (where N is the number of users in the system)              *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Searches for the user with the provided ID.                                      *
 * 2. If the user is found:                                                            *
 *    - Verifies the password.                                                         *
 *    - Prints the user's name, age, ID, balance, and account state.                   *
 *    - Prints "ACTIVE" if the account state is active, "Freezed" otherwise.           *
 *    - Return SuccessfullyDone if the password is correct and the details are printed.*
 *    - Returns WrongPassword if the password is incorrect.                            *
 * 3. If the user is not found, returns Couldn_tFindYourAccount.                       *
 ***************************************************************************************/

ReturnState_t ViewDetails(long long UserID);

#endif //USEROPERATOINS_H_
