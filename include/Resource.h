//Resources may include:

//Study Rooms
//Laptops
//Calculators
//Lab Equipment
//Tutoring appointments
//Each resource must contain:

//Resource ID
//Resource Name
//Resource Type
//Availability Status

#ifdef RESOURCE_H
#define RESOURCE_H

using namespace std;

#include <string>

public class resource {
	private{
		int resourceID;
		string resourceName;
		string resourceType;
		bool availability;
	}
	public{
		public resource();
		public resource(int, string, string, bool);

		int setResourceID();
		void getResourceID(int);

		string setResourceName();
		void getResourceName(string);

		string setResourceType();
		void getResourceType(string);

		bool setAvailability();
		void getAvailability(bool);
	}
}

#endif
