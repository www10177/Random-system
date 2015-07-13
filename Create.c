#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	/*declare and initialize*/
	char name[ 101 ], data[25];
	FILE* stream;
	FILE* list; 
	/*To enter name*/

	printf("\nPlease Enter List Name\n");
	printf("Limit: less than 100 characters\n");
	scanf("%[^\n]",name);
	gets(name);
	printf("You Entered %s \n\n",name);
	/*With some bugs that cause segmentaion fualt*/
	/*
	 *int enter_name_end = 0;
	 *char choice;
	 *scanf("%c",&choice);
	 *while ( enter_name_end == 0 ) {
	 *    if ( choice == 'Y' || choice == 'y') {
	 *        enter_name_end = 1;
	 *        printf("y\n");
	 *    }
	 *    else if ( choice == 'N' || choice == 'n') {
	 *        enter_name_end = 0;
	 *        printf("Please Enter Again...\n");
	 *        scanf("%s",name);
	 *        printf("You Entered %s, Right?(Y/N)\n",name);
	 *        scanf("%c",&choice);
	 *    }
	 *    else {
	 *        enter_name_end = 0;
	 *        printf("Please Enter Y or N and Please Don't Play the System!!!\n");
	 *        choice = 'n';
	 *    }
	 *}
	 */
	/*Take the list name in the "list" list*/
	if ( ( list=fopen(".name.lst","a") )== NULL ){
		printf("ERROR: Open name list ERROR\n");
	}

	/*convert the name into the real datname*/
	char name_temp[110],name_orig[110];
	strcpy(name_orig,name);
	strcpy(name_temp,".");
	strcat(name_temp,name);
	strcat(name_temp,".dat");
	strcpy(name,name_temp);

	/*Check if the List is already existed and create the stream(file)*/
	if ( access(name, F_OK) == 0 ) {
		printf("The list %s is already existed. Append the data to the List. \n",name_orig);
		if( (stream = fopen(name,"ab") ) ==NULL ){
			printf("ERROR: Append error\n");
			return 1;
		}
	}
	else{
		if( (stream = fopen(name,"w") ) ==NULL ){
			printf("ERROR: create error\n");
			return 1;
		}
		printf("The list %s is created\n",name_orig);
		fprintf(list,"%s\n",name_orig);
	} 
	/*input data*/
	printf("*****************\n");
	printf("Please Enter Data\n");
	printf("Limit: less than 20 characters\nSend EOF to end input( in Unix-like systems EOF usually is Ctrl+d)\n");
	printf("*****************\n");
	while ( gets( data ) != NULL){
		fprintf( stream, "%s\n", data);
		printf("\nYou enter\t%s\n\n",data);
	}
	printf("Input End\n\n");
	fclose(stream);
	fclose(list);
	return 0;
}

		char temp ;
