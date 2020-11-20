#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
  int sem;
  char name[100];
  char usn[100];
  struct node *next;
};
struct node *head = NULL;
int counter = 0;


void
Insertst ()
{
  struct node *newnode;
  int s;
  char n[100], u[100];
  printf ("\t ----Enter the name-----  : ");
  scanf ("%s", n);
  printf ("\t ----Enter the semester-----  : ");
  scanf ("%d", &s);
  printf ("\t ----Enter the usn---- : ");
  scanf ("%s", u);
  newnode = (struct node *) malloc (sizeof (struct node));
  newnode->sem = s;
  strcpy (newnode->name, n);
  strcpy (newnode->usn, u);
  if (head == NULL)
    printf (">>First node created\n");
  newnode->next = head;
  head = newnode;
  counter++;
  printf ("Node created!\n");
}

void
Insertany (int p)
{
  struct node *newnode;
  int s;
  char n[100], u[100];
  printf ("\t -Enter the name-  : ");
  scanf ("%s", n);
  printf ("\t -Enter the semester- : ");
  scanf ("%d", &s);
  printf ("\t -Enter the usn-  : ");
  scanf ("%s", u);
  newnode = (struct node *) malloc (sizeof (struct node));
  newnode->sem = s;
  strcpy (newnode->name, n);
  strcpy (newnode->usn, u);
  if (p == 1)
    {
      printf ("Node of linked list is inserted in the first position\n");
      newnode->next = head;
      head = newnode;
      counter++;
    }
  else if (head == NULL && p > 1)
    {
      printf ("currently empty!!!\n");
      return;
    }
  else if (p > (counter + 1))
    {
      printf
	("Not possible since number of pre-existing nodes in list is insufficient!\n");
      return;
    }
  else
    {
      struct node *temp1;
      struct node *temp2;
      int count = 1;
      temp1 = head;
      while (count < (p - 1))
	{
	  temp1 = temp1->next;
	  count++;
	}
      temp2 = temp1->next;
      temp1->next = newnode;
      newnode->next = temp2;
      counter++;
      printf ("Node inserted at %d position in linked list\n", p);
    }
}

void
Insertend ()
{
  struct node *newnode;
  struct node *temp;
  int s;
  char n[100], u[100];
  printf ("Enter the name- : ");
  scanf ("%s", n);
  printf ("Enter the semester-  : ");
  scanf ("%d", &s);
  printf ("Enter the usn-  : ");
  scanf ("%s", u);
  newnode = (struct node *) malloc (sizeof (struct node));
  newnode->sem = s;
  strcpy (newnode->name, n);
  strcpy (newnode->usn, u);
  if (head == NULL)
    {
      newnode->next = NULL;
      head = newnode;
      printf (">Very first node  created\n");
      counter++;
    }
  else
    {
      temp = head;
      while (temp->next != NULL)
	{
	  temp = temp->next;
	}
      temp->next = newnode;
      newnode->next = NULL;
      counter++;
      printf ("Node created!\n");
    }
}

void
display ()
{
  struct node *ptr;
  ptr = head;
  int i = 1;

  if (ptr == NULL)
    {
      printf ("Linked list is empty!!\n");
    }
  else
    {
      while (ptr != NULL)
	{
	  printf ("NODE %d\n", i);
	  printf ("Name: %s\n", ptr->name);
	  printf ("USN: %s\n", ptr->usn);
	  printf ("Sem: %d\n", ptr->sem);
	  printf ("---------\n");
	  i++;
	  ptr = ptr->next;
	}

    }
}
int
main ()
{
  int choice, pos;
  do
    {
      printf ("\n");
      printf
	("\n1. Insert node at starting.. \n2. Insert node anywhere... \n3. Insert at the end of list.\n4. < Display list >\n5. Exit!!!\n");
      printf ("\n\t Enter your choice() : ");
      scanf ("%d", &choice);
      if (choice == 5)
	break;
      switch (choice)
	{
	case 1:
	  Insertst ();
	  break;

	case 2:
	  printf ("Enter in which position you want to enter your node\n");
	  scanf ("%d", &pos);
	  Insertany (pos);
	  break;

	case 3:
	  Insertend ();
	  break;

	case 4:
	  display ();
	  break;

	default:
	  printf ("invalid!\n");
	  break;
	}
    }
  while (choice != 5);
  return 0;
}

