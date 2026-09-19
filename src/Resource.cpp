#include <string>
#include "../include/Resource.h"

using namespace std;

Resource::Resource() {
	resourceID = -1;
	resourceName = "none";
	resourceType = "none";
	availability = false;
}

Resource::Resource(int resourceID, string resourceName, string resourceType, bool availability) {
	this->resourceID = resourceID;
	this->resourceName = resourceName;
	this->resourceType = resourceType;
	this->availability = availability;
}


int Resource::setResourceID() {
	return this->resourceID;
}

void Resource::getResourceID(int resourceID) {
	this->resourceID = resourceID;
}


string Resource::setResourceName() {
	return this->resourceName;
}

void Resource::getResourceName(string resourceName) {
	this->resourceName = resourceName;
}


string Resource::setResourceType() {
	return this->resourceType;
}

void Resource::getResourceType(string resourceType) {
	this->resourceType = resourceType;
}


bool Resource::setAvailability() {
	return this->availability;
}

void Resource::getAvailability(bool availability) {
	this->availability = availability;
}
