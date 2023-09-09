///Be name Khoda


#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>

using namespace std;



#define pb push_back


const int N=11;


int mouse=0;

struct Color{
    int red;
    int blue;
    int green;
};
int ScoreP1;
int ScoreP2;
int ScoreCopmuter;
int ScoreP;
int NumberOfPlayers;
Color color1,color2;
int level;
int ai;
int opp;


vector <int> board[N];


int NumberOfColumns;
int NumberOfRows;
bool ComputerTurn;
//bool GameEnded;
//int ScoreOfEachColumn[N];
int aksha[1000100];


int checkRow(int x,int y){
    int ret=0;
    for(int i=y;i<y+4;i++){
        if(board[i].size()>x){
            if(board[i][x]==2){
                ai++;
            }
            if(board[i][x]==1){
                opp++;
            }
        }
    }
    if(ai==3 && opp==0){
        ret+=5;
    }
    if(ai==4){
        ret+=10000;
    }
    if(ai==2 && opp==0){
        ret+=2;
    }
    if(opp==3 && ai==0){
        ret-=4;
    }
    if(opp==4){
        ret-=9000;
    }
    return ret;
}
int checkColumn(int x,int y){
    int ai=0,opp=0,ret=0;
    for(int i=y;i<y+4;i++){
        if(board[x].size()>i){
            if(board[x][i]==2){
                ai++;
            }
            if(board[x][i]==1){
                opp++;
            }
        }
    }
    if(ai==3 && opp==0){
        ret+=5;
    }
    if(ai==4){
        ret+=10000;
    }
    if(ai==2 && opp==0){
        ret+=2;
    }
    if(opp==3 && ai==0){
        ret-=4;
    }
    if(opp==4){
        ret-=9000;
    }
    return ret;
}
int checkMovarabSouthToNorth(int x,int y){
    int ai=0,opp=0,ret=0;
    for(int i=0;i<4;i++){
        if(board[x+i].size()>y+i){
            if(board[x+i][y+i]==2){
                ai++;
            }
            if(board[x+i][y+i]==1){
                //printf("\ns %d %d %d \n",x+i,y+i,board[x+i][y+i]);
                opp++;
            }
        }
    }
    //printf("s%d\n",y);
    if(ai==3 && opp==0){
        ret+=5;
    }
    if(ai==4){
        ret+=10000;
    }
    if(ai==2 && opp==0){
        ret+=2;
    }
    if(opp==3 && ai==0){
        ret-=4;
    }
    if(opp==4){
        ret-=9000;
    }
    return ret;
}
int checkMovarabNorthToSouth(int x,int y){
    int ai=0,opp=0,ret=0;
    for(int i=0;i<4;i++){
        int chert=board[x+i].size();
        if(chert>x+i){
            if(board[x+i][y-i]==2){
                ai++;
            }
            if(board[x+i][y-i]==1){
                opp++;
            }
        }
    }
    if(ai==3 && opp==0){
        ret+=5;
    }
    if(ai==4){
        ret+=10000;
    }
    if(ai==2 && opp==0){
        ret+=2;
    }
    if(opp==3 && ai==0){
        ret-=4;
    }
    if(opp==4){
        ret-=9000;
    }
    return ret;
}


int ComputerColor;
int PlayerColor;
int player1color;
int player2color;
int neshanehgarKEY;



