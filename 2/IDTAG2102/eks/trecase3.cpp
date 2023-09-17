#include <iostream> //  cout
#include <cstdlib>  //  (s)rand
using namespace std;

/**
 *  Node (med ID/key/data, nivå og venstre/høyre pekere til nodens barn).
 */
struct Node
{
  char ID;     //  Nodens ID/key/navn (en bokstav).
  int nivaa;   //  Nodens nivå i treet ift. rotnoden.
  Node *left;  //  Peker til venstre subtre, evt nullptr.
  Node *right; //  Peker til høyre subtre, evt nullptr.
  Node()
  {
    ID = '-';
    nivaa = 0;
    left = right = nullptr;
  }
};

Node *gRoot = nullptr; ///<  Peker til treets rot.
int gNumber = 65;      ///<  Første node er 'A' (ASCII-tegn nr.65).

Node *generate(const int depth, const int probability);
void traverse(Node *node);
void besok(Node *node);
void finnVerdier(Node *node, int &sumNivaa, int &antall);
void setNivaa(Node *node);

int main()
{
  srand(0); //   Brukes ifm. tilfeldighet/randomisering.
  int sum = 0, ant = 0;
  gRoot = generate(5, 80);
  setNivaa(gRoot);
  traverse(gRoot);
  finnVerdier(gRoot, sum, ant);
  cout << "sum: " << sum << " ant: " << ant << '\n';
  cout << "Gjsnitt: " << static_cast<float>(sum) / ant << '\n';
}
void finnVerdier(Node *node, int &sumNivaa, int &antall)
{
  if (node)
  {
    sumNivaa += node->nivaa;
    antall++;
    finnVerdier(node->left, sumNivaa, antall);
    finnVerdier(node->right, sumNivaa, antall);
  }
}

void setNivaa(Node *node)
{
  if (node)
  {
    if (node->left)
    {
      node->left->nivaa = node->nivaa + 1;
    }
    if (node->right)
    {
      node->right->nivaa = node->nivaa + 1;
    }
    setNivaa(node->right);
    setNivaa(node->left);
  }
}

Node *generate(const int depth, const int probability)
{
  Node *rot = nullptr; //  Peker til det som returneres.
                       //  NB: Initieres til 'nullptr'!
  if (depth > 0)
  { //  Kan fortsatt legge til et nivå:
    if (rand() % 100 < probability)
    {                                                //  Trukket tall i rett intervall:
      rot = new Node;                                //  Lager en ny node.
      rot->left = generate(depth - 1, probability);  // Lager evt v.subtre.
      rot->ID = static_cast<char>(gNumber++);        //  Legger inn egen ID.
      rot->right = generate(depth - 1, probability); // Lager evt h.subtre.
    }
  }
  return rot; //  Returnerer generert tre eller nullptr.
}

void traverse(Node *node)
{
  if (node)
  {
    traverse(node->left);
    besok(node);
    traverse(node->right);
  }
}

void besok(Node *node)
{ //  Viser innholdet i EN node.
  cout << ' ' << node->ID << ":  " << node->nivaa << '\n';
}
// A : 4 B : 3 C : 2 D : 3 E : 4 F : 1 G : 4 H : 3 I : 4 J : 2 K : 0 L : 3 M : 2 N : 1 O : 2 P : 4 Q : 3 R : 4
// A:  4 B:  3 C:  2 D:  3 E:  4 F:  1 G:  4 H:  3 I:  4 J:  2 K:  0 L:  3 M:  2 N:  1 O:  2 P:  4 Q:  3 R:  4