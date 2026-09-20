#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

using namespace std;

class Resource {
	private:
		string resourceID;
		string resourceName;
		string resourceType;
		bool availability;
	
	public:
		Resource();
		Resource(string, string, string, bool);
		
		string getResourceID();
		void setResourceID(string);

		string getResourceName();
		void setResourceName(string);

		string getResourceType();
		void setResourceType(string);

		bool getAvailability();
		void setAvailability(bool);

		void print();
};

#endif
