/*
 * File:   newtestclass.cpp
 * Author: cm704
 *
 * Created on 14/09/2015, 10:06:43 PM
 */

#include "newtestclass.h"
#include "../filearchiver.h"
#include "../version.h"
#include <stdlib.h>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/prepared_statement.h"
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

filearchiver test;
string comment = "this is a test";
string good_file_location = "test.cpp";
string bad_file_location = "aaatttt.cpp";



newtestclass::newtestclass() {
}
newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void newtestclass::insertNew() {
    cout << "here" << endl;
    CPPUNIT_ASSERT(!test.insertNew(bad_file_location, comment));
    CPPUNIT_ASSERT(test.insertNew(good_file_location, comment));
    test.deleteall();
}

void newtestclass::update() {
    CPPUNIT_ASSERT(test.insertNew(good_file_location, comment));
    system("echo \"test\" >> test.cpp");
    CPPUNIT_ASSERT(test.update(good_file_location, comment + "1"));
    test.deleteall();
}

void newtestclass::getComment() {
    CPPUNIT_ASSERT(test.insertNew(good_file_location, comment));
    system("echo \"test\" >> test.cpp");
    CPPUNIT_ASSERT(test.update(good_file_location, comment + "1"));
    CPPUNIT_ASSERT(test.getComment(good_file_location, 0) == comment);
    CPPUNIT_ASSERT(test.getComment(good_file_location, 1) == comment + "1");
    test.deleteall();
}

void newtestclass::retrieveVersion() {
    CPPUNIT_ASSERT(test.insertNew(good_file_location, comment));
    system("echo \"test\" >> test.cpp");
    CPPUNIT_ASSERT(test.update(good_file_location, comment + "1"));
    CPPUNIT_ASSERT(!test.retrieveVersion(0,good_file_location,"0.cpp"));
    CPPUNIT_ASSERT(test.retrieveVersion(1,good_file_location,"1.cpp"));
    test.deleteall();
}

void newtestclass::getVersionInfo() {
    CPPUNIT_ASSERT(test.insertNew(good_file_location, comment));
    system("echo \"test\" >> test.cpp");
    CPPUNIT_ASSERT(test.update(good_file_location, comment + "1"));
    vector<versionRec> versiontest = test.getVersionInfo(good_file_location);
    CPPUNIT_ASSERT(versiontest.size() == 2);
}

void newtestclass::setReference() {
    CPPUNIT_ASSERT(test.insertNew(good_file_location, comment));
    system("echo \"test\" >> test.cpp");
    CPPUNIT_ASSERT(test.update(good_file_location, comment + "1"));
    CPPUNIT_ASSERT(test.setReference(good_file_location, 1, "set reference test"));
    vector<versionRec> versiontest = test.getVersionInfo(good_file_location);
    CPPUNIT_ASSERT(versiontest.size() == 1);
    test.deleteall();
}

