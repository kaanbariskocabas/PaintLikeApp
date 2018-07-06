#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
static int colorNo = 0,pencilNo = 6,eraserNo = 10;
static int sekilNo = 0,mX = 0,mY = 0;
static int mXdizi[3] = {0,0},mYdizi[3] = {0,0};
int pencil();
int eraser();
int shapes();
int tasarim();
using namespace std;
int koordinatSifirlama()
{
    for(int i=0;i<3;i++)
    {
        mXdizi[i]=0;
        mYdizi[i]=0;
    }
}
int mouseClick()
{
    while(1)
    if(ismouseclick(WM_LBUTTONDOWN))
{
    int x = mousex();
    int y = mousey();
            //COLOR
             if(x>800&&y>100)
             {
             for(int i=0;i<16;i++)
             {
                 if(x>=830&&x<=860&&y>150+(i*30)&&y<170+(i*30))
                 {
                     setcolor(i);
                     colorNo=i;
                     printf("colorNo = %d\n",colorNo);
                 }
             }
            }
            //SHAPES
             if(x<200&&y>100)
             {
                //Line
                if(x>=100&&y>=140&&x<=150&&y<=160)
                {
                     clearmouseclick(WM_LBUTTONDOWN);
                     clearmouseclick(WM_LBUTTONDBLCLK);
                     printf("line\n");
                     sekilNo=0;
                     shapes();
                }
                //Rectangle
                if((x>=100&&y>=275&&x<=150&&y<=325))
                {
                     clearmouseclick(WM_LBUTTONDOWN);
                     clearmouseclick(WM_LBUTTONDBLCLK);
                     printf("rectangle\n");
                     sekilNo=1;
                     shapes();
                }
                //Circle
                if(x>=100&&y>=425&&x<=150&&y<=475)
                {
                     clearmouseclick(WM_LBUTTONDOWN);
                     clearmouseclick(WM_LBUTTONDBLCLK);
                     printf("circle\n");
                     sekilNo=2;
                     shapes();
                }
                //Triangle
                if(x>=100&&y>=600&&x<=150&&y<=650)
                {
                     clearmouseclick(WM_LBUTTONDOWN);
                     clearmouseclick(WM_LBUTTONDBLCLK);
                     printf("triangle\n");
                     sekilNo=3;
                     shapes();
                }
             }
             //TOOLS
             if(x>200&&y<100)
             {
                 //NEW
                 if(x>=190&&x<=230&&y>=35&&y<=60)
                 {
                     setfillstyle(SOLID_FILL,WHITE);
                     setcolor(WHITE);
                     tasarim();
                 }
                 //OPEN
                 if(x>=305&&x<=355&&y>=35&&y<=60)
                 {
                     readimagefile(NULL,200, 100, 800, 700);
                 }
                 //Pencil
                 if(x>=420&&x<=485&&y>=35&&y<=72)
                 {
                     if(x>=440&&x<=445&&y>=65&&y<=70)
                     pencilNo=3;
                     else if(x>=448&&x<=454&&y>=65&&y<=71)
                     pencilNo=6;
                     else if(x>=460&&x<=469&&y>=63&&y<=72)
                     pencilNo=9;
                     else
                     pencilNo=6;
                     clearmouseclick(WM_LBUTTONDOWN);
                     clearmouseclick(WM_LBUTTONDBLCLK);
                     printf("pencil No : %d\n",pencilNo);
                     pencil();
                 }
                 //Eraser
                 if(x>=535&&x<=600&&y>=35&&y<=73)
                 {
                     if(x>=550&&x<=555&&y>=68&&y<=73)
                     eraserNo=5;
                     else if(x>=563&&x<=573&&y>=65&&y<=75)
                     eraserNo=10;
                     else if(x>=581&&x<=595&&y>=61&&y<=76)
                     eraserNo=15;
                     else
                     eraserNo=10;
                     clearmouseclick(WM_LBUTTONDOWN);
                     clearmouseclick(WM_LBUTTONDBLCLK);
                     printf("eraser No : %d\n",eraserNo);
                     eraser();
                 }
                 //SAVE
                 if(x>=650&&x<=700&&y>=35&&y<=60)
                 {
                      writeimagefile(NULL,200, 100, 800, 700);
                 }
                 //EXIT
                 if(x>=740&&x<=790&&y>=35&&y<=60)
                 {
                      exit(0);
                 }

             }
clearmouseclick(WM_LBUTTONDOWN);
}
getch();
return 0;
}
int shapes()
{
int sayac=0,temp=0,xFarki=0,yFarki=0,koordinatSayisi=0,poly[8];
koordinatSifirlama();
//setfillstyle(SOLID_FILL,colorNo);
setcolor(colorNo);
    bas:
    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            mXdizi[sayac]=mousex();
            mYdizi[sayac]=mousey();
            clearmouseclick(WM_LBUTTONDOWN);
            if(sekilNo==3)
            {
                sayac++;
                sayac=sayac%3;
                koordinatSayisi=3;
                if(mXdizi[0]>200&&mXdizi[0]<800&&mYdizi[0]>100&&mYdizi[0]<700&&sayac==1)
                goto bas;
                if(mXdizi[0]>200&&mXdizi[0]<800&&mYdizi[0]>100&&mYdizi[0]<700&&mXdizi[1]>200&&mXdizi[1]<800&&mYdizi[1]>100&&mYdizi[1]<700&&sayac==2)
                goto bas;
            }
            else
            {
                sayac++;
                sayac=sayac%2;
                koordinatSayisi=2;
                if(mXdizi[0]>200&&mXdizi[0]<800&&mYdizi[0]>100&&mYdizi[0]<700&&sayac==1)
                goto bas;
            }

            if(mXdizi[0]>200&&mXdizi[0]<800&&mYdizi[0]>100&&mYdizi[0]<700&&mXdizi[1]>200&&mXdizi[1]<800&&mYdizi[1]>100&&mYdizi[1]<700&&koordinatSayisi==2)
            {
                            if(mXdizi[0]!=0&&mXdizi[1]!=0)
                            {
                                if(sekilNo==0)
                                {
                                    line(mXdizi[0],mYdizi[0],mXdizi[1],mYdizi[1]);
                                }
                                if(sekilNo==1)
                                {
                                    if(mXdizi[0]>mXdizi[1])
                                    {
                                    temp=mXdizi[0];
                                    mXdizi[0]=mXdizi[1];
                                    mXdizi[1]=temp;
                                    }
                                    if(mYdizi[0]>mYdizi[1])
                                    {
                                    temp=mYdizi[0];
                                    mYdizi[0]=mYdizi[1];
                                    mYdizi[1]=temp;
                                    }
                                    rectangle(mXdizi[0],mYdizi[0],mXdizi[1],mYdizi[1]);
                                    koordinatSifirlama();
                                }
                                if(sekilNo==2)
                                {
                                    if(mXdizi[0]>mXdizi[1])
                                    {
                                    temp=mXdizi[0];
                                    mXdizi[0]=mXdizi[1];
                                    mXdizi[1]=temp;
                                    }
                                    if(mYdizi[0]>mYdizi[1])
                                    {
                                    temp=mYdizi[0];
                                    mYdizi[0]=mYdizi[1];
                                    mYdizi[1]=temp;
                                    }
                                    xFarki = (mXdizi[1]-mXdizi[0])/2;
                                    yFarki = (mYdizi[1]-mYdizi[0])/2;
                                    if(xFarki<=yFarki)
                                    {
                                        circle(mXdizi[0]+xFarki,mYdizi[0]+yFarki,xFarki);
                                    }
                                    if(xFarki>yFarki)
                                    {
                                        circle(mXdizi[0]+xFarki,mYdizi[0]+yFarki,yFarki);
                                    }
                                    koordinatSifirlama();
                                }


                            }
                }
                else if(mXdizi[0]>200&&mXdizi[0]<800&&mYdizi[0]>100&&mYdizi[0]<700&&mXdizi[1]>200&&mXdizi[1]<800&&mYdizi[1]>100&&mYdizi[1]<700&&mXdizi[2]>200&&mXdizi[2]<800&&mYdizi[2]>100&&mYdizi[2]<700&&koordinatSayisi==3)
                {
                    poly={mXdizi[0],mYdizi[0],mXdizi[1],mYdizi[1],mXdizi[2],mYdizi[2],mXdizi[0],mYdizi[0]};
                    drawpoly(4,poly);
                }
        else
        {
                clearmouseclick(WM_LBUTTONUP);
                clearmouseclick(WM_LBUTTONDOWN);
                mouseClick();
        }
    }
    else
    goto bas;
}
}
int eraser()
{
    setfillstyle(SOLID_FILL,15);
    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
        mX = mousex();
        mY = mousey();

        if(mX>200&&mX<800&&mY>100&&mY<700)
        {

        if(GetAsyncKeyState(VK_LBUTTON))
        {
            bar(mX ,mY ,mX+eraserNo ,mY+eraserNo);
        }
        }
    else
        {
            clearmouseclick(WM_LBUTTONUP);
            clearmouseclick(WM_LBUTTONDOWN);
            mouseClick();
        }
        }
    }
}

