#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

class HuffmanNode {
public:
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}

    bool operator>(const HuffmanNode& other) const {
        return freq > other.freq;
    }
};

class HuffmanTree {
public:
    HuffmanTree(std::string text) {
        build(text);
    }

    ~HuffmanTree() {
        destroy(root_);
    }

    std::unordered_map<char, std::string> get_codes() {
        std::unordered_map<char, std::string> codes;
        std::string code;
        get_codes(root_, code, codes);
        return codes;
    }

private:
    HuffmanNode* root_;

    void build(std::string text) {
        std::unordered_map<char, int> freq;
        for (char c : text) {
            freq[c]++;
        }

        std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, std::greater<HuffmanNode>> nodes;
        for (const auto&
