#include "stdafx.h"
#include "PlayBoard.h"

CPlayBoard::CPlayBoard(std::string fileName)
{
    AllocateMemory();

    // Load data from file
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << fileName << std::endl;
    }
    std::string line;
    int row = 0;
    while (std::getline(file, line) && row < m_size) {
        std::stringstream ss(line);
        std::string value;
        int col = 0;

        while (std::getline(ss, value, ',') && col < m_size) {
            m_board[col][row] = std::stoi(value);
            if (std::stoi(value) == Start)
            {
                m_startx = col;
                m_starty = row;
            }
            col++;
        }

        if (col != m_size) {
            std::cerr << "Row " << row + 1 << " has unmatched column number" << std::endl;
        }

        row++;
    }

    m_bestmoves = std::stoi(line);

    if (row != m_size) {
        std::cerr << "Row number is not " << m_size << std::endl;
    }

    file.close();
}

void CPlayBoard::Reload(std::string fileName)
{
    FreeMemory();
    AllocateMemory();

    // Load data from file
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << fileName << std::endl;
    }
    std::string line;
    int row = 0;
    while (std::getline(file, line) && row < m_size) {
        std::stringstream ss(line);
        std::string value;
        int col = 0;

        while (std::getline(ss, value, ',') && col < m_size) {
            m_board[col][row] = std::stoi(value);
            if (std::stoi(value) == Start)
            {
                m_startx = col;
                m_starty = row;
            }
            col++;
        }

        if (col != m_size) {
            std::cerr << "Row " << row + 1 << " has unmatched column number" << std::endl;
        }

        row++;
    }

    if (row != m_size) {
        std::cerr << "Row number is not " << m_size << std::endl;
    }

    file.close();
}

CPlayBoard::~CPlayBoard()
{
    FreeMemory();
}

void CPlayBoard::SetValue(int row, int col, int value)
{
    if (row < 0 || row >= m_size || col < 0 || col >= m_size) {
        throw std::out_of_range("Index out of range.");
    }
    m_board[row][col] = value;
}

int CPlayBoard::GetValue(int row, int col)
{
    if (row < 0 || row >= m_size || col < 0 || col >= m_size) {
        throw std::out_of_range("Index out of range.");
    }
    return m_board[row][col];
}

void CPlayBoard::AllocateMemory()
{
    m_board = new int* [m_size];
    for (int i = 0; i < m_size; ++i) {
        m_board[i] = new int[m_size];
    }
}

void CPlayBoard::FreeMemory()
{
    for (int i = 0; i < m_size; ++i) {
        delete[] m_board[i];
    }
    delete[] m_board;
}