int scoreYab(){
    /*printf("FSDFDS\n");
    for(int i=0;i<7;i++){
        for(int j=0;j<board[i].size();j++){
            printf("%d ",board[i][j]);
        }
        if(board[i].size()==0){
            printf("0");
        }
        printf("\n");
    }*/
    //ofoghi
    int ret=0;
    for(int i=0;i<=NumberOfRows;i++){
        for(int j=0;j<NumberOfColumns-3;j++){
            ret+=checkRow(i,j);
            ai=0;
            opp=0;
        }
    }
    for(int i=0;i<NumberOfColumns;i++){
        for(int j=0;j<NumberOfRows-3;j++){
            ret+=checkColumn(i,j);
            ai=0;
            opp=0;
        }
    }
    for(int i=0;i<NumberOfColumns-3;i++){
        for(int j=0;j<NumberOfRows-3;j++){
            ret+=checkMovarabSouthToNorth(i,j);
            ai=0;
            opp=0;
        }
    }
    for(int i=0;i<NumberOfColumns-3;i++){
        for(int j=NumberOfRows-1;j>=3;j--){
            ret+=checkMovarabNorthToSouth(i,j);
            ai=0;
            opp=0;
        }
    }
    int tmp=NumberOfColumns/2;
    for(int i=0;i<NumberOfRows;i++){
        if(board[tmp].size()>i)
            if(board[tmp][i]==2){
                ret+=4;
            }
    }
    //printf("SDSAD %d\n",ret);
    return ret;
}
int penaltywinner=0;
int gameEnded(){
    if(penaltywinner){
        return -1*penaltywinner;
    }
    for(int i=0;i<NumberOfRows;i++){
        for(int j=0;j<NumberOfColumns-3;j++){
            int ai=0,opp=0;
            for(int k=j;k<j+4;k++){
                if(board[k].size()>i){
                    if(board[k][i]==2){
                        ai++;
                    }
                    if(board[k][i]==1){
                        opp++;
                    }
                }
            }
            if(ai==4){
                return 1;
            }
            if(opp==4){
                return 2;
            }
        }
    }
    for(int i=0;i<NumberOfColumns;i++){
        for(int j=0;j<NumberOfRows-3;j++){
            int ai=0,opp=0;
            for(int k=j;k<j+4;k++){
                if(board[i].size()>k){
                    if(board[i][k]==2){
                        ai++;
                    }
                    if(board[i][k]==1){
                        opp++;
                    }
                }
            }
            if(ai==4){
                return 1;
            }
            if(opp==4){
                return 2;
            }
        }
    }
    for(int i=0;i<NumberOfColumns-3;i++){
        for(int j=0;j<NumberOfRows-3;j++){
            int ai=0,opp=0;
            for(int k=0;k<4;k++){
                if(board[i+k].size()>j+k){
                    if(board[i+k][j+k]==2){
                        ai++;
                    }
                    if(board[i+k][j+k]==1){
                        opp++;
                    }
                }
            }
            if(ai==4){
                return 1;
            }
            if(opp==4){
                return 2;
            }
        }
    }
    for(int i=0;i<NumberOfColumns-3;i++){
        for(int j=NumberOfRows;j>=0;j--){
            int ai=0,opp=0;
            for(int k=0;k<4;k++){
                if(board[i+k].size()>j-k){
                    if(board[i+k][j-k]==2){
                        ai++;
                    }
                    if(board[i+k][j-k]==1){
                        opp++;
                    }
                }
            }
            if(ai==4){
                return 1;
            }
            if(opp==4){
                return 2;
            }
        }
    }
    //cout<<endl;
    for(int i=0;i<7;i++){
        //cout<<"NAVID"<<endl;
        if(board[i].size()!=6){
            return 0;
        }
        //cout<<i<<" "<<board[i].size();
    }
    return 3;

}

int gameEnded2(){
    if(penaltywinner){
        return -1*penaltywinner;
    }
    for(int i=0;i<NumberOfRows;i++){
        for(int j=0;j<NumberOfColumns-3;j++){
            int ai=0,opp=0;
            for(int k=j;k<j+4;k++){
                if(board[k].size()>i){
                    if(board[k][i]==2){
                        ai++;
                    }
                    if(board[k][i]==1){
                        opp++;
                    }
                }
            }
            if(ai==4){
                return 1;
            }
            if(opp==4){
                return 2;
            }
        }
    }
    for(int i=0;i<NumberOfColumns;i++){
        for(int j=0;j<NumberOfRows-3;j++){
            int ai=0,opp=0;
            for(int k=j;k<j+4;k++){
                if(board[i].size()>k){
                    if(board[i][k]==2){
                        ai++;
                    }
                    if(board[i][k]==1){
                        opp++;
                    }
                }
            }
            if(ai==4){
                return 1;
            }
            if(opp==4){
                return 2;
            }
        }
    }
    for(int i=0;i<NumberOfColumns-3;i++){
        for(int j=0;j<NumberOfRows-3;j++){
            int ai=0,opp=0;
            for(int k=0;k<4;k++){
                if(board[i+k].size()>j+k){
                    if(board[i+k][j+k]==2){
                        ai++;
                    }
                    if(board[i+k][j+k]==1){
                        opp++;
                    }
                }
            }
            if(ai==4){
                return 1;
            }
            if(opp==4){
                return 2;
            }
        }
    }
    for(int i=0;i<NumberOfColumns-3;i++){
        for(int j=NumberOfRows;j>=0;j--){
            int ai=0,opp=0;
            for(int k=0;k<4;k++){
                if(board[i+k].size()>j-k){
                    if(board[i+k][j-k]==2){
                        ai++;
                    }
                    if(board[i+k][j-k]==1){
                        opp++;
                    }
                }
            }
            if(ai==4){
                return 1;
            }
            if(opp==4){
                return 2;
            }
        }
    }
    //cout<<endl;
    for(int i=0;i<7;i++){
        //cout<<"NAVID"<<endl;
        if(board[i].size()!=6){
            return 0;
        }
        //cout<<i<<" "<<board[i].size();
    }
    return 3;

}

