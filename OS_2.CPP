#include<graphics.h>
#include<iomanip.h>
#include<conio.h>
#include<string.h>
class roundrobin
{
    int process_id[6],burst_time[6],arrival_time[6];
    int quantum,x,y;
    char char_id[10];
public:
    void assigndata();
    void display();
    void integer_as_character(int);
    void chart(int,int);
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

  quantum=0;

}
void roundrobin::integer_as_character(int id)
{
   if(id==0)
   {
      strcpy(char_id,"Idle");
      return;
   }
   else if(id==1)
   {
	   strcpy(char_id,"P1");
	   return;
   }
   else if(id==2)
   {
	   strcpy(char_id,"P2");
	   return;
   }
   else if(id==3)
   {
	   strcpy(char_id,"P3");
	   return;
   }
   else if(id==4)
   {
	   strcpy(char_id,"P4");
	   return;
   }
   else if(id==5)
   {
	   strcpy(char_id,"P5");
	   return;
   }
   else if(id==6)
   {
	   strcpy(char_id,"P6");
	   return;
   }
   else
   {
   for(int i=0;id!=0;i++)
   {
	char_id[i]=id%10+48;
	id/=10;
   }
   char_id[i]=0;
   strrev(char_id);
   return;
   }

}
void roundrobin::chart(int id,int t)
{
    rectangle(x,y,x+30,y+30);
    if(id!=-1)
    {
       integer_as_character(id);
       outtextxy(x+12,y+12,char_id);
    }
    integer_as_character(t);
    if(t>=10)
       outtextxy(x+24,y+33,char_id);
    else
       outtextxy(x+30,y+33,char_id);
    x+=30;
    if(x+60>getmaxx())
    {
       y+=50;
       x=5;
       outtextxy(x,y+33,char_id);
    }
}

void roundrobin::display()
{
    int bursts[10],flag=1,flag1=0,fl=1;
    int at=0,wt,i,tnt,z=y+10,prev,ap;







	int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
    /*outtextxy(5,56,"Process ID    Execution time   Arrival Time ");
    x=5,y=66;
    for(i=0;i<6;i++,y+=16)
    {
 integer_as_character(i+1);
 outtextxy(35,y,char_id);
 integer_as_character(burst_time[i]);
 outtextxy(150,y,char_id);
 integer_as_character(arrival_time[i]);
 outtextxy(270,y,char_id);
	}
*/















    for(i=0;i<6;i++)
 bursts[i]=burst_time[i];
    at=arrival_time[0];
    y+=128;
    outtextxy(x,y+10,"GANTT CHART");
    y=y+26;
   // int_to_ch(at);
    outtextxy(x,y+33,char_id);
    /*outtextxy(x,z,"Process id    Waiting time    Turn around time ");
    z=z+16;*/
    while(flag)
    {
 for(int i=0;i<6;i++)
 {
     if(at<arrival_time[i]||process_id[i]<0)
  continue;
     if(fl==0)
	chart(-1,at);
     fl=flag1=1;
     at+=quantum;
     burst_time[i]-=quantum;
     if(burst_time[i]<0)
   at+=burst_time[i];
     chart(process_id[i],at);
     if(burst_time[i]<=0)
     {
  wt=at-bursts[i]-arrival_time[i];
  tnt=at-arrival_time[i];
  //integer_as_character(process_id[i]);
  //outtextxy(35,z,char_id);
  //integer_as_character(wt);
  //outtextxy(150,z,char_id);
  //integer_as_character(tnt);
  //outtextxy(270,z,char_id);
  //z+=16;
  process_id[i]=-1;

     }
 }
	  if(flag1==0)
 {
    at++;
    fl=0;
 }
 flag1=flag=0;
 for(int k=0;k<6;k++)
     if(process_id[k]!=-1)
        flag=1;
    }
 
 
 
 }
}
void main()
{
    clrscr();
	roundrobin rr;
    rr.assigndata();
    rr.display();
    getch();

}
