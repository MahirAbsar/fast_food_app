#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "items_price.h"    /**library that stores prices for all items**/

int print_menu (void);
int burger_subtype(void);
void burger_subtype_choice(void);
int  fries_subtype(void);
void fries_subtype_choice(void);
int tacos_subtype(void);
void tacos_subtype_choice(void);
int chicken_subtype (void);
void chicken_subtype_choice(void);
int desert_subtype(void);
void desert_subtype_choice(void);
int misc_subtype (void);
void misc_subtype_choice(void);
void order();
int amount_choice(char[],int,float );
void store_in_file (char[],int,float);
void print_bill();
int check_password (const char[],char[]);
void review(void);

/** In this c program a person can either log in as an employee or a customer.
 An employee has to enter a password which will open a file with
staff information if correct. If incorrect he can try again or log in as a customer.
If logged in as a customer the program takes order,prints bill and takes review while
logging in incorrectly will mean to log in again**/

int main ()
{
    FILE* fp;
    int num,check;
    char ans,ch,in_pass[50]= {0};
    char password[50] = "MJ1331";
logIN:
    printf ("LOG IN AS......\n\n");
    printf ("\t\t\t1.Staff Member\n");
    printf ("\t\t\t2.Customer\n\n");
    printf ("I want to have access as......");
    scanf ("%d",&num);
    switch (num)
    {
    case 1:
again:
        printf ("Enter Password:");
        fflush(stdin);
        gets (in_pass);
        check = check_password (password,in_pass);
        if (check ==1)
        {
            fp = fopen ("staff_info.txt","r");
            while (ch!=EOF)
            {
                ch = fgetc(fp);
                putchar (ch);
            }
            fclose (fp);
        }
        else
        {
            printf ("INVALID!!!!!!\n");
            printf ("Do You want to log in as a Customer?(y/n)");
            scanf ("%c",&ans);
            if (ans=='Y' || ans == 'y')
                goto CUSTOMERlogin;
            else
                goto again;
        }
        break;
    case 2:

CUSTOMERlogin:
        order();
        break;
    default:
        printf ("Invalid Number!!!!!\n\n");
        goto logIN;
        break;
    }
}


/**Checks if the typed password matches with the one that is set**/


int check_password(const char valid_pass[],char user_pass[])
{
    int i,flag=0;
    for(i=0; i<strlen(valid_pass); i++)
    {
        if(user_pass[i]!=valid_pass[i])
        {
            flag=0;
            break;
        }
        else
        {
            flag = 1;
            continue;
        }

    }
    return flag;
}


/**Prints out the bill and takes review from the customer after the order is taken**/

void order ()
{
    int choice,choiceB,choiceF,choiceC,choiceT,choiceD,choiceM;
    char answer;
    float SUM=0;
    int marks=0;

    printf ("\n\t\t\t\t WELCOME TO 5*****S STALL\n\n");
    printf ("\n\n\t\t\t\t\tM   E   N   U\n\n");
    while (1)
    {
menu:
        choice = print_menu();
        switch (choice)
        {
        case 1:
            printf ("You Selected BURGERS\n\n");
            choiceB = burger_subtype();
            burger_subtype_choice();
            break;
        case 2:
            printf ("You Selected FRIES\n\n");
            choiceF = fries_subtype();
            fries_subtype_choice();
            break;
        case 3:
            printf ("You Selected CHICKEN\n\n");
            choiceC = chicken_subtype();
            chicken_subtype_choice();
            break;
        case 4:
            printf ("You Selected TACOS\n\n");
            choiceT = tacos_subtype();
            tacos_subtype_choice();
            break;
        case 5:
            printf ("You Selected DESERTS\n\n");
            choiceD = desert_subtype();
            desert_subtype_choice();
            break;
        case 6:
            printf ("You Selected MISC\n\n");
            choiceM = misc_subtype();
            misc_subtype_choice();
            break;
        default:
            printf ("Do You want to recheck our menu?(y\\n):\n");
            scanf ("%s",&answer);
            if (answer == 'y' || answer == 'Y' )
                goto menu;
            else
            {
                print_bill();
                review ();
                printf ("\t\t\t\t\t!!!!!!THANK YOU!!!!!!\n");
                printf ("\t\t\t\t\tPlease Visit Us Again!!!!!!\n\n");
                return;
            }

        }
    }

}
/**Shows the main food categories as a menu and
takes the customer's choice among those**/


