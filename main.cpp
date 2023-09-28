#include <iostream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<SDL2/SDL_mixer.h>

using namespace std;
struct B{
int x;
int y;
int strength;




};
bool access=true;
double speed2=4;
int color[3]={0,0,0};
int score=0;
int level=1;
int lives=3;
B br[60];
double d,l;
string Name;
SDL_Rect img_rect2;
SDL_Rect img_rect;
SDL_Rect img_rect3;
SDL_Rect collisionrect;
SDL_Rect bombrect;
SDL_Texture*bricks;
SDL_Texture*bricks4;
SDL_Texture*bricks2;
SDL_Texture*bricks3;
SDL_Texture* m_img2;
SDL_Texture*collision1;
SDL_Texture*collision2;
SDL_Texture*collision3;
SDL_Texture*bomb;
Mix_Chunk *m_chunk1;
Mix_Chunk *m_chunk2;
Mix_Chunk *m_chunk3;
int menu(SDL_Renderer *m_renderer,SDL_Texture* m_img );
string name(SDL_Renderer *m_renderer);
void searchname(string name,SDL_Renderer*m_renderer);
int platemotion(SDL_Renderer *m_renderer,SDL_Texture* m_img);
int changeballcolor(SDL_Renderer *m_renderer);
int ballmotion_1(SDL_Renderer *m_renderer,int x,SDL_Texture*m_img);
int ballmotin_2(SDL_Renderer*m_renderer,int x,SDL_Texture*m_img);
void sr(SDL_Renderer*m_renderer,double l,double d);
void print_one_digit(int X,int Y,int R,SDL_Renderer *renderer);
void savestruct();
void structshift();
void saveresults();
int main( int argc, char * argv[] )
{






   // string name;
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_BORDERLESS ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    //Texture for loading image

    int img_w, img_h;

    SDL_Init( SDL_flags | SDL_INIT_AUDIO );




    SDL_CreateWindowAndRenderer( 1200, 800, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 81,81,81, 255 );
    SDL_RenderClear( m_renderer );
/////////////////////////////////////////////////////////////////////
    //initialize audio
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);

    Mix_Music*m_music;
//    if( m_music == NULL )
//    {
//        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
//        return 0;
//    }

    //


     //Mix_chunk *m_chunk2;
m_chunk1=Mix_LoadWAV("c:\\PROGRA~2\\CodeBlocks\\share\\CodeBlocks\\assets\\sound.wav");
m_chunk2=Mix_LoadWAV("c:\\PROGRA~2\\CodeBlocks\\share\\CodeBlocks\\assets\\sound2.wav");
m_chunk3=Mix_LoadWAV("c:\\PROGRA~2\\CodeBlocks\\share\\CodeBlocks\\assets\\sound3.wav");


      if( m_chunk3 == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        return 0;
    }


///////////////////////////////////////////////////////////////////////////////////////////

    // Show the window
    SDL_RenderPresent( m_renderer );
//Loading image
//IMG
SDL_Texture* m_img = NULL;
    m_img = IMG_LoadTexture(m_renderer, IMG_address_02);
    bricks2=IMG_LoadTexture(m_renderer, IMG_address_04);
    bricks3=IMG_LoadTexture(m_renderer, IMG_address_06);
    bricks4=IMG_LoadTexture(m_renderer, IMG_address_07);
    m_img2=IMG_LoadTexture(m_renderer, IMG_address_05);
    collision1=IMG_LoadTexture(m_renderer,IMG_address_50);
    collision2=IMG_LoadTexture(m_renderer,IMG_address_60);
    collision3=IMG_LoadTexture(m_renderer,IMG_address_70);
    bomb=IMG_LoadTexture(m_renderer,IMG_address_100);
      if( bomb == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        return 0;
    }




    //Get the width and height of the texture
    SDL_QueryTexture(m_img, NULL, NULL, &img_w, &img_h);
    img_rect.x = 0;
    img_rect.y = 0;
    img_rect.w = 1200;
    img_rect.h = 760;
    //////////////////////////////////////////////////////////////////////////////texture
    SDL_QueryTexture(m_img2, NULL, NULL, &img_w, &img_h);
    img_rect2.x = 0;
    img_rect2.y = 0;
    img_rect2.w = 200;
    img_rect2.h = 80;

/////////////////////////////////////////////////////////////////////
 SDL_QueryTexture(bricks4, NULL, NULL, &img_w, &img_h);
    img_rect3.x = 0;
    img_rect3.y = 0;
    img_rect3.w = 200;
    img_rect3.h = 80;
/////////////////////////////////////////////////////////////////////////////////coordinates
 SDL_QueryTexture(bricks2, NULL, NULL, &img_w, &img_h);
    img_rect2.x = 0;
    img_rect2.y = 0;
    img_rect2.w = 200;
    img_rect2.h = 80;
/////////////////////////////////////////////////////////////////////////////////////////
 SDL_QueryTexture(bricks3, NULL, NULL, &img_w, &img_h);
    img_rect2.x = 0;
    img_rect2.y = 0;
    img_rect2.w = 200;
    img_rect2.h = 80;
    //////////////////////////////////////////////////////
SDL_QueryTexture(bricks, NULL, NULL, &img_w, &img_h);
    img_rect.x = 0;
    img_rect.y = 0;
    img_rect.w = 1200;
    img_rect.h = 760;
////////////////////////////////////////////////////////
SDL_QueryTexture(collision1, NULL, NULL, &img_w, &img_h);
    collisionrect.x = 0;
    collisionrect.y = 0;
    collisionrect.w = 200;
    collisionrect.h = 80;

///////////////////////////////////////////////////////
SDL_QueryTexture(collision2, NULL, NULL, &img_w, &img_h);
    collisionrect.x = 0;
    collisionrect.y = 0;
    collisionrect.w = 200;
    collisionrect.h = 80;
///////////////////////////////////////////////////
SDL_QueryTexture(collision3, NULL, NULL, &img_w, &img_h);
    collisionrect.x = 0;
    collisionrect.y = 0;
    collisionrect.w = 200;
    collisionrect.h = 80;
//////////////////////////////////////////////////
SDL_QueryTexture(bomb, NULL, NULL, &img_w, &img_h);
    bombrect.x = 0;
    bombrect.y = 0;
    bombrect.w = 200;
    bombrect.h = 80;



    ////////////////////////////////////
