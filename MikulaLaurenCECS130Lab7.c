//Lauren Mikula
//CECS 130
//Lab 7
//3/8/19

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct con{
    char FirstName[30];
    char LastName[30];
    char PhoneNumber[20];
}contacts;

contacts* phonebook;
int size = 0;

// add new contacts array
void addContact(contacts *temp)
{
	size++;
    phonebook = realloc(phonebook, size*sizeof(contacts));
    phonebook[size - 1] = *temp;
}

// alphabetize contacts by last name
int Alphabetize(char A[30],char B[30]){
    int x;
    for(x = 0; A[x] <= B[x]; x++)
	{
        if(A[x] < B[x])
		{
            return 1;
        }
    }
    return 0;
}

void swap(contacts *x, contacts *y)
{
    contacts temp = *x;
    *x = *y;
    *y = temp;
}

// swaps contacts so they're in alphebetical order by last name
void SortAlpContacts(contacts conarray[],int n)
{
    int i, j;
    for (i = 1; i < n; i++)
	{

        for(j = 0; j < n-i; j++)
		{
            if (!Alphabetize(conarray[j].LastName,conarray[j+1].LastName))
               swap(&conarray[j], &conarray[j+1]);
        }
    }
}

// delete contact function
void delContact(char DelFirstName[30],char DelLastName[30])
{
	int x = 0;
	int y = 0;
	int z = 0;
	
	for(x = 0;x < size; x++)
	{
		if (strcmp(phonebook[x].FirstName, DelFirstName) == 0 && strcmp(phonebook[x].LastName, DelLastName) == 0)
		{
			y = x;
		}
	}
	size--;
	for(z = y; z < size; z++)
	{
        phonebook[z] = phonebook[z+1];
	}
	phonebook = realloc(phonebook, size*sizeof(contacts));
}

// display all contacts function
void displayContacts(contacts *temp)
{
	printf("\nFirst Name: %s", temp -> FirstName);
    printf("\nLast Name: %s", temp -> LastName);
    printf("\nNumber: %s", temp -> PhoneNumber);
}

contacts addNewContact()
{
    contacts ret;
    printf("\nFirst name: ");
    scanf("%s", ret.FirstName);
    printf("Last Name: ");
    scanf("%s", ret.LastName);
    printf("Phone Number: ");
    scanf("%s", ret.PhoneNumber);
    return ret;
}

// main function
int main()
{   
	int n, x, y;
    char FirstName[30],LastName[30], temp[30];

    phonebook = (contacts*) malloc(sizeof(contacts));
    contacts cntct; 

do{
	//phonebook menu
    printf("\n\n   Phone Book ");
    printf("\n  ------------ ");
    printf("\n1) Add contact");
    printf("\n2) Delete contact");
    printf("\n3) Display all contacts");
    printf("\n4) Print random contact");
    printf("\n5) Delete all contacts");
    printf("\n6) Find a contact");
    printf("\n\nPlease pick an option: ");
    scanf("%d", &n);

    switch(n){
    case 1://add new contact
        cntct = addNewContact();
        addContact(&cntct);
        printf("\nContact added");
        SortAlpContacts(phonebook, size);
        break;
    case 2://delete contact
        printf("\nFirst Name: ");
        scanf("%s", FirstName);
        printf("\nLast Name: ");
        scanf("%s", LastName);
        delContact(FirstName,LastName);
        printf("\nContact deleted");
        break;
    case 3://display contacts
        for(x = 0;x < size; x++)
		{
			y = x +1;
			printf("\nContact #%d", y);
            displayContacts(&phonebook[x]);
            printf("\n");
        }
        break;
    case 4://print random contact
        srand(time(0));
        displayContacts(&phonebook[rand()%size]);
        break;
    case 5://deletes all contacts
        size = 0;
        phonebook = realloc(phonebook, size*sizeof(contacts));
        printf("\nAll contacts deleted");
    break;
    case 6://find a contact
        printf("\nFirst Name: ");
        scanf("%s",FirstName);
        printf("Last Name: ");
        scanf("%s",LastName);
        int i;
        for (i = 0; i < size; i++)
		{
          if(strcmp(FirstName, phonebook[i].FirstName) == 0 && strcmp(LastName, phonebook[i].LastName) == 0)
		  {
            displayContacts(&phonebook[i]);
          }
          else if(strcmp(FirstName, phonebook[i].FirstName) != 0 || strcmp(LastName, phonebook[i].LastName) != 0)
          {
          	printf("\nContact not found");
          }
        }
    }
    }while(1);
    return 0;
}
