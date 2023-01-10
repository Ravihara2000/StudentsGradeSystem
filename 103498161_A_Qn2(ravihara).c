#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct person_tag
{
	
	char name[20];
	char id[10];
};

struct course_tag
{
	
	char course_name[20];
	int  no_of_units;
	int marks[4];
	float avg;
};
struct student_tag
{
	
	struct person_tag student_info;
	struct course_tag course_info;
	struct student_tag *next;
};

typedef struct student_tag studentinfor;
typedef struct student_tag * studentinforp;

studentinforp start = NULL;
studentinforp node0;
studentinforp temmp, currrent;

int over =0;
int totl = 0;
char sename[20];
char nename[20];
char neid[20];
char necoursename[20];
int nenoofunits;
int nemark[4];

void display_students()
{
	printf("--Students Details-- \n\n");
	
	
	//display the linked list
	for(studentinforp x = start; x != NULL; x = x->next)
	{
		printf("Name :%s \n", x->student_info.name);
		printf("Student ID  :%s \n", x->student_info.id);
		printf("Course Name  :%s \n", x->course_info.course_name);
		printf("Number of Units  :%d \n", x->course_info.no_of_units);
		printf("Marks  :");
		
		for(int w = 0; w < x->course_info.no_of_units; w++)
		{
			printf("%d \t", x->course_info.marks[w]);
		}
		 printf("\n");
		 
		 //display node average
		 
		 printf("Marks Average   :%.1f \t",x->course_info.avg);
		 
         
		 printf("\n\n");
		
	}
	
	
}

void find_failed()
{
	printf("--Failed students-- \n\n");
	for(studentinforp x = start; x != NULL; x = x->next)
	{
		for(int w =0; w < x->course_info.no_of_units; w++)
		{
			if(x->course_info.marks[w]<50)//check whether marks are small than 50
			{
				 printf("Name  :%s \n", x->student_info.name); 
				 printf("student Id  :%s \n", x->student_info.id);
				 
				 printf("Course Name  :%s \n", x->course_info.course_name);
				 printf("Number of Units  :%d \n", x->course_info.no_of_units);
				 
				 printf("Marks  :");
				 
				 for(int w = 0;w < x->course_info.no_of_units;w++)
				 {
					  printf("%d \t",x->course_info.marks[w]);
					 
				 }
				 printf("\n");
				 
				 printf("Marks Average   :%.1f  \t",x->course_info.avg);
				 
				 printf("\n\n");
				
				 break;
				 
			}
		}
	}
}

void search_student()
{
	 printf("--Search Students-- \n\n");
	 printf("Enter Student Name  :");
	 scanf("%s",sename);
	 studentinforp  x = start; 
	 while (x != NULL)
	 {
		 //check string is same using strcmp function
		 if(strcmp(sename, x->student_info.name)==0)
		 {
			 over = 1;
			 //if name is in linked list print the that student details
			 printf("Name  :%s \n", x->student_info.name); 
			 printf("student Id  :%s \n", x->student_info.id);
			 printf("Course Name  :%s \n", x->course_info.course_name);
			 printf("Number of Units  :%d \n", x->course_info.no_of_units);
			 printf("Marks  :");
			 
			 
			 for(int w = 0;w < x->course_info.no_of_units; w++)
			 {
				 printf("%d \t",x->course_info.marks[w]);
			 }
			 printf("\n");
			 
			 printf("Marks Average  :%.1f \t",x->course_info.avg);
			 
			 printf("\n\n");
			 
			 break;
	 }
	 x = x->next;
	 }
	  if(over == 0)
	  {
		  //will print this  if the searched name is not there
		 printf("--There is no student with this Name-- \n");
	 }
}

void update_file()
{
	printf("--Add a new name-- \n\n");
	
	
	 //open the file
	 FILE *fp = fopen("students.txt", "a");
	 
	 //take the information about students
	 printf("Enter Name  :");
	 fflush(stdin);
	 scanf("%s",nename);
	 
	 printf("Enter student ID  :");
	 fflush(stdin);
	 scanf("%s",neid);
	 
	 printf("Enter course Name  :");
	 fflush(stdin);
	 scanf("%s",necoursename);
	 
	 printf("Enter number of units  :");
	 fflush(stdin);
	 scanf("%d",&nenoofunits);
	 
	 //write the details to the file
     fprintf(fp,"%s\n%s\n%s\n%d\n", nename,neid,necoursename,nenoofunits);
	 printf("Enter Marks  :");
	 
	  //wrire marks to the file
	 for(int w = 0;w < nenoofunits; w++)
	 {
		 scanf("%d",&nemark[w]);
		 
		 fflush(stdin);
		 
		 fprintf(fp,"%d\n", nemark[w]);
	 }
	 
}

