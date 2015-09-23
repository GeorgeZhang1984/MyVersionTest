/* 
 * File:   MurmurHash2.h
 * Author: hz740
 *
 * Created on 8 September 2015, 7:59 PM
 */

//-----------------------------------------------------------------------------
// CMurmurHash2A, by Austin Appleby

// This is a sample implementation of MurmurHash2A designed to work
// incrementally.

// Usage -

// CMurmurHash2A hasher
// hasher.Begin(seed);
// hasher.Add(data1,size1);
// hasher.Add(data2,size2);
// ...
// hasher.Add(dataN,sizeN);
// unsigned int hash = hasher.End()

#ifndef MURMURHASH2A_H
#define MURMURHASH2A_H

unsigned int MurmurHash2 ( const void * key, int len, unsigned int seed );

#endif


