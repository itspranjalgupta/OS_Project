#include<graphics.h>
#include<iomanip.h>
#include<conio.h>
#include<string.h>
class rr_alg
{
    int ar[10],id[10],exe[10];
    int n,q,x,y;
    char d[10];
    void sort(int *f,int *mid,int *last);
public:
    void getdata();
    void display();
    void cal_wt_tt();
    void int_to_ch(int);
    void chart(int,int);
};
void rr_alg::getdata()
{
    cout<<"How many process to be entered : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
 cout<<"Enter execution time and arrival time of process "<<i+1<<" : ";
 cin>>exe[i]>>ar[i];
 id[i]=i+1;
    }
    cout<<"Enter Quantum slice : ";
 cin>>q;
}
void rr_alg::int_to_ch(int temp)
{
   int i;
   if(temp==0)
   {
      d[0]=48;
      d[1]=0;
      return;
   }
   for(i=0;temp!=0;i++)
    {
 d[i]=temp%10+48;
 temp/=10;
    }
    d[i]=0;
    strrev(d);
}
void rr_alg::chart(int id,int t)
{
    rectangle(x,y,x+30,y+30);
    if(id!=-1)
    {
       int_to_ch(id);
       outtextxy(x+12,y+12,d);
    }
    int_to_ch(t);
    if(t>=10)
       outtextxy(x+24,y+33,d);
    else
       outtextxy(x+30,y+33,d);
    x+=30;
    if(x+60>getmaxx())
    {
       y+=50;
       x=5;
       outtextxy(x,y+33,d);
    }
}
void rr_alg::display()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
    outtextxy(5,56,"Process ID    Execution time   Arrival Time ");
    x=5,y=66;
    for(int i=0;i<n;i++,y+=16)
    {
 int_to_ch(i+1);
 outtextxy(35,y,d);
 int_to_ch(exe[i]);
 outtextxy(150,y,d);
 int_to_ch(ar[i]);
 outtextxy(270,y,d);
    }
}
void rr_alg::sort(int *f,int *mid,int *last)
{
    int temp;
    for(int y=0;y<n-1;y++)
    {
 for(int z=0;z<n-1;z++)
     if(f[z]>f[z+1])
     {
  temp=f[z];
  f[z]=f[z+1];
  f[z+1]=temp;
  temp=mid[z];
  mid[z]=mid[z+1];
  mid[z+1]=temp;
  temp=last[z];
  last[z]=last[z+1];
  last[z+1]=temp;
     }
    }
}
void rr_alg::cal_wt_tt()
{
    int exe2[10],flag=1,flag1=0,fl=1;
    int at=0,wt,tnt,z=y+10,prev,ap;
    float avg=0,avtnt=0;
    sort(ar,id,exe);
    for(int i=0;i<n;i++)
 exe2[i]=exe[i];
    at=ar[0];
    y+=(n+2)*16;
    outtextxy(x,y+10,"GANTT CHART");
    y=y+26;
    int_to_ch(at);
    outtextxy(x,y+33,d);
    outtextxy(x,z,"Process id    Waiting time    Turn around time ");
    z=z+16;
    while(flag)
    {
 for(int i=0;i<n;i++)
 {
     if(at<ar[i]||id[i]<0)
  continue;
     if(fl==0)
        chart(-1,at);
     fl=flag1=1;
     at+=q;
     exe[i]-=q;
     if(exe[i]<0)
   at+=exe[i];
     chart(id[i],at);
     if(exe[i]<=0)
     {
  wt=at-exe2[i]-ar[i];
  tnt=at-ar[i];
  int_to_ch(id[i]);
  outtextxy(35,z,d);
  int_to_ch(wt);
  outtextxy(150,z,d);
  int_to_ch(tnt);
  outtextxy(270,z,d);
  z+=16;
  id[i]=-1;
  avg+=wt;
  avtnt+=tnt;
     }
 }
 if(flag1==0)
 {
    at++;
    fl=0;
 }
 flag1=flag=0;
 for(int k=0;k<n;k++)
     if(id[k]!=-1)
        flag=1;
    }
    avg=avg/(float)n;
    avtnt/=(float)n;
    cout<<"\nAverage Waiting time     : "<<avg;
    cout<<"\nAverage turn Around time : "<<avtnt<<endl;
}
int main()
{
    rr_alg rr;
    rr.getdata();
    rr.display();
    rr.cal_wt_tt();
    getch();
    return 0;
} 
