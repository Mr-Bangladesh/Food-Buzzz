#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

int Drinks();
int numbers();
void database();
void print_database();

void loading()
{
    int i;

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t");
        printf("Loading ");

        printf(" .");
        for(i = 1; i <= 500000000; i++);
        printf(".");
        for(i = 1; i <= 500000000; i++);
        printf(".");
        for(i = 1; i <= 500000000; i++);

        system("cls");

}

void loading2()
{
    int i;

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t");
        printf("Loading ");

        printf(" .");
        for(i = 1; i <= 50000000; i++);
        printf(" . ");
        for(i = 1; i <= 50000000; i++);
        printf(".");
        for(i = 1; i <= 50000000; i++);

        system("cls");
        printf("\n\n");
}



int main()
{

    char main_menu[100];



    printf("\n\n\n\n");

    printf("\n\n\n\n\t\t\t\t*****WELCOME TO FOOD BUZZZ*****");

    MAIN_MENU:

    printf("\n\n\t\t\t\t\t$$$MAIN MENU$$$\n\n\n\n");
    printf("\t\t\t1.FOOD MENU AND ORDER\n\n");
    printf("\t\t\t2.AUTHORITY VIEW\n\n");
    printf("\t\t\t3.ABOUT\n\n");
    printf("\t\t\t4.Exit\n\n");

    printf("\t\t\tEnter: ");

    scanf("%s",main_menu);

    if(strcmp(main_menu,"1")==0)
    {
        option:
        system("cls");

        loading2();

        printf("\n\n\n\n\t\t\t\t***FOOD MENU***\n\n");



        char item[100];
        char fahad[100];
        int food_menu_len;
        int i,j,k,a,b,c;
        char food_menu[10000];
        char food_menu_serial[100][100];
        char food_menu_name[100][10000];
        char temp1[1000],temp2[1000];

        int total_price=0;



        FILE *fp1;
        fp1=fopen("files/menu.txt","r");

        b=0;
        c=0;

        while(fgets(food_menu,1000,fp1))
        {
            printf("\t\t\t%s\n",food_menu);
            food_menu_len=strlen(food_menu);
            j=0;
            for(i=0;i<food_menu_len;i++)
            {
                if(food_menu[i]==32)
                    break;
                temp1[j]=food_menu[i];
                j++;
            }
            temp1[j]='\0';
            strcpy(food_menu_serial[b],temp1);
            b++;
            k=0;
            for(i=j+1;i<food_menu_len;i++)
            {
                if(food_menu[i]==32 && food_menu[i]>='0' && food_menu[i]<='9')
                    break;
                temp2[k]=food_menu[i];
                k++;
            }
            temp2[k]='\0';
            strcpy(food_menu_name[c],temp2);
            c++;
        }
        fclose(fp1);

        printf("\n\t\t\t0. back\n");

        printf("\n\t\t\tEnter:  ");
        //getchar();
        scanf("%s",item);

        if(strcmp(item,"0")==0)
        {
            system("cls");
            goto MAIN_MENU;
        }

        if(atoi(item)<1)
        {
            printf("\n\t\t\tWrong keyword!!\n");
            getchar();
            printf("\t\t\tEnter any to continue..  ");
            getchar();
            goto option;
        }

        char food_item[1000];
        char temp3[1000],temp4[1000],temp5[1000];
        char item_serial[100][100];
        char item_name[100][1000];
        char item_price[100][1000];
        int l,m,o,d,e,f,p;
        int item_len;

        int price;

        //int total_price=0;

        int check;

        for(a=0;a<b;a++)
        {
            check=0;
            if(strcmp(food_menu_serial[a],item)==0)
            {

                system("cls");
                printf("\n\n\n\t\t\t\t%s\n\n",food_menu_name[a]);

                char temp[100]="files/";
                strcat(temp,item);
                strcat(temp,".txt");
                FILE *fp3;
                fp3=fopen(temp,"r");
                d=0;
                e=0;
                f=0;

                while(fgets(food_item,1000,fp3))
                {
                    printf("\t\t\t%s\n",food_item);
                    item_len=strlen(food_item);
                    m=0;
                    //o=0;
                    for(l=0;l<item_len;l++)
                    {
                        if(food_item[l]==32)
                            break;
                        temp3[m]=food_item[l];
                        m++;
                    }
                    temp3[m]='\0';
                    strcpy(item_serial[d],temp3);
                    d++;
                    o=0;
                    for(l=m+1;l<item_len;l++)
                    {
                        if(food_item[l]==32 && food_item[l+1]>='0' && food_item[l+1]<='9')
                            break;
                        temp4[o]=food_item[l];
                        o++;
                    }
                    temp4[o]='\0';
                    strcpy(item_name[e],temp4);
                    e++;
                    p=0;
                    for(l=o+3;l<item_len;l++)
                    {
                        if(food_item[l]=='\0')
                            break;
                        temp5[p]=food_item[l];
                        p++;
                    }
                    temp5[p]='\0';
                    strcpy(item_price[f],temp5);
                    f++;

                }
                fclose(fp3);

                char item_number[100];

                char quantity1[100];
                int quantity;

                //int price;
                //int price=0;
                char drinks[10];
                float vat;
                printf("\n\t\t\t0. back\n");
                printf("\n\n\t\t\tEnter:  ");

                scanf("%s",item_number);

                if(strcmp(item_number,"0")==0)
                {
                    system("cls");
                    goto option;
                }

                printf("\t\t\tQunatity:  ");

                scanf("%s",quantity1);

                if(atoi(quantity1)<1 || atoi(item_number)<1)
                {
                    printf("\n\n\t\t\tWrong keyword!!\n");
                    getchar();
                    printf("\t\t\tEnter any key to continue..  ");
                    getchar();
                    goto option;
                }

                quantity=atoi(quantity1);

                for(i=0;i<f;i++)
                {
                    if(strcmp(item_serial[i],item_number)==0)
                    {
                        price=quantity*atoi(item_price[i]);
                    }
                }

                char more[100];

                FILE *P;
                P=fopen("files/temp.txt","a");
                fprintf(P,"%d\n",price);
                fclose(P);

                price=0;

                printf("\n\n\t\t\tPress # to Order more\n\n");
                printf("\n\t\t\tPress * to end the order\n\n");
                printf("\t\t\tEnter  ");
                scanf("%s",more);
                if(strcmp(more,"#")==0)
                {

                    system("cls");

                    goto option;
                }
                else if(strcmp(more,"*")==0)
                    goto part;

                part:
                system("cls");
                //printf("toal price %d\n",total_price);
                printf("\n\n\n\n\n\t\t\tAny Drinks? \n");
                printf("\t\t\t1.Yes\n");
                printf("\t\t\t2.No\n");
                printf("\n\t\t\tEnter (1 or 2):  ");

                scanf("%s",drinks);

                if(atoi(drinks)<1 || atoi(drinks)>2)
                {
                    //printf("%s\n",drinks);

                    printf("\n\t\t\tWrong keyword!!\n");
                    getchar();
                    printf("\t\t\tEnter any key to continue..  ");
                    getchar();
                    //system("cls");
                    goto part;
                }

                else if(atoi(drinks)==1)
                {
                    price=price+Drinks();
                    int T=0,taka;
                    FILE *P;
                    P=fopen("files/temp.txt","r");
                    while(fscanf(P,"%d",&taka)!=EOF)
                    {
                        T+=taka;
                    }
                    fclose(P);
                    price=price + T;

                    vat=(3.0/100.0) * (float)price;

                    loading2();

                    printf("\n\t\t\t\t\t\t***CASH MEMO***\n\n\n");

                    printf("\n\t\t\tBill = %.2f\n",(float)price-vat);
                    printf("\t\t\tvat = %.2f\n",vat);
                    database(price);
                    printf("\t\t\tTotal Bill = %d\n",price);

                }

                else if(atoi(drinks)==2){

                    int T=0,taka;
                    FILE *P;
                    P=fopen("files/temp.txt","r");
                    while(fscanf(P,"%d",&taka)!=EOF)
                    {
                        T+=taka;
                    }
                    fclose(P);

                    price=price + T;

                vat=(3.0/100.0) * (float)price;

                loading2();

                printf("\n\t\t\t\t\t\t***CASH MEMO***\n\n\n");

                printf("\n\t\t\tBill = %.2f\n",(float)price-vat);
                printf("\t\t\tvat = %.2f\n",vat);
                database(price);
                printf("\t\t\tTotal Bill = %d\n",price);

                }

                FILE *P1;
                P1=fopen("files/temp.txt","w");
                fclose(P1);
                //price=0;

            }


        }


        f:

        printf("\n\t\t\tEnter 0 to return Main Menu   ");
        printf("\n\n\t\t\tEnter 1 to return back   ");
        scanf("%s",fahad);
        if(strcmp(fahad,"0")==0)
        {
            loading2();

            system("cls");
            goto MAIN_MENU;
        }
        else if(strcmp(fahad,"1")==0)
        {
            loading2();

            system("cls");
            goto option;
        }
        else
            goto f;
    }

    else if(strcmp(main_menu,"2")==0)
    {

        char enter[100];
        int Q=numbers();
        char Q_string[1000];

        system("cls");
        faizul:

            loading2();

        printf("\n\n\n\n\t\t\t***ADDING FOODS ITEM***\n\n\n\n");
        printf("\t\t\t1. Add New\n\n");
        //printf("\t\t\t2. Add Exist\n\n");
        printf("\t\t\t2. View total sell\n\n");
        printf("\t\t\t0. return Main Menu\n\n\n");
        printf("\t\t\tEnter:  ");
        scanf("%s",enter);
        getchar();
        if(strcmp(enter,"1")==0)
        {

            char food_type[1000];
            char new_food_name[1000];
            char new_food_price[1000];
            char temp[100]="files/";
            //Q--;
            itoa(Q,Q_string,100);
            system("cls");
            printf("\n\n\n\t\t\tEnter the FOOD type:  ");
            gets(food_type);
            FILE *fp4;
            fp4=fopen("files/menu.txt","a");
            fprintf(fp4,"%s %s\n",Q_string,food_type);
            fclose(fp4);



            FILE *fp5;
            strcat(temp,Q_string);
            strcat(temp,".txt");
            fp5=fopen(temp,"a");

            char *ptr;
            ptr=temp;
            int N=file_numbers(ptr);
            char N_string[1000];
            itoa(N,N_string,100);


            printf("\n\n\t\t\tEnter about %s",food_type);
            printf("\n\n\t\tEnter item Name:  ");
            gets(new_food_name);
            printf("\t\tPrice:  ");
            scanf("%s",new_food_price);

            fprintf(fp5,"\n%s %s %s\n",N_string,new_food_name,new_food_price);


            //printf("\n\t\t\tAdding.");

            loading();


            printf("\n\t\tAdded!!\n");
            getchar();

            fclose(fp5);

        }

        else if(strcmp(enter,"2")==0)
        {
            system("cls");
            printf("\n\n\n");
            loading2();
            printf("\n\n\n\t\t\t\t**Total Selling**\n\n");
            print_database();
        }
        else if(strcmp(enter,"0")==0)
        {
            system("cls");

            loading2();

            goto MAIN_MENU;
        }
        printf("\n\n\t\t\tEnter any key to back   ");
        getchar();
        system("cls");

        loading2();

        goto faizul;

    }

    else if(strcmp(main_menu,"3")==0)
    {

        char sonia[100];
        system("cls");
        rajib:

            loading2();

        printf("\n\n\n\t\t\t\t***ABOUT***\n\n");
        printf("\t\t\t1.About Project\n\n");
        printf("\t\t\t2.About Developer\n\n");
        printf("\t\t\tEnter 0 to return Main Menu\n");
        printf("\n\t\tEnter:   ");
        scanf("%s",sonia);
        getchar();
        if(strcmp(sonia,"1")==0)
        {

            loading2();

            system("cls");
            printf("\n\n\n\n");
            about_project();
        }
        else if(strcmp(sonia,"2")==0)
        {

            loading2();

            system("cls");
            printf("\n\n\n\n");
            about_developer();
        }
        else if(strcmp(sonia,"0")==0)
        {
            system("cls");
            loading2();
            goto MAIN_MENU;
        }
        printf("\n\n\t\t\tEnter any key to back   ");
        getchar();
        system("cls");

        loading2();

        goto rajib;
    }
    else if(strcmp(main_menu,"4")==0)
    {
        system("cls");
        return;
    }
    else
    {

        printf("\n\t\t\tWrong keyword!!\n");
        getchar();
        printf("\t\t\tEnter any key to continue..  ");
        getchar();
        system("cls");


        loading2();

        goto MAIN_MENU;
    }

    return 0;
}

