#include "Resource.h"

#include <cassert>
#include <iostream>
#include <vector>

int main() {
    vector<Resource> resources;
    resources.push_back(Resource("R101", "Study Room 101", "Study Room", true));
    resources.push_back(Resource("R102", "Study Room 102", "Study Room", true));
    resources.push_back(Resource("R105", "Laptop 01", "Laptop", true));

    assert(findResourceIndex(resources, "R101") == 0);
    assert(findResourceIndex(resources, "R102") == 1);
    assert(findResourceIndex(resources, "R105") == 2);
    assert(findResourceIndex(resources, "R999") == -1);

    vector<Resource> empty;
    assert(findResourceIndex(empty, "R101") == -1);

    cout << "Search tests passed." << endl;
}