struct NextMove{
    int vazn;
    int Move;
};

NextMove dfs(int height,bool turn){
   // printf("%d\n",height);
    //if turn==0 -> computer turn
    int mini=1e9+7;
    int maxi=-1e9+7;
    NextMove ret;
    if(gameEnded()==1){
        ret.vazn=10000;
        ret.Move=-1;
        return ret;
    }
    if(gameEnded()==2){
        ret.vazn=-9000;
        ret.Move=-1;
        return ret;
    }
    if(gameEnded()==3){
        ret.vazn=0;
        ret.Move=-1;
        return ret;
        //draw
    }
    if(height>4){
        ret.vazn=scoreYab();
        ret.Move=-1;
        return ret;
    }

    for(int i=0;i<NumberOfColumns;i++){
        if(board[i].size()>=NumberOfRows){
            continue;
        }
        //mohre ye computer is 2
        if(turn==0){
            board[i].pb(2);
        }
        else{
            board[i].pb(1);
        }
        if(gameEnded()==1 && !turn){
            ret.vazn=10000;
            ret.Move=i;
            board[i].pop_back();
            return ret;
        }
        if(gameEnded()==2 && turn){
            ret.vazn=-9000;
            ret.Move=i;
            board[i].pop_back();
            return ret;
        }
        if(turn==0){
            if(maxi<dfs(height+1,1-turn).vazn){
                maxi=dfs(height+1,1-turn).vazn;
                ret.Move=i;
            }
        }
        if(turn==1){
            if(mini>dfs(height+1,1-turn).vazn){
                mini=dfs(height+1,1-turn).vazn;
                ret.Move=i;
            }
        }
        /*mini=min(dfs(height+1,1-turn),mini);
        maxi=max(dfs(height+1,1-turn),maxi);*/
        board[i].pop_back();
    }
    if(turn==0){
        ret.vazn=maxi;
        return ret;
    }
    ret.vazn=mini;
    return ret;
}

NextMove dfs1(int height,bool turn){
   // printf("%d\n",height);
    //if turn==0 -> computer turn
    int mini=1e9+7;
    int maxi=-1e9+7;
    NextMove ret;
    if(gameEnded()==1){
        ret.vazn=10000;
        ret.Move=-1;
        return ret;
    }
    if(gameEnded()==2){
        ret.vazn=-9000;
        ret.Move=-1;
        return ret;
    }
    if(gameEnded()==3){
        ret.vazn=0;
        ret.Move=-1;
        return ret;
        //draw
    }
    if(height>1){
        ret.vazn=scoreYab();
        ret.Move=-1;
        return ret;
    }

    for(int i=0;i<NumberOfColumns;i++){
        if(board[i].size()>=NumberOfRows){
            continue;
        }
        //mohre ye computer is 2
        if(turn==0){
            board[i].pb(2);
        }
        else{
            board[i].pb(1);
        }
        if(gameEnded()==1 && !turn){
            ret.vazn=10000;
            ret.Move=i;
            board[i].pop_back();
            return ret;
        }
        if(gameEnded()==2 && turn){
            ret.vazn=-9000;
            ret.Move=i;
            board[i].pop_back();
            return ret;
        }
        if(turn==0){
            if(maxi<dfs1(height+1,1-turn).vazn){
                maxi=dfs1(height+1,1-turn).vazn;
                ret.Move=i;
            }
        }
        if(turn==1){
            if(mini>dfs1(height+1,1-turn).vazn){
                mini=dfs1(height+1,1-turn).vazn;
                ret.Move=i;
            }
        }
        /*mini=min(dfs(height+1,1-turn),mini);
        maxi=max(dfs(height+1,1-turn),maxi);*/
        board[i].pop_back();
    }
    if(turn==0){
        ret.vazn=maxi;
        return ret;
    }
    ret.vazn=mini;
    return ret;
}



void jadvaloChapKon(){
    printf("FSDFDS\n");
    for(int i=0;i<7;i++){
        for(int j=0;j<board[i].size();j++){
            printf("%d ",board[i][j]);
        }
        if(board[i].size()==0){
            printf("0");
        }
        printf("\n");
    }
    printf("FSDFDS\n");
}



void background(int col){
    setfillstyle(1,col);
    bar(0,0,1200,800);
}


