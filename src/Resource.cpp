#include "Resource.h"

using namespace std;

public resource() {
	resourceID = -1;
	resourceName = "none";
	resourceType = "none";
	availability = false;
}

public resource(int resourceID, string resourceName, string resourceType, bool availability) {
	this.resourceID = resourceID;
	this.resourceName = resourceName;
	this.resourceType = resourceType;
	this.availability = availability;
}


int setResourceID() {
	return this.resourceID;
}

void getResourceID(int resourceID) {
	this.resourceID = resourceID;
}


string setResourceName() {
	return this.resourceName;
}

void getResourceName(string resourceName) {
	this.resourceName = resourceName;
}


string setResourceType() {
	return this.resourceType;
}

void getResourceType(string resourceType) {
	this.resourceType = resourceType;
}


bool setAvailability() {
	return this.availability;
}

void getAvailability(bool availability) {
	this.availability = availability;
}