int Drinks()
{

    char faizul[1000];
    char number[100];
    int price,i;
    char quantity[100];
    FILE *fp;
    menu1:
    fp=fopen("files/drinks.txt","r");
    printf("\n\n\n\t\t\t***Drinks***\n\n");
    while(fgets(faizul,1000,fp))
    {
        printf("\t\t\t%s",faizul);
    }
    printf("\n\n\t\t\tEnter : ");
    scanf("%s",number);

    if(atoi(number)<1 && atoi(number)>4){
        printf("\n\t\t\tWrong keyword!!\n");
        getchar();
        printf("\t\t\tEnter any key to continue..  ");
        getchar();
        system("cls");
        goto menu1;}

    printf("\t\t\tQuantity:  ");
    scanf("%s",quantity);
    if(atoi(quantity)<1)
    {
        printf("\n\t\t\tWrong keyword!!\n");
        getchar();
        printf("\t\t\tEnter any key to continue..  ");
        getchar();
        system("cls");
        goto menu1;
    }


    int NUMBER,QUANTITY;

    NUMBER=atoi(number);
    QUANTITY=atoi(quantity);

    if(NUMBER==1)
        price=QUANTITY*15;
    else if(NUMBER==2)
        price=QUANTITY*30;
    else if(NUMBER==3)
        price=QUANTITY*60;



        char more[100];

    printf("\n\n\t\t\tPress # to order more.\n");
    printf("\t\t\tPress * to end the order.\n ");
    printf("\t\t\tEnter: ");
    scanf("%s",more);

    FILE *P;
    P=fopen("files/tempdrinks.txt","a");
    fprintf(P,"%d\n",price);
    fclose(P);

    if(strcmp(more,"#")==0)
    {
        system("cls");
        goto menu1;
    }



        fclose(fp);
    FILE *P1;

    int sum,D;
    sum=0;
    P1=fopen("files/tempdrinks.txt","r");
    while(fscanf(P1,"%d",&D)!=EOF)
    {
        sum+=D;
    }
    fclose(P1);
    FILE *P2;
    P2=fopen("files/tempdrinks.txt","w");
    fclose(P2);



    return sum;

}