void redCircle(int x,int y,int radius){
    //setcolor(COLOR(125,10,10));
    setcolor(YELLOW);
    setlinestyle(0,0,1);
    circle(x,y,radius);
    setfillstyle(SOLID_FILL,COLOR(125,10,10));
    //fillellipse(x,y,radius,radius);
    floodfill(x,y-radius+15,YELLOW);
    floodfill(x,y+radius-15,YELLOW);
   /* setfillstyle(1,COLOR(170,10,10));
    setcolor(COLOR(125,10,10));
    //fillellipse(x,y,radius-10,radius-10);*/
    //floodfill(x,y-radius,)
}

void blueCircle(int x,int y,int radius){
    /*setcolor(COLOR(10,10,125));

    setfillstyle(1,COLOR(10,10,125));
    fillellipse(x,y,radius,radius);
    setfillstyle(1,COLOR(10,10,170));
    setcolor(COLOR(10,10,125));
    fillellipse(x,y,radius-10,radius-10);*/
    //setcolor(COLOR(125,10,10));
    setcolor(YELLOW);
    setlinestyle(0,0,1);
    circle(x,y,radius);
    setfillstyle(SOLID_FILL,COLOR(10,10,125));
    //fillellipse(x,y,radius,radius);
    floodfill(x,y-radius+15,YELLOW);
    floodfill(x,y+radius-15,YELLOW);
   /* setfillstyle(1,COLOR(170,10,10));
    setcolor(COLOR(125,10,10));
    //fillellipse(x,y,radius-10,radius-10);*/
    //floodfill(x,y-radius,)
}






void loadBoard(){
    //initwindow(1200,800);
    background(0);
    //Rectangle(50,50,,600)
    //setfillstyle(1,COLOR(212,161,23));
    setcolor(WHITE);
    rectangle(1100,400,1150,450);
    setlinestyle(0,0,3);
    setcolor(14);
    rectangle(100, 100,750, 670);
    for(int j=0;j<6;j++){
        for(int i=0;i<7;i++){
            //redCircle(100+55+i*90,100+55+j*90,40);
            setcolor(14);
            circle(155+i*90,155+j*90,35);
        }
    }
    setfillstyle(1,14);
    floodfill(105,105,14);
    for(int i=0;i<NumberOfColumns;i++){
        setfillstyle(1,BLACK);
        setcolor(YELLOW);
        fillellipse(90*i+155,120,10,10);
    }
    setfillstyle(1,LIGHTRED);
    bar(850,155,1150,300);
    setbkcolor(LIGHTRED);
    setcolor(BLACK);
    settextstyle(10,0,3);
    outtextxy(900,170,"YOU");
    outtextxy(1000,170,"COMPUTER");
    setfillstyle(1,WHITE);
    bar(905,195,940,230);
    bar(1035,195,1070,230);
    char sc1[40],sc2[40];
    sprintf(sc1,"%d",ScoreP);
    sprintf(sc2,"%d",ScoreCopmuter);
    setbkcolor(WHITE);
    outtextxy(915,200,sc1);
    outtextxy(1045,200,sc2);
}

void loadBoard2(){
    initwindow(1200,800);
    background(0);
    //Rectangle(50,50,,600)
    //setfillstyle(1,COLOR(212,161,23));
    setlinestyle(0,0,3);
    setcolor(14);
    rectangle(100, 100,750, 670);
    for(int j=0;j<6;j++){
        for(int i=0;i<7;i++){
            //redCircle(100+55+i*90,100+55+j*90,40);
            setcolor(14);

            circle(100+55+i*90,100+55+j*90,35);
        }
    }
    setfillstyle(1,14);
    floodfill(105,105,14);
    for(int i=0;i<NumberOfColumns;i++){
        setfillstyle(1,BLACK);
        setcolor(YELLOW);
        fillellipse(90*i+155,120,10,10);
    }
    setfillstyle(1,LIGHTRED);
    bar(850,155,1150,300);
    setbkcolor(LIGHTRED);
    setcolor(BLACK);
    settextstyle(10,0,3);
    outtextxy(890,170,"player1");
    outtextxy(1010,170,"player2");
    setfillstyle(1,WHITE);
    bar(905,195,940,230);
    bar(1035,195,1070,230);
    char sc1[40],sc2[40];
    sprintf(sc1,"%d",ScoreP1);
    sprintf(sc2,"%d",ScoreP2);
    setbkcolor(WHITE);
    outtextxy(915,200,sc1);
    outtextxy(1045,200,sc2);
}
void bendaz(int turn,int col){
    int hala=board[col].size();
    int avalx=col*90+155;
    int avaly=155;
    int next;
    getimage(0,0,1200,800,aksha);
    int ch=-1;
    if(hala<4){
        ch=2;
    }
    cout<<hala<<endl;
    for(int i=0;i<13-hala*2;i++){
        //cleardevice();
        //loadBoard();
        putimage(0,0,aksha,0);
        if(turn==2){
            redCircle(avalx,avaly,40);
        }
        else{
            blueCircle(avalx,avaly,40);
        }
        if(ch!=-1){
            if((ch && ch<2) || (ch==2 && i==13-hala*2-1)){
                ch--;
                i-=2;
                avaly-=90;
                Sleep(60);
            }
        }
        if(ch==0){
            Sleep(60);
        }
        Sleep(60);
        avaly+=45;
    }
}

