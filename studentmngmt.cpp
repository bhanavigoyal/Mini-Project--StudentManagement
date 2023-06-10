#include<iostream>
#include<string>
//#include<fstream>
using std::string;

class Node{
    public:
        int roll_no;
        string name;
        string father_name;
        string qualification;
        string phone_no;
        Node* next;
};

class Record{
    public:
    Node* head; //Node* head = NULL not working bcz non static data members
                //cannot be assigned values prior to C++ 11.that is why constructor
    Record(){
        head = NULL;
    }
    void Insert(){
        // std::fstream file;
        // file.open("Items.txt",std::ios::app);   //what is ios::app

        int Roll;
        string Name;
        string Father_name;
        string Qualif;
        string Phone;

        std::cout<<"\n\n Enter Student ID: ";
        std::cin>>Roll;
        fflush(stdin);
        std::cout<<"\n\n Enter Student Name: ";
        getline(std::cin, Name);
        std::cout<<"\n\n Enter Father Name: ";
        getline(std::cin,Father_name);
        std::cout<<"\n\n Enter Student Qualification: ";
        getline(std::cin, Qualif);
        std::cout<<"\n\n Enter Phone No: ";
        std::cin>>Phone;

        Node *newNode = new Node;
        newNode ->roll_no = Roll;
        newNode ->name = Name;
        newNode ->father_name = Father_name;
        newNode ->qualification = Qualif;
        newNode ->phone_no = Phone;
        newNode -> next = NULL;

        // file<<newNode->roll_no<<"\n";
        // file<<newNode->name<<"\n";
        // file<<newNode->father_name<<"\n";
        // file<<newNode->qualification<<"\n";
        // file<<newNode->phone_no<<"\n";

        if(head==NULL){
            head=newNode;
            //tail=newNode;
        }
        else{
            Node* temp = head;

            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = newNode;
        }
        std::cout<<"\n\n New Data Inserted"<<std::endl;
    }

    void Search(){
        if(head==NULL){
            std::cout<<"\n\n No Records Found. \n Please Enter the details of Students and check again later."<<std::endl;
        }
        else{
            int roll;
            bool found = false;
            std::cout<<"\n\nEnter Student Id to Search: ";
            std::cin>>roll;
            Node*temp=head;

            while(temp!=NULL){
                if(roll== temp->roll_no){
                    std::cout<<"\n\n Student Id: "<< temp->roll_no;
                    std::cout<<"\n\n Student Name: "<<temp->name;
                    std::cout<<"\n\n Student Father Name: "<<temp->father_name;
                    std::cout<<"\n\n Student Qualification: "<<temp->qualification;
                    std::cout<<"\n\n Student Phone Number: "<<temp->phone_no;
                    found=true;

                }

                temp = temp->next;
            }
            if(!found){
                std::cout<<"\n\n No Record for the input Student ID.\n Try again."<<std::endl;
            }
        }
    }

    void Count(){
        if(head==NULL){
            std::cout<<"\n\n No Records Found. \n Please Enter the details of Students and check again later."<<std::endl;
        }
        else{
            int count=0;
            Node* temp = head;
            while(temp!=NULL){
                count++;
                temp=temp->next;
            }
            std::cout<<"\n\n Number of Records: "<< count<<std::endl;
        }
    }

