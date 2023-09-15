//============================================================================
// Name        : Incubyte_chandrayan_3_TDD.cpp
// Author      : Jaydeep Datre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<bits/stdc++.h>
using namespace std;



//class representing chandrayaan3
class Chandrayaan_3{

    int x,y,z;
    char direction;

    public:
        Chandrayaan_3(){
            x=y=z=0;
            direction='O';
        }

        //paramaterised constructor to set the values of the instance of Chandrayaan_3 class
        Chandrayaan_3(int a,int b,int c,char d){
            x=a;
            y=b;
            z=c;
            direction=d;
        }


        //methods to get x,y,z coordinates of chandrayaan3
        int get_x(){
            return x;
        }


        int get_y(){
            return y;
        }

        int get_z(){
            return z;
        }


        //method to get direction of chandrayaan3
        char get_direction(){
            return direction;
        }


        //methods to add passed value to x,y,z coordinates
        void add_x(int x){
            this->x+=x;
        }


        void add_y(int y){
            this->y+=y;
        }


        void add_z(int z){
            this->z+=z;
        }


        //method to change the direction of chandrayaan3 based of the command received
        void set_direction(char d){
            direction=d;
        }

        //method to print configuration of chandrayaan3
        void print_position(){
            cout<<"Coordinates : "<<"("<<x<<","<<y<<","<<z<<")"<<endl;
            cout<<"Direction : "<<direction<<endl;
        }
};


int main(){

    //Taking initial input of the chandrayaan3
    cout<<"Enter initial coordinates(x,y,z)"<<endl;
    int a,b,c;
    cout<<"Enter x coordinate : ";
    cin>>a;
    cout<<"Enter y coordinate : ";
    cin>>b;
    cout<<"Enter z coordinate : ";
    cin>>c;

    //Taking initial direction
    char ch,curr_direction,prev_direction;
    cout<<"Enter initial direction (from N,S,E,W,U,D) in uppercase as a single character : ";
    cin>>ch;

    //Creating object of the custom datatype Chandrayaan_3
    Chandrayaan_3 obj(a,b,c,ch);


    //Taking the commands
    cout<<"Enter commands and 0 to end taking commands : "<<endl;

    vector<char> commands;

    while(1){
        cin>>ch;
        if(ch=='0'){
            break;
        }

        else if(ch=='f' || ch=='b' || ch=='u' || ch=='d'|| ch=='l' || ch=='r'){
            commands.push_back(ch);
        }
        else{
            cout<<"\nNot a valid command"<<endl;
        }
    }


    //Iterating over commands array to perform calculation and updating the configuration of the chandrayaan3
    for(char c: commands){

        switch (c)
        {
        case 'u':
            prev_direction=obj.get_direction();
            obj.set_direction('U');
            break;

        case 'd':
            prev_direction=obj.get_direction();
            obj.set_direction('D');
            break;

        case 'l':
            curr_direction=obj.get_direction();
            if(curr_direction=='N'){
                obj.set_direction('W');
            }
            else if(curr_direction=='E'){
                obj.set_direction('N');
            }
            else if(curr_direction=='S'){
                obj.set_direction('E');
            }
            else if(curr_direction=='W'){
                obj.set_direction('S');
            }
            else if(curr_direction=='U'){
                if(prev_direction=='E'){
                    obj.set_direction('N');
                }
                else if(prev_direction=='N'){
                    obj.set_direction('W');
                }
                else if(prev_direction=='W'){
                    obj.set_direction('S');
                }
                else if(prev_direction=='S'){
                    obj.set_direction('E');
                }
            }
            else if(curr_direction=='D'){
                if(prev_direction=='E'){
                    obj.set_direction('N');
                }
                else if(prev_direction=='N'){
                    obj.set_direction('W');
                }
                else if(prev_direction=='W'){
                    obj.set_direction('S');
                }
                else if(prev_direction=='S'){
                    obj.set_direction('E');
                }
            }
            break;

        case 'r':

            curr_direction=obj.get_direction();
            if(curr_direction=='N'){
                obj.set_direction('E');
            }
            else if(curr_direction=='E'){
                obj.set_direction('S');
            }
            else if(curr_direction=='S'){
                obj.set_direction('W');
            }
            else if(curr_direction=='W'){
                obj.set_direction('N');
            }
            else if(curr_direction=='U'){
                if(prev_direction=='E'){
                    obj.set_direction('S');
                }
                else if(prev_direction=='N'){
                    obj.set_direction('E');
                }
                else if(prev_direction=='W'){
                    obj.set_direction('N');
                }
                else if(prev_direction=='S'){
                    obj.set_direction('W');
                }
            }
            else if(curr_direction=='D'){

                if(prev_direction=='E'){
                    obj.set_direction('S');
                }
                else if(prev_direction=='N'){
                    obj.set_direction('E');
                }
                else if(prev_direction=='W'){
                    obj.set_direction('N');
                }
                else if(prev_direction=='S'){
                    obj.set_direction('W');
                }
            }
            break;

        case 'f':

            curr_direction=obj.get_direction();

            if(curr_direction=='N'){
                obj.add_y(1);
            }
            else if(curr_direction=='E'){
                obj.add_x(1);
            }
            else if(curr_direction=='S'){
                obj.add_y(-1);
            }
            else if(curr_direction=='W'){
                obj.add_x(-1);
            }
            else if(curr_direction=='U'){
                obj.add_z(1);
            }
            else if(curr_direction=='D'){
                obj.add_z(-1);
            }

            break;

        case 'b':
            curr_direction=obj.get_direction();

            if(curr_direction=='N'){
                obj.add_y(-1);
            }
            else if(curr_direction=='E'){
                obj.add_x(-1);
            }
            else if(curr_direction=='S'){
                obj.add_y(1);
            }
            else if(curr_direction=='W'){
                obj.add_x(1);
            }
            else if(curr_direction=='U'){
                obj.add_z(-1);
            }
            else if(curr_direction=='D'){
                obj.add_z(1);
            }


        default:
            break;
        }

        cout<<"\n\nAfter Command \""<<c<<"\" configuration is : "<<endl;
        obj.print_position();
        cout<<"\n\n";


    }

    cout<<"\nFinal Configuraton of Chandrayaan3\n"<<endl;

    obj.print_position();

    return 0;



}