int dis=6;
int width=80;
////////////////
br[0].x=0;
br[0].y=-7*width-dis;
br[1].x=200+dis;
br[1].y=-7*width-dis;
br[2].x=400+2*dis;
br[2].y=-7*width-dis;
br[3].x=600+3*dis;
br[3].y=-7*width-dis;
br[4].x=800+4*dis;
br[4].y=-7*width-dis;
br[5].x=1000+5*dis;
br[5].y=-7*width-dis;



///////////////
br[6].x=0;
br[6].y=-6*width-dis;
br[7].x=200+dis;
br[7].y=-6*width-dis;
br[8].x=400+2*dis;
br[8].y=-6*width-dis;
br[9].x=600+3*dis;
br[9].y=-6*width-dis;
br[10].x=800+4*dis;
br[10].y=-6*width-dis;
br[11].x=1000+5*dis;
br[11].y=-6*width-dis;



/////////////
br[12].x=0;
br[12].y=-5*width-dis;
br[13].x=200+dis;
br[13].y=-5*width-dis;
br[14].x=400+2*dis;
br[14].y=-5*width-dis;
br[15].x=600+3*dis;
br[15].y=-5*width-dis;
br[16].x=800+4*dis;
br[16].y=-5*width-dis;
br[17].x=1000+5*dis;
br[17].y=-5*width-dis;




////////
br[18].x=0;
br[18].y=-4*width-dis;
br[19].x=200+dis;
br[19].y=-4*width-dis;
br[20].x=400+2*dis;
br[20].y=-4*width-dis;
br[21].x=600+3*dis;
br[21].y=-4*width-dis;
br[22].x=800+4*dis;
br[22].y=-4*width-dis;
br[23].x=1000+5*dis;
br[23].y=-4*width-dis;


///////////
br[24].x=0;
br[24].y=-3*width-dis;
br[25].x=200+dis;
br[25].y=-3*width-dis;
br[26].x=400+2*dis;
br[26].y=-3*width-dis;
br[27].x=600+3*dis;
br[27].y=-3*width-dis;
br[28].x=800+4*dis;
br[28].y=-3*width-dis;
br[29].x=1000+5*dis;
br[29].y=-3*width-dis;

/////////
br[30].x=0;
br[30].y=-2*width-dis;
br[31].x=200+dis;
br[31].y=-2*width-dis;
br[32].x=400+2*dis;
br[32].y=-2*width-dis;
br[33].x=600+3*dis;
br[33].y=-2*width-dis;
br[34].x=800+4*dis;
br[34].y=-2*width-dis;
br[35].x=1000+5*dis;
br[35].y=-2*width-dis;

/////
br[36].x=0;
br[36].y=-1*width-dis;
br[37].x=200+dis;
br[37].y=-1*width-dis;
br[38].x=400+2*dis;
br[38].y=-1*width-dis;
br[39].x=600+3*dis;
br[39].y=-1*width-dis;
br[40].x=800+4*dis;
br[40].y=-1*width-dis;
br[41].x=1000+5*dis;
br[41].y=-1*width-dis;
/////////
br[42].x=0;
br[42].y=0;
br[43].x=200+dis;
br[43].y=0;
br[44].x=400+2*dis;
br[44].y=0;
br[45].x=600+3*dis;
br[45].y=0;
br[46].x=800+4*dis;
br[46].y=0;
br[47].x=1000+5*dis;
br[47].y=0;
//////////////////
br[48].x=0;
br[48].y=width+dis;
br[49].x=200+dis;
br[49].y=width+dis;
br[50].x=400+2*dis;
br[50].y=width+dis;
br[51].x=600+3*dis;
br[51].y=width+dis;
br[52].x=800+4*dis;
br[52].y=width+dis;
br[53].x=1000+5*dis;
br[53].y=width+dis;
//////////////
br[54].x=0;
br[54].y=2*width+dis;
br[55].x=200+dis;
br[55].y=2*width+dis;
br[56].x=400+2*dis;
br[56].y=2*width+dis;
br[57].x=600+3*dis;
br[57].y=2*width+dis;
br[58].x=800+4*dis;
br[58].y=2*width+dis;
br[59].x=1000+5*dis;
br[59].y=2*width+dis;
////////////////////
srand(time(0));

for(int i=42;i<=59;i++)
      br[i].strength=1;
for(int i=36;i<=41;i++)
      br[i].strength=abs(rand()%3);
for(int i=30;i<=35;i++)
      br[i].strength=abs(rand()%4);
 srand(8);
for(int i=24;i<=29;i++)
       br[i].strength=abs(rand()%5);
for(int i=18;i<=23;i++)
       br[i].strength=abs(rand()%6);
for(int i=12;i<=17;i++)
       br[i].strength=abs(rand()%7);
for(int i=6;i<=11;i++)
       br[i].strength=abs(rand()%8);
for(int i=0;i<=5;i++)
       br[i].strength=abs(rand()%9);

//////////////////////////////////////////////////////////////////////////
for(int i=1;i<=4;i++)
    br[rand()%59].strength=-40;



/////////////////////////////////////////////////////////////////////////

    // copy the texture to the rendering context
     SDL_RenderCopy(m_renderer, m_img, NULL, &img_rect);

    SDL_RenderPresent( m_renderer );

//////////////////////
const char * text ="WELCOME TO THE PROJECT  ";

// 1 for lazy.ttf , 2 for arial.ttf , 3 for B Roya.ttf
int font =2;
int x_position=175;
int y_position=50;
SDL_Color text_color = { 46,193,2};
     textColor(m_renderer,x_position,y_position,text,font ,60,text_color);

