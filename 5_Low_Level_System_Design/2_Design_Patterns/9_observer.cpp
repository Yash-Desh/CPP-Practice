// Author: Yash Deshpande
// Date  : 27-09-2025
// Tutor : Keerti Purswani YouTube : https://youtu.be/gbTWHeGUeXs?si=vZujnKqi15aV1BfI

#include <iostream>
#include <string>
#include <list>
using namespace std;

// Define interface for all subscribers.
class ISubscriber {
    public:
        virtual void notify(string msg) = 0;
};

class User : public ISubscriber {
    private:
        int userId;
    
    public:
        User(int userId) {
            this->userId = userId;
        }
        void notify(string msg) {
            cout<<"User-"<<userId<<" received the message "<<msg<<endl;
        }
};

// Define class that maintains a group of subscribers
class Group {
    private:
        list<ISubscriber*> users;

    public:
        void subscribe(ISubscriber *user) {
            users.push_back(user);
        }
        void unsubscribe(ISubscriber *user) {
            users.remove(user);
        }
        void notify(string msg) {
            for(auto user : users) {
                user->notify(msg);
            }
        }
};

int main() {
    // ##############
    // Client
    // ##############

    Group* group = new Group;

    // Create Users.
    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);

    // Register/Subscribe users into the group
    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    // Send message to all the subscribers
    group->notify("first message");

    // Unsubscribe some user
    group->unsubscribe(user1);

    // Send message to existing subscribers
    // & check if the unsubscription was successful.
    group->notify("second message");

    return 0;
}