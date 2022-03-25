#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

struct emp{
    string name,id,address;
    int contact,salary;
};
emp e[100];
int total=0;

void empdata(){
    int choice;
    cout<<"How many employees data do you want to enter ?"<<endl;
    cin>>choice;
    for(int i = total;i<total+choice;i++){
        cout<<"Enter the data of the Employee "<<i+1<<endl;
        cout<<"Employee Name : ";
        cin>>e[i].name;
        cout<<"ID : ";
        cin>>e[i].id;
        cout<<"Address : ";
        cin>>e[i].address;
        cout<<"Contact : ";
        cin>>e[i].contact;
        cout<<"Salary : ";
        cin>>e[i].salary;
    }
    total = total+choice;  
}

void show(){
    if(total!=0){
        for(int i = 0;i<total;i++){
            cout<<"Data of employee "<<i+1<<endl;
            cout<<"Employee Name: "<<e[i].name<<endl;
            cout<<"Employee ID: "<<e[i].id<<endl;
            cout<<"Employee Address: "<<e[i].address<<endl;
            cout<<"Employee Salary: "<<e[i].salary<<endl;
            cout<<"Employee Contact: "<<e[i].contact<<endl;
        }
    }
    else{
        cout<<"Your Record is Empty"<<endl;
    }
}

void search(){
    if(total!= 0){
        string id;
        cout<<"Enter ID of data which you want to search "<<endl;
        cin>>id;
        for(int i = 0;i<total;i++){
            if(id==e[i].id){
            cout<<"Data of employee "<<i+1<<endl;
            cout<<"Employee Name: "<<e[i].name<<endl;
            cout<<"Employee ID: "<<e[i].id<<endl;
            cout<<"Employee Address: "<<e[i].address<<endl;
            cout<<"Employee Salary: "<<e[i].salary<<endl;
            cout<<"Employee Contact: "<<e[i].contact<<endl;
            break;
            }
            if(i==total-1){
                cout<<"No such record found"<<endl;
            }
        }
    }
    else{
        cout<<"Your Record is Empty"<<endl;
    }
}

void update(){
    if(total != 0){
        string id;
        cout<<"Enter ID of data which you want to update "<<endl;
        cin>>id;
        for(int i = 0;i<total;i++){
            if(id==e[i].id){
            cout<<"Previous Data "<<endl;
            cout<<"Data of employee "<<i+1<<endl;
            cout<<"Employee Name: "<<e[i].name<<endl;
            cout<<"Employee ID: "<<e[i].id<<endl;
            cout<<"Employee Address: "<<e[i].address<<endl;
            cout<<"Employee Salary: "<<e[i].salary<<endl;
            cout<<"Employee Contact: "<<e[i].contact<<endl;
            
            cout<<"\nEnter new data "<<endl;
            cout<<"Enter the data of the Employee "<<i+1<<endl;
            cout<<"Employee Name : ";
            cin>>e[i].name;
            cout<<"ID : ";
            cin>>e[i].id;
            cout<<"Address : ";
            cin>>e[i].address;
            cout<<"Contact : ";
            cin>>e[i].contact;
            cout<<"Salary : ";
            cin>>e[i].salary;
            break;
            }
            if(i==total-1){
                cout<<"No such record found"<<endl;
            }
        }
    }
    else{
        cout<<"Your Record is Empty"<<endl;
    }
}
void del(){
    if(total != 0){
        char user;
        cout<<"1.To Delete Full Record "<<endl;
        cout<<"2.To Delete Specific Record "<<endl;
        user=getch();
        if(user == '1'){
            total = 0;
            cout<<"All Record is Deleted!!!!"<<endl;
        }
        else if(user=='2'){
            string id;
            cout<<"Enter ID of data which you want to be deleted "<<endl;
            cin>>id;
            for(int i=0;i<total;i++){
                if(id==e[i].id){
                    for(int j=i;j<total;j++){
                    e[j].name = e[j+1].name;
                    e[j].id = e[j+1].id;
                    e[j].address = e[j+1].address;
                    e[j].contact = e[j+1].contact;
                    e[j].salary = e[j+1].salary;
                    total--;
                    cout<<"Your Required Data is Deleted "<<endl;
                    break;
                    }
                if(i==total-1){
                    cout<<"No Such Record Found"<<endl;
                }
                }
            }
        }
    }
    else{
        cout<<"Your record is Empty"<<endl;
    }
}

int main(){
    cout<<"\n\n\t\tEmployee Management System"<<endl;
    cout<<"\n\n\t\tSign Up"<<endl;
    string username,password;
    cout<<"\n\t\tEnter Username : ";  
    cin>>username;
    cout<<"\n\t\tEnter Password : ";
    cin>>password;
    cout<<"\n\t\tYour ID is creating please wait";
    for(int i=0;i<5;i++){
        cout<<".";
        Sleep(500); //1000 miliseconds to 1 seconds
    }
    cout<<"\n\t\tYour ID created successfully"<<endl;
    system("CLS"); //To clear the screen
    start:
        system("CLS");
    cout<<"\n\n\t\tEmployee Management System"<<endl;
    cout<<"\n\n\t\tLogin"<<endl;
    string username1,password1;
    cout<<"Username : ";
    cin>>username1;
    cout<<"Password : ";
    cin>>password1;
    if(username1==username && password1==password){
        system("CLS");
        char user;
        while(1){
            cout<<"\n\n1.Enter Data "<<endl;
            cout<<"2.Show Data "<<endl;
            cout<<"3.Search Data "<<endl;
            cout<<"4.Update Data "<<endl;
            cout<<"5.Delete Data "<<endl;
            cout<<"6.Logout "<<endl;
            cout<<"7.Exit "<<endl;
            user=getch();
            system("CLS");
            switch(user){
                case '1':
                    empdata();
                    break;
                case '2':
                    show();
                    break;
                case '3':
                    search();
                    break;  
                case '4':
                    update();
                    break;
                case '5':
                    del();
                    break;  
                case '6':
                    goto start;
                    break;
                default:
                    cout<<"\aInvalid Input"<<endl;
                    break;
            }
        }
    }else if(username1 != username){
        cout<<"Your Username is incorrect"<<endl;
        Sleep(3000);
        goto start;
    }else if(password1 != password){
        cout<<"Your Password is incorrect"<<endl;
        Sleep(3000);
        goto start;
    }
     
    return 0;
}