#include <stdio.h>
#include <string.h>
#include<time.h>
struct tm tm;
char name[40];
//global variables
int cv,ord_qv,countv=0,i;
int cf,ord_qf,count1=0;
int count3=0,cd,ord_qd;
float totald=0,totalf=0,totalv=0;
struct products //declaration of a structure of products
{
    int srno;
    char name[70];
    float price;
    int qty;
};
struct products p[]={{ 1,"Bitter Gourd     ",50,100},
                     { 2,"Bottle Gourd     ",80,100},
                     { 3,"Brinjal          ",70,100},
                     { 4,"Cabbage          ",60,100},
                     { 5,"Capsicum         ",80,100},
                     { 6,"Cauliflower      ",80,100},
                     { 7,"Garlic           ",200,100},
                     { 8,"Ginger           ",100,100},
                     { 9,"Green Peas       ",70,100},
                     {10,"Lady finger      ",80,100},
                     {11,"Ivy Gourd        ",100,100},
                     {12,"Spinach          ",20,100},
                     {13,"Potato           ",30,100},
                     {14,"Pumpkin          ",40,100},
                     {15,"Onion            ",40,100},
                     {16,"Sweet Potato     ",50,100},
                     {17,"Whole corn       ",42,100},
                     {18,"Apple                   ",44,100},
                     {19,"Apricot (per piece)     ",101,100},
                     {20,"Avocados(per piece)     ",56,100},
                     {21,"Bananas                 ",24,100},
                     {22,"Custard Apple           ",115,100},
                     {23,"Grapes                  ",76,100},
                     {24,"Guava                   ",99,100},
                     {25,"Lychee(per dozen)       ",127,100},
                     {26,"Mango(ripe)(per dozen)  ",500,100},
                     {27,"Mango(unripe)(per dozen)",400,100},
                     {28,"Orange                  ",89,100},
                     {29,"Papaya                  ",105,100},
                     {30,"Pear                    ",106,100},
                     {31,"Pineapple(per piece)    ",69,100},
                     {32,"Pomogranate             ",88,100},
                     {33,"Sweet lime(per dozen)   ",65,100},
                     {34,"Watermelon              ",127,100},
                     {35,"Cow Milk(per l)            ",50,100},
                     {36,"Buffalo Milk(per l)        ",70,100},
                     {37,"Butter(per 100 grms)       ",80,100},
                     {38,"Cheddar Cheese(per 250gm)  ",150,100},
                     {39,"Mozzarela Cheese(per 250gm)",200,100},
                     {40,"Cottage Cheese(per 250gms) ",100,100},
                     {41,"Eggs(per)                  ",5,100},
                     {42,"Bread(per 400gm)           ",30,100}
                    }; 
struct cart //structure for the shopping cart
{
    char name[40];
    float price;
    int qty;
    char catgy;
    int srno;
};
struct cart c[100];//c is the name of the array of structures

void cartv()
{   float costv;
    int k;
  
    costv=(float)ord_qv*(p[cv-1].price);//cost of an individual vegetable
    
    printf("_______________________________________________________________\n");
    printf("Srno.\tProduct\t\tQuantity added\t\tPrice\n");
   
    strcpy(c[cv-1].name,p[cv-1].name);
    c[cv-1].price=ord_qv*p[cv-1].price;
    c[cv-1].qty=ord_qv;
    c[cv-1].catgy='v';
    c[cv-1].srno=cv;
    if(ord_qv!=0)
    printf("%2d.\t%s\t%d\t\t%0.3f\n\n",cv,p[cv-1].name,ord_qv,costv);
    
    printf("*************************************************************\n");
    printf("CURRENTLY IN YOUR CART :\n");
    costv=0;
    for(i=0;i<17;i++)
    {
        if(c[i].qty!=0)
        {   
            printf("%s\t\t%d\t\t%0.3f\n",c[i].name,c[i].qty,c[i].price);
            costv=costv+c[i].price;
        }
    }
    totalv=costv;//total of vegetables in cart
    printf("_____________________________________________________________\n");
    printf("The Total Price is:%0.3f\n",totalv);
    printf("*************************************************************\n");
    
}
void veggies()
 { 
    char c3;
    int i;
    //allowing user to make his/her choice multiple times.
    do
    {
    { 
      clrscr();
      printf("PRODUCT\t\t\tPRICE\t\t\tQUANTITY\n");
      for(i=0;i<17;i++)
      { 
        printf("%2d.%s\t%f\t\t%d\n",p[i].srno,p[i].name,p[i].price,p[i].qty);
      }
      printf("\nMake your choice of vegetable:\n");
      scanf("%d",&cv); //choice of veggies cv
      for(i=0;i<17;i++)
      { 
        if(cv==p[i].srno)
        {
             printf("Enter quantity required:\n");
             scanf("%d",&ord_qv); //ordered quantity variable
             if (ord_qv>p[cv-1].qty)
             {
                  printf("Sorry the quantity is not available:\n");
              }
             else  
             {
               p[cv-1].qty=p[cv-1].qty-ord_qv;  
               clrscr();
               cartv();
             }
        }
        
      }
      for(i=0;i<17;i++)
      {
          if (c[i].qty==0)
          p[i].qty=100;
      }
      printf("\nDo you want to continue shopping vegetables?(y/n)\n");
      getchar();
      scanf("%c",&c3);
      clrscr();
      countv++;
    }
    }while(c3=='y');
 }

