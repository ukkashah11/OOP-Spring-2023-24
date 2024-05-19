#include "iostream"
#include "fstream"
using namespace std;
class Candidate{
    string name, degree, DOB, address;
    unsigned int NIC, experience;
    double expected_salary;
    static int cand_ID;
    public:
    Candidate(){}
    Candidate(string name, string degree, string DOB, string address, unsigned int NIC, unsigned int experience, double expected_salary):
    name(name), degree(degree), DOB(DOB), address(address), NIC(NIC), experience(experience), expected_salary(expected_salary){cand_ID++;}
    string get_name()const{return name;}
    int get_experience()const{return experience;}
    double get_expected_salary()const{return expected_salary;}
    static int get_cand_ID(){return cand_ID;}
    string get_degree()const{return degree;}
};
class Moderator{
    static int mod_ID, applications;
    public:
    Moderator(){mod_ID++;}
    static int get_mod_ID(){return mod_ID;}
    static void applied(){applications++;}
    static int get_applications(){return applications;}
    bool write_data()
    {
        fstream file("info.txt", ios::out);
        try{if(!file) throw "File handling failed";}
        catch(const char* ex){
            cout<<ex<<endl;
            return false;
        }
        file<<"Total job applications: "<<get_applications()<<"\n";
        file.close();
        return true;
    }
    bool write_data(string msg)
    {
        fstream file("messages.txt", ios::out);
        try{if(!file) throw "File handling failed";}
        catch(const char* ex){
            cout<<ex<<endl;
            return false;
        }
        file<<msg<<"\n";
        file.close();
        return true;
    }
};
class Employer{
    Candidate* cand;
    static int employer_ID;
    string name;
    public:
    Employer(string name):name(name){employer_ID++; cand = new Candidate();}
    virtual string post_vacancy() = 0;
    void selectCandidate(Candidate* c){
        cand = c;
        cout<<"vacancy closed"<<endl;
    }
    virtual bool receive_application(Candidate* c)=0;
    static int get_employer_ID(){return employer_ID;}
    string getName()const{return name;}
    ~Employer(){delete cand;}
};
class Ed_Institute: public Employer{
    int campuses;
    public:
    Ed_Institute(string name, int campuses):Employer(name),campuses(campuses){}
    string post_vacancy(){return "teaching years and ability to cope with pressure";}
    bool receive_application(Candidate* c){
        Moderator::applied();
        cout << "Candidate " << c->get_name() << " has applied for the vacancy posted by " << getName() << endl;
        if(c->get_experience()>=60){
            selectCandidate(c);
            return true;
        }
        if(c->get_expected_salary()<=30000 && c->get_degree()=="AP Science"){
            selectCandidate(c);
            return true;
        }
        return false;
    }
    int getCampuses()const{return campuses;}

};
class Bank:public Employer{
    int branches;
    public:
    Bank(string name, int branches):Employer(name),branches(branches){}
    string post_vacancy(){return "Good communication skills and if a candidate can work in a large team";}
    bool receive_application(Candidate* c){
        Moderator::applied();
        cout << "Candidate " << c->get_name() << " has applied for the vacancy posted by " << getName() << endl;
        if(c->get_experience()>=60){
            selectCandidate(c);
            return true;
        }
        if(c->get_expected_salary()<=50000 && c->get_degree()=="Finance"){
            selectCandidate(c);
            return true;
        }
        return false;
    }
    int getBranches()const{return branches;}
};
class Construction: public Employer{
    int projects;
    public:
    Construction(string name, int projects):Employer(name),projects(projects){}
    string post_vacancy(){return "ability to work in remote areas";}
        bool receive_application(Candidate* c){
        Moderator::applied();
        cout << "Candidate " << c->get_name() << " has applied for the vacancy posted by " << getName() << endl;
        if(c->get_experience()>=60){
            selectCandidate(c);
            return true;
        }
        if(c->get_expected_salary()<=50000 && c->get_degree()=="Civil Engineering"){
            selectCandidate(c);
            return true;
        }
        return false;
    }
    int getProjects()const{return projects;}
};
class Pharmaceutical: public Employer{
    float budget;
    public:
    Pharmaceutical(string name, float budget):Employer(name),budget(budget){}
    string post_vacancy(){return "good analytical skills";}
    bool receive_application(Candidate* c){
        Moderator::applied();
        cout << "Candidate " << c->get_name() << " has applied for the vacancy posted by " << getName() << endl;
        if(c->get_experience()>=60){
            selectCandidate(c);
            return true;
        }
        if(c->get_expected_salary()<=60000 && c->get_degree()=="MBBS"){
            selectCandidate(c);
            return true;
        }
        return false;
    }
    int getBudget()const{return budget;}
};
bool operator < (const Candidate& obj1, const Candidate obj2){
    return obj1.get_experience() < obj2.get_experience();
}
int Candidate::cand_ID;
int Moderator::mod_ID;
int Moderator::applications;
int Employer::employer_ID;
int main()
{
    Moderator m;
    Ed_Institute edu("ABC University", 5);
    Bank bank("XYZ Bank", 10);
    Construction construction("DEF Construction", 20);
    Pharmaceutical pharma("GHI Pharmaceutical", 30);
    Candidate c1("John Doe", "AP Science", "01/01/1990", "123 Main St", 123456, 5, 30000);
    Candidate c2("Jane Doe", "Finance", "02/02/1990", "456 Elm St", 234567, 10, 50000);
    Candidate c3("Jim Doe", "Civil Engineering", "03/03/1990", "789 Oak St", 345678, 15, 60000);
    Candidate c4("Jill Doe", "MBBS", "04/04/1990", "321 Pine St", 456789, 20, 70000);
    cout << "Posting vacancies..." << endl;
    cout << "Ed Institute: " << edu.post_vacancy() << endl;
    cout << "Bank: " << bank.post_vacancy() << endl;
    cout << "Construction: " << construction.post_vacancy() << endl;
    cout << "Pharmaceutical: " << pharma.post_vacancy() << endl;
    cout << "\nReceiving applications..." << endl;
    if (edu.receive_application(&c1)) {
        cout << "Candidate " << c1.get_name() << " was selected for the vacancy posted by " << edu.getName() << endl;
    }
    if (bank.receive_application(&c2)) {
        cout << "Candidate " << c2.get_name() << " was selected for the vacancy posted by " << bank.getName() << endl;
    }
    if (construction.receive_application(&c3)) {
        cout << "Candidate " << c3.get_name() << " was selected for the vacancy posted by " << construction.getName() << endl;
    }
    if (pharma.receive_application(&c4)) {
        cout << "Candidate " << c4.get_name() << " was selected for the vacancy posted by " << pharma.getName() << endl;
    }
    cout << "\nModerator stats:" << endl;
    cout << "Moderator ID: " << m.get_mod_ID() << endl;
    cout << "Total applications: " << m.get_applications() << endl;
    cout << "\nEmployer stats:" << endl;
    cout << "Ed Institute ID: " << edu.get_employer_ID() << endl;
    cout << "Campuses: " << edu.getCampuses() << endl;
    cout << "Bank ID: " << bank.get_employer_ID() << endl;
    cout << "Branches: " << bank.getBranches() << endl;
    cout << "Construction ID: " << construction.get_employer_ID() << endl;
    cout << "Active Projects: " << construction.getProjects() << endl;
    cout << "Pharmaceutical ID: " << pharma.get_employer_ID() << endl;
    cout << "Annual Budget: $" << pharma.getBudget() << " million"<<endl;
    m.write_data();
    m.write_data("This is the messages text file");
    return 0;
}

