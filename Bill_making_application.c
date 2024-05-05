/*
You're tasked with creating a simple bill-making application for a small business. 
The application should take inputs such as item names, quantities , and prices and generate a bill for the customer.
Write a C program that prompts the user to enter details for each item purchased (names, quantity, price), calculates the total cost, including tax if applicable, and prints out a formatted bill for the customer. 
*/
#include <stdio.h>
#include<stdlib.h>
void main()
{
    system("cls");
    char flag;
    char items[100][20];
    int quantities[100];
    float prices[100];
    float taxes[100];
    double totals[100];
    double total_inc_tax[100];
    int i=0;
        
    double final_payable_amt=0.0;
        
    do
    {
        char item[20];
        int quantity=0;
        float price=0.0;
        float tax=0.0;

        printf("Enter item name : ");
        scanf("%s",item);
        strcpy(items[i],item);
        printf("Enter Quantity : ");
        scanf("%d",&quantity);
        quantities[i]=quantity;
        printf("Enter prices : ");
        scanf("%f",&price);
        prices[i]=price;
        printf("Enter tax (if there is no tax then enter 0 ): ");
        scanf("%f",&tax);
        taxes[i]=tax;

        getchar();
        double total= quantity * price;
        totals[i]=total;
        total_inc_tax[i]=(total+total*(tax/100));
        final_payable_amt+=total_inc_tax[i];
        printf("Total = %f\n",total);
        printf("Press ' ' to end or Press any other key to continue ...");
        flag=getchar();
        i++;
    } while (flag!=' ');
    
    system("cls");
    printf("************************\tBILL\t************************\n");
    printf("Item\tQuantity\tPrice\t\tTax\t\tTotal(of each)\t\tTotal(inc. tax for each)\n");
    for(int j=0; j<i; j++)
    {
        printf("%s\t%d\t\t%.2f\t\t%.2f\t\t%.3lf\t\t\t%.3lf\n",items[j],quantities[j],prices[j],taxes[j],totals[j],total_inc_tax[j]);
    }
    printf("\nFinal Payable Amount : %.2lf",final_payable_amt);
}