void cartf()
{   float costf;
    int j;
    
    costf=(float)ord_qf*(p[cf-1].price);//cost of an individual fruit
    
    printf("srno.\tProduct\t\t\tquantity added\t\tprice\n");
    strcpy(c[cf-1].name,p[cf-1].name);
    c[cf-1].price=ord_qf*p[cf-1].price;
    c[cf-1].qty=ord_qf;
    c[cf-1].catgy='f';
    c[cf-1].srno=cf;
    if(ord_qf!=0)
    printf("%0.2d.\t%s\t%d\t\t%0.3f\n\n",cf,p[cf-1].name,ord_qf,costf);
    printf("*************************************************************\n");
    printf("CURRENTLY IN YOUR CART :\n");
    costf=0;
    for(i=17;i<34;i++)
    {
        if(c[i].qty!=0)
        {   printf("%s\t\t%d\t\t%0.3f\n",c[i].name,c[i].qty,c[i].price);
            costf=costf+c[i].price;
        }
    }
    totalf=costf;//total of fruits in cart
    printf("_____________________________________________________________\n");
    printf("The total price is:%0.3f\n",totalf);
    printf("*************************************************************\n");
}
void print_fruits()
{ 
    char c5;
    int i;
    //allowing user to make his/her choice multiple times.
    do
    {
    { clrscr();
      printf("PRODUCT\t\t\t\tPRICE\t\t\tQUANTITY\n");
      for(i=17;i<34;i++)
      { 
        printf("%2d.%s\t%f\t\t%d\n",p[i].srno,p[i].name,p[i].price,p[i].qty);
      }
      printf("\nMake your choice of fruit:\n");
      scanf("%d",&cf); //choice of fruit cf
      for(i=17;i<34;i++)
      { 
        if(cf==p[i].srno)
        {
             printf("Enter quantity required:\n");
             scanf("%d",&ord_qf); //ordered quantity of fruits variable
             if (ord_qf>p[cf-1].qty)
             {
                printf("Sorry the quantity is not available:\n");
             }
            else  
            {
              p[cf-1].qty=p[cf-1].qty-ord_qf;  
              clrscr();
              cartf();
            }
        }
        
      }
      for(i=17;i<34;i++)
      {
          if (c[i].qty==0)
          p[i].qty=100;
      }
      printf("\nDo you want to continue shopping fruits? \nenter y for yes or n for no:\n");
      getchar();
      scanf("%c",&c5);
      
      count1++;
      clrscr();
    }
    }while(c5=='y');

 }
