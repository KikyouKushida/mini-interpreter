#pragma once
#include <string>

enum class TokenType {
  INT,
  IDENT, 
  PLUS,
  MINUS,
  MUL,
  DIV,
  ASSIGN,
  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,
  END,
  PRINT,
  SEMICOLON,
  NEWLINE,
  INVALID
};

struct Token {
  TokenType type;
  std::string lexeme; // the initial text
  int value; // only valid for TokenType::INT
  size_t position; // the location in the initial string
  Token(TokenType type_, std::string lexeme_, int value_, size_t position_) {
    type = type_;
    lexeme = lexeme_;
    value = value_;
    position = position_;
  }
  std::string toString() const {
    if (type == TokenType::ASSIGN) {
      return std::string("ASSIGN(" + lexeme + ")");
    } else if (type == TokenType::DIV) {
      return std::string("DIV(" + lexeme + ")");
    } else if (type == TokenType::END) {
      return std::string("END(" + lexeme + ")");
    } else if (type == TokenType::IDENT) {
      return std::string("IDENT(" + lexeme + ")");
    } else if (type == TokenType::INT) {
      return std::string("INT(" + std::to_string(value) + ")");
    } else if (type == TokenType::INVALID) {
      return std::string("INVALID(" + lexeme + ")");
    } else if (type == TokenType::LPAREN) {
      return std::string("LPAREN(" + lexeme + ")");
    } else if (type == TokenType::MINUS) {
      return std::string("MINUS(" + lexeme + ")");
    } else if (type == TokenType::MUL) {
      return std::string("MUL(" + lexeme + ")");
    } else if (type == TokenType::PLUS) {
      return std::string("PLUS(" + lexeme + ")");
    } else if (type == TokenType::RPAREN) {
      return std::string("RPAREN(" + lexeme + ")");
    } else if (type == TokenType::PRINT) {
      return std::string("PRINT(" + lexeme + ")");
    } else {
      return std::string("---");
    }
  }
};

std::string tokenTypeName(TokenType type);