int print_menu ()
{
    int ch;
    printf ("\t\t\t\t\t 1.BURGER\n");
    printf ("\t\t\t\t\t 2.FRIES\n");
    printf ("\t\t\t\t\t 3.CHICKEN\n");
    printf ("\t\t\t\t\t 4.TACOS\n");
    printf ("\t\t\t\t\t 5.DESERTS\n");
    printf ("\t\t\t\t\t 6.MISC\n");
    printf ("\nWHAT DO YOU WANT TO HAVE TODAY?\n");
    scanf ("%d",&ch);
    return ch;
}

/**Prints out the subtypes of burger with the price and takes the customer's order**/


int burger_subtype(void)
{

    int chB;
    printf ("\t\t\tType\t\t\t\tPrice(TK)\n");
    printf ("\n\t\t\t1.Cheese Burger\t\t\t160\n");
    printf ("\t\t\t2.Veg Burger\t\t\t200\n");
    printf ("\t\t\t3.Beef Burger\t\t\t250\n");
    printf ("\nWhich One Would You Love to Have?\n");
    scanf ("%d",&chB);
    return chB;

}

/** Notes down the type and quantity of the burger that the customer wants, gets the total and stores information**/


void burger_subtype_choice()
{
    int choiceB,quan;
    char str[50];
    float total;

    switch (choiceB)
    {
    case 1:
        printf ("You Selected Cheese Burger\n\n");
        strcpy (str,"Cheese Burger");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_CBUR);
        store_in_file (str,quan,total);
        break;
    case 2:
        printf ("You Selected Veg Burger\n\n");
        strcpy (str,"Veg Burger");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_VBUR);
        store_in_file (str,quan,total);
        break;
    case 3:
        printf ("You Selected Beef Burger\n\n");
        strcpy (str,"Beef Burger");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_BBUR);
        store_in_file (str,quan,total);
        break;
    default:
        printf ("I don't want Burgers\n\n");
        break;

    }

}

/**Prints out the subtypes of fries with the price and takes the customer's order**/


int fries_subtype(void)
{

    int chF;
    printf ("\t\t\tType\t\t\t\tPrice(TK)\n");
    printf ("\n\t\t\t1.Waffle Fries\t\t\t160\n");
    printf ("\t\t\t2.Curly Fries\t\t\t200\n");
    printf ("\t\t\t3.Cajun Fries\t\t\t250\n");
    printf ("\nWhich One Would You Love to Have?\n");
    scanf ("%d",&chF);
    return chF;

}


/** Notes down the type and quantity of the fries that the customer wants, gets the total and stores information**/


void fries_subtype_choice()
{
    int choiceF,quan;
    float total;
    char str[50];
    switch (choiceF)
    {
    case 1:
        printf ("You Selected Waffle Fries\n\n");
        strcpy (str,"Waffle Fries");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_WFRI);
        store_in_file (str,quan,total);
        break;
    case 2:
        printf ("You Selected Curly Fries\n\n");
        strcpy (str,"Curly Fries");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_CFRI);
        store_in_file (str,quan,total);
        break;
    case 3:
        printf ("You Selected Cajun Fries\n\n");
        strcpy (str,"Cajun Fries");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_CAFRI);
        store_in_file (str,quan,total);
        break;
    default:
        printf ("I don't want Fries\n\n");
        break;

    }

}


/**Prints out the subtypes of chicken with the price and takes the customer's order**/


