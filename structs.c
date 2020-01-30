#include<stdio.h>
#include<stdlib.h>
#include<curses.h>

int main()
{
    typedef struct
    {
        char name[20];
        int regNum;
        int vatNum;
        float sales[12];
    }company_t;
    
    
	FILE* outFile;
    int numCompanies;

    printf("How many companies do you wish to input?");
    scanf("%d", &numCompanies);
    company_t company[numCompanies];

	//1. Open the file.
	outFile = fopen("CompanyDetails.txt", "a");

    /* FILE HEADER IF NEEDED
    fprintf(outFile,"%-20s%-8s%-8s","Company Name","Reg","VAT");
    for(int i;i<12;i++)
    {
        fprintf(outFile,"%-2s%-6d", "Wk",(i+1));
    }
    fprintf(outFile,"\n");*/

	//2. Check the file is opened.
	if (outFile == NULL)
	{
		printf("Sorry the file could not be opened\n");
	}

	else
	{
		//while (feof(inputfile) == false)
		for (int i = 0; i < numCompanies; i++)
        {
            printf("Please Enter Company Name, Registration Number, Vat Number of company\n");
            scanf(" %s%d%d", company[i].name, &company[i].regNum, &company[i].vatNum);
            fprintf(outFile," %-20s%-8d%-8d", company[i].name, company[i].regNum, company[i].vatNum);
            printf("Please enter sales history for company for the past 12 months format 1.11 2.22 3.33 4.44...\n");
            for(int j=0;j<12;j++)
            {
                scanf(" %f", &company[i].sales[j]);
                fprintf(outFile," %-8.2f", company[i].sales[j]);
            } 
            fprintf(outFile,"\n");
        }
		//Close the file only when finished reading...
		fclose(outFile);
	}
    return 0;
}

