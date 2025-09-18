/*
 * by        : HALZOOM
 * Date      : 5 / 14 / 2024
 * File Name : UserOperations.c
 * */

#include "UserOperations.h"

extern Users_t HALZOOM_Users;

/***************************************************************************************
 * Function Name    : StoreDate                                                        *
 * Parameters       : 1. Temp  => Pointer to UserNode_t  (User Account)                *
 *                    2. src   => String or Pointer to String That Stores Date         *
 *                    3. Sign  => '+' or '-' Show what operation the user had done     *
 *                    4. Money => The Amount Of Money                                  *
 * Return Type      : void                                                             *
 * Functionality    : Stores the date of operation in the user's transaction history,  *
 *                    along with the sign (indicating deposit or withdrawal) and the   *
 *                    amount of money involved.                                        *
 * Time Complexity  : O(1)                                                             *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Stores the transaction details (date, sign, money) in the user's transaction     *
 *    history array.                                                                   *
 * 2. Updates the LastDate index of the transaction history array.                     *
 * 3. This is a simple implementation of circular queue of size 10                     *
 * 4. If the LastDate index exceeds the array size, wraps around to the beginning of   *
 *    the array.                                                                       *
 * 5. If the LastDate index overlaps with the FirstDate index, updates the FirstDate   *
 *    index to prevent overwriting older transactions.                                 *
 * 6. The function is static because it's a file scoop function.                       *
 ***************************************************************************************/
static void StoreDate(UserNode_t *Temp , char *src , char Sign , double Money);

/***************************************************************************************
 * Function Name    : GetDateInStringForm                                              *
 * Parameters       : None                                                             *
 * Return Type      : char*  => Pointer to string that represents the time             *
 * Functionality    : Retrieves the current date and time in string format.            *
 * Time Complexity  : O(1)                                                             *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Retrieves the current date and time using the time function.                     *
 * 2. Formats the date and time as a string using ctime.                               *
 * 3. Returns the string representation of the current date and time.                  *
 * 4. The function is static because it's a file scoop function.                       *
 * 5. For more information about time.h library and date function visit : 			   *
      https://www.codedrome.com/dates-and-times-in-c/             					   *
 ***************************************************************************************/
static char *GetDateInStringForm();

/***************************************************************************************
 * Function Name    : Is_PasswordCorrect                                               *
 * Parameters       : 1. Password => User's password                                   *
 * Return Type      : int                                                              *
 * Functionality    : Checks if the entered password matches the user's password.      *
 * Time Complexity  : O(N) (where N is the length of the password)                     *
 * Space Complexity : O(1)                                                             *
 *                                                                                     *
 * Hints About Function :                                                              *
 * 1. Prompts the user to enter their password.                                        *
 * 2. Compares each character of the entered password with the user's password.        *
 * 3. Returns 1 if the entered password matches the user's password, otherwise         *
 *    returns 0.                                                                       *
 * 4. The function is static because it's a file scoop function.                       *
 ***************************************************************************************/
static int Is_PasswordCorrect(char *Password);




ReturnState_t Deposit(long long UserID){
    UserNode_t *Temp = HALZOOM_Users.Head; // start from the first node
    ReturnState_t RetVal = Couldn_tFindYourAccount;
    while (Temp){ // search for teh user
        if(Temp->Data->ID == UserID){ // check teh id
            if(Temp->Data->State == FREEZED){
                RetVal = YourFreezedAccount;
            }
            else if(Is_PasswordCorrect(Temp->Data->Password)){
                double Money = 0;
                printf("Please Enter The Amount Of Money :\n");
                scanf("%lf" , &Money);

                char *Date = GetDateInStringForm(); //Get the date in string form
                StoreDate(Temp , Date , '+' , Money); // store the date and operation


                Temp->Data->Balance += Money;
                RetVal = SuccessfullyDone;
            }
            else{
                RetVal = WrongPassword;
            }

            break;
        }
        Temp = Temp->Next;
    }

    return RetVal;
}
/*********************************************************************************************************************/

ReturnState_t Withdraw(long long UserID){
    UserNode_t *Temp = HALZOOM_Users.Head;
    ReturnState_t RetVal = Couldn_tFindYourAccount;
    while (Temp){
        if(Temp->Data->ID == UserID){
            if(Temp->Data->State == FREEZED){
                RetVal = YourFreezedAccount;
            }
            else if(Is_PasswordCorrect(Temp->Data->Password)){
                double Money;
                printf("Please Enter The Amount OF Money :\n");
                scanf("%lf" , &Money);

                if(Temp->Data->Balance >= Money){

                    char *Date = GetDateInStringForm();
                    StoreDate(Temp , Date , '-' , Money);

                    Temp->Data->Balance -= Money;
                    RetVal = SuccessfullyDone;
                }
                else{
                    RetVal = NoEnoughMoney;
                }
            }
            else{
                RetVal = WrongPassword;
            }

            break;
        }
        Temp = Temp->Next;
    }

    return  RetVal;
}
/*********************************************************************************************************************/

