//
// Created by dell on 5/9/2024.
//


#ifndef ADMINOPERATIONS_H_
#define ADMINOPERATIONS_H_

/**********************************Includes****************************/
#include <stdio.h>
#include <stdlib.h>
#include "../User/UserOperations.h"
#include "../Shared/SharedFunctions.h"

#define MANGER_ID 123456789123

/***********************This struct contains all admin details************************/
typedef struct {
    char Name[50];
    long long ID;
    int Age;
    char Password[20];
    State_t State;
}AdminAccountDetails_t;

/****This struct contains Pointer to the admin details and pointer to the next admin***/
typedef struct ANode{
    AdminAccountDetails_t *Data;
    struct ANode *Next;
}AdminNode_t;

/**This struct contains pointer to the first admin and number of admins in the system**/
typedef struct {
    int Size;
    AdminNode_t *Head;
}Admins_t;


/***************************************************************************************
 * Function Name    : InitializeBank                                                   *
 * Parameters       : None                                                             *
 * Return Type      : void                                                             *
 * Functionality    : Initializes the list of users and admins accounts with a default *
 *                    manager account.                                                 *
 * Time Complexity  : O(1)                                                             *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Allocates memory for the manager account.                                        *
 * 2. Sets the manager account's details: name, state, age, password, and ID.          *
 * 3. Sets the manager account's state to ACTIVE.                                      *
 * 4. Initializes the size of the admin list to 1.                                     *
 * 5. Sets the head of the admin list to the manager account and its next pointer to   *
 *    NULL, as it's the only account initially.                                        *
 ***************************************************************************************/
void InitializeBank();

/***************************************************************************************
 * Function Name    : CreateUserAccount                                                *
 * Parameters       : 1. AdminID => ID of the admin creating the user account          *
 * Return Type      : ReturnState_t                                                    *
 * Functionality    : Creates a new user account if the admin exists and allocates     *
 *                    memory for the account details.                                  *
 * Time Complexity  : O(N) (where N is the number of admins in the system)             *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Allocates memory for the new user account and its details.                       *
 * 2. Checks if memory allocation was successful for the user account and its details. *
 * 3. Searches for the admin with the provided ID or the manager ID.                   *
 * 4. If the admin is found:                                                           *
 *    - Prompts the admin to enter the user's name, age, and password.                 *
 *    - Generates a unique ID for the user.                                            *
 *    - Sets the user's balance to 0 and state to ACTIVE.                              *
 *    - Initializes the user's transaction history.                                    *
 *    - Prints the user's ID.                                                          *
 *    - Adds the user to the list of users.                                            *
 *    - Returns SuccessfullyDone.                                                      *
 * 5. If the admin is not found, returns Couldn_tFindAdminAccount.                     *
 * 6. If memory allocation fails, returns FailedToCreateUserAccount.                   *
 ***************************************************************************************/
ReturnState_t CreateUserAccount(long long AdminID);

/***************************************************************************************
 * Function Name    : CreateAdminAccount                                               *
 * Parameters       : 1. ManagerID => ID of the manager creating the admin account     *
 * Return Type      : ReturnState_t                                                    *
 * Functionality    : Creates a new admin account if the manager ID is correct and     *
 *                    allocates memory for the account details.                        *
 * Time Complexity  : O(1)                                                             *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Allocates memory for the new admin account and its details.                      *
 * 2. Checks if memory allocation was successful for the admin account and its details.*
 * 3. Validates the manager's ID.                                                      *
 * 4. If the manager ID is correct:                                                    *
 *    - Prompts the manager to enter the admin's name, age, and password.              *
 *    - Generates a unique ID for the admin.                                           *
 *    - Sets the admin's state to ACTIVE.                                              *
 *    - Prints the admin's ID.                                                         *
 *    - Adds the admin to the list of admins.                                          *
 *    - Returns SuccessfullyDone.                                                      *
 * 5. If the manager ID is incorrect, returns WrongMangerID.                           *
 * 6. If memory allocation fails, returns FailedToCreateAdminAccount.                  *
 ***************************************************************************************/
ReturnState_t CreateAdminAccount(long long ManagerID);

