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
  GREATER,
  LESS,
  EQUAL,
  LESSEQUAL,
  GREATEREQUAL,
  NOTEQUAL,
  END,
  PRINT,
  SEMICOLON,
  IF,
  ELSE,
  WHILE,
  NEWLINE,
  INVALID
};

struct Token {
  TokenType type;
  std::string lexeme; // the initial text
  int value; // only valid for TokenType::INT
  // size_t position; // the location in the initial string
  size_t row, column; // the location in the initial program
  Token(TokenType type_, std::string lexeme_, int value_, size_t row_, size_t column_) {
    type = type_;
    lexeme = lexeme_;
    value = value_;
    row = row_;
    column = column_;
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
    } else if (type == TokenType::LPAREN) {
      return std::string("LPAREN(" + lexeme + ")");
    } else if (type == TokenType::LBRACE) {
      return std::string("LBRACE(" + lexeme + ")");
    } else if (type == TokenType::MINUS) {
      return std::string("MINUS(" + lexeme + ")");
    } else if (type == TokenType::MUL) {
      return std::string("MUL(" + lexeme + ")");
    } else if (type == TokenType::PLUS) {
      return std::string("PLUS(" + lexeme + ")");
    } else if (type == TokenType::RPAREN) {
      return std::string("RPAREN(" + lexeme + ")");
    } else if (type == TokenType::RBRACE) {
      return std::string("RBRACE(" + lexeme + ")");
    } else if (type == TokenType::PRINT) {
      return std::string("PRINT(" + lexeme + ")");
    } else if (type == TokenType::GREATER) {
      return std::string("GREATER(" + lexeme + ")");
    } else if (type == TokenType::LESS) {
      return std::string("LESS(" + lexeme + ")");
    } else if (type == TokenType::EQUAL) {
      return std::string("EQUAL(" + lexeme + ")");
    } else if (type == TokenType::LESSEQUAL) {
      return std::string("LESSEQUAL(" + lexeme + ")");
    } else if (type == TokenType::GREATEREQUAL) {
      return std::string("GREATEREQUAL(" + lexeme + ")");
    } else if (type == TokenType::NOTEQUAL) {
      return std::string("NOTEQUAL(" + lexeme + ")");
    } else if (type == TokenType::SEMICOLON) {
      return std::string("SEMICOLON(" + lexeme + ")");
    } else if (type == TokenType::IF) {
      return std::string("IF(" + lexeme + ")");
    } else if (type == TokenType::ELSE) {
      return std::string("ELSE(" + lexeme + ")");
    } else if (type == TokenType::WHILE) {
      return std::string("WHILE(" + lexeme + ")");
    } else if (type == TokenType::NEWLINE) {
      return std::string("NEWLINE(\n)");
    } else if (type == TokenType::INVALID) {
      return std::string("INVALID(" + lexeme + ")");
    } else {
      return std::string("?(-?-?-?)");
    }
  }
};

std::string tokenTypeName(TokenType type);