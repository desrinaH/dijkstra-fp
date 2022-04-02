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
    struct route arrival[1000];
};
struct V{
    string current;
    float shortest;
    string previous;
    bool status;
    bool awal;
};
//vector< vector <float>> town;
struct Node data[10000]; int m1=-1;
struct Route departure[1000]; long int m2=-1,m3=-1;
struct V vertex[1000]; int m4=-1;

void append(string nama, float x, float y){
    m1+=1; m4+=1;
    data[m1].name = nama;
    data[m1].x = x+100;
    data[m1].y = y+100;
    vertex[m4].current = nama;
    vertex[m4].shortest = INT_MAX;
    vertex[m4].status = false;
    vertex[m4].awal = false;
    //cout<<"udah sampe sini append"<<endl;
    //town.push_back(data[m]);
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
    //town.push_back(data[m]);
}

void connect(string berangkat, string nyampe){
    //cout<<"nyampe connect1"<<endl;
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
                        //cout<< "x1="<<x1<<" y1="<<y1<<endl;
                    }
                    if(data[k].name == nyampe){
                        x2 = data[k].x; y2 = data[k].y;
                        //cout<< "x2="<<x2<<" y2="<<y2<<endl;
                    }
                }
                a = x2-x1; b = y2-y1;
                //cout<<a<<" "<<b<<endl;
                departure[m2].arrival[m3].distance = sqrt(((a*a)+(b*b))); //cout<<"Jarak "<<departure[m2].arrival[m3].distance<<endl;
                break;//cout<<"nyampe sini connect2"<<endl;
            }
            else{ //kalo sama datanya
                m3 +=1;
                departure[j].arrival[m3].name = nyampe;
                for(int l=0; l<=m1; l++){
                    if(data[l].name == departure[j].name){
                        x1 = data[l].x; y1 = data[l].y;
                        //cout<< "x1="<<x1<<" y1="<<y1<<endl;
                    }
                    if(data[l].name == nyampe){
                        x2 = data[l].x; y2 = data[l].y;
                        //cout<< "x2="<<x2<<" y2="<<y2<<endl;
                    }
                }
                a = x2-x1; b = y2-y1;
                departure[j].arrival[m3].distance = sqrt((a*a)+(b*b)); //cout<<"Jarak "<<departure[j].arrival[m3].distance<<endl;
                break;//cout<<"nyampe sini connect 3"<<endl;
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
                        //cout<< "x1="<<x1<<" y1="<<y1<<endl;
                    }
                    if(data[k].name == nyampe){
                        x2 = data[k].x; y2 = data[k].y;
                        //cout<< "x2="<<x2<<" y2="<<y2<<endl;
                    }
                }
                a = x2-x1; b = y2-y1;
                //cout<<a<<" "<<b<<endl;
                departure[m2].arrival[m3].distance = sqrt(((a*a)+(b*b))); //cout<<"Jarak "<<departure[m2].arrival[m3].distance<<endl;
                break;
            }
            else{ //kalo sama
                m3 +=1;
                departure[j].arrival[m3].name = nyampe;
                for(int l=0; l<=m1; l++){
                    if(data[l].name == departure[j].name){
                        x1 = data[l].x; y1 = data[l].y;
                        //cout<< "x1="<<x1<<" y1="<<y1<<endl;
                    }
                    if(data[l].name == nyampe){
                        x2 = data[l].x; y2 = data[l].y;
                        //cout<< "x2="<<x2<<" y2="<<y2<<endl;
                    }
                }
                a = x2-x1; b = y2-y1;
                departure[j].arrival[m3].distance = sqrt((a*a)+(b*b)); //cout<<"Jarak "<<departure[j].arrival[m3].distance<<endl;
                break;
            }
        }
    }
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
                //cout<<"x1= "<<x1<<"y1= "<<y1<<endl;
                //cout<<"departure[k].name = "<<departure[k].name<<endl;
                //cout<<"departure[1].name = "<<departure[1].name<<endl;
                //cout<<k<<endl;
                for(int l=0; l<=m1; l++){
                    for(int n=0; n<=m3; n++){
                        if(data[l].name == departure[k].arrival[n].name){
                            x2 = data[l].x; y2 = data[l].y;
                            //cout<<"x2= "<<x2<<"y2= "<<y2<<endl;
                            //cout<< "departure[k].arrival[n].name = "<< departure[k].arrival[n].name<<endl;
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
            vertex[i].status = true; //cout<<"sampe sini2 ";
            for(int j=0; j<=m2;j++){
                if(vertex[i].current == departure[j].name&&vertex[i].current==dari){
                    for(int k=0; k<=m3; k++){
                        a=vertex[i].shortest+departure[j].arrival[k].distance;
                        for(int l=0;l<=m4;l++){
                                if(vertex[l].current==departure[j].arrival[k].name){
                                if(vertex[l].shortest>a){
                                    vertex[l].shortest = a; //cout<<vertex[l].shortest;
                                    vertex[l].previous = vertex[i].current; //cout<<vertex[l].previous;//cout<<vertex[l].current<<" "; //cout<<vertex[l].previous;/cout<<vertex[i].current;
                                    dijkstra(vertex[l].current);
                                }
                            }
                        }
                    }
                }
            }
        }
        if(dari == vertex[i].current&&vertex[i].awal==false){
                //cout<<"sampe sini3 ";
            for(int j=0; j<=m2;j++){
                if(vertex[i].current == departure[j].name&&vertex[i].current==dari){
                    for(int k=0; k<=m3; k++){
                        a=vertex[i].shortest+departure[j].arrival[k].distance;
                        for(int l=0;l<=m4;l++){
                                if(vertex[l].current==departure[j].arrival[k].name){
                                if(vertex[l].shortest>a){
                                    vertex[l].shortest = a; //cout<<vertex[l].shortest;
                                    vertex[l].previous = vertex[i].current; //cout<<vertex[l].previous; //cout<<vertex[l].current<<" "; //cout<<vertex[l].previous;//cout<<vertex[i].current;
                                    dijkstra(vertex[l].current);
                                    //showtime(ke);
                                }
                            }
                        }
                    }
                }
            }
            vertex[i].status = true; //cout<<"sampe sini4 ";
        }
        //if(vertex[i].status==true){
         //   return;
        //}
    }

}

