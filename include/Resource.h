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
		
		string getResourceID() const;
		void setResourceID(string);

		string getResourceName() const;
		void setResourceName(string);

		string getResourceType() const;
		void setResourceType(string);

		bool getAvailability() const;
		void setAvailability(bool);

		void print();
};

#endif
