#include <cstdlib>
#include <iostream>
#include <fstream>
#include "lights.h"
#include <windows.h>

using namespace std;

void Output(Lights North, Lights South, Lights East, Lights West, Lights East2);
enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

int main(int argc, char** argv) {
    Lights North, South, East, West, East2;
    int i=0;
    /* Baca File */
        string dummy;
        int N,idx,val,Start;
        int* Interrupt;
        int acc;
        ifstream input;
        input.open("input.txt");
        if (input.is_open()) {
            getline(input, dummy, ']');
            input >> Start;
            getline(input, dummy, ']');
            input >> N;
            Interrupt = new int[N];
            for (int i = 0;i<N;i++) Interrupt[i] = 0;
            getline(input, dummy, ']');
            input >> acc;
            getline(input,dummy,']');
            while (!input.eof()) {
                input >> idx >> val;
                Interrupt[idx-1] = val;
                } 
        } else {
                cerr << "File gagal dibuka" << endl;
        }
        input.close();

    /*Deklarasi lainnya*/
    int timer = 0;
    int timercum = 0;
    int scale=950/acc;//950 = 1 detik, kalibrasi
    int stoptime = N; //stoptime dalam detik
    bool stop=false;
    bool start=false;
    while (!stop && timercum < stoptime) {
        if(Start == 1 || start==true) {
            start = true;
                North.SetOn("Green");
                South.SetOn("Green");
                East.SetOn("Red");
                East2.SetOn("Red");
                West.SetOn("Red");
                Output(North,South,East,West,East2);
        while(timer < 120 && timercum < stoptime && !stop) { //dalam detik
            if(Interrupt[timercum] != 0) {
                    timer = 0;
                    while(timer < 5 && timercum < stoptime && !stop) { //dalam detik
                    ++timer;
                    ++timercum;
                    Sleep(scale);
                    cout << string(20,'\b');
                    cout << "Time elapsed : " << timercum << "s.";
                    }
                    timer = 0;
                North.SetOn("Red");
                South.SetOn("Red");
                Output(North,South,East,West,East2);
                if(Interrupt[timercum] == 1) cout << "Ada penyebrang dari arah utara" <<endl << endl;
                else cout << "Ada penyebrang dari arah selatan" <<endl << endl;
                    timer = 0;
                    while(timer < 25 && timercum < stoptime && !stop) { // asumsi penyebrang diberi waktu 30 detik untuk menyebrang
                    ++timer;
                    ++timercum;
                    Sleep(scale);
                    cout << string(20,'\b');
                    cout << "Time elapsed : " << timercum << "s.";
                    }
                    timer = 0;
                North.SetOn("Yellow");
                South.SetOn("Yellow");
                Output(North,South,East,West,East2);
                if(Interrupt[timercum] == 1) cout  << "Ada penyebrang dari arah utara" << endl << endl;
                else cout << "Ada penyebrang dari arah selatan" << endl << endl;                
                    timer = 0;
                    while(timer < 5 && timercum < stoptime && !stop) { //dalam detik
                    ++timer;
                    ++timercum;
                    Sleep(scale);
                    cout << string(20,'\b');
                    cout << "Time elapsed : " << timercum << "s.";                   
                    }
                    timer = 0;
                North.SetOn("Green");
                South.SetOn("Green");
                Output(North,South,East,West,East2);                
            }
        ++timer;
        ++timercum;
        Sleep(scale);
        cout << string(20,'\b');
        cout << "Time elapsed : " << timercum << "s.";
        }   
        timer = 0; 
                East.SetOn("Yellow");
                Output(North,South,East,West,East2);
        while(timer < 5 && timercum < stoptime && !stop) { //dalam detik
        ++timer;
        ++timercum;
        Sleep(scale);
        cout << string(20,'\b');
        cout << "Time elapsed : " << timercum << "s.";
        }   
        timer = 0;             
                North.SetOn("Red");
                South.SetOn("Red");
                Output(North,South,East,West,East2);
        while(timer < 5 && timercum < stoptime && !stop) { //dalam detik
        ++timer;
        ++timercum;
        Sleep(scale);
        cout << string(20,'\b');
        cout << "Time elapsed : " << timercum << "s.";       
        }   
        timer = 0;
        } if (Start == 2 || start==true) {
            if(!start) West.SetOn("Red");
            start = true;
                North.SetOn("Red");
                South.SetOn("Red");
                East.SetOn("Green");
                East2.setRed(false);
                Output(North,South,East,West,East2);
        while(timer < 25 && timercum < stoptime && !stop) { //dalam detik
        ++timer;
        ++timercum;
        Sleep(scale); 
        cout << string(20,'\b');
        cout << "Time elapsed : " << timercum << "s.";     
        }   
        timer = 0; 
                West.SetOn("Yellow");
                Output(North,South,East,West,East2);            
        while(timer < 5 && timercum < stoptime && !stop) { //dalam detik
        ++timer;
        ++timercum;
        Sleep(scale);
        cout << string(20,'\b');
        cout << "Time elapsed : " << timercum << "s.";
        }   
        timer = 0; 
                East2.SetOn("Red");
                Output(North,South,East,West,East2);
        while(timer < 5 && timercum < stoptime && !stop) { //dalam detik
        ++timer;
        ++timercum;
        Sleep(scale); 
        cout << string(20,'\b');
        cout << "Time elapsed : " << timercum << "s.";       
        }   
        timer = 0;
                West.SetOn("Green");
                Output(North,South,East,West,East2);
        while(timer < 90 && timercum < stoptime && !stop) { //dalam detik
        ++timer;
        ++timercum;
        Sleep(scale); 
        cout << string(20,'\b');
        cout << "Time elapsed : " << timercum << "s.";    
        }   
        timer = 0;        
                North.SetOn("Yellow");
                South.SetOn("Yellow");
                Output(North,South,East,West,East2);
        while(timer < 5 && timercum < stoptime && !stop) { //dalam detik
        ++timer;
        ++timercum;
        Sleep(scale); 
        cout << string(20,'\b');
        cout << "Time elapsed : " << timercum << "s.";
        }   
        timer = 0; 
                East.SetOn("Red");
                East2.SetOn("Red");
                West.SetOn("Red");
                Output(North,South,East,West,East2);
        while(timer < 5 && timercum < stoptime && !stop) { //dalam detik
        ++timer;
        ++timercum;
        Sleep(scale); 
        cout << string(20,'\b');
        cout << "Time elapsed : " << timercum << "s.";     
        }   
        timer = 0;
        }
        if (timercum >= stoptime) stop = true; // kondisi apa yang mau supaya stop lagi
    }
    cout << endl << "Time elapsed : " << timercum << "s.";    
    cout << endl << "Press enter key to exit" << endl;
    getchar();
    delete [] Interrupt;
    return 0;
}

