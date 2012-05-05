#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<string.h>

hidemouseptr();
getmousepos(int *button,int *x,int *y);
restrictmouseptr(int x1,int y1,int x2, int y2);
showmouseptr();
union REGS isa,o;


long BB[30][30],fl1,fl2,ffl1,ffl2;
long i1,j1,cp;
long i,j,A[30][30],B[30],n,m1,x,y,in,flag=0;
double pi=3.12,r,Q,start;
long X[30],Y[30],g,h,k;
char str[100];
long store[30];
long AA[30][30];
long rajib;
long A1[30][30];
long number[30],flag1[30],limit,yes;
long B1[59][59];
long si[30][30];
/////long X[50],Y[50];
long sa;
void make1(long h1,long h2)
{
long t,i;
t=store[h1-1];
for(i=1;i<=n;i++)
if(A1[t][i]==1)
{
if(i==store[0])
{
if(h2>=4)
{
limit=h1;
yes=1;
break;
}
}
else if(flag1[i]==0&&number[i]<=3)
{
flag1[i]=1;
store[h1]=i;
if(number[i]==3)
make1(h1+1,h2+1);
else
make1(h1+1,h2);
flag1[i]=0;
}
if(yes==1)
break;
}

}

void line1(long h1,long h2,long h3,long h4)
{
long i;
if(h1==h3)
{
if(h2<h4)
{for(i=h2+1;i<=h4;i++)
 B1[h1][i]=1;
}
else
{
for(i=h4;i<h2;i++)
B1[h1][i]=1;
}
}
else
{
if(h1<h3)
{for(i=h1+1;i<=h3;i++)
 B1[i][h2]=1;
}
else
{
for(i=h3;i<h1;i++)
B1[i][h2]=1;
}
}
}

void fun(long h1,long h2)
{

if(B1[X[h1]][Y[h2]]==0)
{
line1(X[h2],Y[h2],X[h1],Y[h2]);
line1(X[h1],Y[h1],X[h1],Y[h2]);
A1[h1][h2]=0;
A1[h2][h1]=0;
}
else if(B1[X[h2]][Y[h1]]==0)
{
line1(X[h2],Y[h2],X[h2],Y[h1]);
line1(X[h1],Y[h1],X[h2],Y[h1]);
A1[h1][h2]=0;
A1[h2][h1]=0;
}
else
sa=0;
}
void vertical(long h1,long h2,long h3,long h4)
{
long te1[50],p0=0,i,j;
long h7;
if(h1<h3)
{
for(i=h3;i>=h1;i--)
if(B1[i][h2]!=1)
{
h7=B1[i][h2];
for(j=1;j<=n;j++)
if(X[j]==i&&Y[j]==h2)
{
te1[p0]=j;
p0++;
break;
}
B1[i][h2]=1;
}
for(i=h1;i>=0;i--)
if(B1[i][h2]!=1)
break;
j=(h1-i)/p0;
for(i=0;i<p0;i++)
{
X[te1[i]]=h1;
B1[h1][Y[te1[i]]]=h7;
h1=h1-j;
}
}
else if(h1>h3)
{
for(i=h3;i<=h1;i++)
if(B1[i][h2]!=1)
{
h7=B1[i][h2];
for(j=1;j<=n;j++)
if(X[j]==i&&Y[j]==h2)
{
te1[p0]=j;
p0++;
break;
}
B1[i][h2]=1;
}
for(i=h1;i<=50;i++)
if(B1[i][h2]!=1)
break;
j=(i-h1)/p0;
for(i=0;i<p0;i++)
{
X[te1[i]]=h1;
B1[h1][Y[te1[i]]]=h7;
h1=h1+j;
}
}
}
void horizontal(long h1,long h2,long h3,long h4)
{
long te1[50],p0=0,i,j;
long h7;
if(h2<h4)
{
for(i=h4;i>=h2;i--)
if(B1[h1][i]!=1)
{
h7=B1[h1][i];
for(j=1;j<=n;j++)
if(X[j]==h1&&Y[j]==i)
{
te1[p0]=j;
p0++;
break;
}
B1[h1][i]=1;
}
for(i=h2;i>=0;i--)
if(B1[h1][i]!=1)
break;
j=(h2-i)/p0;
for(i=0;i<p0;i++)
{
Y[te1[i]]=h2;
B1[X[te1[i]]][Y[h2]]=h7;
h2=h2-j;
}
}
else if(h2>h4)
{
for(i=h4;i<=h2;i++)
if(B1[h1][i]!=1)
{
h7=B1[h1][i];
for(j=1;j<=n;j++)
if(X[j]==h1&&Y[j]==i)
{
te1[p0]=j;
p0++;
break;
}
B1[h1][i]=1;
}
for(i=h2;i<=50;i++)
if(B1[h1][i]!=1)
break;
j=(i-h2)/p0;
for(i=0;i<p0;i++)
{
Y[te1[i]]=h2;
B1[X[te1[i]]][h2]=h7;
h2=h2+j;
}
}
}