int chicken_subtype(void)
{
    int chC;
    printf ("\t\t\tType\t\t\t\tPrice(TK)\n");
    printf ("\n\t\t\t1.Chicken Fingers\t\t90\n");
    printf ("\t\t\t2.Chicken Nuggets\t\t280\n");
    printf ("\t\t\t3.Chicken Tenders\t\t570\n");
    printf ("\nWhich One Would You Love to Have?\n");
    scanf ("%d",&chC);
    return chC;
}


/** Notes down the type and quantity of the chicken that the customer wants, gets the total and stores information**/


void chicken_subtype_choice()
{
    int choiceC,quan;
    float total;
    char str[50];
    switch (choiceC)
    {
    case 1:
        printf ("You Selected Chicken Fingers\n\n");
        strcpy (str,"Chicken Fingers");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_CFIN);
        store_in_file (str,quan,total);
        break;
    case 2:
        printf ("You Selected Chicken Nuggets\n\n");
        strcpy (str,"Chicken Nuggets");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_CNUG);
        store_in_file (str,quan,total);
        break;
    case 3:
        printf ("You Selected Chicken Tenders\n\n");
        strcpy (str,"Chicken Tenders");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_CTEN);
        store_in_file (str,quan,total);
        break;
    default:
        printf ("I will try something else\n\n");
        break;

    }

}


/** Notes down the type and quantity of the tacos that the customer wants, gets the total and stores information**/


int tacos_subtype(void)
{
    int chT;
    printf ("\t\t\tType\t\t\t\tPrice(TK)\n");
    printf ("\n\t\t\t1.Asada Tacos\t\t\t90\n");
    printf ("\t\t\t2.Chorizo Tacos\t\t\t250\n");
    printf ("\t\t\t3.Soft Tacos\t\t\t650\n");
    printf ("\nWhich One Would You Love to Have?\n");
    scanf ("%d",&chT);
    return chT;
}


/** Notes down the type and quantity of the tacos that the customer wants**/


void tacos_subtype_choice()
{
    int choiceT,quan;
    float total;
    char str[50];
    switch (choiceT)
    {
    case 1:
        printf ("You Selected Asada Tacos\n\n");
        strcpy (str,"Asada Tacos");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_AST);
        store_in_file (str,quan,total);
        break;
    case 2:
        printf ("You Selected Chorizo Tacos\n\n");
        strcpy (str,"Chorizo Tacos");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_CZT);
        store_in_file (str,quan,total);
        break;
    case 3:
        printf ("You Selected Soft Tacos\n\n");
        strcpy (str,"Soft Tacos");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_ST);
        store_in_file (str,quan,total);
        break;
    default:
        printf ("I will try something else\n\n");
        break;
    }

}


/**Prints out the subtypes of desert with the price and takes the customer's order**/


int desert_subtype(void)
{
    int chD;
    printf ("\t\t\tType\t\t\t\tPrice(TK)\n");
    printf ("\n\t\t\t1.Choco Brownie\t\t\t160\n");
    printf ("\t\t\t2.Cream Roll\t\t\t250\n");
    printf ("\t\t\t3.Frozen Parfait\t\t500\n");
    printf ("\nWhich One Would You Love to Have?\n");
    scanf ("%d",&chD);
    return chD;
}


/** Notes down the type and quantity of the desert that the customer wants, gets the total and stores information**/


void desert_subtype_choice(void)
{
    int choiceD,quan;
    float total;
    char str[50];
    switch (choiceD)
    {
    case 1:
        printf ("You Selected Choco Brownie \n\n");
        strcpy (str,"Choco Brownie");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_CB);
        store_in_file (str,quan,total);
        break;
    case 2:
        printf ("You Selected Cream Roll\n\n");
        strcpy (str,"Cream Roll");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_CR);
        store_in_file (str,quan,total);
        break;
    case 3:
        printf ("You Selected Frozen Parfait\n\n");
        strcpy (str,"Frozen Parfait");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_FP);
        store_in_file (str,quan,total);
        break;
    default:
        printf ("I will try something else\n\n");
        break;
    }

}


