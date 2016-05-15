//
//  ConvertSequence.h
//  CompressFastaCPP
//
//  Created by Wongsapat Tangwanidgoon on 5/15/16.
//  Copyright © 2016 Wongsapat Tangwanidgoon. All rights reserved.
//

#ifndef ConvertSequence_h
#define ConvertSequence_h

class ConvertSequene {
    
    
public:
    // constructor
    /*
     fileType is type of file.
     F = FASTA
     Q = FASTAQ
     seqType is type of sequence in file.
     D = DNA
     R = RNQ
     P = Protein
     convertType is type of convert
     0 = Original sequence to Compress sequence.
     1 = Compress sequence to original sequence.
     */
    ConvertSequene(string sequence, unsigned char fileType, unsigned char seqType, bool convertType){
        seq = sequence;
    }
    
    // pure virtual function providing interface framework.
    virtual string convertToBinary();
    virtual string convertToAscii();
    virtual string convertToOriginal();
    virtual string convertSequence();
    
private:
    string seq;
    
};


#endif /* ConvertSequence_h */

