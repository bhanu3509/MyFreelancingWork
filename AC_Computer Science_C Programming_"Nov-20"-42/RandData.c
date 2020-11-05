#include<stdio.h>
#include<stdlib.h>

int seedInput()
{
	int seedValue;
	printf("Enter seed value -> ");
	scanf("%d",&seedValue);
	//loop until valid input is not given
	while(seedValue <=0)
	{
		printf("Error! Seed must be a positive value!");
		printf("\n\nEnter seed value -> ");
		scanf("%d",&seedValue);
	}
return seedValue;
}

int dataSizeInput()
{
	int dataSetSize;
	printf("Enter data set size to generate -> ");
	scanf("%d",&dataSetSize);
	//loop until valid input is not given
	while(dataSetSize <=0)
	{
		printf("\nError! Minimum data set size is one!");
		printf("\n\nEnter data set size to generate -> ");
		scanf("%d",&dataSetSize);
	}
return dataSetSize;
}

void displayValuesNotInTheDataSet(int counterArray[101])
{
	int counter = 0;
	//Print the output now.
	printf("Values not present in data set : ");
	for(int i=1;i<=100;i++)
	{
		if(counterArray[i]==0)
		{
			printf("%d ",i);
			counterArray[i] = 0;
			counter++;
		}
	}
	if(counter == 0)
	{
		printf("None");
	}
	printf("\n");
}

void displayValuesPresentInDataSetAtleastTruncateTimes(int counterArray[101],int truncateRemainder)
{	
	int counter = 0;
	printf("Values present at least %d times in data set : ",truncateRemainder);
	for(int i=1;i<=100;i++)
	{
		if(counterArray[i] >= truncateRemainder)
		{
			printf("%d ",i);
			counter++;
		}
	}
	if(counter == 0)
	{
		printf("None");
	}
	printf("\n");
}

int calculateTruncateRemainder(int dataSetSize)
{
	//initialise the truncate Remainder variable and find it's value.
	//it is 2.5% of dataSetSize.
	int truncateRemainder = (2.5 * dataSetSize)/100;
return truncateRemainder;
}

int main()
{
	int seedValue, dataSetSize;
	//take input for the seed value 
	seedValue = seedInput();
	//take input for dataSetSize that is to be generated
	dataSetSize = dataSizeInput();
	//initialising an array to store the generated ranodm numbers.
	int dataSet[dataSetSize];
	
	srand(seedValue);
	for(int i=0;i<dataSetSize;i++)
	{
		//we want the numbers in the range 1 to 100
		//so we get modulo 100
		dataSet[i] = rand()%100+1;
	}
	//Initialise counter Array 
	int counterArray[101];
	for(int i=0;i<101;i++)
	{
		//initialise the counterArray to zero.
		counterArray[i] = 0;
	}
	
	for(int i=0;i<dataSetSize;i++)
	{
		//incerement the counterArray by iterating 
		//the dataSet values.
		counterArray[dataSet[i]]++;
	}
	
	displayValuesNotInTheDataSet(counterArray);	
	int truncateRemainder = calculateTruncateRemainder(dataSetSize);
	displayValuesPresentInDataSetAtleastTruncateTimes(counterArray, truncateRemainder);
return 0;	
}
