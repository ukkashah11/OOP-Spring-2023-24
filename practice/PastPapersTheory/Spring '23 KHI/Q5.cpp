#include "iostream"
#include "fstream"
using namespace std;
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
    static int instances;
    int users;
    string recent_user;
    public:
    ChatBot(int u=0):users(u){}
    virtual void getInstances() = 0;
    virtual string generate_response(User u)=0;
    void RecentUser(string name){recent_user = name;}
    int getTotalUsers()const{return users;}
};
int ChatBot::instances;
class MedicalChatBot: public ChatBot{
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
        for(i=0; query[i]==' '||i<query.length(); i++)str[i]+=query[i];
        try{
            if(str == "doc" || (str=="special" && interest=="medicine")){
                MedicalChatBot m; 
                m.generate_response(*this);
            }
            if(str == "guru" || (str=="special" && interest=="tech")){
                TechnologyChatBot t; 
                t.generate_response(*this);
            }
            if(str == "attorney" || (str=="special" && interest=="law")){
                LegalChatBot l; 
                l.generate_response(*this);
            }
            if(str == "Hello"){
                GeneralChatBot g; 
                g.generate_response(*this);
            }
            else{
                throw BotException("Invalid query prefix");
            }
        }
        catch(BotException e){
            cout<<e.getException()<<endl;
        }
    }
}
int main()
{
    User me("Ukkashah", "Pak", "law", 20);
    me.ask("special");
    return 0;
}