    void Update(){
        if(head==NULL){
            std::cout<<"\n\n No Records Found. \n Please Enter the details of Students and check again later."<<std::endl;
        }
        else{
            int roll;
            bool found = false;

            std::cout<<"\n\n Enter Student ID to update: ";
            std::cin>>roll;

            Node* temp = head;
            while(temp!=NULL){
                if(roll==temp->roll_no){
                    std::cout<<"\n\n Enter new Student ID: ";
                    std::cin>>temp->roll_no;
                    std::cout<<"\n\n Enter new Student Name: ";
                    std::cin>>temp->name;
                    std::cout<<"\n\n Enter new Student Father Name: ";
                    std::cin>>temp->father_name;
                    std::cout<<"\n\n Enter new Student Qualification: ";
                    std::cin>>temp->qualification;
                    std::cout<<"\n\n Enter new Student Phone Number: ";
                    std::cin>>temp->phone_no;


                    std::cout<<"\n\n\n Record Updated Successfully"<<std::endl;
                    found=true;
                }
                temp=temp->next;
            }

            if(!found){
                std::cout<<"Record with Student ID: "<<roll<<" can't be found."<<std::endl;
            }
        }
    }
    void Del(){
        if(head==NULL){
            std::cout<<"\n\n No Records Found. \n Please Enter the details of Students and check again later."<<std::endl;
        }
        else{
            int roll;
            bool found = false;

            std::cout<<"\n\n Enter Student ID to delete: ";
            std::cin>>roll;

            if(roll==head->roll_no){
                Node*temp=head;
                head= head->next;
                found=true;

                temp->next = NULL;
                delete temp;
                std::cout<<"\n\n Record Deleted Successfully"<<std::endl;
            }

            else{
                Node* curr = head->next;
                Node* prev = head;

                while(curr!=NULL){
                    if(roll==curr->roll_no){
                        prev->next = curr->next;
                        found = true;

                        curr->next = NULL;
                        delete curr;
                        break;
                    }

                    prev = curr;
                    curr= curr->next;
                }
                
            }

            if(!found){
                std::cout<<"\n\n Entered Student ID "<<roll<<" can't be found."<<std::endl;
            }
        }
    }

    void Show(){
        if(head==NULL){
            std::cout<<"\n\n No Records Found. \n Please Enter the details of Students and check again later."<<std::endl;
        }
        else{
            
            Node*temp=head;

            while(temp!=NULL){
                std::cout<<"\n Student Id: "<< temp->roll_no;
                std::cout<<"\n Student Name: "<<temp->name;
                std::cout<<"\n Student Father Name: "<<temp->father_name;
                std::cout<<"\n Student Qualification: "<<temp->qualification;
                std::cout<<"\n Student Phone Number: "<<temp->phone_no;

                std::cout<<std::endl;
                std::cout<<std::endl;
                temp = temp->next;
            }
        }
    }

    // void ShowFile(){
        
    // }

};


int main(){

    Record obj;
    block:
    system("clear");
    int choice;
    std::cout<<"\n *******Welcome to Student Management System*******"<<std::endl;
    std::cout<<"\n\n 1. Insert Record";
    std::cout<<"\n\n 2. Search Record";
    std::cout<<"\n\n 3. Total Number of Records";
    std::cout<<"\n\n 4. Update Record";
    std::cout<<"\n\n 5. Delete Record";
    std::cout<<"\n\n 6. Show all Records";
    std::cout<<"\n\n 7. Exit";

    std::cout<<"\n\n\n Enter the number corresponding to the task you want to perform: ";
    std::cin>>choice;
    char x;

    switch (choice)
    {
    case 1:
    do{
        system("clear");
        obj.Insert();
        std::cout<<"\n --- Add more records (y/n)";
        std::cin>>x;
    } while(x=='y'|| x=='Y');
        break;
    case 2:
        system("clear");
        obj.Search();
        break;
    case 3:
        system("clear");
        obj.Count();
        break;
    case 4:
        system("clear");
        obj.Update();
        break;
    case 5:
        system("clear");
        obj.Del();
        break;
    case 6:
        system("clear");
        obj.Show();
        break;
    case 7:
        exit(0);
        break;
    
    default:
        std::cout<<"\n\n\n Invalid Choice \n Please Try Again."<<std::endl;
        break;
    }
    std::cout<<"\n\n Press Enter to continue ";
    // fflush(stdin);
    // getchar();
    std::cin.get();
    std::cin.get();
    goto block;

    return 0;
}