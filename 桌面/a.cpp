#include <vector>  
#include <string>  
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <iterator>
#include <memory>
#include <set>
#include <map>

using namespace std;

class Parent {
    public:
    	Parent(int parentMem = 0): parentMem(parentMem){}
    	
        virtual void foo() {
            std::cout << "Parent member is: " << parentMem << std::endl;
        };
    
    private:
    	int parentMem;
};

class Child : public Parent {
    public:
    	Child(int parentMem, int childMem):childMem(childMem){
    		Parent(parentMem);
    	}
    	
        virtual void foo() override {
            Parent::foo();
            std::cout << "Child member is: " << childMem << std::endl;
        };
        
    private:
    	int childMem;
};

void fun()
{
    Child childInstance(1,2);
    childInstance.foo();
}
/*
class A;
class A {
	private:
		int setID;
		int intrasetID;
	public:
		A(int _setID, int _intrasetID):setID(_setID), intrasetID(_intrasetID){}
		int getSetID()const{return setID; }
		int getIntrasetID()const{return intrasetID;}
		bool operator<(const A& rhs) const {
			return (this->setID < rhs.setID) || (this->setID == rhs.setID && this->intrasetID < rhs.intrasetID);
		}
};

inline bool comp(const A* lhs, const A* rhs) {return *lhs < *rhs;}

void fun() {
	//auto compare = [](auto lhs, auto rhs){return *lhs < *rhs;};
	set<A*, decltype(comp)*> setOfInt(comp);
	A a(0, 3);
	A b(0, 2);
	A c(1, 1);
	A d(0, 1);
	setOfInt.insert(&a);
	setOfInt.insert(&b);
	setOfInt.insert(&c);
	setOfInt.insert(&d);
	for_each(setOfInt.begin(), setOfInt.end(), [](auto element){cout << "Set ID:" << element->getSetID() << endl 
																<< "Intraset ID: " << element->getIntrasetID() << endl; });
}
*/
/*
void fun() {
	vector<int> vec(3, 1);
	auto it = vec.begin();
	it = vec.erase(vec.end() - 1);
	cout << *it << " ";
	for_each(vec.begin(), vec.end(), [](auto a){cout << a << " ";});
}
*/
/*
class A {
	public:
		virtual const A& f1(int default_arg = 1)const{cout << "A's f1's default argument is " << default_arg << endl; return *this;}
		virtual ~A(){}
};

class B: public A{
	public:
		const B& f1(int default_arg = 2)const override final{cout << "B's f1's default argument is " << default_arg << endl; return *this;}
		~B(){}
};

class C: public A{
	public:
		const C& f1(int default_arg = 3)const override{cout << "C's f1's default argument is " << default_arg << endl; return *this;}
		~C(){}
};

void fun() {
	B b;
	C c;
	A& a = b;
	A& _a = c;
	//B& _b = c;
	a.f1();
	b.f1();
	_a.f1();
	int num = 3;
	vector<int*> v;
	v.push_back(&num);
	*(v.at(0)) = 1;
	cout << "num's value is " << num << endl;
}
*/
/*
void fun() {
	unique_ptr<int> ptr = make_unique<int>(5);
	int* raw_ptr = &(*ptr);
	cout << "The value that raw_ptr points is " << raw_ptr << endl;
	cout << "The value that unique_ptr points is " << &(*ptr) << endl;
	ptr.reset();
	if(ptr == nullptr)
		cout << "ptr has been delete" << endl;
	else
		cout << "ptr has not been delete" << endl;
	
	if(raw_ptr == nullptr)
		cout << "raw_ptr becomes nullptr after deleting the unique_ptr" << endl;
	else
		cout << "raw_ptr is not nullptr" << endl;
}
*/
/*
void fun() {
	vector<string> vec;
	set<string> c = {"violet Evergarden", "darling in the Franxx"};
	cout << "Please enter the number of string you need: ";
	unsigned int sz;
	cin >> sz;
	cin.get();
	string temp;
	for (unsigned int i = 0; i < sz; ++i) {
		getline(cin, temp);
		vec.push_back(temp);
	}
	copy(vec.begin(), vec.end(), inserter(c, c.end()));
	
	 * this command is invaild, because associative containers do not support
	 * push_back and push_front functions. But back_inserter will call push_back
	 * function when it is assigned.
	 */
	//copy(vec.begin(), vec.end(), back_inserter(c));
	/*
	for(const auto &setIt: c)
		cout << setIt << endl;
	map<int, int> mp({1,1});
	mp.insert({2, 2});
	auto it = mp.begin();
	cout << it->first << " " << it->second << endl;
}
*/
/*
void fun() {
	allocator<string> alloc;
	int n;
	cout << "The number of strings you need: ";
	cin >> n;
	string* const ptr = alloc.allocate(n);
	cout << "Please enter the strings: " << endl;
	for(auto q = ptr; q != ptr + n; ++q){
		string temp;
		cin >> temp;
		alloc.construct(q, temp);
	}
	cout << "These are the strings you have entered: " << endl;
	for(auto q = ptr; q != ptr + n; ++q)
		cout << *q << endl;
	for(auto q = ptr; q != ptr + n; ++q)
		alloc.destroy(q);
	alloc.deallocate(ptr, n);
}
*/
//this function will result in double free problem
/*
void fun() {
	shared_ptr<int> ptr = make_shared<int>(42);
	weak_ptr<int> ptr2(shared_ptr<int>(ptr.get()));
	cout << "Ptr user count: " << ptr.use_count() << endl;
	cout << "Where ptr points: " << ptr.get() << endl;
	cout << "Ptr user count: " << ptr2.use_count() << endl;
	if(ptr2.lock())
		cout << "Where ptr points: " << ptr2.lock().get() << endl;
	else
		cout << "Null Pointer" << endl;	
}
*/
/*
void fun() {
	cout << "Please enter as many intergers as you want" <<	endl;
	istream_iterator<int> in_iter(cin), eof;
	vector<int> intVec(in_iter, eof);
	cout << "The size of the vector is: " << intVec.size() << endl;
	istream_iterator<string> str_in_iter(cin), str_eof;
	cout << "Please enter as many strings as you want" << endl;
	vector<string> strVec(str_in_iter, str_eof);
	cout << "The size of the vector is: " << strVec.size() << endl;
}
*/
/*
void print(ostream &os, const string & s, char delimitor) {
	os << s << delimitor;
}
void fun() {
	vector<string> vec;
	auto insertIt = back_inserter(vec);
	cout << "Please enter the number of string you want to have: ";
	int num;
	cin >> num;
	cin.get();
	for (int i = 0; i < num; ++i)
	{
		string temp;
		getline(cin, temp);
		*insertIt = temp;
	}
	cout << "Please enter which delimitor you want to use: ";
	char c;
	cin >> c;
	cout << "These are the strings you enter(lambda version)" << endl;
	for_each(vec.begin(), vec.end(), [c](const string &s) {cout << s << c; });
	cout << endl;
	cout << "These are the strings you enter(bind version)" << endl;
	for_each(vec.begin(), vec.end(), bind(print, ref(cout), placeholders::_1, c));
	cout << endl;
}
*/
/*
bool check_size(string &s, unsigned int sz) {
	return s.size() > sz;
}  

void fun() {
	cout << "Please enter a string" << endl;
	string s;
	getline(cin, s);
	auto check10 = bind(check_size,placeholders:: _1, 10);
	if(check10(s))
		cout << "This string has more than 10 character\n";
	else
		cout << "This string has less than or equal to 10 character\n";
}
*/
/*
struct President  
{  
    std::string name;  
    std::string country;  
    int year;  
	
	President()=default;
	
    President(std::string p_name, std::string p_country, int p_year)  
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)  
    {  
        std::cout << "I am being constructed.\n";  
    }
    President(const President& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        std::cout << "I am being copy constructed.\n";
    }
    President(President&& other)  noexcept
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)  
    {  
        std::cout << "I am being moved.\n";  
    }  
    President& operator=(const President& other);  
}; 

President f() {
	return President();
}

void fun()  
{  
    std::vector<President> elections;  
    std::cout << "emplace_back:\n";  
    elections.emplace_back("Nelson Mandela", "South Africa", 1994); //没有类的创建  

    std::vector<President> reElections;  
    std::cout << "\npush_back:\n";
    President temp("Franklin Delano Roosevelt", "the USA", 1936);
    reElections.push_back(std::move(temp));  

    std::cout << "\nContents:\n";  
    for (President const& president: elections) {  
       std::cout << president.name << " was elected president of "  
            << president.country << " in " << president.year << ".\n";  
    }  
    for (President const& president: reElections) {  
        std::cout << president.name << " was re-elected president of "  
            << president.country << " in " << president.year << ".\n";  
    }
    
    elections.push_back(reElections.at(0));
    cout << "Capacity: " << elections.capacity() << endl;
    
    President s = f();
}
*/
int main() {
	fun();
}




