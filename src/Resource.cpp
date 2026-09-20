#include <string>
#include "../include/Resource.h"

using namespace std;

//Constructors
Resource::Resource() {
	resourceID = "";
	resourceName = "";
	resourceType = "";
	availability = false;
}

Resource::Resource(string resourceIDNew, string resourceNameNew, string resourceTypeNew, bool availabilityNew) {
	this->resourceID = resourceIDNew;
	this->resourceName = resourceNameNew;
	this->resourceType = resourceTypeNew;
	this->availability = availabilityNew;
}

//Setters and getters
string Resource::getResourceID() {
	return this->resourceID;
}

void Resource::setResourceID(string resourceID) {
	this->resourceID = resourceID;
}


string Resource::getResourceName() {
	return this->resourceName;
}

void Resource::setResourceName(string resourceName) {
	this->resourceName = resourceName;
}


string Resource::getResourceType() {
	return this->resourceType;
}

void Resource::setResourceType(string resourceType) {
	this->resourceType = resourceType;
}


bool Resource::getAvailability() {
	return this->availability;
}

void Resource::setAvailability(bool availability) {
	this->availability = availability;
}