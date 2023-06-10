/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define size 7
int hash[size];

void insert(int key)
{
    int i=0;
    while(1)
    {
        int h = (key+ i)% size;
        if(hash[h]==-1)
        {
            hash[h] = key;
            break;
        }
        i++;
    }
    printf("Done\n");
}

int delete(int key)
{
    int i=0;
    int ret;
    while(1)
    {
        int h = (key+ i)% size;
        if(hash[h] == key)
        {
            ret = hash[h];
            hash[h] = -1;
            break;
        }
        i++;
    }
    return ret;
}

void display()
{
    for(int i=0;i<size;i++)
    {
        printf("%d\n",hash[i]);
    }
}
int main()
{
for(int i=0;i<size;i++)
{
    hash[i] = -1;
}
while(1)
{
   printf("Enter 1 to Insert elements\nEnter 2 to delete element\nEnter 3 to display\n");
   int ch;
   scanf("%d",&ch);
   switch(ch)
   {
       case 1: printf("Enter number to inserted\n");
            int n;
            scanf("%d",&n);
            insert(n);
            break;
        case 2:
             printf("Enter number to deleted\n");
             int n1;
            scanf("%d",&n1);
             printf("%d",delete(n1));
             break;
        case 3:
            display();
            break;
        default:printf("Wrong case ENtered\n");
   }
}
return 0;
}
