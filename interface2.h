#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class Student{
    protected:
        string cls,div;
        string first_name,last_name;
    public:
        string full_name;        
        int roll_no;        
};

class Div_A:public Student{
    protected:
    int fds,cg,deld,dm,oop;
    public:
    float percentage;
    static int count_a;
    static int count_a_m,count_avg,count_poor,count_good,count_temp;
    Div_A(){
        count_a++;
        cls = "SE";
        div = "A";
        roll_no = count_a;
    }
    void set_data();
    void set_marks(Div_A* temp1);
    //void percentage();
    //void t_analysis();
}*A[100],*A_aggre[100],*A_fds[100],*A_cg[100],*A_deld[100],*A_dm[100],*A_oop[100],*A_temp[100];

int Div_A :: count_a;
int Div_A :: count_poor;
int Div_A :: count_avg;
int Div_A :: count_good;
int Div_A :: count_temp;




