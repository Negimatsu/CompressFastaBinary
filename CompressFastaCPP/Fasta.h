//
//  Fasta.h
//  CompressFastaCPP
//
//  Created by Wongsapat Tangwanidgoon on 5/15/16.
//  Copyright © 2016 Wongsapat Tangwanidgoon. All rights reserved.
//

//Include development header file
#include "../StratgyConvertFile.h"
#include "CompressFasta.h"
#include "ExtractFasta.h"
#include "../ConvertSequence/DNASequence.h"
#include "../ConvertSequence/RNASequence.h"

//Include Standard library
#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <string>
#include <algorithm>

#ifndef Fasta_h
#define Fasta_h

class Fasta : public StratgyConvertFile {
    virtual void compress();
    virtual void extract();
    
public:
    <#member functions#>
};

#endif /* Fasta_h */