/***************************************************************************************
 * Function Name    : DeleteUserAccount                                                *
 * Parameters       : 1. AdminID => ID of the admin performing the deletion            *
 * Return Type      : ReturnState_t                                                    *
 * Functionality    : Deletes a user account if the admin exists and the user is found,*
 *                    and deallocates memory associated with the account.              *
 * Time Complexity  : O(N + M) (where N is the number of admins and M is the number    *
 *                    of users in the system).                                         *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Searches for the admin with the provided ID or the manager ID.                   *
 * 2. If the admin is found:                                                           *
 *    - Prompts the admin to enter the ID of the user account to delete.               *
 *    - Searches for the user account with the provided ID.                            *
 *    - If the user account is found:                                                  *
 *      - Deletes the user account by deallocating memory and updating pointers.       *
 *      - Returns SuccessfullyDone.                                                    *
 *    - If the user account is not found, returns Couldn_tFindUserAccount.             *
 * 3. If the admin is not found, returns Couldn_tFindAdminAccount.                     *
 ***************************************************************************************/
ReturnState_t DeleteUserAccount(long long AdminID);

/***************************************************************************************
 * Function Name    : DeleteAdminAccount                                               *
 * Parameters       : 1. MangerID => ID of the manager performing the deletion         *
 * Return Type      : ReturnState_t                                                    *
 * Functionality    : Deletes an admin account if the manager ID is correct and the    *
 *                    admin is found and deallocates memory associated with the account*
 * Time Complexity  : O(N) (where N is the number of admins in the system)             *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Validates the manager's ID.                                                      *
 * 2. If the manager ID is correct:                                                    *
 *    - Prompts the manager to enter the ID of the admin account to delete.            *
 *    - Searches for the admin account with the provided ID.                           *
 *    - If the admin account is found:                                                 *
 *      - Deletes the admin account by deallocating memory and updating pointers.      *
 *      - Returns SuccessfullyDone.                                                    *
 *    - If the admin account is not found, returns Couldn_tFindAdminAccount.           *
 * 3. If the manager ID is incorrect, returns WrongManagerID.                          *
 ***************************************************************************************/
ReturnState_t DeleteAdminAccount(long long MangerID);

/***************************************************************************************
 * Function Name    : ChangeUserAccountState                                           *
 * Parameters       : 1. AdminID => ID of the admin performing the state change        *
 *                    2. State => New state for the user account                       *
 * Return Type      : ReturnState_t                                                    *
 * Functionality    : Changes the state of a user account if the admin exists and the  *
 *                    user is found.                                                   *
 * Time Complexity  : O(N + M) (where N is the number of admins and M is the number    *
 *                    of users in the system).                                         *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Searches for the admin with the provided ID or the manager ID.                   *
 * 2. If the admin is found:                                                           *
 *    - Prompts the admin to enter the ID of the user account whose state needs to be  *
 *      changed.                                                                       *
 *    - Searches for the user account with the provided ID.                            *
 *    - If the user account is found:                                                  *
 *      - Updates the user's state to the new state provided.                          *
 *      - Returns SuccessfullyDone.                                                    *
 *    - If the user account is not found, returns Couldn_tFindUserAccount.             *
 * 3. If the admin is not found, returns Couldn_tFindAdminAccount.                     *
 ***************************************************************************************/
ReturnState_t ChangeUserAccountState(long long AdminID , State_t State);

/***************************************************************************************
 * Function Name    : ChangeAdminAccountState                                          *
 * Parameters       : 1. MangerID => ID of the manager performing the state change     *
 *                    2. State => New state for the admin account                      *
 * Return Type      : ReturnState_t                                                    *
 * Functionality    : Changes the state of an admin account if the manager ID is       *
 *                    correct and the admin is found.                                  *
 * Time Complexity  : O(N) (where N is the number of admins in the system)             *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Validates the manager's ID.                                                      *
 * 2. If the manager ID is correct:                                                    *
 *    - Prompts the manager to enter the ID of the admin account whose state needs to  *
 *      be changed.                                                                    *
 *    - Searches for the admin account with the provided ID.                           *
 *    - If the admin account is found:                                                 *
 *      - Updates the admin's state to the new state provided.                         *
 *      - Returns SuccessfullyDone.                                                    *
 *    - If the admin account is not found, returns Couldn_tFindAdminAccount.           *
 * 3. If the manager ID is incorrect, returns WrongMangerID.                           *
 ***************************************************************************************/
ReturnState_t ChangeAdminAccountState(long long MangerID , State_t State);


#endif //ADMINOPERATIONS_H_
