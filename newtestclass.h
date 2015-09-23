/*
 * File:   newtestclass.h
 * Author: cm704
 *
 * Created on 14/09/2015, 10:06:42 PM
 */

#ifndef NEWTESTCLASS_H
#define	NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(insertNew);
    CPPUNIT_TEST(update);
    CPPUNIT_TEST(getComment);
    CPPUNIT_TEST(retrieveVersion);
    CPPUNIT_TEST(getVersionInfo);
    CPPUNIT_TEST(setReference);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void insertNew();
    void update();
    void getComment();
    void retrieveVersion();
    void getVersionInfo();
    void setReference();
};

#endif	/* NEWTESTCLASS_H */

