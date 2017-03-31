#include <sstream>
#include <algorithm>
#include "./huffman.h"

void getCodeWordsImpl(Node* root, string codewords[], string str){
    if(!root){
        return;
    }

    if(root->data()){
        codewords[root->data()] = str;
    }

    getCodeWordsImpl(root->right(), codewords, str+"1");
    getCodeWordsImpl(root->left(), codewords, str+"0"); 
}

void getCodewords(Node* root, string codewords[]) {
    getCodeWordsImpl(root, codewords, ""); 
}


// TODO: implement
Node* buildBinaryTree(const int* freq) {      
    //Keyed on frequency
    priority_queue<Node*, vector<Node*>, NodeComp> pQueue;

    //Fill priority queue
    for(int i = 0; i < 256; i++){
        if(freq[i] != 0){
            pQueue.push(new Node(freq[i], i));
        }
    }

    while(pQueue.size() > 1){
        Node* newNodeZ = new Node(0, 0);
        Node* tempLeft;
        Node* tempRight;

        tempLeft = pQueue.top();
        newNodeZ->setLeft(pQueue.top());
        pQueue.pop();

        tempRight = pQueue.top();
        newNodeZ->setRight(pQueue.top());
        pQueue.pop();

        
        //Parent node
        int xFreq = newNodeZ->left()->key();
        int yFreq = newNodeZ->right()->key();
       
        newNodeZ->setKey(xFreq + yFreq);
        pQueue.push(newNodeZ);
    }

    return pQueue.top();
}

// TODO: implement
// Tested and appears to be working
void countFrequencies(const string& data, int* freq) {
    for(int i = 0; i < data.length(); i++){
        freq[data[i]]++;
    }
}

string getHeader(int* freq) {
    std::stringstream ss;
    int numChars = 0;
    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) numChars++;
    }
    ss << numChars << std::endl;
    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            ss << i << " " << freq[i] << std::endl;
        }
    }
    return ss.str();
}

string compressData(const string& data) {

    // TODO: Count the frequencies of the characters
    int freq[256];
    countFrequencies(data, freq);
    // TODO: Get the codewords for the used characters.
    Node* tree = buildBinaryTree(freq);
    string codewords[256];
    getCodewords(tree, codewords);

    // Write the header.
    std::stringstream ss;
    ss << getHeader(freq);
    
    // TODO: Iterate through the data and write the corresponding
    // codeword for each character to the bit buffer. See comments
    // at the top of bit_buffer for usage instructions.
    bit_buffer buf;

    for(int i = 0; i < data.size(); i++){
        string code = codewords[data[i]];
        for(int j = 0; j < code.size(); j++){
            if(code[j] == '0'){
                buf.add(0);
            }
            else{
                buf.add(1);
            }
        }
    }

    // Write the data portion
    string compressed = ss.str();
    std::stringstream ss2;
    ss2 << buf;
    compressed += ss2.str();
    return compressed;
}

string uncompressData(const string& data) {
    // Read frequencies from the header
    std::stringstream ss(data);
    int count;
    ss >> count;
    int freq[256];
    std::fill(freq, freq+256, 0);
    for (int i = 0; i < count; ++i) {
        int c;
        int f;
        ss >> c >> f;
        freq[c] = f;
    }
    Node* tree = buildBinaryTree(freq);

    // Write the header.
    //std::stringstream ss;
    ss << getHeader(freq);
    
    bit_buffer buf(ss);
    std::stringstream out;
    // TODO: Use the binary tree to get the characters back from the buffer.
    // Note that you should use the binary tree itself and not the
    // codewords to decompress the data.
    // Once you find the next character, add it to the output stream as
    //   out << c;
    Node* currentNode;
    currentNode = tree; 
    for(int i = 0; i < data.size(); i++){
        if(currentNode->data() == NULL){

        }
    }

    
//    return "1";
    return out.str();
}

