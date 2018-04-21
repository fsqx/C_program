#include <stdio.h>
int cnt_bit_1(unsigned char num); //计算有多少二进制的1
unsigned int encrypt(unsigned int num); //加密算法
unsigned int a_length_of_bit(unsigned int num, int begin, int end); //取出begin--end
unsigned int ro_a_length_of_bit(unsigned int num, int begin, int end);//b--e并取反
unsigned int change_bit(unsigned int num, int position, int bnum);  //修改目标bit的值
void print_bin(unsigned int num);   //二进制形式打印
unsigned int ror(unsigned int num, unsigned int times); //循环右移
unsigned int ror2(unsigned int num, unsigned int times);    //循环右移

int main()
{
    unsigned int  beef = 0xdeadbeef;
    /* printf("计算一个字节中有多少二进制数1：\n"); */
    /* printf("%d\n",cnt_bit_1(65)); */
    /* printf("%x\n",beef); */
    print_bin(0xdeadbeef);
    /* print_bin(ror(beef, 8)); */
    /* print_bin(ror2(beef, 8)); */
    /* print_bin(a_length_of_bit(beef, 8, 15)); */
    /* print_bin(ro_a_length_of_bit(beef, 8, 15)); */
    /* print_bin(change_bit(beef, 9, 1)); */
    print_bin(encrypt(beef));
    printf("%d\n",encrypt(beef));
    return 0;
}

/*求1的个数*/
int cnt_bit_1(unsigned char num)
{
    unsigned char mask = 1u;
    int temp = 0u;
    int cnt = 0;
    while(num != 0)
    {
        if((num & mask) == 1u)
        {
            cnt++;
        }
        num = num >> 1;
    }
    return cnt;

}

/*循环右移*/
unsigned int ror(unsigned int num,  unsigned int times)
{
    int i = 0;
    unsigned char mask = 1u;

    /* 使每次移动控制再0-31次之间 */
    while(times < 0)
    {
        times += 32;
    }
    times = times % 32;

    for(; i < times; i++)
    {
        num = ((num & mask) << 31) | (num >> 1);
    }
    return num; 
}

/*循环右移*/
unsigned int ror2(unsigned int num, unsigned int times)
{
    return (num >> times) | (num << 32 - times);
}

/*按位操作*/
void print_bin(unsigned int num)
{
    int cnt = 0;
    unsigned int mask = (1u << 31);
    while(mask > 0)
    {
        if(mask & num)
        {
            printf("1");
        }
        else 
        {
            printf("0");
        }
        cnt++;
        mask = mask >> 1;
        if(cnt % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

/*取对应begin--end位的值*/
unsigned int a_length_of_bit(unsigned int num, int begin, int end)
{
    int length = end - begin + 1;

    /*错误处理*/
    if(end < begin || begin > 32 || end > 32)
    {
        return 0;
    }

    /* 全0；全取反为1；左移XX个位；再取反，高位为0,低位为1 */
    int mask = ~(~0u <<  length) ;
    unsigned int newnum =(num >> begin);

    return (newnum & mask); 
}

/*取其中begin--end位的值，并取反*/
unsigned int ro_a_length_of_bit(unsigned int num, int begin, int end)
{
    int length = end - begin + 1;

    /*错误处理*/
    if(end < begin || begin > 32 || end > 32)
    {
        return 0;
    }

    /* 全0；全取反为1；左移XX个位；再取反，高位为0,低位为1 */
    int mask = ~(~0u <<  length) ;
    unsigned int newnum =(num >> begin);

    return ~(newnum & mask) & mask; 
}

/*改变某一bit为指定值*/
unsigned int change_bit(unsigned int num, int position, int bnum)
{
    unsigned int mask1 = 1u;
    unsigned int mask2 = ~mask1;
    unsigned int numtemp = ror(num, position -1);
    print_bin(mask1);
    print_bin(mask2);
    if(bnum == 1)
    {
        numtemp = numtemp | mask1;
    }
    else if(bnum == 0)
    {
        numtemp = numtemp & mask2;
    }
    else
    {
        return 0;
    }

    return ror(numtemp, 32 - position + 1);
}

/*加密算法*/
unsigned int encrypt(unsigned int num)
{
    unsigned int temp = 0u;
    unsigned int new_num = 0u;
    int i = 0;
    unsigned int mask = 1u;

    /* 循环右移和左移，通过掩码取最低位数，
     * 实际循环是编码后的数左移，原数循环右移一次，左移两次，相当于也是左移
     * 循环32次后，对应新数生成*/
    for(; i < 32; i++)
    {
        num = ror(num, 1);
        temp = num & mask;
        num = ror(num, -2);
        temp = temp ^ (num & mask);
        new_num = new_num | temp;
        new_num = new_num << 1;
        temp = 0u;
    }
    return new_num;
}
