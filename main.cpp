#include <iostream>
#include <string>

std::string area1 [10][10];
std::string area2 [10][10];

std::string initFog (std::string area[][10]) {
    for (int i = 0; i < 10; i++) {
        for (int f = 0; f < 10; f++) {
            area[i][f] = "_";
        }
    }
    return area[10][10];
}

std::string placeShips (std::string area[][10]) {
    std::cout << "place your ships horizontal and vertical. Two coordinates for 1-cell ships, and four (start and end) coordinates for 2,3 & 4-cell ships." << std::endl;
    bool check = false;
    int a, b, c, d;
        std::cout << "Input coordinates(0-9) for 4 1-cell ships:" << std::endl;
            for (int i = 0; i < 4; i++) {
                do {
                    std::cin >> a >> b;
                        if (a >= 0 && a < 10 && b >= 0 && b < 10) {
                            if (area[a][b] != "_") {
                                std::cerr << "Error! This cell is already done! Input again!" << std::endl;
                                check = false;
                            } else {
                                area[a][b] = "S";
                                check = true;
                            }
                        } else {
                            std::cerr << "Error! Input again!" << std::endl;
                            check = false;
                        }
                } while (!check);
            }
            check = false;
            std::cout << "Input coordinates for 3 2-cell ships:" << std::endl;
                for (int i = 0; i < 3; i++) {
                    do {
                        std::cin >> a >> b >> c >> d;
                            if (a >= 0 && a < 10 && b >= 0 && b < 10 && c >= 0 && c < 10 && d >= 0 && d < 10) {
                                if (area[a][b] != "_" || area[c][d] != "_") {
                                    std::cerr << "Error! This cell is already done! Input again!" << std::endl;
                                    check = false;
                                } else if ((a == c) && ((d == b + 1) || (d == b - 1))) {
                                    area[a][b] = "S";
                                    area[c][d] = "S";
                                    check = true;
                                } else if ((b == d) && ((c == a + 1) || (c == a - 1))) {
                                    area[a][b] = "S";
                                    area[c][d] = "S";
                                    check = true;
                                } else {
                                    std::cerr << "Error! Not valid start and end of ship!" << std::endl;
                                    check = false;
                                }
                            } else {
                                std::cerr << "Error! Input again!" << std::endl;
                                check = false;
                            }
                    } while (!check);
                }
            check = false;
            std::cout << "Input coordinates for 2 3-cell ships:" << std::endl;
                for (int i = 0; i < 2; i++) {
                    do {
                        std::cin >> a >> b >> c >> d;
                        if (a >= 0 && a < 10 && b >= 0 && b < 10 && c >= 0 && c < 10 && d >= 0 && d < 10) {
                            if (area[a][b] != "_" || area[c][d] != "_") {
                                std::cerr << "Error! This cell is already done! Input again!" << std::endl;
                                check = false;
                            } else if ((a == c) && ((d == b + 2) || (d == b - 2))) {
                                if ((d == b + 2) && (area[a][b + 1] == "_")) {
                                    area[a][b + 1] = "S";
                                    area[a][b] = "S";
                                    area[c][d] = "S";
                                    check = true;
                                } if ((d == b - 2) && (area[a][b - 1] == "_")) {
                                    area[a][b - 1] = "S";
                                    area[a][b] = "S";
                                    area[c][d] = "S";
                                    check = true;
                                }
                            } else if ((b == d) && ((c == a + 2) || (c == a - 2))) {
                                if ((c == a + 2) && (area[a + 1][b] == "_")) {
                                    area[a + 1][b] = "S";
                                    area[a][b] = "S";
                                    area[c][d] = "S";
                                    check = true;
                                } if ((c == a - 2) && (area[a - 1][b] == "_")) {
                                    area[a - 1][b] = "S";
                                    area[a][b] = "S";
                                    area[c][d] = "S";
                                    check = true;
                                }
                            } else {
                                std::cerr << "Error! Not valid start and end of ship!" << std::endl;
                                check = false;
                            }
                        } else {
                            std::cerr << "Error! Input again!" << std::endl;
                            check = false;
                        }
                    } while (!check);
                }
            check = false;
            std::cout << "Input coordinates for 4-cell ship:" << std::endl;
                do {
                    std::cin >> a >> b >> c >> d;
                        if (a >= 0 && a < 10 && b >= 0 && b < 10 && c >= 0 && c < 10 && d >= 0 && d < 10) {
                            if ((area[a][b] != "_" || area[c][d] != "_") && ((a == c) || (b == d))) {
                                std::cerr << "Error! This cell is already done! Input again!" << std::endl;
                                check = false;
                            } else if ((a == c) && ((d == b + 3) || (d == b - 3))) {
                                if ((d == b + 3) && (area[a][b + 1] == "_") && (area[a][b + 2] == "_")) {
                                    area[a][b + 1] = "S";
                                    area[a][b + 2] = "S";
                                    area[a][b] = "S";
                                    area[c][d] = "S";
                                    check = true;
                                } if ((d == b - 3) && (area[a][b - 1] == "_") && (area[a][b - 2] == "_")) {
                                    area[a][b - 1] = "S";
                                    area[a][b - 2] = "S";
                                    area[a][b] = "S";
                                    area[c][d] = "S";
                                    check = true;
                                }
                            } else if ((b == d) && ((c == a + 3) || (c == a - 3))) {
                                if ((c == a + 3) && (area[a + 1][b] == "_") && (area[a + 2][b] == "_")) {
                                    area[a + 1][b] = "S";
                                    area[a + 2][b] = "S";
                                    area[a][b] = "S";
                                    area[c][d] = "S";
                                    check = true;
                                } if ((c == a - 3) && (area[a - 1][b] == "_") && (area[a - 2][b] == "_")) {
                                    area[a - 1][b] = "S";
                                    area[a - 2][b] = "S";
                                    area[a][b] = "S";
                                    area[c][d] = "S";
                                    check = true;
                                }
                            } else {
                                std::cerr << "Error! Not valid start and end of ship!" << std::endl;
                                check = false;
                            }
                        } else {
                            std::cerr << "Error! Input again!" << std::endl;
                            check = false;
                        }
                    } while (!check);
                std::cout << "Done!" << std::endl;
            return area[10][10];
}