void Output(Lights North, Lights South, Lights East, Lights West, Lights East2) {
    string N,S,E,W,E2;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
    system("cls");
    SetConsoleTextAttribute(hConsole, WHITE);    
    cout << "\t\tNorth : " ;
    if (North.getGreen()) {
        N = "Hijau"; 
        SetConsoleTextAttribute(hConsole, GREEN);    
        cout << N;
    }
    else if (North.getRed()) {
        N = "Merah";
        SetConsoleTextAttribute(hConsole, RED);
        cout << N;
    }
    else if (North.getYellow()) {
        N = "Kuning";
        SetConsoleTextAttribute(hConsole, YELLOW);
        cout << N;
    }
    cout << endl;
    SetConsoleTextAttribute(hConsole, WHITE); 
    cout << "West : ";    
    if (West.getGreen()) {
        W = "Hijau";
        SetConsoleTextAttribute(hConsole, GREEN);
        cout << W;        
    }
    else if (West.getRed()) {
        W = "Merah";
        SetConsoleTextAttribute(hConsole, RED);
        cout << W;        
    }
    else if (West.getYellow()) {
        W = "Kuning";
        SetConsoleTextAttribute(hConsole, YELLOW);
        cout << W;
    }
    SetConsoleTextAttribute(hConsole, WHITE); 
    cout << "\t\t\tEast : ";    
    if (East.getGreen()) {
        E = "Hijau";
        SetConsoleTextAttribute(hConsole, GREEN);
        cout << E;
    }
    else if (East.getRed()) {
        E = "Merah";
        SetConsoleTextAttribute(hConsole, RED);
        cout << E;
    }
    else if (East.getYellow()) {
        E = "Kuning";
        SetConsoleTextAttribute(hConsole, YELLOW);
        cout << E;
    }    
    cout << endl;
    SetConsoleTextAttribute(hConsole, WHITE); 
    cout << "\t\t\t\tBelok Kanan : ";    
    if (East2.getGreen()) {
        E2 = "Hijau";
        SetConsoleTextAttribute(hConsole, GREEN);
        cout << E2;
    }
    else if (East2.getRed()) {
        E2 = "Merah";
        SetConsoleTextAttribute(hConsole, RED);
        cout << E2;
    }
    else if (East2.getYellow()) {
        E2 = "Kuning";
        SetConsoleTextAttribute(hConsole, YELLOW);
        cout << E2;
    }    
    cout << endl;    
    SetConsoleTextAttribute(hConsole, WHITE);     
    cout << "\t\tSouth : ";
    if (South.getGreen()){
        S = "Hijau";
        SetConsoleTextAttribute(hConsole, GREEN);
        cout << S;
    }
    else if (South.getRed()) {
        S = "Merah";
        SetConsoleTextAttribute(hConsole, RED);
        cout << S;        
    }
    else if (South.getYellow()) {
        S = "Kuning";
        SetConsoleTextAttribute(hConsole, YELLOW);
        cout << S;        
    }
    SetConsoleTextAttribute(hConsole, WHITE); 
    cout << endl << endl;

}