void cartd()
{ 
    float costd;
    int i;
    
    costd=(float)ord_qd*(p[cd-1].price);//cost of an individual dairy product
    
    printf("SrNo.\tProduct\t\t\tquantity added\t\tprice\n");
    strcpy(c[cd-1].name,p[cd-1].name);
    c[cd-1].price=ord_qd*p[cd-1].price;
    c[cd-1].qty=ord_qd;
    c[cd-1].catgy='d';
    c[cd-1].srno=cd;
    if(ord_qd!=0)
    printf("%2d.\t%s\t%d\t\t%0.3f\n\n",cd,p[cd-1].name,ord_qd,costd);
    printf("*************************************************************\n");
    printf("CURRENTLY IN YOUR CART :\n");
    costd=0;
    for(i=34;i<42;i++)
    {
        if(c[i].qty!=0)
        {   
            printf("%s\t\t%d\t\t%0.3f\n",c[i].name,c[i].qty,c[i].price);
            costd=costd+c[i].price;
        }
    }
    totald=costd;//total of dairy products in cart
    printf("_____________________________________________________________\n");
    printf("The total price is:%0.3f\n",totald);
    printf("*************************************************************\n");
}
void print_dairy()
{  
    char c7;
    int i;
    //allowing user to make his/her choice multiple times.
    do
    {
     { clrscr();
       printf("PRODUCT\t\t\t\tPRICE\t\t\tQUANTITY\n");
       for(i=34;i<42;i++)
       { 
         printf("%2d.%s\t%f\t\t%d\n",p[i].srno,p[i].name,p[i].price,p[i].qty);
       }
       printf("\nMake your choice of dairy:\n");
       scanf("%d",&cd); //choice of dairy cd
       for(i=34;i<42;i++)
       { 
        if(cd==p[i].srno)
        {
           printf("Enter quantity required:\n");
           scanf("%d",&ord_qd); //ordered quantity variable
           if (ord_qd>p[cd-1].qty)
           {
              printf("Sorry the quantity is not available:\n");
           }
           else  
           {
              p[cd-1].qty=p[cd-1].qty-ord_qd;  
              clrscr();
              cartd();
           }
        }
       
      }
      for(i=34;i<42;i++)
      {
          if (c[i].qty==0)
          p[i].qty=100;
      }
      printf("\nDo you want to continue shopping dairy products?\nenter y for yes or n for no:\n");
      getchar();
      scanf("%c",&c7);
      clrscr();
      
      count3++;
     
    }
    }while(c7=='y');
}

void main()
{   
    int c1;
    char c2;
    void customer();
    void billing();
    void modify();
    void veggies();
    void print_fruits();
    void print_dairy();
    void cartf();
    void cartd();
    void cartv();
    clrscr();
    printf("\t\t\tWELCOME TO FARMFRESH!\n");
    printf("\t\t\tHAPPY SHOPPING!!!!\n\n");
    printf("PLease enter your name: ");
    scanf("%s",&name);//to input the name of the user
    do
    {
        printf("WITH WHAT WOULD YOU LIKE TO PROCEED?\n");
         printf("1.BUY\n2.EXIT\n");
         scanf("%d",&c1);
         clrscr();
         switch(c1)
         {
            case 1: customer();
            break;
            case 2: exit(0);
            break;
            default:
            printf("Please enter a valid 1 or 2 only. ");
         }
        printf("\nWould you like to browse through other categories?(enter y/n)\n");
        flushall();
        scanf("%c",&c2);
         
    }while(c2=='y');
    
}
void customer()
{  
    void billing();
    void modify();
    int c3;
    char c8;
    do
    {
    printf("\t\tWHAT WOULD YOU LIKE TO BUY TODAY?\n");
    printf("1.VEGETABLES\n\n2.FRUITS\n\n3.DAIRY\n\n4.EXIT\n");
    scanf("%d",&c3);
    
     switch(c3)
     {
        
        case 1: veggies();
        break;
        case 2: print_fruits();
        break;
        case 3: print_dairy();
        break;
        case 4: exit(0);
        default:    
        { 
         clrscr();
         printf("Please enter one of the above. ");
         break;
        }
     }
     printf("\nGO BACK TO MAIN MENU?(enter y/n)\n");
     flushall();
     scanf("%c",&c8);
     
     clrscr();
    }while (c8=='y');
    billing();
 }
