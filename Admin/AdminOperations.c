//
// Created by dell on 5/9/2024.
//

#include "AdminOperations.h"


extern Admins_t HALZOOM_Admins;
extern Users_t HALZOOM_Users;

/***************************************************************************************
 * Function Name    : GenerateID                                                       *
 * Parameters       : None                                                             *
 * Return Type      : long long                                                        *
 * Functionality    : Generates a unique ID for users and admins.                      *
 * Time Complexity  : O(1)                                                             *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Uses the current time as a seed for the random number generator.                 *
 * 2. Generates a random 12-digit ID by appending random digits to ID.                 *
 * 3. Ensures the ID consists of 12-digit.                                             *
 * 4. Returns the generated ID.                                                        *
 * 5. The function is static because it's a file scoop function.                       *
 ***************************************************************************************/
static long long GenerateID();

void InitializeBank(){

    HALZOOM_Users.Size = 0;    //initialize the users list
    HALZOOM_Users.Head = NULL;

    AdminNode_t *MangerAccount = (AdminNode_t *) malloc(sizeof (AdminNode_t)); // create the first node for the manger
    strcpy(MangerAccount->Data->Name , "HALZOOM");
    MangerAccount->Data->State = ACTIVE;
    MangerAccount->Data->Age = 19;
    strcpy(MangerAccount->Data->Password , "halzm") ;
    MangerAccount->Data->ID = MANGER_ID;

    HALZOOM_Admins.Size = 1;    //initialize the users list
    HALZOOM_Admins.Head = MangerAccount;
    HALZOOM_Admins.Head->Next = NULL;

}
/*********************************************************************************************************************/

ReturnState_t CreateUserAccount(long long AdminID){
    AdminNode_t *Temp = HALZOOM_Admins.Head; // state from the first admin
    UserNode_t *UserAccount = (UserNode_t *) malloc(sizeof(UserNode_t));//allocate for the user account
    UserAccount->Data = (UserAccountDetails_t *)malloc(sizeof(UserAccountDetails_t));//allocate for his data
    UserAccount->Data->History = (History_t *)malloc(sizeof(History_t));// allocate for his history

    ReturnState_t RetVal = Couldn_tFindAdminAccount;
    if(!UserAccount || !UserAccount->Data || !UserAccount->Data->History){ // make sure that all allocation done
        free(UserAccount->Data->History);
        free(UserAccount->Data);
        free(UserAccount);
        RetVal = FailedToCreateUserAccount;
    }
    else{
        while(Temp){
            if(Temp->Data->ID == AdminID || AdminID == MANGER_ID){
                if(Temp->Data->State == ACTIVE){
                    printf("Enter User Name :\n");
                    scanf("%s" , &(UserAccount->Data->Name));
                    printf("Enter User Age :\n");

                    scanf("%d" , &(UserAccount->Data->Age));

                    printf("Enter User Password :\n");
                    scanf("%s" , &(UserAccount->Data->Password));

                    UserAccount->Data->Balance = 0;
                    UserAccount->Data->ID = GenerateID();
                    UserAccount->Data->State = ACTIVE;

                    UserAccount->Data->History->FirstDate = 0;
                    UserAccount->Data->History->LastDate = 0;

                    printf("Your ID Number : %lld\n" , UserAccount->Data->ID);

                    UserAccount->Next = HALZOOM_Users.Head;
                    HALZOOM_Users.Head = UserAccount;
                    HALZOOM_Users.Size++;

                    RetVal = SuccessfullyDone;
                }
                else{
                    RetVal = YourFreezedAccount;
                }

                break;
            }
            Temp = Temp->Next;
        }
    }
    return RetVal;
}
/*********************************************************************************************************************/

ReturnState_t CreateAdminAccount(long long ManagerID){
    AdminNode_t *AdminAccount = (AdminNode_t *) malloc(sizeof (AdminNode_t));
    AdminAccount->Data = (AdminAccountDetails_t *) malloc(sizeof (AdminAccountDetails_t));
    ReturnState_t RetVal = SuccessfullyDone;
    if(!AdminAccount || !AdminAccount->Data){
        free(AdminAccount->Data);
        free(AdminAccount);
        RetVal = FailedToCreateAdminAccount;
    }
    else{

        if(ManagerID == MANGER_ID){
            printf("Enter Admin Name :\n");
            scanf("%s" , &(AdminAccount->Data->Name));
            printf("Enter Admin Age :\n");
            scanf("%d" , &(AdminAccount->Data->Age));

            printf("Enter Admin Password :\n");
            scanf("%s" , &(AdminAccount->Data->Password));
            AdminAccount->Data->ID = GenerateID();
            AdminAccount->Data->State = ACTIVE;

            printf("Admin ID Number : %lld\n" , AdminAccount->Data->ID);

            AdminAccount->Next = HALZOOM_Admins.Head;
            HALZOOM_Admins.Head = AdminAccount;
            HALZOOM_Admins.Size++;
        }
        else{
            RetVal = WrongManagerID;
        }

    }
    return  RetVal;
}
/*********************************************************************************************************************/