SDL_RenderCopy(m_renderer, m_img, NULL,NULL);
SDL_Delay(2500);
////////////////////////////////////////////////////////////////////////////menu
SDL_RenderClear(m_renderer);
SDL_RenderCopy(m_renderer, m_img, NULL,NULL);
textRGBA(m_renderer,100,50,"choose your background music",2,30,0,255,0,255);
SDL_RenderPresent(m_renderer);
textRGBA(m_renderer,50,150,"1_ crab rave",2,30,0,255,0,255);
textRGBA(m_renderer,50,200,"2_bad style time back",2,30,0,255,0,255);
textRGBA(m_renderer,50,250,"3_piercing light",2,30,0,255,0,255);
textRGBA(m_renderer,50,300,"4_no background music",2,30,0,255,0,255);
SDL_Delay(2000);
 SDL_Event *e=new SDL_Event();
 e->type=0;
 while(e->type!=SDL_KEYDOWN){
    SDL_PollEvent(e);
 }

 switch(e->key.keysym.sym){

 case SDLK_1:

     m_music=Mix_LoadMUS(MP3_1);
     Mix_PlayMusic(m_music,-1);
     e->type=0;
     break;

case SDLK_2:

     m_music=Mix_LoadMUS(MP3_2);
     Mix_PlayMusic(m_music,-1);
     e->type=0;
     break;
case SDLK_3:

     m_music=Mix_LoadMUS(MP3_3);
     Mix_PlayMusic(m_music,-1);
     e->type=0;
     break;

case SDLK_4:
     e->type=0;
     break;




 }













//////////////////////////////////////////////////////////////////
int flag;

flag=menu(m_renderer,m_img);
if(flag==3){
SDL_SetRenderDrawColor(m_renderer,255,255,255,255);
SDL_RenderClear(m_renderer);
SDL_RenderPresent(m_renderer);
textRGBA(m_renderer,50,50,"Hi",1,60,255,0,0,255);
textRGBA(m_renderer,50,150,"Press       Left      on Keyboard for plate to go left",2,26,255,0,0,255);
textRGBA(m_renderer,50,250,"Press       Right     on Keyboard for plate to go right",2,26,255,0,0,255);
textRGBA(m_renderer,50,350,"Press         P       to pause game",2,26,255,0,0,255);
textRGBA(m_renderer,50,450,"Press any key to continue paused game",2,26,255,0,0,255);
textRGBA(m_renderer,50,550,"   enjoy playig !!!!!........         ",1,80,0,255,0,255);
SDL_RenderPresent(m_renderer);
    SDL_Delay(5000);
   flag=menu(m_renderer,m_img);




}
SDL_RenderCopy(m_renderer, m_img, NULL,NULL);
textRGBA(m_renderer,20,650,"Please Enter Your Name ",2,39,255,255,255,255);
SDL_RenderPresent(m_renderer);
SDL_Delay(2000);
SDL_RenderCopy(m_renderer, m_img, NULL,NULL);
SDL_RenderPresent(m_renderer);
SDL_Delay(2000);
/////////////////////////////////////////////////////////////////////////////////////////name
SDL_SetRenderDrawColor(m_renderer,81,81,81,255);
Name=name(m_renderer);
SDL_Delay(1000);




int difficulty=0;

if(flag==1){
ofstream out;
out.open("archive",ios::app);
out<<Name<<"\n";
searchname(Name,m_renderer);
SDL_RenderPresent(m_renderer);

SDL_Delay(4000);
SDL_RenderClear(m_renderer);
SDL_RenderPresent(m_renderer);
textRGBA(m_renderer,170,70,"Select difficulty of the game",2,32,255,255,255,255);
int x_,y_;
bool f_=false;
SDL_Event *e=new SDL_Event();
while(!f_){
  textRGBA(m_renderer,190,200,"easy",2,36,255,255,255,255);
  textRGBA(m_renderer,190,250,"hard",2,36,255,255,255,255);

SDL_RenderPresent(m_renderer);
e->type=0;
SDL_PollEvent(e);
if(e->type==SDL_MOUSEMOTION){
    x_=e->motion.x;
    y_=e->motion.y;

   if((x_>=180)&&(x_<=240)&&(y_>=190)&&(y_<=210)){
        textRGBA(m_renderer,190,200,"easy",2,36,255,0,0,255);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(500);
        e->type=0;
        for(int i=0;i<=300;i++){
        SDL_PollEvent(e);
    if(e->type==SDL_MOUSEBUTTONDOWN)
        {difficulty=1;
        f_=true;}}

   }

    if((x_>=180)&&(x_<=240)&&(y_>=240)&&(y_<=260)){
        textRGBA(m_renderer,190,250,"hard",2,36,255,0,0,255);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(500);
        e->type=0;
        for(int i=0;i<=300;i++){
        SDL_PollEvent(e);

        if(e->type==SDL_MOUSEBUTTONDOWN)
        {difficulty=2;
        f_=true;}}

    }
}
}
}

if(difficulty==1){
srand(time(0));
for(int i=1;i<=10;i++)
     br[rand()%59].strength=0;



}







else if(flag==2){
ifstream in;
string q=Name,N=Name;
ofstream out;
out.open("archive",ios::app);
out<<Name<<"\n";
searchname(Name,m_renderer);
SDL_RenderPresent(m_renderer);

SDL_Delay(4000);
q+=".txt";


int temp;
in.open(q);
if(in.good()){

 while(!in.eof()){

    in>>N;
    if(N==Name){
            in>>lives;

            in>>score;
            in>>level;
            temp=level;
            while(temp>=2){
                structshift();
                temp--;

            }
        for(int i=0;i<=59;i++)
            in>>br[i].strength;

           break;

        }





    }


 }








}
SDL_RenderClear(m_renderer);
SDL_RenderPresent(m_renderer);
SDL_Delay(1000);



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////motion
m_img=NULL;
m_img=IMG_LoadTexture(m_renderer, IMG_address_03);
SDL_QueryTexture(m_img, NULL, NULL, &img_w, &img_h);
    img_rect.x =500;
    img_rect.y =640;
    img_rect.w =200;
    img_rect.h =70;

   SDL_RenderCopy(m_renderer, m_img, NULL,&img_rect);
filledEllipseRGBA(m_renderer,600,620,25,25,255,0,0,255);
filledEllipseRGBA(m_renderer,600,620,15,15,0,0,255,255);
filledEllipseRGBA(m_renderer,600,620,9,9,0,255,0,255);

SDL_RenderPresent(m_renderer);

int f=changeballcolor(m_renderer);
if(f==1)
    color[0]=255;
else if(f==2)
     color[2]=240;

else if(f==3)
      color[1]=255;

      SDL_Delay(200);

while(access)
{
flag=platemotion(m_renderer,m_img);
flag=ballmotion_1(m_renderer,flag,m_img);
ballmotin_2(m_renderer,flag,m_img);
}
saveresults();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



