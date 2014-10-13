#ifndef contactInfo_H
#define contactInfo_H
using namespace std;
#include <string>
// Code written by Christian Lozano

class contactInfo{
public:
	string getName() { return name; }
	string getContact() { return contact; }
	string getResidence() { return residence; }
	string getWnum() { return wnum; }
	string getNumb() { return numb; }
	contactInfo::contactInfo(){
		name = "none";
		contact = "none";
		residence = "none;";
		wnum = "none";
		numb = "none";
	}
	contactInfo::contactInfo(string xname, string xcontact, string xresidence, string xwnum, string xnumb){
		name = xname;
		contact = xcontact;
		residence = xresidence;
		wnum = xwnum;
		numb = xnumb;
	}
	contactInfo::contactInfo(const contactInfo& copp){
		name = copp.name;
		contact = copp.contact;
		residence = copp.residence;
		wnum = copp.wnum;
		numb = copp.numb;
	}
	virtual~contactInfo(void){}
	contactInfo& operator = (const contactInfo& copp){
		if (this != &copp){
			name = copp.name;
			contact = copp.contact;
			residence = copp.residence;
			wnum = copp.wnum;
			numb = copp.numb;
		}
		return *this;
	}

private:
	string name, contact, residence, wnum, numb;

};
#endif
