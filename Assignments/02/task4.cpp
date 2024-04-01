#include <string>
#include <regex>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
const int PRIME_CONST = 31;
 static const int MAX_FEED_SIZE = 10;
bool isValidEmail(const string email) { //function checks email validity
    // Regular expression for validating an Email
    regex emailRegex(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");
    // Return true if the email matches the regex, else false
    return regex_match(email, emailRegex);
}
int hashFunction(string key) { //function encrypts password by using the Polynomial Rolling Algorithm
    int hashCode = 0;
    for (int i = 0; i < key.length(); i++) {
        hashCode += key[i] * pow(PRIME_CONST, i);
    }
    return hashCode; // a hashcode is returned
}
class Post{
    static int id;
    int postId, views=0, likes=0;
    vector <string> comments;
    string content;
   public:
   Post(string c):content(c)
   {
    id++;
    postId=id;
    cout<<"Post created"<<endl;
   }
   void addComment(string c){
    comments.push_back(c);
    views++;
    cout<<"Comment added to Post"<<endl;
   }
   void likePost(){
    likes++;
    views++;
    cout<<"Post liked"<<endl;
   }
   void displayPostDetails(){
    cout<<"\nPost DETAILS:\n";
    cout<<"Content: "<<content<<endl;
    cout<<"Likes: "<<likes<<endl;
    cout<<"Views: "<<views<<endl;
    cout<<"Post comments:\n ";
    for(string i: comments)cout<<i<<endl;
   }
   void setLikes(const int l){
    likes = l;
   }
   int getLikes()const{
    return likes;
   }
   void setViews(const int v){
    views = v;
   }
   int getViews() const{
    return views;
   }
   int getComments()const{
    return comments.size();
   }
};
int Post::id;
class User{
    string username, email;
    int hash_pwd;
    public:
    User(string u, string e, string pwd){
        if(isValidEmail(e))email = e;
        else cout<<"Invalid email"<<endl;
        hash_pwd = hashFunction(pwd);
        username = u;
    }
};
class RegularUser : public User{
    static Post* feed[MAX_FEED_SIZE];
    static int cnt;
    Post* posts[5] = {nullptr};
    public:
    RegularUser(string u, string e, string pwd):User(u,e,pwd){}
    virtual void addToFeed(Post* p){
        bool flag = true;
        if(cnt<MAX_FEED_SIZE){
        for(int i=0; i<5; i++){
        if(posts[i]==nullptr){
            posts[i] = p;
            feed[cnt] = posts[i];
            cnt++;
            flag = false;
            break;
        }
    }
    if(flag)cout<<"Upgrade to Business user to add more posts"<<endl; 
    }
    else{
        cout<<"Feed is full"<<endl;
    }
    }
    virtual void viewFeed(){
        for(Post* p:feed)p->displayPostDetails();
    }
};
Post* RegularUser:: feed[MAX_FEED_SIZE] = {nullptr};
int RegularUser::cnt;
class BusinessUser: public RegularUser{
    static Post* feed[MAX_FEED_SIZE];
    Post* business_posts[MAX_FEED_SIZE]={nullptr};
    static int cnt;
    int promo = 0;
    public:
    BusinessUser(string u, string e, string pwd):RegularUser(u,e,pwd){}
    void promotePost(Post* p){
        if(promo<10){
        p->setLikes(p->getLikes()*2);
        p->setViews(p->getViews()*3);
        promo++;
        cout<<"Post promoted"<<endl;
        }
        else{
        cout<<"Can't promote more posts"<<endl;
        }
    }
    void trackPost(Post* p){
        cout<<"Post Analytics: \n";
        cout<<"Views: "<<p->getViews()<<endl;
        cout<<"Likes: "<<p->getLikes()<<endl;
        cout<<"Comments: "<<p->getComments()<<endl;
    }
    void addToFeed(Post* p){
        if(cnt<MAX_FEED_SIZE){
        for(int i=0; i<MAX_FEED_SIZE; i++){
        if(business_posts[i]==nullptr){
            business_posts[i] = p;
            feed[cnt] = business_posts[i];
            cnt++;
            break;
        }
    }
        }
    else{
        cout<<"Feed is full"<<endl;
    }
    }
    void viewFeed(){
        for(int i=0; i<MAX_FEED_SIZE; i++){
            if(business_posts[i]!=nullptr)business_posts[i]->displayPostDetails();
    }
}
};
Post* BusinessUser:: feed[MAX_FEED_SIZE] = {nullptr};
int BusinessUser::cnt;
int main(){
    cout<<"SYED UKKASHAH\n23K-0055\n\n";
    cout<<"Regular user interactions:\n\n";
    RegularUser u1("ukkashah11", "k230055@nu.edu.pk", "uk456");
    RegularUser u2("ukkashah22", "453mdksn", "ksmkf"); // Invalid email example, regex check returns false as email format is incorrect
    RegularUser u3("ukkashah33", "ukkashahsyed@gmail.com", "uk123");
    Post p1("1st Regular User Post from user 1");
    Post p2("2nd Regular User Post from user 1");
    Post p3("3rd Regular User Post from user 1");
    Post p4("4th Regular User Post from user 1");
    Post p5("5th Regular User Post from user 1");
    Post p6("6th Regular User Post from user 1");
    Post p7("1st Regular User Post from user 2");
    Post p8("2nd Regular User Post from user 2");
    Post p9("3rd Regular User Post from user 2");
    Post p10("1st Regular User Post from user 3");
    Post p11("2nd Regular User Post from user 3");
    Post p12("3rd Regular User Post from user 3");
    u1.addToFeed(&p1);
    u1.addToFeed(&p2);
    u1.addToFeed(&p3);
    u1.addToFeed(&p4);
    u1.addToFeed(&p5); 
    u1.addToFeed(&p6); //won't add 6th post, limit is 5 posts per Regular User
    u2.addToFeed(&p7);
    u2.addToFeed(&p8);
    u2.addToFeed(&p9);
    u3.addToFeed(&p10);
    u3.addToFeed(&p11);
    u3.addToFeed(&p12); //feed post limit reached
    p1.likePost();
    p1.likePost();
    p1.addComment("Comment 1 on regular post 1");
    p1.addComment("Comment 2 on regular post 1");
    cout<<"\n\nRegular Feed: \n";
    u1.viewFeed();
    cout<<"\n\nBusiness user interactions:\n\n";
    BusinessUser b1("syed11", "syed@gmail.com", "123wer");
    Post p13("1st Business User Post from user 1");
    Post p14("2nd Business User Post from user 1");
    b1.addToFeed(&p13);
    b1.addToFeed(&p14);
    p13.likePost();
    p13.likePost();
    p13.likePost();
    p13.likePost();
    p13.addComment("Comment 1 on business post 1");
    p14.likePost();
    p14.addComment("Comment 2 on business post 2");
    b1.promotePost(&p13);
    b1.promotePost(&p14);
    b1.trackPost(&p13);
    cout<<"\n\nBusiness Feed: \n";
    b1.viewFeed();
    return 0;
}