void neshoonehKEY(int pre,int nex){
    setfillstyle(1,BLACK);
    setcolor(YELLOW);
    fillellipse(90*pre+155,120,10,10);
    setfillstyle(1,CYAN);
    fillellipse(90*nex+155,120,10,10);
}

time_t forsat1,forsat2;

void settings(){
    initwindow(1200,800);
    while(!kbhit){
        if(ismouseclick(WM_LBUTTONDOWN)){
            closegraph;
        }
    }
}

int neshanbede(int player){
    neshoonehKEY(0,0);//previous , next
    int now1=0;
    forsat1=time(0);
    int rr=5;
    time_t i1=time(0),i2;
        if(!mouse){
            while(1){
                int x=mousex();
                int y=mousey();
                if(ismouseclick(WM_LBUTTONDOWN)){
                    clearmouseclick(WM_LBUTTONDOWN);
                    if(x<1150 && x>1100 && y>400 && y<450){
                        closegraph();
                        settings();
                    }
                }
                forsat2=time(0);
                int forsat;
                forsat=forsat2-forsat1;
                int l=forsat/2;
                l*=40;
                setfillstyle(1,BLACK);
                bar(700-l,70,700,85);
                if(forsat>=20){
                    penaltywinner=-1*player;
                    return penaltywinner;
                }
                char c=getch();

                if(c=='a'){
                    if(now1==0){
                        continue;
                    }
                    neshoonehKEY(now1,now1-1);
                    now1--;
                }
                if(c=='d'){
                    if(now1==6){
                        continue;
                    }
                    neshoonehKEY(now1,now1+1);
                    now1++;
                }
                if(c=='s'){
                    if(board[now1].size()==NumberOfRows)
                        continue;
                    neshoonehKEY(now1,0);
                    return now1;
                }
            //_getch();
            }
        }
        if(mouse){
            while(!kbhit()){
                forsat2=time(0);
                int forsat;
                forsat=forsat2-forsat1;
                int l=forsat/2;
                l*=40;
                setfillstyle(1,BLACK);
                bar(700-l,70,700,85);
                if(forsat>=20){
                    penaltywinner=-1*player;
                    return penaltywinner;
                }
                int x=mousex();
                int y=mousey();
                x-=155;
                x/=90;
                if(x<7 && x>=0){
                    int tmp=x;
                    neshoonehKEY(now1,tmp);
                    now1=tmp;
                }
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(board[now1].size()==NumberOfRows)
                        continue;
                    clearmouseclick(WM_LBUTTONDOWN);
                    return now1;
                }

            }
        }
}

string CheatCodeKam="pcbxjcf";
string CheatCodeZiad="knbtvnq";


void updateBoard(int player,int what){
    if(player==1){
        ScoreP++;
    }
    else{
        ScoreCopmuter+=what;
    }
}

void updateBoard2(int player,int what){
    if(player==1){
        ScoreP1++;
    }
    else{
        ScoreP2+=what;
    }
}


void getMohre(){
    setfillstyle(1,GREEN);
    setlinestyle(0,0,1);
    bar(300,70,700,85);
    int inputColumn;
    //scanf("%d",&inputColumn);

    inputColumn=neshanbede(1);
    /*while(!kbhit()){

    }*/
    if(inputColumn<0){
        return;
    }
    board[inputColumn].pb(1);
    bendaz(PlayerColor,inputColumn);
    //printf("%d\n",board[0].size());
}
void getMohre2(int turn){
    setfillstyle(1,GREEN);
    setlinestyle(0,0,1);
    bar(300,70,700,85);
    int inputColumn;
    //scanf("%d",&inputColumn);
    inputColumn=neshanbede(turn);
    /*while(!kbhit()){

    }*/
    board[inputColumn].pb(turn);
    bendaz(turn,inputColumn);
    //printf("%d\n",board[0].size());
}