/**Prints out the subtypes of misc with the price and takes the customer's order**/


int misc_subtype(void)
{
    int chM;
    printf ("\t\t\tType\t\t\t\tPrice(TK)\n");
    printf ("\n\t\t\t1.Tortilla Chips\t\t320\n");
    printf ("\t\t\t2.Cheese Curds\t\t\t350\n");
    printf ("\t\t\t3.Potato Wedges\t\t\t380\n");
    printf ("\nWhich One Would You Love to Have?\n");
    scanf ("%d",&chM);
    return chM;
}


/** Notes down the type and quantity of the misc that the customer wants, gets the total and stores information**/


void misc_subtype_choice(void)
{
    int choiceM,quan;
    float total;
    char str[50];
    switch (choiceM)
    {
    case 1:
        printf ("You Selected Tortilla Chips\n\n");
        strcpy (str,"Tortilla Chips");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_TC);
        store_in_file (str,quan,total);
        break;
    case 2:
        printf ("You Selected Cheese Curds\n\n");
        strcpy (str,"Cheese Curds");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_CCUR);
        store_in_file (str,quan,total);
        break;
    case 3:
        printf ("You Selected Potato Wedges\n\n");
        strcpy (str,"Potato Wedges");
        printf ("How Many Do You Want?\n");
        scanf ("%d",&quan);
        total = amount_choice (str,quan,PRICE_PW);
        store_in_file (str,quan,total);
        break;
    default:
        printf ("I will try something else\n\n");
        break;
    }

}


/** Calculates the total price for each item separately and appends it to a file named price.txt**/


int amount_choice (char name[],int val,float price)
{
    FILE* fp;
    float total=0;
    fp = fopen ("PRICE.txt","a+");
    total =  val * price;
    fprintf (fp,"%.2f\n",total);
    fclose (fp);
    return total;
}


/** Stores the name,quantity and total price of the items ordered in a file named bill.txt**/


void store_in_file (char name[],int val, float amount)
{
    FILE* fp;
    char str[20]="bill.txt";
    float total=0;
    fp = fopen ("bill.txt","a");
    fprintf (fp,"%s\t\t\t\t%d\t\t\t\t%.2f\n",name,val,amount);
    fclose (fp);

}


/**calculates the total price and prints the bill**/


void print_bill(void)
{
    FILE* fp;
    FILE* fp2;
    float total,price,sum;
    char ch;
    int fileClose_bill=0,fileClose_PRICE=0;
    fp = fopen ("bill.txt","r");
    printf ("\n\t\t\t\t  PAYMENT SCRIPT\n\n\n\n");
    printf ("ORDERED\t\t\t\t     QUANTITY\t\t\t\tPRICE\n");
    printf ("\n");
    while (ch!=EOF)
    {
        ch = fgetc (fp);
        putchar(ch);
    }
    fclose (fp);
    fileClose_bill = remove ("bill.txt");
    fp2 = fopen ("PRICE.txt","r");
    sum = 0;
    while (!feof (fp2))
    {
        fscanf (fp2,"%f\n",&price);
        sum+=price;
    }
    fclose (fp2);
    fileClose_PRICE = remove ("PRICE.txt");
    printf ("\n\t\t\t\t\t\t\t\t  TOTAL %.2f\n\n\n",sum);

}


/**Takes review from customer**/


void review(void)
{
    int ratings=0;
    rate:
    printf ("\n\n\nKindly Rate Our Food on the Scale of 1-5\n\n");
    scanf ("%d",&ratings);
    switch (ratings)
    {
    case 1:
        printf("\tT E R R I B L E\n\n");
        break;
    case 2:
        printf("\tP O O R\n\n");
        break;

    case 3:
        printf("\tO K A Y\n\n");
        break;
    case 4:
        printf("\tG O O D\n\n");
        break;
    case 5:
        printf("\tE X C E L L E N T\n\n");
        break;
    default:
        printf ("\tPlease Check The Range Again\n\n");
        goto rate;
        break;
    }

}





