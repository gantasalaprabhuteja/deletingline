#include <stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp1,*fp2;
    char filename[40];
    char ch;
    int deleteline, count = 1,i;
    printf("Enter file name: ");
    scanf("%s", filename);
    fp1 = fopen(filename, "r");
    ch = getc(fp1);
    printf("Enter line number of the line to be deleted:");
    scanf("%d", &deleteline);
    fp2 = fopen("replica.c", "w");
    ch = getc(fp1);
    rewind(fp1);
    while(ch != EOF)
    {
        ch = getc(fp1);
        if (ch == '\n')
            count++;
            if (count!= deleteline)
            {
                  putc(ch, fp2);
            }
    }
    fclose(fp1);
    fclose(fp2);
    remove(filename);
    rename("replica.c", filename);
    fclose(fp1);
    return 0;
}