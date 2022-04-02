#include <iostream>
#include <vector>
#include <windows.h>
#include <graphics.h>
#include <math.h>

using namespace std;

struct Node{
    string name;
    float x;
    float y;
};
struct Route{
    string name;
    struct route{
        string name;
        float distance;
    };
    struct route arrival[10000];
};
struct V{
    string current;
    float shortest;
    string previous;
    bool status;
    bool awal;
};

struct Node data[10000]; int m1=-1;
struct Route departure[1000]; int m2=-1,m3=-1;
struct V vertex[1000]; int m4=-1;

void append(string nama, float x, float y){
    m1+=1; m4+=1;
    data[m1].name = nama;
    data[m1].x = x;
    data[m1].y = y;
    vertex[m4].current = nama;
    vertex[m4].shortest = INT_MAX;
    vertex[m4].status = false;
    vertex[m4].awal = false;
}

void custom_append(){
    m1+=1; m4+=1;
    cout<<"Nama Kota: ";
    cin>>data[m1].name; //cin>>vertex[m4].current;
    cout<<"Koordinat x: ";
    cin>>data[m1].x;
    cout<<"Koordinat y: ";
    cin>>data[m1].y;
    //vertex[m4].shortest = INT_MAX;

}

void connect(string berangkat, string nyampe){
    float x1,y1,x2,y2,a,b; bool left, arrived;
    if(m2==-1||m2==0){m2+=1;}
    for(int i=0; i<=m1; i++){
        if(data[i].name == berangkat){
            left = true;
        }
        if(data[i].name == nyampe){
            arrived = true;
        }
    }
    if(left==true && arrived==true){
        for(int j=0; j<=m2; j++){
            if(departure[j].name != berangkat){ //kalo gak ada data
                if(m2>0){m2 +=1;} m3 +=1;
                departure[m2].name = berangkat;
                departure[m2].arrival[m3].name = nyampe;
                for(int k=0; k<=m1; k++){
                    if(data[k].name == berangkat){
                        x1 = data[k].x; y1 = data[k].y;

                    }
                    if(data[k].name == nyampe){
                        x2 = data[k].x; y2 = data[k].y;

                    }
                }
                a = x2-x1; b = y2-y1;

                departure[m2].arrival[m3].distance = sqrt(((a*a)+(b*b))); break;
            }
            else{ //kalo sama datanya
                m3 +=1;
                departure[j].arrival[m3].name = nyampe;
                for(int l=0; l<=m1; l++){
                    if(data[l].name == departure[j].name){
                        x1 = data[l].x; y1 = data[l].y;

                    }
                    if(data[l].name == nyampe){
                        x2 = data[l].x; y2 = data[l].y;

                    }
                }
                a = x2-x1; b = y2-y1;
                departure[j].arrival[m3].distance = sqrt((a*a)+(b*b)); break;
            }
        }
    }
    else{
        cout<<"Data not found!"<<endl;
    }

}


void connect_input(){
    string berangkat, nyampe;
    cout<<"NOTE: isi juga data kota Dari & Ke sebaliknya"<<endl;
    cout<<"Dari kota: ";cin>>berangkat;
    cout<<"Ke kota: ";cin>>nyampe;
    float x1,y1,x2,y2,a,b; bool left, arrived;
    if(m2==-1||m2==0){m2+=1;}
    for(int i=0; i<=m1; i++){
        if(data[i].name == berangkat){
            left = true;
        }
        if(data[i].name == nyampe){
            arrived = true;
        }
    }
    if(left==true && arrived==true){
        for(int j=0; j<=m2; j++){
            if(departure[j].name != berangkat){ //kalo gak ada
                if(m2<0){m2 +=1;} m3 +=1;
                departure[m2].name = berangkat;
                departure[m2].arrival[m3].name = nyampe;
                for(int k=0; k<=m1; k++){
                    if(data[k].name == berangkat){
                        x1 = data[k].x; y1 = data[k].y;

                    }
                    if(data[k].name == nyampe){
                        x2 = data[k].x; y2 = data[k].y;

                    }
                }
                a = x2-x1; b = y2-y1;

                departure[m2].arrival[m3].distance = sqrt(((a*a)+(b*b))); break;
            }
            else{ //kalo sama
                m3 +=1;
                departure[j].arrival[m3].name = nyampe;
                for(int l=0; l<=m1; l++){
                    if(data[l].name == departure[j].name){
                        x1 = data[l].x; y1 = data[l].y;

                    }
                    if(data[l].name == nyampe){
                        x2 = data[l].x; y2 = data[l].y;

                    }
                }
                a = x2-x1; b = y2-y1;
                departure[j].arrival[m3].distance = sqrt((a*a)+(b*b)); break;
        }
    }}
    else{
        cout<<"Data not found!"<<endl;
    }

}