void shot (std::string area[][10]) {
    int x, y;
    std::cout << "input coordinates of your shot: " << std::endl;
    do {
        std::cin >> x >> y;
        if (x < 0 || x > 9 || y < 0 || y > 9 || area[x][y] == "X" || area[x][y] == "V") {
            std::cout << "Error! Input again!" << std::endl;
        }
    } while (x < 0 || x > 9 || y < 0 || y > 9 || area[x][y] == "X" || area[x][y] == "V");
    if (area[x][y] == "S") {
        std::cout << "It's a hit!" << std::endl;
        area[x][y] = "V";
        for (int i = 0; i < 10; i++) {
            for (int f = 0; f < 10; f++) {
                if (area[i][f] == "S") {
                    std::cout << "_" << " ";
                } else {
                    std::cout << area[i][f] << " ";
                }
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "Away!" << std::endl;
        area[x][y] = "X";
        for (int i = 0; i < 10; i++) {
            for (int f = 0; f < 10; f++) {
                if (area[i][f] == "S") {
                    std::cout << "_" << " ";
                } else {
                    std::cout << area[i][f] << " ";
                }
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    initFog(area1);
    initFog(area2);
    int count1, count2;
    std::cout << "Player 1, ";
    placeShips(area1);
    std::cout << "Player 2, ";
    placeShips(area2);
    do {
        std::cout << "Player 1, ";
        shot(area2);
        count1 = 0;
        for (int i = 0; i < 10; i++) {
            for (int f = 0; f < 10; f++) {
                if (area2[i][f] == "S") {
                    count1 += 1;
                }
            }
        }
        if (count1 == 0) {
            std::cout << "Congrats! Player 1 WIN!" << std::endl;
            return 0;
        }
        std::cout << "Player 2, ";
        shot(area1);
        count2 = 0;
        for (int i = 0; i < 10; i++) {
            for (int f = 0; f < 10; f++) {
                if (area1[i][f] == "S") {
                    count2 += 1;
                }
            }
        }
        if (count2 == 0) {
            std::cout << "Congrats! Player 2 WIN!" << std::endl;
            return 0;
        }
    } while (true);
}
