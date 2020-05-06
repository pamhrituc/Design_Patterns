// GalaxyNotes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>
#include "DateTime.h"
#include "StarList.h"
#include "StarListFactory.h"
#include "StarListIterator.h"
#include "Tests.h"
#include "UI.h"

using namespace std;

int main() {
	runTests();
	ui();
	return 0;
}