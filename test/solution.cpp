#include "catch2/catch_all.hpp"
#include "solution.h"

using namespace std;

void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}

TEST_CASE("Validate isContains") {

    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);

    CHECK(isContains(test, 140) == true);
    CHECK(isContains(test, 25) == true);
    CHECK(isContains(test, 0) == false);
    CHECK(isContains(test, 150) == true);
    clean(test);
}

TEST_CASE("Validate getMin") {

    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);

    CHECK(getMin(test) == 25);
    test->left->left->left = new Node(5);
    CHECK(getMin(test) == 5);

    clean(test);
}

TEST_CASE("Validate getMax") {

    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);
    CHECK(getMin(test) == 140);
    test->right->right = new Node(180);
    CHECK(getMin(test) == 180);

    clean(test);
}


TEST_CASE("Validate insert") {

    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);
    test = insert(test, 150);
    CHECK(test->right->right->key == 180);
    test = insert(test, 75);
    CHECK(test->left->right->key == 75);

    clean(test);
}

TEST_CASE("Validate remove") {

    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);
    test = remove(test, 25);
    CHECK(test->left->left == nullptr);
    test = remove(test, 100);
    CHECK(test->key == 140);
    CHECK(test->right == nullptr);

    clean(test);
}