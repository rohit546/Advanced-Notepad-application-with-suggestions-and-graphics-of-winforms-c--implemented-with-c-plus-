#include<stdlib.h>
#include<string>
#include<iostream>
#include"priorityQ.h"
#include<fstream>
using namespace std;


// class for storing codes 
class codes {

public:
    char ch[28];
    string str[28];
    string decoded;
    int i;
};


//huffman node 
class huffNode
{
public:
    char ch;
    int freq;
    int edge;
    huffNode* left, * right;

    huffNode() {
        left = right = NULL;
        edge = NULL;
        freq = NULL;
        ch = NULL;
    }
};


//huffman tree node 
class huffmtree {
public:
    huffNode* huffroot;// root 
    PriorityQ Pq;
    PriorityQ useful;
    codes code;

    huffmtree() {
        huffroot = NULL;
    }

    void insertfunc(huffNode* N, char data, int freq, int ed) {
        // N = new huffNode();
        N->ch = data;
        N->freq = freq;
        N->edge = ed;
    }
    // building tree from given string 
    void buildQtree(){


        if (Pq.count < 3)
            return;
        while (Pq.front != NULL)
        {

            if (huffroot == NULL) {// if root is null then poping first two vaules from queue and inserting into tree

                Pnode* temp = Pq.peek();

                char data = temp->info;
                int freq = temp->freq;
                Pq.del();
                temp = Pq.peek();

                char data2 = temp->info;
                int freq2 = temp->freq;
                Pq.del();
                huffroot = new huffNode;
                huffroot->ch = '0';
                huffroot->freq = freq + freq2;// sum of frequencies 
                huffroot->left = new huffNode;
                huffroot->right = new huffNode;

                if (data <= data2) {

                    insertfunc(huffroot->left, data2, freq2, 0);
                    insertfunc(huffroot->right, data, freq, 1);

                }
                else {
                    insertfunc(huffroot->left, data, freq, 0);
                    insertfunc(huffroot->right, data2, freq2, 1);

                }


            }


            //  Pq.peek();

            //if inserting after tree 

            huffNode* huff = new huffNode;
            huff->freq = Pq.peek()->freq + huffroot->freq;
            huff->ch = '0';



            if (Pq.peek()->freq <= huffroot->freq) {
                huff->left = new huffNode;
                insertfunc(huff->left, Pq.peek()->info, Pq.peek()->freq, 0);
                huff->right = huffroot;
                huffroot = huff;
                if (huffroot->left != NULL)
                    huffroot->left->edge = 0;
                if (huffroot->right != NULL)
                    huffroot->right->edge = 1;

            }
            else {
                huff->right = new huffNode;
                insertfunc(huff->right, Pq.peek()->info, Pq.peek()->freq, 1);
                huff->left = huffroot;
                huffroot = huff;

                if (huffroot->left != NULL)
                    huffroot->left->edge = 0;
                if (huffroot->right != NULL)
                    huffroot->right->edge = 1;

            }
            Pq.del();
        }

        Pq.del();


    }
    void buildtree(string str) {


        Pq.FindFreq(str);
        useful.FindFreq(str);
      
        buildQtree();
    }

    codes getCodes() {

        return code;

        int i = 0;
    }

    PriorityQ get_tree() {
        return useful;
    }

    //encoding of 
    void encode(huffNode* root, string str)
    {
        if (root == nullptr)
            return;

        // found a leaf node
        if (!root->left && !root->right) {


            if (root != NULL) {

                // for handling space 
                if (root->ch == ' ')
                {
                    code.ch[26] = root->ch;
                    code.str[26] = str;
                }
                //for handling endline
                else if (root->ch == '\n')
                {
                    code.ch[27] = root->ch;
                    code.str[27] = str;
                }
                else {
                    code.i = root->ch - 'a';
                    code.ch[code.i] = root->ch;// storing codes in code class 
                    code.str[code.i] = str;
                }

            }
        }

        encode(root->left, str + "0");
        encode(root->right, str + "1");
    }


    // decoding of encoded string
    void decode(huffNode* root, int& index, string str)
    {
        if (root == nullptr) {
            return;
        }

        // found a leaf node
        if (!root->left && !root->right)
        {
            code.decoded += root->ch;
            return;
        }

        index++;
    
        if (str[index] == '0')
            decode(root->left, index, str);
       else
            decode(root->right, index, str);
    }

    //getter for decoded string 
    string get_decoded_string(string encoded) {


        int index = -1;
        while (index < (int)encoded.size() - 2) {
            decode(huffroot, index, encoded);
        }

        return code.decoded;
    }

    //getter for encoded string 
    string get_encoded_string(string str) {

        encode(huffroot, "");

        string encoded = "";
        for (int i = 0; i < str.size(); i++) {

            if (str[i] == ' ')
                encoded += code.str[26];

            else if (str[i] == '\n')
                encoded += code.str[27];

            else
                encoded += code.str[str[i] - 'a'];

        }

        return encoded;
    }



};