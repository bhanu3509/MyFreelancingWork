#include<stdio.h>
#include<stdlib.h>

int main(){
    // Menu driven program to select a planet
    printf("Select a Planet\n");
    printf("1. Mercury\n");
    printf("2. Venus\n");
    printf("3. Earth\n");
    printf("4. Mars\n");
    printf("5. Exit the program\n\n");
    printf("Enter your selection.\n");
    int choice = 0;
    // scanf("%d",&choice);
    while(choice!=5)
    {
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            /* code */
            printf("Average distance form the sun : 57.9 million kilometers\n");
            printf("Mass : 3.31 x 10^23kg\n");
            printf("Surface temperature : -173to430 degrees Celsius\n");
            break;
        case 2:
            /* code */
            printf("Average distance form the sun : 108.2 million kilometers\n");
            printf("Mass : 4.87 x 10^24kg\n");
            printf("Surface temperature : 472 degrees Celsius\n");
            break;
        case 3:
            /* code */
            printf("Average distance form the sun : 149.6 million kilometers\n");
            printf("Mass : 5.967 x 10^24kg\n");
            printf("Surface temperature : -50 to 50 degrees Celsius\n");
            break;
        case 4:
            /* code */
            printf("Average distance form the sun : 227.9 million kilometers\n");
            printf("Mass : 0.6424 x 10^24kg\n");
            printf("Surface temperature : -140 to 20 degrees Celsius\n");
            break;
        case 5:
            /* code */
            fflush(stdin);
            exit(choice);
            break;
        
        default:
            break;
        }
    }
}