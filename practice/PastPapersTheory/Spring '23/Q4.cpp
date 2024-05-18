#include "iostream"
using namespace std;
class social_network{
    int num_users;
    int** friends;
    public:
    social_network(int users): num_users(users){
    friends = new int*[num_users];
    for(int i = 0; i < num_users; i++)friends[i] = new int[num_users];
    }
    int countFriends(int ID){
        if(num_users>ID)for(int i = 0; i < friends[ID][i]; i++)
        return i;
    }
    void add_friend(int ID, int friend_ID)
    {
        int count =  countFriends(ID);
        int* temp = new int[count + 2];
        int i;
        for (i = 0; i < count; i++)temp[i]=friends[ID][i] ;
        temp[count] = friend_ID;
        temp[i+1] = -1;
        delete[]friends[ID];
        friends[ID] = temp;
    }
    void add_user(int* frnd, int n)
    {
        int** temp = new int* [num_users+1];
        for(size_t i = 0; i < num_users; i++)temp[i] = friends[i];
        delete[]friends;
        friends = temp;
        friends[num_users] = new int[n+1];
        for(int i = 0; i < n; i++)
        {
            friends[num_users][i] = frnd[i];
            add_friend(frnd[i], num_users);
        }
        friends[num_users][n] = -1;
        num_users++;
    }
    bool isFriends(int i, int j)
    {
        for (int k = 0; friends[i][k]!=-1; k++)
        {
            if (friends[i][k]==j)return true;
        }
        return false;
    }
   float* comp_CC() 
   {
        float* cc = new float[num_users];
        //compute the CC of user u
        for (int u = 0;u < num_users;u++) {
            cc[u] = 0;
            int count = countFriends(u);
            int pairs = 0;
            for (int i = 0;friends[u][i] != -1;i++) {
                for (int j = i + 1;friends[u][j] != -1;j++) {
                    if (isFriends(friends[u][i], friends[u][j]))
                        pairs++;
                    }
                }
                if (count > 1)
                cc[u] = (2.0 * pairs) / (count * (count - 1));
            }
        return cc;
    }
};