void playWithLevelHard(){

    initwindow(1200,800);
    loadBoard();
   // cout<<"32423434";
      // cout<<"GSFHDFHADFS"<<endl<<gameEnded()<<endl;
       //jadvaloChapKon();
    while(!gameEnded()){
        if(ComputerTurn){
            NextMove tmp=dfs(0,0);
            printf("rewerw %d\n",tmp.vazn);
            if(tmp.vazn>9000){
                settextstyle(10,0,2);
                setbkcolor(CYAN);
                setcolor(RED);
                outtextxy(900,700,"FEKR KONAM MIBAZI!");
            }
            if(tmp.vazn<-5000){
                settextstyle(10,0,2);
                setbkcolor(CYAN);
                setcolor(RED);
                outtextxy(900,700,"AGE KHOOB BAZI BOKONI MIBARI!");
            }

            board[tmp.Move].pb(2);
            bendaz(ComputerColor,tmp.Move);
            jadvaloChapKon();
            printf("%d\n",tmp.Move);
            ComputerTurn=0;
            continue;
        }
        getMohre();
        ComputerTurn=1;
    }
}



void playWithLevelEasy(){
    initwindow(1200,800);
    background(0);
    loadBoard();
    while(!gameEnded()){
        if(ComputerTurn){
            int alaki=1;
            while(alaki){
                int y=rand();
                y%=7;
                if(board[y].size()<NumberOfRows){
                    board[y].pb(2);
                    bendaz(ComputerColor,y);
                    break;
                }
            }
            ComputerTurn=0;
            continue;
        }
        getMohre();
        ComputerTurn=1;
    }
}
void playWithLevelMedium(){
    initwindow(1200,800);
    background(0);
    loadBoard();
    while(!gameEnded()){
        if(ComputerTurn){
            NextMove tmp=dfs1(0,0);
            printf("rewerw %d\n",tmp.vazn);
            board[tmp.Move].pb(2);
            bendaz(ComputerColor,tmp.Move);
            jadvaloChapKon();
            printf("%d\n",tmp.Move);
            ComputerTurn=0;
            continue;
        }
        getMohre();
        ComputerTurn=1;
    }
}



void getLevelOfAI(){
    initwindow(1200,800);
    background(DARKGRAY);
    settextstyle(10,0,5);
    setbkcolor(DARKGRAY);
    setcolor(WHITE);
    outtextxy(470,25,"SELECT LEVEL");
    setfillstyle(1,LIGHTGREEN);
    setcolor(LIGHTGREEN);
    fillellipse(120,170,70,70);
    setfillstyle(1,YELLOW);
    setcolor(YELLOW);
    fillellipse(120,370,70,70);
    setfillstyle(1,COLOR(245,24,24));
    setcolor(COLOR(245,24,24));
    fillellipse(120,570,70,70);
    setcolor(COLOR(245,24,24));
    settextstyle(8,0,5);
    setbkcolor(DARKGRAY);
    setcolor(WHITE);
    outtextxy(220,150,"Easy Peasy lemon squeezy");
    outtextxy(220,350,"Not that Easy");
    outtextxy(220,550,"It needs a very big \"JIGAR\"");
    int dise;
    int dism;
    int dish;
    bool tmp=0;
    while(!kbhit()){
        if(ismouseclick(WM_LBUTTONDOWN)){
            int x=mousex();
            int y=mousey();
            dise=(x-120)*(x-120)+(y-170)*(y-170);
            dism=(x-120)*(x-120)+(y-370)*(y-370);
            dish=(x-120)*(x-120)+(y-570)*(y-570);
            clearmouseclick(WM_LBUTTONDOWN);
            if(dise<4900){
                tmp=1;
            }
            if(dism<4900){
                tmp=1;
            }
            if(dish<4900){
                tmp=1;
            }
            if(tmp){
                closegraph();
                break;
            }
        }
    }
    //loadBoard();
    time_t zaman2,zaman1=time(0);
    if(dise<4900){
        playWithLevelEasy();
        zaman2=time(0);
        int tim=zaman2-zaman1;
        char tym[50];
        sprintf(tym,"%d",tim);
        setcolor(BLACK);
        outtextxy(800,650,"FINAL TIME : ");
        outtextxy(980,650,tym);
        outtextxy(1030,650,"SECONDS");
    }
    if(dism<4900){
        playWithLevelMedium();
        zaman2=time(0);
        int tim=zaman2-zaman1;
        char tym[50];
        sprintf(tym,"%d",tim);
        setcolor(BLACK);
        outtextxy(800,650,"FINAL TIME : ");
        outtextxy(980,650,tym);
        outtextxy(1030,650,"SECONDS");
    }
    if(dish<4900){
        playWithLevelHard();
        zaman2=time(0);
        int tim=zaman2-zaman1;
        char tym[50];
        sprintf(tym,"%d",tim);
        setcolor(BLACK);
        outtextxy(800,650,"FINAL TIME : ");
        outtextxy(980,650,tym);
        outtextxy(1030,650,"SECONDS");
    }
    int ans=gameEnded();
    cout<<"barande is "<<ans;
    if(ans==1){
        settextstyle(6,0,10);
        setbkcolor(RED);
        setcolor(LIGHTGREEN);
        outtextxy(100,200,"YOU LOST");
        updateBoard(2,1);
    }
    if(ans==2){
        settextstyle(6,0,10);
        setbkcolor(RED);
        setcolor(LIGHTGREEN);
        outtextxy(100,200,"YOU WIN");
        updateBoard(1,1);
    }
    if(ans==3){
        settextstyle(6,0,10);
        setbkcolor(RED);
        setcolor(LIGHTGREEN);
        outtextxy(100,200,"DRAW");
    }

}

