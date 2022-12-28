#include <stdio.h>
#include<time.h>

int get_1st_weekday(int year,int month){
    // Create a tm structure and set the fields
    struct tm tm;
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = 1; // The first day of the month
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_isdst = -1; // Let mktime determine whether daylight saving time is in effect

    // Use mktime to convert the tm structure to a time_t value
    time_t time = mktime(&tm);

    // Use localtime to convert the time_t value to a tm structure
    struct tm *local_tm = localtime(&time);

    return local_tm->tm_wday;
}

void print_year(int year,int month){
    int day,daysInMonth,weekDay=0,startingDay;
    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((year%4==0&&year%100!=0)||year%400==0)
     monthDay[1]=29;

    startingDay=get_1st_weekday(year,month);

       daysInMonth=monthDay[month-1];
       printf("\n\n---------------%s-------------------\n",months[month-1]);
       printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

      for(weekDay=0;weekDay<startingDay;weekDay++)
        printf("     ");

      for(day=1;day<=daysInMonth;day++){
        printf("%5d",day);

        if(++weekDay>6){
            printf("\n");
            weekDay=0;
        }
        startingDay=weekDay;
      }
      printf("\n");
}

int main()
{
   int year,month,day,daysInMonth,weekDay=0,startingDay;
   char c;
   do{
   printf("\nEnter year: ");
   scanf("%d",&year);
   printf("\nEnter month number(1-12): ");
   scanf("%d",&month);
   if(!(month>=1 && month<=12)){
    printf("ENTER MONTH BW 1 TO 12!\n");
   } 
   }while(!(month>=1 && month<=12));
   print_year(year,month);
   scanf(" %c",&c);
   do{
    if(c=='a' || c=='A'){
        month--;
        if(month==0){
            year--;
            month=12;
        }
        print_year(year,month);
        
    } else if(c=='d' || c=='D'){
        month++;
        if(month==13){
            month=1;
            year++;
        }
        print_year(year,month);
        
    } else if(c=='w' || c=='W'){
        year++;
        print_year(year,month);
    
    } else if(c=='s' || 'S'){
        year--;
        print_year(year,month);

    } else if(c=='i' || c=='I'){
        printf("\nEnter year: ");
        scanf("%d",&year);
        printf("\nEnter month number(1-12): ");
        scanf("%d",&month);
        print_year(year,month);
    }
    scanf(" %c",&c);
   
   
   }while(c!=27);
}
