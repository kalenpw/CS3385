#include <sstream>
#include <algorithm>

#include "./huffman.h"

// TODO: implement
void getCodewords(Node* root, string codewords[]) {
}

// TODO: implement
Node* buildBinaryTree(const int* freq) {
  return NULL;
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
  return "";

  // TODO: Count the frequencies of the characters


  // TODO: Get the codewords for the used characters.

  // Write the header.
  // std::stringstream ss;
  // ss << getHeader(freq);
  
  // TODO: Iterate through the data and write the corresponding
  // codeword for each character to the bit buffer. See comments
  // at the top of bit_buffer for usage instructions.
  // bit_buffer buf;

  // Write the data portion
  // string compressed = ss.str();
  // std::stringstream ss2;
  // ss2 << buf;
  // compressed += ss2.str();
  // return compressed;
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

  // TODO: build the binary tree

  bit_buffer buf(ss);
  std::stringstream out;
  // TODO: Use the binary tree to get the characters back from the buffer.
  // Note that you should use the binary tree itself and not the
  // codewords to decompress the data.
  // Once you find the next character, add it to the output stream as
  //   out << c;

  return out.str();
}

