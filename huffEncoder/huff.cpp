/**
 * @file huff.cpp
 * @brief Huffman's encoder implementation.
 * 
 * This file contains the implementation of Huffman's encoder,
 * which is used for compressing data using Huffman coding algorithm.
 * 
 * @note The file path is /d:/pro/cpp/Crash Course/huffEncoder/huff.cpp
 */
//huffman's encoder, built using help from AI assistant (github copilot)

#include <string>
using namespace std;

/*
string huffmanEncoder(string message)
{

}*/
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

/// @brief 
/// @param root 
/// @param str 
/// @param huffmanCode 
void buildHuffmanTree(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    buildHuffmanTree(root->left, str + "0", huffmanCode);
    buildHuffmanTree(root->right, str + "1", huffmanCode);
}

string huffmanEncoder(string message) {
    unordered_map<char, int> freq;
    for (char ch : message) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        int sum = left->freq + right->freq;
        Node *node = new Node('\0', sum);
        node->left = left;
        node->right = right;
        pq.push(node);
    }

    Node* root = pq.top();
    unordered_map<char, string> huffmanCode;
    buildHuffmanTree(root, "", huffmanCode);
    cout<<"Huffman Codes are:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }

    string encodedString = "";
    for (char ch : message) {
        encodedString += huffmanCode[ch];
    }

    return encodedString;
}

int main(){
    string message = "Huffman coding is a data compression algorithm.";
    string encodedString = huffmanEncoder(message);
    cout << "Encoded String: " << encodedString << endl;

    return 0;
}