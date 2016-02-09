#include <iostream>

using namespace std;

class Base{
	private:
		int baseprivatenumber;
	protected:
		int baseprotectednumber;

	public:
		int basepublicnumber;
		Base () {
			std::cout << "Base called" << endl ;
		}

		void setbasenumber(int basenumber , int privatenumber,int protectednumber) ;
		void getbasenumber() { 
			std::cout << " base number " << basepublicnumber << endl;
		}
};


void Base::setbasenumber(int basenumber,int privatenumber,int protectednumber)
{
	basepublicnumber = basenumber;
	baseprivatenumber = privatenumber;
	baseprotectednumber = protectednumber;

}


class Derived : public Base {

	int derivednumber;

	public:
	Derived(int basenumber,int privatenumber,int protectednumber) {
	setbasenumber(basenumber,privatenumber,protectednumber);
		std::cout << "Derived " << endl ; 
	}

	void setderivednumber (int number) ;
	void getderivednumber() { std::cout << "derived number " << derivednumber << endl ; }
	int baseplusderived() {
		std::cout << "b+d : " << derivednumber + basepublicnumber << endl ;
		return (derivednumber + basepublicnumber); 
	}
	void display () {
	cout << " Base derived as Public " << "basepublic: " << basepublicnumber << "baseprotected :" << baseprotectednumber << endl;
	}
};

void Derived::setderivednumber(int number)
{
	derivednumber = number;
}

class DerivedOne : private Base {

	int derivednumber;

	public:
	DerivedOne(int basenumber,int privatenumber,int protectednumber) {
	setbasenumber(basenumber,privatenumber,protectednumber);
	}
	void setderivednumber (int number) ;
	void getderivednumber() { std::cout << "derived number " << derivednumber << endl ; }
	void display() {
	cout << "Base derived as private " << "basepublic:" << basepublicnumber << "baseprotected:" << baseprotectednumber << endl;
	}
};

void DerivedOne::setderivednumber(int number)
{
	derivednumber = number;
}

class DerivedTwo : protected Base {

	int derivednumber;

	public:
	DerivedTwo(int basenumber,int privatenumber,int protectednumber) {
	setbasenumber(basenumber,privatenumber,protectednumber);
	}
	void setderivednumber (int number) ;
	void getderivednumber() { std::cout << "derived number " << derivednumber << endl ; }
	void display() {
	cout << "Base derived as protected: " << "basepublic :" << basepublicnumber <<  "baseprotected:" << baseprotectednumber << endl ; 
	}
};

void DerivedTwo::setderivednumber(int number)
{
	derivednumber = number;
}

int main()
{
	Base base;
	Derived derived(7,88,99);
	DerivedOne derivedone(7,88,99);
	DerivedTwo derivedtwo(7,88,99);

	derived.getbasenumber();
	derived.setderivednumber(10);
	derived.getderivednumber();
	std::cout << derived.baseplusderived() << endl;

	derived.display();
	derivedone.display();
	derivedtwo.display();

}
