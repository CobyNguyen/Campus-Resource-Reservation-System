#include "Resource.h"

#include <cassert>
#include <iostream>
#include <vector>

int main() {
    vector<Resource> resources;
    resources.push_back(Resource("R101", "Study Room 101", "Study Room", true));
    resources.push_back(Resource("R102", "Study Room 102", "Study Room", true));
    resources.push_back(Resource("R105", "Laptop 01", "Laptop", true));

    assert(findResourceIndex(resources, "R101") == 0);   // first item
    assert(findResourceIndex(resources, "R102") == 1);   // middle item
    assert(findResourceIndex(resources, "R105") == 2);   // last item
    assert(findResourceIndex(resources, "R999") == -1);  // not in the list

    vector<Resource> empty;
    assert(findResourceIndex(empty, "R101") == -1);      // empty list

    cout << "Search tests passed." << endl;
}
