/*
 * by        : HALZOOM
 * Date      : 5 / 14 / 2024
 * File Name : SharedFunctions.c
 * */


#include "SharedFunctions.h"

void DealWithRetVal(ReturnState_t RetVal){
    printf("/*****************************************/\n");
    if(RetVal == SuccessfullyDone){
        printf("Operation Successfully Done\n");
    }
    else if(RetVal == FailedToCreateUserAccount) {
        printf("Failed To Create User Account\n");
    }
    else if(RetVal == FailedToCreateAdminAccount) {
        printf("Failed To Create Admin Account\n");
    }
    else if(RetVal == Couldn_tFindUserAccount){
        printf("Couldn't Find User Account\n");
    }
    else if(RetVal == Couldn_tFindAdminAccount){
        printf("Couldn't Find Admin Account\n");
    }
    else if(RetVal == Couldn_tFindYourAccount){
        printf("Couldn't Find Your Account\n");
    }
    else if(RetVal == Couldn_tFindTheReceiverAccount){
        printf("Couldn't Find The Receiver Account \n");
    }
    else if(RetVal == NoEnoughMoney){
        printf("No Enough Money\n");
    }
    else if(RetVal == AdminFreezedAccount){
        printf("Admin Account Is Freezed\n");
    }
    else if(RetVal == UserFreezedAccount){
        printf("User Account Is Freezed\n");
    }else if(RetVal == YourFreezedAccount){
        printf("Your Account Is Freezed\n");
    }else if(RetVal == ReciverFreezedAccount){
        printf("Reciver Account Is Freezed\n");
    }
    else if(RetVal == NoTransactionYet){
        printf("No Transaction Yet\n");
    }
    else if(RetVal == WrongManagerID){
        printf("Wrong Manager ID\n");
    }
    else if(RetVal == WrongPassword){
        printf("Wrong Password\n");
    }
    else{

    }

}
/*********************************************************************************************************************/

long long Get_ID(char *Type){
    long long ID = 0;
    printf("Please Enter %s ID :\n" , Type);
    scanf("%lld" , &ID);

    return ID;
}
/*********************************************************************************************************************/

State_t Get_State(){
    State_t RetVal = ACTIVE;
    int State = 0;
    printf("Please Choose The Account State :\n");
    printf("1. Active\n2. Freezed\n");
    scanf("%d" , &State);
    if(State - 1 == FREEZED){
        RetVal = FREEZED;
    }
    return RetVal;
}
/*********************************************************************************************************************/


void clearConsole() {
    //system("cls"); // ANSI escape sequence to clear console
}