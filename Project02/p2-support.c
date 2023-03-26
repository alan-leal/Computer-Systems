///////////////////////////////////////////////
//Add program description, author name, last edit date as in project1
// File          : p2-support.c
// Description   : This project is based on creating a menu driven email client. 
//                 Included functionality: inbox display, email display, finding emails by
//                 utilizing keyword search, inbox sorting by sender, inbox sorting by
//                 ID, and lastly, email deletion via email ID.
// Author        : Alan Leal
// Last Modified : November 14 2022
//



//Add necessary include statements (I added for you!)
#include "p2-support.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////
// Function Definitions
// //////////////////////////////////////////

void initialize(struct Mailbox *ib)
{
  //allocate memory for 2000 emails
  ib->emails = malloc(sizeof(struct Email) * MAILBOX_SIZE);
  ib->size = 0;

  create_email("asonmez@mail.com", user_email, "Welcome to your inbox.",
    "Welcome to your inbox, just wanted to say hi. Here's hoping you get all your code done.",
    11, 20, 2020, ib);
  create_email("mmartinez@mail.com", user_email, "Padding out your inbox.",
    "Yet another email just to pad out your inbox, have fun!",
    11, 30, 2020, ib);
  create_email("dboyle@mail.com", user_email, "3rd email!",
    "Alright, time for another email for your inbox. Not going too lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!",
    12, 2, 2020, ib);
  create_email("cbluer@mail.com", user_email, "4th email!",
    "Content of fourth email. More coding, more fun!",
    12, 8, 2020, ib);
  create_email("cboyle@mail.com", user_email, "5th email!",
    "Content of fifth email. Coding is fun-tastic!",
    12, 18, 2020, ib);
  create_email("sblack@mail.com", user_email, "6th email!",
    "Content of sixth email. Coding is fun-tastic!",
    1, 1, 2021, ib);
  create_email("sblack@mail.com", user_email, "7th email!",
    "Body of seventh email. Coding is fun-tastic!",
    1, 5, 2021, ib);
  create_email("sblack@mail.com", user_email, "8th email!",
    "Body of eighth email. Coding is fun-tastic!",
    2, 15, 2021, ib);
  create_email("sblack@mail.com", user_email, "9th email!",
    "Body of ninth email. Coding is fun-tastic!",
    2, 25, 2021, ib);
  create_email("dboyle@mail.com", user_email, "Last email!",
    "Body of tenth email. Coding is fun-tastic!",
    3, 15, 2021, ib);
}

