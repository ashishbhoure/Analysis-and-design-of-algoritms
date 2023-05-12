/*Ques: Implement the Huffman coding algorithm to compress a given string in Cpp*/

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// A Huffman tree node
struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Custom comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Build the Huffman tree and return the root node
Node* buildHuffmanTree(string str) {
    unordered_map<char, int> freqMap;
    for (char c : str) {
        freqMap[c]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto it = freqMap.begin(); it != freqMap.end(); it++) {
        pq.push(new Node(it->first, it->second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    return pq.top();
}

// Traverse the Huffman tree and generate codes for each character
void generateCodes(Node* root, string code, unordered_map<char, string>& codesMap) {
    if (root == nullptr) {
        return;
    }

    if (root->data != '$') {
        codesMap[root->data] = code;
    }

    generateCodes(root->left, code + "0", codesMap);
    generateCodes(root->right, code + "1", codesMap);
}

// Compress the input string using the Huffman codes
string compress(string str, unordered_map<char, string>& codesMap) {
    string compressedStr = "";
    for (char c : str) {
        compressedStr += codesMap[c];
    }
    return compressedStr;
}

// Driver function to compress a given string
string huffmanEncoding(string str) {
    Node* root = buildHuffmanTree(str);
    unordered_map<char, string> codesMap;
    generateCodes(root, "", codesMap);
    return compress(str, codesMap);
}

int main() {
    string str = "hello world";
    string compressedStr = huffmanEncoding(str);
    cout << "Compressed string: " << compressedStr << endl;
    return 0;
}

//Time complexity 
/*The time complexity of the Huffman coding algorithm is O(n log n) for building the Huffman tree and generating the codes, where n is the length of the input string. The space complexity is O(k), where k is the number of unique characters in the input string. In comparison, the time complexity of a brute-force approach for compressing a string would be O(2^n), where n is the length of the input string, as we would need to generate all possible combinations of binary codes for each character.*/