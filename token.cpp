
#include "token.h"

std::string tokenTypeName(TokenType type) {
  if (type == TokenType::ASSIGN) {
    return std::string("ASSIGN");
  } else if (type == TokenType::DIV) {
    return std::string("DIV");
  } else if (type == TokenType::END) {
    return std::string("END");
  } else if (type == TokenType::IDENT) {
    return std::string("IDENT");
  } else if (type == TokenType::INT) {
    return std::string("INT");
  } else if (type == TokenType::INVALID) {
    return std::string("INVALID");
  } else if (type == TokenType::LPAREN) {
    return std::string("LPAREN");
  } else if (type == TokenType::MINUS) {
    return std::string("MINUS");
  } else if (type == TokenType::MUL) {
    return std::string("MUL");
  } else if (type == TokenType::PLUS) {
    return std::string("PLUS");
  } else if (type == TokenType::RPAREN) {
    return std::string("RPAREN");
  } else if (type == TokenType::PRINT) {
    return std::string("PRINT");
  } else if (type == TokenType::GREATER) {
    return std::string("GREATER");
  } else if (type == TokenType::LESS) {
    return std::string("LESS");
  } else if (type == TokenType::GREATEREQUAL) {
    return std::string("GREATEREQUAL");
  } else if (type == TokenType::LESSEQUAL) {
    return std::string("LESSEQUAL");
  } else if (type == TokenType::EQUAL) {
    return std::string("EQUAL");
  } else if (type == TokenType::NOTEQUAL) {
    return std::string("NOTEQUAL");
  } else if (type == TokenType::SEMICOLON) {
    return std::string("SEMICOLON");
  } else if (type == TokenType::IF) {
    return std::string("IF");
  } else if (type == TokenType::ELSE) {
    return std::string("ELSE");
  } else if (type == TokenType::WHILE) {
    return std::string("WHILE");
  } else if (type == TokenType::NEWLINE) {
    return std::string("NEWLINE");
  } else if (type == TokenType::INVALID) {
    return std::string("INVALID");
  } else {
    return std::string("?(-?-?-?)");
  }
}