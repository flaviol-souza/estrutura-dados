#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100

char *p[MAX];
char *qretrieve(void);
int spos = 0;
int rpos = 0;
void enter(void);
void qstore(char *q);
void review(void);
void delete_ap(void);

int main() {
   char str[10];
   register int t;
   
   for(t=0; t<MAX; t++) {
      p[t] = NULL;
   }
   for(;;) {
      printf("Press E, L, R, or Q for enter, list, remove, or quit :");
      gets(str);
      *str = toupper(*str);

      switch(*str)
      {
         case 'E' :
            enter();
            break;
         case 'L' :
            review();
            break;
         case 'R' :
            delete_ap();
            break;
         case 'Q' :
            exit(1);
         default :
            printf("Wrong choice..!!\n");
            printf("Press any key to exit...");
            getch();
            exit(2);
      }
   }
   getch();
   return 0;
}

void enter(void) {
   char str[10], *p;

   do {
      printf("Enter appointment %d : ", spos+1);
      gets(str);
      if(*str==0) {               
        break;
      }
      p = (char *) malloc(strlen(str)+1);
      if(!p) {
         printf("Out of memory..!!\n");
         return;
      }
      strcpy(p, str);
      if(*str)
         qstore(p);
   } while(*str);
}

void review(void) {
   register int t;

   for(t=rpos; t<spos; t++)
   {
      printf("%d. %s\n", t+1, p[t]);
   }
}

void delete_ap(void) {
   char *p;

   if((p=qretrieve())==NULL)
   {
      return;
   }
   printf("%s\n", p);
}

void qstore(char *q) {
   if(spos==MAX)
   {
      printf("List Full..!!\n");
      return;
   }
   p[spos] = q;
   spos++;
}

char *qretrieve(void) {
   if(rpos==spos)
   {
      printf("No more appointments..!!\n");
      return NULL;
   }
   rpos++;
   return p[rpos-1];
}
