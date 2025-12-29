
#include "tokenizer.h"

bool isEmpty(char c) {
  if (c == ' ' || c == '\n' || c == '\t' || c == '\r') {
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
  size_t pos = 0;
  while (pos < input.size()) {
    char c = input[pos];
    // TODO: 空白
    // TODO: 数字
    // TODO: 标识符
    // TODO: 运算符 / 符号
    // TODO: 错误
    if (isEmpty(c)) {
      pos = pos + 1;
      continue;
    } else if (isdigit(c)) {
      int value = 0;
      size_t startPos = pos;
      while (pos < input.size() && isdigit(input[pos])) {
        value = value * 10 + c - '0';
        pos = pos + 1;
        c = input[pos];
      }
      tokens.push_back(Token(TokenType::INT, input.substr(startPos, pos - startPos), value, startPos));
    } else if (isIdentStart(c)) {
      size_t startPos = pos;
      while (pos < input.size() && isIdentChar(input[pos])) {
        pos = pos + 1;
      }
      tokens.push_back(Token(TokenType::IDENT, input.substr(startPos, pos - startPos), 0, startPos));
    } else if (c == '+') {
      tokens.push_back(Token(TokenType::PLUS, input.substr(pos, 1), 0, pos));
      pos = pos + 1;
    } else if (c == '-') {
      tokens.push_back(Token(TokenType::MINUS, input.substr(pos, 1), 0, pos));
      pos = pos + 1;
    } else if (c == '=') {
      tokens.push_back(Token(TokenType::ASSIGN, input.substr(pos, 1), 0, pos));
      pos = pos + 1;
    } else if (c == '*') {
      tokens.push_back(Token(TokenType::MUL, input.substr(pos, 1), 0, pos));
      pos = pos + 1;
    } else if (c == '/') {
      tokens.push_back(Token(TokenType::DIV, input.substr(pos, 1), 0, pos));
      pos = pos + 1;
    } else if (c == '(') {
      tokens.push_back(Token(TokenType::LPAREN, input.substr(pos, 1), 0, pos));
      pos = pos + 1;
    } else if (c == ')') {
      tokens.push_back(Token(TokenType::RPAREN, input.substr(pos, 1), 0, pos));
      pos = pos + 1;
    } else {
      throw std::runtime_error(
          "Unexpected character '" + std::string(1, c) +
          "' at position " + std::to_string(pos)
          );
    }
  }
  tokens.push_back(Token(TokenType::END, "", 0, pos));
  return tokens;
}