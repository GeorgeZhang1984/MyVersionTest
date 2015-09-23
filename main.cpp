#include <iostream>
#include "filearchiver.h"
#include "version.h"

int main(int argc, char *argv[])
{
    string good_file_location = "test.cpp";
    string comment = "test test test";
    
    filearchiver test;
    
    test.insertNew("test.cpp", "this is a test");
          
    system("echo \"test\" >> test.cpp");
        
    test.update(good_file_location, comment + "1");
    cout << "get comment 0: " << test.getComment(good_file_location, 0) << endl;
    cout << "get comment 1: " << test.getComment(good_file_location, 1) << endl;
    test.retrieveVersion(0,good_file_location,"0.cpp");
    test.retrieveVersion(1,good_file_location,"1.cpp");
    vector<versionRec> versiontest = test.getVersionInfo(good_file_location);
    cout << "versiontest.size(): " << versiontest.size() << endl;
    test.setReference(good_file_location, 1, "set reference test");
    
    vector<versionRec> versiontest1 = test.getVersionInfo(good_file_location);
    cout << "versiontest1.size(): " << versiontest1.size() << endl;
     
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //return a.exec();
}