e->type=0;
    //Wait for a key to be pressed
    while(e->type != SDL_KEYDOWN)
        SDL_PollEvent(e);

    //Finalize and free resources
    Mix_FreeMusic(m_music);
    Mix_FreeChunk(m_chunk1);
    Mix_FreeChunk(m_chunk2);
    Mix_FreeChunk(m_chunk3);
    SDL_DestroyTexture(bomb);
    SDL_DestroyTexture(m_img);
    SDL_DestroyTexture(m_img2);
    SDL_DestroyTexture(bricks);
    SDL_DestroyTexture(bricks2);
    SDL_DestroyTexture(bricks3);
    SDL_DestroyTexture(bricks4);
    SDL_DestroyTexture(collision1);
    SDL_DestroyTexture(collision2);
    SDL_DestroyTexture(collision3);
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	SDL_Quit();
    return 0;

}
int menu(SDL_Renderer *m_renderer,SDL_Texture* m_img ){

    SDL_RenderCopy(m_renderer, m_img, NULL, &img_rect);
    bool f=false;
const char * text[3]={"instructions","Play a new game..","Continue previous game"};
textRGBA(m_renderer,20,600,text[0],2,26,255,255,255,255);
textRGBA(m_renderer,20,650,text[1],2,26,255,255,255,255);
textRGBA(m_renderer,20,700,text[2],2,26,255,255,255,255);
SDL_RenderPresent(m_renderer);
int x,y;
SDL_Event *e=new SDL_Event();
while(!f){
  textRGBA(m_renderer,20,600,text[0],2,26,255,255,255,255);
  textRGBA(m_renderer,20,650,text[1],2,26,255,255,255,255);
  textRGBA(m_renderer,20,700,text[2],2,26,255,255,255,255);
SDL_RenderPresent(m_renderer);
e->type=0;
SDL_PollEvent(e);
if(e->type==SDL_MOUSEMOTION){
    x=e->motion.x;
    y=e->motion.y;

   if((x>=20)&&(x<=190)&&(y>=590)&&(y<=610)){
        textRGBA(m_renderer,20,600,text[0],2,26,255,0,0,255);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(500);
        e->type=0;
        for(int i=0;i<=300;i++){
        SDL_PollEvent(e);
    if(e->type==SDL_MOUSEBUTTONDOWN)
        {return 3;
        f=true;}}

   }

    if((x>=20)&&(x<=190)&&(y>=640)&&(y<=660)){
        textRGBA(m_renderer,20,650,text[1],2,26,255,0,0,255);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(500);
        e->type=0;
        for(int i=0;i<=300;i++){
        SDL_PollEvent(e);

        if(e->type==SDL_MOUSEBUTTONDOWN)
        {return 1;
        f=true;}}

    }
    else if((x>=20)&&(x<=190)&&(y>695)&&(y<=705)){
       textRGBA(m_renderer,20,700,text[2],2,26,255,0,0,255);
    SDL_RenderPresent(m_renderer);
    SDL_Delay(500);
       e->type=0;
       for(int i=0;i<=300;i++){
        SDL_PollEvent(e);
        if(e->type==SDL_MOUSEBUTTONDOWN)
        {return 2;
        f=true;}}

    }

}


}}

