// Author: Yash Deshpande
// Date  : 18-08-2026
// Interviwee: Vedant Paranjpe
// Interviewer: Michal Weston (Microsoft)
// Link  : https://gist.github.com/VedantParanjape/bb6cd275b34f9523ccf9f3ffd43cd42a

//===----------------------------------------------------------------------===//
//
// Your task is to make a tree representation that contains shapes as nodes and
// then implement a post-order traversal of the tree.
//
// Please write neat code that aims towards production quality with one test.
//
//===----------------------------------------------------------------------===//
#include <array>
#include <cmath>
#include <numbers>
#include <span>
#include <string>
#include <iostream>
#include <vector>


class Shape {
 int64_t id;


protected:
 Shape(int64_t id) : id(id) {}


public:
 virtual ~Shape() = default;
 virtual std::string name() const = 0;
 virtual double area() const = 0;


 int64_t getID() const { return id; }
};


class Circle : public Shape {
 double radius;


public:
 Circle(int64_t id, double radius) : Shape(id), radius(radius) {}
 std::string name() const override { return "Circle"; }
 double area() const override { return std::numbers::pi * radius * radius; }
};


class Triangle : public Shape {
 std::array<double, 3> sides;


public:
 Triangle(int64_t id, std::span<double, 3> c)
     : Shape(id), sides{c[0], c[1], c[2]} {}
 std::string name() const override { return "Triangle"; }
 double area() const override {
   double s = (sides[0] + sides[1] + sides[2]) / 2;
   return std::sqrt(s * (s - sides[0]) * (s - sides[1]) * (s - sides[2]));
 }
};


class Rectangle : public Shape {
 double width;
 double height;


public:
 Rectangle(int64_t id, double width, double height)
     : Shape(id), width(width), height(height) {}
 std::string name() const override { return "Rectangle"; }
 double area() const override { return width * height; }
};


class Node {
   public:
       Shape *shape;
       std::vector<Node*> children;
};


void dfs(Node *root, std::vector<Node*> &postorder) {
   if (!root)
       return;
  
   for (auto child: root->children) {
       dfs(child, postorder);
   }
   postorder.push_back(root);
   return;
}


//     0
//   1  2
// 3  4


// 3 4 1 2 0
int main() {
   Node *root = new Node();
   root->shape = new Circle(0, 1.0);
   root->children = {new Node(), new Node()};


   root->children[0]->shape = new Circle(1, 1.0);
   root->children[1]->shape = new Circle(2, 1.0);
  
   root->children[0]->children = {new Node(), new Node()};
   root->children[0]->children[0]->shape = new Circle(3, 1.0);
   root->children[0]->children[1]->shape = new Circle(4, 1.0);
  
   std::vector<Node*> po;


   dfs(root, po);
  
   for (auto p: po) {
       std::cout << p->shape->getID() << "\n";
   }
   return 0;
}