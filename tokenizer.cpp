
#include "tokenizer.h"

bool isEmpty(char c) {
  if (c == ' ' || c == '\t' || c == '\r') {
    return true;
  } else {
    return false;
  }
}

bool isIdentStart(char c) {
  if (c >= 'a' && c <= 'z') {
    return true;
  } else if (c >= 'A' && c <= 'Z') {
    return true;
  } else if (c == '_') {
    return true;
  } else {
    return false;
  }
}   // 字母或 _

bool isIdentChar(char c) {
  if (c >= 'a' && c <= 'z') {
    return true;
  } else if (c >= 'A' && c <= 'Z') {
    return true;
  } else if (c == '_') {
    return true;
  } else if (isdigit(c)) {
    return true;
  } else {
    return false;
  }
}   // 字母/数字/_

// bool isOperator(char c) {
//   if (c == '+' || c == '-' || c == '*' || c == '/') {
//     return true;
//   } else {
//     return false;
//   }
// }

std::vector<Token> tokenize(const std::string& input) {
  std::vector<Token> tokens;
  size_t pos = 0, row = 1, column = 1;
  while (pos < input.size()) {
    char c = input[pos];
    if (isEmpty(c)) {
      pos = pos + 1;
      column = column + 1;
      if (c == '\n') {
        column = 1;
        row = row + 1;
      }
    } else if (c == '#') {
      while (true) {
        pos = pos + 1;
        column = column + 1;
        if (input[pos] == '\n') {
          tokens.push_back(Token(TokenType::NEWLINE, input.substr(pos, 1), 0, row, column));
          pos = pos + 1;
          row = row + 1;
          column = 1;
          break;
        }
      }
    } else if (c == ';') {
      tokens.push_back(Token(TokenType::SEMICOLON, input.substr(pos, 1), 0, row, column));
      pos = pos + 1;
      column = column + 1;
    } else if (c == '\n') {
      tokens.push_back(Token(TokenType::NEWLINE, input.substr(pos, 1), 0, row, column));
      pos = pos + 1;
      row = row + 1;
      column = 1;
    } else if (c == '{') {
      tokens.push_back(Token(TokenType::LBRACE, input.substr(pos, 1), 0, row, column));
      pos = pos + 1;
      column = column + 1;
    } else if (c == '}') {
      tokens.push_back(Token(TokenType::RBRACE, input.substr(pos, 1), 0, row, column));
      pos = pos + 1;
      column = column + 1;
    } else if (isdigit(c)) {
      int value = 0;
      size_t startPos = pos;
      while (pos < input.size() && isdigit(input[pos])) {
        value = value * 10 + c - '0';
        pos = pos + 1;
        column = column + 1;
        c = input[pos];
      }
      tokens.push_back(Token(TokenType::INT, input.substr(startPos, pos - startPos), value, row, column));
    } else if (isIdentStart(c)) {
      size_t startPos = pos;
      while (pos < input.size() && isIdentChar(input[pos])) {
        pos = pos + 1;
        column = column + 1;
      }
      if (input.substr(startPos, pos - startPos) == "print") {
        tokens.push_back(Token(TokenType::PRINT, input.substr(startPos, pos - startPos), 0, row, column));
      } else if (input.substr(startPos, pos - startPos) == "if") {
        tokens.push_back(Token(TokenType::IF, input.substr(startPos, pos - startPos), 0, row, column));
      } else if (input.substr(startPos, pos - startPos) == "while") {
        tokens.push_back(Token(TokenType::WHILE, input.substr(startPos, pos - startPos), 0, row, column));
      } else if (input.substr(startPos, pos - startPos) == "else") {
        tokens.push_back(Token(TokenType::ELSE, input.substr(startPos, pos - startPos), 0, row, column));
      } else {
        tokens.push_back(Token(TokenType::IDENT, input.substr(startPos, pos - startPos), 0, row, column));
      }
    } else if (c == '+') {
      tokens.push_back(Token(TokenType::PLUS, input.substr(pos, 1), 0, row, column));
      pos = pos + 1;
      column = column + 1;
    } else if (c == '-') {
      tokens.push_back(Token(TokenType::MINUS, input.substr(pos, 1), 0, row, column));
      pos = pos + 1;
      column = column + 1;
    } else if (c == '=') {
      if (pos + 1 < input.size() && input[pos + 1] == '=') {
        tokens.push_back(Token(TokenType::EQUAL, input.substr(pos, 2), 0, row, column));
        pos = pos + 2;
        column = column + 2;
      }
      else {
        tokens.push_back(Token(TokenType::ASSIGN, input.substr(pos, 1), 0, row, column));
        pos = pos + 1;
        column = column + 1;
      }
    } else if (c == '*') {
      tokens.push_back(Token(TokenType::MUL, input.substr(pos, 1), 0, row, column));
      pos = pos + 1;
      column = column + 1;
    } else if (c == '/') {
      tokens.push_back(Token(TokenType::DIV, input.substr(pos, 1), 0, row, column));
      pos = pos + 1;
      column = column + 1;
    } else if (c == '(') {
      tokens.push_back(Token(TokenType::LPAREN, input.substr(pos, 1), 0, row, column));
      pos = pos + 1;
      column = column + 1;
    } else if (c == ')') {
      tokens.push_back(Token(TokenType::RPAREN, input.substr(pos, 1), 0, row, column));
      pos = pos + 1;
      column = column + 1;
    } else if (c == '>') {
      if (pos + 1 < input.size() && input[pos + 1] == '=') {
        tokens.push_back(Token(TokenType::GREATEREQUAL, input.substr(pos, 2), 0, row, column));
        pos = pos + 2;
        column = column + 2;
      }
      else {
        tokens.push_back(Token(TokenType::GREATER, input.substr(pos, 1), 0, row, column));
        pos = pos + 1;
        column = column + 1;
      }
    } else if (c == '<') {
      if (pos + 1 < input.size() && input[pos + 1] == '=') {
        tokens.push_back(Token(TokenType::LESSEQUAL, input.substr(pos, 2), 0, row, column));
        pos = pos + 2;
        column = column + 2;
      }
      else {
        tokens.push_back(Token(TokenType::LESS, input.substr(pos, 1), 0, row, column));
        pos = pos + 1;
        column = column + 1;
      }
    } else if (c == '!') {
      if (pos + 1 >= input.size() || input[pos + 1] != '=') {
        throw std::runtime_error(
          "Unexpected character '" + std::string(1, c) +
          "' at line " + std::to_string(row) + " , column " +
          std::to_string(column) + "!"
        );
      }
      tokens.push_back(Token(TokenType::NOTEQUAL, input.substr(pos, 2), 0, row, column));
      pos = pos + 2;
      column = column + 2;
    } else {
      throw std::runtime_error(
        "Unexpected character '" + std::string(1, c) +
        "' at line " + std::to_string(row) + " , column " +
        std::to_string(column) + "!"
      );
    }
  }
  tokens.push_back(Token(TokenType::END, std::string(""), 0, row, column));
  return tokens;
}