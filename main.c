#include <stdio.h>

#include "User/UserOperations.h"
#include "Admin/AdminOperations.h"
#include "Shared/SharedFunctions.h"

Users_t  HALZOOM_Users;
Admins_t HALZOOM_Admins;


int main() {

    InitializeBank();
    ReturnState_t RetVal = SuccessfullyDone;
    int Category = 0;


    while (1) {

        int GoBackFlag = 0;

        printf("Welcome to HALZOOM's Bank\n\n");
        printf("Please Choose Your Category\n");
        printf("1. User\n2. Admin\n");

        scanf("%d", &Category);

        while (Category != 1 && Category != 2) {
            scanf("%d", &Category);
        }

        while (1 == Category) { //User

            int UserOperation = 0;
            printf("Choose Your Operation\n\n");
            printf("1. Deposit\n");
            printf("2. Withdraw\n");
            printf("3. Transfer\n");
            printf("4. Transaction History\n");
            printf("5. View Account Data\n");
            printf("6. Exit\n");

            scanf("%d", &UserOperation);

            while(UserOperation > 6 || UserOperation < 1){
                scanf("%d", &UserOperation);
            }

            switch (UserOperation) {
                case 1 : {
                    long long ID = Get_ID("Your");
                    RetVal = Deposit(ID);
                    DealWithRetVal(RetVal);
                    break;
                }
                case 2 : {
                    long long ID = Get_ID("Tour");
                    RetVal = Withdraw(ID);
                    DealWithRetVal(RetVal);
                    break;
                }
                case 3 : {
                    long long Sender_ID = Get_ID("Your");
                    long long Reciver_ID = Get_ID("Reciver");
                    RetVal = Transfer(Sender_ID, Reciver_ID);
                    DealWithRetVal(RetVal);
                    break;
                }
                case 4 : {
                    long long ID = Get_ID("Your");
                    RetVal = TransactionHistory(ID);
                    DealWithRetVal(RetVal);
                    break;
                }
                case 5 : {
                    long long ID = Get_ID("Your");
                    RetVal = ViewDetails(ID);
                    DealWithRetVal(RetVal);
                    break;
                }
                case 6 : {
                    GoBackFlag = 1;
                    break;
                }

            }
            if(GoBackFlag){
                break;
            }

        }
        while (2 == Category) { // Admin

            int AdminOperations = 0;
            printf("Choose Your Operation\n\n");
            printf("1. Create User Account\n");
            printf("2. Create Admin Account\n");
            printf("3. Delete User Account\n");
            printf("4. Delete Admin Account\n");
            printf("5. Change User Account State\n");
            printf("6. Change Admin Account State\n");
            printf("7. Exit\n");

            scanf("%d", &AdminOperations);
            while(AdminOperations > 7 || AdminOperations < 1){
                scanf("%d", &AdminOperations);
            }

            switch (AdminOperations) {
                case 1 : {
                    long long AdminID = Get_ID("Admin");
                    RetVal = CreateUserAccount(AdminID);
                    DealWithRetVal(RetVal);
                    break;
                }
                case 2 : {
                    long long MangerID = Get_ID("Manager");
                    RetVal = CreateAdminAccount(MangerID);
                    DealWithRetVal(RetVal);
                    break;
                }
                case 3 : {
                    long long AdminID = Get_ID("Admin");
                    RetVal = DeleteUserAccount(AdminID);
                    DealWithRetVal(RetVal);
                    break;
                }
                case 4 : {
                    long long MangerID = Get_ID("Manager");
                    RetVal = DeleteAdminAccount(MangerID);
                    DealWithRetVal(RetVal);
                    break;
                }
                case 5 : {
                    State_t State = Get_State();
                    long long AdminID = Get_ID("Admin");
                    RetVal = ChangeUserAccountState(AdminID , State);
                    DealWithRetVal(RetVal);
                    break;
                }
                case 6 : {
                    State_t State = Get_State();
                    long long MangerID = Get_ID("Manager");
                    RetVal = ChangeAdminAccountState(MangerID , State);
                    DealWithRetVal(RetVal);
                    break;
                }
                case 7 : {
                    GoBackFlag = 1;
                    break;
                }
            }
            if(GoBackFlag){
                break;
            }
        }
        printf("/***********************************/\n");
        printf("/**Thanks For Using HALZOOM's Bank**/\n");
        printf("/***********************************/\n\n\n");

    }
    return 0;
}