void Reset(int);

void twoPlayer(){
//    loadBoard();
    time_t zaman2,zaman1=time(0);
    loadBoard2();
    int turn=1;
    while(!gameEnded()){
        getMohre2(turn);
        turn++;
        turn%=2;
        if(turn==0){
            turn=2;
        }
    }
    int ans=gameEnded();
    if(ans==1){
        settextstyle(6,0,5);
        setbkcolor(RED);
        setcolor(LIGHTGREEN);
        outtextxy(100,200,"PLAYER 2 WIN");
        updateBoard2(2,1);
    }
    if(ans==2){
        settextstyle(6,0,5);
        setbkcolor(RED);
        setcolor(LIGHTGREEN);
        outtextxy(100,200,"PLAYER 1 WIN");
        updateBoard2(1,1);
    }
    if(ans==3){
        settextstyle(6,0,10);
        setbkcolor(RED);
        setcolor(LIGHTGREEN);
        outtextxy(100,200,"DRAW");
    }
    if(gameEnded()==1){
        cout<<endl<<"player2 wins";
    }
    if(gameEnded()==2){
        cout<<endl<<"player1 wins";
    }
    zaman2=time(0);
    int tim=zaman2-zaman1;
    char tym[40];
    sprintf(tym,"%d",tim);

    settextstyle(10,0,2);
    setcolor(BLACK);
    setbkcolor(WHITE);
    outtextxy(800,650,"FINAL TIME : ");
    outtextxy(980,650,tym);
    outtextxy(1030,650,"SECONDS");
}


void bazikon(){
    twoPlayer();
    while(1){
        char c=getch();
        if(c=='r'){
            for(int i=0;i<NumberOfColumns;i++){
                board[i].clear();
            }
            closegraph();
            twoPlayer();
            break;
        }
        if(c==27){
            closegraph();
            break;
        }
    }
}



void onePlayer(){
    initwindow(1200,800);
    background(RED);
    settextstyle(6,0,4);
    setbkcolor(RED);
    setcolor(7);
    outtextxy(220,70, "Choose your color (BLUE will start!!!)");
    setfillstyle(1,LIGHTGRAY);
    bar(345,345,855,455);
    redCircle(400,400,40);
    //circle(400,400,40);
    blueCircle(800,400,40);
    //circle(800,400,40);
    bool tmp=0;
    while(!kbhit()){
            //cout<<"DFSDF";
        if(ismouseclick(WM_LBUTTONDOWN)){
            int x=mousex();
            int y=mousey();
            int disr;
            disr=(x-400)*(x-400)+(y-400)*(y-400);
            int disb;
            disb=(x-800)*(x-800)+(y-400)*(y-400);
            if(disr<1600){
                ComputerTurn=1;
                ComputerColor=1;
                PlayerColor=2;
                ///1=red
                tmp=1;
            }
            if(disb<1600){
                ComputerColor=2;
                PlayerColor=1;
                tmp=1;
            }
            clearmouseclick(WM_LBUTTONDOWN);
            if(tmp){
                closegraph();
                break;
            }
        }
    }
    getLevelOfAI();
    stack <char> CheatK;
    stack <char> CheatZ;
    for(int i=CheatCodeKam.size()-1;i>=0;i--){
        CheatK.push(CheatCodeKam[i]);
        CheatZ.push(CheatCodeZiad[i]);
    }
    while(1){
        char c=getch();
        if(c==CheatK.top()){
            CheatK.pop();
        }
        else{
            while(!CheatK.empty()){
                CheatK.pop();
            }
            for(int i=CheatCodeKam.size()-1;i>=0;i--){
                CheatK.push(CheatCodeKam[i]);
            }
        }
        if(c==CheatZ.top()){
            CheatZ.pop();
        }
        else{
            while(!CheatZ.empty()){
                CheatZ.pop();
            }
            for(int i=CheatCodeKam.size()-1;i>=0;i--){
                CheatZ.push(CheatCodeZiad[i]);
            }
        }
        if(CheatK.size()==0){
            updateBoard(2,-1);
             for(int i=CheatCodeKam.size()-1;i>=0;i--){
                CheatK.push(CheatCodeKam[i]);
            }
        }
       // cout<<"DGFAG "<<CheatZ.top()<<endl;
        if(CheatZ.size()==0){
            updateBoard(1,1);
            for(int i=CheatCodeKam.size()-1;i>=0;i--){
                CheatZ.push(CheatCodeZiad[i]);
            }
            cout<<endl<<"FAGBYYHERYHYREHhBQRSD";
        }

        if(c=='r'){
            closegraph();
            Reset(1);

        }
        if(c==27){
            closegraph();
            break;
        }
    }

   // printf("sfsafsf%d",ans);

    //getch();
   // closegraph();
}