string name(SDL_Renderer *m_renderer){
SDL_Event *e=new SDL_Event();
e->type=0;
string a="";
int ii=29;

int i=0;
while((i++)<=10){
while(e->type!=SDL_KEYDOWN)
SDL_PollEvent(e);
    switch(e->key.keysym.sym){

        case SDLK_a:
             textRGBA(m_renderer,20+ii,600,"a",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
             SDL_Delay(2000);
             e->type=0;
             ii+=19;
             a+="a";
            break;


        case SDLK_b:
             textRGBA(m_renderer,20+ii,600,"b",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
             e->type=0;
             ii+=19;
             a+="b";
            break;


        case SDLK_c:
             textRGBA(m_renderer,20+ii,600,"c",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
             e->type=0;
             ii+=19;
             a+="c";
            break;
        case SDLK_d:
             textRGBA(m_renderer,20+ii,600,"d",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="d";
            break;

        case SDLK_e:
             textRGBA(m_renderer,20+ii,600,"e",2,29,255,255,255,255);
            SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="e";
            break;
        case SDLK_f:
             textRGBA(m_renderer,20+ii,600,"f",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
             e->type=0;
             ii+=19;
             a+="f";
            break;

        case SDLK_g:
             textRGBA(m_renderer,20+ii,600,"g",2,29,255,255,255,255);
              e->type=0;
             ii+=19;
             a+="g";
            break;
        case SDLK_h:
             textRGBA(m_renderer,20+ii,600,"h",2,29,255,255,255,255);
            SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="h";
            break;
        case SDLK_i:
             textRGBA(m_renderer,20+ii,600,"i",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="i";
            break;
        case SDLK_j:
             textRGBA(m_renderer,20+ii,600,"j",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="j";
            break;
        case SDLK_k:
             textRGBA(m_renderer,20+ii,600,"k",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="k";
            break;
         case SDLK_l:
             textRGBA(m_renderer,20+ii,600,"l",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="l";
            break;
         case SDLK_m:
             textRGBA(m_renderer,20+ii,600,"m",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="m";
            break;
         case SDLK_n:
             textRGBA(m_renderer,20+ii,600,"n",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="n";
            break;

        case SDLK_o:
             textRGBA(m_renderer,20+ii,600,"o",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="o";
            break;
       case SDLK_p:
             textRGBA(m_renderer,20+ii,600,"p",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="p";
            break;
       case SDLK_q:
             textRGBA(m_renderer,20+ii,600,"q",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="q";
            break;
       case SDLK_r:
             textRGBA(m_renderer,20+ii,600,"r",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="r";
            break;
       case SDLK_s:
             textRGBA(m_renderer,20+ii,600,"s",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="s";
            break;
        case SDLK_t:
             textRGBA(m_renderer,20+ii,600,"t",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="t";
            break;
        case SDLK_u:
             textRGBA(m_renderer,20+ii,600,"u",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="u";
            break;
          case SDLK_v:
             textRGBA(m_renderer,20+ii,600,"v",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="v";
            break;
          case SDLK_w:
             textRGBA(m_renderer,20+ii,600,"w",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="w";
            break;

          case SDLK_x:
             textRGBA(m_renderer,20+ii,600,"x",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="x";
            break;
          case SDLK_y:
             textRGBA(m_renderer,20+ii,600,"y",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="y";
            break;
         case SDLK_z:
             textRGBA(m_renderer,20+ii,600,"z",2,29,255,255,255,255);
             SDL_RenderPresent(m_renderer);
              e->type=0;
             ii+=19;
             a+="z";
            break;


         case SDLK_KP_ENTER:
            return a;
    }
}



const char* name_=a.c_str();
textRGBA(m_renderer,50,50,name_,2,39,255,255,255,255);
SDL_RenderPresent(m_renderer);
SDL_Delay(1500);
}
void searchname(string name,SDL_Renderer*m_renderer){
 ifstream in;
string se;
string score_;
string level_;
int i=1;
//bool flag=false;
in.open("archive");
if(in.good()){

while(!in.eof()){

in>>se;
if(se==name){
  in>>score_;
if((isdigit(score_[0])&&(i<=5))){
  in>>level_;
        i++;
textRGBA(m_renderer,180,100,"score",2,38,255,0,0,255);
textRGBA(m_renderer,380,100,"level",2,38,255,0,0,255);

textRGBA(m_renderer,200,100+50*i,score_.c_str(),2,26,255,0,0,255);
textRGBA(m_renderer,400,100+50*i,level_.c_str(),2,26,255,0,0,255);

}

}

}
return;
}

in.close();
}
int changeballcolor(SDL_Renderer *m_renderer){

textRGBA(m_renderer,100,100,"What color would you like the ball to be :",2,40,255,255,255,255);
textRGBA(m_renderer,100,200,"Press R for Red",2,26,255,0,0,255);
textRGBA(m_renderer,100,300,"Press B for Blue",2,26,0,0,255,255);
textRGBA(m_renderer,100,400,"Press D for Default",2,26,0,255,0,255);

SDL_RenderPresent(m_renderer);
SDL_Delay(1500);
SDL_Event *e=new SDL_Event();
e->type=0;
while(e->type!=SDL_KEYDOWN)
    SDL_PollEvent(e);
SDL_SetRenderDrawColor( m_renderer,81,81,81, 255 );
switch(e->key.keysym.sym){
case SDLK_r:
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);
    return 1;
    break;
case SDLK_b:
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);
    return 2;
    break;
case SDLK_d:
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);
    return 3;
    break;


}


}

int platemotion(SDL_Renderer *m_renderer,SDL_Texture* m_img){

 SDL_Event *e=new SDL_Event();
 ////////////////////////////////////////////////////
string sc,le,li;

//////////////////////////////////////////////////////////
 int x=0;
   SDL_SetRenderTarget(m_renderer,bricks);
for(int i=59;i>=42-6*(level-1);i--){

  if((br[i].strength>=1)||(br[i].strength==-40)){

  img_rect2.x=br[i].x;
  img_rect2.y=br[i].y;
                if(br[i].strength==-40)
                          SDL_RenderCopy(m_renderer,bomb,NULL,&img_rect2);

                else if(br[i].strength<=2)
                        SDL_RenderCopy(m_renderer,m_img2,NULL,&img_rect2);

                else if((br[i].strength<=4)&&(br[i].strength>=3))
                        SDL_RenderCopy(m_renderer,bricks2,NULL,&img_rect2);
                else if ((br[i].strength<=6)&&(br[i].strength>=5))
                        SDL_RenderCopy(m_renderer,bricks3,NULL,&img_rect2);

                else if((br[i].strength<=8)&&(br[i].strength>=7))
                         SDL_RenderCopy(m_renderer,bricks4,NULL,&img_rect2);



  }

}SDL_RenderCopy(m_renderer,bricks,NULL,NULL);
SDL_SetRenderTarget(m_renderer,NULL);
            SDL_RenderCopy(m_renderer, m_img, NULL,&img_rect);
            filledEllipseRGBA(m_renderer,600+x,620,25,25,255,0,0,255);
            filledEllipseRGBA(m_renderer,600+x,620,15,15,0,0,255,255);
            filledEllipseRGBA(m_renderer,600+x,620,9,9,color[0],color[1],color[2],255);

sc=to_string(score);
le=to_string(level);
li=to_string(lives);
textRGBA(m_renderer,300,710,"Level :                       Score :                         lives :  ",2,20,255,255,255,240);
textRGBA(m_renderer,610,710,sc.c_str(),2,20,255,255,255,255);
textRGBA(m_renderer,360,710,le.c_str(),2,20,255,255,255,255);
textRGBA(m_renderer,780,710,li.c_str(),2,20,255,255,255,255);

       SDL_RenderPresent(m_renderer);




 bool flag=true;
 while(flag){
e->type=0;
SDL_SetRenderDrawColor( m_renderer,81,81,81, 255 );

while(e->type!=SDL_KEYDOWN)
    SDL_PollEvent(e);
switch(e->key.keysym.sym){
  case SDLK_SPACE:
       flag=false;
       return x;
       break;
   case SDLK_LEFT:
       x-=5;
       img_rect.x-=5;
       SDL_RenderClear(m_renderer);

    SDL_SetRenderTarget(m_renderer,bricks);
for(int i=59;i>=42-6*(level-1);i--){

  if(br[i].strength>=1||(br[i].strength==-40)){

  img_rect2.x=br[i].x;
  img_rect2.y=br[i].y;
                if(br[i].strength==-40)
                          SDL_RenderCopy(m_renderer,bomb,NULL,&img_rect2);
                else if(br[i].strength<=2)
                        SDL_RenderCopy(m_renderer,m_img2,NULL,&img_rect2);

                else if((br[i].strength<=4)&&(br[i].strength>=3))
                        SDL_RenderCopy(m_renderer,bricks2,NULL,&img_rect2);
                else if ((br[i].strength<=6)&&(br[i].strength>=5))
                        SDL_RenderCopy(m_renderer,bricks3,NULL,&img_rect2);

                else if((br[i].strength<=8)&&(br[i].strength>=7))
                         SDL_RenderCopy(m_renderer,bricks4,NULL,&img_rect2);



  }

}SDL_RenderCopy(m_renderer,bricks,NULL,NULL);
SDL_SetRenderTarget(m_renderer,NULL);



       SDL_RenderCopy(m_renderer, m_img, NULL,&img_rect);

            filledEllipseRGBA(m_renderer,600+x,620,25,25,255,0,0,255);
            filledEllipseRGBA(m_renderer,600+x,620,15,15,0,0,255,255);
            filledEllipseRGBA(m_renderer,600+x,620,9,9,color[0],color[1],color[2],255);


sc=to_string(score);
le=to_string(level);
li=to_string(lives);
textRGBA(m_renderer,300,710,"Level :                       Score :                         lives :  ",2,20,255,255,255,240);
textRGBA(m_renderer,610,710,sc.c_str(),2,20,255,255,255,255);
textRGBA(m_renderer,360,710,le.c_str(),2,20,255,255,255,255);
textRGBA(m_renderer,780,710,li.c_str(),2,20,255,255,255,255);






       SDL_RenderPresent(m_renderer);
       break;
   case SDLK_RIGHT:
       x+=5;
       img_rect.x+=5;
       SDL_RenderClear(m_renderer);
   SDL_SetRenderTarget(m_renderer,bricks);
for(int i=59;i>=42-6*(level-1);i--){

  if(br[i].strength>=1||(br[i].strength==-40)){

  img_rect2.x=br[i].x;
  img_rect2.y=br[i].y;
                if(br[i].strength==-40)
                          SDL_RenderCopy(m_renderer,bomb,NULL,&img_rect2);

                else if(br[i].strength<=2)
                        SDL_RenderCopy(m_renderer,m_img2,NULL,&img_rect2);

                else if((br[i].strength<=4)&&(br[i].strength>=3))
                        SDL_RenderCopy(m_renderer,bricks2,NULL,&img_rect2);
                else if ((br[i].strength<=6)&&(br[i].strength>=5))
                        SDL_RenderCopy(m_renderer,bricks3,NULL,&img_rect2);

                else if((br[i].strength<=8)&&(br[i].strength>=7))
                         SDL_RenderCopy(m_renderer,bricks4,NULL,&img_rect2);



  }

}SDL_RenderCopy(m_renderer,bricks,NULL,NULL);
SDL_SetRenderTarget(m_renderer,NULL);



       SDL_RenderCopy(m_renderer, m_img, NULL,&img_rect);
            filledEllipseRGBA(m_renderer,600+x,620,25,25,255,0,0,255);
            filledEllipseRGBA(m_renderer,600+x,620,15,15,0,0,255,255);
            filledEllipseRGBA(m_renderer,600+x,620,9,9,color[0],color[1],color[2],255);
sc=to_string(score);
le=to_string(level);
li=to_string(lives);
textRGBA(m_renderer,300,710,"Level :                       Score :                         lives :  ",2,20,255,255,255,240);
textRGBA(m_renderer,610,710,sc.c_str(),2,20,255,255,255,255);
textRGBA(m_renderer,360,710,le.c_str(),2,20,255,255,255,255);
textRGBA(m_renderer,780,710,li.c_str(),2,20,255,255,255,255);

       SDL_RenderPresent(m_renderer);
       break;
}
}
}
int ballmotion_1(SDL_Renderer *m_renderer,int x,SDL_Texture*m_img){

int speed=4;
 l=600+x;
 d=620;
img_rect.x=l-100;
bool flag=true;
while(flag)

   {






       d-=speed;
            SDL_SetRenderDrawColor( m_renderer,81,81,81, 255 );
            SDL_RenderClear(m_renderer);

for(int i=59;i>=42-6*(level-1);i--){

  if((br[i].strength>=1)||(br[i].strength==-40)){

        if((d<=br[i].y+80+30)&&(l>=br[i].x)&&(l<=br[i].x+200))
              {
                  br[i].strength-=1;





                  flag=false;
                  Mix_PlayChannel(-1,m_chunk1,0);
              }

if(br[i].strength>=1||(br[i].strength==-40)){
  img_rect2.x=br[i].x;
  img_rect2.y=br[i].y;

                if(br[i].strength==-40)
                          SDL_RenderCopy(m_renderer,bomb,NULL,&img_rect2);
                else if(br[i].strength<=2)
                        SDL_RenderCopy(m_renderer,m_img2,NULL,&img_rect2);

                else if((br[i].strength<=4)&&(br[i].strength>=3))
                        SDL_RenderCopy(m_renderer,bricks2,NULL,&img_rect2);
                else if ((br[i].strength<=6)&&(br[i].strength>=5))
                        SDL_RenderCopy(m_renderer,bricks3,NULL,&img_rect2);

                else if((br[i].strength<=8)&&(br[i].strength>=7))
                         SDL_RenderCopy(m_renderer,bricks4,NULL,&img_rect2);





  }
  }
}

SDL_RenderCopy(m_renderer, m_img, NULL,&img_rect);

            filledEllipseRGBA(m_renderer,l,d,25,25,255,0,0,255);
            filledEllipseRGBA(m_renderer,l,d,15,15,0,0,255,255);
            filledEllipseRGBA(m_renderer,l,d,9,9,color[0],color[1],color[2],255);





SDL_RenderPresent(m_renderer);
SDL_Delay(15);



}
score++;
return 600+x;

}
int ballmotin_2(SDL_Renderer*m_renderer,int x,SDL_Texture*m_img){

l=x;
int slope1[5]={2,3,4,5};
int slope2[5]={-2,-3,-4,-5};
int slope=1;
int y_intercept=d+10;
SDL_SetRenderDrawColor(m_renderer,81,81,81,255);
SDL_RenderClear(m_renderer);

int damage=level+1;
srand(time(0));
/////////////////////////////////////////////////////////////////////////////////








////////////////////////////////////////////////////////////////////////////////////////////
bool enter=true;

while(enter){




  SDL_Event *e=new SDL_Event();
  e->type=0;
  if(slope>0){
if(slope>=4)
l+=speed2/3;
else if(slope==3)
l+=speed2/2;
else
    l+=speed2;
}
else{
    if(slope<=-4)
        l+=speed2/3;
    else if(slope==-3)

        l+=speed2/2;

else
l+=speed2;



}


d=slope*(l-x)+y_intercept;

if(d<=230+(86)*(level-1)){
            for(int j=59;j>=42-6*(level-1);j--){


                    if(speed2>0){
                if((l>=br[j].x-30)&&(l<=br[j].x-10)&&(d>=br[j].y)&&(d<=br[j].y+80)&&(br[j].strength>=1))
                {


    l-=10;


      br[j].strength -=1;
      //////////////////////////////////////////////////
      if(br[j].strength==0){
         collisionrect.x=br[j].x;
         collisionrect.y=br[j].y;

        SDL_RenderCopy(m_renderer,collision1,NULL,&collisionrect);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(15);
        SDL_RenderCopy(m_renderer,collision2,NULL,&collisionrect);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(15);
        SDL_RenderCopy(m_renderer,collision3,NULL,&collisionrect);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(15);
        br[j].strength-=1;


       }
///////////////////////////////////////////////////////////////


      Mix_PlayChannel(-1,m_chunk1,0);
      score+=1*level;
    slope*=-1;
    x=l;
    y_intercept=d;
    speed2*=-1;
damage-=1;
 ////////////////////////////////
      if(damage==0){
        img_rect.x=500;
        level++;
        enter=false;
      structshift();
        return 0;



      }
/////////////////////////////////////////

                }
                    }
else{

   if((l>=br[j].x+200)&&(l<=br[j].x+230)&&(d>=br[j].y)&&(d<=br[j].y+80)&&((br[j].strength>=1)||(br[j].strength==-40)))
                {

    l+=10;


      br[j].strength -=1;
      //////////////////////////////////////////////////////////////////////

 if(br[j].strength==0){
         collisionrect.x=br[j].x;
         collisionrect.y=br[j].y;

        SDL_RenderCopy(m_renderer,collision1,NULL,&collisionrect);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(15);
        SDL_RenderCopy(m_renderer,collision2,NULL,&collisionrect);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(15);
        SDL_RenderCopy(m_renderer,collision3,NULL,&collisionrect);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(15);
        br[j].strength-=1;


       }

       //////////////////////////////////////////////////

       if(br[j].strength==-41)
       {
           br[j+1].strength=0;
           br[j+2].strength=0;
           br[j+3].strength=0;
           br[j].strength=-45;

       }





/////////////////////////////////////////////////////////////////

      Mix_PlayChannel(-1,m_chunk1,0);
      score+=1*level;

    slope*=-1;
    x=l;
    y_intercept=d;
    speed2*=-1;


                }

}








            }




        }





for(int i=59;i>=42-6*(level-1);i--){

if((br[i].y>=500)&&(br[i].strength>=1))
{

 SDL_RenderClear(m_renderer);
string sc,le,li;
sc=to_string(score);
le=to_string(level);
li=to_string(lives);
textRGBA(m_renderer,300,710,"Level :                       Score :                         lives :  ",2,20,255,255,255,240);
textRGBA(m_renderer,610,710,sc.c_str(),2,20,255,255,255,255);
textRGBA(m_renderer,360,710,le.c_str(),2,20,255,255,255,255);
textRGBA(m_renderer,780,710,li.c_str(),2,20,255,255,255,255);
textRGBA(m_renderer,410,500,"Game  Over",2,60,255,0,0,255);
Mix_PlayChannel(-1,m_chunk3,0);
access=false;
SDL_RenderPresent(m_renderer);
SDL_Delay(2000);
SDL_RenderClear(m_renderer);
return 0;






}




   if((l>=br[i].x+10)&&(l<=br[i].x+190)&&(d<=br[i].y+105)&&((br[i].strength>=1)||(br[i].strength==-40)))
   {

       br[i].strength-=1;
       ////////////////////////////////////////////////////
       if(br[i].strength==0){
         collisionrect.x=br[i].x;
         collisionrect.y=br[i].y;

        SDL_RenderCopy(m_renderer,collision1,NULL,&collisionrect);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(15);
        SDL_RenderCopy(m_renderer,collision2,NULL,&collisionrect);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(15);
        SDL_RenderCopy(m_renderer,collision3,NULL,&collisionrect);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(15);
        br[i].strength-=1;


       }

     /////////////////////////////////////////
 if(br[i].strength==-41)
       {
           br[i+1].strength=0;
           br[i+2].strength=0;
           br[i+3].strength=0;
           br[i].strength=-45;

       }
///////////////////////////////////////////////

       Mix_PlayChannel(-1,m_chunk1,0);
       score+=1*(level);
       damage-=1;
 ////////////////////////////////
      if(damage==0){
       img_rect.x=500;
     structshift();
        level++;
        enter=false;
return 0;



      }
/////////////////////////////////////////

    if(slope>0){

              l-=10;

    slope=slope2[rand()%4];
    x=l;
    y_intercept=d;}
    else
    {
        l+=3;
        slope=slope1[rand()%4];
        x=l;
        y_intercept=d;
    }




   }
   else{


  if((br[i].strength>=1)||(br[i].strength==-40)){

  img_rect2.x=br[i].x;
  img_rect2.y=br[i].y;
                 if(br[i].strength==-40)
                          SDL_RenderCopy(m_renderer,bomb,NULL,&img_rect2);
                else if(br[i].strength<=2)
                        SDL_RenderCopy(m_renderer,m_img2,NULL,&img_rect2);

                else if((br[i].strength<=4)&&(br[i].strength>=3))
                        SDL_RenderCopy(m_renderer,bricks2,NULL,&img_rect2);
                else if ((br[i].strength<=6)&&(br[i].strength>=5))
                        SDL_RenderCopy(m_renderer,bricks3,NULL,&img_rect2);

                else if((br[i].strength<=8)&&(br[i].strength>=7))
                         SDL_RenderCopy(m_renderer,bricks4,NULL,&img_rect2);








}

}
}
int temp;
textRGBA(m_renderer,300,720,"Level :                       Score :                         lives :  ",2,20,255,255,255,240);
sr(m_renderer,l,d);
if(score>=100){
temp=score;
print_one_digit(627,705,temp%10,m_renderer);
temp/=10;
print_one_digit(597,705,temp%10,m_renderer);
temp/=10;
print_one_digit(565,705,temp%10,m_renderer);
}
if(score>=10){

print_one_digit(597,705,score/10,m_renderer);
print_one_digit(627,705,score%10,m_renderer);
}
else
print_one_digit(627,705,score%10,m_renderer);


print_one_digit(360,710,level,m_renderer);

print_one_digit(780,710,lives,m_renderer);

SDL_RenderCopy(m_renderer, m_img, NULL,&img_rect);
SDL_RenderPresent(m_renderer);
SDL_Delay(45);
SDL_SetRenderDrawColor(m_renderer,81,81,81,255);



if(l<=26)
    {
    slope*=-1;
    l+=10;
    x=l;
    y_intercept=d;
    speed2*=-1;

    }

if(l>=1175)
    {
    slope*=-1;
     l-=10;
     x=l;
    y_intercept=d;
   speed2*=-1; }

if((l>=(img_rect.x+10))&&(l<=(img_rect.x+190)&&(d>=img_rect.y-30)))
{
  slope*=-1;
   x=l;
   y_intercept=d;
if(speed2<0)
     l-=10;

else
        l+=10;


}
if((d<=30)){
    d+=10;
    x=l;
    y_intercept=d;
    slope*=-1;

}
if(d>=660){
    lives-=1;
    Mix_PlayChannel(-1,m_chunk2,0);
    x=l;
    y_intercept=d;
    slope*=-1;




}






if(lives==0)
{
SDL_RenderClear(m_renderer);
string sc,le,li;
sc=to_string(score);
le=to_string(level);
li=to_string(lives);
textRGBA(m_renderer,300,710,"Level :                       Score :                         lives :  ",2,20,255,255,255,240);
textRGBA(m_renderer,610,710,sc.c_str(),2,20,255,255,255,255);
textRGBA(m_renderer,360,710,le.c_str(),2,20,255,255,255,255);
textRGBA(m_renderer,780,710,li.c_str(),2,20,255,255,255,255);
textRGBA(m_renderer,410,500,"Game  Over",2,60,255,0,0,255);
Mix_PlayChannel(-1,m_chunk3,0);
SDL_RenderPresent(m_renderer);
SDL_Delay(1000);
access=false;
SDL_RenderClear(m_renderer);
return 0;
}







   SDL_PollEvent(e);
   if(e->type=SDL_KEYDOWN){
switch(e->key.keysym.sym){
  case SDLK_RIGHT:
       img_rect.x+=7;

       break;
   case SDLK_LEFT:

       img_rect.x-=7;

        break;
   case SDLK_p:
       SDL_Event *ee=new SDL_Event();
       ee->type=0;
        filledEllipseRGBA(m_renderer,600,430,400,90,255,255,255,255);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(200);
        textRGBA(m_renderer,350,400,"Do you want to save this game ? ",2,26,255,0,0,255);
        textRGBA(m_renderer,350,450,"(press Y for yes)/(press N for No)",2 ,28,0,0,255,255);
        while(ee->type!=SDL_KEYDOWN){


            SDL_PollEvent(ee);}
                       switch(ee->key.keysym.sym){
                             case SDLK_y:
                                       savestruct();
                                       ee->type=0;
                                       SDL_RenderClear(m_renderer);
                                       filledEllipseRGBA(m_renderer,600,430,400,90,255,255,255,255);
                                        filledEllipseRGBA(m_renderer,600,430,400,90,255,255,255,255);
                                        SDL_RenderPresent(m_renderer);
                                        SDL_Delay(500);
                                        textRGBA(m_renderer,300,400,"Game Saved successfully!!!!! ",2,60,0,255,0,255);
                                        SDL_RenderPresent(m_renderer);
                                        SDL_Delay(1500);
                                       access=false;
                                       return 0;
                                       break;}







e->type=0;
    break;
}}

SDL_RenderClear(m_renderer);



}


}



void sr(SDL_Renderer*m_renderer,double l,double d){

        filledEllipseRGBA(m_renderer,l,d,25,25,255,0,0,255);
        filledEllipseRGBA(m_renderer,l,d,15,15,0,0,255,255);
        filledEllipseRGBA(m_renderer,l,d,9,9,color[0],color[1],color[2],255);
return;
}
void print_one_digit(int X,int Y,int R,SDL_Renderer *renderer){
    if (R==0) {
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
        SDL_RenderDrawLine(renderer, X+5, Y+40, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+5, Y+40);
        SDL_RenderDrawLine(renderer, X+30, Y+10, X+30, Y+40);
    }
    if (R==1) {
        SDL_RenderDrawLine(renderer, X+17, Y+40, X+17, Y+10);
    }
    if (R==2) {
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
        SDL_RenderDrawLine(renderer, X+5, Y+40, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+25, X+30, Y+25);
        SDL_RenderDrawLine(renderer, X+30, Y+10, X+30, Y+25);
        SDL_RenderDrawLine(renderer, X+5, Y+25, X+5, Y+40);
    }
    if (R==3) {
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
        SDL_RenderDrawLine(renderer, X+5, Y+40, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+25, X+30, Y+25);
        SDL_RenderDrawLine(renderer, X+30, Y+10, X+30, Y+40);
    }
    if (R==4) {
        SDL_RenderDrawLine(renderer, X+30, Y+10, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+5, Y+20);
        SDL_RenderDrawLine(renderer, X+5, Y+20, X+30, Y+20);
    }
    if (R==5) {
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
        SDL_RenderDrawLine(renderer, X+5, Y+25, X+30, Y+25);
        SDL_RenderDrawLine(renderer, X+5, Y+40, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+5, Y+25);
        SDL_RenderDrawLine(renderer, X+30, Y+25, X+30, Y+40);
    }
    if (R==6) {
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
        SDL_RenderDrawLine(renderer, X+5, Y+25, X+30, Y+25);
        SDL_RenderDrawLine(renderer, X+5, Y+40, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+30, Y+25, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+5, Y+40);
    }
    if (R==7) {
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
        SDL_RenderDrawLine(renderer, X+30, Y+10, X+5, Y+40);
    }
    if (R==8) {
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
        SDL_RenderDrawLine(renderer, X+5, Y+25, X+30, Y+25);
        SDL_RenderDrawLine(renderer, X+5, Y+40, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+30, Y+10, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+5, Y+40);
    }
    if (R==9) {
        SDL_RenderDrawLine(renderer, X+30, Y+10, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+5, Y+20);
        SDL_RenderDrawLine(renderer, X+5, Y+20, X+30, Y+20);
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
    }

}
void savestruct(){
ofstream out;
string N=Name;
N+=".txt";
out.open(N);
if(out.good()){
out<<Name;
out<<"\n";
out<<lives;
out<<"\n";
out<<score;
out<<"\n";
out<<level;
out<<"\n";
for(int i=0;i<=59;i++){
out<<br[i].strength;
out<<" ";}
out<<"\n";




}
out.close();

}

void structshift(){
for(int i=0;i<=59;i++)
     br[i].y+=86;

}
void saveresults(){
ofstream out;
out.open("archive",ios::app);
if(out.good()){
 out<<score;
 out<<"\n";
 out<<level;
out<<"\n";
    }


}
