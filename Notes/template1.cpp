#include "iostream"
#include "vector"
using namespace std;
template<typename T>
class Stack{
    vector <T> items;
    public:
    void addItem(T a)
    {
        if(!isMember(a))items.push_back(a);
        
    }
    void removeItem(T a)
    {
        for (int i = 0; i< items.size(); i++)
        {
            if(items[i]==a){
                items.erase(items.begin()+i);
                break;
            }
        }
    }
    int getSize()const{return items.size();}
    bool isMember(T a){
        bool flag = false;
        for(T item: items){
            if(item == a){
                flag = true;
                break;
            } 
        }
        return flag;
    }
};
using namespace std;
int main(){
    Stack<int> s;
    s.addItem(3);
    s.addItem(3);
    cout<<s.getSize()<<endl;
    s.addItem(1);
    cout<<s.getSize()<<endl;
    s.removeItem(3);
    cout<<s.getSize()<<endl;
}