void band()
{
long e,i,j,x,y;
long ele[50],start,P,t,u;
long N,temp[50],temp1[50],M;
long PP[50],X1,Y1,LL;

clrscr();
cleardevice();

/////printf("\n\n\t=>");
///////while(scanf("%ld %ld",&n,&e)==2)
{
/*
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
A1[i][j]=0;
*/
sa=1;
/*
for(i=1;i<=e;i++)
{
printf("\t=>");
scanf("%ld %ld",&x,&y);
A1[x][y]=1;
A1[y][x]=1;
}
*/
for(i=1;i<=n;i++)
{
number[i]=0;
flag1[i]=0;
for(j=1;j<=n;j++)
number[i]+=A1[i][j];
}
yes=0;
for(i=1;i<=n;i++)
if(number[i]==3)
{
flag1[i]=1;
store[0]=i;
make1(1,1);
flag1[i]=0;
if(yes==1)
break;
}
if(yes==0)
{
sa=0;
}
/*
for(i=0;i<limit;i++)
printf("%ld ",store[i]);
*/
for(i=0;i<=50;i++)
for(j=0;j<=50;j++)
{
  B1[i][j]=0;
  //////C[i][j]=0;
  }
for(i=0;i<=50;i++)
{
B1[0][i]=1;
B1[50][i]=1;
B1[i][0]=1;
B1[i][50]=1;
}

for(i=1;i<=n;i++)
{
X[i]=-1;
Y[i]=-1;
ele[i]=0;
}

start=0;

P=limit;
t=P/4;
if(t*4!=P)
t++;
u=10;
for(i=0;i<t;i++)
{
X[store[i]]=0;
Y[store[i]]=u;
B1[0][u]=3;
ele[store[i]]=3;
u=u+10;
}
start=t;
P=P-t;
t=P/3;
if(t*3!=P)
t++;
u=10;
for(i=start;i<start+t;i++)
{
X[store[i]]=u;
Y[store[i]]=50;
ele[store[i]]=4;
B1[u][50]=4;
u=u+10;
}
start+=t;
P=P-t;
t=P/2;
if(t*2!=P)
t++;
u=10;
for(i=start+t-1;i>=start;i--)
{
X[store[i]]=50;
Y[store[i]]=u;
ele[store[i]]=5;
B1[50][u]=5;
u=u+10;
}
start+=t;
u=10;
for(i=start;i<limit;i++)
{
X[store[i]]=u;
Y[store[i]]=0;
ele[store[i]]=6;
B1[u][0]=6;
u=u+10;
}
for(i=0;i<limit;i++)
{
A1[store[i]][store[(i+1)%limit]]=0;
A1[store[(i+1)%limit]][store[i]]=0;
}

N=0;
for(i=1;i<=n;i++)
{
if(ele[i]==6)
{
temp[N]=i;
temp1[N]=-1;
flag1[i]=1;
N++;
}
flag1[i]=0;
}
M=0;
while(N!=M)
{
for(i=1;i<=n;i++)
if(A1[temp[M]][i]==1&&flag1[i]==0)
{
temp[N]=i;
temp1[N]=M;
N++;
flag1[i]=1;
if(ele[temp[N-1]]==4)
break;
}
M++;
if(ele[temp[N-1]]==4)
break;
}
if(ele[temp[N-1]]!=4)
{
sa=0;
}
t=N-1;
M=0;
while(t!=-1)
{
PP[M]=temp[t];
M++;
t=temp1[t];
}
X1=X[PP[M-1]];
Y1=Y[PP[M-1]];
Y1=Y1+10;
for(i=M-2;i>=1;i--)
{
X[PP[i]]=X1;
Y[PP[i]]=Y1;
B1[X1][Y1]=2;
ele[PP[i]]=2;
for(j=Y1-1;j>=Y1-9;j--)
B1[X1][j]=1;
if(i==1)
break;
Y1=Y1+10;
}
if(X[PP[0]]==X1&&Y[PP[0]]==50)
{
 for(j=Y1+1;j<50;j++)
 B1[X1][j]=1;
}
else
{
vertical(X1,50,X[PP[0]],Y[PP[0]]);
for(j=Y1+1;j<50;j++)
 B1[X1][j]=1;
}
/*
for(i=0;i<M;i++)
printf(" %ld",PP[i]);
printf("\n");
*/
for(i=0;i<M-1;i++)
{
A1[PP[i]][PP[i+1]]=0;
A1[PP[i+1]][PP[i]]=0;
}

N=0;
for(i=1;i<=n;i++)
{
if(ele[i]==3)
{
temp[N]=i;
temp1[N]=-1;
flag1[i]=1;
N++;
}
flag1[i]=0;
}
M=0;
while(N!=M)
{
for(i=1;i<=n;i++)
if(A1[temp[M]][i]==1&&flag1[i]==0)
{
temp[N]=i;
temp1[N]=M;
N++;
flag1[i]=1;
if(ele[temp[N-1]]==2)
break;
}
M++;
if(ele[temp[N-1]]==2)
break;
}
if(ele[temp[N-1]]!=2)
{
sa=0;
}
t=N-1;
M=0;
while(t!=-1)
{
PP[M]=temp[t];
M++;
t=temp1[t];
}
Y1=Y[PP[0]];
X1=X[PP[0]];
if(M!=2)
{
LL=X1/(M-1);
X1=X1-LL;
}
for(i=1;i<M-1;i++)
{
X[PP[i]]=X1;
Y[PP[i]]=Y1;
B1[X1][Y1]=2;
ele[PP[i]]=2;
for(j=X1+1;j<X1+LL;j++)
B1[j][Y1]=1;
if(i==M-2)
break;
X1=X1-LL;
}
for(j=X1-1;j>0;j--)
B1[j][Y1]=1;
X1=0;
if(Y[PP[M-1]]!=Y1)
horizontal(X1,Y1,X[PP[M-1]],Y[PP[M-1]]);
/*
for(i=0;i<M;i++)
printf(" %ld",PP[i]);
printf("\n");
*/

for(i=0;i<M-1;i++)
{
A1[PP[i]][PP[i+1]]=0;
A1[PP[i+1]][PP[i]]=0;
}

N=0;
for(i=1;i<=n;i++)
{
if(ele[i]==5)
{
temp[N]=i;
temp1[N]=-1;
flag1[i]=1;
N++;
}
flag1[i]=0;
}
M=0;
while(N!=M)
{
for(i=1;i<=n;i++)
if(A1[temp[M]][i]==1&&flag1[i]==0)
{
temp[N]=i;
temp1[N]=M;
N++;
flag1[i]=1;
if(ele[temp[N-1]]==2)
break;
}
M++;
if(ele[temp[N-1]]==2)
break;
}
if(ele[temp[N-1]]!=2)
{
sa=0;
}

t=N-1;
M=0;
while(t!=-1)
{
PP[M]=temp[t];
M++;
t=temp1[t];
}
Y1=Y[PP[0]];
X1=X[PP[0]];
LL=(50-X1)/(M-1);
if(M!=2)
X1=X1+LL;
for(i=1;i<M-1;i++)
{
X[PP[i]]=X1;
Y[PP[i]]=Y1;
B1[X1][Y1]=2;
ele[PP[i]]=2;
for(j=X1-1;j>X1-LL;j--)
B1[j][Y1]=1;
if(i==M-2)
break;
X1=X1+LL;
}
for(j=X1+1;j<50;j++)
B1[j][Y1]=1;
X1=50;
if(Y[PP[M-1]]!=Y1)
horizontal(X1,Y1,X[PP[M-1]],Y[PP[M-1]]);


for(i=0;i<M-1;i++)
{
A1[PP[i]][PP[i+1]]=0;
A1[PP[i+1]][PP[i]]=0;
}
long p0;

for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(A1[i][j]==1&&ele[i]!=0&&ele[j]!=0)
{


A1[i][j]=0;
A1[j][i]=0;
t=0;
X1=X[i];
Y1=Y[j];
if(ele[i]>=3&&ele[i]<=6&&ele[j]==2)
{
if(ele[i]==3&&B1[X[j]-1][Y[j]]==0)
{
for(p0=X[j]-1;p0>0;p0--)
B1[p0][Y[j]]=1;
if(Y[i]!=Y[j])
horizontal(X[i],Y[j],X[i],Y[i]);
t=1;
}
if(ele[i]==4&&B1[X[j]][Y[j]+1]==0)
{
for(p0=Y[j]+1;p0<50;p0++)
B1[X[j]][p0]=1;
if(X[i]!=X[j])
vertical(X[j],Y[i],X[i],Y[i]);
t=1;
}
if(ele[i]==5&&B1[X[j]+1][Y[j]]==0)
{
for(p0=X[j]+1;p0<50;p0++)
B1[p0][Y[j]]=1;
if(Y[i]!=Y[j])
horizontal(X[i],Y[j],X[i],Y[i]);
t=1;
}
if(ele[i]==6&&B1[X[j]][Y[j]-1]==0)
{
for(p0=Y[j]-1;p0>0;p0--)
B1[X[j]][p0]=1;
if(X[i]!=X[j])
vertical(X[j],Y[i],X[i],Y[i]);
t=1;
}
}

if(ele[j]>=3&&ele[j]<=6&&ele[i]==2)
{
if(ele[j]==3&&B1[X[i]-1][Y[i]]==0)
{
for(p0=X[i]-1;p0>0;p0--)
B1[p0][Y[i]]=1;
if(Y[j]!=Y[i])
horizontal(X[j],Y[i],X[j],Y[j]);
t=1;
}
if(ele[j]==4&&B1[X[i]][Y[i]+1]==0)
{
for(p0=Y[i]+1;p0<50;p0++)
B1[X[i]][p0]=1;
if(X[j]!=X[i])
vertical(X[i],Y[j],X[j],Y[j]);
t=1;
}
if(ele[j]==5&&B1[X[i]+1][Y[i]]==0)
{
for(p0=X[i]+1;p0<50;p0++)
B1[p0][Y[i]]=1;
if(Y[j]!=Y[i])
horizontal(X[j],Y[i],X[j],Y[j]);
t=1;
}
if(ele[i]==6&&B1[X[i]][Y[i]-1]==0)
{
for(p0=Y[i]-1;p0>0;p0--)
B1[X[i]][p0]=1;
if(X[j]!=X[i])
vertical(X[i],Y[j],X[j],Y[j]);
t=1;
}
}

if(t==0&&(X[i]==X[j]||Y[i]==Y[j]))
{
line1(X[i],Y[i],X[j],Y[j]);
t=1;
}

if(B1[X1][Y1]==0 && t==0)
{
line1(X[i],Y[i],X1,Y1);
line1(X[j],Y[j],X1,Y1);
}
else if(t==0)
{
X1=X[j];
Y1=Y[i];
if(B1[X1][Y1]==0)
{
line1(X[i],Y[i],X1,Y1);
line1(X[j],Y[j],X1,Y1);
}
else
sa=0;
}
}

long te_fl=0;

while(1)
{
te_fl=0;

N=0;
for(i=1;i<=n;i++)
{
if(ele[i]>=3&&ele[i]<=6)
{
temp[N]=i;
temp1[N]=-1;
flag1[i]=1;
N++;
}
else
flag1[i]=0;
}

M=0;
while(N!=M)
{
for(i=1;i<=n;i++)
if(A1[temp[M]][i]==1&&flag1[i]==0)
{
temp[N]=i;
temp1[N]=M;
N++;
flag1[i]=1;
if(ele[temp[N-1]]==2)
break;
}
M++;
if(ele[temp[N-1]]==2)
break;
}
if(ele[temp[N-1]]==2)
{
t=N-1;
M=0;
while(t!=-1)
{
PP[M]=temp[t];
M++;
t=temp1[t];
}
if(B1[X[PP[0]]][Y[PP[M-1]]]==0||Y[PP[0]]==Y[PP[M-1]])
{
line1(X[PP[0]],Y[PP[0]],X[PP[0]],Y[PP[M-1]]);
line1(X[PP[M-1]],Y[PP[M-1]],X[PP[0]],Y[PP[M-1]]);
t=Y[PP[M-1]]-Y[PP[0]];
if(X[PP[0]]==X[PP[M-1]])
t=t/(M-1);
else
t=t/(M-2);
X1=X[PP[0]];
Y1=Y[PP[0]];
Y1+=t;
for(i=1;i<M-1;i++)
{
if(i==M-2)
Y1=Y[PP[M-1]];
X[PP[i]]=X1;
Y[PP[i]]=Y1;
ele[PP[i]]=7;
B1[X1][Y1]=7;
Y1+=t;
}
te_fl=1;
}
else if(B1[X[PP[M-1]]][Y[PP[0]]]==0||X[PP[0]]==X[PP[M-1]])
{
line1(X[PP[0]],Y[PP[0]],X[PP[M-1]],Y[PP[0]]);
line1(X[PP[M-1]],Y[PP[M-1]],X[PP[M-1]],Y[PP[0]]);
t=Y[PP[M-1]]-Y[PP[0]];
if(Y[PP[0]]==Y[PP[M-1]])
t=t/(M-1);
else
t=t/(M-2);

X1=X[PP[M-1]];
Y1=Y[PP[0]];
for(i=1;i<M-1;i++)
{
X[PP[i]]=X1;
Y[PP[i]]=Y1;
ele[PP[i]]=7;
B1[X1][Y1]=7;
Y1+=t;
}
te_fl=1;
}
else
sa=0;
for(i=0;i<M-1;i++)
{
A1[PP[i]][PP[i+1]]=0;
A1[PP[i+1]][PP[i]]=0;
}
}
if(te_fl==0)
break;
}

/*
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(A1[i][j]==1)
{
fun(i,j);
}
*/
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(A1[i][j]==1&&ele[i]!=0&&ele[j]!=0)
{


A1[i][j]=0;
A1[j][i]=0;
t=0;
X1=X[i];
Y1=Y[j];
if(ele[i]>=3&&ele[i]<=6&&(ele[j]==2||ele[j]==7))
{
if(ele[i]==3&&B1[X[j]-1][Y[j]]==0)
{
for(p0=X[j]-1;p0>0;p0--)
B1[p0][Y[j]]=1;
if(Y[i]!=Y[j])
horizontal(X[i],Y[j],X[i],Y[i]);
t=1;
}
if(ele[i]==4&&B1[X[j]][Y[j]+1]==0)
{
for(p0=Y[j]+1;p0<50;p0++)
B1[X[j]][p0]=1;
if(X[i]!=X[j])
vertical(X[j],Y[i],X[i],Y[i]);
t=1;
}
if(ele[i]==5&&B1[X[j]+1][Y[j]]==0)
{
for(p0=X[j]+1;p0<50;p0++)
B1[p0][Y[j]]=1;
if(Y[i]!=Y[j])
horizontal(X[i],Y[j],X[i],Y[i]);
t=1;
}
if(ele[i]==6&&B1[X[j]][Y[j]-1]==0)
{
for(p0=Y[j]-1;p0>0;p0--)
B1[X[j]][p0]=1;
if(X[i]!=X[j])
vertical(X[j],Y[i],X[i],Y[i]);
t=1;
}
}

if(ele[j]>=3&&ele[j]<=6&&(ele[i]==2||ele[i]==7))
{
if(ele[j]==3&&B1[X[i]-1][Y[i]]==0)
{
for(p0=X[i]-1;p0>0;p0--)
B1[p0][Y[i]]=1;
if(Y[j]!=Y[i])
horizontal(X[j],Y[i],X[j],Y[j]);
t=1;
}
if(ele[j]==4&&B1[X[i]][Y[i]+1]==0)
{
for(p0=Y[i]+1;p0<50;p0++)
B1[X[i]][p0]=1;
if(X[j]!=X[i])
vertical(X[i],Y[j],X[j],Y[j]);
t=1;
}
if(ele[j]==5&&B1[X[i]+1][Y[i]]==0)
{
for(p0=X[i]+1;p0<50;p0++)
B1[p0][Y[i]]=1;
if(Y[j]!=Y[i])
horizontal(X[j],Y[i],X[j],Y[j]);
t=1;
}
if(ele[i]==6&&B1[X[i]][Y[i]-1]==0)
{
for(p0=Y[i]-1;p0>0;p0--)
B1[X[i]][p0]=1;
if(X[j]!=X[i])
vertical(X[i],Y[j],X[j],Y[j]);
t=1;
}
}

if(t==0&&(X[i]==X[j]||Y[i]==Y[j]))
{
line1(X[i],Y[i],X[j],Y[j]);
t=1;
}

if(B1[X1][Y1]==0 && t==0)
{
line1(X[i],Y[i],X1,Y1);
line1(X[j],Y[j],X1,Y1);
}
else if(t==0)
{
X1=X[j];
Y1=Y[i];
if(B1[X1][Y1]==0)
{
line1(X[i],Y[i],X1,Y1);
line1(X[j],Y[j],X1,Y1);
}
else
sa=0;
}
}


for(i=1;i<50;i++)
for(j=1;j<50;j++)
if(B1[i][j]==1)
{
t=0;
if(B1[i+1][j]!=0)
t++;
if(B1[i][j+1]!=0)
t++;
if(B1[i][j-1]!=0)
t++;
if(B1[i-1][j]!=0)
t++;
if(t>2)
sa=0;
}

/*
for(i=0;i<=50;i++)
{
for(j=0;j<=50;j++)
printf("%ld",B1[i][j]);
printf("\n");
getch();
}
getch();
*/


if(sa==0)
goto posible1;

/*
int d,m;
d=DETECT;
initgraph(&d,&m,"G:\\Install\\tc\\bgi");
*/
if(rajib==0)
{
for(i=1;i<=n;i++)
if(X[i]<0||Y[i]<0)
{sa=0; break;}

if(sa==0)
goto posible1;

clrscr();
cleardevice();
X1=100;
Y1=100;

for(i=0;i<=50;i++)
for(j=0;j<=50;j++)
{
if(B1[i][j]!=0&&B1[i][j]!=1)
circle(Y1+j*4,X1+i*4,3);
if(B1[i][j]!=0)
{
if(B1[i][j+1]!=0)
line(Y1+j*4,X1+i*4,Y1+(j+1)*4,X1+i*4);
if(B1[i+1][j]!=0)
line(Y1+j*4,X1+i*4,Y1+j*4,X1+(i+1)*4);
}
}
for(i=1;i<=n;i++)
{
long v1,v2;
char sha[10];
v1=Y1+Y[i]*4;
v2=X1+X[i]*4;
v1=v1+10;
v2=v2-10;
sha[0]=0;
sprintf(sha,"%ld",i);
outtextxy(v1,v2,sha);
}
}
posible1:
if(sa==0&&rajib==0)
printf("\n\n\n\t\tSufficient Condition Not Satisfy.");
/*
getch();
clrscr();
cleardevice();
*/
/////printf("\n\n\t=>");

}
}

