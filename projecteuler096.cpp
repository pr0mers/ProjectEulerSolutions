#include <bits/stdc++.h>

using namespace std;
int sudokus[50][9][9] = {
    {{0, 0, 3, 0, 2, 0, 6, 0, 0}, {9, 0, 0, 3, 0, 5, 0, 0, 1}, {0, 0, 1, 8, 0, 6, 4, 0, 0}, {0, 0, 8, 1, 0, 2, 9, 0, 0}, {7, 0, 0, 0, 0, 0, 0, 0, 8}, {0, 0, 6, 7, 0, 8, 2, 0, 0}, {0, 0, 2, 6, 0, 9, 5, 0, 0}, {8, 0, 0, 2, 0, 3, 0, 0, 9}, {0, 0, 5, 0, 1, 0, 3, 0, 0}},
    {{2, 0, 0, 0, 8, 0, 3, 0, 0}, {0, 6, 0, 0, 7, 0, 0, 8, 4}, {0, 3, 0, 5, 0, 0, 2, 0, 9}, {0, 0, 0, 1, 0, 5, 4, 0, 8}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {4, 0, 2, 7, 0, 6, 0, 0, 0}, {3, 0, 1, 0, 0, 7, 0, 4, 0}, {7, 2, 0, 0, 4, 0, 0, 6, 0}, {0, 0, 4, 0, 1, 0, 0, 0, 3}},
    {{0, 0, 0, 0, 0, 0, 9, 0, 7}, {0, 0, 0, 4, 2, 0, 1, 8, 0}, {0, 0, 0, 7, 0, 5, 0, 2, 6}, {1, 0, 0, 9, 0, 4, 0, 0, 0}, {0, 5, 0, 0, 0, 0, 0, 4, 0}, {0, 0, 0, 5, 0, 7, 0, 0, 9}, {9, 2, 0, 1, 0, 8, 0, 0, 0}, {0, 3, 4, 0, 5, 9, 0, 0, 0}, {5, 0, 7, 0, 0, 0, 0, 0, 0}},
    {{0, 3, 0, 0, 5, 0, 0, 4, 0}, {0, 0, 8, 0, 1, 0, 5, 0, 0}, {4, 6, 0, 0, 0, 0, 0, 1, 2}, {0, 7, 0, 5, 0, 2, 0, 8, 0}, {0, 0, 0, 6, 0, 3, 0, 0, 0}, {0, 4, 0, 1, 0, 9, 0, 3, 0}, {2, 5, 0, 0, 0, 0, 0, 9, 8}, {0, 0, 1, 0, 2, 0, 6, 0, 0}, {0, 8, 0, 0, 6, 0, 0, 2, 0}},
    {{0, 2, 0, 8, 1, 0, 7, 4, 0}, {7, 0, 0, 0, 0, 3, 1, 0, 0}, {0, 9, 0, 0, 0, 2, 8, 0, 5}, {0, 0, 9, 0, 4, 0, 0, 8, 7}, {4, 0, 0, 2, 0, 8, 0, 0, 3}, {1, 6, 0, 0, 3, 0, 2, 0, 0}, {3, 0, 2, 7, 0, 0, 0, 6, 0}, {0, 0, 5, 6, 0, 0, 0, 0, 8}, {0, 7, 6, 0, 5, 1, 0, 9, 0}},
    {{1, 0, 0, 9, 2, 0, 0, 0, 0}, {5, 2, 4, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 7, 0}, {0, 5, 0, 0, 0, 8, 1, 0, 2}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {4, 0, 2, 7, 0, 0, 0, 9, 0}, {0, 6, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 3, 0, 9, 4, 5}, {0, 0, 0, 0, 7, 1, 0, 0, 6}},
    {{0, 4, 3, 0, 8, 0, 2, 5, 0}, {6, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 9, 4}, {9, 0, 0, 0, 0, 4, 0, 7, 0}, {0, 0, 0, 6, 0, 8, 0, 0, 0}, {0, 1, 0, 2, 0, 0, 0, 0, 3}, {8, 2, 0, 5, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 5}, {0, 3, 4, 0, 9, 0, 7, 1, 0}},
    {{4, 8, 0, 0, 0, 6, 9, 0, 2}, {0, 0, 2, 0, 0, 8, 0, 0, 1}, {9, 0, 0, 3, 7, 0, 0, 6, 0}, {8, 4, 0, 0, 1, 0, 2, 0, 0}, {0, 0, 3, 7, 0, 4, 1, 0, 0}, {0, 0, 1, 0, 6, 0, 0, 4, 9}, {0, 2, 0, 0, 8, 5, 0, 0, 7}, {7, 0, 0, 9, 0, 0, 6, 0, 0}, {6, 0, 9, 2, 0, 0, 0, 1, 8}},
    {{0, 0, 0, 9, 0, 0, 0, 0, 2}, {0, 5, 0, 1, 2, 3, 4, 0, 0}, {0, 3, 0, 0, 0, 0, 1, 6, 0}, {9, 0, 8, 0, 0, 0, 0, 0, 0}, {0, 7, 0, 0, 0, 0, 0, 9, 0}, {0, 0, 0, 0, 0, 0, 2, 0, 5}, {0, 9, 1, 0, 0, 0, 0, 5, 0}, {0, 0, 7, 4, 3, 9, 0, 2, 0}, {4, 0, 0, 0, 0, 7, 0, 0, 0}},
    {{0, 0, 1, 9, 0, 0, 0, 0, 3}, {9, 0, 0, 7, 0, 0, 1, 6, 0}, {0, 3, 0, 0, 0, 5, 0, 0, 7}, {0, 5, 0, 0, 0, 0, 0, 0, 9}, {0, 0, 4, 3, 0, 2, 6, 0, 0}, {2, 0, 0, 0, 0, 0, 0, 7, 0}, {6, 0, 0, 1, 0, 0, 0, 3, 0}, {0, 4, 2, 0, 0, 7, 0, 0, 6}, {5, 0, 0, 0, 0, 6, 8, 0, 0}},
    {{0, 0, 0, 1, 2, 5, 4, 0, 0}, {0, 0, 8, 4, 0, 0, 0, 0, 0}, {4, 2, 0, 8, 0, 0, 0, 0, 0}, {0, 3, 0, 0, 0, 0, 0, 9, 5}, {0, 6, 0, 9, 0, 2, 0, 1, 0}, {5, 1, 0, 0, 0, 0, 0, 6, 0}, {0, 0, 0, 0, 0, 3, 0, 4, 9}, {0, 0, 0, 0, 0, 7, 2, 0, 0}, {0, 0, 1, 2, 9, 8, 0, 0, 0}},
    {{0, 6, 2, 3, 4, 0, 7, 5, 0}, {1, 0, 0, 0, 0, 5, 6, 0, 0}, {5, 7, 0, 0, 0, 0, 0, 4, 0}, {0, 0, 0, 0, 9, 4, 8, 0, 0}, {4, 0, 0, 0, 0, 0, 0, 0, 6}, {0, 0, 5, 8, 3, 0, 0, 0, 0}, {0, 3, 0, 0, 0, 0, 0, 9, 1}, {0, 0, 6, 4, 0, 0, 0, 0, 7}, {0, 5, 9, 0, 8, 3, 2, 6, 0}},
    {{3, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 5, 0, 0, 9, 0, 0, 0}, {2, 0, 0, 5, 0, 4, 0, 0, 0}, {0, 2, 0, 0, 0, 0, 7, 0, 0}, {1, 6, 0, 0, 0, 0, 0, 5, 8}, {7, 0, 4, 3, 1, 0, 6, 0, 0}, {0, 0, 0, 8, 9, 0, 1, 0, 0}, {0, 0, 0, 0, 6, 7, 0, 8, 0}, {0, 0, 0, 0, 0, 5, 4, 3, 7}},
    {{6, 3, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 5, 0, 0, 0, 0, 8}, {0, 0, 5, 6, 7, 4, 0, 0, 0}, {0, 0, 0, 0, 2, 0, 0, 0, 0}, {0, 0, 3, 4, 0, 1, 0, 2, 0}, {0, 0, 0, 0, 0, 0, 3, 4, 5}, {0, 0, 0, 0, 0, 7, 0, 0, 4}, {0, 8, 0, 3, 0, 0, 9, 0, 2}, {9, 4, 7, 1, 0, 0, 0, 8, 0}},
    {{0, 0, 0, 0, 2, 0, 0, 4, 0}, {0, 0, 8, 0, 3, 5, 0, 0, 0}, {0, 0, 0, 0, 7, 0, 6, 0, 2}, {0, 3, 1, 0, 4, 6, 9, 7, 0}, {2, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 5, 0, 1, 2, 0, 3}, {0, 4, 9, 0, 0, 0, 7, 3, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0}, {8, 0, 0, 0, 0, 4, 0, 0, 0}},
    {{3, 6, 1, 0, 2, 5, 9, 0, 0}, {0, 8, 0, 9, 6, 0, 0, 1, 0}, {4, 0, 0, 0, 0, 0, 0, 5, 7}, {0, 0, 8, 0, 0, 0, 4, 7, 1}, {0, 0, 0, 6, 0, 3, 0, 0, 0}, {2, 5, 9, 0, 0, 0, 8, 0, 0}, {7, 4, 0, 0, 0, 0, 0, 0, 5}, {0, 2, 0, 0, 1, 8, 0, 6, 0}, {0, 0, 5, 4, 7, 0, 3, 2, 9}},
    {{0, 5, 0, 8, 0, 7, 0, 2, 0}, {6, 0, 0, 0, 1, 0, 0, 9, 0}, {7, 0, 2, 5, 4, 0, 0, 0, 6}, {0, 7, 0, 0, 2, 0, 3, 0, 1}, {5, 0, 4, 0, 0, 0, 9, 0, 8}, {1, 0, 3, 0, 8, 0, 0, 7, 0}, {9, 0, 0, 0, 7, 6, 2, 0, 5}, {0, 6, 0, 0, 9, 0, 0, 0, 3}, {0, 8, 0, 1, 0, 3, 0, 4, 0}},
    {{0, 8, 0, 0, 0, 5, 0, 0, 0}, {0, 0, 0, 0, 0, 3, 4, 5, 7}, {0, 0, 0, 0, 7, 0, 8, 0, 9}, {0, 6, 0, 4, 0, 0, 9, 0, 3}, {0, 0, 7, 0, 1, 0, 5, 0, 0}, {4, 0, 8, 0, 0, 7, 0, 2, 0}, {9, 0, 1, 0, 2, 0, 0, 0, 0}, {8, 4, 2, 3, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 8, 0}},
    {{0, 0, 3, 5, 0, 2, 9, 0, 0}, {0, 0, 0, 0, 4, 0, 0, 0, 0}, {1, 0, 6, 0, 0, 0, 3, 0, 5}, {9, 0, 0, 2, 5, 1, 0, 0, 8}, {0, 7, 0, 4, 0, 8, 0, 3, 0}, {8, 0, 0, 7, 6, 3, 0, 0, 1}, {3, 0, 8, 0, 0, 0, 1, 0, 4}, {0, 0, 0, 0, 2, 0, 0, 0, 0}, {0, 0, 5, 1, 0, 4, 8, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 9, 8, 0, 5, 1, 0, 0}, {0, 5, 1, 9, 0, 7, 4, 2, 0}, {2, 9, 0, 4, 0, 1, 0, 6, 5}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 4, 0, 5, 0, 8, 0, 9, 3}, {0, 2, 6, 7, 0, 9, 5, 8, 0}, {0, 0, 5, 1, 0, 3, 6, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 3, 0, 0, 9, 0}, {0, 0, 0, 9, 0, 7, 0, 0, 0}, {9, 0, 0, 2, 0, 8, 0, 0, 5}, {0, 0, 4, 8, 0, 6, 5, 0, 0}, {6, 0, 7, 0, 0, 0, 2, 0, 8}, {0, 0, 3, 1, 0, 2, 9, 0, 0}, {8, 0, 0, 6, 0, 5, 0, 0, 7}, {0, 0, 0, 3, 0, 9, 0, 0, 0}, {0, 3, 0, 0, 2, 0, 0, 5, 0}},
    {{0, 0, 5, 0, 0, 0, 0, 0, 6}, {0, 7, 0, 0, 0, 9, 0, 2, 0}, {0, 0, 0, 5, 0, 0, 1, 0, 7}, {8, 0, 4, 1, 5, 0, 0, 0, 0}, {0, 0, 0, 8, 0, 3, 0, 0, 0}, {0, 0, 0, 0, 9, 2, 8, 0, 5}, {9, 0, 7, 0, 0, 6, 0, 0, 0}, {0, 3, 0, 4, 0, 0, 0, 1, 0}, {2, 0, 0, 0, 0, 0, 6, 0, 0}},
    {{0, 4, 0, 0, 0, 0, 0, 5, 0}, {0, 0, 1, 9, 4, 3, 6, 0, 0}, {0, 0, 9, 0, 0, 0, 3, 0, 0}, {6, 0, 0, 0, 5, 0, 0, 0, 2}, {1, 0, 3, 0, 0, 0, 5, 0, 6}, {8, 0, 0, 0, 2, 0, 0, 0, 7}, {0, 0, 5, 0, 0, 0, 2, 0, 0}, {0, 0, 2, 4, 3, 6, 7, 0, 0}, {0, 3, 0, 0, 0, 0, 0, 4, 0}},
    {{0, 0, 4, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 3, 0, 0, 0, 2}, {3, 9, 0, 7, 0, 0, 0, 8, 0}, {4, 0, 0, 0, 0, 9, 0, 0, 1}, {2, 0, 9, 8, 0, 1, 3, 0, 7}, {6, 0, 0, 2, 0, 0, 0, 0, 8}, {0, 1, 0, 0, 0, 8, 0, 5, 3}, {9, 0, 0, 0, 4, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 8, 0, 0}},
    {{3, 6, 0, 0, 2, 0, 0, 8, 9}, {0, 0, 0, 3, 6, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {8, 0, 3, 0, 0, 0, 6, 0, 2}, {4, 0, 0, 6, 0, 3, 0, 0, 7}, {6, 0, 7, 0, 0, 0, 1, 0, 8}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 4, 1, 8, 0, 0, 0}, {9, 7, 0, 0, 3, 0, 0, 1, 4}},
    {{5, 0, 0, 4, 0, 0, 0, 6, 0}, {0, 0, 9, 0, 0, 0, 8, 0, 0}, {6, 4, 0, 0, 2, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 8}, {2, 0, 8, 0, 0, 0, 5, 0, 1}, {7, 0, 0, 5, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 9, 0, 0, 8, 4}, {0, 0, 3, 0, 0, 0, 6, 0, 0}, {0, 6, 0, 0, 0, 3, 0, 0, 2}},
    {{0, 0, 7, 2, 5, 6, 4, 0, 0}, {4, 0, 0, 0, 0, 0, 0, 0, 5}, {0, 1, 0, 0, 3, 0, 0, 6, 0}, {0, 0, 0, 5, 0, 8, 0, 0, 0}, {0, 0, 8, 0, 6, 0, 2, 0, 0}, {0, 0, 0, 1, 0, 7, 0, 0, 0}, {0, 3, 0, 0, 7, 0, 0, 9, 0}, {2, 0, 0, 0, 0, 0, 0, 0, 4}, {0, 0, 6, 3, 1, 2, 7, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 7, 9, 0, 5, 0, 1, 8, 0}, {8, 0, 0, 0, 0, 0, 0, 0, 7}, {0, 0, 7, 3, 0, 6, 8, 0, 0}, {4, 5, 0, 7, 0, 8, 0, 9, 6}, {0, 0, 3, 5, 0, 2, 7, 0, 0}, {7, 0, 0, 0, 0, 0, 0, 0, 5}, {0, 1, 6, 0, 3, 0, 4, 2, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 3, 0, 0, 0, 0, 0, 8, 0}, {0, 0, 9, 0, 0, 0, 5, 0, 0}, {0, 0, 7, 5, 0, 9, 2, 0, 0}, {7, 0, 0, 1, 0, 5, 0, 0, 8}, {0, 2, 0, 0, 9, 0, 0, 3, 0}, {9, 0, 0, 4, 0, 2, 0, 0, 1}, {0, 0, 4, 2, 0, 7, 1, 0, 0}, {0, 0, 2, 0, 0, 0, 8, 0, 0}, {0, 7, 0, 0, 0, 0, 0, 9, 0}},
    {{2, 0, 0, 1, 7, 0, 6, 0, 3}, {0, 5, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 6, 0, 7, 9}, {0, 0, 0, 0, 4, 0, 7, 0, 0}, {0, 0, 0, 8, 0, 1, 0, 0, 0}, {0, 0, 9, 0, 5, 0, 0, 0, 0}, {3, 1, 0, 4, 0, 0, 0, 0, 0}, {0, 0, 5, 0, 0, 0, 0, 6, 0}, {9, 0, 6, 0, 3, 7, 0, 0, 2}},
    {{0, 0, 0, 0, 0, 0, 0, 8, 0}, {8, 0, 0, 7, 0, 1, 0, 4, 0}, {0, 4, 0, 0, 2, 0, 0, 3, 0}, {3, 7, 4, 0, 0, 0, 9, 0, 0}, {0, 0, 0, 0, 3, 0, 0, 0, 0}, {0, 0, 5, 0, 0, 0, 3, 2, 1}, {0, 1, 0, 0, 6, 0, 0, 5, 0}, {0, 5, 0, 8, 0, 2, 0, 0, 6}, {0, 8, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 8, 5}, {0, 0, 0, 2, 1, 0, 0, 0, 9}, {9, 6, 0, 0, 8, 0, 1, 0, 0}, {5, 0, 0, 8, 0, 0, 0, 1, 6}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {8, 9, 0, 0, 0, 6, 0, 0, 7}, {0, 0, 9, 0, 7, 0, 0, 5, 2}, {3, 0, 0, 0, 5, 4, 0, 0, 0}, {4, 8, 0, 0, 0, 0, 0, 0, 0}},
    {{6, 0, 8, 0, 7, 0, 5, 0, 2}, {0, 5, 0, 6, 0, 8, 0, 7, 0}, {0, 0, 2, 0, 0, 0, 3, 0, 0}, {5, 0, 0, 0, 9, 0, 0, 0, 6}, {0, 4, 0, 3, 0, 2, 0, 5, 0}, {8, 0, 0, 0, 5, 0, 0, 0, 3}, {0, 0, 5, 0, 0, 0, 2, 0, 0}, {0, 1, 0, 7, 0, 4, 0, 9, 0}, {4, 0, 9, 0, 6, 0, 7, 0, 1}},
    {{0, 5, 0, 0, 1, 0, 0, 4, 0}, {1, 0, 7, 0, 0, 0, 6, 0, 2}, {0, 0, 0, 9, 0, 5, 0, 0, 0}, {2, 0, 8, 0, 3, 0, 5, 0, 1}, {0, 4, 0, 0, 7, 0, 0, 2, 0}, {9, 0, 1, 0, 8, 0, 4, 0, 6}, {0, 0, 0, 4, 0, 1, 0, 0, 0}, {3, 0, 4, 0, 0, 0, 7, 0, 9}, {0, 2, 0, 0, 6, 0, 0, 1, 0}},
    {{0, 5, 3, 0, 0, 0, 7, 9, 0}, {0, 0, 9, 7, 5, 3, 4, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 2}, {0, 9, 0, 0, 8, 0, 0, 1, 0}, {0, 0, 0, 9, 0, 7, 0, 0, 0}, {0, 8, 0, 0, 3, 0, 0, 7, 0}, {5, 0, 0, 0, 0, 0, 0, 0, 3}, {0, 0, 7, 6, 4, 1, 2, 0, 0}, {0, 6, 1, 0, 0, 0, 9, 4, 0}},
    {{0, 0, 6, 0, 8, 0, 3, 0, 0}, {0, 4, 9, 0, 7, 0, 2, 5, 0}, {0, 0, 0, 4, 0, 5, 0, 0, 0}, {6, 0, 0, 3, 1, 7, 0, 0, 4}, {0, 0, 7, 0, 0, 0, 8, 0, 0}, {1, 0, 0, 8, 2, 6, 0, 0, 9}, {0, 0, 0, 7, 0, 2, 0, 0, 0}, {0, 7, 5, 0, 4, 0, 1, 9, 0}, {0, 0, 3, 0, 9, 0, 6, 0, 0}},
    {{0, 0, 5, 0, 8, 0, 7, 0, 0}, {7, 0, 0, 2, 0, 4, 0, 0, 5}, {3, 2, 0, 0, 0, 0, 0, 8, 4}, {0, 6, 0, 1, 0, 5, 0, 4, 0}, {0, 0, 8, 0, 0, 0, 5, 0, 0}, {0, 7, 0, 8, 0, 3, 0, 1, 0}, {4, 5, 0, 0, 0, 0, 0, 9, 1}, {6, 0, 0, 5, 0, 8, 0, 0, 7}, {0, 0, 3, 0, 1, 0, 6, 0, 0}},
    {{0, 0, 0, 9, 0, 0, 8, 0, 0}, {1, 2, 8, 0, 0, 6, 4, 0, 0}, {0, 7, 0, 8, 0, 0, 0, 6, 0}, {8, 0, 0, 4, 3, 0, 0, 0, 7}, {5, 0, 0, 0, 0, 0, 0, 0, 9}, {6, 0, 0, 0, 7, 9, 0, 0, 8}, {0, 9, 0, 0, 0, 4, 0, 1, 0}, {0, 0, 3, 6, 0, 0, 2, 8, 4}, {0, 0, 1, 0, 0, 7, 0, 0, 0}},
    {{0, 0, 0, 0, 8, 0, 0, 0, 0}, {2, 7, 0, 0, 0, 0, 0, 5, 4}, {0, 9, 5, 0, 0, 0, 8, 1, 0}, {0, 0, 9, 8, 0, 6, 4, 0, 0}, {0, 2, 0, 4, 0, 3, 0, 6, 0}, {0, 0, 6, 9, 0, 5, 1, 0, 0}, {0, 1, 7, 0, 0, 0, 6, 2, 0}, {4, 6, 0, 0, 0, 0, 0, 3, 8}, {0, 0, 0, 0, 9, 0, 0, 0, 0}},
    {{0, 0, 0, 6, 0, 2, 0, 0, 0}, {4, 0, 0, 0, 5, 0, 0, 0, 1}, {0, 8, 5, 0, 1, 0, 6, 2, 0}, {0, 3, 8, 2, 0, 6, 7, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 9, 4, 0, 7, 3, 5, 0}, {0, 2, 6, 0, 4, 0, 5, 3, 0}, {9, 0, 0, 0, 2, 0, 0, 0, 7}, {0, 0, 0, 8, 0, 9, 0, 0, 0}},
    {{0, 0, 0, 9, 0, 0, 0, 0, 2}, {0, 5, 0, 1, 2, 3, 4, 0, 0}, {0, 3, 0, 0, 0, 0, 1, 6, 0}, {9, 0, 8, 0, 0, 0, 0, 0, 0}, {0, 7, 0, 0, 0, 0, 0, 9, 0}, {0, 0, 0, 0, 0, 0, 2, 0, 5}, {0, 9, 1, 0, 0, 0, 0, 5, 0}, {0, 0, 7, 4, 3, 9, 0, 2, 0}, {4, 0, 0, 0, 0, 7, 0, 0, 0}},
    {{3, 8, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 4, 0, 0, 7, 8, 5}, {0, 0, 9, 0, 2, 0, 3, 0, 0}, {0, 6, 0, 0, 9, 0, 0, 0, 0}, {8, 0, 0, 3, 0, 2, 0, 0, 9}, {0, 0, 0, 0, 4, 0, 0, 7, 0}, {0, 0, 1, 0, 7, 0, 5, 0, 0}, {4, 9, 5, 0, 0, 6, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 9, 2}},
    {{0, 0, 0, 1, 5, 8, 0, 0, 0}, {0, 0, 2, 0, 6, 0, 8, 0, 0}, {0, 3, 0, 0, 0, 0, 0, 4, 0}, {0, 2, 7, 0, 3, 0, 5, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 4, 6, 0, 8, 0, 7, 9, 0}, {0, 5, 0, 0, 0, 0, 0, 8, 0}, {0, 0, 4, 0, 7, 0, 1, 0, 0}, {0, 0, 0, 3, 2, 5, 0, 0, 0}},
    {{0, 1, 0, 5, 0, 0, 2, 0, 0}, {9, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 2, 0, 0, 8, 0, 3, 0}, {5, 0, 0, 0, 3, 0, 0, 0, 7}, {0, 0, 8, 0, 0, 0, 5, 0, 0}, {6, 0, 0, 0, 8, 0, 0, 0, 4}, {0, 4, 0, 1, 0, 0, 7, 0, 0}, {0, 0, 0, 7, 0, 0, 0, 0, 6}, {0, 0, 3, 0, 0, 4, 0, 5, 0}},
    {{0, 8, 0, 0, 0, 0, 0, 4, 0}, {0, 0, 0, 4, 6, 9, 0, 0, 0}, {4, 0, 0, 0, 0, 0, 0, 0, 7}, {0, 0, 5, 9, 0, 4, 6, 0, 0}, {0, 7, 0, 6, 0, 8, 0, 3, 0}, {0, 0, 8, 5, 0, 2, 1, 0, 0}, {9, 0, 0, 0, 0, 0, 0, 0, 5}, {0, 0, 0, 7, 8, 1, 0, 0, 0}, {0, 6, 0, 0, 0, 0, 0, 1, 0}},
    {{9, 0, 4, 2, 0, 0, 0, 0, 7}, {0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 7, 0, 6, 5, 0, 0}, {0, 0, 0, 8, 0, 0, 0, 9, 0}, {0, 2, 0, 9, 0, 4, 0, 6, 0}, {0, 4, 0, 0, 0, 2, 0, 0, 0}, {0, 0, 1, 6, 0, 7, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 3, 0}, {3, 0, 0, 0, 0, 5, 7, 0, 2}},
    {{0, 0, 0, 7, 0, 0, 8, 0, 0}, {0, 0, 6, 0, 0, 0, 0, 3, 1}, {0, 4, 0, 0, 0, 2, 0, 0, 0}, {0, 2, 4, 0, 7, 0, 0, 0, 0}, {0, 1, 0, 0, 3, 0, 0, 8, 0}, {0, 0, 0, 0, 6, 0, 2, 9, 0}, {0, 0, 0, 8, 0, 0, 0, 7, 0}, {8, 6, 0, 0, 0, 0, 5, 0, 0}, {0, 0, 2, 0, 0, 6, 0, 0, 0}},
    {{0, 0, 1, 0, 0, 7, 0, 9, 0}, {5, 9, 0, 0, 8, 0, 0, 0, 1}, {0, 3, 0, 0, 0, 0, 0, 8, 0}, {0, 0, 0, 0, 0, 5, 8, 0, 0}, {0, 5, 0, 0, 6, 0, 0, 2, 0}, {0, 0, 4, 1, 0, 0, 0, 0, 0}, {0, 8, 0, 0, 0, 0, 0, 3, 0}, {1, 0, 0, 0, 2, 0, 0, 7, 9}, {0, 2, 0, 7, 0, 0, 4, 0, 0}},
    {{0, 0, 0, 0, 0, 3, 0, 1, 7}, {0, 1, 5, 0, 0, 9, 0, 0, 8}, {0, 6, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 7, 0, 0, 0}, {0, 0, 9, 0, 0, 0, 2, 0, 0}, {0, 0, 0, 5, 0, 0, 0, 0, 4}, {0, 0, 0, 0, 0, 0, 0, 2, 0}, {5, 0, 0, 6, 0, 0, 3, 4, 0}, {3, 4, 0, 2, 0, 0, 0, 0, 0}},
    {{3, 0, 0, 2, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 7, 0, 0, 0}, {7, 0, 6, 0, 3, 0, 5, 0, 0}, {0, 7, 0, 0, 0, 9, 0, 8, 0}, {9, 0, 0, 0, 2, 0, 0, 0, 4}, {0, 1, 0, 8, 0, 0, 0, 5, 0}, {0, 0, 9, 0, 4, 0, 3, 0, 1}, {0, 0, 0, 7, 0, 2, 0, 0, 0}, {0, 0, 0, 0, 0, 8, 0, 0, 6}},
};

int sudoku[9][9] = {};
bool olurmu(int y,int x,int sayi){
    for(int i=0;i<9;i++){
        if(sudoku[i][x] ==sayi || sudoku[y][i]==sayi){
            return false;
        }
    }
    int ky=y/3;
    int kx=x/3;
    for(int i=ky*3;i<ky*3+3;i++){
        for(int j=kx*3;j<kx*3+3;j++){
            if(sudoku[i][j]==sayi){
                return false;
            }
        }
    }
    return true;
}

bool solve(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j]==0){
                for(int sa=1;sa<10;sa++){
                    if(olurmu(i,j,sa)){
                        sudoku[i][j]=sa;
                        if (solve()) {
                            return true;
                        }
                        sudoku[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main() {
    int toplam=0;
    for(int kls=0;kls<50;kls++){
        for(int i =0;i<9;i++){
            for(int j=0;j<9;j++){
                sudoku[i][j]=sudokus[kls][i][j];
            }
        }
        if(solve()){
            toplam=toplam+sudoku[0][2]+sudoku[0][1]*10+sudoku[0][0]*100;
        }
    }
    cout<<toplam;
}
    
