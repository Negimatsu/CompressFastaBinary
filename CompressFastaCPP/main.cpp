//
//  main.cpp
//  CompressFastaCPP
//
//  Created by Wongsapat Tangwanidgoon on 2/7/16.
//  Copyright © 2016 Wongsapat Tangwanidgoon. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <string>
#include <algorithm>


const int DIV_SEQ = 6;

int is_dsc(std::string data){
    if (data[0] == '>'){
        return 1;
    }
    
    return 0;
}

std::string convert_binary(char data){
    //char convert_value[2];
    std::string convert_value;
    std::cout << data;
    
    if (data == 'A' || data == 'a'){
        convert_value = "00";
    }else if (data == 'T' || data == 't'){
        convert_value = "01";
    }else if (data == 'C' || data == 'c'){
        convert_value = "10";
    }else if (data == 'G' || data == 'g'){
        convert_value = "11";
    }else{
        convert_value = "";
    }

    return convert_value;
}

std::string convert_seq(std::string seq){
    std::string str = seq;
    std::string result = "";
    
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    
    for(int i = 0; i < seq.size(); ++i) {
        result += convert_binary(seq[i]);
    }

    //std::cout << result;
    return result;
}

int calculate_add_char(std::string seq){
    int addChar = DIV_SEQ - seq.length()%DIV_SEQ;
    if (seq.length()%(DIV_SEQ/2) == 0){
        addChar = 0;
    }
    
    return addChar;
}


std::string add_head_char(std::string seq){
    
    int addChar = calculate_add_char(seq);
    
    std::string headSeqString = "" ;
    
    for (int i = 0; i < addChar; i++){
        headSeqString += "0";
    }
    
    return headSeqString;
}

std::string convert_seq_ascii(std::string seq){

    seq = add_head_char(seq) + seq;
    std::cout << seq;
    
    std::stringstream sstream(seq);
    std::string output;
    
    while(sstream.good())
    {
        std::bitset<6> bits;
        sstream >> bits;
        
        //std::cout << bits;
        
        unsigned char c = char(bits.to_ulong() + 20);
//        std::cout << bits.to_ulong();
        
        output += c;
        //std::cout << "x";
    }

    return output;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    //FILE *fp;
    // insert code here...
    printf("Hello, World!\n");

    
    std::ifstream infile("/Users/Ongkrab/Documents/Toy Project/FastaCompress/Example Fasta.txt");
    
    /* elapsed.dta is the name of the file */
    /* "rt" means open the file for reading text */
    
    //fp = fopen("/Users/Ongkrab/Documents/Toy Project/FastaCompress/test.txt", "w+");
    std::ofstream out("/Users/Ongkrab/Documents/Toy Project/FastaCompress/EncodeSeq.txt");
    
    int flag = 0;
    std::string  seq_partial = "";
    std::string  header = "";
    std::string line;
    while (std::getline(infile, line))
    {
        /* get a line, up to 80 chars from fr.  done if NULL */
        //std::cout << line;
        
        if(is_dsc(line) == 1 && flag == 0){
            header = line;
            flag = 2;
        }
        
        if (is_dsc(line) == 1 && flag == 1){
            header = line;
            flag = 2;
        }else if (flag == 2 && is_dsc(line) == 0){
            seq_partial += line;
            flag = 2;
        }
        
        if(is_dsc(line) == 1 && header != "" && seq_partial != ""){

            flag = 3;
        }

        if(flag == 3){ //end of sequence
            printf("%s\n\n", header.c_str());
            std::string sequence_binary = convert_seq(seq_partial);
            std::string output = convert_seq_ascii(sequence_binary);
            
            //printf("%s\n", sequence_binary.c_str());
            //fput(header, fp);
            
            out << header + "\n";
            std::string prefix = "+" + std::to_string(calculate_add_char(sequence_binary));
            out <<  prefix + output + "\n";
            flag = 2;
            
            seq_partial = "";
            header = line;
        }
        
        
    }
    
    if(flag == 2){ //end of sequence
         printf("%s\n\n", header.c_str());
        std::string sequence_binary = convert_seq(seq_partial);
        std::string output = convert_seq_ascii(sequence_binary);
        
        
        //printf("%s\n", sequence_binary.c_str());
        //fput(header, fp);
        
        out << header + "\n";
        std::string prefix = "+" + std::to_string(calculate_add_char(sequence_binary));
        out <<  prefix + output + "\n";
        flag = 1;
        
        seq_partial = "";
        header = line;
    }
    
    

    return 0;
}






