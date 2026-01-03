#pragma once

#include <memory>
#include <string>
#include <vector>
#include "token.h"
#include "ast.h"
#include "stmt.h"
#include "program.h"
#include <stdexcept>

struct TokenStream {
  const std::vector<Token>& tokens;
  size_t pos;
  TokenStream(const std::vector<Token>& tokens_) 
    : tokens(tokens_) {
    pos = 0;
  }
  const Token& peek() const {
    return tokens[pos];
  }
  const Token& consume() {
    return tokens[pos++];
  }
  bool match(TokenType type) {
    if (peek().type == type) {
      consume();
      return true;
    } else {
      return false;
    }
  }
  const Token& expect(TokenType type) {
    if (peek().type == type) {
      return tokens[pos++];
    } else {
      throw std::runtime_error(
        "Expected token " + tokenTypeName(type) +
        ", but got " + tokenTypeName(peek().type) +
        " ('" + peek().lexeme + "') at position " +
        std::to_string(peek().position)
      );
    }
  }
};

std::unique_ptr<Expr> parseExpression(TokenStream& ts);
std::unique_ptr<Expr> parseTerm(TokenStream& ts);
std::unique_ptr<Expr> parseFactor(TokenStream& ts);
std::unique_ptr<Expr> parseAllExpression(TokenStream& ts);
std::unique_ptr<Stmt> parseStatement(TokenStream& ts);
Program parseProgram(TokenStream& ts);