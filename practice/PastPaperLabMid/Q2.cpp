#include <iostream>
#include <cstdlib>
#define SIZE 5
using namespace std;
class Post;
class Comment;
class User{
    static int id;
    int userId;
    string userName;
    Post* posts [SIZE];
    public:
    User(string un):userName(un){
        id++;
        userId = id;
    }
    void displayUserFeed(){
        cout<<"Post History\n";
        for(int i=0; i<SIZE; i++){
            if(posts[i]==nullptr){
                break;
            }
            else{
                cout<<posts[i]->getContent()<<endl;
                cout<<"Comments on post:\n";
                posts[i]->showComments();
            }
        }
    }
    int getId() const{
        return userId;
    }
    void createPost(Post* p){
        for(int i=0; i<SIZE; i++){
            if(posts[i]==nullptr){
                posts[i] = p;
                cout<<"New post created"<<endl;
                break;
            }       
        }
    }
    Post* searchPost(int id){
        for(int i=0; i<SIZE; i++){
            if(posts[i]!=nullptr && posts[i]->getId()==id){
                return posts[i];
                break;
            }
        }
        return nullptr;
}
};
class Post{
    static int id;
    int postId;
    string content;
    Comment* comments[SIZE];
    public:
    void addComment(Comment* c){
        for(int i=0; i<SIZE; i++){
            if(comments[i]==nullptr){
                comments[i] = c;
                cout<<"Comment added to post"<<endl;
                break;
            }       
        }
    }
    int getId() const{
        return postId;
    }
    void showComments(){
        for(int i=0; i<SIZE; i++){
            if(comments[i]==nullptr){
                cout<<comments[i]<<endl;
                break;
            }       
        }
    }
    Post(string c): content(c){id++;postId=id;}
    string getContent()const{
        return content;
    }

};
class Comment {
    static int id;
    int commentId;
    string content;
    User* user;
public:
    Comment(string c, User* u);
};
class SocialMediaPlatform{
    User* users[SIZE];
    public:
    void registerUser(User* u){
        for(int i=0; i<SIZE; i++){
            if(users[i]==nullptr){
                users[i] = u;
                cout<<"User registered"<<endl;
                break;
            }
        }
    }
    User* searchUser(int id){
        for(int i=0; i<SIZE; i++){
            if(users[i]!=nullptr && users[i]->getId()==id){
                return users[i];
                break;
            }
        }
        return nullptr;
}
};
User::User(string un) : userName(un) {
    id++;
    userId = id;
    for (int i = 0; i < SIZE; ++i) posts[i] = nullptr;  // Initialize pointers to nullptr
}

void User::createPost(Post* p) {
    // Implementation...
}

Post* User::searchPost(int id) {
    // Implementation...
}

// Implementations of the Post methods that require Comment
Post::Post(string c) : content(c) {
    id++;
    postId = id;
    for (int i = 0; i < SIZE; ++i) comments[i] = nullptr;  // Initialize pointers to nullptr
}

// Implementations of the Comment methods
Comment::Comment(string c, User* u) : content(c), user(u) {
    id++;
int main(){
    int c, id;
    string name, content;
    SocialMediaPlatform IG;
    cout<<"SOCIAL MEDIA PLATFORM\n";
    cout<<"1. Register a new user"<<endl;
    cout<<"2. Create a new post"<<endl;
    cout<<"3. Add a new comment to posts"<<endl;
    cout<<"4. Display user feed"<<endl;
    cout<<"5. Exit"<<endl;
    cin>>c;
    while(1){
    switch(c){
        case 1:
        cin.ignore();
        cout<<"Enter name: ";
        getline(cin, name);
        IG.registerUser(new User(name));
        break;
        case 2:
        cout<<"Enter ID of user to create new post with: ";
        cin>>id;
        if(IG.searchUser(id)==nullptr){
            cout<<"User not found"<<endl;
        }
        else{
            cout<<"Write post: ";
            cin.ignore();
            getline(cin, content);
            IG.searchUser(id)->createPost(new Post(content));
        }
        break;
        case 3:
        cout<<"Enter ID of user to comment with: ";
        cin>>id;
        User* u = IG.searchUser(id);
        if(u==nullptr){
            cout<<"User not found"<<endl;
        }
        else{
            cout<<"Enter ID of post to comment on: ";
            cin>>id;
            Post* p = u->searchPost(id);
            if(p == nullptr) cout<<"Post not found"<<endl;
            else{
                cout<<"Write comment: ";
                cin.ignore();
                getline(cin, content);
                p->addComment(new Comment(content, u));
            }
        }
        break;
        case 4:
        cout<<"Enter ID of user for their post history: ";
        cin>>id;
        User* u = IG.searchUser(id);
        u->displayUserFeed();
        break;
        case 5:
        exit(1);
        defualt:cout<<"Invalid input"<<endl;
    }
}
}
