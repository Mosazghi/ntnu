#include <iostream>
using namespace std;

struct Node
{
  char ID;
  bool besokt;
  Node *left, *right;
  Node(char id)
  {
    ID = id;
    left = right = nullptr;
    besokt = false;
  }
};

Node *byggTre();
int getAntallNoder(Node *node);
int getAntallNull(Node *node);
int getHoyde(Node *node);
void besok();

int gAntNoder = 0, gAntNull = 0, gAntFull = 0;

int main()
{
  Node *root;

  root = byggTre();
  cout << "Hoyde: " << getHoyde(root) << '\n';
  return 0;
}

int getAntallNoder(Node *node)
{
  if (node)
  {
    gAntNoder++;
    getAntallNoder(node->left);
    getAntallNoder(node->right);
  }
  return gAntNoder;
}
int getAntallNull(Node *node)
{
  gAntNoder = 0;
  return getAntallNoder(node) + 1;
}
int getHoyde(Node *node)
{
  if (!node)
    return 0;

  int l = getHoyde(node->left);
  int r = getHoyde(node->right);
  return max(l, r) + 1;
}

void besok(const Node *node)
{
}

Node *byggTre()
{
  Node *noder[15];
  for (int i = 0; i < 15; i++)
    noder[i] = new Node(static_cast<char>('A' + i));

  noder[0]->left = noder[1];
  noder[0]->right = noder[2];
  noder[1]->left = noder[3];
  noder[1]->right = noder[4];
  noder[2]->left = noder[5];
  noder[3]->left = noder[6];
  noder[3]->right = noder[7];
  noder[4]->right = noder[8];
  noder[5]->left = noder[9];
  noder[6]->right = noder[10];
  noder[7]->left = noder[11];
  noder[7]->right = noder[12];
  noder[8]->left = noder[13];
  noder[9]->right = noder[14];
  return noder[0];
}