////////tri-connected Graph check///////

void make(long element_1)
{
long is,js,As[30][30],fs,ss,ks;
fs=store[0];
ss=fs;
if(element_1>=2)
ss=store[1];
for(is=1;is<=n;is++)
for(js=1;js<=n;js++)
{
if(is!=fs&&is!=ss&&js!=fs&&js!=ss)
As[is][js]=A[is][js];
else
As[is][js]=0;
}
for(ks=1;ks<=n;ks++)  ////Warshal algorithm
for(is=1;is<=n;is++)
for(js=1;js<=n;js++)
if(As[is][ks]==1&&As[ks][js]==1)
As[is][js]=1;

ks=0;

for(is=1;is<=n;is++)
for(js=1;js<=n;js++)
if(is!=fs&&is!=ss&&js!=fs&&js!=ss)
if(As[is][js]==0&&AA[is][js]==1)
ks=1;
if(ks==1)
flag=0;
else if(element_1==1)
{
long tes;
for(tes=store[0]+1;tes<=n;tes++)
{
store[1]=tes;
make(2);
}
}
}
void  conected()
{
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
AA[i][j]=A[i][j];

for(k=1;k<=n;k++)  ////Warshal algorithm
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(AA[i][k]==1&&AA[k][j]==1)
AA[i][j]=1;

flag=0;

for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(A[i][j]==0&&AA[i][j]==1)
flag=1;

if(flag==1)
{
for(i=1;i<=n;i++)  /////backtack for 1 or 2 connecitivity
{
store[0]=i;
make(1);
if(flag==0)
break;
}

}

if(flag==0)
printf("This is not a tri-connected Graph.");
else
printf("This is a tri-connected Graph.");
}

