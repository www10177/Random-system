#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(void)
{
	FILE* listPtr;
	char list_name_cache[101],item_cache[21];
	char list_name[100][101];
	int  list_number= 1, list_chosen;
	char item[101][21];
	int item_num = 0, item_chosen;

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

	/*User choose the list	*/
		printf("Please enter number to select list...\t");
		scanf("%d",&list_chosen);

	/*Deal with list name*/
	char name_temp[110],name_orig[110];
	strcpy(name_orig,&list_name[list_chosen][0]);
	strcpy(name_temp,".");
	strcat(name_temp,&list_name[list_chosen][0]);
	strcat(name_temp,".dat");

	/*open list*/
	if (  (listPtr=fopen(name_temp, "r")) == NULL ) {
		printf("ERROR: open %s ERROR\n", name_temp);
		return -1;
	}
/*convert file into string array to handle*/ while ( 1 ) {
		fgets(item_cache, 21, listPtr);
		if ( feof(listPtr) ) {
			break;
		}
		sscanf(item_cache, "%[^\n]", &item[item_num][0]);
		/*printf("%d\t%5s\n", item_num, &item[item_num][0]);*/
		item_num++;
	}
	fclose(listPtr);

	/*Random*/
		char temp ,c;
	while ( 1 ) {
		srand( time(NULL) );
		item_chosen = rand()%item_num;
		printf("\n\nThe Result is \t %s\n\n", &item[item_chosen][0]);
		printf("If you want to random again, just input 'Y'\nOr press input any character to exit\t");
		while ( (c = getchar()) != '\n' && c != EOF ) ;
		temp =getchar();
		/*scanf("%[^\n]",&temp);	*/
		/*flush the stdin*/
		if ( temp != 'y' && temp != 'Y') {
			break;	 	
		}
		/*wait a sec to avoid repeated result*/
		sleep(1);
	}
	printf(" \n");


	return 0;
}
