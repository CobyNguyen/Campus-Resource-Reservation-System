#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

using namespace std;

class Resource {
	private:
		int resourceID;
		string resourceName;
		string resourceType;
		bool availability;
	
	public:
		Resource();
		Resource(int, string, string, bool);

		int setResourceID();
		void getResourceID(int);

		string setResourceName();
		void getResourceName(string);

		string setResourceType();
		void getResourceType(string);

		bool setAvailability();
		void getAvailability(bool);
};

#endif