void getNumberofplayers(){
    //background();
    setfillstyle(1,4);
    bar(300,350,500,450);
    bar(700,350,900,450);
    settextstyle(6,0,7);
    setbkcolor(BLACK);
    setcolor(CYAN);
    outtextxy(400,50, "Connect  4");
    settextstyle(8,0,4);
    setbkcolor(BLACK);
    setcolor(9);
    outtextxy(285,180, "select number of players, BI ZAHMET");
    settextstyle(8,0,4);
    setbkcolor(RED);
    setcolor(YELLOW);
    outtextxy(323, 385, "1 player");
    outtextxy(723,385, "2 player");
    setbkcolor(BLACK);
    settextstyle(8,0,1);
    setcolor(GREEN);
    outtextxy(500,730, "An NNTEHRANI production");
    int tmp=0;
    while(!kbhit()){
        if(ismouseclick(WM_LBUTTONDOWN)){
            int x=mousex();
            int y=mousey();
            if(x<500 && x>300 && y>350 && y<450){
                cout<<"chap";
                tmp=1;
            }
            if(x<900 && x>700 && y>350 && y<450){
                cout<<"rast";
                tmp=2;
            }
            clearmouseclick(WM_LBUTTONDOWN);
            if(tmp){
                closegraph();
                break;
            }
        }
    }
    if(tmp==1)
        onePlayer();
    else
        bazikon();
}






int main(){
    NumberOfColumns=7;
    NumberOfRows=6;
    initwindow(1200,800);
    //background(0);
    settextstyle(10,0,6);
    int tmp=0;
    srand(time(0));
    while(tmp<10){
      //  int ran=rand();
        settextstyle(10,0,6);
        setcolor(15);
        outtextxy(300,300,"IN THE NAME OF GOD");        delay(500);
        tmp++;
        settextstyle(6,0,6);
        setcolor(14);
        if(2<tmp){
            outtextxy(330,500,"4");
        }
        if(4<tmp){
            outtextxy(400,500,"IN");
        }
        if(5<tmp){
            outtextxy(530,500,"A");
        }
        if(6<tmp){
            outtextxy(610,500,"ROW");
        }
        cout<<tmp<<endl;
    }
    //cleardevice();
    delay(1000);
    cout<<endl<<"KK";
    //outtextxy(300,500,"N");
    //getch();
    closegraph();
    initwindow(1200,800);
    background(0);
    setcolor(WHITE);
    rectangle(300,300,500,420);
    rectangle(700,300,900,420);
    settextstyle(10,0,4);
    outtextxy(360,340,"MOUSE");
    outtextxy(730,340,"KEYBOARD");
    while(!kbhit()){
        if(ismouseclick(WM_LBUTTONDOWN)){
            int x=mousex();
            int y=mousey();
            if(y>=300 && y<=420){
                if(x<=500 && x>=300){
                    mouse=1;
                    break;
                }
                if(x<=900 && x>=700){
                    mouse=0;
                    break;
                }
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);
    }
    closegraph();
    initwindow(1200,800);
    getNumberofplayers();
    getch();
    closegraph();
/*    getSizeOfBoard();
    if(NumberOfPlayers==1){
        getLevel();
        selectWichTurn();
        getColorOfplayers1p();
        if(level==3){
            playWithLevelHard();
        }
    }
	getch();
*/
/*
	///alaki baraye test
	NumberOfColumns=7;
	NumberOfRows=6;
	ComputerTurn=1;
	playWithLevelHard();
*/




    }





void Reset(int level){
    for(int i=0;i<NumberOfColumns;i++){
        board[i].clear();
    }
   /* if(level==0){
        twoPlayer();
    }*/
    if(level==1){
        getLevelOfAI();
    }

}
