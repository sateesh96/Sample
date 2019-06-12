
/* Game of lifes program 			*
 * user input number of rows and columns	*/

#include<stdio.h>
#include<stdlib.h>

int row,col;
void nextgeneration(char cell[row][col]);
int neighbourcount(char cell[row][col],int,int);
void printcells(char cell[row][col]);

/* main strats here */
int main()
{
	int i,j;
	char g;
	
	/* Initializing rows and columns */
	printf("Enter no.of rows : ");
	scanf("%d",&row);
	printf("Enter no.of columns : ");
	scanf("%d",&col);
	
	char cell[row][col];
	
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			cell[i][j]='.';
	
	/* Initializing the living cells */
	printf("Enter rows and columns of a cell that you need to be intialize initially as living\n");
	printf("Enter -1 -1, separated by a space to quit\n");
	
	do {
	printf("Enter a row and column, separated by a space : ");
	scanf("%d %d",&i,&j);
	cell[i][j]='*';
	} while((i!=-1)&&(j!=-1));
	printcells(cell);

label:
	printf("Do you want to see the next generation yes(y) or no(n)");
	fflush(stdin);
	scanf(" %c",&g);
	
	if(g=='y') 
	{
		nextgeneration(cell);
		printcells(cell);
		goto label;
	}
}

/********* Next generation function *********/

void nextgeneration(char cell[row][col])
{
	int i,j,m,n,ncount=0,flag=0;
	char nextcell[row][col];
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++,ncount=0)
		{
			ncount=neighbourcount(cell,i,j);  /* Neighbour count of each cell */
			if(ncount==3)
				nextcell[i][j]='*';
			else if((ncount<2)||(ncount>3))
				nextcell[i][j]='.';
			else if(ncount==2)
				nextcell[i][j]=cell[i][j];
		}
	}
	
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			if(cell[i][j]!=nextcell[i][j])
				flag=1;
	
	if(flag==0)
	{
		printf("..............GAME OVER..........\n");
		exit(0);
	}
	else
	{
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				cell[i][j]=nextcell[i][j];
	}
}
			

/******* Neighbour count function *********/

int neighbourcount(char cell[row][col],int i,int j)
{
	int m,n,ncount=0;
	
	for(m=-1;m<2;m++)
	{
		for(n=-1;n<2;n++)
		{
			if((m!=0)||(n!=0))
			{
				if(cell[i+m][j+n]=='*')
					ncount++;
			}
		}
	}
	
	return ncount;
}

/******* Printing cellls ******/

void printcells(char cell[row][col])
{
	int i,j;
	
	for(i=0;i<row;i++,printf("\n"))
		for(j=0;j<col;j++)
			printf("%c ",cell[i][j]);

}

