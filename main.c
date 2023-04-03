#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>

// Sign Up
int signUp()
{
    FILE *fp;
    fp = fopen("account.txt", "r"); // fopen untuk membuka file
    char username[100], password[100], words[100];
reinputSignUp:
    fflush(stdin); // fflush(stdin) untuk membersihkan cache
    printf("Please Input Your Username Without Space!\n");
    printf("Input Username: ");
    scanf("%s", username);
    fflush(stdin);
    printf("Input Password: ");
    scanf("%s", password);
    while (!feof(fp))
    {
        fscanf(fp, "%s", words);             // fscanf untuk membaca isi file
        if (strcmp(words, "Username:") == 0) // strcmp untuk mengcompare isi dalam file
        {
            fscanf(fp, "%s", words);
            if (strcmp(words, username) == 0)
            {
                printf("Your Username Already Exist, Please Input Your Username Again!\n\n");
                goto reinputSignUp;
            }
        }
    }
    fclose(fp); // fclose untuk menutup file yang telah dibuka
    fp = fopen("account.txt", "a+");
    fprintf(fp, "\nUsername: %s\nPassword: %s", username, password);
    fclose(fp);
    return 0;
}

// Login
struct Account
{
    char username[20];
    char password[20];
};

struct System
{
    char choice;
    _Bool validation;
    bool isValid;
};

bool userValidation(char *user, char *pass)
{
    char words[100];
    FILE *fp = fopen("account.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%s", words);
        if (strcmp(words, "Username:") == 0)
        {
            fscanf(fp, "%s", words);
            if (strcmp(words, user) == 0)
            {
                fscanf(fp, "%s", words);
                if (strcmp(words, "Password:") == 0)
                {
                    fscanf(fp, "%s", words);
                    if (strcmp(words, pass) == 0)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }
    return false;
}

// BMI Calculate
int bmiCalculate()
{
    float height, weight, bmi;

    printf("Input Your Height(CM): ");
    scanf("%f", &height);

    printf("Input Your Weight(KG): ");
    scanf("%f", &weight);

    height = height / 100;
    bmi = weight / (height * height);
    printf("\n");
    printf("---------------------------------------------------------------\n");
    printf("-------------------- Result And Some Tips ---------------------\n");
    printf("---------------------------------------------------------------\n");
    printf("The Result of Your BMI Calculation is: %.0f", bmi);

    if (bmi < 18.5)
    {
        printf("\nYou Are in The Underweight Range\n");
        printf("\nSome Tips For You:\n");
        printf("Increasing Your Intake of Foods Containing Protein and Carbohydrates is Very Good For Increasing Your Weight\n");
        printf("Eat Foods That Contain Carbohydrates and Protein Such as Bread, Rice, Fish, Meat, Tempe, and Tofu More Than Usual\n\n");
        printf("Press Any Key!");
        getch();
    }
    else if (bmi < 25)
    {
        printf("\nYou Are in The Ideal Range\n");
        printf("\nSome Tips For You:\n");
        printf("Consume Enough Vegetables and Fruits, Reduce Fast Food, Reduce Calorie Intake, and Do Exercise Regularly\n\n");
        printf("Press Any Key!");
        getch();
    }
    else if (bmi < 30)
    {
        printf("\nYou Are in The Overweight Range\n");
        printf("\nSome Tips For You:\n");
        printf("You Need to Avoid High Calorie Foods, Change Your Diet and Lifestyle\n\n");
        printf("Press Any Key!");
        getch();
    }
    else if (bmi > 30)
    {
        printf("\nYou Are in The Obese Range\n");
        printf("\nSome Tips For You:\n");
        printf("The Main Key in Losing Fat in Your Body and Reducing Your Weight is Consistency\n");
        printf("You Need to Change Your Lifestyle and Reduce Your Calorie Intake Gradually\n");
        printf("Choose Foods That are High in Fiber so You Don't Get Hungry Easily, Auch as Oats, Pasta From Wheat, or Brown Rice");
        printf("Reduce Eating Foods That Contain High Calories Such as Fast Food and Foods That Contain High Sugar\n\n");
        printf("Press Any Key!");
        getch();
    }
    return 0;
}

// Menu
int main()
{
    char username[100], password[100], words[100];
    struct Account acc;
    struct System Sys;
    system("cls");
    printf("\n--------------- Welcome To Program BMI Counting ---------------\n");
reinput:
    fflush(stdin);
    printf("---------------------------------------------------------------\n");
    printf("------------------------ Menu Account -------------------------\n");
    printf("---------------------------------------------------------------\n");
    printf("1.Sign Up\n2.Login\n3.Logout\n");
    printf("Select Menu Account: ");
    scanf("%c", &Sys.choice);
    switch (Sys.choice)
    {
    case '1':
        system("cls");
        printf("---------------------------------------------\n");
        printf("------------------ Sign Up ------------------\n");
        printf("---------------------------------------------\n");
        signUp();
        printf("Your Account Has Been Created!\n\n");
        break;
    case '2':
        system("cls");
        printf("---------------------------------------------\n");
        printf("------------------- Login -------------------\n");
        printf("---------------------------------------------\n");
        printf("Username: ");
        scanf("%s", acc.username);
        printf("Password: ");
        scanf("%s", acc.password);
        Sys.validation = userValidation(acc.username, acc.password);
        if (Sys.validation == true)
        {
            printf("Login Success, Welcome %s\n\n", acc.username);
        }
        else
        {
            printf("Login Failed!\n");
            printf("Username or Password is Wrong!\n\n");
            goto reinput;
        }
        break;
    case '3':
        printf("\n");
        printf("Thank You For Using Our Program");
        goto logout;
        break;
    default:
        printf("The Input What You Entered is Wrong!\n");
        printf("Choose One of The Three Existing Menu!\n\n");
        goto reinput;
    }
    bmiCalculate();
    goto reinput;
logout:
    return 0;
}
