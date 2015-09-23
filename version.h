/* 
 * File:   version.h
 * Author: hz740
 *
 * Created on 8 September 2015, 7:59 PM
 */

#ifndef VERSION_H
#define VERSION_H
#include <iostream>
using namespace std;

struct blob{
    int line_num;
    string data;
    string blob_hash;
};

class versionRec {
private:
    string version_id;
    int version_num;
    int length;
    int version_hash;
    string date;
    blob* blobs;
public:
    versionRec();
    ~versionRec();
    void getinfo();
    void setinfo();
    string getversionid();
    void setversionid(string);
    int getversionnum();
    void setversionnum(int);
    int getlength();
    void setlength(int);
    int gethash();
    void sethash(int);
    blob* getblobs();
    void setblobs(blob*);
    void setdate(string);
    string getdate();
};

#endif



