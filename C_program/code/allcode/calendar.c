#include <stdio.h>

int zeller(int century, int year, int month, int day); // 蔡勒公式
void print_day(int month, int day, int week, int *month_array); //顺序打印某一天
int day_cycle(int century, int year, int month, int *month_array);  //天数循环
void month_cycle(int century, int year);    //月份循环


int main()
{
    int AD;
    static int century = 0;
    static int year = 0;
    printf("输入年份获得日历：");
    scanf("%d", &AD);
    century = AD / 100;
    year = AD % 100;
    month_cycle(century, year);    
    //print_day(2,28,zeller(20,18,2,28),month_array);
    //printf("%d\n",zeller(20,17,3,1));
    return 0;
}

/*蔡勒公式判断星期*/
int zeller(int century, int year, int month, int day)
{
     /****************************************
     * 蔡勒公式
     * 公元1年12月30日正好是周日
     * 蔡勒公式首先计算距这天的日期
     * 然后天数MOD 7后，余数对应周几
     * 此余数可能为负数
     * 因此天数加上7的整倍数再MOD7 得到结果即为正确的星期
     ****************************************/

    /*一月和二月当作去年的13月和14月参与计算*/
    if(month == 1)
    {
        month = 13;
        year--;
    }
    if(month == 2)
    {
        month = 14;
        year--;
    }

    return (70 + year + year / 4 + century / 4 - 2 * century
                + 26 * (month + 1) / 10 + day - 1) % 7; //蔡勒公式

}

/*一月中按日循环判断输出*/
int day_cycle(int century, int year, int month, int *month_array)
{

    int i;
    int week = 0;
    int end_day = month_array[month - 1];//月份对应到数组中的天数
    for(i = 1; i <= end_day; i++)
    {
        week = zeller(century, year, month, i); //判断这一天是周几
        print_day(month, i, week, month_array); //根据月 日 周顺序打印
    }
}

/*打印当天日期*/
void print_day(int month, int day, int week, int *month_array)
{
    int weekcopy = week;
    if(day == 1) //打印第一天以及空出第一天前
    {
        while (weekcopy-- > 0)
        {
            printf("   ");
        }
        printf("%2d ", day);
        if(week == 6)   //每到星期六，换行
        {
            printf("\n");
        }
    }
    /*按顺序打印中间日子*/
    else if(day > 1 && day < month_array[month -1])
    {
        printf("%2d ", day);
        if(week == 6)   //每到星期六，换行
        {
            printf("\n");
        }
    }
    else
    {
        printf("%2d ", day);
        while (weekcopy++ < 6)
        {
            printf("   ");
        }
        printf("\n");
    }


}

/*分每月情况*/
void month_cycle(int century, int year)
{
    int i;
    int month_array[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /*四年一润*/
    if(year % 4 == 0)
    {
        *(month_array + 1) == 29;
    }

    /*百年不润*/
    if(year % 100 == 0)
    {
        *(month_array + 1) == 28;
    }

    /*四百年又润*/
    if(year % 400 == 0)
    {
        *(month_array + 1) == 29;
    }

    /*按月打印*/
    for(i = 1; i <= 12; i++)
    {
        printf("%d月:\n", i);
        printf("日 一 二 三 四 五 六 \n");
        day_cycle(century, year, i, month_array);
        printf("\n");
    }
}