////////tri-connected Graph check///////


void grapicaly()
{
cleardevice();
clrscr();
hidemouseptr();
rectangle(50,50,100,100);
outtextxy(60,60,"Node");
rectangle(150,50,200,100);
outtextxy(160,60,"Edge");
rectangle(250,50,300,100);
outtextxy(260,60,"End");
delay(500);
showmouseptr();
int lo_x[100],lo_y[100],node=1;
int indicator=0;
int button,x,y;
int p_f = -1;
int i,j;
char strp[10];
while(1)
{
 getmousepos(&button,&x,&y);
 if((button & 2)==2)
  {
  break;
  }
 if((button & 1)==1)
 {
 if(x>=250&&x<=300&&y>=50&&y<=100)
 break;
 else if(x>=50&&x<=100&&y>=50&&y<=100)
 indicator=1;
 else if(x>=150&&x<=200&&y>=50&&y<=100)
 {
  indicator=2;
  for(i=1;i<=node;i++)
  for(j=1;j<=node;j++)
  si[i][j]=0;
 }
 else if(indicator==1)
 {
 lo_x[node]=x;
 lo_y[node]=y;
 node++;
 hidemouseptr();
 circle(x,y,5);
 strp[0]=0;
 sprintf(strp,"%d",node-1);
 outtextxy(x+10,y+10,strp);
 delay(500);
 showmouseptr();
 }
 else if(indicator==2)
 {
 int nop=-1;
 float g1,g2;
 for(i=1;i<node;i++)
 {
 g1=x-lo_x[i];
 g2=y-lo_y[i];
 g1=g1*g1+g2*g2;
 g1=sqrt(g1);
 if(g1<=5.0)
 {  nop=i; break; }
 }
 if(p_f==-1)
 {
 p_f=nop;
 delay(500);
 }
 else
 {
 si[p_f][nop]=1;
 si[nop][p_f]=1;
 hidemouseptr();
 line(lo_x[p_f],lo_y[p_f],lo_x[nop],lo_y[nop]);
 delay(500);
 showmouseptr();
 p_f=-1;
 }

 }
 }


}

n=node-1;
for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   {
    A[i][j]=si[i][j];
    A1[i][j]=si[i][j];
    }

}
void table()
{
long m1,x,y;

clrscr();
cleardevice();
printf("\n\n\tNumber of node and edges: ");
scanf("%ld %ld",&n,&m1);

for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   {
    A[i][j]=0;
    A1[i][j]=0;
    si[i][j]=0;
    }
   for(i=1;i<=m1;i++)
   {
   printf("\t=>");
   scanf("%ld %ld",&x,&y);
   A[x][y]=1;
   A[y][x]=1;
   A1[x][y]=1;
   A1[y][x]=1;
   si[x][y]=1;
   si[y][x]=1;
   }

}


