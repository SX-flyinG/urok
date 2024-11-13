#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
	string name;
	int age;
	int countOfUsers;
public:
	User() {
		name = "Boryslav";
		age = 21;
		countOfUsers = 1;
	}

	User(string name, int age) {
		this->name = name;
		this->age = age;
	}

	void WriteUserToFile(){
		ofstream outFile("users.txt" , ios::app);
		outFile << "User : " << this->name << "\tAge : " << this->age << endl;
		outFile.close();
	
	}


};

class Group {
	User* obj;
	int countOfStudents;
	string name;
	int age;
public:
	Group() {
		countOfStudents = 1;
		obj = new User[countOfStudents];
		name = "Boryslav";
		age = 21;
	}

	Group(string name, int age , int countOfUsers) {
		this->name = name;
		this->age = age;
		this->countOfStudents = countOfStudents;
	}

	void AddUsers() {
		cout << "Write number of Students : ";
		cin >> countOfStudents;
		for (int i = 0; i < countOfStudents; i++) {
			cout << "Write name of student : ";
			cin >> name;
			cout << "Write age of student : ";
			cin >> age;
			User obj2 = User(name , age);
			obj2.WriteUserToFile();
		}
	}

	void ReadUsersFile() {
		ifstream inFile("users.txt");
		string line;
		while (getline(inFile, line)) {
			cout << line;
		}
		inFile.close();
	}

	~Group() {
		delete[]obj;
		obj = nullptr;
	}
};

int main()
{
	Group obj;
	obj.AddUsers();
	obj.ReadUsersFile();
}