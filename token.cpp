
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
  } else {
    return std::string("---");
  }
}