void show(){
    float x1,y1,x2,y2;
    for(int i=0;i<=m1;i++){
        setcolor(WHITE); circle(data[i].x, data[i].y, 10);
    }
    for(int j=0; j<=m1; j++){
        for(int k=0; k<=m2; k++){
            if(data[j].name==departure[k].name){
                x1 = data[j].x; y1 = data[j].y;

                for(int l=0; l<=m1; l++){
                    for(int n=0; n<=m3; n++){
                        if(data[l].name == departure[k].arrival[n].name){
                            x2 = data[l].x; y2 = data[l].y;

                            setcolor(WHITE);line(x1,y1,x2,y2);
                        }
                    }
                }
            }
        }
    }

}

void dijkstra(string dari /*string ke*/){
    float a;
    for(int i=0; i<=m4;i++){
        if(dari == vertex[i].current&&vertex[i].awal == true){ //from
            vertex[i].shortest = 0;
            vertex[i].status = true;
            for(int j=0; j<=m2;j++){
                if(vertex[i].current == departure[j].name&&vertex[i].current==dari){
                    for(int k=0; k<=m3; k++){
                        a=vertex[i].shortest+departure[j].arrival[k].distance;
                        for(int l=0;l<=m4;l++){
                                if(vertex[l].current==departure[j].arrival[k].name){
                                if(vertex[l].shortest>a){
                                    vertex[l].shortest = a;
                                    vertex[l].previous = vertex[i].current;
                                    dijkstra(vertex[l].current);
                                }
                            }
                        }
                    }
                }
            }
        }
        if(dari == vertex[i].current&&vertex[i].awal==false){

            for(int j=0; j<=m2;j++){
                if(vertex[i].current == departure[j].name&&vertex[i].current==dari){
                    for(int k=0; k<=m3; k++){
                        a=vertex[i].shortest+departure[j].arrival[k].distance;
                        for(int l=0;l<=m4;l++){
                                if(vertex[l].current==departure[j].arrival[k].name){
                                if(vertex[l].shortest>a){
                                    vertex[l].shortest = a;
                                    vertex[l].previous = vertex[i].current;
                                    dijkstra(vertex[l].current);

                                }
                            }
                        }
                    }
                }
            }
            vertex[i].status = true;
        }

    }

}

void showtime(string akhir){
    float x1,y1,x2,y2,a,b;
    for(int i=0;i<=m4;i++){
        for(int j=0;j<=m1;j++){
            if(akhir==vertex[i].current&&vertex[i].current==data[j].name){
                x1=data[j].x; y1=data[j].y;
                setcolor(BLUE); setfillstyle(SOLID_FILL,LIGHTCYAN);circle(x1,y1,15); floodfill(x1,y1,BLUE);
                for(int k=0;k<=m1;k++){
                    if(vertex[i].previous==data[k].name){
                        x2=data[k].x; y2=data[k].y;
                        setcolor(LIGHTMAGENTA); setfillstyle(SOLID_FILL,LIGHTCYAN);circle(x2,y2,15); floodfill(x2,y2,LIGHTMAGENTA);
                        line(x1-2,y1-2,x2-2,y2-2); line(x1+2,y1+2,x2+2,y2+2);
                        for(int l=0;l<=m4;l++){
                            if(vertex[i].previous==vertex[l].current){
                                showtime(vertex[l].current);
                            }
                        }
                    }
                }
            }
        }

    }

}

void intro_dijkstra(string awal,string akhir){
    for(int i=0;i<=m4;i++){
        if(vertex[i].current == awal){
            vertex[i].awal = true;
        }
    }

    dijkstra(awal);
    showtime(akhir);
}


int main()
{

    append("A",100,100); append("B",400,100); append("C",700,250); append("D", 100,400); append("E", 400,400);
    connect("A","B"); connect("A","D"); connect("B","A"); connect("B","D"); connect("B","E"); connect("B","C"); connect("D","A"); connect("D","B"); connect("D","E"); connect("E","D"); connect("E","B"); connect("E","C");connect("C","B"); connect("C","E");

    initwindow(1000,800);
    while(!kbhit()){
        show();
        delay(10);
        intro_dijkstra("A","C");
    }
    return 0;
}
