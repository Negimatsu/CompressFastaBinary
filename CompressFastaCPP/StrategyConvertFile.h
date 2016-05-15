//
//  StrategyConvertFile.h
//  CompressFastaCPP
//
//  Created by Wongsapat Tangwanidgoon on 5/15/16.
//  Copyright © 2016 Wongsapat Tangwanidgoon. All rights reserved.
//

#ifndef StrategyConvertFile_h
#define StrategyConvertFile_h
class StrategyConvertFile {
    
    
public:
    //Constructor
    StrategyConvertFile(string filename, string pathfile){
        fileName = filename;
        pathFile = pathFile;
    }
    
    virtual void compress();
    virtual void extract();
    
protected:
    string fileName;
    string pathFile;
    
};

#endif /* StrategyConvertFile_h */