ReturnState_t Transfer(long long Sender_ID , long long Receiver_ID){
    UserNode_t *Sender = HALZOOM_Users.Head;
    UserNode_t *Reciver = HALZOOM_Users.Head;
    ReturnState_t RetVal = Couldn_tFindYourAccount;
    while (Sender){
        if(Sender->Data->ID == Sender_ID){
            if(Sender->Data->State == FREEZED){
                RetVal = YourFreezedAccount;
            }
            else{
                while(Reciver){
                    if(Reciver->Data->ID == Receiver_ID ){
                        if(Reciver->Data->State == FREEZED){
                            RetVal = ReciverFreezedAccount;
                        }
                        else if(Is_PasswordCorrect(Sender->Data->Password)){
                            double Money;
                            printf("Please Enter The Amount OF Money :\n");
                            scanf("%lf" , &Money);

                            if(Sender->Data->Balance >= Money) {
                                char *Date = GetDateInStringForm();
                                StoreDate(Reciver , Date , '+' , Money);
                                StoreDate(Sender , Date , '-' , Money);

                                Reciver->Data->Balance += Money;
                                Sender->Data->Balance -= Money;
                                RetVal = SuccessfullyDone;
                            }
                            else{
                                RetVal = NoEnoughMoney;
                            }
                        }
                        else{
                            RetVal = WrongPassword;
                        }

                        break;
                    }
                    RetVal = Couldn_tFindTheReceiverAccount;
                    Reciver = Reciver->Next;
                }
                break;
            }

        }
        Sender = Sender->Next;
    }

    return  RetVal;
}
/*********************************************************************************************************************/

ReturnState_t TransactionHistory(long long ID){

    int IteratorOne = 0;
    int IteratorTwo = 0;
    int NumberOfTransaction = 0;
    UserNode_t *Temp = HALZOOM_Users.Head;
    ReturnState_t RetVal = Couldn_tFindYourAccount;

    while (Temp){
        if(Temp->Data->ID == ID){
            if(Is_PasswordCorrect(Temp->Data->Password)){
                IteratorOne = Temp->Data->History->FirstDate;
                IteratorTwo = Temp->Data->History->LastDate;

                NumberOfTransaction = IteratorOne > IteratorTwo ? (9 - IteratorOne) + IteratorTwo : IteratorTwo - IteratorOne;
                for(int i = 0 ; i < NumberOfTransaction ; ++i){
                    printf("%s %c%0.3lf\n" , Temp->Data->History->DatesForTransactionOperations[IteratorOne].Date ,
                                                 Temp->Data->History->DatesForTransactionOperations[IteratorOne].Sign ,
                                                 Temp->Data->History->DatesForTransactionOperations[IteratorOne].Money);
                    IteratorOne++;
                    IteratorOne %= 10;
                }
                RetVal = SuccessfullyDone;
            }
            else{
                RetVal = WrongPassword;
            }
            break;
        }
        Temp = Temp->Next;
    }

    return RetVal;
}
/*********************************************************************************************************************/

ReturnState_t ViewDetails(long long UserID){
    UserNode_t *Temp = HALZOOM_Users.Head;
    ReturnState_t RetVal = Couldn_tFindYourAccount;
    while (Temp){
        if(Temp->Data->ID == UserID){

            if(Is_PasswordCorrect(Temp->Data->Password)){
                printf("Name     : %s\n" ,   Temp->Data->Name);
                printf("Age      : %d\n" ,   Temp->Data->Age);
                printf("ID       : %lld\n" , Temp->Data->ID);
                printf("Balance  : %0.3lf\n" ,  Temp->Data->Balance);

                printf("State    : ");
                if(Temp->Data->State == ACTIVE){ // Colors Works only in console
                    //printf("\033[0;32m"); // Set text color to Green
                    printf("ACTIVE\n");
                    //printf("\033[0m"); // Reset text color to default
                }
                else{
                    //printf("\033[0;31m"); // Set text color to red
                    printf("Freezed\n");
                    //printf("\033[0m"); // Reset text color to default
                }

                RetVal = SuccessfullyDone;
            }
            else{
                RetVal = WrongPassword;
            }

            break;
        }
        Temp = Temp->Next;
    }
    return RetVal;
}
/*********************************************************************************************************************/

static void StoreDate(UserNode_t *Temp ,char *src , char Sign , double Money){

    Temp->Data->History->DatesForTransactionOperations[Temp->Data->History->LastDate].Date = src;
    Temp->Data->History->DatesForTransactionOperations[Temp->Data->History->LastDate].Sign = Sign;
    Temp->Data->History->DatesForTransactionOperations[Temp->Data->History->LastDate].Money = Money;

    Temp->Data->History->LastDate++;
    Temp->Data->History->LastDate %= 10;
    if(Temp->Data->History->LastDate == Temp->Data->History->FirstDate){
        Temp->Data->History->FirstDate++;
        Temp->Data->History->FirstDate %= 10;
    }
}
/*********************************************************************************************************************/

static char *GetDateInStringForm(){

    time_t t = time(NULL);

    char *Time = ctime(&t);

    return Time;
}
/*********************************************************************************************************************/

static int Is_PasswordCorrect(char *Password){
    char Pass[20];
    printf("Please Enter Your Password :");
    scanf("%s" , &Pass);

    int idx = 0;
    while(Password[idx]){
        if(Pass[idx] != Password[idx]){
            return 0;
        }
        idx++;
    }
    return  1;
}
/*********************************************************************************************************************/
