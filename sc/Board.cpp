#include "Board.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iterator>
using namespace std;

Board::Board(){
    reset();
}
void Board::reset(){
        score=0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                grid[i][j] = 0;
            }
        }
        spawnTile();
        spawnTile();
    }
void Board::spawnTile(){
        multimap<int,int> empty;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(grid[i][j] == 0){
                    empty.insert({i,j});
                }
            }
        }
        if(empty.empty()) return;
        auto index = rand() % empty.size();
        auto it = empty.begin();
        advance(it, index);
        int x = it -> first;
        int y = it -> second;
        grid[x][y] = (rand() % 10 == 0) ? 4 : 2;
    }
void Board::moveLeft(){
        bool moved = false;
        for(int i = 0; i < 4; i++){
            vector<int> row;

            for(int j = 0; j < 4; j++){
                if(grid[i][j] != 0){
                    row.push_back(grid[i][j]);
                }
            }
            for(int j = 0; j < (int)row.size()-1; j++){
                if(row[j] == row[j+1]){
                    row[j]*=2;
                    score+=row[j];
                    row[j+1] = 0;
                    moved = true;
                }
            }

            vector<int> newRow;
            for(int x : row){
                if(x != 0){
                    newRow.push_back(x);
                }
            }
            while((int)newRow.size() < 4) newRow.push_back(0);

            for(int j = 0; j < 4; j++){
                if(grid[i][j] != newRow[j]){
                    moved = true;
                }
                grid[i][j] = newRow[j];
            }
        }
        if(moved) spawnTile();
    }
void Board::moveRight(){
        bool moved = false;
        for (int i = 0; i < 4; ++i) {
            vector<int> row;

            for (int j = 3; j >= 0; --j)
                if (grid[i][j] != 0)
                    row.push_back(grid[i][j]);

            for (int j = 0; j + 1 < (int)row.size(); ++j) {
                if (row[j] == row[j + 1]) {
                    row[j] *= 2;
                    score+=row[j];
                    row[j + 1] = 0;
                    moved = true;
                }
            }
            vector<int> newRow;
            for (int x : row)
                if (x != 0)
                    newRow.push_back(x);
            while ((int)newRow.size() < 4)
                newRow.push_back(0);

            reverse(newRow.begin(), newRow.end());

            for (int j = 0; j < 4; ++j){
                if (grid[i][j] != newRow[j])
                    moved = true;
                grid[i][j] = newRow[j];
            }
        }

        if (moved) spawnTile();
    }   
void Board::moveUp(){
        bool moved = false;

        for (int j = 0; j < 4; ++j) {
            vector<int> col;
            for (int i = 0; i < 4; ++i)
                if (grid[i][j] != 0)
                    col.push_back(grid[i][j]);

            for (int i = 0; i + 1 < (int)col.size(); ++i) {
                if (col[i] == col[i + 1]) {
                    col[i] *= 2;
                    score+=col[i];
                    col[i + 1] = 0;
                    moved = true;
                }
            }

            vector<int> newCol;
            for (int x : col)
                if (x != 0)
                    newCol.push_back(x);
            while ((int)newCol.size() < 4)
                newCol.push_back(0);

            for (int i = 0; i < 4; ++i) {
                if (grid[i][j] != newCol[i])
                    moved = true;
                grid[i][j] = newCol[i];
            }
        }
        if (moved)spawnTile();
    }
void Board::moveDown(){
        bool moved = false;

        for (int j = 0; j < 4; ++j) {
            vector<int> col;
            for (int i = 3; i >= 0; --i)
                if (grid[i][j] != 0)
                    col.push_back(grid[i][j]);
            for (int i = 0; i + 1 < (int)col.size(); ++i) {
                if (col[i] == col[i + 1]) {
                    col[i] *= 2;
                    score+=col[i];
                    col[i + 1] = 0;
                    moved = true;
                }
            }
            vector<int> newCol;
            for (int x : col)
                if (x != 0)
                    newCol.push_back(x);
            while ((int)newCol.size() < 4)
                newCol.push_back(0);

            reverse(newCol.begin(), newCol.end());
            for (int i = 0; i < 4; ++i) {
                if (grid[i][j] != newCol[i])
                    moved = true;
                grid[i][j] = newCol[i];
            }
        }
        if (moved) spawnTile();
    }
bool Board::isGameOver(){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] == 0) return false; 
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == grid[i][j+1]) return false;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] == grid[i+1][j]) return false;
        }
    }
    return true;
}     
int Board::Score()const{
    return score;
}
int Board::loadHighScore()const{
    ifstream fin("highscore.txt");
    int high = 0;
    if (fin.is_open()){
        fin >> high;
        fin.close();
    }
    return high;
}
void Board::saveHighScore(int newScore){
    ofstream fout("highscore.txt");
    fout << newScore;
    fout.close();
}
int Board::get(int i, int j) const {
    return grid[i][j];
}