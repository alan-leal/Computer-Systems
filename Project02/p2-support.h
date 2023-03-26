///////////////////////////////////////////////
//Add program description, author name, last edit date as in project1
// File          : p2-support.h
// Description   : This file contains declarations and macro definitions to work in
//                 unison with the remaining files  
// Author        : Alan Leal
// Last Modified : November 14 2022
//
#ifndef CMSC257_P2SUPPORT_INCLUDED
#define CMSC257_P2SUPPORT_INCLUDED

#define MAILBOX_SIZE 2000
#define ADDRESS_SIZE 50
#define SUBJECT_SIZE 200
#define BODY_SIZE 2000
#define NAME_SIZE 20
//Replace e@mail.com with your VCU email below
#define user_email "leala2@vcu.edu"
//add other define Macros as needed

struct sent_date
{
  int month;
  int day;
  int year;
};


struct Email
{
  char sender[ADDRESS_SIZE];
  char receiver[ADDRESS_SIZE];
  char subject[SUBJECT_SIZE];
  char body[BODY_SIZE];
  int ID;
  //add other struct members as needed
  //consider adding a nested struct here
  struct sent_date date;
};

struct Mailbox
{
  int size;
  struct Email *emails;
  //add other struct members as needed
};

///////////////////////////////////////////////////////////////////////////////
// This is a sample comment for the initialize function
// You should include a similar comment for each function declared within the 
// 	.h file
//
// Function     : initialize
// Description  : Initializes the database for CMSC257 project #2 by manually 
//                entering the records using create_email function
// Inputs       : struct Mailbox *ib - pointer to the database
// Outputs      : void
void initialize(struct Mailbox *ib);

///////////////////////////////////////////////////////////////////////////////
// Function     : create_email
// Description  : Makes an email that is put into the mailbox database
// Inputs       : char* sender - points to sender,
//                char* receiver - points to receiver,
//                char* subject - points to subject,
//                char* body - points to body,
//                int month - integer value of corresponding month,
//                int day - integer value of corresponding month,
//                int year - integer value of corresponding month,
//                struct Mailbox *ib - pointer to the database
// Outputs      : void

//add other function declarations as needed
void create_email(char* sender, char* receiver, char* subject, char* body, int month, int day, int year, struct Mailbox *ib);

///////////////////////////////////////////////////////////////////////////////
// Function     : display_inbox_menu
// Description  : Creates a menu capable of performing various functions such as: 
//                  1. Show Inbox
//                  2. Show Email by ID
//                  3. Sort Inbox by Sender
//                  4. Sort Inbox by ID
//                  5. Search Inbox by Keyword
//                  6. Delete
//                  7. Exit Inbox
//                  Additionaly, this function displays the user their email address
//                  along with the number of e-mails in their inbox
// Outputs      : void
void display_inbox_menu(struct Mailbox *ib);

#endif // CMSC257_P2SUPPORT_INCLUDED
