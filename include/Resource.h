#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <vector>

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

// Returns the index of the resource, or -1 if not found
int findResourceIndex(vector<Resource>& resources, const string& resourceID);

#endif
