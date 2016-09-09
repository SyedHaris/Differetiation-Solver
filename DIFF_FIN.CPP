#include<conio.h>
#include<stdio.h>
#include<string.h>
void eq(int ,int *,int *);
int sint(char *,int *,int *,int *);
void diff(int *,int *,int);
void diff(int *j,int *k,int l)
{
int i;
for(i=0;i<l;i++)
{
j[i]=j[i]*k[i];
k[i]=k[i]-1;
}
}
int sint(char *a,int *co,int *p)
{
int c[30],i=0,j=0,l,k,size;
while(a[i]!='\0')
{
c[j]=0;
if(a[i]=='x')
i+=2;
if(a[i]=='-' || a[i]=='+' || a[i]=='(' || a[i]==')')
i++;
if(a[i-1]=='-')
{
while(a[i]>='0' && a[i]<='9')
{
c[j]=c[j]*10+(a[i]-48);
i++;
}
c[j]*=-1;
j++;
}
else
{while(a[i]>='0' && a[i]<='9')
{
c[j]=c[j]*10+(a[i]-48);
i++;
}
j++;
}
}
size=j/2;
l=0;
for(k=0;k<j-1;k++)
{
if(k%2==0)
{
co[l]=c[k];
l++;
}
}
l=0;
for(k=0;k<j-1;k++)
{
if(k%2!=0)
{p[l]=c[k];
l++;
}
}
return(size);
}
void eq(int j,int *k,int *l)
{
int i,h=0;
for(i=0;i<j;i++)
{
if(k[i]==0)
continue;
else if(k[i]>0 && h>0)
{
printf("+%dx^%d",k[i],l[i]);
h++;
}
else if(k[i]<0 || (k[i]>0 && h==0))
{
printf("%dx^%d",k[i],l[i]);
h++;
}
}
}
void main()
{
clrscr();
int c[30],n[20],size,i,s,uc[20],un[20],vc[20],vn[20],duc[20],dun[20],dvc[20],dvn[20],s1c[20],s1n[20],k=0,j,s2n[20],s2c[20],l=0,ac[20],an[20],m=0,ac2[20],an2[20],nu,de,u1[20],u2[20],v1[20],v2[20],du1[20],du2[20],dv1[20],dv2[20],u3[20],u4[20],v3[20],v4[20],rc[20],rn[20],tp=0,p[20],co[20],tp2;
char a[15],b[15],h[20],f[6],t[4],t2[4];
FILE *c1;
printf("Press 1 for f'(x) of polynomials\nPress 2 for f'(x) of rational function\nPress 3 for f'(x) of tignometric functions(sin,cos or tan)\n");
printf("ENTE YOUR CHOICE=");
scanf("%d",&s);
switch(s)
{
case 1:
c1=fopen("case1.txt","r");
while(fgets(h,65,c1)!=NULL)
puts(h);
fclose(c1);
printf("Enter equation=");
fflush(stdin);
gets(a);
size=sint(a,c,n);
diff(c,n,size);
printf("f'(x)=");
eq(size,c,n);
break;
case 2:
c1=fopen("case2.txt","r");
while(fgets(h,65,c1)!=NULL)
puts(h);
fclose(c1);
fflush(stdin);
printf("Enter numerator=");
gets(a);
nu=sint(a,u1,u2);
fflush(stdin);
printf("Enter denominator=");
gets(b);
de=sint(b,v1,v2);
for(i=0;i<de;i++)
{
dv1[i]=v1[i]*v2[i];
dv2[i]=v2[i]-1;
}
for(i=0;i<nu;i++)
{
du1[i]=u1[i]*u2[i];
du2[i]=u2[i]-1;
}
for(i=0;i<de;i++)
{
for(j=0;j<nu;j++)
{
u3[k]=v1[i]*du1[j];
u4[k]=v2[i]+du2[j];
k++;
}
}
for(i=0;i<nu;i++)
{
for(j=0;j<de;j++)
{
v3[l]=u1[i]*dv1[j];
v4[l]=u2[i]+dv2[j];
v3[l]=v3[l] * -1;
l++;
}
}
for(i=0;i<k;i++)
{
for(j=i+1;j<k;j++)
{
if(u4[i]==u4[j])
{
u3[i]=u3[i]+u3[j];
u3[j]=0;
}
}
}
for(i=0;i<k;i++)
{
rc[m]=u3[i];
rn[m]=u4[i];
for(j=0;j<l;j++)
{
if(u4[i]==v4[j])
{
rc[m]=rc[m]+v3[j];
v3[j]=0;
}
}
m++;
}
for(i=0;i<l;i++)
{
if(v3[i]!=0)
{
rc[m]=v3[i];
rn[m]=v4[i];
m++;
}
}
printf("f'(x)=");
eq(m,rc,rn);
printf("/");
printf("(");
for(i=0;i<de;i++)
{
if((i>=1 && v1[i]>0))
printf("+%dx^%d",v1[i],v2[i]);
else
printf("%dx^%d",v1[i],v2[i]);
}
printf(")^2");
break;
case 3:
c1=fopen("case3.txt","r");
while(fgets(h,65,c1)!=NULL)
puts(h);
fclose(c1);
fflush(stdin);
printf("Enter tignometric function=");
gets(f);
i=0;
while(f[i]!='\0')
{
if((f[i]<'0' || f[i]>'9') && (f[i]!='^'))
t[i]=f[i];
else if((f[i]>='0' || f[i]<='9') && (f[i]!='^'))
tp=tp*10+(f[i]-48);
i++;
}
fflush(stdin);
printf("Input angle=");
gets(a);
fflush(stdin);
size=sint(a,co,p);
diff(co,p,size);
if(t[0]=='s')
strcpy(t2,"cos");
if(t[0]=='c')
strcpy(t2,"-sin");
if(t[0]=='t')
strcpy(t2,"sec^2");
tp2=tp-1;
if(tp==1)
{
printf("%s",t2);
printf(" %s ",a);
eq(size,co,p);
}
if(tp!=1)
{
printf("%d",tp);
printf(" %s ",t);
printf("^%d",tp2);
printf("%s",a);
printf(" %s",t2);
printf(" %s",a);
eq(size,co,p);
}
}
getch();
}





















