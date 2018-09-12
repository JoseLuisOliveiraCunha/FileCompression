//
// Created by jose-cunha on 11-09-2018.
//

#include "DecodingNode.h"
#include <algorithm>

DecodingNode::DecodingNode() = default;

DecodingNode::DecodingNode(bool root, int bit) {
    this->root = root;
    this->bit = bit;
}

DecodingNode::~DecodingNode() = default;

std::string DecodingNode::getCode() {
    std::string ret = std::to_string(bit);
    DecodingNode* ancestor = parent;
    while(!ancestor->root){
        ret += std::to_string(ancestor->bit);
        ancestor = ancestor->parent;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void DecodingNode::setBit0(DecodingNode* bit0) {
    this->bit0 = bit0;
}

void DecodingNode::setBit1(DecodingNode* bit1) {
    this->bit1 = bit1;
}

void DecodingNode::setParent(DecodingNode* parent) {
    this->parent = parent;
}

DecodingNode* DecodingNode::getBit0() const {
    return bit0;
}

DecodingNode* DecodingNode::getBit1() const {
    return bit1;
}
