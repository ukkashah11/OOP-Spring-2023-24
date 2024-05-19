#include "iostream"
#include "fstream"
#include "vector"
using namespace std;
fstream file;
class User{
    string username, country, interest;
    int age;
    public:
    User(string u, string c, string i, int a)
    :username(u), country(c), interest(i), age(a){}
    void ask(string query);
    string getName()const{return username;}
    string getInterest()const{return interest;}
};
class ChatBot{
    protected:
    int users;
    string recent_user;
    public:
    ChatBot(int u=0):users(u){}
    virtual void getInstances() = 0;
    virtual string generate_response(User u)=0;
    void RecentUser(string name){
        recent_user = name;
        cout<<"Most recent user: "<<recent_user<<endl;
    }
    int getTotalUsers()const{return users;}
};
class MedicalChatBot: public ChatBot{
    static int instances;
    public:
    MedicalChatBot(int u=0):ChatBot(u){instances++;}
    void getInstances(){
        cout<<"Total instances of Medical ChatBot: "<<instances<<endl;
    }
    string generate_response(User u){
        users++;
        recent_user = u.getName();
        return "Take medicines\n";
    }
};
class TechnologyChatBot: public ChatBot{
    static int instances;
    public:
    TechnologyChatBot(int u=0):ChatBot(u){instances++;}
    void getInstances(){
        cout<<"Total instances of Technology ChatBot: "<<instances<<endl;
    }
    string generate_response(User u){
        users++;
        recent_user = u.getName();
        return "Restart your system\n";
        }
};
class LegalChatBot: public ChatBot{
    static int instances;
    public:
    LegalChatBot(int u=0):ChatBot(u){instances++;}
    void getInstances(){
        cout<<"Total instances of Legal ChatBot: "<<instances<<endl;
    }
    string generate_response(User u){
        users++;
        recent_user = u.getName();
        return "Call your lawyer\n";
    }
};
class GeneralChatBot: public ChatBot{
    static int instances;
    public:
    GeneralChatBot(int u=0):ChatBot(u){instances++;}
    void getInstances(){
        cout<<"Total instances of General ChatBot: "<<instances<<endl;
    }
    string generate_response(User u){
        users++;
        recent_user = u.getName();
        return "Response\n";
    }
};
int MedicalChatBot::instances;
int LegalChatBot::instances;
int GeneralChatBot::instances;
int TechnologyChatBot::instances;
class BotException{
    string ex;
    public:
    BotException(string e):ex(e){}
    string getException() const{ return ex;}
};
void User::ask(string query){
    {
        string str;
        int i;
        for(i=0; i<query.length(); i++){
            if(query[i]==' ' || query[i]=='\0') break;
            str+=query[i];
        }
        try{
            if(str == "doc" || (str=="special" && interest=="medicine")){
                MedicalChatBot m; 
                cout<<m.generate_response(*this);
                m.getInstances();
                m.RecentUser(username);
            }
            else if(str == "guru" || (str=="special" && interest=="tech")){
                TechnologyChatBot t; 
                cout<<t.generate_response(*this);
                t.getInstances();
                t.RecentUser(username);
            }
            else if(str == "attorney" || (str=="special" && interest=="law")){
                LegalChatBot l; 
                cout<<l.generate_response(*this);
                l.getInstances();
                l.RecentUser(username);
            }
            else if(str == "Hello"){
                GeneralChatBot g; 
                cout<<g.generate_response(*this);
                g.getInstances();
                g.RecentUser(username);
            }
            else{
                throw BotException("Invalid query prefix");
            }
        }
        catch(BotException e){
            cout<<e.getException()<<endl;
            file.open("error_log.txt", ios::app);
            file<<username+" caused an exception with the query: "<<query<<"\n";
        }
    }
}
int main()
{
    User me("ukkashah20@gmail.com", "Pak", "law", 20);
    User me2("Leo19&yahoo.com", "Ind", "tech", 19);
    me.ask("special case");
    me.ask("doc what should I do?");
    me.ask("fksml");
    me.ask("doc I'm ill");
    me.ask("Hello my name is Ukkashah");
    me.ask("guru my mic doesn't work");
    me2.ask("special case again");
    file.close();
    return 0;
}