int numbers()
{
    char a[1000];
    FILE *fp;
    fp=fopen("files/menu.txt","r");
    int i=1;
    while(fgets(a,1000,fp))
    {
        i++;
    }
    return i;
}


int file_numbers(char *str)
{
    char a[1000];
    FILE *fp;
    fp=fopen(str,"r");
    int i=1;
    while(fgets(a,1000,fp))
    {
        i++;
    }
    return i;
}


void about_project()
{
    FILE *fp;
    char faizul[100000];
    fp=fopen("files/about/2.txt","r");
    while(fgets(faizul,10000,fp))
    {
        printf("%s",faizul);
    }
    fclose(fp);
}

void about_developer()
{
    FILE *fp;
    char faizul[100000];
    fp=fopen("files/about/1.txt","r");
    while(fgets(faizul,10000,fp))
    {
        printf("%s",faizul);
    }
    fclose(fp);
}


void database(int taka)
{
    FILE *fp;
    fp=fopen("files/Project_database.txt","a");
    fprintf(fp,"%d\n",taka);
    fclose(fp);

}

void print_database()
{
    int total;
    char taka[1000];
    FILE *fp;
    fp=fopen("files/Project_database.txt","r");
    printf("\t\t\t\tTotal Sell:\n\n");
    total=0;
    while(fscanf(fp,"%s",taka)!=EOF)
    {
        total=total+atoi(taka);
        printf("\t\t\t\t%s\n",taka);
    }
    printf("\n\t\t\tTOTAL = %d\n",total);
    fclose(fp);
}