int main()
{
   clrscr();
   int d,m;
   d=DETECT;
   initgraph(&d,&m,"G:\\Install\\tc\\bgi");
   printf("\n\n\t");
   printf("Enter your number of Node and Edge:");
   while(1)
   {
   /////Graph Input/////////////
int button,x,y;
clrscr();
cleardevice();
rectangle(100,50,500,100);
/////////settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
outtextxy(120,60,"1 - band orthogonal drawing.");
rectangle(100,200,200,250);
outtextxy(110,210,"Graphical");
rectangle(300,200,400,250);
outtextxy(320,210,"Table");
rectangle(200,300,300,350);
outtextxy(210,310,"Exit");
restrictmouseptr(0,0,600,600);  //55,445,585,455
delay(500);
showmouseptr();

int input_type=0;

while(1)
{
 getmousepos(&button,&x,&y);
 if((button & 2)==2)
  {
  input_type=-1;
  break;
  }
 if((button & 1)==1)
 {
 if(x>=200&&x<=300&&y>=300&&y<=350)
{ input_type=-1;
break;}
 if(x>=100&&x<=200&&y>=200&&y<=250)
 {
  grapicaly();
  input_type=2;
  break;
 }
 if(x>=300&&x<=400&&y>=200&&y<=250)
 {
 hidemouseptr();
 table();
 input_type=1;
 showmouseptr();
 break;
 }

 }

 }

if(input_type==-1)
break;
hidemouseptr();
/*
   for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   {
    A[i][j]=0;
    A1[i][j]=0;
    }
   for(i=1;i<=m1;i++)
   {
   printf("\t=>");
   scanf("%ld %ld",&x,&y);
   A[x][y]=1;
   A[y][x]=1;
   A1[x][y]=1;
   A1[y][x]=1;
   }
*/
   clrscr();
  cleardevice();
   /////Graph Input/////////////
   //////Conectivity Check//////
   for(i=1;i<=n;i++)
   B[i]=0;
   for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   if(A[i][j]==1)
   B[i]++;
   clrscr();
   in=0;
   for(i=1;i<=n;i++)
   if(B[i]>in)
   in=B[i];
 /////  printf("\n\n\t%ld Conected Graph",in);
  //////Conectivity Check//////
  //////Draw Graph/////////
  x=300;y=300;r=150;
  Q=360/n;
  start=0;
  for(i=1;i<=n;i++)
  {
  X[i]=x+r*cos(start*pi/180.0);
  Y[i]=y-r*sin(start*pi/180.0);
  start+=Q;
  }

if(input_type==2)
goto sha;


for(i=1;i<=n;i++)
{
circle(X[i],Y[i],2);
str[0]=0;
sprintf(str,"%ld",i);
outtextxy(X[i]+3,Y[i],str);
}

for(i=1;i<=n;i++)
for(j=i;j<=n;j++)
if(A[i][j]==1)
{
line(X[i],Y[i],X[j],Y[j]);
}
//////Draw Graph/////////

  getch();
  sha:
  clrscr();
  cleardevice();
/////Planer check/////
  flag=1;

  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  BB[i][j]=0;

  for(i=1;i<=n;i++)
  for(j=i;j<=n;j++)
  if(A[i][j]==1)
  {
  fl1=0;
  fl2=0;
  for(g=i+1;g<j;g++)
  for(h=1;h<=n;h++)
  if(A[g][h]==1&&h<i)
   {
   if(BB[g][h]==0)
   fl1=1;
   else if(BB[g][h]==1)
   fl2=1;
   }
   if((fl1==0&&fl2==0)||(fl1==0&&fl2==1))
   {BB[i][j]=0;BB[j][i]=0;}
   else if(fl1==1&&fl2==0)
   {BB[i][j]=1;BB[j][i]=1;}
   else
   flag=0;
  }
  /////Planer check/////
  if(flag==0)
  {
  rajib=1;
  band();
  rajib=0;
  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
  A1[i][j]=si[i][j];
  A[i][j]=si[i][j];
  }
  if(sa==0)
  printf("\n\tThis is not a Planer Graph.\n");
  else
  {
  printf("\n\tThis is Planer Graph.\n");
  goto next;
  }
  }
  else
  {
  printf("\n\tThis is Planer Graph.\n");
  /////Planer Draw/////
  for(i=1;i<=n;i++)
  {
  circle(X[i],Y[i],2);
  str[0]=0;
  sprintf(str,"%ld",i);
  outtextxy(X[i]+3,Y[i],str);
  }
for(i=1;i<=n;i++)
for(j=i;j<=n;j++)
if(A[i][j]==1)
{
if(BB[i][j]==0)
line(X[i],Y[i],X[j],Y[j]);
else
{
setcolor(RED);
cp=0;
for(i1=i;i1<=j;i1++)
for(j1=i1+1;j1<=j;j1++)
if(BB[i1][j1]==1)
cp++;
cp--;
fl1=X[i];
fl2=Y[i];
for(k=i;k<=j;k++)
{
ffl1=X[k];
ffl2=Y[k];

if(Y[k]<300)
ffl2=ffl2-10-(cp*10);
else if(Y[k]>300)
ffl2+=10+(cp*10);
if(X[k]<300)
ffl1=ffl1-10-(cp*10);
else if(X[k]>300)
ffl1+=10+(cp*10);

line(ffl1,ffl2,fl1,fl2);
fl1=ffl1;fl2=ffl2;
}
line(fl1,fl2,X[j],Y[j]);
setcolor(WHITE);
}
}
/////Planer Draw/////
  next:
  getch();
  clrscr();
  cleardevice();
  printf("\n\n\t");
  ////4 Planer Graph Check//////////////
  if(in==4)
  {
  printf("This is a 4-Graph.");
  getch();
  clrscr();
  cleardevice();
  printf("\n\n\t");
  conected();
  getch();
  clrscr();
  cleardevice();
  band();
  }
  else
  printf("This is not a 4-Graph.");
 ////4 Planer Graph Check//////////////
 }
  getch();
  clrscr();
  cleardevice();
  }
    showmouseptr();
////closegraph();

return 0;
}


initmouse()
{isa.x.ax=0;
 int86(0x33,&isa,&o);
 return(o.x.ax);
}
getmousepos(int *button,int *x,int *y)
{isa.x.ax=3;
 int86(0x33,&isa,&o);
 *button=o.x.bx;
 *x=o.x.cx;
 *y=o.x.dx;
}
showmouseptr()
{isa.x.ax=1;
 int86(0x33,&isa,&o);
}
restrictmouseptr(int x1,int y1,int x2, int y2)
{isa.x.ax=7;
 isa.x.cx=x1;
 isa.x.dx=x2;
 int86(0x33,&isa,&o);
 isa.x.ax=8;
 isa.x.cx=y1;
 isa.x.dx=y2;
 int86(0x33,&isa,&o);
 }

hidemouseptr()
{
	isa.x.ax=2;
    int86(0x33,&isa,&o);


}