// Welcome to the Banking Management System
/*Header Files Inclusion Section*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// Functions Declaration Section
void ContinuetoMainMenu(void);
void Discontinue(void);
void Services(void);
int OpeningAccount(void);
void SavingAccount(char *, int, int, int);
void CurrentAccount(char *, int, int, int, int);
void ATMpinGeneration(int, int, int);
void WithDrawMoney(int,int,int);
void InterestCalculator(double, double, double);
void ReceiptPrintout();
void BankStatement(char*);
void Schemes(int, int);
int Eligibility(int, int);
void MoneyDeposit(char*,char*);
void HelpCenter(int);

/*Main Menu*/
void main()
{
  /*kickstarts the program*/
LoginProcedure:
  printf("******************************Welcome to Banking Management System**********************\n");
  printf("1.Login\n2.Signup\n3.Exit\n");
  int option;
  printf("Enter::");
  scanf("%d", &option);
  struct User
  {
    char username[50];
    char password[50];
  };
  switch (option)
  {
  case 1:/*Login Panel*/
    printf("---------------------------------------------\n");
    printf("Welcome to Login Panel\n");
    char username[100], password[100];
    printf("Enter Your Username:");
    scanf("%s", &username);
    printf("Enter Your Password:");
    scanf("%s", &password);
    printf("You Entered Following Username:%s Password: %s\n", username, password);
    struct User fetchuser;
    FILE *fetchinguserdetails = fopen("Usernameandpasswords.txt", "r");
    if (fetchinguserdetails == NULL)
    {
      printf("No User registered yet\n");
      goto LoginProcedure;
      return;
    }
    else
    {
      // while (fscanf(fetchinguserdetails, "%s %s", fetchuser.username, fetchuser.password) != EOF)
      while(fread(&fetchuser,sizeof(fetchuser),1,fetchinguserdetails)==1)
      {
        if (strcmp(fetchuser.username, username) == 0)
        {
          printf("Your Username Checking......\n");
          printf("Your Username is matched :)\n");
          if (strcmp(fetchuser.password, password) == 0)
          {
            printf("Your Password Checking......\n");
            printf("Your Password is matched:)\n");
            printf("Username:%s is logged Successfully\n",fetchuser.username);
            ContinuetoMainMenu();
            return;
          }
        }
        else
        {
          printf("Your Details are not matched with our data :(\n");
          goto LoginProcedure;
          return;
        }
      };
    };
    break;
  case 2:/*Sign Up Panel*/
  printf("---------------------------------------------\n");
    printf("Welcome to SignUp Panel\n");
    struct User user;
    FILE *Users;
    Users = fopen("Usernameandpasswords.txt", "a");
    printf("Set Your username and Password\n");
    printf("Set Your Username:");
    scanf("%s", &user.username);
    printf("Set Your Password:");
    scanf("%s", &user.password);
    if (Users == NULL)
    {
      printf("Something went wrong");
    }
    else
    {
      fwrite(&user,sizeof(user),1,Users);
      fclose(Users);
    }
    printf("You're Signup Successfully\nYour Username & password is Saved.\nNow use them for login\n");
    goto LoginProcedure;
    break;
  case 3:/*Existing Program*/
    Discontinue();
    break;
  default:
    break;
  }
};
/*Main Menu for all the Operations*/
void ContinuetoMainMenu(void)
{
  printf("---------------------------------------------\n");
  printf("Welcome to the Main Menu \n");
  printf("Enter-1:To Know about Our Services \n");
  printf("Enter-2:To Open Bank Account with Us.\n");
  printf("Enter-3:To Generate ATM Pin \n");
  printf("Enter-4:To Calculate Interest\n");
  printf("Enter-5:To Make a Deposit\n");
  printf("Enter-6:To Withdraw Money Using ATM(Debit Card)or Credit Card\n");
  printf("Enter-7:To Print Transaction Receipt \n");
  printf("Enter-8:To Know about Our Schemes for Different Income Groups \n");
  printf("Enter-9:To See Bank Statements \n");
  printf("Enter-10:Help Center\n");
  printf("Enter-11:Exit\n");
  int option;
  printf("Enter Your Choice over Here:");
  scanf("%d", &option);
  switch (option)
  {
  case 1:/*For knowing about services*/
    printf("Your Choice is Procceded :)\n");
    Services();
    break;
  case 2:/*for opening bank accounts*/
    printf("Your Choice is Procceded :) \n");
    OpeningAccount();
    break;
  case 3:/*Generation of ATM PIN*/
    printf("Your Choice is Procceded :) \n");
    printf("---------------------------------------------\n");
    int AccountNumber, MobileNumber, CardNumber;
    printf("Enter Your Account Number:");
    scanf("%d", &AccountNumber);
    printf("Enter Your Mobile Number:");
    scanf("%d", &MobileNumber);
    printf("Enter the Card Number:");
    scanf("%d", &CardNumber);
    ATMpinGeneration(AccountNumber, MobileNumber, CardNumber);
    break;
  case 4:/*For Interest Calculation*/
    printf("Your Choice is Procceded :) \n");
    printf("---------------------------------------------\n");
    double amt, rate, time;
    printf("Enter Your  Principle Amount:");
    scanf("%lf", &amt);
    printf("Enter Your  Rate of Interest:");
    scanf("%lf", &rate);
    printf("Enter Your Time Duration:");
    scanf("%lf", &time);
    InterestCalculator(amt, rate, time);
    break;
  case 5:/*For Money Deposit*/
    printf("Your Choice is Procceded :) \n");
    printf("---------------------------------------------\n");
    char AccountNum[15], Amount[15];
    printf("Enter Your Account Number:");
    scanf("%s",&AccountNum);
    printf("Enter Your Amount:");
    scanf("%s",&Amount);
    MoneyDeposit(AccountNum,Amount);
    break;
  
  case 6:/*For Withdraw of Money Using Cards*/
  printf("Your Choice is Procceded :) \n");
    printf("---------------------------------------------\n");
    int AccountHolderNumber;
    int WithdrawAmount,ATMPIN;
    printf("Enter Account Number:");
    scanf("%d",&AccountHolderNumber);
    printf("Enter the Amount:");
    scanf("%d",&Amount);
    printf("Enter the ATM (Four Digit Pin):");
    scanf("%d",&ATMPIN);
    WithDrawMoney(AccountHolderNumber,WithdrawAmount,ATMPIN);
  case 7:/*Reciept Printout*/
  printf("Your Choice is Procceded :) \n");
  ReceiptPrintout();
    break;
  case 8:/*For Special Schemes*/
    printf("Your Choice is Procceded :) \n");
    printf("---------------------------------------------\n");
    int AcNumber, Income;
    printf("Enter Your Account Number:");
    scanf("%d", &AcNumber);
    printf("Enter Your Annual Income:");
    scanf("%d", &Income);
    Schemes(AcNumber, Income);
    break;
  case 9:/*For Bank Statements*/
    printf("Your Choice is Procceded :) \n");
    printf("---------------------------------------------\n");
    char AcNum[15];
    printf("Enter Your Account Number:");
    scanf("%s",&AcNum);
    BankStatement(AcNum);
    break;
  case 10:/*For Help Center*/
    printf("Your Choice is Procceded :) \n");
    printf("---------------------------------------------\n");
    printf("1.Saving Account with High Interest rate than Competitors\n");
    printf("2.Current Account with Low Interesr rate Charges\n");
    printf("3.No Limit Credit Cards\n");
    printf("4.Special Interest Calculator for Simple and Compound Effect\n");
    printf("5.Generation of ATM PIN With Unique Proccedure\n");
    printf("6.Loan At Easy Installments\n");
    printf("7.All Kinds of Loan at reasonable Interest rates\n");
    printf("8.Bank Statement at One click\n");
    printf("9.Special Interest rates for Low Income Group\n");
    printf("10.24X7 Customer Care Service\n");
    int choice;
    printf("Enter Help No:");
    scanf("%d",&choice);
    HelpCenter(choice);
    break;
  case 11:/*For Existing Program*/
    printf("Your Choice is Procceded :) \n");
    printf("---------------------------------------------\n");
    printf("Thanks for Using Our Services :)\n");
    Discontinue();
    exit(0); 
  default:
    break;
  }
};
/*Discontinuing by user Initially*/
void Discontinue()
{
  printf("---------------------------------------------\n");
  printf("What Makes You to Discontinue?\n");
  char CustomerName[50];
  printf("Provide Your Name and Feedback Without Spacing\n");
  printf("Enter Your Good Name:");
  scanf("%s", &CustomerName);
  printf("Please Give us Feedback:");
  char feedback[100];
  scanf("%s", &feedback);
  printf("Your Feedback:%s\n", feedback);
  FILE *feedbackfile;
  feedbackfile = fopen("feedback.txt", "a");
  if (feedbackfile == NULL)
  {
    printf("There is Error while Saving Your feedBack");
  }
  fprintf(feedbackfile, "\nCustomer Name:");
  fprintf(feedbackfile, CustomerName);
  fprintf(feedbackfile, "\nFeedBack:");
  fprintf(feedbackfile, feedback);
  fclose(feedbackfile);
  printf("Thanks for Giving us FeedBack");
};
/*For Showcasing the Services of Our Bank*/
void Services(void)
{
  printf("---------------------------------------------\n");
  printf("We Provide these Services\n");
  printf("1.Saving Account with High Interest rate than Competitors\n");
  printf("2.Current Account with Low Interesr rate Charges\n");
  printf("3.No Limit Credit Cards\n");
  printf("4.Special Interest Calculator for Simple and Compound Effect\n");
  printf("5.Generation of ATM PIN With Unique Proccedure\n");
  printf("6.Loan At Easy Installments\n");
  printf("7.All Kinds of Loan at reasonable Interest rates\n");
  printf("8.Bank Statement at One click\n");
  printf("9.Special Interest rates for Low Income Group\n");
  printf("10.24X7 Customer Care Service\n");
  int choice;
  printf("For Returning Back to Main Menu:0\n");
  printf("For Futher Details of Service:1-10 :)");
  scanf("%d", &choice);
  if (choice == 0)
  {
    ContinuetoMainMenu();
  }
  else
  {
    HelpCenter(choice);
  }
};
/*Opening of Bank Account*/
int OpeningAccount(void)
{
  printf("---------------------------------------------\n");
  printf("Which Account do you want to open?\n");
  printf("1:Saving Account\n");
  printf("2 Current Account\n");
  int choice;
  printf("Enter Which One:");
  scanf("%d", &choice);
  int Amount, MobileNumber, DateofBirth, Income;
  char CustomerName[50];
  printf("Enter Customer Name:");
  scanf("%s", &CustomerName);
  printf("Enter Minmum Amount:");
  scanf("%d", &Amount);
  printf("Enter Mobile Number");
  scanf("%d", &MobileNumber);
  printf("Enter DOB as DayMonthYear:");
  scanf("%d", &DateofBirth);
  if (choice == 1)
  {
    SavingAccount(CustomerName, Amount, MobileNumber, DateofBirth);
  }
  else
  {
    printf("Enter Income:");
    scanf("%d", &Income);
    CurrentAccount(CustomerName, Amount, MobileNumber, DateofBirth, Income);
  }
}
/*For opening of Saving Account*/
void SavingAccount(char *CustomerName, int Amount, int MobileNumber, int DateofBirth)
{
  printf("---------------------------------------------\n");
  int AccountNumber;
  int startNumber = 434454;
  AccountNumber = startNumber * 1000000 + DateofBirth;
  FILE *SavingAccounts;
  SavingAccounts = fopen("SavingAccountsFile.txt", "a");
  if (SavingAccounts == NULL)
  {
    printf("There is a error while Saving Customer Details");
  }
  fprintf(SavingAccounts, "\nNew Saving Account\n");
  fprintf(SavingAccounts, "Account Number:%d\n", AccountNumber);
  fprintf(SavingAccounts, "Customer Name: %s\n", CustomerName);
  fprintf(SavingAccounts, "Mobile Number:%d\n", MobileNumber);
  fprintf(SavingAccounts, "Minimum Deposit:%d\n", Amount);
  fprintf(SavingAccounts, "Date of Birth: %d\n\n", DateofBirth);
  fclose(SavingAccounts);
  printf("Your Saving Account is Opened With Us Successfully\n");
  ContinuetoMainMenu();
}
/*For opening of Current Account*/
void CurrentAccount(char *CustomerName, int Amount, int MobileNumber, int DateofBirth, int Income)
{
  printf("---------------------------------------------\n");
  long int AccountNumber;
  int startNumber = 434454;
  AccountNumber = startNumber * 1000000 + DateofBirth;
  FILE *CurrentAccounts;
  CurrentAccounts = fopen("CurrentAccountsFile.txt", "a");
  if (CurrentAccounts == NULL)
  {
    printf("There is a error while Saving Customer Details");
  }
  fprintf(CurrentAccounts, "\nNew Current Account\n");
  fprintf(CurrentAccounts, "Account Number:%d\n", AccountNumber);
  fprintf(CurrentAccounts, "Customer Name: %s\n", CustomerName);
  fprintf(CurrentAccounts, "Mobile Number:%d\n", MobileNumber);
  fprintf(CurrentAccounts, "Minimum Deposit:%d\n", Amount);
  fprintf(CurrentAccounts, "Income:%d\n", Income);
  fprintf(CurrentAccounts, "Date of Birth: %d\n\n", DateofBirth);
  fclose(CurrentAccounts);
  printf("Your Current Account is Opened With Us Successfully\n");
  ContinuetoMainMenu();
}
/*For Providing all Information related to the Services*/
void HelpCenter(int helpno)
{
  int choice;
  printf("*********************************Welcome to the Help Center*************************\n");
  switch (helpno)
  {
  case 1:
  printf("---------------------------------------------\n");
    printf("High Interest Savings Account - Help Center\n\n"
           "Welcome to the High Interest Savings Account! Our account offers\n"
           "a superior interest rate, providing you with more growth potential\n"
           "compared to competitors' offerings.\n\n"
           "Key Features:\n"
           "- High Interest Rate: Earn more on your savings with our competitive\n"
           "  interest rates.\n"
           "- Compound Interest: Your interest is compounded regularly, helping\n"
           "  your savings grow faster over time.\n"
           "- Safe and Secure: Your deposits are safe and insured, ensuring peace\n"
           "  of mind while your money works for you.\n"
           "- No Hidden Fees: Unlike other accounts, we do not charge fees that\n"
           "  reduce your earned interest.\n\n"
           "How It Works:\n"
           "1. Deposit your funds into the account.\n"
           "2. Watch your savings grow faster with our high interest rate.\n"
           "3. Access your funds anytime, with the advantage of interest growth.\n\n"
           "If you have any questions, please contact our support team or visit\n"
           "our FAQs for more information on how to get started.\n\n");
           printf("Enter 1:Back to Main Menu\nEnter 2:Back to Services");
           scanf("%d",&choice);
           if(choice==1){
            ContinuetoMainMenu();
           }
           else{
            Services();
           }
    break;
  case 2:
  printf("---------------------------------------------\n");
    printf("Current Account with Low Interest Rate Charges - Help Center\n\n"
           "Welcome to our Current Account. While it offers a lower interest rate\n"
           "compared to other account types, it provides flexibility and ease of use\n"
           "for everyday transactions.\n\n"
           "Key Features:\n"
           "- Low Interest Rate: This account offers a lower interest rate, which\n"
           "  may not yield significant returns but is perfect for day-to-day banking.\n"
           "- Flexible Access: Access your funds anytime for transactions without\n"
           "  worrying about withdrawal restrictions.\n"
           "- Safe and Secure: Your funds are protected and insured, ensuring peace\n"
           "  of mind while using the account.\n"
           "- Transaction Charges: Please be aware of possible transaction fees for\n"
           "  specific services, as this account may have charges for certain\n"
           "  transactions.\n\n"
           "How It Works:\n"
           "1. Deposit funds into the account for regular transactions.\n"
           "2. Enjoy easy access to your money for payments and withdrawals.\n"
           "3. Keep in mind that this account offers a low-interest rate and\n"
           "   is more suitable for active transactions rather than saving.\n\n"
           "If you have any questions, please contact our support team or visit\n"
           "our FAQs for more information on how to get started with your Current\n"
           "Account.\n\n");
           printf("Enter 1:Back to Main Menu\nEnter 2:Back to Services");
           scanf("%d",&choice);
           if(choice==1){
            ContinuetoMainMenu();
           }
           else{
            Services();
           }
    break;
  case 3:
  printf("---------------------------------------------\n");
    printf("No Limit Credit Card - Help Center\n\n"
           "Welcome to our No Limit Credit Card! With this card, you can enjoy\n"
           "unlimited spending potential, giving you the freedom to make purchases\n"
           "without worrying about credit limits.\n\n"
           "Key Features:\n"
           "- No Spending Limit: Enjoy the flexibility of making purchases without\n"
           "  a predefined credit limit. Spend as much as you need, when you need it.\n"
           "- Flexible Payments: Pay off your balance at your own pace with a range\n"
           "  of payment options and terms.\n"
           "- Rewards Program: Earn rewards on every purchase, allowing you to\n"
           "  accumulate points, cash back, or other benefits.\n"
           "- Global Acceptance: Use your No Limit Credit Card anywhere that accepts\n"
           "  major credit cards, both online and in stores worldwide.\n\n"
           "Important Notes:\n"
           "- Interest Rates: Keep in mind that the No Limit Credit Card may have\n"
           "  higher interest rates compared to other cards. Please ensure timely\n"
           "  payments to avoid accumulating high interest.\n"
           "- Fees: Be aware of any associated annual fees, foreign transaction fees,\n"
           "  or late payment charges.\n\n"
           "How It Works:\n"
           "1. Apply for the No Limit Credit Card and enjoy an unlimited spending\n"
           "   potential.\n"
           "2. Make purchases on the card and earn rewards as you go.\n"
           "3. Pay your balance by the due date to avoid interest charges.\n\n"
           "If you have any questions, please contact our support team or visit\n"
           "our FAQs for more information on how to get started with your No Limit\n"
           "Credit Card.\n\n");
           printf("Enter 1:Back to Main Menu\nEnter 2:Back to Services");
           scanf("%d",&choice);
           if(choice==1){
            ContinuetoMainMenu();
           }
           else{
            Services();
           }
    break;
  case 4:
  printf("---------------------------------------------\n");
    printf("Special Interest Calculator - Help Center\n\n"
           "Welcome to our Special Interest Calculator! With this tool, you can\n"
           "calculate both Simple Interest and Compound Interest to see how your\n"
           "investment or loan grows over time.\n\n"
           "Key Features:\n"
           "- Simple Interest: Calculate interest on the principal amount using\n"
           "  a fixed rate over a specified period.\n"
           "- Compound Interest: Calculate interest on both the initial principal\n"
           "  and the accumulated interest from previous periods.\n"
           "- Flexible Inputs: Enter your principal amount, interest rate, and\n"
           "  the number of years to see how different scenarios affect your returns.\n"
           "- Instant Results: Get quick results for both interest calculations,\n"
           "  allowing you to compare the effects of simple vs. compound interest.\n\n"
           "How Simple Interest Works:\n"
           "1. Simple interest is calculated by multiplying the principal amount\n"
           "   by the interest rate and the number of years.\n"
           "2. Formula: Simple Interest = Principal * Rate * Time\n"
           "   where Principal is the initial investment, Rate is the annual interest rate,\n"
           "   and Time is the duration in years.\n\n"
           "How Compound Interest Works:\n"
           "1. Compound interest is calculated on the principal amount, as well as\n"
           "   the accumulated interest from previous periods.\n"
           "2. Formula: Compound Interest = Principal * (1 + Rate / n)^(n * Time)\n"
           "   where n is the number of times interest is compounded per year.\n\n"
           "Important Notes:\n"
           "- Simple interest is easier to calculate but may not yield the same\n"
           "  returns over time as compound interest.\n"
           "- Compound interest offers exponential growth because interest is\n"
           "  calculated on both the principal and accumulated interest.\n"
           "- The more frequently interest is compounded, the greater the effect\n"
           "  on the final amount.\n\n"
           "To use the calculator, simply input your values for Principal, Rate,\n"
           "and Time, then select whether you want to calculate Simple or Compound Interest.\n\n"
           "If you have any questions, please contact our support team or visit\n"
           "our FAQs for more detailed explanations on how to use the Special Interest Calculator.\n\n");
           printf("Enter 1:Back to Main Menu\nEnter 2:Back to Services");
           scanf("%d",&choice);
           if(choice==1){
            ContinuetoMainMenu();
           }
           else{
            Services();
           }
    break;
  case 5:
  printf("---------------------------------------------\n");
    printf("ATM PIN Generation with Unique Procedure - Help Center\n\n"
           "Welcome to the ATM PIN Generation service! For enhanced security,\n"
           "we use a unique procedure to generate your PIN. This ensures that\n"
           "your PIN is both secure and easy to remember.\n\n"
           "Key Features:\n"
           "- Unique PIN Generation: Your ATM PIN is generated using a secure,\n"
           "  random algorithm, ensuring that no two customers will have the same PIN.\n"
           "- Customizable PIN Length: You can choose the length of your PIN, with\n"
           "  options ranging from 4 to 6 digits for better flexibility.\n"
           "- Secure Algorithm: Our algorithm combines randomness with user\n"
           "  input (such as birthday, preferred numbers, etc.) to generate a PIN\n"
           "  that's both secure and unique.\n"
           "- Instant Delivery: Once your PIN is generated, it's instantly delivered\n"
           "  to you via a secure method, either through SMS, email, or in-person.\n\n"
           "How It Works:\n"
           "1. Input your preferences, such as the length of the PIN (4-6 digits)\n"
           "   and any optional customization details (like preferred numbers).\n"
           "2. The system generates a random and secure PIN using an algorithm,\n"
           "   taking into account your preferences.\n"
           "3. Your unique ATM PIN is generated and securely delivered to you.\n"
           "4. You can use your PIN for accessing ATMs, online banking, and other\n"
           "   services that require secure authentication.\n\n"
           "Important Notes:\n"
           "- Do not share your PIN with anyone. Keep it confidential to prevent\n"
           "  unauthorized access to your account.\n"
           "- If you forget your PIN, you can easily reset it by following the\n"
           "  reset procedure or contacting customer support.\n"
           "- You can update your PIN at any time through our secure portal.\n\n"
           "For any issues or further inquiries regarding PIN generation, please\n"
           "contact our support team or visit our FAQs for additional guidance.\n\n");
           printf("Enter 1:Back to Main Menu\nEnter 2:Back to Services");
           scanf("%d",&choice);
           if(choice==1){
            ContinuetoMainMenu();
           }
           else{
            Services();
           }
    break;
  case 6:
  printf("---------------------------------------------\n");
    printf("Loan at Easy Installments - Help Center\n\n"
           "Welcome to our Loan at Easy Installments service! We offer flexible\n"
           "loan options that allow you to repay in affordable monthly installments.\n"
           "This makes it easier to manage your finances without stress.\n\n"
           "Key Features:\n"
           "- Flexible Repayment Plans: Choose from various installment options to\n"
           "  suit your budget and repayment preferences.\n"
           "- Low Interest Rates: Enjoy competitive interest rates that keep your\n"
           "  monthly payments low and affordable.\n"
           "- Quick Approval Process: Our loan application process is fast and\n"
           "  straightforward, with quick approval and disbursement of funds.\n"
           "- Transparent Terms: No hidden fees or charges. We provide clear\n"
           "  terms and conditions for your loan agreement.\n\n"
           "How It Works:\n"
           "1. Apply for the loan by providing your necessary details, such as loan\n"
           "   amount, income, and preferred repayment term.\n"
           "2. Once approved, you will receive the loan amount in your account.\n"
           "3. Start repaying your loan in easy, manageable monthly installments.\n"
           "4. The amount you pay each month will depend on the loan amount, interest\n"
           "   rate, and repayment term you chose.\n\n"
           "Important Notes:\n"
           "- Make sure to adhere to the repayment schedule to avoid penalties\n"
           "  or extra charges.\n"
           "- You can repay your loan early without any prepayment penalty.\n"
           "- If you experience financial difficulties, please contact us to\n"
           "  discuss potential adjustments to your repayment plan.\n\n"
           "For more information or assistance with applying for a loan, please\n"
           "contact our support team or visit our FAQs for further guidance.\n");
           printf("Enter 1:Back to Main Menu\nEnter 2:Back to Services");
           scanf("%d",&choice);
           if(choice==1){
            ContinuetoMainMenu();
           }
           else{
            Services();
           }
    break;
  case 7:
  printf("---------------------------------------------\n");
    printf("All Kinds of Loans at Reasonable Interest Rates - Help Center\n\n"
           "Welcome to our comprehensive loan service! We offer a variety of loans\n"
           "to meet your needs, all with reasonable interest rates and flexible terms.\n"
           "Whether you're looking to finance a home, car, education, or any other\n"
           "personal or business expense, we have the right loan for you.\n\n"
           "Key Features:\n"
           "- Variety of Loan Types: Choose from home loans, car loans, education\n"
           "  loans, personal loans, and business loans, all tailored to your needs.\n"
           "- Reasonable Interest Rates: We offer competitive and affordable interest\n"
           "  rates, making it easier for you to repay without financial strain.\n"
           "- Flexible Repayment Terms: Our loans come with customizable repayment\n"
           "  plans ranging from short to long-term, depending on your financial situation.\n"
           "- Quick and Easy Application: Apply online or in person with a simple,\n"
           "  hassle-free application process and quick approval.\n\n"
           "How It Works:\n"
           "1. Choose the loan type that best fits your needs and budget.\n"
           "2. Submit your loan application with details such as the amount you wish\n"
           "   to borrow, repayment term, and purpose of the loan.\n"
           "3. Upon approval, the loan amount will be disbursed to your account.\n"
           "4. Start repaying the loan according to your chosen repayment plan.\n\n"
           "Important Notes:\n"
           "- Make sure to review the interest rate and repayment terms before\n"
           "  accepting the loan.\n"
           "- We offer early repayment options with no additional charges.\n"
           "- Late payments may result in additional charges or penalties, so make\n"
           "  sure to stick to the repayment schedule.\n\n"
           "For any questions or more details about our loan options, please\n"
           "contact our support team or visit our FAQs for further guidance.\n\n");
           printf("Enter 1:Back to Main Menu\nEnter 2:Back to Services");
           scanf("%d",&choice);
           if(choice==1){
            ContinuetoMainMenu();
           }
           else{
            Services();
           }
    break;
  case 8:
  printf("---------------------------------------------\n");
    printf("Bank Statement at One Click - Help Center\n\n"
           "Welcome to the Bank Statement at One Click service! With just a single\n"
           "click, you can access and download your complete bank statement anytime,\n"
           "providing a quick and convenient way to keep track of your transactions.\n\n"
           "Key Features:\n"
           "- Instant Access: Get your full bank statement instantly with just one click.\n"
           "- Easy Download: Download your statement in various formats (PDF, CSV, etc.)\n"
           "  for easy record-keeping and sharing.\n"
           "- Time Range Selection: Choose the specific time period for which you need your\n"
           "  statement (e.g., last month, last 3 months, or custom range).\n"
           "- Secure and Private: Your statement is delivered securely and only accessible\n"
           "  by you through your personal banking portal.\n\n"
           "How It Works:\n"
           "1. Log in to your online banking account.\n"
           "2. Navigate to the 'Bank Statement' section.\n"
           "3. Select the time range for the statement you need.\n"
           "4. Click the 'Download' button to generate your bank statement.\n"
           "5. Your statement will be ready for download in seconds.\n\n"
           "Important Notes:\n"
           "- Bank statements are available for download for up to the last 12 months.\n"
           "- You can download your statement as many times as needed, free of charge.\n"
           "- Make sure to keep your login credentials secure to protect your personal\n"
           "  information and statement access.\n\n"
           "For any issues or if you need help accessing your bank statement, please\n"
           "contact our support team or visit our FAQs for additional assistance.\n\n");
           printf("Enter 1:Back to Main Menu\nEnter 2:Back to Services");
           scanf("%d",&choice);
           if(choice==1){
            ContinuetoMainMenu();
           }
           else{
            Services();
           }
    break;
  case 9:
  printf("---------------------------------------------\n");
    printf("Special Interest Rates for Low-Income Groups - Help Center\n\n"
           "Welcome to our Special Interest Rates program designed specifically for\n"
           "low-income groups! We understand that financial constraints can be a barrier\n"
           "to accessing essential banking services, and we’re here to make things easier.\n\n"
           "Key Features:\n"
           "- Reduced Interest Rates: Benefit from lower interest rates on loans,\n"
           "  credit cards, and savings accounts to ease your financial burden.\n"
           "- Affordable Monthly Payments: Choose from flexible repayment options\n"
           "  that fit your monthly budget and reduce financial strain.\n"
           "- Access to Loans: Eligible low-income individuals can apply for personal\n"
           "  loans with reduced rates, making it easier to afford essential needs.\n"
           "- Savings Account Benefits: Low-income groups can also take advantage\n"
           "  of higher interest rates on savings accounts to grow their savings over time.\n\n"
           "How It Works:\n"
           "1. Apply for a loan, credit card, or savings account under the low-income program.\n"
           "2. Provide necessary documentation to confirm your eligibility, such as proof\n"
           "   of income, household details, and other required information.\n"
           "3. Once approved, enjoy reduced interest rates and flexible repayment options.\n"
           "4. You can access additional financial services that cater to low-income households.\n\n"
           "Important Notes:\n"
           "- To qualify, you may need to meet specific income criteria or provide\n"
           "  proof of financial hardship.\n"
           "- Reduced rates apply only to specific products, such as personal loans\n"
           "  and savings accounts. Please check the terms for eligibility.\n"
           "- Timely repayments will help you maintain a good credit history and access\n"
           "  future financial services.\n\n"
           "For further information or assistance, please contact our support team or\n"
           "visit our FAQs for more details on how to apply for special interest rates.\n\n");
           printf("Enter 1:Back to Main Menu\nEnter 2:Back to Services");
           scanf("%d",&choice);
           if(choice==1){
            ContinuetoMainMenu();
           }
           else{
            Services();
           }
    break;
  case 10:
  printf("---------------------------------------------\n");
    printf("24X7 Customer Care Service - Help Center\n\n"
           "Welcome to our 24X7 Customer Care Service! We are always here to assist\n"
           "you, no matter the time of day or night. Whether you have questions, need\n"
           "support, or require assistance with any banking services, our team is ready\n"
           "to help you 24 hours a day, 7 days a week.\n\n"
           "Key Features:\n"
           "- 24/7 Availability: Our customer care team is available around the clock,\n"
           "  so you can get help whenever you need it.\n"
           "- Multiple Support Channels: Contact us via phone, email, live chat, or\n"
           "  through our mobile app for immediate assistance.\n"
           "- Quick Resolution: We aim to provide fast, effective solutions to your\n"
           "  issues, ensuring that your banking experience is smooth and hassle-free.\n"
           "- Expert Assistance: Our support staff is well-trained to handle a wide\n"
           "  range of queries, from account inquiries to technical issues.\n\n"
           "How It Works:\n"
           "1. Choose your preferred method of contact: phone, email, live chat, or\n"
           "   the mobile app.\n"
           "2. Reach out to our support team with your query or issue.\n"
           "3. Our customer care representatives will assist you and provide a solution\n"
           "   or escalate the issue if necessary.\n"
           "4. You'll receive updates on the status of your issue until it's fully resolved.\n\n"
           "Important Notes:\n"
           "- Please have your account information ready when contacting customer care.\n"
           "- Our team is available to assist with banking services, account issues,\n"
           "  troubleshooting, and general inquiries.\n"
           "- For urgent matters, please call our customer care number directly for faster\n"
           "  assistance.\n\n"
           "If you need further information or have any questions, don't hesitate to\n"
           "contact us. We're here to provide the support you need, whenever you need it!\n\n");
           printf("Enter 1:Back to Main Menu\nEnter 2:Back to Services");
           scanf("%d",&choice);
           if(choice==1){
            ContinuetoMainMenu();
           }
           else{
            Services();
           }
    break;
  default:
    break;
  }
}
/*ATM pin Generation*/
void ATMpinGeneration(int AccountNumber, int MobileNumber, int CardNumber)
{
  printf("---------------------------------------------\n");
  FILE *atmpin;
  atmpin = fopen("atmpins.txt", "a");
  srand(time(0));
  int pin = 1000 + rand() % 9000;
  printf("Your ATM pin is Generated Successfully\n");
  if (atmpin == NULL)
  {
    printf("Something went wrong while creating Pin\n");
  }
  else
  {
    fprintf(atmpin, "Account Number:%d\n", AccountNumber);
    fprintf(atmpin, "Mobile Number:%d\n", MobileNumber);
    fprintf(atmpin, "Card Number:%d\n", CardNumber);
    fprintf(atmpin, "ATM PIN:%d\n\n", pin);
    fclose(atmpin);
  }
  ContinuetoMainMenu();
};
/*For Eligibility Criteria for Schemes as per Income slap*/
int Eligiblity(int AccountNumber, int Income)
{
  printf("---------------------------------------------\n");
  printf("Your Eligibility is checking.........\n");
  if (Income < 100000)
  {
    printf("Your are Eligible for all of the above Schemes\n");
    printf("We are Back to Schemes\n");
    Schemes(AccountNumber, Income);
  }
  if (Income < 400000)
  {
    printf("Your are Eligible for only these Schemes Kishan credit card,Sukaniya Yojana\n");
    printf("We are Back to Schemes\n");
    Schemes(AccountNumber, Income);
  }
  else
  {
    printf("Sorry your Income is too high\n");
    printf("We are Back to Schemes\n");
    Schemes(AccountNumber, Income);
  }
}
/*Schemes Provided by the Bank For Certain Income groups*/
void Schemes(int AcNumber, int Income)
{
  printf("---------------------------------------------\n");
  printf("Please make a choice out of the Schemes\n");
  printf("1.Startup Funding For College Student\n2.Kishan credit card\n3.Phela Kadam\n4.Sukaniya Yojana\n5.Phela Business Initiative for Lower Middle Class\n6.Back to Main Menu\n");
  int choice;
  printf("Enter your choice:");
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:
  printf("---------------------------------------------\n");
    printf("**********************Startup Funding For College Student************************\n");
    printf("Startup Funding For College Student,it is an initiative for college students who are seeking funding for their startups.\nwe are providing a golden opportunity to those students who wants to pitch their ideas to our business development panel \nand get chance to get funding upto 50 lakhs as per Childern reserve Bank of india\n");
    printf("for pitching your idea call us at 9999XXXXX\n");
    printf("For Returning Back to Main Menu:0\n");
    printf("For Knowing Eligiblity:1:)\n");
    printf("Enter::");
    int choice;
    scanf("%d", &choice);
    if (choice == 0)
    {
      ContinuetoMainMenu();
    }
    else
    {
      Eligiblity(AcNumber, Income);
    }
  case 2:
    printf("---------------------------------------------\n");
    printf("**********************Kishan Credit Card Opportunity************************\n");
    printf("Kishan Credit Card is a unique offering for young professionals and\n students who are looking to build their credit history. It provides an excellent opportunity to get a credit limit of up to 1 lakh,\n helping you manage your finances effectively and build a strong financial future.\n");
    printf("To apply for your Kishan Credit Card, call us at 9999XXXXX or visit our nearest branch for more details.\n");
    printf("For Returning Back to Main Menu:0\n");
    printf("For Knowing Eligiblity:1:)\n");
    printf("Enter::");
    scanf("%d", &choice);
    if (choice == 0)
    {
      ContinuetoMainMenu();
    }
    else
    {
      Eligiblity(AcNumber, Income);
    }
  case 3:
    printf("---------------------------------------------\n");
    printf("**********************Phela Kadam Initiative************************\n");
    printf("Phela Kadam is an exciting initiative aimed at empowering youth and providing them \nwith a stepping stone towards a brighter future. It offers financial support and\n guidance to help individuals take their first step towards financial independence and success.\n");
    printf("To be a part of Phela Kadam, call us at 9999XXXXX or visit our nearest center to learn more and start your journey today.\n");
    printf("For Returning Back to Main Menu:0\n");
    printf("For Knowing Eligiblity:1:)\n");
    printf("Enter::");
    scanf("%d", &choice);
    if (choice == 0)
    {
      ContinuetoMainMenu();
    }
    else
    {
      Eligiblity(AcNumber, Income);
    }
    break;
  case 4:
    printf("---------------------------------------------\n");
    printf("**********************Sukanya Samriddhi Yojana************************\n");
    printf("Sukanya Samriddhi Yojana is a government-backed savings scheme designed to secure the future\n of your daughter. This initiative helps in saving for her education,\n marriage, and other essential needs, offering attractive interest rates and tax benefits.\n");
    printf("To open an account under Sukanya Samriddhi Yojana, call us at 9999XXXXX\n or visit your nearest post office or bank branch for more details.\n");
    printf("For Returning Back to Main Menu:0\n");
    printf("For Knowing Eligiblity:1:)\n");
    printf("Enter::");
    scanf("%d", &choice);
    if (choice == 0)
    {
      ContinuetoMainMenu();
    }
    else
    {
      Eligiblity(AcNumber, Income);
    }
  case 5:
    printf("---------------------------------------------\n");
    printf("**********************Phela Business Initiative for Lower Middle Class************************\n");
    printf("Phela Business Initiative is a special program designed to empower the lower-middle-class community by providing them with opportunities\n to start and grow their own businesses.\nIt offers financial support, training, and resources to help individuals turn their business ideas into reality.\n");
    printf("To apply for the Phela Business Initiative, call us at 9999XXXXX or visit our nearest branch to learn more and get started with your entrepreneurial journey.\n");
    printf("For Returning Back to Main Menu:0\n");
    printf("For Knowing Eligiblity:1:)\n");
    printf("Enter::");
    scanf("%d", &choice);
    if (choice == 0)
    {
      ContinuetoMainMenu();
    }
    else
    {
      Eligiblity(AcNumber, Income);
    }
  
  case 6:
  ContinuetoMainMenu();
  break;
  default:
    break;
  }
}
/*Interest Calculation*/
void InterestCalculator(double Amount, double Rate, double Time)
{
  printf("---------------------------------------------\n");
  printf("Welcome to Interest Calculator\n");
  printf("Choose which interst you wants to calculate \n1.Simple Interest\n2.Compound Interest\n");
  int option;
  double simpleInterest, compoundInterest;
  printf("Enter::");
  scanf("%d", &option);
  switch (option)
  {
  case 1:
  printf("---------------------------------------------\n");
    printf("Simple Interest as per Your Details:Amount: %.0lf,Rate:%.0lf Time:%.0lf\n", Amount, Rate, Time);
    simpleInterest=(Amount*Rate*Time/100);
    printf("Your Simple Interest is %.0lf\n", simpleInterest);
    ContinuetoMainMenu();
    break;
  case 2:
  printf("---------------------------------------------\n");
    printf("Compound Interest as per Your Details:Amount: %.0lf,Rate:%.0lf Time:%.0lf\n", Amount, Rate, Time);
    compoundInterest=(Amount * pow((1 + Rate / 100), Time));
    printf("Your Compound Interest is %.2lf\n", compoundInterest);
    ContinuetoMainMenu();
  default:
    break;
  }
};
/*Receipt printout*/
void ReceiptPrintout(){
  printf("---------------------------------------------\n");
  char accountnumber[15];
  printf("Enter Your Account Number:");
  scanf("%s",&accountnumber);
  char *accountnumberfile;
  char receipt[100];
  accountnumberfile=strcat(accountnumber,".txt");
  FILE *accountfile;
  accountfile=fopen(accountnumber,"r");
  if(accountfile==NULL){
    printf("No Record Found\n");
  }
  while (fgets(receipt,sizeof(receipt),accountfile)!=NULL)
  {
        puts(receipt);
  }
  printf("Your Reciept for Latest Deposit\n");
  ContinuetoMainMenu();
};
void BankStatement(char *AccountNumber){
  printf("---------------------------------------------\n");
  printf("Bank Statements of Account Number: %s\n",AccountNumber);
  FILE *statements;
  char getter[1000];
  char *accountfile;
  accountfile=strcat(AccountNumber,".txt");
  statements=fopen(accountfile,"r");
  if(statements==NULL){
    printf("No Record Found\n");
  }
  while(fgets(getter,sizeof(getter),statements)!=NULL){
    printf("\n");
        puts(getter);
  }
  ContinuetoMainMenu();
};
void MoneyDeposit(char *Accountnumber,char *Amount){
  printf("---------------------------------------------\n");
  printf("Your Account is %s and Money is: %s\n",Accountnumber,Amount);
  FILE *accountfile;
  char *accountfilename;
  accountfilename=strcat(Accountnumber,".txt");
  accountfile=fopen(accountfilename,"a");
  if(accountfilename==NULL){
    printf("Something Went While opening the File\n");
  }
  fprintf(accountfile,"Date:%s\t",__DATE__);
  fprintf(accountfile,"Amount:%s\t",Amount);
  fprintf(accountfile,"To Amit Dhangar\t");
  fprintf(accountfile,"Time:%s\n",__TIMESTAMP__);
  fclose(accountfile);
  printf("In Account Number File  %s  Amount is Deposited %s Successfully\n",Accountnumber,Amount);
  ContinuetoMainMenu();
}

void WithDrawMoney(int AccountNumber,int Amount,int ATMpin){
    printf("---------------------------------------------\n");
  FILE *accountfile,atmpins;
  printf("Which Account is Yours?\n1.Saving Account\n2.Current Account\n");
  int choice;
  printf("Enter Your Your Account Type::");
  scanf("%d",&choice);
  if(choice==1){
    accountfile=fopen("SavingAccountsFile.txt","r");
  }
  if(choice==2){
    accountfile=fopen("CurrentAccountsFile.txt","r");
  }
  if(accountfile==NULL){
    printf("No Record is Found\n");
  }
  while(fscanf(accountfile,"%d %s",AccountNumber)){
    
  }
}//Feel free to contribute to this project.
// If you are school or college student looking for project for your practicals then it will the best for Your Project.

// 1-Reviews::