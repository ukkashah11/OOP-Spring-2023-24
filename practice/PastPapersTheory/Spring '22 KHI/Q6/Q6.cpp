#include "iostream"
#include "fstream"
using namespace std;
class file{
    int size;
    string location, created_date, modified_date;
    public:
    file(string l, int s, string cd, string md): location(l), size(s), created_date(cd), modified_date(md){}
    virtual bool open() = 0;
    virtual void print()
    {
        cout<<"FILE DETAILS\n";
        cout<<"location: "<<location<<endl;
        cout<<"size(MB): "<<size<<endl;
        cout<<"created on: "<<created_date<<endl;
        cout<<"last modified on: "<<modified_date<<endl;
    }
    int getSize()const{return size;}
    string getLocation()const{return location;}
    string getCD()const{return created_date;}
    string getMD()const{return modified_date;}
      
};
class PDF: public file{
    public:
    PDF(string l, int s, string cd, string md): file(l, s, cd, md){}
    bool open()
    {
        fstream file("PDF_file.txt", ios::out);
        try{if(!file) throw "File creation failed";}
        catch(const char* e){
            cout<<e<<endl;
            return false; 
        }
        cout<<"PDF File created/opened"<<endl;
        file<<"This is a PDF File";
        file.close();
        return true;
    }
    void print()
    {
        cout<<"PDF FILE DETAILS\n";
        cout<<"location: "<<getLocation()<<endl;
        cout<<"size(MB): "<<getSize()<<endl;
        cout<<"created on: "<<getCD()<<endl;
        cout<<"last modified on: "<<getMD()<<endl;
    }
};
class ASCII: public file{
    public:
    ASCII(string l, int s, string cd, string md): file(l, s, cd, md){}
    bool open()
    {
        fstream file("ASCII_file.txt", ios::out);
        try{if(!file) throw "File creation failed";}
        catch(const char* e){
            cout<<e<<endl;
            return false; 
        }
        cout<<"ASCII File created/opened"<<endl;
        file<<"This is a ASCII File";
        file.close();
        return true;
    }
    void print()
    {
        cout<<"ASCII FILE DETAILS\n";
        cout<<"location: "<<getLocation()<<endl;
        cout<<"size(MB): "<<getSize()<<endl;
        cout<<"created on: "<<getCD()<<endl;
        cout<<"last modified on: "<<getMD()<<endl;
    }
};
class PS: public file{
    public:
    PS(string l, int s, string cd, string md): file(l, s, cd, md){}
    bool open()
    {
        fstream file("PS_file.txt", ios::out);
        try{if(!file) throw "File creation failed";}
        catch(const char* e){
            cout<<e<<endl;
            return false; 
        }
        cout<<"PS File created/opened"<<endl;
        file<<"This is a PS File";
        file.close();
        return true;
    }
    void print()
    {
        cout<<"PS FILE DETAILS\n";
        cout<<"location: "<<getLocation()<<endl;
        cout<<"size(MB): "<<getSize()<<endl;
        cout<<"created on: "<<getCD()<<endl;
        cout<<"last modified on: "<<getMD()<<endl;
    }
};
bool operator *(const file& obj, const file&obj2){
    return (obj2.getLocation()== obj.getLocation()) && (obj2.getSize()==obj.getSize());
}
int main()
{
    PDF* pdf_ptr = new PDF("Desktop", 12, "5/14/2024", "6/25/2024");
    ASCII* ascii_ptr = new ASCII("D Drive", 14, "7/14/2024", "9/25/2024");
    PS* ps_ptr = new PS("D Drive", 14, "8/14/2024", "10/25/2024");
    pdf_ptr->print();
    ascii_ptr->print();
    ps_ptr->print();
    pdf_ptr->open();
    ascii_ptr->open();
    ps_ptr->open();
    cout<<*pdf_ptr * *ascii_ptr<<endl;
    cout<<*ascii_ptr * *ps_ptr<<endl;
    delete pdf_ptr;
    delete ascii_ptr;
    delete ps_ptr;
    return 0;
}