void find_maximum()
{
	 printf("--Maximun average student-- \n\n");
	 
	 float max;
	 max = currrent->course_info.avg;
	 
	 //get the maximum average in the linked lsit
	 for(currrent = start; currrent != NULL; currrent = currrent->next)
	 {
		  if(max < currrent->course_info.avg)
		  {
             max = currrent->course_info.avg;  
         } 
	 }
	 
	 for(currrent = start; currrent != NULL; currrent = currrent->next)
	 {
		 //check the linklist and print student details using avg
		 if(max == currrent->course_info.avg)
		 {
			 printf("Name  :%s \n", currrent->student_info.name); 
			 
			 printf("student Id  :%s \n", currrent->student_info.id);
			 
			 printf("Course Name  :%s \n", currrent->course_info.course_name);
			 
			 printf("Number of Units  :%d \n", currrent->course_info.no_of_units);
			 
			 printf("Marks  :");
			 
			 for(int w = 0; w < currrent->course_info.no_of_units; w++)
			 {
				 printf("%d \t",currrent->course_info.marks[w]);
			 }
			 
			 printf("\n");
			 
			 printf("Average marks   :%.1f \t",max);
			 
			 printf("\n");
			
			 break;
		 }
		 
	 }
}

void read_file()
{
	
	int mf,lf[4];
	
	char u[20],ui[20];
	char w[20];
	 
	 FILE *file=fopen("students.txt","r");//file open in read mode
	 
	 while(fscanf(file,"%s\n%s\n%s\n%d\n", w, u, ui,&mf)!=EOF)
	 {
		 printf("\n");
		 
		 //memory allocation
		 
		 node0=(studentinfor *)malloc(sizeof(studentinfor));
		 
		 
		 strcpy(node0->student_info.name,w);
		 strcpy(node0->student_info.id,u);
		 strcpy(node0->course_info.course_name,ui);
		 node0->course_info.no_of_units = mf;
		 
		 
		 for(int p = 0; p < mf; p++)
		 {
			 
			 fscanf(file, "%d\n", &lf[p]);
			 node0->course_info.marks[p]= lf[p];
			 
		 }
		 
		 for(int y = 0; y < mf; y++)
		 {
			 totl = totl + node0->course_info.marks[y];
			 
		 }
		 node0->course_info.avg = totl/mf;//get average of students marks
		 totl=0;
		 
		 
		 //node add according to the alpebetical order
		 if(start==NULL || strcmp(start->student_info.name,node0->student_info.name)>=0 )
		 {
			 node0->next =start;
			 start= node0;
		 }
		 else
		 {
			 currrent=start;
			 while(currrent->next !=NULL && strcmp(currrent->next->student_info.name, node0->student_info.name)<0)
			 {
				 currrent = currrent->next;
			 }
			 node0->next = currrent->next; 
			 currrent->next = node0; 
		 }
	
		}

	
	 printf("--Sucessfully add file details to the linked list-- \n");
	 
	 fclose(file);//close txt file
}


void menu(){
	 //print the menu
	printf("\n");
	 printf("(1)-- Display students details-- \n");
	 printf("(2)--Search students mark-- \n");
	 printf("(3)--Find the details about student with the largest average-- \n");
	 printf("(4)--Find the details about failed students-- \n");
	 printf("(5)--Add new students to the record-- \n");
	 printf("(6)--Quit the program-- \n");
} 

int main()
{
	 int opt;
	 
	 
		read_file();
	 //switch case for select options
	 do{
		 menu();
		 
		 printf("Enter Your Option   :");
		 scanf("%d", &opt);
		 
		 
	     switch(opt)
		 {
			 case 1:display_students();
			 break;
			 
			 case 2:search_student();
			 ;break;
			 
			 case 3:find_maximum();
			 break;
			 
			 case 4:find_failed();
			 break;
			 
			 case 5:update_file();
			 break;
			 
			 case 6:printf("---Porgrame terminated. bye---\n");
			        exit(1);
			break;
			
			 default:printf("--Wrong Option --\n");
			 
		 }
		 
		
	 }while(opt !=6);
	
	
}





 

