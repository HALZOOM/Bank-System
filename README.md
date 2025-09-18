### Bank System

## Overview
The project have to options admin or user and each one has his own operations:
1. Admin :
   - Create User Account.     
   - Create Admin Account.
   - Delete User Account.
   - Delete Admin Account.
   - Change User Account State.
   - Change Admin Account State.

2. User :
   - Deposit.     
   - Withdraw.
   - Transfer.
   - Transaction History.
   - View Details.

#### How It Works
- The project have two separated linked lists one to represent the admins and other
 to represent the users.
- Each node represent either user or admin , that contains pointer to the next
  one and some detials (e.g., name , age , password , ....).
- Each user node have it's own circular queue that represents the date of operations.
- All structs are passed by refrence to save memory.
- There is only one manager in the system can do any thing in admin mode and you can 
  find it's id in the (AdminOperations.h) file. 
- Only manager can do any thing related to admin like (CreateAdminAccount , DeleteAdminAccount).

## Functionality
- Manage user and admin accounts.
- Perform account operations such as deposit and withdrawal.
- View transaction history and account details.
- Ensure security with password authentication.
- Handle various error scenarios.

## Installation
- Install it and make you config file to link files and enjoy.
