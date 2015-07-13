#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Print_List(FILE*);
int main(void)
{

	FILE* listPtr;
	char list_name_cache[101],item_cache[21];
	char list_name[100][101];
	int  list_number= 1, list_chosen;
	char item[101][21];
	int item_num = 0, item_chosen, action;
	char data[21];

	/*show list*/
	/*open file*/
	if (  (listPtr=fopen(".name.lst", "r")) == NULL ) {
		printf("ERROR: open .name.lst ERROR\n");
		return -1;
	}

	/*convert file into string to handle*/
	printf("\nShow All Available Lists\n");
	printf("*****************************\n");
	printf("Number\tName\n");
	while ( 1 ) { 
		fgets(list_name_cache, 101, listPtr);
		if ( feof(listPtr) ) { 
			break;
		}
		sscanf(list_name_cache, "%[^\n]", &list_name[list_number][0]);
		printf("%d\t%5s\n", list_number, &list_name[list_number][0]);
		list_number++;
	}   
	fclose(listPtr);
	printf("*****************************\n");

	/*User choose the list  */
	printf("Please enter number to select list...\t");
	scanf("%d",&list_chosen);

	/*Deal with list name*/
	char name_temp[110],name_orig[110],flush;
	strcpy(name_orig,&list_name[list_chosen][0]);
	strcpy(name_temp,".");
	strcat(name_temp,&list_name[list_chosen][0]);
	strcat(name_temp,".dat");

	/*open list*/
	if (  (listPtr=fopen(name_temp, "r")) == NULL ) {
		printf("ERROR: open %s ERROR\n", name_temp);
		return -1;
	}

	/*Action Menu*/
	printf("\n*****************************\n");
	printf("Input '1' to show all item in the %s\n",&list_name[list_chosen][0]);
	printf("Input '2' to add item in the %s\n",&list_name[list_chosen][0]);
	printf("*****************************\n");
	printf("Please input instruction...\t");
	/*Clean the stdin*/
	while ( ((flush = getchar()) != '\n')  && (flush != EOF) ) ;
	scanf("%d",&action);
printf(" \n");
	/*Do the action */
	if ( action == 1 ) {
		Print_List(listPtr)	;
		printf("\n");
	}
	if ( action ==2 ) {
		fseek(listPtr, 0, SEEK_END);

		/*input data*/
		printf("*****************\n");
		printf("Please Enter Data\n");
		printf("Limit: less than 20 characters\nSend EOF to end input( in Unix-like systems EOF usually is Ctrl+d)\n");
		printf("*****************\n");
		while ( gets( data ) != NULL){
			fprintf( listPtr, "%s\n", data);
			printf("\nYou enter\t%s\n\n",data);
		}   
		printf("Add End\n\n");
	}
	fclose(listPtr);
	return 0;
}
void Print_List(FILE* list){
	char data[21];
	while ( 1 ) {
		fgets(data, 21, list);
		if ( feof(list) ) {
			break;	
		}
		printf("%s",data);
	}
	return;
}
