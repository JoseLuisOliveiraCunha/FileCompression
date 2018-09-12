//
// Created by jose-cunha on 11-09-2018.
//

#ifndef FILECOMPRESSION_DECODINGNODE_H
#define FILECOMPRESSION_DECODINGNODE_H

#include <string>

class DecodingNode {
private:
    bool root;
    int bit;
    DecodingNode* bit0;
    DecodingNode* bit1;
    DecodingNode* parent;

public:
    DecodingNode();
    DecodingNode(bool root, int bit);
    ~DecodingNode();
    std::string getCode();
    void setBit0(DecodingNode* bit0);
    void setBit1(DecodingNode* bit1);
    void setParent(DecodingNode* parent);
    DecodingNode* getBit0() const;
    DecodingNode* getBit1() const;

};


#endif //FILECOMPRESSION_DECODINGNODE_H