void billing()
{   void modify();
    int a,j,k,i;
    float total;
    time_t t;
    t = time(NULL);
    tm = *localtime(&t);
    flushall();
    clrscr();
    printf("\t\t    FARMFRESH\t\t     Date:%d-%d-%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
    printf("\n\t      EAT FRESH ALWAYS!!....");
    printf("\n\t\t      BILL\n");
    printf("CUSTOMER'S NAME: %s\n",name);
    printf("_____________________________________________________________\n");
    printf("YOUR BILLING ID :%d\n",&a);
    printf("_____________________________________________________________\n");
    total=totald+totalv+totalf; //the final amount to be paid
    printf("PRODUCT\t\t\t\tQUANTITY\tPRICE\n");
    printf("_____________________________________________________________\n");
    printf("VEGETABLES:\n");
    for(i=0;i<17;i++)
    {
        if(c[i].qty!=0)
        printf("%s\t\t%d\t\t%0.3f\n",c[i].name,c[i].qty,c[i].price);
    }
    printf("\nFRUITS:\n");
    for(i=17;i<34;i++)
    {
        if(c[i].qty!=0)
        printf("%s\t%d\t\t%0.3f\n",c[i].name,c[i].qty,c[i].price);
    }
    printf("\nDAIRY:\n");
    for(i=34;i<42;i++)
    {
        if(c[i].qty!=0)
        printf("%s\t%d\t\t%0.3f\n",c[i].name,c[i].qty,c[i].price);
    }
    printf("*************************************************************\n");
    printf("\nYOUR TOTAL AMOUNT IS:%f\n",total);
    if(total>1000 && total<5000)
    {
        total=total- 0.1*total;
    }
    else if(total>5000)
    {
        total=total- 0.2*total;
    }
    printf("\nYOUR AMOUNT AFTER DISCOUNT IS:%f\n",total);
    printf("*************************************************************\n");
    printf("\n\t\tTHANK YOU FOR SHOPPING WITH US!!!\n\n");
    modify();
}

void modify()  //allows the user to add/delte items from their cart
{   
    void modifyv();
    void modifyf();
    void modifyd();
    char c10,c11;
    printf("Do you wish to modify your cart?(y/n)\n");
    scanf("%c",&c10);
    clrecr();
    if(c10=='y')
    {
        printf("What do you wish to modify?\n");
        printf("1.VEGETABLES\n\n2.FRUITS\n\n3.DAIRY\n\n4.EXIT\n");
        scanf("%d",&c11);
        switch(c11)
        {
            case 1: modifyv();
            break;
            case 2: modifyf();
            break;
            case 3: modifyd();
            break;
            case 4: exit(0);
            default:    
            { 
                clrscr();
                printf("Please enter one of the above. ");
                break;
            };
        }
        
    }
    
} 
void modifyv() //used to modify the vegetables section of the cart
{   int cvm,ord_qvm;
    int l,b,k;
    void billing();
    void cartv();
    void veggies();
    clrscr();
    printf("select the item you want to modify\n\n");
    printf("SRNO.\t\t\tPRODUCT\t\t\tPRICE\n");
    
    for(i=0;i<17;i++)
    {
        if(p[i].qty!=0)
        printf("%d\t%s\t\t\t%0.3f\n",p[i].srno,p[i].name,p[i].price);
    }
    scanf("%d",&cvm);
    if(cvm>=0 && cvm<17)
    {   
        printf("\nEnter quantity required:\n");
        scanf("%d",&ord_qvm);
        clrscr();
        cv=cvm;
        ord_qv=ord_qvm;
        cartv();
        
    }
    for(i=0;i<17;i++)
    {
          if (c[i].qty==0)
          p[i].qty=100;
    }
    clrscr();
    printf("\nThe modified bill is:\n");
    billing();  //displays the final bill
    
}
void modifyf() //used to modify the fruits section of the cart
{   int cfm,ord_qfm;
    clrscr();
    printf("select the item you want to modify\n\n");
    printf("SRNO.\t\t\tPRODUCT\t\t\tPRICE\n");
    
    for(i=17;i<34;i++)
    {
        if(p[i].qty!=0)
        printf("%d\t%s\t\t\t%0.3f\n",p[i].srno,p[i].name,p[i].price);
    }
    scanf("%d",&cfm);
    if(cfm>=17 && cfm<34)
    {   
        printf("\nEnter quantity required:\n");
        scanf("%d",&ord_qfm);
        clrscr();
        cf=cfm;
        ord_qf=ord_qfm;
        cartf();
        
    }
    for(i=17;i<34;i++)
    {
          if (c[i].qty==0)
          p[i].qty=100;
    }
    clrscr();
    printf("\nThe modified bill is:\n");
    billing();  //displays the final bill
    
}
void modifyd()  //used to modify the dairy section of the cart
{    
    int cdm,ord_qdm;
    clrscr();
    printf("select the item you want to modify\n\n");
    printf("SRNO.\t\t\tPRODUCT\t\t\tPRICE\n");
    
    for(i=34;i<42;i++)
    {
        if(p[i].qty!=0)
        printf("%d\t%s\t\t\t%0.3f\n",p[i].srno,p[i].name,p[i].price);
    }
    scanf("%d",&cdm);
    if(cdm>=34 && cdm<42)
    {   
        printf("\nEnter quantity required:\n");
        scanf("%d",&ord_qdm);
        clrscr();
        clrscr();
        cd=cdm;
        ord_qd=ord_qdm;
        cartd();
        
    }
    for(i=34;i<42;i++)
    {
          if (c[i].qty==0)
          p[i].qty=100;
    }
    clrscr();
    printf("\nThe modified bill is:\n");
    billing(); //displays the final bill
}