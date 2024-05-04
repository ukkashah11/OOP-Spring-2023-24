#include "iostream"
#include "vector"
using namespace std;
class Medicine{
    string name, formula, expiration, manufacture_date;
    float retail_price;
    public:
    Medicine(string n, string f, string exp, string m, float p):name(n), formula(n), expiration(exp), manufacture_date(m), retail_price(p){}
     string getName();
    void setName(string n);
    string getFormula();
    void setFormula(string f);
    string getExpiration();
    void setExpiration(string exp);
    string getManufactureDate();
    void setManufactureDate(string m);
    float getRetailPrice();
    void setRetailPrice(float r);
    virtual void print();
      bool operator == (const Medicine& obj) { return obj.expiration == expiration; }
};
class Tablet: public Medicine{
    float sucroseLevel;
    public:
    Tablet(string n, string f, string exp, string m, float s, float p):Medicine(n, f, exp, m, p)
    {
        if (s>=0 && s<=1) sucroseLevel = s;
        else cout<<"Sucrose level should range from 0 to 1"<<endl;
    }
    float getSucroseLevel();
    void setSucroseLevel(const float s);
    void print();
};
class Capsule: public Medicine{
    float absorption;
    public:
    Capsule(string n, string f, string exp, string m, float p, float a):Medicine(n, f, exp, m, p){
        if (a>=0 && a<=100) absorption = a;
        else cout<<" 'Absorption %' should range from 0 to 100"<<endl;
    }
    void setAbsorption(const float a);
    float getAbsorption();
    void print();
};
class Syrup : public Medicine{
    string type;
    public:
    Syrup(string n, string f, string exp, string m, string t, float p):Medicine(n, f, exp, m, p), type(t){}
    void setType(const string);
    string getType()const; 
    void print();
};
// global medicine array maintained for the store
int med_count = 3;
Medicine *medicine_list[] = {
    new Capsule("Capsule", "Formula 1", "5/24", "Manufacturer 1", 30.99, 80.5),
    new Tablet("Table", "Formula 2", "6/25", "Manufacturer 2", 20.66, 50),
    new Syrup("Syrup", "Formula 3", "7/24", "Manufacturer 3", "Cough", 95)
};
class Pharmacist{
    vector <Medicine> medicines;
    public:
    Pharmacist(vector<Medicine> meds):medicines(meds){}
    void Search_Medicine(string formula);
};
class Counter{
    vector <Medicine> medicines;
    float total_revenue = 0;
    public:
    Counter(vector<Medicine> meds):medicines(meds){}
    void Search_Medicine(string name);
    void Update_Revenue();
};


