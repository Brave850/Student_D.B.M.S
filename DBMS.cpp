#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <iostream>
#include<ctype.h>
#include<direct.h>
#include<process.h>
#include<time.h>
#include<string.h>
#include<windows.h>

using namespace std;
int mean;
int test=0;
void add();// add a record
void search();// search a record
void list(); //display the record
void del(); // delete the record
void modify();// mpdify the record
void rec(); //scan the new record
void mainpage(); //starting page
//int logscreen();// login screen
//void callExit();// exit function
void menu();// Main Menu
void date();// to get current date
void empty();// used in deleting the record
void title();// title bar
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
struct information
{
	char ID[15]; //Student ID
  char fname[15]; //Student First Name
  char lname[30];  //Student Last Name
  
  char Course[35];  //Course Name
  
  char section[8];  //section of a student
}c,dol,upd;

FILE *fpt;
int main()
{
  system("cls");
  mainpage();
  return 0;
  //logscreen();
}
void date()
{
  time_t T= time(NULL);
  struct  tm tm = *localtime(&T);
  printf("\n\n\n");
  printf("\t\t\t   Date:%02d/%02d/%04d\n",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
}
void title()
{
  cout<<"\n\n\n";
  cout<<"\t\t\t\t\t";
  printf("\n");
  printf("\t\t    ---------------------------\n");
  printf("\t\t    |STUDENT MANAGEMENT SYSTEM|\n");
  printf("\t\t    ---------------------------\n");
  printf("\n\n");
  printf("\t\t");

}
void mainpage()
{
  int process=0;
  system("cls");
  date();
  printf("\n");
  printf("\t\t    ---------------------------\n");
  printf("\t\t    |STUDENT MANAGEMENT SYSTEM|\n");
  printf("\t\t    ---------------------------\n");
  printf("\n\n\n");
  printf("\t\t");
  printf("Prepared By    ");
  printf(":");
  printf("   Sambit Kumar Khandai");
  printf("\n\n");
  printf("\t\t");
  printf("This Project   ");
  printf(":");
  printf("   Student Management System");
  printf("\n\n");
  printf("\t\t");
  printf("\n\n");
  cout<<"\t\t";system("pause");
  printf("\n\n");
  
  printf("\t\tLoading");

  for(process=0;process<25;process++)
  {
    delay(150);
    printf(".");
  }
  menu();
}
void menu()
{
  int input;
  system("cls");
  title();
  printf(" 1. Enter new Records\n\n");
  printf("\t\t");
  printf(" 2. Modify Records\n\n");
  printf("\t\t");
  printf(" 3. Delete Records\n\n");
  printf("\t\t");
  printf(" 4. Search and view Records\n\n");
  printf("\t\t");
  printf(" 5. Exit\n\n");
  printf("\t\t");
  printf("Choose options:[1/2/3/4/5]: ");
  fflush(stdin);
  scanf("%d",&input);
  switch(input)
  {
    case 1:
    {
      system("cls");
      add();
    }
    break;

    case 2:
    {
      system("cls");
      modify();
      getchar();
    }
    break;

    case 3:
    {
      system("cls");
      del();
    }
    break;

    case 4:
    {
      system("cls");
      search();
    }break;

    case 5:
    {
      exit(0);
    }
    break;

    default:
    {
      fflush(stdin);
      printf("\n\n\n");
      printf("\t\t\t\t");
      printf("      Invalid input!");
      printf("\n\n");
      printf("\t\t\t\t");
      printf("Press Enter to choose again...");
      getchar();
      menu();
    }
  }
  }
  void add()
  {
  	FILE *fpt;
  	fpt=fopen("data.txt","a+");
  	devil:
    system("cls");
    printf(" ");
    printf("\n");
    printf("\t\t");
    printf("\n");
    printf("\t\t");
    printf("\n");
    printf("\t\t");
    printf("\n");
    printf("\n\n\n\n");
    printf("\t\t");
    printf("Enter The Information Below: \n\n");
    cout<<"\t\t";
 
    printf("Enter ID        :  ");

    fflush(stdin);
    scanf("%s",dol.ID);
    
    while(fscanf(fpt,"%s %s %s %s %s\n",&c.ID,&c.fname,&c.lname,&c.Course,&c.section)!=EOF)
    {
    	if(c.ID==dol.ID)
    	{
    		cout<<"\n\n\tAccount Already Exits!";
    		goto devil;
		}
	}
	strcpy(c.ID,dol.ID);
    cout<<endl;
    printf("\t\t");
    printf("Enter First Name        :  ");

    fflush(stdin);
    scanf("%s",c.fname);
    printf("\n\n");
    printf("\t\t");
    printf("Enter Last Name       :  ");
    fflush(stdin);
    scanf("%s",c.lname);
    printf("\n\n");
    printf("\t\t");
    printf("Enter Your Course           :  ");
    fflush(stdin);
    scanf("%s",c.Course);
    printf("\n\n");
    printf("\t\t");
    printf("Section          :  ");
    fflush(stdin);
    scanf("%s",c.section);
    printf("\n\n");
    
    
    fprintf(fpt,"%s %s %s %s %s\n",c.ID,c.fname,c.lname,c.Course,c.section);
    fclose(fpt);
    printf("\n\n");
    printf("\t\t\t");
    printf("Record added successfully!!");

    printf("\n\n\n");
    printf("\t\t\t");
    printf("Do you want to add more? (1/0)");
    int sa;
    cin>>sa;
    
    if(sa)
    {
      add();
    }
    else
    menu();
    }
void modify()
{
  char mid[30];

  int found=0;
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\t\t\t");
  fflush(stdin);
  cout<<"Enter Your Id: ";
  cin>>mid;
  fflush(stdin);
  FILE *fpt, *temp;
  temp =fopen("temp.txt","a+");
  fpt = fopen("data.txt","r+");
  while(fscanf(fpt,"%s %s %s %s %s",&c.ID,&c.fname,&c.lname,&c.Course,&c.section)!=EOF)
  {
      if(strcmp(mid, c.ID) == 0)
      {
          fflush(stdin);
          system("cls");
          printf("\n\n\n\n\n\n\n");
          printf("\t\t\t");
          printf("<<<==Old Record==>>>");
          printf("\n");
          printf("\t\t");
          list();
          printf("\n\n");
          printf("\t\t");

          printf("Press Enter to modify the record...");


          getchar();
          system("cls");
          test=1;
    		printf("\t\t\n Which data you want to update(1.Course & 2.Section)");
			printf("\n\t\t Enter Your choice:\t");
			int choice;
			scanf("%d",&choice);
			if(choice==1)
			{
				printf("\n\t\tEnter the new Course:\t");
				scanf("%s",upd.Course);
				fprintf(temp,"%s %s %s %s %s\n",c.ID,c.fname,c.lname,upd.Course,c.section);
			
			}
			else if(choice==2)
			{
				printf("\nEnter the new Section:\t");
				scanf("%s",upd.section);
				fprintf(temp,"%s %s %s %s %s\n",c.ID,c.fname,c.lname,c.Course,upd.section); 
				system("cls");
			
			}

		}
		else
			fprintf(temp,"%s %s %s %s %s\n",c.ID,c.fname,c.lname,c.Course,c.section);
    }
        fclose(temp);
        fclose(fpt);
        remove("data.txt");
		rename("temp.txt","data.txt");
		cout<<"\n\n\t\t\t Data Updated Sucessfully";
		cout<<endl<<endl;
		getch();
        menu();
      

      if(test==0)
      {
        {
          system("cls");
          delay(200);
          fflush(stdin);

          printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
          printf("\t\t\t\t\t");
          fflush(stdin);

          printf("<<--Record Not Found-->>");
          getchar();
          menu();
        }
      }
      
      
}
       
void list()
{
      printf(" ");
      printf("\n");
      printf("\t\t\t\t");

      printf("\t\t\t\t");
      printf("\n");
      printf("\t\t\t\t");
      printf("\n");

      printf("\t\t\t");


      printf("ID       \t:  %s\n\n",c.ID);
      printf("\t\t\t");
      printf("First Name       : %s  ",c.fname);

      printf("\n\n");
      printf("\t\t\t");
      printf("last Name        : %s  ",c.lname);

      printf("\n\n");
      printf("\t\t\t");
      printf("Course           : %s  ",c.Course);

      printf("\n\n");
      printf("\t\t\t");
      printf("Section          : %s  ",c.section);

}
void del()
       {
   system("cls");
	int test=0,choice;
	char is[15];
	cout<<"\n\n\n\n\t\t\tEnter Id: ";
	cin>>dol.ID;
	cout<<endl;
	FILE *old,*ne;
	old=fopen("data.txt","r+");
	ne=fopen("new.txt","a+");
	
	while(fscanf(old,"%s %s %s %s %s",c.ID,c.fname,c.lname,c.Course,c.section)!=EOF)
	{
		if(strcmp(c.ID,dol.ID)!=0)
		{
			fprintf(ne,"%s %s %s %s %s\n",c.ID,c.fname,c.lname,c.Course,c.section);
		}
		else
			{
				test++;
			printf("\n\n!!!Acount Remove Successfully!!!");
			}
	}
	fclose(old);
	fclose(ne);
	remove("data.txt");
	rename("new.txt","data.txt");
 	cout<<"Do you want to continue (1/0):/t";
 	cout<<endl;
    int sa;
    cin>>sa;
    
    if(sa)
    {
      del();
    }
    else
    menu();
	if(test==0)
	{
		printf("\n!!!Sorry Record is not found!!!");
		invalid_choice:
			printf("\nEnter 1 to Retry\n 2 to main menu()\n 0 for Exit");
			scanf("%d",&mean);
			if(mean==1)
			{
				system("cls");
				del();
			}
			else if(mean==2)
			{
				system("cls");
				menu();
			}
			else if(mean==0)
				exit(0);
			else
				goto invalid_choice;
	}
}
      void search()
      {
        int ch;
        FILE *fpt;
        char sid[15];
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t");

        fflush(stdin);
        printf("Enter Your ID: ");
        scanf("%s",sid);

        fpt=fopen("data.txt","r");
        while (fscanf(fpt,"%s %s %s %s %s",&c.ID,&c.fname,&c.lname,&c.Course,&c.section)!=EOF)
        {
          if(strcmp(sid,c.ID)==0)
          {
            ch=1;
            break;
          }
        }
        if(ch==1)
        {
          system("cls");
          printf("\n\n\n\n\n\n\n");
          printf("\t\t\t\t\t");

          printf("<<==Search Succesfull==>>");
          fflush(stdin);
          getchar();
          list(); //display the record
          printf("\n\n\n");
          printf("\t\t\t\t\t");
          printf("Press Enter For Main Menu...");
          getchar();
          menu();
        }
        else
        {
          system("cls");
          getchar();
          printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
          printf("\t\t\t\t\t");

          printf("<<--Record Not Found-->>");
          printf("\n\n\n");
          printf("\t\t\t\t\t");
          printf("Press Enter For Main Menu...");
          getchar();
          menu();
        }

        fclose(fpt);
      }