int pencil()
{
    setfillstyle(SOLID_FILL,colorNo);
    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
        mX = mousex();
        mY = mousey();

        if(mX>200&&mX<800&&mY>100&&mY<700)
        {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            bar(mX ,mY ,mX+pencilNo ,mY+pencilNo);
        }

        }
    else
        {
            clearmouseclick(WM_LBUTTONUP);
            clearmouseclick(WM_LBUTTONDOWN);
            mouseClick();
        }
    }
    }
}
int tasarim()
{
    bar(200,100,800,700);
    outtextxy(200,40,"NEW");
    outtextxy(315,40,"OPEN");
    outtextxy(430,40,"PENCIL");
    bar(440,67,443,70);
    bar(448,65,454,71);
    bar(460,63,469,72);
    outtextxy(545,40,"ERASER");
    bar(550,68,555,73);
    bar(563,65,573,75);
    bar(581,61,596,76);
    outtextxy(660,40,"SAVE");
    outtextxy(770,40,"EXIT");
    //COLORS
    setfillstyle(SOLID_FILL,0);
    bar(830,150,860,170);
    rectangle(830,150,860,170);
    for(int i=1;i<16;i++)
    {
        setfillstyle(SOLID_FILL,i);
        bar(830,150+(i*30),860,170+(i*30));
    }
    //SHAPES
    setcolor(5);
    line(100,150,150,150);
    rectangle(100,275,150,325);
    circle(125,450,25);
    //Ucgen
    line(125,600,100,650);
    line(150,650,125,600);
    line(100,650,150,650);
    mouseClick();
    }
int main()
{
    int mX,mY,x,y;
    initwindow( 1000, 800, "PAINT", 10, 10);
    tasarim();
    getch();
    closegraph();
    return 0;
}