void showtime(string akhir){
    float x1,y1,x2,y2;
    cout<< akhir<<" ";
    for(int i=0;i<=m4;i++){
        for(int j=0;j<=m1;j++){
            if(akhir==vertex[i].current&&vertex[i].current==data[j].name){
                x1=data[j].x; y1=data[j].y;
                setcolor(BLUE); setfillstyle(SOLID_FILL,LIGHTCYAN);circle(x1,y1,15); floodfill(x1,y1,BLUE);  //cout<<"x1= "<<x1<<"y1= "<<y1<<endl;
                for(int k=0;k<=m1;k++){
                    if(vertex[i].previous==data[k].name){
                        x2=data[k].x; y2=data[k].y;
                        setcolor(LIGHTRED); setfillstyle(SOLID_FILL,LIGHTCYAN);circle(x2,y2,15); floodfill(x2,y2,LIGHTRED);//cout<<"x2= "<<x2<<"y2= "<<y2<<endl;
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
    //line(x1,y1,x2,y2);
}

void intro_dijkstra(string awal,string akhir){
    for(int i=0;i<=m4;i++){
        if(vertex[i].current == awal){
            vertex[i].awal = true;
        }
    }
    //cout<<"sampe sini1 ";
    dijkstra(awal);
    showtime(akhir);
}


int main()
{
    //append("A",100,100); append("B",400,100); append("C",700,250); append("D", 100,400); append("E", 400,400);
    //connect("A","B"); connect("A","D"); connect("B","A"); connect("B","D"); connect("B","E"); connect("B","C"); connect("D","A"); connect("D","B"); connect("D","E"); connect("E","D"); connect("E","B"); connect("E","C");connect("C","B"); connect("C","E");

    /*append("A",25,667); append("B",764,312); append("C",63,769);append("D", 707,613); append("E", 419,302); append("F",469,481); append("G",337,234); append("H",44,439); append("I", 538,519); append("J", 114,521);
    connect("H","J");
    connect("J","H");
    connect("G","F");
    connect("F","G");
    connect("J","E");
    connect("E","J");
    connect("I","G");
    connect("G","I");
    connect("I","D");
    connect("D","I");
    connect("D","J");
    connect("J","D");
    connect("J","G");
    connect("G","J");
    connect("C","B");
    connect("B","C");
    connect("H","B");
    connect("B","H");
    connect("I","A");
    connect("A","I");
    connect("C","E");
    connect("E","C");*/

    append("A",0,0);
    append("B",0,300);
    append("C",100,-100);
    append("D",300,0);
    append("E",100,200);
    append("F",300,400);
    append("G",400,100);
    append("H",500,0);
    append("I",400,100);
    append("J",600,0);
    append("L",200,400);
    append("K",500,400);
    connect("A","B");
    connect("B","A");
    connect("B","E");
    connect("C","A");
    connect("C","E");
    connect("C","D");
    connect("D","F");
    connect("E","C");
    connect("E","G");
    connect("E","F");
    connect("F","D");
    connect("F","E");
    connect("F","I");
    connect("G","D"); //mentok sini
    connect("G","H");
    connect("H","F");
    connect("H","J");
    connect("I","H");
    connect("J","H");
    connect("B","L");
    connect("L","B");
    connect("L","F");
    connect("F","K");
    connect("K","F");
    connect("K","J");
    connect("J","K");


    //connect_input();
    //connect_input();
    //intro_dijkstra("A","C");

    initwindow(1000,800);
    while(!kbhit()){
        show();
        delay(10);
        intro_dijkstra("J","L");
    }
    return 0;
}