ReturnState_t DeleteUserAccount(long long AdminID){
    AdminNode_t *TempAdmin = HALZOOM_Admins.Head;
    UserNode_t  *TempUser = HALZOOM_Users.Head;
    UserNode_t  *PreviousNode = NULL;

    ReturnState_t RetVal = Couldn_tFindAdminAccount;

    long long UserID = Get_ID("User");
    while(TempAdmin){
        if(TempAdmin->Data->ID == AdminID || AdminID == MANGER_ID){
            if(TempAdmin->Data->State == ACTIVE){
                RetVal = Couldn_tFindUserAccount;
                while(TempUser){
                    if(UserID == TempUser->Data->ID){
                        if(PreviousNode == NULL){
                            HALZOOM_Users.Head = HALZOOM_Users.Head->Next;
                        }
                        else{
                            PreviousNode->Next = TempUser->Next;
                        }
                        free(TempUser->Data->History);
                        free(TempUser->Data);
                        free(TempUser);
                        RetVal = SuccessfullyDone;
                        HALZOOM_Users.Size--;
                        break;
                    }

                    PreviousNode = TempUser;
                    TempUser = TempUser->Next;
                }
            }
            else{
                RetVal = YourFreezedAccount;
            }

            break;
        }
        TempAdmin = TempAdmin->Next;
    }

    return  RetVal;
}
/*********************************************************************************************************************/

ReturnState_t DeleteAdminAccount(long long ManagerID){
    AdminNode_t *Temp = HALZOOM_Admins.Head;
    AdminNode_t *PreviousNode = NULL;

    ReturnState_t RetVal = Couldn_tFindAdminAccount;

    long long AdminID = Get_ID("Admin");

    if(ManagerID == MANGER_ID){
        while(Temp){
            if(AdminID == Temp->Data->ID){
                if(PreviousNode == NULL){
                    HALZOOM_Admins.Head = HALZOOM_Admins.Head->Next;
                }
                else{
                    PreviousNode->Next = Temp->Next;
                }
                free(Temp->Data);
                free(Temp);
                RetVal = SuccessfullyDone;
                HALZOOM_Admins.Size--;
                break;
            }

            PreviousNode = Temp;
            Temp = Temp->Next;
        }
    }
    else{
        RetVal = WrongManagerID;
    }
    return RetVal;
}
/*********************************************************************************************************************/

ReturnState_t ChangeUserAccountState(long long AdminID,  State_t State){
    AdminNode_t *TempAdmin = HALZOOM_Admins.Head;
    UserNode_t *TempUser = HALZOOM_Users.Head;
    ReturnState_t RetVal = Couldn_tFindAdminAccount;

    long long UserID = Get_ID("User");

    while(TempAdmin){
        if(TempAdmin->Data->ID == AdminID || AdminID == MANGER_ID){
            if(TempAdmin->Data->State == ACTIVE){
                RetVal = Couldn_tFindUserAccount;
                while (TempUser){
                    if(TempUser->Data->ID == UserID){
                        TempUser->Data->State = State;
                        RetVal = SuccessfullyDone;
                        break;
                    }
                    TempUser = TempUser->Next;
                }
            }
            else{
                RetVal = YourFreezedAccount;
            }
            break;
        }
        TempAdmin = TempAdmin->Next;
    }

    return RetVal;
}
/*********************************************************************************************************************/

ReturnState_t ChangeAdminAccountState(long long ManagerID , State_t State){
    AdminNode_t *Temp = HALZOOM_Admins.Head;
    ReturnState_t RetVal = Couldn_tFindAdminAccount;

    long long AdminID = Get_ID("Admin");

    if(ManagerID == MANGER_ID){
        while (Temp){
            if(Temp->Data->ID == AdminID){
                Temp->Data->State = State;
                RetVal = SuccessfullyDone;
                break;
            }
            Temp = Temp->Next;
        }
    }
    else{
        RetVal = WrongManagerID;
    }

    return RetVal;
}
/*********************************************************************************************************************/

static long long GenerateID(){
    long long ID  = 0;
    srand(time(NULL));

    for(int i = 1 ; i <= 12 ; ++i){
        ID = ID * 10 + rand() % 10;
    }

    while(ID <= 99999999999){
        ID = ID * 10 + rand() % 10;
    }

    return  ID;
}
/*********************************************************************************************************************/
