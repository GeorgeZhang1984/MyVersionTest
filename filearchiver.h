/* 
 * File:   filearchiver.h
 * Author: hz740
 *
 * Created on 8 September 2015, 8:08 PM
 */

#ifndef FILEARCHIVER_H
#define FILEARCHIVER_H
#include "mysql_connection.h"
#include "mysql_driver.h"
#include "version.h"
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/prepared_statement.h"

#include "MurmurHash2.h"

using namespace std;

class filearchiver {
private:
    bool invalid;
    sql::Connection *dbcon;
    sql::Driver *driver;
    //calculate the hash value of a filename by using its name and last modified time
    string calhash(string);
    //Get the length of a file
    int callength(string);
    //To get the current time which's unit is seconds 
    time_t get_curr_rawtime();
    //To get the last insert id which generated by auto increment
    int get_last_insert();
    bool zip_file(string);
    bool Unzip_file(string);
public:
    //Default constructor of filearchiver object and it will try to connect to mysql database
    filearchiver();
    //Default destructor of filearchiver object and it delete the connect and driver variables
    ~filearchiver();
    //use method of comparing hash to check if there is some difference berween
    //the input file and the data in the database
    bool differs(string) throw (const char*);
    //check if the specified file has existed in the database
    bool exists(string) throw (const char*);
    //ask database the id of a filename
    int getfileid(string) throw(const char*);
    //insert a file record into database which contains the overall file records,
    //each lines data of file, user's comment and version information
    bool insertNew(string, string) throw (const char*);
    //update the record of specified file (open called after the system find that 
    //the specified file has a new version)
    bool update(string,string) throw (const char*);
    //retrieve a specified file with a specified version to a given file from database
    bool retrieveVersion(int, string, string) throw (const char*);
    //get the newest version of a specified file
    int getCurrentVersionNumber(string) throw (const char*);
    //get the hash value of the newest version of a specified file
    string getHashOfLastSaved(string) throw (const char*);
    //get the comment of one of version of a specified file
    string getComment(string, int) throw (const char*);
    //get the length and create date of all version 
    vector<versionRec> getVersionInfo(string) throw (const char*);
    //get the version id of a version
    int getVersionID(string,int);
    //choose a version and set it as original version
    bool setReference(string, int, string) throw (const char*);
    bool isOK(){return !(this->invalid);};
    //delete the connect and driver variables
    void close();
    // A test function to check if I can pass a blob to the mysql datebase.
    void insertblob(string);
    //read specified file and put the content into a vector with type of blob
    vector<blob> readfile(string);
    void deleteall();
};


#endif


