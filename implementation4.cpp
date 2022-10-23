#include"interface2.h"
#include<string>
void Div_A::set_data(){
        cout<<"Enter first name : ";
        cin>>first_name;
        cout<<"Enter last name : ";
        cin>>last_name;
        full_name = last_name + " " + first_name;
        /*ofstream MyWriteFile("filename.txt");
        MyWriteFile << full_name;
        system("cls");
        cout<<"Entry created Successfully!";*/
        ofstream file ("students.txt", ios::app);
        file <<roll_no << " " << full_name << endl;
        
}

int er_handler(int* marks){
    //int mark = marks;
    try{
        if(*marks<0 || *marks>100){
            throw *marks;
        }
    }
    catch(int temp){
        cout<<"Invalid input the marks should be greater than or equal to 0 and less than or equal to 100";
        cout<<"\nPlease enter valid marks :";
        cin>>*marks;
        er_handler(marks);
    }
    return *marks;
}

void sortA(){
    for(int i = 1;i<=Div_A::count_a;i++){
            Div_A *temp1,*temp2;
            cout<<A[Div_A::count_a]->full_name<<endl;
            if((A[Div_A::count_a]->full_name)<(A[i]->full_name)){
                //temp = A[i];
                temp1 = A[i];
                A[i] = A[Div_A::count_a];
                A[i]->roll_no = i;
                for(int j=i+1;j<Div_A::count_a;j++){
                    temp2 = A[j];
                    A[j] = temp1;
                    A[j]->roll_no = j;
                    temp1 = temp2;
                }
                A[Div_A::count_a] = temp1;
                A[Div_A::count_a]->roll_no = Div_A::count_a;
                break;    
            }
        }
}



void A_sortpercent(){
    for(int i =0 ;i<Div_A::count_temp;i++){
        Div_A *temp1,*temp2;
        temp1 = A_temp[i];
        for (int j = 0; j < Div_A::count_temp; j++){
            if(A_temp[i]->percentage>A_temp[j]->percentage){
                for(int k=j;k<=i;k++ ){
                    temp2 = A_temp[k];
                    A_temp[k] = temp1;
                    temp1 = temp2;
                }            
            }
        }
        
    }

}

void topper(){
    Div_A *temp;
    temp = A[1];
    for(int j = 1;j < Div_A::count_a;j++){
        if (temp->percentage>A[j]->percentage){
            temp = A[j];
        }
        
    }
    cout<<"The student with highest percentage is and the percentage obtained are :\n";
    cout<<temp->full_name<<" : "<<temp->percentage<<endl; 
    
}

void setdata(){
    A[Div_A::count_a] = new Div_A;  
    //*A = new Div_A;
    A[Div_A::count_a]->set_data();
    for(int i = 1;i<=Div_A::count_a;i++){
            Div_A *temp1,*temp2;
            cout<<A[Div_A::count_a]->full_name<<endl;
            if((A[Div_A::count_a]->full_name)<(A[i]->full_name)){
                //temp = A[i];
                temp1 = A[i];
                A[i] = A[Div_A::count_a];
                A[i]->roll_no = i;
                for(int j=i+1;j<Div_A::count_a;j++){
                    temp2 = A[j];
                    A[j] = temp1;
                    A[j]->roll_no = j;
                    temp1 = temp2;
                }
                A[Div_A::count_a] = temp1;
                A[Div_A::count_a]->roll_no = Div_A::count_a;
                break;    
            }
        }
        
    //A[Div_A::count_a]->get_data();
    //*A++;
}

void all_data()
{
    string abc;
    //for(int i=0;i<Div_A::count_a;i++)
    
        cout<<"Following is the list of the students present in Class: \n";
        //cout<<A[i]->roll_no<<" "<<A[i]->full_name<<endl;
        ifstream file ("students.txt");
        while (getline (file, abc))
        cout << abc << endl;
        file.close();
    
    
}
void Div_A :: set_marks(Div_A *temp1){
try{
    if(Div_A::count_a==0){throw 1;}
    if(Div_A::count_a == Div_A::count_temp){throw 2.0;}
    else{
    cout<<"For which student you want to input the marks of the student?";
    
    cout<<"\nEnter marks out of 100 "<<endl;
    cout<<"FDS :";
    cin>>fds;
    //er_handler(&fds);
    cout<<"CG :";
    cin>>cg;
    //er_handler(&cg);
    cout<<"DELD :";
    cin>>deld;
    //er_handler(&deld);
    cout<<"OOP :";
    cin>>oop;
    //er_handler(&oop);
    cout<<"DM :";
    cin>>dm;
    percentage = float((fds+cg+deld+oop+dm)*0.2);
    A_temp[count_temp] = temp1;
    count_temp++;
    ofstream file ("marks.txt", ios::app);
    file << "FDS: " << fds <<"CG: " << cg <<"DELD: "  << deld << "DM: " << dm <<endl;
    }
}
    catch(int one){
        cout<<"No entry is created please create an entry.\n";
        setdata();
    }
    catch(float two){}
}

int main()
{
    int ch,set=1;
    do
    {
        cout<<" 1. For creating your entry\n 2. For Analysis of all the students\n 3. For Entering marks of the student\n 4. Student with the highest percentage\n 5. Return to Main Menu\n 6. Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                //A[Div_A::count_a]->set_data();
                setdata();
                main();
                break;
                
            case 2:
                all_data();
                main();
                break;
                //function to present all the data
            case 3:
                all_data();
                A[set]->set_marks(A[set]);
                set++;
                main();
                break;
                //function to present the analysis of the particular student
            case 4:
            /*    A_sortpercent();
            for(int i=0;i<Div_A::count_a;i++){
                cout<<A_temp[i]->full_name<<" : "<<A_temp[i]->percentage<<endl;
            }*/
                topper();
                main();
                break;
                //function to present analysis of the merit list
            case 5:
                main();
                break;
            case 6:
                cout<<"Thankyou for using our Program";
                break;
        }
    }
    while(0<ch>5);
    

}
