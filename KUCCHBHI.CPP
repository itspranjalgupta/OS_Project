#include<graphics.h>
#include<iomanip.h>
#include<conio.h>
#include<string.h>
class roundrobin
{
    int  process_id[6],burst_time[6],arrival_time[6];
    int quantum,x,y;
    char d[10];
public:
    void assigndata();
    void display();
    void integer_as_character(int);
    void gantt_chart(int,int);
};
void roundrobin::assigndata()
{
  process_id[0]=1;
  burst_time[0]=20;
  arrival_time[0]=0;
  
  process_id[1]=2;
  burst_time[1]=25;
  arrival_time[1]=25;
  
  process_id[2]=3;
  burst_time[2]=25;
  arrival_time[2]=30;
  
  process_id[3]=4;
  burst_time[3]=15;
  arrival_time[3]=60;
  
  process_id[4]=5;
  burst_time[4]=10;
  arrival_time[4]=100;
  
  process_id[5]=6;
  burst_time[5]=10;
  arrival_time[5]=105;

  quantum=10;
}
void roundrobin::integer_as_character(int temp)
{
   int i;
   if(temp==0)
   {
      d[0]=48;
      d[1]=0;
     // strcpy(d,"Idle");
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
void roundrobin::gantt_chart(int id,int t)
{
    rectangle(x,y,x+30,y+30);
    if(id!=-1)
    {
       integer_as_character(id);
       outtextxy(x+12,y+12,d);
    }
    integer_as_character(t);
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
void roundrobin::display()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
	int burst[10],flag=1,flag1=0,fl=1;
    int at=0,wt,tnt,z,prev,ap,i,j,k;
    float avg=0,avtnt=0;
    outtextxy(5,56,"Process ID    Burst time   Arrival Time ");
    x=5,y=66;
    for(i=0;i<6;i++,y+=16)
    {
 integer_as_character(i+1);
 outtextxy(35,y,d);
 integer_as_character(burst_time[i]);
 outtextxy(150,y,d);
 integer_as_character(arrival_time[i]);
 outtextxy(270,y,d);
    }

    for(i=0;i<6;i++)
    burst[i]=burst_time[i];
    at=arrival_time[0];
    y+=128;
    outtextxy(x,y+10,"GANTT CHART");
    y=y+26;
    integer_as_character(at);
    outtextxy(x,y+33,d);
    z=y-144;
    outtextxy(x,z,"Process id    Waiting time    Turnaround time ");
    z=z+16;
    while(flag)
    {
 for(i=0;i<6;i++)
 {
     if(at<arrival_time[i]|| process_id[i]<0)
  continue;
     if(fl==0)
	gantt_chart(-1,at);
     fl=flag1=1;
     at+=quantum;
     burst_time[i]-=quantum;
     if(burst_time[i]<0)
   at+=burst_time[i];
     gantt_chart( process_id[i],at);
     if(burst_time[i]<=0)
     {
  wt=at-burst[i]-arrival_time[i];
  tnt=at-arrival_time[i];
  integer_as_character( process_id[i]);
  outtextxy(35,z,d);
  integer_as_character(wt);
  outtextxy(150,z,d);
  integer_as_character(tnt);
  outtextxy(270,z,d);
  z+=16;
   process_id[i]=-1;
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
 for(k=0;k<6;k++)
     if( process_id[k]!=-1)
	flag=1;
    }
    avg=avg/(float)6;
    avtnt/=(float)6;
    cout<<"\nAverage Waiting time     : "<<avg;
    cout<<"\nAverage turn Around time : "<<avtnt<<endl;




}

int main()
{
    clrscr();
    roundrobin rr;
    rr.assigndata();
    rr.display();
    getch();
    return 0;
}