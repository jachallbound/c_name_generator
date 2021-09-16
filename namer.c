#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int uppc();
int lowc();
int uppv();
int lowv();
int suffix(int, int, int, int, int);
int namegendeci ( );
int namegencalc (int, int, int, int, int);

//Main Function
int main (void)
{
	time_t t;
	t=(time(NULL)-1);
	srand((char)time(&t));
	t=rand()%100;
	srand((char)time(NULL)*time(&t));

	printf("\nThis program will generate a name for you.");

	//Name Generator PCF - Not All Inclusive
	namegendeci();

	return 0;
}

//Functions to return random characters
int uppc(void)
{	
	char cupp="BCCCDFGGHHJJJKLLLMMMNNNPQRRRRSSSSTTTTVVWXYZ"[rand()%43];
	printf("%c",cupp);
	return(cupp);
}

int lowc(void)
{	
	char clow="bcccdddfgghhjjklllmmmnnnpqrrrrrrssssssttttttvwwxyyz"[rand()%51];
	printf("%c",clow);
	return(clow);
}

int uppv(void)
{	
	char vupp="AEIOU"[rand()%5];
	printf("%c",vupp);
	return(vupp);
}

int lowv(void)
{	
	char vlow="aaaaeeeiiiooou"[rand()%14];
	printf("%c",vlow);
	return(vlow);
}

//Function to return less random "suffixes"
//Common ways to end names so generated names look better
int suffix(int i, int j, int k, int l, int dec)
{
	FILE *fp;
	char clow, vlow;
	fp=fopen("names.txt" , "a+");
	dec=rand()%8+1;
	if (k<7)
	{	if(dec==1||dec==2)
		{	dec=rand()%8+1;
			if (dec==1||dec==2||dec==3)
			{	printf("r");
				fprintf(fp,"r");
			}
			else if (dec==4||dec==5||dec==6)
			{	clow = lowc();
				fprintf(fp,"%c",clow);
			}
			else
			{	vlow = lowv();
				fprintf(fp,"%c",vlow);
			}
		}
		else if(dec==3)
		{	clow = lowc();
			fprintf(fp,"%c",clow);
		}
		else if(dec==4)
		{	printf("s");
			fprintf(fp,"s");
		}
		else if(dec==5)
		{	printf("y");
			fprintf(fp,"y");
		}
		else if(dec==6)
		{	printf("e");
			fprintf(fp,"e");
		}
		else
		{	clow = lowc();
			fprintf(fp,"%c",clow);
		}
	}

	if (j==k-5)
	{
		if(dec==1||dec==2)
		{	printf("son");
			fprintf(fp,"son");
		}
		else if(dec==3||dec==4)
		{	printf("man");
			fprintf(fp,"man");
		}
		else if(dec==5)
		{	printf("ing");
			fprintf(fp,"ing");
		}
		else if(dec==6)
		{	printf("sky");
			fprintf(fp,"sky");
		}
		else if(dec==7||dec==8)
		{	printf("ich");
			fprintf(fp,"ich");
		}
	}
	if (j==k-4)
	{
		dec=rand()%8+1;
		if(dec==1||dec==2)
		{	printf("ez");
			fprintf(fp,"ez");
		}
		else if(dec==3||dec==4)
		{	printf("er");
			fprintf(fp,"er");
		}
		else if(dec==5)
		{	printf("ia");
			fprintf(fp,"ia");
		}
		else if(dec==6)
		{	printf("ny");
			fprintf(fp,"ny");
		}
		else if(dec==7||dec==8)
		{	printf("ov");
			fprintf(fp,"ov");
		}

	}
	fprintf(fp,"\n");
//	fclose(fp);
	return (dec);
}

//Function for user to decide name length or choose random length
int namegendeci()
{
	int i, j, k, l;
	int dec;
	char length=' ';
	dec=rand()%2+1;

	printf("\nWould you like me to determine the length of your name?");
	printf("\n[Y/N]");
	scanf("%c", &length);

	if (length=='N'||length=='n')
	{
		printf("\nHow long should your name be? ");
		scanf(" %d",&k);
		if( k>=1 && k<=65 )
			namegencalc(i, j, k, l, dec);
		else
			printf("\nRot in shreds.\n");
	}
	else if (length=='Y'||length=='y')
	{
		dec=rand()%2+1;
		if(dec==1)
		{	k=rand()%7+3;
			namegencalc(i, j, k, l, dec);
		}
		else
		{	k=rand()%5+6;
			namegencalc(i, j, k, l, dec);
		}
	}
	else
		printf("\nRot in shreds.\n");

	return 0;
}

//Function to generate name
int namegencalc(int i, int j, int k, int l, int dec)
{
FILE *fp;
if (fp!=NULL)
{
	char cupp, clow, vupp, vlow;
	int prevdec, total=0;
  fp=fopen("names.txt", "a");
	//fprintf(fp,"\n");
	printf("\n");
	
  //For names 1 character long.
	if(dec==1)
	{	cupp = uppc();
		fprintf(fp,"%c",cupp);
	}
	else
	{	vupp = uppv();
		fprintf(fp,"%c",vupp);
	}
	
  //For names 2 characters long or more.
	if(k>1)
	{	
	  // For names exactly 2 characters long.
	  if(dec==1)
		{
		 vlow = lowv();
		 fprintf(fp,"%c",vlow);
		}
		else
		{
		 clow = lowc();
		 fprintf(fp,"%c",clow);
		}
		
    //For names 3-6 characters long.
		if ( k>2 && k<7 )
		{
			for(i=4;i<=k;i++)
			{	dec=rand()%8+1;
				if(dec==1||dec==2||dec==3)
				{	vlow = lowv();
					fprintf(fp,"%c",vlow);
				}
				else
				{	clow = lowc();
					fprintf(fp,"%c",clow);
				}
			}
			suffix( i, j, k, l, dec);
		}
		
    //For names over 6 characters long.
		else if ( k>6 /*&& k<10*/ )
		{	j=rand()%2+k-5;
		
  		//For names 7-9 characters long.
			if(k<10)
			{	for(i=0;i<j;i++)
				{	dec=rand()%8+1;
					if(dec==1||dec==2||dec==3)
					{	vlow = lowv();
						fprintf(fp,"%c",vlow);
					}
					else
					{	clow = lowc();
						fprintf(fp,"%c",clow);
					}
				}
			}
			
      //For names over 10 characters long.
			if(k>9)
			{	for(i=0;i<j;i++)
				{	if(total != 3 && total !=6 /*&& total >= 7 && total  !=8 && total != 9*/)
					{	dec=rand()%2+1;
						if(dec==1)
						{	vlow = lowv();
							fprintf(fp,"%c",vlow);
						}
						else if(dec==2/*||dec==3*/)
						{	clow = lowc();
							fprintf(fp,"%c",clow);
						}
						total=total+dec;
							if (total>6)
								total = 0;
					}
					else
					{	if(total==3)
						{	clow = lowc();
							fprintf(fp,"%c",clow);
							total = 0;
						}
						else if(total==6)
						{	vlow = lowv();
							fprintf(fp,"%c",vlow);
							total = 0;
						}
					}
				}
			}
      //Endings for names over 7 characters long.
			suffix(i, j, k, l, dec);
		}
	}
  //	fprintf(fp,"\n");
	printf("\n\nYou're Welcome.\n");
	fclose(fp);
}
else
	printf("\nRot in shreds.\n");

	return 0;
}
