// working:
//         - chatsInOrder() - parser and printer of 
//            collective chats of two users
// TODO full name support is pending, working with just first name rn
// TODO modify chatID to have real time time-stamps with each messages
//      easily readable and retrievable for forensics etc.

#include<iostream>
#include<string_view>
#include<string>
#include<vector>
using std::cout,std::string,std::string_view,std::vector,std::pair;



class Users {
	string uName;
	string name;
public:
	int uid;
	Users(string_view chatterName, string_view userName,const int &id): 
		uName(userName), name(chatterName), uid(id)
	{}

};

class ChatsById {
	int uid;
	// each chat shall have two fields, chat id (simply counter, it can be modified to have timestamps in future), and the text
	vector< pair<int,string> > chatList; 

public:
	ChatsById(int id): uid(id) {}
  void addChat(const int &counter, string_view message) {
		chatList.push_back( pair<int,string> {counter,message} );
	}

	void print() {
		for ( pair<int,string> message : chatList ) {
			cout << (message.first) << ":  " << (message.second) << '\n';
		}
		cout << '\n';
	}

	void chatsInOrder(const ChatsById &u1Chats,const ChatsById &u2Chats) {
		int p1{0},p2{0};
		while ( p1<u1Chats.chatList.size() && p2<u2Chats.chatList.size() ) {
			if (u1Chats.chatList[p1].first < u2Chats.chatList[p2].first ) {
				// meaning pointer1 is having lower counter than pointer2
				cout << u1Chats.chatList[p1].first << ": User" << u1Chats.uid << ": " << u1Chats.chatList[p1].second << '\n';	
				p1++;
			} else {
				// meaning pointer2 is having lower counter than pointer1
				cout << u2Chats.chatList[p2].first << ": User" << u2Chats.uid << ": " << u2Chats.chatList[p2].second << '\n';	
				p2++;
			}
		}
		// cout << "exited while\n";
		if ( ! (p1<u1Chats.chatList.size()) ) { // u1's chats are all done,
																				 // time to print u2's chats
			// cout << "p1 chats finished\n";	
			while ( p2<u2Chats.chatList.size() ) {
				cout << u2Chats.chatList[p2].first << ": User" << u2Chats.uid << ": " << u2Chats.chatList[p2].second << '\n';	
				p2++;
			}
		} else if ( ! (p2<u2Chats.chatList.size()) ) {  // u2's chats are finished, print u1's chats now
			// cout << "p2 chats finished\n";	
			while ( p1<u1Chats.chatList.size() ) {
				cout << u1Chats.chatList[p1].first << ": User" << u1Chats.uid << ": " << u1Chats.chatList[p1].second << '\n';	
				p1++;
			}
		}
	}
};


int main(int num, char **arr) {
	
	// ---------- get and set users ----------------
	Users u1 {"anand","an",1};
	Users u2 {"Shimla","sh",2};

	// ---------- create chat objs -----------------
	ChatsById u1Chats{u1.uid};
	ChatsById u2Chats{u2.uid};

	// ---------- record chats ------------------
	// for now, automated recording only for testing
	u1Chats.addChat(1,"namaste, kaisi ho?");
	for (int i{2};i<12;i++) {
		if (i%2==0) { //u1
		  u1Chats.addChat(i, "Hii");
		} else {  //u2
		  u2Chats.addChat(i, "Aur");
		}
	}
	u1Chats.addChat(12,"theek hai fir");


	// ----------- display -----------------------
	cout << "chats of user " << u1.uid << '\n';
	u1Chats.print();
	cout << "chats of user " << u2.uid << '\n';
	u2Chats.print();

	cout << "chats in order \n";
	u1Chats.chatsInOrder(u1Chats,u2Chats);
	

	return 0;
}