void display_inbox_menu(struct Mailbox *ib)
{
  int s;
  while(1)
  {
    printf("\n*************** %s INBOX  ***************\n", user_email);
    printf("***************   Total Inbox: %04d   ***************\n", ib->size);
    printf("\n1. Show Inbox\n");
    printf  ("2. Show Email by ID\n");
    printf  ("3. Sort Inbox by Sender\n");
    printf  ("4. Sort Inbox by ID\n");
    printf  ("5. Search Inbox by Keyword\n");
    printf  ("6. Delete\n");
    printf  ("7. Exit Inbox\n\n");

    if(scanf("%d",&s) <= 0)
    {
      printf("Enter only an Integer\n");
      exit(0);
    } else {
      printf("\n");
      switch (s)
      {
      // 1. Show Inbox
      case 1:
        printf("ID   SENDER--------------   MM/DD/YYYY   SUBJECT--------\n");
        printf("--   --------------------   --/--/----   ---------------\n");

        int i;
        for(i = 0; i < ib->size; i++)
        {
          char subject_message[SUBJECT_SIZE] = "";
          strncpy(subject_message, ib->emails[i].subject, 15);
          printf("%02d - %-20s - %02d/%02d/%02d - %-15s\n", 
                 ib->emails[i].ID, 
                 ib->emails[i].sender, 
                 ib->emails[i].date.month, 
                 ib->emails[i].date.day,
                 ib->emails[i].date.year,
                 subject_message);
        }
        printf("\n");
        break;

      // 2. Show Email by ID
      case 2:
        printf("Enter the ID of the email you want to read:\n");
        int ID_num;
        if(scanf("%d",&ID_num) < 0)
        {
          printf("Enter only an Integer\n");
          exit(0);
        } else {
          char subject_message[SUBJECT_SIZE] = "";
          strncpy(subject_message, ib->emails[ID_num].subject, 24);
          //c
          printf("\n%s - %s\n", ib->emails[ID_num].sender, ib->emails[ID_num].subject);
          printf("Email Received on: %02d/%02d/%02d\n", ib->emails[ID_num].date.month, ib->emails[ID_num].date.day, ib->emails[ID_num].date.year);
          printf("\n%s\n\n\n", ib->emails[ID_num].body);
        }
        break;

      // 3. Sort Inbox by Sender
      case 3:
        printf("");
        int x;
        int y;
        int count = ib->size;
        for (x = 0; x < count; x++)
        {
          for (y = x + 1; y < count; y++)
          {
            int result = strcmp(ib->emails[x].sender, ib->emails[y].sender);
            if(result > 0)
            {
              struct Email temp = ib->emails[x];
              ib->emails[x] = ib->emails[y];
              ib->emails[y] = temp;
            }
          }

        }
        break;

      // 4. Sort Inbox by ID
      case 4:
        printf("");
        int x2;
        int y2;
        int count1 = ib->size;
        for (x2 = 0; x2 < count1; x2++)
        {
          for (y2 = x2 + 1; y2 < count1; y2++)
          {
            if(ib->emails[y2].ID < ib->emails[x2].ID)
            {
              struct Email temp = ib->emails[y2];
              ib->emails[y2] = ib->emails[x2];
              ib->emails[x2] = temp;
            }
          }

        } 
        break;

      // 5. Search Inbox by Keyword
      case 5:
        printf("Enter the keyword you are searching for:\n");
        char word[10];
        scanf("%s",word);
        int k;
        int count2 = ib->size;
        printf("\nID   SENDER--------------   MM/DD/YYYY   SUBJECT--------\n");
        printf("--   --------------------   --/--/----   ---------------\n");
        for (k = 0; k < count2; k++)
        {
          if(strstr(ib->emails[k].sender, word) != NULL || strstr(ib->emails[k].subject, word) != NULL || strstr(ib->emails[k].body, word) != NULL) 
          {
          printf("%02d - %-20s - %02d/%02d/%02d - %s\n", 
              ib->emails[k].ID, 
              ib->emails[k].sender, 
              ib->emails[k].date.month, 
              ib->emails[k].date.day,
              ib->emails[k].date.year,
              ib->emails[k].subject);
          }
        }
        break;

      // 6. Delete
      case 6:
        printf("Enter the ID of the e-mail you want to delete:\n");
        int ID_delete;
        if(scanf("%d",&ID_delete) < 0)
        {
          printf("Enter only an Integer\n");
          exit(0);
      } else 
        {
          int f;
          int g;
          int count3 = ib->size;
          for(f = 0; f < count3; f++)
          {
            if(ib->emails[f].ID == ID_delete)
            {
              for(g = f; g < count3 - 1; g++)
              {
                ib->emails[g] = ib->emails[g + 1];
              }
            }
          }
        ib->size--;
        printf("Email with ID = %d is deleted\n\n", ID_delete);
        }
        break;

      // 7. Exit Inbox
      case 7:
        free(ib->emails);
        printf("Exiting e-mail client - Good Bye!\n");
        return(0);   
      }
    }
  }
}

void create_email(char* sender, char* receiver, char* subject, char* body, int month, int day, int year, struct Mailbox *ib)
{
  int count = ib -> size;
  strncpy(ib -> emails[count].sender, sender, ADDRESS_SIZE);
  strncpy(ib -> emails[count].receiver, receiver, ADDRESS_SIZE);
  strncpy(ib -> emails[count].subject, subject, SUBJECT_SIZE);
  strncpy(ib -> emails[count].body, body, BODY_SIZE);
  ib -> emails[count].date.month = month;
  ib -> emails[count].date.day = day;
  ib -> emails[count].date.year = year;
  ib -> emails[count].ID = count;
  ib -> size++;
}




//Other function definitions go below
