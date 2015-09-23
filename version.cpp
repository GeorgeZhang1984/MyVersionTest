#include "version.h"

versionRec::versionRec(){

}

versionRec::~versionRec(){

}

void versionRec::getinfo(){

}

void versionRec::setinfo(){

}

string versionRec::getversionid(){
    return version_id;
}

void versionRec::setversionid(string a){
    version_id = a;
}

int versionRec::getversionnum(){
    return version_num;
}

void versionRec::setversionnum(int a){
    version_num = a;
}

int versionRec::getlength(){
    return length;
}

void versionRec::setlength(int a){
    length = a;
}

int versionRec::gethash(){
    return version_hash;
}

void versionRec::sethash(int a){
    version_hash = a;
}

blob* versionRec::getblobs(){
    return blobs;
}

void versionRec::setblobs(blob* a){
    blobs = a;
}

string versionRec::getdate(){
    return date;
}

void versionRec::setdate(string a){
    date = a;
}




